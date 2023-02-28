//
// Created by sunxg on 22-2-3.
//

#include <analyze/UselessMatcherException.h>
#include "AbstractUserAgentAnalyzerDirect.h"
#include "analyze/Matcher.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"
#include "analyze/Analyzer.h"
#include <analyze/MatcherList.h>
#include <parse/UserAgentTreeFlattener.h>
#include <analyze/Matcher.h>
#include <config/AnalyzerConfig.h>
#include <calculate/FieldCalculator.h>
#include <utils/CheckLoggingDependencies.h>
#include <calculate/ConcatNONDuplicatedCalculator.h>
#include <calculate/MajorVersionCalculator.h>
#include <calculate/CalculateAgentClass.h>
#include <calculate/CalculateAgentName.h>
#include <calculate/CalculateNetworkType.h>
#include <calculate/CalculateDeviceName.h>
#include <calculate/CalculateDeviceBrand.h>
#include <calculate/CalculateAgentEmail.h>
#include <config/ConfigLoader.h>
#include <utils/YauaaVersion.h>

namespace ycpp {



    std::list<std::string> AbstractUserAgentAnalyzerDirect::HARD_CODED_GENERATED_FIELDS = init();

    std::set<std::string> AbstractUserAgentAnalyzerDirect::getAllPossibleFieldNames() {
        if (allPossibleFieldNamesCache.empty()) {
            lock.lock();
            if (allPossibleFieldNamesCache.empty()) {
                std::set<std::string> names(HARD_CODED_GENERATED_FIELDS.begin(),HARD_CODED_GENERATED_FIELDS.end());
                for (Matcher * matcher : allMatchers) {
                    std::set<std::string> t = matcher->getAllPossibleFieldNames();
                    names.insert(t.begin(),t.end());
                }
                allPossibleFieldNamesCache = names;
            }
            lock.unlock();
        }
        return allPossibleFieldNamesCache;
    }

    std::list<std::string> AbstractUserAgentAnalyzerDirect::getAllPossibleFieldNamesSorted() {
        if (allPossibleFieldNamesSortedCache.empty()) {
            lock.lock();
            if (allPossibleFieldNamesSortedCache.empty()) {
                auto t = getAllPossibleFieldNames();
                std::vector<std::string> fieldNames(t.begin(),t.end());
                std::sort(fieldNames.begin(),fieldNames.end());

                std::list<std::string> names ;
                for (size_t i=0; i< PRE_SORTED_FIELDS_LIST_SIZE; i++) {
                    const char * fieldName = PRE_SORTED_FIELDS_LIST[i];
                    for(auto it = fieldNames.begin(); it!=fieldNames.end(); it++){
                        if(*it == fieldName){
                            fieldNames.erase(it);
                            break;
                        }

                    }
                    names.emplace_back(fieldName);
                }
                names.insert(names.end(),fieldNames.begin(),fieldNames.end());
                allPossibleFieldNamesSortedCache = names;
            }
            lock.unlock();
        }
        return allPossibleFieldNamesSortedCache;
    }

    void AbstractUserAgentAnalyzerDirect::verifyWeAreNotAskingForImpossibleFields() {
        if (wantedFieldNames.empty()) {
            return; // Nothing to check
        }
        std::list<std::string> impossibleFields ;
        std::list<std::string> allPossibleFields = getAllPossibleFieldNamesSorted();

        for (const std::string & wantedFieldName: wantedFieldNames) {
            if (MutableUserAgent::isSystemField(wantedFieldName)) {
                continue; // These are fine
            }
            if (allPossibleFields.end() == std::find(allPossibleFields.begin(),allPossibleFields.end(),wantedFieldName)) {
                impossibleFields.push_back(wantedFieldName);
            }
        }
        if (impossibleFields.empty()) {
            return;
        }
        throw InvalidParserConfigurationException(std::string("We cannot provide these fields:") +
                                                  to_string(impossibleFields.begin(),impossibleFields.end()));
    }

