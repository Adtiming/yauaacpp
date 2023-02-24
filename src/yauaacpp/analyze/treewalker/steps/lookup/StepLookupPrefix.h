//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPLOOKUPPREFIX_H
#define YAUAACPP_STEPLOOKUPPREFIX_H

#include "yauaacpp_def.h"
#include "../Step.h"
#include "utils/StringPrefixMap.h"

namespace ycpp {

    class StepLookupPrefix :public Step {
    private:
        std::string            lookupName;
        std::string            defaultValue;
        PrefixMap<std::string> * prefixMap;
        bool           _canFail;

        // Private constructor for serialization systems ONLY (like Kryo)
        StepLookupPrefix() {
            if(prefixMap)
                delete prefixMap;
            prefixMap = nullptr;
            _canFail = true;
        }

    public:
        StepLookupPrefix(const std::string & lookupName, STRMAP_SP prefixList, std::string defaultValue) {
            this->lookupName = lookupName;
            this->defaultValue = defaultValue;
            this->prefixMap = new StringPrefixMap<std::string>(false);
            this->prefixMap->putAll(prefixList);
            _canFail = defaultValue.empty();
        }
        ~StepLookupPrefix();


        bool canFail() override {
            return _canFail;
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override;

        std::string toString() const override {
            std::string dvs;
            if(defaultValue.empty())
                dvs = "null";
            else
                dvs = defaultValue;
            return "LookupPrefix(@" + lookupName + " ; default="+dvs+")";
        }

    };
}

#endif //YAUAACPP_STEPLOOKUPPREFIX_H
