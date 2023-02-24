//
// Created by sunxg on 22-2-3.
//

#include <analyze/InvalidParserConfigurationException.h>
#include <tool/tool.h>
#include "AnalyzerConfig.h"

namespace ycpp {
    std::shared_ptr<AnalyzerConfigBuilder>AnalyzerConfig::newBuilder() {
        return std::make_shared<AnalyzerConfigBuilder>();
    }

    AnalyzerConfig::AnalyzerConfig() {
        lookups = std::make_shared<MAPMAPS>();
        lookupSets = std::make_shared<MAPSETS>();
    }

    void AnalyzerConfig::merge(AnalyzerConfig additionalConfig) {
        testCases.insert(testCases.end(),additionalConfig.testCases.begin(),additionalConfig.testCases.end());
        lookups->insert(additionalConfig.lookups->begin(),additionalConfig.lookups->end());
        lookupSets->insert(additionalConfig.lookupSets->begin(),additionalConfig.lookupSets->end());
        matcherConfigs.insert(additionalConfig.matcherConfigs.begin(),additionalConfig.matcherConfigs.end());
    }

    std::shared_ptr<AnalyzerConfig> AnalyzerConfigBuilder::build() {
        if (!analyzerConfig->lookups->empty()) {
            if (!analyzerConfig->lookupMerge.empty()) {
                for(auto pair:analyzerConfig->lookupMerge){
                    const std::string & mapName = pair.first;
                    const STRSET_SP allExtraToLoad = pair.second;
                    auto it = analyzerConfig->lookups->find(mapName);
                    if(it != analyzerConfig->lookups->end()){
                        STRMAP_SP theMap = it->second;
                        for(const std::string & extraToLoad:*allExtraToLoad){
                            auto lookupit = analyzerConfig->lookups->find(extraToLoad);
                            if(lookupit == analyzerConfig->lookups->end()){
                                throw InvalidParserConfigurationException("Unable to merge lookup '" + extraToLoad + "' into '" + mapName + "'.");
                            }
                            STRMAP_SP extraMap = lookupit->second;
                            theMap->insert(extraMap->begin(),extraMap->end());
                        }
                    }
                }
            }

            // All compares are done in a case insensitive way. So we lowercase ALL keys of the lookups beforehand.
            MAPMAPS cleanedLookups;
            for (auto lookupsEntry : *analyzerConfig->lookups) {
                STRMAP_SP cleanedLookup = std::make_shared<std::map<std::string, std::string>>();
                for (auto entry : *lookupsEntry.second) {
                    (*cleanedLookup)[tolowers(entry.first)] = entry.second;
                }
                cleanedLookups[lookupsEntry.first] = cleanedLookup;
            }
            analyzerConfig->lookups->clear();
            analyzerConfig->lookups->insert(cleanedLookups.begin(),cleanedLookups.end());
        }

        if (!analyzerConfig->lookupSetMerge.empty()) {
            for(auto pair : analyzerConfig->lookupSetMerge){
                const std::string & setName = pair.first;
                const STRSET_SP allExtraToLoad = pair.second;
                auto it = analyzerConfig->lookupSets->find(setName);
                if(it != analyzerConfig->lookupSets->end()){
                    STRSET_SP theSet = it->second;
                    for(const std::string & extraToLoad: *allExtraToLoad){
                        auto lookupit = analyzerConfig->lookups->find(extraToLoad);
                        if(lookupit != analyzerConfig->lookups->end()){
                            STRMAP_SP extralookup = lookupit->second;
                            for(auto p: *extralookup){theSet->insert(p.first);}
                        }
                        auto lookupSetit = analyzerConfig->lookupSets->find(extraToLoad);
                        if(lookupSetit != analyzerConfig->lookupSets->end()){
                            STRSET_SP extralookupSet = lookupSetit->second;
                            theSet->insert(extralookupSet->begin(),extralookupSet->end());
                        }

                        if(lookupit == analyzerConfig->lookups->end() && lookupSetit == analyzerConfig->lookupSets->end())
                            throw InvalidParserConfigurationException("Unable to merge set '" + extraToLoad + "' into '" + setName + "'.");
                    }
                }
            }
        }
        return analyzerConfig;
    }
}