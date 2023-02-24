//
// Created by sunxg on 22-4-7.
//

#ifndef YAUAACPP_MATCHERINSTANCE_H
#define YAUAACPP_MATCHERINSTANCE_H

#include <vector>

namespace ycpp {
    class Matcher;
    class MatchersInstance {
    public:
        std::vector<Matcher *> allMatchers;
        std::vector<Matcher *> zeroInputMatchers;
        bool matchersHaveBeenInitialized = false;
    public:
        std::vector<Matcher *> getAllMatchers() {
            return allMatchers;
        }
    };
}


#endif //YAUAACPP_MATCHERINSTANCE_H
