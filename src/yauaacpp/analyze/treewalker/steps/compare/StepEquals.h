//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPEQUALS_H
#define YAUAACPP_STEPEQUALS_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepEquals :public Step {
    private:
        std::string desiredValue;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepEquals() {
        }
    public:
        StepEquals(const std::string & desiredValue) {
            this->desiredValue = desiredValue;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);


        std::string toString() const override {
                    std::ostringstream o;
            return "Equals(" + desiredValue + ")";
        }

    };

}

#endif //YAUAACPP_STEPEQUALS_H
