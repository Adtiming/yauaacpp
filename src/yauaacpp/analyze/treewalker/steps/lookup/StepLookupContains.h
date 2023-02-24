//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPLOOKUPCONTAINS_H
#define YAUAACPP_STEPLOOKUPCONTAINS_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepLookupContains :public Step {
    private:
        std::string lookupName;
        STRMAP_SP lookup;
        std::string defaultValue;

        // Private constructor for serialization systems ONLY (like Kryo)
        StepLookupContains() {
            lookupName = "<< Should not be seen anywhere >>";
            defaultValue = "<< Should not be seen anywhere >>";
        }

    public:
        StepLookupContains(const std::string & lookupName, STRMAP_SP lookup, std::string defaultValue) {
            this->lookupName = lookupName;
            this->lookup = lookup;
            this->defaultValue = defaultValue;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override;


        std::string toString() const override {
            std::string dvs;
            if(defaultValue.empty())
                dvs = "null";
            else
                dvs = defaultValue;
            return "LookupContains(@" + lookupName + " ; default="+dvs+")";
        }

    };

}

#endif //YAUAACPP_STEPLOOKUPCONTAINS_H
