//
// Created by sunxg on 22-1-30.
//

#include <analyze/treewalker/steps/WalkList.h>
#include "StepContains.h"
#include "UserAgent.h"
#include "tool/tool.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepContains::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        std::string actualValue = getActualValue(tree, value);

        std::string s = tolowers(actualValue);
        if (s.npos != s.find(desiredValue)) {
            return walkNextStep(tree, actualValue);
        }
        return nullptr;
    }

    StepContains::StepContains(const std::string &desiredValue) {
        this->desiredValue = tolowers(desiredValue);
    }
}