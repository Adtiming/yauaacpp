//
// Created by sunxg on 22-2-7.
//


#include "MatcherRequireAction.h"
#include "MatcherAction.h"
#include "analyze/treewalker/TreeExpressionEvaluator.h"
#include "ImmutableUserAgent.h"

namespace ycpp{
    long MatcherRequireAction::initialize(MatcherAction * this_action) {
        long newEntries = MatcherAction::initialize(this_action);
        newEntries -= evaluator->pruneTrailingStepsThatCannotFail();
        return newEntries;
    }

    int g_MatcherRequireAction_cnt = 0;
    MatcherRequireAction::~MatcherRequireAction() {
        g_MatcherRequireAction_cnt --;
        //printf("g_MatcherRequireAction_cnt = %d\n",g_MatcherRequireAction_cnt);
    }


    MatcherRequireAction::MatcherRequireAction() {
        g_MatcherRequireAction_cnt ++;
    }

    MatcherRequireAction::MatcherRequireAction(const std::string &config, Matcher *matcher) {
        g_MatcherRequireAction_cnt ++;
        init(config, matcher);
    }


}

