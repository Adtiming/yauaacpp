//
// Created by sunxg on 22-1-30.
//

#include "StepIsInLookupPrefix.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    StepIsInLookupPrefix::~StepIsInLookupPrefix() {
        if(prefixMap != nullptr)
            delete prefixMap;
    }

    StepIsInLookupPrefix::StepIsInLookupPrefix(const std::string &lookupName,
                                               STRMAP_SP prefixList) {
        this->lookupName = lookupName;
        this->prefixMap = new StringPrefixMap<std::string>(false);
        this->prefixMap->putAll(prefixList);
    }

    std::shared_ptr<WalkResult>StepIsInLookupPrefix::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);

        std::string result;
        if(prefixMap->getLongestMatch(actualValue,result))
            return walkNextStep(tree, actualValue);

        return nullptr;
    }
}