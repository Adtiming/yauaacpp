//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPCONTAINS_H
#define YAUAACPP_STEPCONTAINS_H

#include <tool/tool.h>
#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {


    class StepContains :public Step {
    private:
        std::string desiredValue;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepContains() {
        }

    public:
        explicit StepContains(const std::string & desiredValue);


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override ;

        std::string toString() const override {
                    std::ostringstream o;
            return "Contains(" + desiredValue + ")";
        }
    };

}

#endif //YAUAACPP_STEPCONTAINS_H
