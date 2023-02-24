//
// Created by sunxg on 22-1-30.
//

#include "StepDefaultIfNull.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepDefaultIfNull::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::shared_ptr<WalkResult> actualValue = walkNextStep(tree, value);

        if (actualValue == nullptr ||
            actualValue->getValue().empty()) {
            return std::make_shared<WalkResult>(tree, defaultValue);
        }
        return actualValue;
    }
}