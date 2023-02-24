//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPNORMALIZEBRAND_H
#define YAUAACPP_STEPNORMALIZEBRAND_H

#include <utils/Normalize.h>
#include "yauaacpp_def.h"

namespace ycpp {
    class StepNormalizeBrand :public Step {

    public:

        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override {
            std::string actualValue = getActualValue(tree, value);
            std::string filteredValue = Normalize::brand(actualValue);
            return walkNextStep(tree, filteredValue);
        }


        bool canFail() override {
            return false;
        }


        std::string toString() const override {
            return "NormalizeBrand()";
        }

    };
}

#endif //YAUAACPP_STEPNORMALIZEBRAND_H
