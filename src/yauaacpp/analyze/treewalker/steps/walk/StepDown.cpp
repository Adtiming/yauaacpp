//
// Created by sunxg on 22-1-30.
//

#include "StepDown.h"
#include "analyze/NumberRangeVisitor.h"
#include "analyze/treewalker/steps/walk/stepdown/UserAgentGetChildrenVisitor.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    void StepDown::setDefaultFieldValues() {
        if(userAgentGetChildrenVisitor) delete userAgentGetChildrenVisitor;
        userAgentGetChildrenVisitor = new UserAgentGetChildrenVisitor(name, start, end);
    }

    StepDown::StepDown(const NumberRangeList & numberRange, const std::string & name) {
        userAgentGetChildrenVisitor = nullptr;
        this->name = name;
        this->start = numberRange.getStart();
        this->end = numberRange.getEnd();
        setDefaultFieldValues();
    }

    StepDown::StepDown(UserAgentTreeWalkerParser::NumberRangeContext * numberRange, const std::string & name) {
        new (this) StepDown(*NumberRangeVisitor::getList(numberRange).as<std::shared_ptr<NumberRangeList>>(), name);
    }

    std::shared_ptr<WalkResult>StepDown::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        Iterator<antlr4::tree::ParseTree*> * children = userAgentGetChildrenVisitor->visit(tree).as<Iterator<antlr4::tree::ParseTree*> *>();
        while (children->hasNext()) {
            antlr4::tree::ParseTree *  child       = children->next();
            std::shared_ptr<WalkResult> childResult = walkNextStep(child, "");
            if (childResult != nullptr) {
                return childResult;
            }
        }
        return nullptr;
    }

    StepDown::~StepDown() {
        if(userAgentGetChildrenVisitor) delete userAgentGetChildrenVisitor;
    }
}
