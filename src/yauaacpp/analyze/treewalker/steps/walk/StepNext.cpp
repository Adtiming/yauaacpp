//
// Created by sunxg on 22-1-30.
//

#include "StepNext.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    antlr4::tree::ParseTree *StepNext::next(antlr4::tree::ParseTree *tree) {
        antlr4::tree::ParseTree * parent = up(tree);

        if (parent == nullptr) {
            return nullptr;
        }

        antlr4::tree::ParseTree * child;
        bool foundCurrent = false;
        for (size_t i = 0; i < parent->children.size(); i++) {
            child = parent->children[i];
            if (foundCurrent) {
                if (Step::treeIsSeparator(child)) {
                    continue;
                }
                return child;
            }

            if (child == tree) {
                foundCurrent = true;
            }
        }
        return nullptr; // There is no next
    }

    std::shared_ptr<WalkResult>StepNext::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        antlr4::tree::ParseTree * nextTree = next(tree);
        if (nextTree == nullptr) {
            return nullptr;
        }

        return walkNextStep(nextTree, std::string());
    }
}
