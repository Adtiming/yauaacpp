//
// Created by sunxg on 22-1-30.
//

#include <analyze/treewalker/steps/WalkList.h>
#include "StepIsNull.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepIsNull::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::shared_ptr<WalkResult> actualValue = walkNextStep(tree, value);

        if (actualValue == nullptr ||
            actualValue->getValue().empty()) {
            return std::make_shared<WalkResult>(tree, "<<<IsNull Success Value>>>");
        }
        return nullptr;
    }
}