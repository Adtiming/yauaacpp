//
// Created by sunxg on 22-1-30.
//

#include <tool/tool.h>
#include "StepLookupContains.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepLookupContains::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);

        actualValue = tolowers(actualValue);
        for (auto entry: *lookup) {
            if (contains(actualValue,entry.first)) {
                return walkNextStep(tree, entry.second);
            }
        }

        // Not found:
        if (defaultValue.empty()) {
            return nullptr;
        }
        return walkNextStep(tree, defaultValue);
    }
}