    void AbstractUserAgentAnalyzerDirect::destroy() {
        lock.lock();

        for(Matcher * matcher : zeroInputMatchers) matcher->destroy();
        zeroInputMatchers.clear();

        informMatcherActions.clear();

        config.reset(); //释放config对象

        wantedFieldNames.clear();

        lookups->clear();
        lookupSets->clear();
        flattener->clear();


        invalidateCaches();

        delete touchedMatchers;
        touchedMatchers = nullptr;
        delete flattener;
        flattener = nullptr;

        for(Matcher * mather:allMatchers){
            delete mather;
        }
        lock.unlock();
    }

    void AbstractUserAgentAnalyzerDirect::loadResources(const DirExt * resourceString, bool showLoadMessages,
                                                        bool optionalResources) {

        if (matchersHaveBeenInitialized) {
            throw antlr4::IllegalStateException("Refusing to load additional resources after the datastructures have been initialized.");
        }

        std::shared_ptr<AnalyzerConfig> extraConfig = ConfigLoader(showLoadMessages).addResource(*resourceString, optionalResources)
                .load();


        addAnalyzerConfig(*extraConfig);
        invalidateCaches();
        finalizeLoadingRules();

    }

    void AbstractUserAgentAnalyzerDirect::finalizeLoadingRules() {

        YauaaVersion::logVersion(std::list<std::string>());
        flattener = new UserAgentTreeFlattener(this);

        if (!wantedFieldNames.empty()) {
            int wantedSize = wantedFieldNames.size();
            if (wantedFieldNames.end()!=wantedFieldNames.find(SET_ALL_FIELDS)) {
                wantedSize--;
            }
            LOG::error( "Building all needed matchers for the requested %d fields.\n", wantedSize);
        } else {
            LOG::error( "Building all matchers for all possible fields.\n");
        }

        struct less
        {
            bool operator()(const std::string& __x, const std::string& __y) const
            {
                std::vector<std::string> xv = string_split(__x,':');
                std::vector<std::string> yv = string_split(__y,':');
                if(xv.size()<=1 || yv.size()<=1)
                    return __x < __y;
                if(xv[0] != yv[0])
                    return xv[0] < yv[0];
                if(isdigit(xv[1][0]) && isdigit(yv[1][0]))
                    return atoi(xv[1].c_str()) < atoi(yv[1].c_str());
                return xv[1] < yv[1];
            }
        };
        auto t = config->getMatcherConfigs();
        std::map<std::string, std::shared_ptr<MatcherConfig>,less> matcherConfigs;
        for(auto itt:t)matcherConfigs[itt.first] = itt.second;

        if (matcherConfigs.empty()) {
            throw InvalidParserConfigurationException("No matchers were loaded at all.");
        }

        if(!allMatchers.empty()){
            for(Matcher * m:allMatchers)
                delete m;
        }
        allMatchers.clear();
        for (auto matcherConfigEntry : matcherConfigs) {
            std::shared_ptr<MatcherConfig> matcherConfig = matcherConfigEntry.second;
            Matcher * matcher = new Matcher();
            try {
                matcher->initMatcher(this,wantedFieldNames,matcherConfig);
                allMatchers.push_back(matcher);
            } catch (UselessMatcherException & ume) {
                delete matcher;
            }
        }

        verifyWeAreNotAskingForImpossibleFields();
        if (!_delayInitialization) {
            initializeMatchers();
        }

    }

    void AbstractUserAgentAnalyzerDirect::initializeMatchers() {
        if(matchersHaveBeenInitialized)
            return;
        lock.lock();
        if (matchersHaveBeenInitialized) {
            lock.unlock();
            return;
        }
        matchersHaveBeenInitialized = true;

        LOG::error( "Initializing Analyzer data structures");

        if (allMatchers.empty()) {
            lock.unlock();
            throw InvalidParserConfigurationException("No matchers were loaded at all.");
        }

        long start = get_cur_msec();
        //for(Matcher * matcher : allMatchers) matcher->initialize();
        for(size_t i=0; i<allMatchers.size(); i++){
            //printf("%zd=%s\n",i,allMatchers[i]->toString().c_str());
            allMatchers[i]->initialize();
        }
        long stop = get_cur_msec();


        LOG::error( "Built in %ld msec : Hashmap %zd, Ranges map:%zd\n",
                (stop - start),
                informMatcherActions.size(),
                informMatcherActionRanges.size());

        for (Matcher * matcher: allMatchers) {
            if (matcher->getActionsThatRequireInput() == 0) {
                zeroInputMatchers.push_back(matcher);
            }
        }

        // Reset all Matchers
        for (Matcher * matcher : allMatchers) {
            matcher->reset();
        }
        lock.unlock();
    }

