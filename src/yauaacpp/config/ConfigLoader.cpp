//
// Created by sunxg on 22-2-16.
//

#include <algorithm>
#include <analyze/InvalidParserConfigurationException.h>
#include <utils/YamlUtils.h>
#include "ConfigLoader.h"
#include "PackagedRules.h"
#include <regex>
#include <tool/tool.h>
#include "Config.h"

namespace ycpp {

    DirExt ConfigLoader::DEFAULT_RESOURCES(USER_AGENT_YAML_FILES_PATH,".yaml");

    std::map<std::string, std::shared_ptr<Resource> >
    ConfigLoader::findAllResources(const DirExt & dirExt, bool showLoadMessages,
                                   bool areOptional, bool loadingDefaultResources) {
        std::map<std::string, std::shared_ptr<Resource> > resources;
        try {
            std::list<std::shared_ptr<Resource>> resourceArray;
            if(dirExt.isResource)
                resourceArray.emplace_back(dirExt.convertToResource());
            else
                resolve_dir(dirExt,resourceArray);

            if (!loadingDefaultResources && showLoadMessages) {
                LOG::error( "Loading %zd rule files using expression: %s", resourceArray.size(), dirExt.toString().c_str());
            }
            for (std::shared_ptr<Resource> & resource : resourceArray) {
                if (!keepTests && isTestRulesOnlyFile(resource->getFilename())) {
                    if (showLoadMessages) {
                        LOG::error( "- Skipping tests only file %s (%ld bytes)", resource->getFilename().c_str(), resource->contentLength());
                    }
                    continue;
                }
                if (!loadingDefaultResources && showLoadMessages) {
                    LOG::error( "- Preparing %s (%ld bytes)", resource->getFilename().c_str(), resource->contentLength());
                }
                resources[resource->getFilename()] = resource;
            }
        } catch (std::exception & e) {
            if (areOptional) {
                LOG::error("The specified (optional) resource string is invalid: %s", dirExt.toString().c_str());
                return std::map<std::string, std::shared_ptr<Resource>>();
            } else {
                throw InvalidParserConfigurationException(std::string("Error reading resources: ") + e.what(), e);
            }
        }
        return resources;
    }

    void ConfigLoader::loadYaml(std::istream &yamlStream, const std::string &filename) {

        lock.lock();
        YAML::Node loadedYaml;
        try {
            loadedYaml = YAML::Load(yamlStream);
        } catch (std::exception & e) {
            lock.unlock();
            throw InvalidParserConfigurationException("Parse error in the file " + filename + ": " + e.what(), e);
        }

        if (loadedYaml.IsNull()) {
            LOG::warn("The file %s is empty", filename.c_str());
            lock.unlock();
            return;
        }

        // Get and check top level config
        YamlUtils::requireNodeInstanceOf(YAML::NodeType::Map, loadedYaml, filename, "File must be a std::map");

        YAML::Node & rootNode = loadedYaml;

        YAML::Node::iterator configNodeTuple = rootNode.begin();
        for (;configNodeTuple != rootNode.end(); configNodeTuple++) {
            std::string name = YamlUtils::getKeyAsString(configNodeTuple, filename);
            if ("config" == name) {
                break;
            }
            if ("version" == name) {
                // Check the version information from the Yaml files
                // assertSameVersion(tuple, filename);
                lock.unlock();
                return;
            }
        }

        YamlUtils::require(configNodeTuple != rootNode.end(), loadedYaml, filename, "The top level entry MUST be 'config'.");

        //YAML::Node configNode = rootNode["config"];
        YAML::Node configNode = YamlUtils::getValueAsSequenceNode(configNodeTuple, filename);

        for (size_t i=0; i<configNode.size(); i++) {
            YAML::Node configEntry = configNode[i];
            YamlUtils::requireNodeInstanceOf(YAML::NodeType::Map, configEntry, filename, "The entry MUST be a mapping");
            YAML::Node::iterator entry = YamlUtils::getExactlyOneNodeTuple(configEntry, filename);
            YAML::Node actualEntry = YamlUtils::getValueAsMappingNode(entry, filename);
            std::string entryType = YamlUtils::getKeyAsString(entry, filename);
            if(entryType == "lookup")
                    loadYamlLookup(actualEntry, filename);
            else if(entryType == "set")
                loadYamlLookupSets(actualEntry, filename);
            else if(entryType == "matcher")
                loadYamlMatcher(actualEntry, filename);
            else if(entryType == "test") {
                if (keepTests) {
                    loadYamlTestcase(actualEntry, filename);
                }
            }
            else {
                lock.unlock();
                throw InvalidParserConfigurationException(
                        std::string("Yaml config.(") + filename + ":" + itos(actualEntry.Mark().line) + "): " +
                        "Found unexpected config entry: " + entryType +
                        ", allowed are 'lookup', 'set', 'matcher' and 'test'");
            }

        }
        lock.unlock();
    }

