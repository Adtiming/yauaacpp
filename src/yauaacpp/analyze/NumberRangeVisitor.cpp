//
// Created by sunxg on 22-2-7.
//

#include "NumberRangeVisitor.h"

namespace ycpp {
    std::map<std::string, int> NumberRangeVisitor::MAX_RANGE = initMAX_RANGE();
    NumberRangeVisitor NumberRangeVisitor::NUMBER_RANGE_VISITOR;

    int NumberRangeVisitor::getMaxRange(UserAgentTreeWalkerParser::NumberRangeContext *ctx) {
        antlr4::tree::ParseTree * parent = ctx->parent;
        std::string name = dynamic_cast<UserAgentTreeWalkerParser::StepDownContext*>(parent)->name->getText();
        auto it =  MAX_RANGE.find(name);
        if(it == MAX_RANGE.end())
            return DEFAULT_MAX;
        int maxRange = it->second;
        return maxRange;
    }

    std::map<std::string, int> NumberRangeVisitor::initMAX_RANGE() {
        std::map<std::string, int> t;
        // Hardcoded maximum values because of the parsing rules
        MAX_RANGE["agent"] =                1;
        MAX_RANGE["name"] =                 1;
        MAX_RANGE["key"] =                  1;

        // Did statistics on over 200K real useragents from 2015.
        // These are the maximum values from that test set (+ a little margin)
        MAX_RANGE["value"] =                2; // Max was 2
        MAX_RANGE["version"] =              4; // Max was 4
        MAX_RANGE["comments"] =             2; // Max was 2
        MAX_RANGE["entry"] =               20; // Max was much higher
        MAX_RANGE["product"] =             10; // Max was much higher

        MAX_RANGE["email"] =                2;
        MAX_RANGE["keyvalue"] =             3;
        MAX_RANGE["text"] =                 8;
        MAX_RANGE["url"] =                  2;
        MAX_RANGE["uuid"] =                 2;
        return t;
    }
}
