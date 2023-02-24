//
// Created by sunxg on 22-2-2.
//

#ifndef YAUAACPP_PREHEATCASES_H
#define YAUAACPP_PREHEATCASES_H
#include <string>
#include <vector>

namespace ycpp {
    class PreHeatCases {
    public:
        static std::vector<std::string> USERAGENTS;
        static std::vector<std::string> init();
    };
}

#endif //YAUAACPP_PREHEATCASES_H