    void ConfigLoader::loadYamlLookup(YAML::Node &entry, const std::string &filename) {
        assert(entry.IsMap());
        std::string name;
        STRMAP_SP map = std::make_shared<std::map<std::string, std::string>>();

        STRSET_SP merge = std::make_shared<std::set<std::string>>();

        for (YAML::Node::iterator tuple = entry.begin(); tuple != entry.end(); tuple++) {
            std::string keyname = YamlUtils::getKeyAsString(tuple, filename);
            if(keyname == "name")
                name = YamlUtils::getValueAsString(tuple, filename);
            else if(keyname == "merge") {
                YAML::Node node = YamlUtils::getValueAsSequenceNode(tuple, filename);
                std::list<std::string> t = YamlUtils::getStringValues(node, filename);
                merge->insert(t.begin(),t.end());
            }
            else if(keyname == "map") {
                YAML::Node mappings = YamlUtils::getValueAsMappingNode(tuple, filename);
                for (YAML::Node::iterator mapping=mappings.begin(); mapping != mappings.end(); mapping++) {
                    std::string key = YamlUtils::getKeyAsString(mapping, filename);
                    std::string value = YamlUtils::getValueAsString(mapping, filename);

                    if (map->find(key) != map->end()) {
                        throw InvalidParserConfigurationException(
                                "In the lookup \"" + name + "\" the key \"" + key + "\" appears multiple times.");
                    }

                    (*map)[key] = value;
                }

            }
        }

        YamlUtils::require(!name.empty() && (!map->empty() || !merge->empty()), entry, filename, "Invalid lookup specified");

        if (!merge->empty()) {
            analyzerConfig->putLookupMerges(name, merge);
        }

        analyzerConfig->putLookup(name, map);
    }

    void ConfigLoader::loadYamlLookupSets(YAML::Node &entry, const std::string &filename) {
        assert(entry.IsMap());
        std::string name;
        STRSET_SP lookupSet = std::make_shared<std::set<std::string>>();

        STRSET_SP merge = std::make_shared<std::set<std::string>>();

        for (YAML::Node::iterator tuple=entry.begin(); tuple != entry.end(); tuple++) {
            std::string keyname = YamlUtils::getKeyAsString(tuple, filename);
            if( keyname == "name")
                name = YamlUtils::getValueAsString(tuple, filename);
            else if(keyname == "merge") {
                YAML::Node node = YamlUtils::getValueAsSequenceNode(tuple, filename);
                std::list<std::string> t = YamlUtils::getStringValues(node, filename);
                merge->insert(t.begin(),t.end());
            }
            else if(keyname == "values"){
                YAML::Node node = YamlUtils::getValueAsSequenceNode(tuple, filename);
                for (const std::string & value: YamlUtils::getStringValues(node, filename)) {
                    lookupSet->insert(tolowers(value));
                }
            }
        }

        YamlUtils::require(!name.empty() && (!lookupSet->empty() || !merge->empty()), entry, filename, "Invalid lookup specified");

        if (!merge->empty()) {
            analyzerConfig->putLookupSetsMerges(name, merge);
        }

        analyzerConfig->putLookupSet(name, lookupSet);
    }

