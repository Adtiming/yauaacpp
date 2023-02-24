//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MATCHERLIST_H
#define YAUAACPP_MATCHERLIST_H

#include "yauaacpp_def.h"
#include "Matcher.h"

namespace ycpp {

    class MatcherList: public std::list<Matcher *> {
    };
}
#endif //YAUAACPP_MATCHERLIST_H
