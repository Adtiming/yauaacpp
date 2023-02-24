//
// Created by sunxg on 22-1-30.
//

#include <tool/tool.h>
#include "StepIsNotInSet.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepIsNotInSet::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);

        if (list->end() == list->find(tolowers(actualValue))) {
            return walkNextStep(tree, actualValue);
        }
        return nullptr;
    }
}