    void AbstractUserAgentAnalyzerDirect::lookingForRange(const std::string &treeName, const Range & range) {
        linked_hash_set<Range> & ranges = informMatcherActionRanges[treeName];
        ranges.insert(range);
    }

    size_t AbstractUserAgentAnalyzerDirect::firstCharactersForPrefixHashLength(const std::string &input, size_t maxChars) {
        return std::min(maxChars, std::min((size_t)MAX_PREFIX_HASH_MATCH, input.length()));
    }

    std::string AbstractUserAgentAnalyzerDirect::firstCharactersForPrefixHash(const std::string &input, size_t maxChars) {
        return input.substr(0, firstCharactersForPrefixHashLength(input, maxChars));
    }

    void AbstractUserAgentAnalyzerDirect::informMeAboutPrefix(MatcherAction * matcherAction, const std::string &treeName,
                                                              const std::string &prefix) {
        this->informMeAbout(matcherAction, treeName + "{\"" + firstCharactersForPrefixHash(prefix, MAX_PREFIX_HASH_MATCH) + "\"");
        linked_hash_set<size_t > & lengths = informMatcherActionPrefixesLengths[treeName];
        lengths.insert(firstCharactersForPrefixHashLength(prefix, MAX_PREFIX_HASH_MATCH));
    }

    void AbstractUserAgentAnalyzerDirect::informMeAbout(MatcherAction *matcherAction, const std::string &keyPattern) {
        std::string hashKey = tolowers(keyPattern);
        if(hashKey == "agent")
        {
            hashKey = tolowers(keyPattern);
        }
        linked_hash_set<MatcherAction *> & analyzerSet = informMatcherActions[std::string(hashKey.c_str())];
        analyzerSet.insert(matcherAction);
    }

    std::shared_ptr<UserAgent> AbstractUserAgentAnalyzerDirect::parsePtr(std::shared_ptr<MutableUserAgent> userAgent) {
        initializeMatchers();
        std::string useragentString = userAgent->getUserAgentString();
        if (!useragentString.empty() && useragentString.length() > (size_t)userAgentMaxLength) {
            setAsHacker(userAgent, 100);
            userAgent->setForced(HACKER_ATTACK_VECTOR, "Buffer overflow", 100);
            return std::make_shared<ImmutableUserAgent>(*hardCodedPostProcessing(userAgent));
        }

        lock.lock();
        {
            // Reset all Matchers
            reset();

            if (userAgent->isDebug()) {
                for (Matcher * matcher : allMatchers) {
                    matcher->setVerboseTemporarily(true);
                }
            }

            try {
                userAgent = flattener->parse(userAgent);

                inform(SYNTAX_ERROR, userAgent->getValue(SYNTAX_ERROR), nullptr);

                if (verbose) {
                    LOG::error( "=========== Checking all Touched Matchers: %zd", touchedMatchers->size());
                }
                // Fire all Analyzers with any input
                for (Matcher * matcher : *touchedMatchers) {
                    matcher->analyze(userAgent);
                }

                if (verbose) {
                    LOG::error( "=========== Checking all Zero Input Matchers: %zd", zeroInputMatchers.size());
                }
                // Fire all Analyzers that should not get input
                for (Matcher * matcher : zeroInputMatchers) {
                    matcher->analyze(userAgent);
                }

                userAgent->processSetAll();
            } catch (std::exception & rte) {
                // If this occurs then someone has found a previously undetected problem.
                // So this is a safety for something that 'can' but 'should not' occur.
                userAgent->reset();
                setAsHacker(userAgent, 10000);
                userAgent->setForced(HACKER_ATTACK_VECTOR, "Yauaa Exploit", 10000);
            }
        }
        lock.unlock();
        return std::make_shared<ImmutableUserAgent>(*hardCodedPostProcessing(userAgent));
    }