    void ConfigLoader::loadYamlMatcher(YAML::Node &entry, const std::string &filename) {
        assert(entry.IsMap());
        int matcherSourceLineNumber = entry.Mark().line;
        std::string matcherSourceLocation = filename + ':' + itos(matcherSourceLineNumber);

        // List of 'attribute', 'confidence', 'expression'
        std::list<ConfigLine> configLines;
        std::list<std::string> options;

        for (YAML::Node::iterator nodeTuple = entry.begin(); nodeTuple != entry.end(); nodeTuple++) {
            std::string name = YamlUtils::getKeyAsString(nodeTuple, matcherSourceLocation);
            if(name == "options")
                options = YamlUtils::getStringValues(nodeTuple->second, matcherSourceLocation);
            else if(name == "variable") {
                for (const std::string &variableConfig : YamlUtils::getStringValues(nodeTuple->second,
                                                                                   matcherSourceLocation)) {
                    std::vector<std::string> configParts = string_split(variableConfig,':',2);

                    if (configParts.size() != 2) {
                        throw InvalidParserConfigurationException("Invalid variable config line: " + variableConfig);
                    }
                    std::string variableName = trim(configParts[0]);
                    std::string config = trim(configParts[1]);

                    configLines.emplace_back(ConfigLine(ConfigLine::VARIABLE, variableName, -1, config));
                }
            }
            else if(name == "require") {
                for (std::string requireConfig : YamlUtils::getStringValues(nodeTuple->second,
                                                                                  matcherSourceLocation)) {
                    requireConfig = trim(requireConfig);
                    if (starts_with(requireConfig,std::string("IsNull["))) {
                        // FIXME: Nasty String manipulation code: Cleanup
                        std::string failIfFoundConfig = requireConfig;
                        failIfFoundConfig = std::regex_replace(failIfFoundConfig,std::regex("^IsNull\\["),std::string(""));
                        failIfFoundConfig = std::regex_replace(failIfFoundConfig,std::regex("\\]$"),std::string(""));
                        configLines.emplace_back(ConfigLine(ConfigLine::FAIL_IF_FOUND, "", -1, failIfFoundConfig));
                    } else {
                        configLines.emplace_back(ConfigLine(ConfigLine::REQUIRE, "", -1, requireConfig));
                    }
                }
            }
            else if(name == "extract") {
                for (const std::string &extractConfig : YamlUtils::getStringValues(nodeTuple->second,
                                                                                  matcherSourceLocation)) {
                    std::vector<std::string> configParts = string_split(extractConfig,':',3);

                    if (configParts.size() != 3) {
                        throw InvalidParserConfigurationException("Invalid extract config line: " + extractConfig);
                    }
                    std::string attribute = trim(configParts[0]);

                    long confidence = atoll(trim(configParts[1]).c_str());
                    std::string config = trim(configParts[2]);
                    configLines.emplace_back(ConfigLine(ConfigLine::EXTRACT, attribute, confidence, config));
                }
            }
        }

        analyzerConfig->addMatcherConfigs(matcherSourceLocation, std::make_shared<MatcherConfig>(filename, matcherSourceLineNumber, options, configLines));
    }

