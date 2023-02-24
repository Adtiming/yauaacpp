//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPNOTCONTAINS_H
#define YAUAACPP_STEPNOTCONTAINS_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepNotContains :public Step {
    private:
        std::string desiredValue;

        // Private constructor for serialization systems ONLY (like Kryo)
        StepNotContains() {
        }

    public:
        explicit StepNotContains(const std::string & desiredValue);


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override ;


        std::string toString() const override {
            return "NotContains(" + desiredValue + ")";
        }
    };
}

#endif //YAUAACPP_STEPNOTCONTAINS_H
