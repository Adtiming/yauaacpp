//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_INVALIDPARSERCONFIGURATIONEXCEPTION_H
#define YAUAACPP_INVALIDPARSERCONFIGURATIONEXCEPTION_H

#include "../yauaacpp_def.h"
#include <exception>

namespace ycpp {
    class InvalidParserConfigurationException : public std::exception {
    public:
        explicit InvalidParserConfigurationException(const std::string & message) {
            this->message = message;
        }
        InvalidParserConfigurationException(const std::string & message, const std::exception & e) {
            this->message = message;
        }

        const char* what() const noexcept override {
            return this->message.c_str();
        }

        std::string message;
    };
}

#endif //YAUAACPP_INVALIDPARSERCONFIGURATIONEXCEPTION_H