    void ConfigLoader::loadYamlTestcase(YAML::Node &entry, const std::string &filename) {
        assert(entry.IsMap());
        if (!doingOnlyASingleTest) {
            std::string input;
            std::string testName;
            std::list<std::string> options;
            std::map<std::string, std::string> expected;
            for (YAML::Node::iterator tuple = entry.begin(); tuple != entry.end(); tuple++) {
                std::string name = YamlUtils::getKeyAsString(tuple, filename);
                if(name == "options") {
                    options = YamlUtils::getStringValues(tuple->second, filename);
                    if (options.end() != std::find(options.begin(),options.end(),"only")) {
                        doingOnlyASingleTest = true;
                        analyzerConfig->clearAllTestCases();
                    }
                }
                else if(name == "input") {
                    YAML::Node m = YamlUtils::getValueAsMappingNode(tuple, filename);
                    for (auto inputTuple = m.begin(); inputTuple != m.end(); inputTuple++) {
                        std::string inputName = YamlUtils::getKeyAsString(inputTuple, filename);
                        if ("user_agent_string" == inputName) {
                            input = YamlUtils::getValueAsString(inputTuple, filename);
                        }
                        if ("name" == inputName) {
                            testName = YamlUtils::getValueAsString(inputTuple, filename);
                        }
                    }
                }
                else if (name == "expected") {
                    YAML::Node mappings = YamlUtils::getValueAsMappingNode(tuple, filename);
                    for (auto mapping=mappings.begin(); mapping!=mappings.end(); mapping++) {
                        std::string key = YamlUtils::getKeyAsString(mapping, filename);
                        std::string value = YamlUtils::getValueAsString(mapping, filename);
                        expected[key] = value;
                    }
                }
            }

            YamlUtils::require(!input.empty(), entry, filename, "Test is missing input");

            if (expected.empty()) {
                doingOnlyASingleTest = true;
                analyzerConfig->clearAllTestCases();
            }

            std::shared_ptr<TestCase> testCase( new TestCase(input, testName) );

            if (!expected.empty()) {
                for(auto pair : expected){
                    testCase->expect(pair.first,pair.second);
                }
            }
            if (!options.empty()) {
                for (const std::string & option: options) {
                    testCase->addOption(option);
                }
            }
            testCase->addMetadata("filename", filename);
            testCase->addMetadata("fileline", itos(entry.Mark().line));

            analyzerConfig->addTestCase(testCase);
        }

    }

    ConfigLoader & ConfigLoader::addResource(const std::list<DirExt> & resourceNames, bool optionalResource) {
        for(const DirExt & resource : resourceNames)
            addResource(resource,optionalResource);
        return *this;
    }

    ConfigLoader & ConfigLoader::addResource(const DirExt &resourceName, bool optionalResource) {
        if (resourceName.empty()) {
            throw InvalidParserConfigurationException("The provided resource name was empty.");
        }
        if (optionalResource) {
            optionalResources.push_back(resourceName);
        } else {
            mandatoryResources.push_back(resourceName);
        }
        return *this;
    }

    std::shared_ptr<AnalyzerConfig> ConfigLoader::load() {
        for(const DirExt & resourceString : mandatoryResources)
            loadResources(resourceString, showLoading, false);
        for(const DirExt & resourceString : optionalResources)
            loadResources(resourceString, showLoading, true);

        printf("yamlRules.size() = %zd\n",yamlRules.size());

        for(auto pair : yamlRules) {
            std::stringstream yamlStream(pair.second);
            std::string filename = pair.first;
            loadYaml(yamlStream, filename);
        }

        return analyzerConfig->build();
    }

