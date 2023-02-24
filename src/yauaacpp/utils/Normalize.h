//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_NORMALIZE_H
#define YAUAACPP_NORMALIZE_H

#include "yauaacpp_def.h"
#include <regex>

namespace ycpp {
    class Normalize {
    private:
        Normalize() {}
        static std::wregex DEVICE_CLEANUP_PATTERN_1;
        static std::wregex DEVICE_CLEANUP_PATTERN_2;
        static std::wregex DEVICE_CLEANUP_PATTERN_3;
        static std::wregex DEVICE_CLEANUP_PATTERN_4;


        static bool isTokenSeparator(uint16_t letter) {
            switch (letter) {
                case ' ':
                case '-':
                case '_':
                case '/':
                    return true;
                default:
                    return false;
            }
        }

    public:
        static std::string brand(const std::string & brand);


        static std::string cleanupDeviceBrandName(const std::string & deviceBrand, const std::string & deviceName);

        static std::string email(const std::string & email);

        static std::wstring replaceString(
                const std::wstring & input,
                const std::wstring & searchFor,
                const std::wstring & replaceWith
        );

        static bool isLowerCase(const std::string & text);

    };
}
#endif //YAUAACPP_NORMALIZE_H
