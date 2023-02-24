//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPISINLOOKUPPREFIX_H
#define YAUAACPP_STEPISINLOOKUPPREFIX_H


#include <utils/PrefixMap.h>
#include <utils/StringPrefixMap.h>
#include "yauaacpp_def.h"
#include "../Step.h"


namespace ycpp {

    class StepIsInLookupPrefix :public Step {
    private:
        std::string            lookupName;
        PrefixMap<std::string> * prefixMap;

         // Private constructor for serialization systems ONLY (like Kryo)
        StepIsInLookupPrefix() {
            prefixMap = nullptr;
        }

    public:
        ~StepIsInLookupPrefix() override;

        StepIsInLookupPrefix(const std::string & lookupName, STRMAP_SP prefixList);


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override;


        std::string toString() const override {
            return "IsInLookupPrefix(@" + lookupName + ")";
        }

};

}

#endif //YAUAACPP_STEPISINLOOKUPPREFIX_H
