//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPISINSET_H
#define YAUAACPP_STEPISINSET_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepIsInSet :public Step {

    private:
        std::string listName;
        STRSET_SP list;

        // Private constructor for serialization systems ONLY (like Kryo)
        StepIsInSet() {
            listName = "<< Should not be seen anywhere >>";
        }

    public:
        StepIsInSet(const std::string & listName, STRSET_SP list) {
            this->listName = listName;
            this->list = list;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);

        std::string toString() const override {
            return "IsInSet(@" + listName + ")";
        }

    };

}

#endif //YAUAACPP_STEPISINSET_H
