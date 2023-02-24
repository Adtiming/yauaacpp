//
// Created by sunxg on 22-1-30.
//

#include <analyze/treewalker/steps/WalkList.h>
#include <tool/tool.h>
#include "StepNotContains.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepNotContains::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);
        std::string t = tolowers(actualValue);
        if (t.npos == t.find(desiredValue)) {
            return walkNextStep(tree, actualValue);
        }
        return nullptr;
    }

    StepNotContains::StepNotContains(const std::string &desiredValue) {
        this->desiredValue = tolowers(desiredValue);
    }
}