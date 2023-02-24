//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPEXTRACTBRANDFROMURL_H
#define YAUAACPP_STEPEXTRACTBRANDFROMURL_H

#include <utils/HostnameExtracter.h>
#include "yauaacpp_def.h"


namespace ycpp {
    class StepExtractBrandFromUrl :public Step {

    public:
        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override {
            std::string actualValue = getActualValue(tree, value);
            std::string filteredValue = HostnameExtracter::extractBrandFromUrl(actualValue);
            return walkNextStep(tree, filteredValue);
        }


        std::string toString() const override {
            return "ExtractBrandFromUrl()";
        }

    };
}

#endif //YAUAACPP_STEPEXTRACTBRANDFROMURL_H
