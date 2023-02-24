//
// Created by sunxg on 22-2-11.
//

#ifndef YAUAACPP_NOTINANTLR4_H
#define YAUAACPP_NOTINANTLR4_H

#include "antlr4-runtime.h"
namespace antlr4 {
    class NoSuchElementException: public RuntimeException{
    public:
        NoSuchElementException(const std::string &msg = "") : RuntimeException(msg) {}
        NoSuchElementException(NoSuchElementException const&) = default;
        ~NoSuchElementException() override {};
        NoSuchElementException& operator=(NoSuchElementException const&) = default;
    };
    class InvalidParserConfigurationException: public RuntimeException{
    public:
        InvalidParserConfigurationException(const std::string &msg = "") : RuntimeException(msg) {}
        InvalidParserConfigurationException(InvalidParserConfigurationException const&) = default;
        ~InvalidParserConfigurationException() override {};
        InvalidParserConfigurationException& operator=(InvalidParserConfigurationException const&) = default;
    };
}

#endif //YAUAACPP_NOTINANTLR4_H
