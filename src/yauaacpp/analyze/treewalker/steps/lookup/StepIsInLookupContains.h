//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPISINLOOKUPCONTAINS_H
#define YAUAACPP_STEPISINLOOKUPCONTAINS_H

#include <tool/tool.h>
#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepIsInLookupContains :public Step {

    private:
        std::string          lookupName;
        std::set<std::string> lookupKeys;

     // Private constructor for serialization systems ONLY (like Kryo)
        StepIsInLookupContains() {
        }

    public:
        StepIsInLookupContains(const std::string & lookupName, STRMAP_SP lookup) {
            this->lookupName = lookupName;
            for(auto it=lookup->begin(); it!=lookup->end(); it++){
                this->lookupKeys.emplace(it->first);
            }
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override {
            std::string actualValue = getActualValue(tree, value);
            std::string compareInput = tolowers(actualValue);
            for (const std::string & key : lookupKeys) {
                if (compareInput.npos != compareInput.find(key)) {
                    return walkNextStep(tree, actualValue);
                }
            }
            // Not found:
            return nullptr;
        }


        std::string toString() const override {
            return "IsInLookupContains(@" + lookupName + ")";
        }

    };
}

#endif //YAUAACPP_STEPISINLOOKUPCONTAINS_H
