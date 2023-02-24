//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPNEXT_H
#define YAUAACPP_STEPNEXT_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepNext :public Step {
    private:
        antlr4::tree::ParseTree * next(antlr4::tree::ParseTree * tree);

    public:
        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);


        std::string toString() const override {
            return "Next(1)";
        }

    };

}

#endif //YAUAACPP_STEPNEXT_H
