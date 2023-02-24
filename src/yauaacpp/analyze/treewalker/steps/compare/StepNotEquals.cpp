//
// Created by sunxg on 22-1-30.
//

#include "StepNotEquals.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepNotEquals::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);

        if (!icasecompare(actualValue,desiredValue)) {
            return walkNextStep(tree, actualValue);
        }
        return nullptr;
    }
}