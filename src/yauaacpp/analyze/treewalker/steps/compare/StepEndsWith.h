//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPENDSWITH_H
#define YAUAACPP_STEPENDSWITH_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepEndsWith :public Step {
    private:
        std::string desiredValue;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepEndsWith() {
        }
    public:
        StepEndsWith(const std::string & desiredValue) {
            this->desiredValue = desiredValue;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override;


        std::string toString() const override {
                    std::ostringstream o;
            return "EndsWith(" + desiredValue + ")";
        }

    };

}

#endif //YAUAACPP_STEPENDSWITH_H
