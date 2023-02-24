//
// Created by sunxg on 22-2-3.
//

#include "AntlrUtils.h"

namespace ycpp {
    antlr4::tree::ParseTree * AntlrUtils::NULL_PARSE_TREE = init();

    std::string AntlrUtils::getSourceText(antlr4::ParserRuleContext *ctx) {
        if (ctx == nullptr) {
            return "";
        }
        if (ctx->start == nullptr || ctx->stop == nullptr) {
            return ctx->getText();
        }
        int startIndex = ctx->start->getStartIndex();
        int stopIndex = ctx->stop->getStopIndex();
        if (stopIndex < startIndex) {
            return ""; // Just return the empty string.
        }
        antlr4::CharStream * inputStream = ctx->start->getInputStream();
        return inputStream->getText(antlr4::misc::Interval((size_t)startIndex, (size_t)stopIndex));
    }

}