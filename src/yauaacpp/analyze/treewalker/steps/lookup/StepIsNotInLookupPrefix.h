//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPISNOTINLOOKUPPREFIX_H
#define YAUAACPP_STEPISNOTINLOOKUPPREFIX_H

#include <utils/PrefixMap.h>
#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepIsNotInLookupPrefix :public Step {
    private:
        std::string            lookupName;
        PrefixMap<std::string> * prefixMap;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepIsNotInLookupPrefix() {
            prefixMap = nullptr;
        }
    public:
        StepIsNotInLookupPrefix(const std::string & lookupName, STRMAP_SP prefixList);

        StepIsNotInLookupPrefix(const std::string & lookupName, STRSET_SP prefixSet);

        ~StepIsNotInLookupPrefix();


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);


        std::string toString() const override {
            return "IsNotInLookupPrefix(@" + lookupName + ")";
        }

    };
}


#endif //YAUAACPP_STEPISNOTINLOOKUPPREFIX_H
