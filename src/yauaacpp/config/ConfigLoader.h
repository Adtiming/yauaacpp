//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_CONFIGLOADER_H
#define YAUAACPP_CONFIGLOADER_H

#include "yauaacpp_def.h"
#include "AnalyzerConfig.h"
#include "tool/dir.h"
#include <yaml-cpp/yaml.h>
namespace ycpp {

    class ConfigLoader {

    private:
        std::recursive_mutex lock;
        bool doingOnlyASingleTest = false;

        std::list<DirExt>                               mandatoryResources;
        std::list<DirExt>                               optionalResources;
        std::shared_ptr<AnalyzerConfigBuilder>          analyzerConfig;

        // std::map from filename to yaml config string.
        std::map<std::string, std::string>          yamlRules;

        bool keepTests = true;
        std::map<std::string, std::shared_ptr<Resource> > findAllResources(const DirExt & dirExt, bool showLoadMessages, bool areOptional, bool loadingDefaultResources);

        YAML::Node * createYaml() {
//            LoaderOptions yamlLoaderOptions = new LoaderOptions();
//            yamlLoaderOptions.setMaxAliasesForCollections(200); // We use this many in the hacker/sql injection config.
//            return new Yaml(yamlLoaderOptions);
            return new YAML::Node();
        }

        void loadYaml(std::istream& yamlStream, const std::string & filename);

        void loadYamlLookup(YAML::Node & entry, const std::string & filename);

        void loadYamlLookupSets(YAML::Node & entry, const std::string & filename);

        void loadYamlMatcher(YAML::Node & entry, const std::string & filename);

        void loadYamlTestcase(YAML::Node & entry, const std::string & filename);

    public:
        // ------------------------------------------

        static DirExt DEFAULT_RESOURCES;

        bool showLoading;

        // ------------------------------------------

        ConfigLoader(bool showLoading) {
            this->showLoading = showLoading;
            analyzerConfig = AnalyzerConfig::newBuilder();
        }

        ConfigLoader & addResource(const std::list<DirExt> & resourceNames, bool optionalResource);

        ConfigLoader & addResource(const DirExt & resourceName, bool optionalResource);

        ConfigLoader & addYaml(const std::string & configString, const std::string & filename) {
            yamlRules[filename] = configString;
            return *this;
        }

        ConfigLoader & enableKeepTests(){
            this->keepTests = true;
            return *this;
        }

        ConfigLoader & enableDropTests(){
            this->keepTests = false;
            return *this;
        }

        // ------------------------------------------

        std::shared_ptr<AnalyzerConfig> load();

        // ------------------------------------------

        void loadResources(const DirExt & resourceString, bool showLoadMessages, bool areOptional);


        static bool isTestRulesOnlyFile(const std::string & filename);

    };

}
#endif //YAUAACPP_CONFIGLOADER_H
