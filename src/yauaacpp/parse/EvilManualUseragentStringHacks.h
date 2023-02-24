//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_EVILMANUALUSERAGENTSTRINGHACKS_H
#define YAUAACPP_EVILMANUALUSERAGENTSTRINGHACKS_H

#include "yauaacpp_def.h"
#include <regex>

namespace ycpp {

    class EvilManualUseragentStringHacks {
    private:
        EvilManualUseragentStringHacks() {}

        static std::regex MISSING_PRODUCT_AT_START;
        static std::regex MISSING_SPACE;
        static std::regex MULTIPLE_SPACES;
        static std::regex AVOID_BASE64_MATCH;
        static std::regex ANDROID_DASH_VERSION;
        static std::regex TENCENT_NETTYPE_FIX;
        static std::regex TENCENT_LANGUAGE_FIX;

    public:
        /**
         * There are a few situations where in order to parse the useragent we need to 'fix it'.
         * Yes, all of this is pure evil but we "have to".
         *
         * @param useragent Raw useragent
         * @return Cleaned useragent
         */
        static std::string fixIt(const std::string & useragent);

    };

}
#endif //YAUAACPP_EVILMANUALUSERAGENTSTRINGHACKS_H
