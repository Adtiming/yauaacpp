//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_TREEEXPRESSIONEVALUATOR_H
#define YAUAACPP_TREEEXPRESSIONEVALUATOR_H

#include "yauaacpp_def.h"
#include <analyze/treewalker/steps/WalkList.h>
#include "ParserRuleContext.h"

namespace ycpp {

    class UserAgentTreeWalkerVisitorImp;

    class TreeExpressionEvaluator {
    private:
        bool verbose;

        std::string requiredPatternText;
        WalkList * walkList;
        std::string fixedValue;
        UserAgentTreeWalkerVisitorImp * vistor;

         // Private constructor for serialization systems ONLY (like Kryo)
        TreeExpressionEvaluator() {
            verbose = false;
            walkList = nullptr;
            vistor = nullptr;
        }

        std::string calculateFixedValue(antlr4::ParserRuleContext * requiredPattern);

    public:
        explicit TreeExpressionEvaluator(antlr4::ParserRuleContext *requiredPattern,
                                   Matcher *matcher,
                                   bool verbose);
        ~TreeExpressionEvaluator();

        bool isEmpty() {
            return walkList->isEmpty();
        }

        void destroy() {
            walkList->destroy();
        }

        /**
         * @return The fixed value in case of a fixed value. NULL if a dynamic value
         */
        std::string getFixedValue() {
            return fixedValue;
        }



        // ------------------------------------------

        std::shared_ptr<WalkResult> evaluate(antlr4::tree::ParseTree * tree, const std::string & key, const std::string & value);

        bool mustHaveMatches();

        WalkList * getWalkListForUnitTesting();

        long pruneTrailingStepsThatCannotFail();
    };

}

#endif //YAUAACPP_TREEEXPRESSIONEVALUATOR_H
