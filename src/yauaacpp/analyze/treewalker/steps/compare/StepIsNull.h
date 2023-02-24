//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPISNULL_H
#define YAUAACPP_STEPISNULL_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepIsNull :public Step {
    public:

        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override;


        bool mustHaveInput() {
            return false;
        }


        std::string toString() const override {
            return "IsNull()";
        }
    };

}

#endif //YAUAACPP_STEPISNULL_H
