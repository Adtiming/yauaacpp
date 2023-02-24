//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPCONCATPREFIX_H
#define YAUAACPP_STEPCONCATPREFIX_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {
    class StepConcatPrefix :public Step {
    private:std::string prefix;

     // Private constructor for serialization systems ONLY (like Kryo)
        StepConcatPrefix() {
        }

    public:
        StepConcatPrefix(const std::string & prefix) {
            this->prefix = prefix;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) {
            std::string actualValue = getActualValue(tree, value);
            std::string filteredValue = prefix + actualValue;
            return walkNextStep(tree, filteredValue);
        }


        bool canFail(){
            return false;
        }


        std::string toString() const override {
            return "ConcatPrefix(" + prefix + ")";
        }

    };
}

#endif //YAUAACPP_STEPCONCATPREFIX_H