    void ConfigLoader::loadResources(const DirExt &resourceString, bool showLoadMessages, bool areOptional) {
        long startFiles = get_cur_msec();
        bool loadingDefaultResources = (DEFAULT_RESOURCES == resourceString);
        std::map<std::string, std::shared_ptr<Resource>> resources = findAllResources(resourceString, showLoadMessages, areOptional, loadingDefaultResources);

        doingOnlyASingleTest = false;
        size_t maxFilenameLength = 0;

        // When using a framework like Quarkus loading resources can fail in mysterious ways.
        // Just trying to open a stream for one of the resources is enough to see if we can continue.
        if (!resources.empty()) {
            std::shared_ptr<Resource> resource = resources.begin()->second;
            std::istream * ignored = resource->getInputStream();
            if(ignored != nullptr){
                // Just seeing if opening this stream triggers an error.
                // Having a useless statement that references the 'ignored' to avoid checkstyle and compilation warnings.
                LOG::debug("Opening the resource worked. %x", ignored);
            } else {
                LOG::error("Cannot load the resources (usually classloading problem).");
                LOG::error("- Resource   : %s", resource->getPathName().c_str());
                LOG::error("- Filename   : %s", resource->getFilename().c_str());
                LOG::error("- Description: %s", resource->getDescription().c_str());
                if (loadingDefaultResources) {
                    LOG::warn("Falling back to the built in list of resources");
                    resources.clear();
                } else {
                    LOG::error("FATAL: Unable to load the specified resources for %s", resourceString.toString().c_str());
                    throw InvalidParserConfigurationException("Error reading resources (" + resourceString.toString() + ")");
                }
            }
        }

        if (resources.empty()) {
            if (areOptional) {
                LOG::warn("NO optional resources were loaded from expression: %s", resourceString.toString().c_str());
            } else {
                LOG::error("NO config files were found matching this expression: %s", resourceString.toString().c_str());

                if (loadingDefaultResources) {
                    LOG::warn("Unable to load the default resources, usually caused by classloader problems.");
                    LOG::warn("Retrying with built in list.");
                    for(std::shared_ptr<Resource> resource : PackagedRules::getRuleFileNames()){
                        DirExt dirExt(resource->path,resource->name);
                        loadResources(dirExt,false,false);
                    }
                } else {
                    LOG::warn("If you are using wildcards in your expression then try explicitly naming all yamls files explicitly.");
                    throw InvalidParserConfigurationException("There were no resources found for the expression: " + resourceString.toString());
                }
            }
            return;
        }

        // We need to determine if we are trying to load the yaml files TWICE.
        // This can happen if the library is loaded twice (perhaps even two different versions).
        std::set<std::string> resourceBasenames;
        for(auto pair : resources){
            std::string k = pair.first;
            k = std::regex_replace(k,std::regex("^.*/"), std::string(""));
            resourceBasenames.insert(k);
        }

        std::set<std::string> alreadyLoadedResourceBasenames;
        for(auto pair : yamlRules){
            std::string k = pair.first;
            k = std::regex_replace(k,std::regex("^.*/"), std::string(""));
            alreadyLoadedResourceBasenames.insert(k);
        }

        std::set<std::string> t;

        std::set_intersection(alreadyLoadedResourceBasenames.begin(),alreadyLoadedResourceBasenames.end(),
                              resourceBasenames.begin(),resourceBasenames.end(),
                              std::inserter(t,t.begin()));
        alreadyLoadedResourceBasenames = t;
        if (!alreadyLoadedResourceBasenames.empty()) {
            LOG::error("Trying to load these %zd resources for the second time",
                       alreadyLoadedResourceBasenames.size());
            throw InvalidParserConfigurationException("Trying to load " + uitos(alreadyLoadedResourceBasenames.size()) +
                                                      " resources for the second time");
        }

        for (auto resourceEntry : resources) {
            std::shared_ptr<Resource> resource = resourceEntry.second;
            std::string filename = resource->getFilename();
            if (!filename.empty()) {
                maxFilenameLength = std::max(maxFilenameLength, filename.length());
                std::string yamlString;
                std::string line;
                std::istream * is= resource->getInputStream();
                if(is == nullptr)
                    throw InvalidParserConfigurationException("Error reading resources: " + resource->getPathName());
                while(getline(*is, line)){
                    yamlString += (line + "\n");
                }
                yamlRules[filename] = yamlString;
            }
        }

        long stopFiles = get_cur_msec();

        LOG::error( "- Loaded %2zd files in %4ld ms using expression: %s",
                   resources.size(),
                   (stopFiles - startFiles),
                   resourceString.toString().c_str());

        if (resources.empty()) {
            throw InvalidParserConfigurationException("No matchers were loaded at all.");
        }

    }

    bool ConfigLoader::isTestRulesOnlyFile(const std::string &filename) {
        if (filename.empty()) {
            return false;
        }
        return (contains(filename,"-tests") || contains(filename,"-Tests"));
    }

}
