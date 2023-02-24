//
// Created by sunxg on 22-1-30.
//

#include "StepIsNotInLookupPrefix.h"
#include "utils/StringPrefixMap.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    StepIsNotInLookupPrefix::~StepIsNotInLookupPrefix() {
        if(prefixMap)
            delete prefixMap;
    }

    StepIsNotInLookupPrefix::StepIsNotInLookupPrefix(const std::string &lookupName,
                                                     STRMAP_SP prefixList) {
        this->lookupName = lookupName;
        this->prefixMap = new StringPrefixMap<std::string>(false);
        this->prefixMap->putAll(prefixList);
    }

    StepIsNotInLookupPrefix::StepIsNotInLookupPrefix(const std::string &lookupName, STRSET_SP prefixSet) {
        this->lookupName = lookupName;
        this->prefixMap = new StringPrefixMap<std::string>(false);

        STRMAP_SP theMap = std::make_shared< std::map<std::string, std::string> >();
        for(const std::string & s : *prefixSet){
            (*theMap)[s] = "";
        }
        this->prefixMap->putAll(theMap);
    }

    std::shared_ptr<WalkResult>StepIsNotInLookupPrefix::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);

        std::string result;

        if (prefixMap->getLongestMatch(actualValue,result)) {
            return nullptr;
        }
        return walkNextStep(tree, actualValue);
    }
}