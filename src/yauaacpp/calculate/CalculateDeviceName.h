//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_CALCULATEDEVICENAME_H
#define YAUAACPP_CALCULATEDEVICENAME_H

#include "yauaacpp_def.h"
#include "FieldCalculator.h"
#include <regex>
#include <UserAgent.h>
#include <utils/Normalize.h>

namespace ycpp {

    class CalculateDeviceName : public FieldCalculator {

    private:

        static std::regex CLEAN_1_PATTERN;

        std::string removeBadSubStrings(const std::string & input) {
            return std::regex_replace(input,CLEAN_1_PATTERN,std::string(""));
        }


    public:
        void calculate(std::shared_ptr<MutableUserAgent> userAgent) override;


        std::string getCalculatedFieldName() {
            return DEVICE_NAME;
        }


        std::set<std::string> getDependencies() {
            std::set<std::string> t;
            t.emplace(DEVICE_BRAND);
            return t;
        }


        std::string toString() {
            return std::string("Calculate ") + DEVICE_NAME;
        }

    };
}
#endif //YAUAACPP_CALCULATEDEVICENAME_H
