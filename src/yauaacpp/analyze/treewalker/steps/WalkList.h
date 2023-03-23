//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_WALKLIST_H
#define YAUAACPP_WALKLIST_H

#include "yauaacpp_def.h"
#include <analyze/InvalidParserConfigurationException.h>
#include <AbstractUserAgentAnalyzerDirect.h>
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

        std::any doStepNextN(UserAgentTreeWalkerParser::PathContext * nextStep, int nextSteps);
        std::any doStepPrevN(UserAgentTreeWalkerParser::PathContext * nextStep, int prevSteps);
        STRSET_SP getLookupSet(const std::string & lookupSetName);
        // Because we are jumping in 'mid way' we need to skip creating steps until that point.
        bool foundHashEntryPoint = false;

    public:
        explicit WalkListBuilder(WalkList * walkList);
        std::any visitMatcherPath(UserAgentTreeWalkerParser::MatcherPathContext * ctx) override {
            visit(ctx->basePath());
            return nullptr; // std::any
        }



        std::any visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext * ctx) override;


        std::any visitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext * ctx) override;


        std::any visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext * ctx) override;


        std::any visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext * ctx) override;



        std::any visitMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext * ctx) override;



        std::any visitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext * ctx) override;


        std::any visitMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext * ctx) override;


        std::any visitMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext * ctx) override;




        std::any visitMatcherCleanVersion(UserAgentTreeWalkerParser::MatcherCleanVersionContext * ctx) override;


        std::any visitMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext * ctx) override;


        std::any visitMatcherNormalizeBrand(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext * ctx) override;


        std::any visitMatcherExtractBrandFromUrl(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext * ctx) override;


        std::any visitMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext * ctx) override;


        std::any visitMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext * ctx) override;


        std::any visitMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext * ctx) override;


        std::any visitMatcherWordRange(UserAgentTreeWalkerParser::MatcherWordRangeContext * ctx) override;


        std::any visitMatcherSegmentRange(UserAgentTreeWalkerParser::MatcherSegmentRangeContext * ctx) override;


        std::any visitMatcherPathIsNull(UserAgentTreeWalkerParser::MatcherPathIsNullContext * ctx) override;


        std::any visitPathVariable(UserAgentTreeWalkerParser::PathVariableContext * ctx) override;


        std::any visitPathWalk(UserAgentTreeWalkerParser::PathWalkContext * ctx) override;


        std::any visitStepDown(UserAgentTreeWalkerParser::StepDownContext * ctx) override;


        std::any visitStepUp(UserAgentTreeWalkerParser::StepUpContext * ctx) override;

        //----

        std::any visitStepNext(UserAgentTreeWalkerParser::StepNextContext * ctx) override;



        std::any visitStepNext2(UserAgentTreeWalkerParser::StepNext2Context * ctx) override;


        std::any visitStepNext3(UserAgentTreeWalkerParser::StepNext3Context * ctx) override;


        std::any visitStepNext4(UserAgentTreeWalkerParser::StepNext4Context * ctx) override;

        //----

        std::any visitStepPrev(UserAgentTreeWalkerParser::StepPrevContext * ctx) override;



        std::any visitStepPrev2(UserAgentTreeWalkerParser::StepPrev2Context * ctx) override;


        std::any visitStepPrev3(UserAgentTreeWalkerParser::StepPrev3Context * ctx) override;


        std::any visitStepPrev4(UserAgentTreeWalkerParser::StepPrev4Context * ctx) override;

        //----

        std::any visitStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext * ctx) override;


        std::any visitStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext * ctx) override;


        std::any visitStepIsInSet(UserAgentTreeWalkerParser::StepIsInSetContext * ctx) override;


        std::any visitStepIsNotInSet(UserAgentTreeWalkerParser::StepIsNotInSetContext * ctx) override;




        std::any visitStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext * ctx) override;


        std::any visitStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext * ctx) override;


        std::any visitStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext * ctx) override;


        std::any visitStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext * ctx) override;


        std::any visitStepWordRange(UserAgentTreeWalkerParser::StepWordRangeContext * ctx) override;


        std::any visitStepBackToFull(UserAgentTreeWalkerParser::StepBackToFullContext * ctx) override;

    };
}

#endif //YAUAACPP_WALKLIST_H
