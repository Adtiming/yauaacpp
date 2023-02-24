//
// Created by sunxg on 22-1-30.
//

#include <analyze/treewalker/steps/WalkList.h>
#include <tool/tool.h>
#include "StepIsInSet.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepIsInSet::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);

        if (list->end() != list->find(tolowers(actualValue))) {
            return walkNextStep(tree, actualValue);
        }
        return nullptr;
    }
}