    void AbstractUserAgentAnalyzerDirect::setAsHacker(std::shared_ptr<MutableUserAgent> userAgent, int confidence) {
        userAgent->set(DEVICE_CLASS,                 "Hacker",  confidence);
        userAgent->set(DEVICE_BRAND,                 "Hacker",  confidence);
        userAgent->set(DEVICE_NAME,                  "Hacker",  confidence);
        userAgent->set(DEVICE_VERSION,               "Hacker",  confidence);
        userAgent->set(OPERATING_SYSTEM_CLASS,       "Hacker",  confidence);
        userAgent->set(OPERATING_SYSTEM_NAME,        "Hacker",  confidence);
        userAgent->set(OPERATING_SYSTEM_VERSION,     "Hacker",  confidence);
        userAgent->set(LAYOUT_ENGINE_CLASS,          "Hacker",  confidence);
        userAgent->set(LAYOUT_ENGINE_NAME,           "Hacker",  confidence);
        userAgent->set(LAYOUT_ENGINE_VERSION,        "Hacker",  confidence);
        userAgent->set(LAYOUT_ENGINE_VERSION_MAJOR,  "Hacker",  confidence);
        userAgent->set(AGENT_CLASS,                  "Hacker",  confidence);
        userAgent->set(AGENT_NAME,                   "Hacker",  confidence);
        userAgent->set(AGENT_VERSION,                "Hacker",  confidence);
        userAgent->set(AGENT_VERSION_MAJOR,          "Hacker",  confidence);
        userAgent->set(HACKER_TOOLKIT,               "Unknown", confidence);
        userAgent->set(HACKER_ATTACK_VECTOR,         "Unknown", confidence);
    }

    void AbstractUserAgentAnalyzerDirect::receivedInput(Matcher *matcher) {
        if(zeroInputMatchers.end() != std::find(zeroInputMatchers.begin(),zeroInputMatchers.end(),matcher)){
            return;
        }
        touchedMatchers->push_back(matcher);
    }

    void AbstractUserAgentAnalyzerDirect::reset() {
        // Reset all Matchers
        for (Matcher * matcher : *touchedMatchers) {
            matcher->reset();
        }
        touchedMatchers->clear();

        for (Matcher * matcher : zeroInputMatchers) {
            matcher->reset();
        }
    }

    void AbstractUserAgentAnalyzerDirect::addAnalyzerConfig(const AnalyzerConfig &analyzerConfig) {
        if (!config) {
            config = AnalyzerConfig::newBuilder()->build();
            config->merge(analyzerConfig);
        } else {
            config->merge(analyzerConfig);
        }
        testCases = config->getTestCases();
        lookups = config->getLookups();
        lookupSets = config->getLookupSets();
    }

    void AbstractUserAgentAnalyzerDirect::setVerbose(bool newVerbose) {
        lock.lock();
        this->verbose = newVerbose;
        flattener->setVerbose(newVerbose);
        lock.unlock();
    }

    linked_hash_set<size_t> * AbstractUserAgentAnalyzerDirect::getRequiredPrefixLengths(const std::string &treeName) {
        auto it = informMatcherActionPrefixesLengths.find(treeName);
        if(it == informMatcherActionPrefixesLengths.end())
            return nullptr;
        return &it->second;
    }

    std::list<std::string> AbstractUserAgentAnalyzerDirect::init() {
        std::list<std::string> l;
        l.emplace_back(SYNTAX_ERROR);
        l.emplace_back(AGENT_VERSION_MAJOR);
        l.emplace_back(LAYOUT_ENGINE_VERSION_MAJOR);
        l.emplace_back(AGENT_NAME_VERSION);
        l.emplace_back(AGENT_NAME_VERSION_MAJOR);
        l.emplace_back(LAYOUT_ENGINE_NAME_VERSION);
        l.emplace_back(LAYOUT_ENGINE_NAME_VERSION_MAJOR);
        l.emplace_back(OPERATING_SYSTEM_NAME_VERSION);
        l.emplace_back(OPERATING_SYSTEM_NAME_VERSION_MAJOR);
        l.emplace_back(WEBVIEW_APP_VERSION_MAJOR);
        l.emplace_back(WEBVIEW_APP_NAME_VERSION);
        l.emplace_back(WEBVIEW_APP_NAME_VERSION_MAJOR);
        return l;
    }

