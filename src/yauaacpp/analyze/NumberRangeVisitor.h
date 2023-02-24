//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_NUMBERRANGEVISITOR_H
#define YAUAACPP_NUMBERRANGEVISITOR_H

#include "yauaacpp_def.h"
#include "NumberRangeList.h"
#include "UserAgentTreeWalkerBaseVisitor.h"

namespace ycpp {

    class NumberRangeVisitor : public UserAgentTreeWalkerBaseVisitor {

    private:
        enum {
            DEFAULT_MIN = 1,
            DEFAULT_MAX = 10
        };

        static std::map<std::string, int> MAX_RANGE;

        static std::map<std::string, int> initMAX_RANGE();

        NumberRangeVisitor() {
        }

        static int getMaxRange(UserAgentTreeWalkerParser::NumberRangeContext * ctx);
    public:
        static NumberRangeVisitor NUMBER_RANGE_VISITOR;

        static antlrcpp::Any getList(UserAgentTreeWalkerParser::NumberRangeContext * ctx) {
            return NUMBER_RANGE_VISITOR.visit(ctx);
        }


        antlrcpp::Any visitNumberRangeStartToEnd(UserAgentTreeWalkerParser::NumberRangeStartToEndContext * ctx) override {
            return std::make_shared<NumberRangeList>(
                    std::stoi(ctx->rangeStart->getText()),
                    std::stoi(ctx->rangeEnd->getText()));
        }


        antlrcpp::Any visitNumberRangeOpenStartToEnd(UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext * ctx) override {
            return std::make_shared<NumberRangeList>(
                    1,
                    std::stoi(ctx->rangeEnd->getText()));
        }


        antlrcpp::Any visitNumberRangeStartToOpenEnd(UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext * ctx) override {
            return std::make_shared<NumberRangeList>(
                    std::stoi(ctx->rangeStart->getText()),
                    getMaxRange(ctx));
        }


        antlrcpp::Any visitNumberRangeSingleValue(UserAgentTreeWalkerParser::NumberRangeSingleValueContext * ctx) override {
            int value = std::stoi(ctx->count->getText());
            return std::make_shared<NumberRangeList>(value, value);
        }


        antlrcpp::Any visitNumberRangeAll(UserAgentTreeWalkerParser::NumberRangeAllContext * ctx) override {
            return std::make_shared<NumberRangeList>(DEFAULT_MIN, getMaxRange(ctx));
        }


        antlrcpp::Any visitNumberRangeEmpty(UserAgentTreeWalkerParser::NumberRangeEmptyContext * ctx) override {
            return std::make_shared<NumberRangeList>(DEFAULT_MIN, getMaxRange(ctx));
        }
    };

}
#endif //YAUAACPP_NUMBERRANGEVISITOR_H
