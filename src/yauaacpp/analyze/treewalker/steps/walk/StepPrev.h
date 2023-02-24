//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPPREV_H
#define YAUAACPP_STEPPREV_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepPrev :public Step {

    private:
        antlr4::tree::ParseTree * prev(antlr4::tree::ParseTree * tree);

    public:
        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) {
            antlr4::tree::ParseTree * prevTree = prev(tree);
            if (prevTree == nullptr) {
                return nullptr;
            }
            return walkNextStep(prevTree, "");
        }

        std::string toString() const override {
            return "Prev(1)";
        }

    };

}
#endif //YAUAACPP_STEPPREV_H
