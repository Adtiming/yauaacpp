//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_ANALYZERCONFIG_H
#define YAUAACPP_ANALYZERCONFIG_H

#include "yauaacpp_def.h"
#include "MatcherConfig.h"
#include "TestCase.h"

namespace ycpp {
    class AnalyzerConfigBuilder;

    class AnalyzerConfig {

    private:
        // file+line number --> Config at that location
        std::map<std::string, std::shared_ptr<MatcherConfig>> matcherConfigs;
        // Lookup name --> keys+values for the lookup
        std::shared_ptr<MAPMAPS> lookups;

        // Lookup SET name --> values of this set
        std::shared_ptr<MAPSETS> lookupSets;

        std::list<std::shared_ptr<TestCase>> testCases;

        AnalyzerConfig();

        // Lookup name --> names of lookups to merge in it
        MAPSETS lookupMerge; // The names of the lookups that need to be merged

        // Lookup SET name --> names of lookup SETs to merge in it
        MAPSETS lookupSetMerge;  // The names of the sets that need to be merged


    public:
        static std::shared_ptr<AnalyzerConfigBuilder> newBuilder();

        void merge(AnalyzerConfig additionalConfig);

        std::map<std::string, std::shared_ptr<MatcherConfig>> getMatcherConfigs() {
            return matcherConfigs;
        }

        std::shared_ptr<MAPMAPS> getLookups() {
            return lookups;
        }

        std::shared_ptr<MAPSETS> getLookupSets() {
            return lookupSets;
        }

        std::list<std::shared_ptr<TestCase>> getTestCases() {
            return testCases;
        }

        friend class AnalyzerConfigBuilder;
    };

    class AnalyzerConfigBuilder {
    private:
        std::shared_ptr<AnalyzerConfig> analyzerConfig;

    public:
        AnalyzerConfigBuilder() {
            this->analyzerConfig = std::shared_ptr<AnalyzerConfig>(new AnalyzerConfig());
        }

        void addMatcherConfigs(const std::string & filename, std::shared_ptr<MatcherConfig> matcherConfig) {
            analyzerConfig->matcherConfigs[filename] = matcherConfig;
        }

        /**
         * Store the keys and values.
         *
         * @param name   The name of the lookup
         * @param values The additional keys and values for this lookup->
         */
        void putLookup(const std::string & name,STRMAP_SP values) {
            (*analyzerConfig->lookups)[name] = values;
        }

        /**
         * Store the additional lookups that need to be merged in with a lookup
         * @param name The name of the lookup
         * @param lookupNames The names of the lookups that must be added to the specified lookup->
         */
        void putLookupMerges(const std::string & name, STRSET_SP lookupNames) {
            analyzerConfig->lookupMerge[name] = lookupNames;
        }


        /**
         * Store the keys and values.
         * @param name   The name of the lookupSet
         * @param values The additional keys and values for this lookup->
         */
        void putLookupSet(const std::string & name, STRSET_SP values) {
            (*analyzerConfig->lookupSets.get())[name] = values;
        }

        /**
         * Store the additional lookupSets that need to be merged in with a lookupSet
         * @param name The name of the lookupSet
         * @param setNames The names of the lookupSets that must be added to the specified lookupSet.
         */
        void putLookupSetsMerges(const std::string & name, STRSET_SP setNames) {
            analyzerConfig->lookupSetMerge[name] = setNames;
        }

        void clearAllTestCases() {
            analyzerConfig->testCases.clear();
        }

        void addTestCase(std::shared_ptr<TestCase> testCase) {
            analyzerConfig->testCases.push_back(testCase);
        }

        std::shared_ptr<AnalyzerConfig> build();
    };
}
#endif //YAUAACPP_ANALYZERCONFIG_H
