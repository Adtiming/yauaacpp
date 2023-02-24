//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_WALKLIST_H
#define YAUAACPP_WALKLIST_H

#include <analyze/InvalidParserConfigurationException.h>
#include <AbstractUserAgentAnalyzerDirect.h>
#include "yauaacpp_def.h"
#include "UserAgentTreeWalkerBaseVisitor.h"


namespace ycpp {
    class Step;
    class WalkResult {
    private:

        antlr4::tree::ParseTree * tree;
        std::string value;

    public:
        WalkResult(antlr4::tree::ParseTree * tree, const std::string & value) {
            this->tree = tree;
            this->value = value;
        }

        antlr4::tree::ParseTree * getTree() {
            return tree;
        }

        std::string getValue() {
            return value;
        }

        std::string toString() {
            std::ostringstream o;
            o << "WalkResult{"<<"tree=";
            o << (tree == nullptr ? ">>>NULL<<<" : tree->getText().c_str());
            o << ", value=";
            if( value == "" )
                o <<">>>NULL<<<" ;
            else
                o << '\'' << value << '\'';
            o << '}';
            return o.str();
        }
    };

    class WalkList {
    private:
        // Private constructor for serialization systems ONLY (like Kryo)
        WalkList() {
            verbose = false;
            _mustHaveMatches = 0;
        }

        std::shared_ptr<MAPMAPS> lookups;
        std::shared_ptr<MAPSETS> lookupSets;
        std::vector<std::shared_ptr<Step> > steps;

        bool verbose;

        void linkSteps();

        int _mustHaveMatches; // 0-not set, 1-set to true, 2-set to false

    public:

        WalkList(antlr4::ParserRuleContext * requiredPattern,
                 std::shared_ptr<MAPMAPS> lookups,
                 std::shared_ptr<MAPSETS> lookupSets,
                 bool verbose);
        ~WalkList();



        void destroy();



        bool isEmpty() {
            return steps.empty();
        }




        long pruneTrailingStepsThatCannotFail();



        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree *tree, const std::string & value);



        std::shared_ptr<Step> getFirstStep();

        bool mustHaveMatches();

        std::string toString();

        friend class WalkListBuilder;
    };

    class WalkListBuilder :public UserAgentTreeWalkerBaseVisitor {

    private:
        WalkList * walkList;

        void fromHereItCannotBeInHashMapAnymore() {
            foundHashEntryPoint = true;
        }

        bool stillGoingToHashMap() {
            return !foundHashEntryPoint;
        }

        void add(std::shared_ptr<Step> step) {
            if (foundHashEntryPoint) {
                walkList->steps.push_back(step);
            }
        }

        void visitNext(UserAgentTreeWalkerParser::PathContext * nextStep) {
            if (nextStep != nullptr) {
                visit(nextStep);
            }
        }

        std::string extractText(antlr4::Token * token) {
            if (token == nullptr) {
                return "";
            }
            return token->getText();
        }
        STRMAP_SP getLookup(const std::string & lookupName);

        antlrcpp::Any doStepNextN(UserAgentTreeWalkerParser::PathContext * nextStep, int nextSteps);
        antlrcpp::Any doStepPrevN(UserAgentTreeWalkerParser::PathContext * nextStep, int prevSteps);
        STRSET_SP getLookupSet(const std::string & lookupSetName);
        // Because we are jumping in 'mid way' we need to skip creating steps until that point.
        bool foundHashEntryPoint = false;

    public:
        explicit WalkListBuilder(WalkList * walkList);
        antlrcpp::Any visitMatcherPath(UserAgentTreeWalkerParser::MatcherPathContext * ctx) override {
            visit(ctx->basePath());
            return nullptr; // antlrcpp::Any
        }



        antlrcpp::Any visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext * ctx) override;


        antlrcpp::Any visitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext * ctx) override;


        antlrcpp::Any visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext * ctx) override;


        antlrcpp::Any visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext * ctx) override;



        antlrcpp::Any visitMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext * ctx) override;



        antlrcpp::Any visitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext * ctx) override;


        antlrcpp::Any visitMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext * ctx) override;


        antlrcpp::Any visitMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext * ctx) override;




        antlrcpp::Any visitMatcherCleanVersion(UserAgentTreeWalkerParser::MatcherCleanVersionContext * ctx) override;


        antlrcpp::Any visitMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext * ctx) override;


        antlrcpp::Any visitMatcherNormalizeBrand(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext * ctx) override;


        antlrcpp::Any visitMatcherExtractBrandFromUrl(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext * ctx) override;


        antlrcpp::Any visitMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext * ctx) override;


        antlrcpp::Any visitMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext * ctx) override;


        antlrcpp::Any visitMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext * ctx) override;


        antlrcpp::Any visitMatcherWordRange(UserAgentTreeWalkerParser::MatcherWordRangeContext * ctx) override;


        antlrcpp::Any visitMatcherSegmentRange(UserAgentTreeWalkerParser::MatcherSegmentRangeContext * ctx) override;


        antlrcpp::Any visitMatcherPathIsNull(UserAgentTreeWalkerParser::MatcherPathIsNullContext * ctx) override;


        antlrcpp::Any visitPathVariable(UserAgentTreeWalkerParser::PathVariableContext * ctx) override;


        antlrcpp::Any visitPathWalk(UserAgentTreeWalkerParser::PathWalkContext * ctx) override;


        antlrcpp::Any visitStepDown(UserAgentTreeWalkerParser::StepDownContext * ctx) override;


        antlrcpp::Any visitStepUp(UserAgentTreeWalkerParser::StepUpContext * ctx) override;

        //----

        antlrcpp::Any visitStepNext(UserAgentTreeWalkerParser::StepNextContext * ctx) override;



        antlrcpp::Any visitStepNext2(UserAgentTreeWalkerParser::StepNext2Context * ctx) override;


        antlrcpp::Any visitStepNext3(UserAgentTreeWalkerParser::StepNext3Context * ctx) override;


        antlrcpp::Any visitStepNext4(UserAgentTreeWalkerParser::StepNext4Context * ctx) override;

        //----

        antlrcpp::Any visitStepPrev(UserAgentTreeWalkerParser::StepPrevContext * ctx) override;



        antlrcpp::Any visitStepPrev2(UserAgentTreeWalkerParser::StepPrev2Context * ctx) override;


        antlrcpp::Any visitStepPrev3(UserAgentTreeWalkerParser::StepPrev3Context * ctx) override;


        antlrcpp::Any visitStepPrev4(UserAgentTreeWalkerParser::StepPrev4Context * ctx) override;

        //----

        antlrcpp::Any visitStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext * ctx) override;


        antlrcpp::Any visitStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext * ctx) override;


        antlrcpp::Any visitStepIsInSet(UserAgentTreeWalkerParser::StepIsInSetContext * ctx) override;


        antlrcpp::Any visitStepIsNotInSet(UserAgentTreeWalkerParser::StepIsNotInSetContext * ctx) override;




        antlrcpp::Any visitStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext * ctx) override;


        antlrcpp::Any visitStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext * ctx) override;


        antlrcpp::Any visitStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext * ctx) override;


        antlrcpp::Any visitStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext * ctx) override;


        antlrcpp::Any visitStepWordRange(UserAgentTreeWalkerParser::StepWordRangeContext * ctx) override;


        antlrcpp::Any visitStepBackToFull(UserAgentTreeWalkerParser::StepBackToFullContext * ctx) override;

    };
}

#endif //YAUAACPP_WALKLIST_H