    void AbstractUserAgentAnalyzerDirect::inform(const std::string &key, const std::string &value,
                                                 antlr4::tree::ParseTree *ctx) {
        inform(key, key, value, ctx);
        inform(key + "=\"" + value + '"', key, value, ctx);

        linked_hash_set<size_t> * lengths = getRequiredPrefixLengths(key);
        if (lengths != nullptr && !lengths->empty()) {
            size_t valueLength = value.length();
            for (size_t prefixLength : *lengths) {
                if (valueLength >= prefixLength) {
                    inform(key + "{\"" + firstCharactersForPrefixHash(value, prefixLength) + '"', key, value, ctx);
                }
            }
        }
    }

    void
    AbstractUserAgentAnalyzerDirect::inform(const std::string &match, const std::string &key, const std::string &value,
                                            antlr4::tree::ParseTree *ctx) {
        linked_hash_set<MatcherAction * > relevantActions;
        auto it = informMatcherActions.find(tolowers(match));
        if(it != informMatcherActions.end())
            relevantActions = it->second;

        if (verbose) {
            if (relevantActions.empty()) {
                LOG::error( "--- Have (0): %s", match.c_str());
            } else {
                LOG::error( "+++ Have (%zd): %s", relevantActions.size(), match.c_str());

                int count = 1;
                for (MatcherAction * action : relevantActions) {
                    LOG::error( "+++ -------> (%d): %s", count, action->toString().c_str());
                    count++;
                }
            }
        }

        if (!relevantActions.empty()) {
            for (MatcherAction * matcherAction : relevantActions) {
                matcherAction->inform(key, value, ctx);
            }
        }
    }

    std::list<std::string> AbstractUserAgentAnalyzerDirect::getAllPaths(const std::string &agent) {
        GetAllPathsAnalyzer t(agent);
        return t.getValues();
    }

    std::shared_ptr<GetAllPathsAnalyzer> AbstractUserAgentAnalyzerDirect::getAllPathsAnalyzer(const std::string &agent) {
        return std::shared_ptr<GetAllPathsAnalyzer>(new GetAllPathsAnalyzer(agent));
    }

    bool AbstractUserAgentAnalyzerDirect::isWantedField(const std::string &fieldName) {
        if (wantedFieldNames.empty()) {
            return true;
        }
        return wantedFieldNames.find(fieldName) != wantedFieldNames.end();
    }

    void AbstractUserAgentAnalyzerDirect::setFieldCalculators(std::list<std::shared_ptr<FieldCalculator> > & newFieldCalculators) {
        fieldCalculators.merge(newFieldCalculators);
    }

    std::shared_ptr<MutableUserAgent> AbstractUserAgentAnalyzerDirect::hardCodedPostProcessing(std::shared_ptr<MutableUserAgent>userAgent) {
        // If it is really really bad ... then it is a Hacker.
        if (userAgent->getValue(SYNTAX_ERROR) == "true") {
            if (userAgent->get(DEVICE_CLASS).getConfidence() == -1) {
                setAsHacker(userAgent, 10);
            }
        }

        // Calculate all fields that are constructed from the found ones.
        for (std::shared_ptr<FieldCalculator> fieldCalculator: fieldCalculators) {
            if (verbose) {
                LOG::error( "Running FieldCalculator: %s", fieldCalculator->toString().c_str());
            }
            fieldCalculator->calculate(userAgent);
        }

        return userAgent;
    }

    const linked_hash_set<Range> & AbstractUserAgentAnalyzerDirect::getRequiredInformRanges(const std::string &treeName) {
        return informMatcherActionRanges[treeName];
    }

