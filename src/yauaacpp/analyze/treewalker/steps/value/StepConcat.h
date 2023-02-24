//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPCONCAT_H
#define YAUAACPP_STEPCONCAT_H

#include "yauaacpp_def.h"


namespace ycpp {
    class StepConcat :public Step {
    private:
        std::string prefix;
        std::string postfix;

        // Private constructor for serialization systems ONLY (like Kryo)
        StepConcat() {
        }

    public:

        StepConcat(const std::string & prefix, std::string postfix) {
            this->prefix = prefix;
            this->postfix = postfix;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) {
            std::string actualValue = getActualValue(tree, value);
            std::string filteredValue = prefix + actualValue + postfix;
            return walkNextStep(tree, filteredValue);
        }


        bool canFail(){
            return false;
        }


        std::string toString() const override {
            return "Concat(" + prefix + ";" + postfix + ")";
        }

    };

}

#endif //YAUAACPP_STEPCONCAT_H
