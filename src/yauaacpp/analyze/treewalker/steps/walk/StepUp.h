//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPUP_H
#define YAUAACPP_STEPUP_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepUp :public Step {

    public:
        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override {
            antlr4::tree::ParseTree * parent = up(tree);
            if (parent == nullptr) {
                return nullptr;
            }

            return walkNextStep(parent, "");
        }


        std::string toString() const override {
            return "Up()";
        }

    };

}
#endif //YAUAACPP_STEPUP_H