    std::string AbstractUserAgentAnalyzerDirect::toString() {
        std::ostringstream o;
        o << "UserAgentAnalyzerDirect{";
        o << "\nallMatchers=";
        o << allMatchers ;
        o << "\n, zeroInputMatchers=";
        o << zeroInputMatchers <<
          //"\n, informMatcherActions=" << informMatcherActions <<
          "\n, showMatcherStats=" << showMatcherStats <<
          //            "\n, doingOnlyASingleTest=" << doingOnlyASingleTest <<
          "\n, wantedFieldNames=" << to_string(wantedFieldNames.begin(),wantedFieldNames.end()).c_str() <<
          "\n, testCases=" << to_string_objs(testCases.begin(),testCases.end()) <<
          //"\n, lookups=" << lookups <<
          //"\n, lookupSets=" << lookupSets <<
          "\n, flattener=" << flattener->toString().c_str() <<
          "\n, userAgentMaxLength=" << userAgentMaxLength <<
          "\n, loadTests=" << loadTests <<
          "\n, delayInitialization=" << _delayInitialization <<
          "\n, matchersHaveBeenInitialized=" << matchersHaveBeenInitialized <<
          //            "\n, informMatcherActionRanges=" << ToString.toString(informMatcherActionRanges) <<
          //            "\n, informMatcherActionPrefixesLengths=" << ToString.toString(informMatcherActionPrefixesLengths) <<
          "\n, verbose=" << verbose <<
          "\n, fieldCalculators=" << to_string_objs(fieldCalculators.begin(),fieldCalculators.end()).c_str() <<
          "\n}";
        return o.str();
    }

    void AbstractUserAgentAnalyzerDirect::showDeserializationStats() {
        std::list<std::string> lines ;
        lines.emplace_back("This Analyzer instance was deserialized.");
        lines.emplace_back("");
        lines.emplace_back("Lookups      : " + uitos(lookups->size()));
        lines.emplace_back("LookupSets   : " + uitos(lookupSets->size()));
        lines.emplace_back("Matchers     : " + uitos(allMatchers.size()));
        lines.emplace_back("Hashmap size : " + uitos(informMatcherActions.size()));
        lines.emplace_back("Ranges map   : " + uitos(informMatcherActionRanges.size()));
        lines.emplace_back("Testcases    : " + uitos(testCases.size()));

        YauaaVersion::logVersion(lines);
    }

    void AbstractUserAgentAnalyzerDirect::invalidateCaches() {
        allPossibleFieldNamesCache.clear();
        allPossibleFieldNamesSortedCache.clear();
    }

    MatcherList *AbstractUserAgentAnalyzerDirect::getTouchedMatchers() {
        return touchedMatchers;
    }

    AbstractUserAgentAnalyzerDirect::AbstractUserAgentAnalyzerDirect() {
        flattener = nullptr;
        config = nullptr;
        userAgentMaxLength = DEFAULT_USER_AGENT_MAX_LENGTH;
        loadTests = false;
        touchedMatchers = new MatcherList();
    }

    std::shared_ptr<UserAgent> AbstractUserAgentAnalyzerDirect::parse(const std::string &userAgentString) {
        auto userAgent = std::make_shared<MutableUserAgent>(userAgentString, wantedFieldNames);
        return std::shared_ptr<UserAgent>(parsePtr(userAgent));
    }

    AbstractUserAgentAnalyzerDirect::~AbstractUserAgentAnalyzerDirect() {
        destroy();
    }

    GetAllPathsAnalyzer::GetAllPathsAnalyzer(const std::string &useragent) {
        flattener = new UserAgentTreeFlattener(this);
        result = flattener->parse(useragent);
    }

    GetAllPathsAnalyzer::~GetAllPathsAnalyzer() {
        delete flattener;
        delete result;
    }

    void
    AbstractUserAgentAnalyzerDirectBuilder::registerFieldCalculator(std::shared_ptr<FieldCalculator> fieldCalculator) {
        std::string calculatedFieldName = fieldCalculator->getCalculatedFieldName();
        allFieldsForWhichACalculatorExists.insert(calculatedFieldName);
        if (uaa->isWantedField(calculatedFieldName)) {
            fieldCalculators.push_back(fieldCalculator);
            std::set<std::string> set = fieldCalculator->getDependencies();
            uaa->wantedFieldNames.insert(set.begin(),set.end());
        }
    }

