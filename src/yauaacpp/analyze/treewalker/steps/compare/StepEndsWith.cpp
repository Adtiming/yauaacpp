//
// Created by sunxg on 22-1-30.
//

#include <tool/tool.h>
#include "StepEndsWith.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepEndsWith::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);

        if (ends_with_ignore_case(actualValue, desiredValue)) {
            return walkNextStep(tree, actualValue);
        }
        return nullptr;
    }
}