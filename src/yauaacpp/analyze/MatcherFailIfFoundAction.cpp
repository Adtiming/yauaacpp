//
// Created by sunxg on 22-2-6.
//

#include "MatcherFailIfFoundAction.h"
#include "analyze/treewalker/TreeExpressionEvaluator.h"
#include "MatcherAction.h"
#include "Matcher.h"
#include "tool/tool.h"
#include "ImmutableUserAgent.h"

namespace ycpp {
    std::string MatcherFailIfFoundAction::toString() {
        std::ostringstream o;
        o << "FailIfFound.(" << matcher->getMatcherSourceLocation().c_str()<<"): " << getMatchExpression().c_str();
        return o.str();
    }

    long MatcherFailIfFoundAction::initialize(MatcherAction * this_action) {
        long newEntries = MatcherAction::initialize(this_action);
        newEntries -= evaluator->pruneTrailingStepsThatCannotFail();
        return newEntries;
    }

    void
    MatcherFailIfFoundAction::inform(const std::string &key, const std::string &value, antlr4::tree::ParseTree *result) {
        MatcherAction::inform(key, value, result);
        // If there are NO additional steps then we can immediately conclude this is matcher must fail.
        if (evaluator->isEmpty()) {
            matcher->failImmediately();
        }
    }

    int g_MatcherFailIfFoundAction_cnt = 0;
    MatcherFailIfFoundAction::~MatcherFailIfFoundAction() {
        g_MatcherFailIfFoundAction_cnt --;
        //printf("g_MatcherFailIfFoundAction_cnt = %d\n",g_MatcherFailIfFoundAction_cnt);
    }

    MatcherFailIfFoundAction::MatcherFailIfFoundAction() {
        g_MatcherFailIfFoundAction_cnt ++;
    }

    MatcherFailIfFoundAction::MatcherFailIfFoundAction(const std::string &config, Matcher *matcher) {
        g_MatcherFailIfFoundAction_cnt ++;
        init(config, matcher);
    }

    void MatcherFailIfFoundAction::inform(const std::string &key, std::shared_ptr<WalkResult> foundValue) {
        foundRequiredValue = true;
        if (verbose) {
            LOG::error( "Info FailIfFound: %s", key.c_str());
            LOG::error( "NEED FailIfFound: %s", getMatchExpression().c_str());
            LOG::error( "KEPT FailIfFound: %s", key.c_str());
        }
    }
}