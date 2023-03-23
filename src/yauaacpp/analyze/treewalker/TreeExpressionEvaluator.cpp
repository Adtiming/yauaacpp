//
// Created by sunxg on 22-1-30.
//

#include "TreeExpressionEvaluator.h"
#include "../Matcher.h"
#include "ImmutableUserAgent.h"

namespace ycpp {
    class UserAgentTreeWalkerVisitorImp : public UserAgentTreeWalkerBaseVisitor {
    private:

        std::any visitLookupsFailOnFixedString(antlr4::tree::ParseTree * matcherTree) {
            std::any value = visit(matcherTree);
            if (!value.has_value()) {
                return value;
            }
            // Now we know this is a fixed value lookup ... JUST DON'T as it is needless.
            throw InvalidParserConfigurationException("A lookup for a fixed input value is a needless complexity.");
        }

    public:
        bool shouldVisitNextChild(antlr4::tree::ParseTree * node, const std::any & currentResult) override {
            return !currentResult.has_value();
        }

        // =================
        // Having a lookup that provides a fixed value yields an error as it complicates things needlessly
        std::any visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        std::any visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        std::any visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext * ctx) override {
        return visitLookupsFailOnFixedString(ctx->matcher());
        }

        std::any visitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        std::any visitMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        std::any visitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }

        std::any visitMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext * ctx) override {
            return visitLookupsFailOnFixedString(ctx->matcher());
        }


        // =================


        std::any visitPathFixedValue(UserAgentTreeWalkerParser::PathFixedValueContext * ctx) override {
            return std::make_shared<std::string>(ctx->value->getText());
        }
    };

    std::string TreeExpressionEvaluator::calculateFixedValue(antlr4::ParserRuleContext * requiredPattern) {
        if(vistor) delete vistor;
        vistor = new UserAgentTreeWalkerVisitorImp();
        std::any r = vistor->visit(requiredPattern);
        if(r.has_value())
            return *std::any_cast<std::shared_ptr<std::string>>(r);
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