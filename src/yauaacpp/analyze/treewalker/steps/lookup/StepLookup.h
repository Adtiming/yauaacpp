//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPLOOKUP_H
#define YAUAACPP_STEPLOOKUP_H

#include <tool/tool.h>
#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepLookup :public Step {
    private:
        std::string lookupName;
        STRMAP_SP lookup;
        std::string  defaultValue;
        bool _canFail;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepLookup() {
            lookupName = "<< Should not be seen anywhere >>";
            defaultValue = "<< Should not be seen anywhere >>";
            _canFail = false;
        }
    public:
        StepLookup(const std::string & lookupName, const STRMAP_SP lookup, std::string defaultValue) {
            this->lookupName = lookupName;
            this->lookup = lookup;
            this->defaultValue = defaultValue;
            _canFail = defaultValue.empty();
        }


        bool canFail() {
            return _canFail;
        }


        bool mustHaveInput() {
            return _canFail;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) {
            std::string actualValue = getActualValue(tree, value);

            std::string result;
            if (!actualValue.empty()) {
                result = (*lookup)[tolowers(actualValue)];
            }

            if (result.empty()) {
                if (defaultValue.empty()) {
                    return nullptr;
                } else {
                    return walkNextStep(tree, defaultValue);
                }
            }
            return walkNextStep(tree, result);
        }


        std::string toString() const override {
            std::string dvs;
            if(defaultValue.empty())
                dvs = "null";
            else
                dvs = defaultValue;
            return "Lookup(@" + lookupName + " ; default=" + dvs + ")";
        }

    };
}

#endif //YAUAACPP_STEPLOOKUP_H
