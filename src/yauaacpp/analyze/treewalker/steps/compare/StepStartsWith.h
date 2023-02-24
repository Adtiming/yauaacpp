//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPSTARTSWITH_H
#define YAUAACPP_STEPSTARTSWITH_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {


    class StepStartsWith :public Step {

    private:
        std::string desiredValue;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepStartsWith() {
        }

    public:
        StepStartsWith(const std::string & desiredValue) {
            this->desiredValue = desiredValue;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);


        std::string toString() const override {
            return "StartsWith(" + desiredValue + ")";
        }

    };

}

#endif //YAUAACPP_STEPSTARTSWITH_H
