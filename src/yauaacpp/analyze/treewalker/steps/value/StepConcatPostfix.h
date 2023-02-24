//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPCONCATPOSTFIX_H
#define YAUAACPP_STEPCONCATPOSTFIX_H

#include "yauaacpp_def.h"


namespace ycpp {
    class StepConcatPostfix :public Step {

    private:
        std::string postfix;

        // Private constructor for serialization systems ONLY (like Kryo)
        StepConcatPostfix() {
        }

    public:
        StepConcatPostfix(const std::string & postfix) {
            this->postfix = postfix;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) {
            std::string actualValue = getActualValue(tree, value);
            std::string filteredValue = actualValue + postfix;
            return walkNextStep(tree, filteredValue);
        }


        bool canFail(){
            return false;
        }


        std::string toString() const override {
            return "ConcatPostfix(" + postfix + ")";
        }

    };
}

#endif //YAUAACPP_STEPCONCATPOSTFIX_H
