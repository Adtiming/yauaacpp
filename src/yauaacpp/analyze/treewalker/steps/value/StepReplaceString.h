//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPREPLACESTRING_H
#define YAUAACPP_STEPREPLACESTRING_H

#include "yauaacpp_def.h"


namespace ycpp {
    class StepReplaceString :public Step {
    private:
        std::string search;
        std::string replace;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepReplaceString() {
            search = "";
            replace = "";
        }

    public:
        StepReplaceString(const std::string & search, std::string replace) {
        this->search = search;
        this->replace = replace;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override {
            std::string actualValue = getActualValue(tree, value);
            string_replace(actualValue, search, replace);
            return walkNextStep(tree, actualValue);
        }


        bool canFail() override {
            return false;
        }


        std::string toString() const override {
            return "ReplaceString(\""+search+"\";\""+replace+"\")";
        }
    };

}

#endif //YAUAACPP_STEPREPLACESTRING_H
