//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPDEFAULTIFNULL_H
#define YAUAACPP_STEPDEFAULTIFNULL_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepDefaultIfNull :public Step {
    private:
        std::string  defaultValue;
        bool _canFail;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepDefaultIfNull() {
            defaultValue = "<< Should not be seen anywhere >>";
             _canFail = false;
        }

    public:
        StepDefaultIfNull(const std::string & defaultValue) {
            this->defaultValue = defaultValue;
            _canFail = defaultValue.empty();
        }


        bool canFail() {
            return _canFail;
        }


        bool mustHaveInput() {
            return _canFail;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);


        std::string toString() const override{
            std::string dvs;
            if(defaultValue.empty())
                dvs = "null";
            else
                dvs = defaultValue;
            return "DefaultIfNull(default=" + dvs + ")";
        }

    };

}

#endif //YAUAACPP_STEPDEFAULTIFNULL_H
