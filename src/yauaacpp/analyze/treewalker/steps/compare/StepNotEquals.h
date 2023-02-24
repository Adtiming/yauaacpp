//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPNOTEQUALS_H
#define YAUAACPP_STEPNOTEQUALS_H

#include <tool/tool.h>
#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepNotEquals :public Step {

    private:
        std::string desiredValue;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepNotEquals() {
        }
    public:
        explicit StepNotEquals(const std::string & desiredValue) {
            this->desiredValue = tolowers(desiredValue);
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);


        std::string toString() const override {
            return "NotEquals(" + desiredValue + ")";
        }

    };
}

#endif //YAUAACPP_STEPNOTEQUALS_H
