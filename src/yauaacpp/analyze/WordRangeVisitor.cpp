//
// Created by sunxg on 22-2-14.
//

#include "WordRangeVisitor.h"

namespace ycpp{

    WordRangeVisitor WordRangeVisitor::WORD_RANGE_VISITOR;
    std::shared_ptr<Range> WordRangeVisitor::getRange(UserAgentTreeWalkerParser::WordRangeContext *ctx) {
        std::any any = WORD_RANGE_VISITOR.visit(ctx);
        return std::any_cast<std::shared_ptr<Range>>(any);
    }

    std::any WordRangeVisitor::visitWordRangeSingleWord(UserAgentTreeWalkerParser::WordRangeSingleWordContext *ctx) {
        int wordNumber = std::stoi(ctx->singleWord->getText());
        return std::make_shared<Range>(
                wordNumber,
                wordNumber);
    }

    std::string Range::toString() const {
        std::string s;
        if (last == -1) {
            s = "[" + itos(first) + "-]";
        } else {
            s = "[" + itos(first) + "-" + itos(last) + "]";
        }
        return s;
    }
}