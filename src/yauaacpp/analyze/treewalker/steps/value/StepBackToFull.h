//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPBACKTOFULL_H
#define YAUAACPP_STEPBACKTOFULL_H

#include "yauaacpp_def.h"


namespace ycpp {
    class StepBackToFull :public Step {

    public:
        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override {
            return walkNextStep(tree, "");
        }

        bool canFail() override {
            return false;
        }


        std::string toString() const override {
            return "BackToFull()";
        }

    };

}

#endif //YAUAACPP_STEPBACKTOFULL_H
