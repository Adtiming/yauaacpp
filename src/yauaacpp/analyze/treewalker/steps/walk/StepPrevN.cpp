//
// Created by sunxg on 22-1-30.
//

#include <analyze/treewalker/steps/WalkList.h>
#include "StepPrevN.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::shared_ptr<WalkResult>StepPrevN::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        antlr4::tree::ParseTree * prevTree = prev(tree);
        if (prevTree == nullptr) {
            return nullptr;
        }

        return walkNextStep(prevTree, "");
    }

    antlr4::tree::ParseTree *StepPrevN::prev(antlr4::tree::ParseTree *tree) {
        antlr4::tree::ParseTree * parent = up(tree);

        if (parent == nullptr) {
            return nullptr;
        }

        if (children == nullptr) {
            children = new PParseTree[SIZE];
        }

        int lastChildIndex = -1;
        antlr4::tree::ParseTree * child = nullptr;
        size_t i;
        for (i = 0; i < parent->children.size(); i++) {
            if (!treeIsSeparator(child)) {
                lastChildIndex++;
                children[lastChildIndex] = child;
            }
            child = parent->children[i];
            if (child == tree) {
                if (lastChildIndex < steps) {
                    break; // There is no previous
                }
                return children[lastChildIndex - steps + 1];
            }
        }
        return nullptr; // There is no previous
    }
}