//
// Created by sunxg on 22-1-30.
//

#include "TreeExpressionEvaluator.h"
#include "../Matcher.h"
#include "ImmutableUserAgent.h"

namespace ycpp {
    class UserAgentTreeWalkerVisitorImp : public UserAgentTreeWalkerBaseVisitor {
    private:

        antlrcpp::Any visitLookupsFailOnFixedString(antlr4::tree::ParseTree * matcherTree) {
            antlrcpp::Any value = visit(matcherTree);
            if (value.isNull()) {
                return value;
            }
            // Now we know this is a fixed value lookup ... JUST DON'T as it is needless.
            throw InvalidParserConfigurationException("A lookup for a fixed input value is a needless complexity.");
        }

    public:
        bool shouldVisitNextChild(antlr4::tree::ParseTree * node, const antlrcpp::Any & currentResult) override {
            return currentResult.isNull();
        }

        antlrcpp::Any aggregateResult(antlrcpp::Any aggregate, const antlrcpp::Any & nextResult) override {
            return nextResult.isNull() ? aggregate : nextResult;
        }

        // =================
        // Having a lookup that provides a fixed value yields an error as it complicates things needlessly
        antlrcpp::Any visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        antlrcpp::Any visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        antlrcpp::Any visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext * ctx) override {
        return visitLookupsFailOnFixedString(ctx->matcher());
        }

        antlrcpp::Any visitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        antlrcpp::Any visitMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        antlrcpp::Any visitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        antlrcpp::Any visitMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }


        // =================


        antlrcpp::Any visitPathFixedValue(UserAgentTreeWalkerParser::PathFixedValueContext * ctx) override {
            return std::make_shared<std::string>(ctx->value->getText());
        }
    };

    std::string TreeExpressionEvaluator::calculateFixedValue(antlr4::ParserRuleContext * requiredPattern) {
        if(vistor) delete vistor;
        vistor = new UserAgentTreeWalkerVisitorImp();
        antlrcpp::Any r = vistor->visit(requiredPattern);
        if(!r.isNull())
            return *r.as< std::shared_ptr<std::string> >();
        else
            return "";
    }

    std::shared_ptr<WalkResult>
    TreeExpressionEvaluator::evaluate(antlr4::tree::ParseTree *tree, const std::string & key, const std::string &value) {
        if (verbose) {
            LOG::error( "Evaluate: %s => %s", key.c_str(), value.c_str());
            LOG::error( "Pattern : %s", requiredPatternText.c_str());
            LOG::error( "WalkList: %s", walkList->toString().c_str());
        }
        std::shared_ptr<WalkResult> result = walkList->walk(tree, value);
        if (verbose) {
            LOG::error( "Evaluate: Result = %s", result == nullptr ? "null" : result->getValue().c_str());
        }
        return result;
    }

    bool TreeExpressionEvaluator::mustHaveMatches() {
        return walkList->mustHaveMatches();
    }

    WalkList *TreeExpressionEvaluator::getWalkListForUnitTesting() {
        return walkList;
    }

    long TreeExpressionEvaluator::pruneTrailingStepsThatCannotFail() {
        return walkList->pruneTrailingStepsThatCannotFail();
    }

    TreeExpressionEvaluator::~TreeExpressionEvaluator() {
        if(walkList) delete walkList;
        if(vistor) delete vistor;
    }

    TreeExpressionEvaluator::TreeExpressionEvaluator(antlr4::ParserRuleContext *requiredPattern,
                                                     Matcher * matcher, bool verbose) : verbose(verbose),requiredPatternText(requiredPattern->getText())
    {
        vistor = nullptr;
        walkList = new WalkList(requiredPattern, matcher->getLookups(),
                                matcher->getLookupSets(), verbose);
        fixedValue = calculateFixedValue(requiredPattern);
    }
}