    AbstractUserAgentAnalyzerDirectBuilder::AbstractUserAgentAnalyzerDirectBuilder(
            std::shared_ptr<AbstractUserAgentAnalyzerDirect> newUaa) {
        this->uaa = newUaa;
        this->uaa->setShowMatcherStats(false);
        resources = new std::list<DirExt>();
        optionalResources = new std::list<DirExt>();
        resources->emplace_back(ConfigLoader::DEFAULT_RESOURCES);
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::dropDefaultResources() {
        failIfAlreadyBuilt();
        resources->remove(ConfigLoader::DEFAULT_RESOURCES);
        return *this;
    }

    void AbstractUserAgentAnalyzerDirectBuilder::verifyCalculatorDependencyOrdering() {
        // Verify calculator dependencies ordering
        std::set<std::string> seenCalculatedFields;
        for (std::shared_ptr<FieldCalculator> fieldCalculator: fieldCalculators) {
            for (const std::string & dependency: fieldCalculator->getDependencies()){
                auto it = allFieldsForWhichACalculatorExists.find(dependency);
                if (it != allFieldsForWhichACalculatorExists.end()) {
                    auto itset = seenCalculatedFields.find(dependency);
                    if (itset == seenCalculatedFields.end()) {
                        throw InvalidParserConfigurationException(
                                std::string("Calculator ordering is wrong:") +
                                "For " + fieldCalculator->getCalculatedFieldName() +
                                " we need " + dependency + " which is a " +
                                "calculated field but it has not yet been calculated.");
                    }
                }
            }
            seenCalculatedFields.emplace(fieldCalculator->getCalculatedFieldName());
        }
    }

    std::shared_ptr<AbstractUserAgentAnalyzerDirect> AbstractUserAgentAnalyzerDirectBuilder::build() {
        failIfAlreadyBuilt();
        uaa->initTransientFields();

        // Before we initialize we check if the logging has been setup correctly.
        // Not all useragents trigger the same logging libraries because some
        // of the logging libraries are only used in specific analysis code.
        // This is a "fail fast" to ensure any problems happen even before startup.
        CheckLoggingDependencies::verifyLoggingDependencies();

        // In case we only want specific fields we must all these special cases too

        // Special field that affects ALL fields.
        uaa->wantedFieldNames.insert(SET_ALL_FIELDS);

        // This is always needed to determine the Hacker fallback
        uaa->wantedFieldNames.insert(DEVICE_CLASS);

        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new ConcatNONDuplicatedCalculator(AGENT_NAME_VERSION_MAJOR,         AGENT_NAME,             AGENT_VERSION_MAJOR)));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new ConcatNONDuplicatedCalculator(AGENT_NAME_VERSION,               AGENT_NAME,             AGENT_VERSION)));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new MajorVersionCalculator(AGENT_VERSION_MAJOR,                     AGENT_VERSION)));

        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new ConcatNONDuplicatedCalculator(WEBVIEW_APP_NAME_VERSION_MAJOR,   WEBVIEW_APP_NAME,       WEBVIEW_APP_VERSION_MAJOR)));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new ConcatNONDuplicatedCalculator(WEBVIEW_APP_NAME_VERSION,         WEBVIEW_APP_NAME,       WEBVIEW_APP_VERSION)));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new MajorVersionCalculator(WEBVIEW_APP_VERSION_MAJOR,               WEBVIEW_APP_VERSION)));

        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new ConcatNONDuplicatedCalculator(LAYOUT_ENGINE_NAME_VERSION_MAJOR, LAYOUT_ENGINE_NAME,     LAYOUT_ENGINE_VERSION_MAJOR)));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new ConcatNONDuplicatedCalculator(LAYOUT_ENGINE_NAME_VERSION,       LAYOUT_ENGINE_NAME,     LAYOUT_ENGINE_VERSION)));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new MajorVersionCalculator(LAYOUT_ENGINE_VERSION_MAJOR,             LAYOUT_ENGINE_VERSION)));

        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new MajorVersionCalculator(OPERATING_SYSTEM_NAME_VERSION_MAJOR,     OPERATING_SYSTEM_NAME_VERSION)));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new ConcatNONDuplicatedCalculator(OPERATING_SYSTEM_NAME_VERSION,    OPERATING_SYSTEM_NAME,  OPERATING_SYSTEM_VERSION)));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new MajorVersionCalculator(OPERATING_SYSTEM_VERSION_MAJOR,          OPERATING_SYSTEM_VERSION)));

        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new CalculateAgentClass()));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new CalculateAgentName()));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new CalculateNetworkType()));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new CalculateDeviceName()));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new CalculateDeviceBrand()));
        registerFieldCalculator(std::shared_ptr<FieldCalculator>(
                new CalculateAgentEmail()));

        std::reverse(fieldCalculators.begin(),fieldCalculators.end());
        uaa->setFieldCalculators(fieldCalculators);

        bool showLoading = uaa->getShowMatcherStats();

        ConfigLoader configLoader(showLoading);
        configLoader.addResource(*resources, false)
                .addResource(*optionalResources, true);
        if (uaa->willKeepTests()) {
            configLoader.enableKeepTests();
        } else {
            configLoader.enableDropTests();
        }

        int yamlRuleCount = 1;
        for (const std::string & yamlRule : yamlRules) {
            configLoader.addYaml(yamlRule, "Manually Inserted Rules " + yamlRuleCount++);
        }

        uaa->addAnalyzerConfig(*configLoader.load());

        //uaa->addAnalyzerConfig(*AnalyzerConfigBuilder().build());
        uaa->finalizeLoadingRules();
        if (preheatIterations < 0) {
            uaa->preHeat();
        } else {
            if (preheatIterations > 0) {
                uaa->preHeat(preheatIterations);
            }
        }
        didBuildStep = true;
        return uaa;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &
    AbstractUserAgentAnalyzerDirectBuilder::addResources(const std::string &path, const std::string & ext) {
        failIfAlreadyBuilt();
        DirExt dirExt(path,ext);
        resources->emplace_back(dirExt);
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &
    AbstractUserAgentAnalyzerDirectBuilder::addOptionalResources(const std::string &path, const std::string & ext) {
        failIfAlreadyBuilt();
        DirExt dirExt(path,ext);
        optionalResources->push_back(dirExt);
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &
    AbstractUserAgentAnalyzerDirectBuilder::addYamlRule(const std::string &yamlRule) {
        failIfAlreadyBuilt();
        yamlRules.emplace_back(yamlRule);
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::preheat(int iterations) {
        failIfAlreadyBuilt();
        this->preheatIterations = iterations;
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::preheat() {
        failIfAlreadyBuilt();
        this->preheatIterations = -1;
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &
    AbstractUserAgentAnalyzerDirectBuilder::withField(const std::string &fieldName) {
        failIfAlreadyBuilt();
        uaa->wantedFieldNames.insert(fieldName);
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::withAllFields() {
        failIfAlreadyBuilt();
        uaa->wantedFieldNames.clear();
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::showMatcherLoadStats() {
        failIfAlreadyBuilt();
        uaa->setShowMatcherStats(true);
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::hideMatcherLoadStats() {
        failIfAlreadyBuilt();
        uaa->setShowMatcherStats(false);
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &
    AbstractUserAgentAnalyzerDirectBuilder::withUserAgentMaxLength(int newUserAgentMaxLength) {
        failIfAlreadyBuilt();
        uaa->setUserAgentMaxLength(newUserAgentMaxLength);
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::keepTests() {
        failIfAlreadyBuilt();
        uaa->keepTests();
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::dropTests() {
        failIfAlreadyBuilt();
        uaa->dropTests();
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::delayInitialization() {
        failIfAlreadyBuilt();
        uaa->delayInitialization();
        return *this;
    }

    AbstractUserAgentAnalyzerDirectBuilder::B &AbstractUserAgentAnalyzerDirectBuilder::immediateInitialization() {
        failIfAlreadyBuilt();
        uaa->immediateInitialization();
        return *this;
    }

    void AbstractUserAgentAnalyzerDirectBuilder::failIfAlreadyBuilt() {
        if (didBuildStep) {
            throw antlr4::IllegalStateException("A builder can provide only a single instance. It is not allowed to set values after doing build()");
        }
    }

    AbstractUserAgentAnalyzerDirectBuilder::~AbstractUserAgentAnalyzerDirectBuilder() {
        delete resources;
        delete optionalResources;
    }
}
