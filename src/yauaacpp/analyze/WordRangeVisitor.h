//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_WORDRANGEVISITOR_H
#define YAUAACPP_WORDRANGEVISITOR_H

#include "yauaacpp_def.h"
#include <analyser/cpp/UserAgentTreeWalkerBaseVisitor.h>
#include <analyser/cpp/UserAgentTreeWalkerParser.h>
#include "../Range.h"
#include "tool/tool.h"


namespace ycpp {

    class WordRangeVisitor : public UserAgentTreeWalkerBaseVisitor{
    private:
        static WordRangeVisitor WORD_RANGE_VISITOR;
        WordRangeVisitor() = default;;

    public:

        static std::shared_ptr<Range> getRange(UserAgentTreeWalkerParser::WordRangeContext * ctx);


        std::any visitWordRangeStartToEnd(UserAgentTreeWalkerParser::WordRangeStartToEndContext * ctx) override {
            return std::make_shared<Range>(
                    std::stoi(ctx->firstWord->getText()),
                    std::stoi(ctx->lastWord->getText()) );
        }


        std::any visitWordRangeFirstWords(UserAgentTreeWalkerParser::WordRangeFirstWordsContext * ctx) override {
            return std::make_shared<Range>(
                    1,
                    std::stoi(ctx->lastWord->getText()));
        }


        std::any visitWordRangeLastWords(UserAgentTreeWalkerParser::WordRangeLastWordsContext * ctx) override {
            return std::make_shared<Range>(
                    std::stoi(ctx->firstWord->getText()),
                    -1);
        }


        std::any visitWordRangeSingleWord(UserAgentTreeWalkerParser::WordRangeSingleWordContext * ctx) override;
    };



}

#endif //YAUAACPP_WORDRANGEVISITOR_H
