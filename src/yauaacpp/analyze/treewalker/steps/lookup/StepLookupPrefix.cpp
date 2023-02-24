//
// Created by sunxg on 22-1-30.
//

#include "StepLookupPrefix.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepLookupPrefix::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);

        std::string result;

        if (!prefixMap->getLongestMatch(actualValue,result)) {
            if (defaultValue.empty()) {
                return nullptr;
            } else {
                return walkNextStep(tree, defaultValue);
            }
        }
        return walkNextStep(tree, result);
    }

    StepLookupPrefix::~StepLookupPrefix() {
        if(prefixMap)
            delete prefixMap;
    }
}