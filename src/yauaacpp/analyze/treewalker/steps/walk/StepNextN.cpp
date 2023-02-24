//
// Created by sunxg on 22-1-30.
//

#include "StepNextN.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    antlr4::tree::ParseTree *StepNextN::next(antlr4::tree::ParseTree *tree) {
        antlr4::tree::ParseTree * parent = up(tree);

        if (parent == nullptr) {
            return nullptr;
        }

        antlr4::tree::ParseTree * child;
        bool foundCurrent = false;
        int stepsToDo = steps;
        for (size_t i = 0; i < parent->children.size(); i++) {
            child = parent->children[i];
            if (foundCurrent) {
                if (treeIsSeparator(child)) {
                    continue;
                }
                stepsToDo--;
                if (stepsToDo == 0) {
                    return child;
                }
            }

            if (child == tree) {
                foundCurrent = true;
            }
        }
        return nullptr; // There is no next
    }

    std::shared_ptr<WalkResult>StepNextN::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        antlr4::tree::ParseTree * nextTree = next(tree);
        if (nextTree == nullptr) {
            return nullptr;
        }

        return walkNextStep(nextTree, "");
    }
}
