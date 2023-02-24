//
// Created by sunxg on 22-1-30.
//

#include "StepPrev.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    antlr4::tree::ParseTree *StepPrev::prev(antlr4::tree::ParseTree *tree) {
        antlr4::tree::ParseTree * parent = up(tree);

        if (parent == nullptr) {
            return nullptr;
        }

        antlr4::tree::ParseTree * prevChild = nullptr;
        antlr4::tree::ParseTree * child = nullptr;
        for (size_t i = 0; i < parent->children.size(); i++) {
            if (!treeIsSeparator(child)) {
                prevChild = child;
            }
            child = parent->children[i];
            if (child == tree) {
                break; // Found it
            }
        }
        return prevChild;
    }
}
