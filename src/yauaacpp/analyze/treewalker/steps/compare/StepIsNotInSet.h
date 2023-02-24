//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPISNOTINSET_H
#define YAUAACPP_STEPISNOTINSET_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepIsNotInSet :public Step {
    private:
        std::string listName;
        STRSET_SP list;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepIsNotInSet() {
            listName = "<< Should not be seen anywhere >>";
        }
    public:
        StepIsNotInSet(const std::string & listName, STRSET_SP list) {
            this->listName = listName;
            this->list = list;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);


        std::string toString() const override {
                    std::ostringstream o;
            return "IsNotInSet(@" + listName + ")";
        }

    };
}

#endif //YAUAACPP_STEPISNOTINSET_H
