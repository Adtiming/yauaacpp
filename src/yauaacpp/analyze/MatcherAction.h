//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MATCHERACTION_H
#define YAUAACPP_MATCHERACTION_H

#include "yauaacpp_def.h"

#include "UserAgentTreeWalkerBaseVisitor.h"

#include "treewalker/steps/WalkList.h"
#include <functional>

namespace ycpp {
    class Matcher;
    class MatchesList;
    class WalkResult;
    class TreeExpressionEvaluator;
    class InitErrorListener;
    class UserAgentTreeWalkerLexer;

    class UnQuoteValues : public UserAgentTreeWalkerBaseVisitor {
    private:
        void unQuoteToken(antlr4::Token *token);

    public:
        antlrcpp::Any visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext* ctx) override {
            unQuoteToken(ctx->defaultValue);
            return UserAgentTreeWalkerBaseVisitor::visitMatcherPathLookup(ctx);
        }


        antlrcpp::Any visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext* ctx) override {
            unQuoteToken(ctx->defaultValue);
            return UserAgentTreeWalkerBaseVisitor::visitMatcherPathLookupContains(ctx);
        }


        antlrcpp::Any visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext* ctx) override {
            unQuoteToken(ctx->defaultValue);
            return UserAgentTreeWalkerBaseVisitor::visitMatcherPathLookupPrefix(ctx);
        }


        antlrcpp::Any visitMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext* ctx) override {
            unQuoteToken(ctx->defaultValue);
            return UserAgentTreeWalkerBaseVisitor::visitMatcherDefaultIfNull(ctx);
        }


        antlrcpp::Any visitPathFixedValue(UserAgentTreeWalkerParser::PathFixedValueContext* ctx) override {
            unQuoteToken(ctx->value);
            return UserAgentTreeWalkerBaseVisitor::visitPathFixedValue(ctx);
        }


        antlrcpp::Any visitMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext* ctx) override {
            unQuoteToken(ctx->prefix);
            unQuoteToken(ctx->postfix);
            return UserAgentTreeWalkerBaseVisitor::visitMatcherConcat(ctx);
        }


        antlrcpp::Any visitMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext* ctx) override {
            unQuoteToken(ctx->prefix);
            return UserAgentTreeWalkerBaseVisitor::visitMatcherConcatPrefix(ctx);
        }


        antlrcpp::Any visitMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext* ctx) override {
            unQuoteToken(ctx->postfix);
            return UserAgentTreeWalkerBaseVisitor::visitMatcherConcatPostfix(ctx);
        }


        antlrcpp::Any visitMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext* ctx) override {
            unQuoteToken(ctx->search);
            unQuoteToken(ctx->replace);
            return UserAgentTreeWalkerBaseVisitor::visitMatcherReplaceString(ctx);
        }


        antlrcpp::Any visitStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext* ctx) override {
            unQuoteToken(ctx->value);
            return UserAgentTreeWalkerBaseVisitor::visitStepEqualsValue(ctx);
        }


        antlrcpp::Any visitStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext* ctx) override {
            unQuoteToken(ctx->value);
            return UserAgentTreeWalkerBaseVisitor::visitStepNotEqualsValue(ctx);
        }


        antlrcpp::Any visitStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext* ctx) override {
            unQuoteToken(ctx->value);
            return UserAgentTreeWalkerBaseVisitor::visitStepStartsWithValue(ctx);
        }


        antlrcpp::Any visitStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext* ctx) override {
            unQuoteToken(ctx->value);
            return UserAgentTreeWalkerBaseVisitor::visitStepEndsWithValue(ctx);
        }


        antlrcpp::Any visitStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext* ctx) override {
            unQuoteToken(ctx->value);
            return UserAgentTreeWalkerBaseVisitor::visitStepContainsValue(ctx);
        }


        antlrcpp::Any visitStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext* ctx) override {
            unQuoteToken(ctx->value);
            return UserAgentTreeWalkerBaseVisitor::visitStepNotContainsValue(ctx);
        }
    };

    class MatcherAction {
    public:
        MatcherAction();
        virtual ~MatcherAction();
        typedef std::function<int(MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)>
                CalculateInformPathFunction ;
    private:
        std::string matchExpression;
        MatchesList * matches;
        bool verbosePermanent = false;
        bool verboseTemporary = false;

        InitErrorListener * errorListener;
        antlr4::ANTLRInputStream * input;
        UserAgentTreeWalkerLexer * lexer;
        antlr4::BufferedTokenStream * tokens;
        UserAgentTreeWalkerParser * parser;
        UnQuoteValues * uqvs;
        void setVerbose(bool newVerbose) {
            setVerbose(newVerbose, false);
        }

        static std::map<std::string, CalculateInformPathFunction> CALCULATE_INFORM_PATH;

        friend class InitErrorListener;

    protected:
        Matcher * matcher;

    public:
        TreeExpressionEvaluator * evaluator;

        TreeExpressionEvaluator * getEvaluatorForUnitTesting() {
            return evaluator;
        }


        bool _mustHaveMatches = false;

        bool mustHaveMatches() {
            return _mustHaveMatches;
        }

        void destroy();

        bool verbose = false;

        void setVerbose(bool newVerbose, bool temporary) {
            this->verbose = newVerbose;
            if (!temporary) {
                this->verbosePermanent = newVerbose;
            }
            this->verboseTemporary = temporary;
        }

        std::string getMatchExpression() {
            return matchExpression;
        }



        void init(const std::string & newMatchExpression, Matcher * newMatcher);

        virtual long initialize(MatcherAction * this_action);



        virtual antlr4::ParserRuleContext * parseWalkerExpression(UserAgentTreeWalkerParser * parser) = 0;




        virtual void setFixedValue(const std::string & newFixedValue)= 0;

        /**
         * For each key that this action wants to be notified for this method is called.
         * Note that on a single parse event the same name CAN be called multiple times!!
         *
         * @param key    The key of the node
         * @param value  The value that was found
         * @param result The node in the parser tree where the match occurred
         */
        void inform(const std::string & key, const std::string & value, antlr4::tree::ParseTree * result);

        virtual void inform(const std::string & key, std::shared_ptr<WalkResult> foundValue) = 0;

        /**
         * @return If it is impossible that this can be valid it returns true, else false.
         */
        bool cannotBeValid();

        /**
         * Called after all nodes have been notified.
         * @return true if the obtainResult result was valid. False will fail the entire matcher this belongs to.
         */
        virtual bool obtainResult() = 0;

        bool isValidWithoutMatches();

        /**
         * Optimization: Only if there is a possibility that all actions for this matcher CAN be valid do we
         * actually perform the analysis and do the (expensive) tree walking and matching.
         */
        void processInformedMatches();

        // ============================================================================================================




        static std::map<std::string, CalculateInformPathFunction> initCALCULATE_INFORM_PATH();

        static int calculateInformPath(MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree);

        // ============================================================================================================

        virtual void reset();

        MatchesList * getMatches() {
            return matches;
        }


        virtual std::string toString();
    };

}
#endif //YAUAACPP_MATCHERACTION_H
