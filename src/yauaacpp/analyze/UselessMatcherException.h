//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_USELESSMATCHEREXCEPTION_H
#define YAUAACPP_USELESSMATCHEREXCEPTION_H

#include "yauaacpp_def.h"

namespace ycpp {

    class UselessMatcherException : public antlr4::RuntimeException{
    public:
         UselessMatcherException(const std::string & message):RuntimeException(message) {
        }
    };

}
#endif //YAUAACPP_USELESSMATCHEREXCEPTION_H
