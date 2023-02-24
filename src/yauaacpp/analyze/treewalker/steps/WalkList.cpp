//
// Created by sunxg on 22-1-30.
//

#include "WalkList.h"
#include "UserAgent.h"
#include <analyze/treewalker/steps/walk/StepNextN.h>
#include <analyze/treewalker/steps/walk/StepPrevN.h>
#include <analyze/treewalker/steps/lookup/StepLookupContains.h>
#include <analyze/treewalker/steps/lookup/StepLookupPrefix.h>
#include <analyze/treewalker/steps/lookup/StepIsInLookupContains.h>
#include <analyze/treewalker/steps/lookup/StepIsInLookupPrefix.h>
#include <analyze/treewalker/steps/value/StepCleanVersion.h>
#include <analyze/treewalker/steps/value/StepReplaceString.h>
#include <analyze/treewalker/steps/value/StepNormalizeBrand.h>
#include <analyze/treewalker/steps/value/StepExtractBrandFromUrl.h>
#include <analyze/treewalker/steps/value/StepConcat.h>
#include <analyze/treewalker/steps/value/StepConcatPrefix.h>
#include <analyze/treewalker/steps/value/StepConcatPostfix.h>
#include <analyze/treewalker/steps/value/StepWordRange.h>
#include <analyze/treewalker/steps/value/StepSegmentRange.h>
#include <analyze/treewalker/steps/compare/StepIsNull.h>
#include <analyze/treewalker/steps/walk/StepDown.h>
#include <analyze/treewalker/steps/walk/StepUp.h>
#include <analyze/treewalker/steps/walk/StepNext.h>
#include <analyze/treewalker/steps/walk/StepPrev.h>
#include <analyze/treewalker/steps/compare/StepNotEquals.h>
#include <analyze/treewalker/steps/compare/StepIsInSet.h>
#include <analyze/treewalker/steps/compare/StepContains.h>
#include <analyze/treewalker/steps/compare/StepNotContains.h>
#include <analyze/treewalker/steps/value/StepBackToFull.h>
#include <analyze/treewalker/steps/lookup/StepLookup.h>
#include <analyze/treewalker/steps/lookup/StepIsNotInLookupPrefix.h>
#include <analyze/treewalker/steps/compare/StepEquals.h>
#include <analyze/treewalker/steps/compare/StepIsNotInSet.h>
#include <analyze/treewalker/steps/compare/StepStartsWith.h>
#include <analyze/treewalker/steps/compare/StepEndsWith.h>
#include <analyze/treewalker/steps/compare/StepDefaultIfNull.h>
#include <utils/AntlrUtils.h>
#include "ImmutableUserAgent.h"

namespace ycpp {
    WalkList::WalkList(antlr4::ParserRuleContext *requiredPattern,
                             std::shared_ptr<MAPMAPS> lookups,
                       std::shared_ptr<MAPSETS> lookupSets, bool verbose) {
        this->lookups = lookups;
        this->lookupSets = lookupSets;
        this->verbose = verbose;
        this->_mustHaveMatches = 0;
        // Generate the walkList from the requiredPattern
        WalkListBuilder(this).visit(requiredPattern);
        linkSteps();

        int i = 1;
        if (verbose) {
            LOG::error( "------------------------------------");
            LOG::error( "Required: %s", requiredPattern->getText().c_str());
            for (std::shared_ptr<Step> step : steps) {
                step->setVerbose(true);
                LOG::error( "%d: %s", i++, step->toString().c_str());
            }
        }
    }

    void WalkList::destroy() {
        for (std::shared_ptr<Step> step : steps){step->destroy();}
        steps.clear();
    }

    long WalkList::pruneTrailingStepsThatCannotFail() {
        int lastStepThatCannotFail = INT_MAX;
        for (int i = steps.size() - 1; i >= 0; i--) {
            std::shared_ptr<Step> current = steps[i];
            if (current->canFail()) {
                break; // We're done. We have the last step that CAN fail.
            }
            lastStepThatCannotFail = i;
        }

        if (lastStepThatCannotFail == INT_MAX) {
            return 0;
        }
        if (lastStepThatCannotFail == 0) {
            long prunedSteps = steps.size();
            steps.clear();
            return prunedSteps;
        }

        int lastRelevantStepIndex = lastStepThatCannotFail - 1;
        std::shared_ptr<Step> lastRelevantStep = steps[lastRelevantStepIndex];
        lastRelevantStep->setNextStep(lastRelevantStepIndex, nullptr);

        size_t oldSize = steps.size();
        steps.resize(lastRelevantStepIndex + 1);
        return ((long) oldSize) - (lastRelevantStepIndex + 1);
    }

    std::shared_ptr<WalkResult> WalkList::walk(antlr4::tree::ParseTree *tree, const std::string &value) {
        if (steps.empty()) {
            return std::make_shared<WalkResult>(tree, value);
        }
        std::shared_ptr<Step> firstStep = steps[0];
        if (verbose) {
            LOG::error( "Tree: >>>%s<<<", AntlrUtils::getSourceText((antlr4::ParserRuleContext*) tree).c_str());
            LOG::error( "Enter step: %s", firstStep->toString().c_str());
        }
        std::shared_ptr<WalkResult> result = firstStep->walk(tree, value);
        if (verbose) {
            LOG::error( "Leave step (%s): %s", result == nullptr ? "-" : "+", firstStep->toString().c_str());
        }
        return result;
    }

    bool WalkList::mustHaveMatches() {
        if (_mustHaveMatches != 0) {
            return _mustHaveMatches == 1;
        }

        _mustHaveMatches = 1;

        std::shared_ptr<Step> step = getFirstStep();
        while (step != nullptr) {
            if (!step->mustHaveInput()) {
                _mustHaveMatches = 2;
                break;
            }
            step = step->getNextStep();
        }
        return _mustHaveMatches == 1;
    }

    std::shared_ptr<Step> WalkList::getFirstStep() {
        return steps.empty() ? nullptr : steps[0];
    }

    std::string WalkList::toString() {
        if (steps.empty()) {
            return "Empty";
        }
        std::stringstream o;
        for (std::shared_ptr<Step> step : steps) {
            o <<" --> " << step->toString();
        }
        return o.str();
    }

    void WalkList::linkSteps() {
        std::shared_ptr<Step> nextStep;
        for (int i = (int)(steps.size() - 1); i >= 0; i--) {
            std::shared_ptr<Step> current = steps[i];
            current->setNextStep(i, nextStep);
            nextStep = current;
        }
    }

    WalkList::~WalkList() {
        destroy();
    }

    WalkListBuilder::WalkListBuilder(WalkList *walkList) {
        this->walkList = walkList;
    }

    STRMAP_SP WalkListBuilder::getLookup(const std::string &lookupName) {
        auto it = walkList->lookups->find(lookupName);
        if(it == walkList->lookups->end()){
            throw InvalidParserConfigurationException("Missing lookup \"" + lookupName + "\" ");
        }
        return it->second;
    }

    antlrcpp::Any WalkListBuilder::doStepNextN(UserAgentTreeWalkerParser::PathContext *nextStep, int nextSteps) {
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepNextN(nextSteps)));
        visitNext(nextStep);
        return nullptr; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::doStepPrevN(UserAgentTreeWalkerParser::PathContext *nextStep, int prevSteps) {
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepPrevN(prevSteps)));
        visitNext(nextStep);
        return nullptr; // antlrcpp::Any
    }

    STRSET_SP WalkListBuilder::getLookupSet(const std::string &lookupSetName) {
        STRSET_SP lookupSet = (*walkList->lookupSets)[lookupSetName];
        if (!lookupSet) {
            STRMAP_SP lookup = (*walkList->lookups)[lookupSetName];
            if(lookup){
                lookupSet = std::make_shared<std::set<std::string>>();
                for(auto pair:*lookup)
                    lookupSet->insert(pair.first);
            }
        }
        if (!lookupSet) {
            throw InvalidParserConfigurationException("Missing lookupSet \"" + lookupSetName + "\" ");
        }
        return lookupSet;
    }

    antlrcpp::Any WalkListBuilder::visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext * ctx) {
        visit(ctx->matcher());

        fromHereItCannotBeInHashMapAnymore();

        std::string lookupName = ctx->lookup->getText();
        const STRMAP_SP lookup = getLookup(lookupName);

        add(std::shared_ptr<Step>(new StepLookup(lookupName, lookup, extractText(ctx->defaultValue))));
        return nullptr; // antlrcpp::Any
    }

    antlrcpp::Any
    WalkListBuilder::visitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext * ctx) {
        visit(ctx->matcher());

        fromHereItCannotBeInHashMapAnymore();

        std::string lookupName = ctx->lookup->getText();
        STRMAP_SP lookup = getLookup(lookupName);

        // No need to write new code for essentially the same in a different syntax
        STRSET_SP t = std::make_shared<std::set<std::string>>();
        for(auto pair:*lookup) t->insert(pair.first);
        add(std::shared_ptr<Step>(new StepIsInSet(lookupName, t)));
        return nullptr; // antlrcpp::Any
    }

    antlrcpp::Any
    WalkListBuilder::visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext * ctx) {
        visit(ctx->matcher());

        fromHereItCannotBeInHashMapAnymore();

        std::string lookupName = ctx->lookup->getText();
        STRMAP_SP lookup = getLookup(lookupName);

        add(std::shared_ptr<Step>(new StepLookupContains(lookupName, lookup, extractText(ctx->defaultValue))));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any
    WalkListBuilder::visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext * ctx) {
        visit(ctx->matcher());

        fromHereItCannotBeInHashMapAnymore();

        std::string lookupName = ctx->lookup->getText();
        STRMAP_SP lookup = getLookup(lookupName);

        add(std::shared_ptr<Step>(new StepLookupPrefix(lookupName, lookup, extractText(ctx->defaultValue))));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherPathIsInLookupContains(
            UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext * ctx) {
        visit(ctx->matcher());

        fromHereItCannotBeInHashMapAnymore();

        std::string lookupName = ctx->lookup->getText();
        STRMAP_SP lookup = getLookup(lookupName);

        add(std::shared_ptr<Step>(new StepIsInLookupContains(lookupName, lookup)));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any
    WalkListBuilder::visitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext * ctx) {
        visit(ctx->matcher());

        fromHereItCannotBeInHashMapAnymore();

        std::string lookupName = ctx->lookup->getText();
        STRMAP_SP lookup = getLookup(lookupName);

        add(std::shared_ptr<Step>(new StepIsInLookupPrefix(lookupName, lookup)));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherPathIsNotInLookupPrefix(
            UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext * ctx) {
        visit(ctx->matcher());

        fromHereItCannotBeInHashMapAnymore();

        std::string              lookupName = ctx->lookup->getText();
        STRSET_SP                lookupSet  = (*walkList->lookupSets)[lookupName];
        if (!lookupSet->empty()) {
            add(std::shared_ptr<Step>(new StepIsNotInLookupPrefix(lookupName, lookupSet)));
        } else {
            STRMAP_SP lookup     =  (*walkList->lookups)[lookupName];
            if (!lookup->empty()) {
                add(std::shared_ptr<Step>(new StepIsNotInLookupPrefix(lookupName, lookup)));
            } else {
                throw InvalidParserConfigurationException("Missing lookup/set \"" + lookupName + "\" ");
            }
        }

        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext * ctx) {
        // Always add this one, it's special
        walkList->steps.push_back(std::shared_ptr<Step>(new StepDefaultIfNull(ctx->defaultValue->getText())));
        visit(ctx->matcher());
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherCleanVersion(UserAgentTreeWalkerParser::MatcherCleanVersionContext * ctx) {
        visit(ctx->matcher());
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepCleanVersion()));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext * ctx) {
        visit(ctx->matcher());
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepReplaceString(ctx->search->getText(), ctx->replace->getText())));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any
    WalkListBuilder::visitMatcherNormalizeBrand(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext * ctx) {
        visit(ctx->matcher());
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepNormalizeBrand()));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any
    WalkListBuilder::visitMatcherExtractBrandFromUrl(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext * ctx) {
        visit(ctx->matcher());
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepExtractBrandFromUrl()));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext * ctx) {
        visit(ctx->matcher());
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepConcat(ctx->prefix->getText(), ctx->postfix->getText())));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext * ctx) {
        visit(ctx->matcher());
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepConcatPrefix(ctx->prefix->getText())));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext * ctx) {
        visit(ctx->matcher());
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepConcatPostfix(ctx->postfix->getText())));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherWordRange(UserAgentTreeWalkerParser::MatcherWordRangeContext * ctx) {
        visit(ctx->matcher());
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepWordRange(*WordRangeVisitor::getRange(ctx->wordRange()))));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherSegmentRange(UserAgentTreeWalkerParser::MatcherSegmentRangeContext * ctx) {
        visit(ctx->matcher());
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepSegmentRange(*WordRangeVisitor::getRange(ctx->wordRange()))));
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitMatcherPathIsNull(UserAgentTreeWalkerParser::MatcherPathIsNullContext * ctx) {
        // Always add this one, it's special
        walkList->steps.push_back(std::shared_ptr<Step>(new StepIsNull()));
        visit(ctx->matcher());
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitPathVariable(UserAgentTreeWalkerParser::PathVariableContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitPathWalk(UserAgentTreeWalkerParser::PathWalkContext * ctx) {
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepDown(UserAgentTreeWalkerParser::StepDownContext * ctx) {
        add(std::shared_ptr<Step>(new StepDown(ctx->numberRange(), ctx->name->getText())));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepUp(UserAgentTreeWalkerParser::StepUpContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepUp()));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepNext(UserAgentTreeWalkerParser::StepNextContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepNext()));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepNext2(UserAgentTreeWalkerParser::StepNext2Context * ctx) {
        return doStepNextN(ctx->nextStep, 2);
    }

    antlrcpp::Any WalkListBuilder::visitStepNext3(UserAgentTreeWalkerParser::StepNext3Context * ctx) {
        return doStepNextN(ctx->nextStep, 3);
    }

    antlrcpp::Any WalkListBuilder::visitStepNext4(UserAgentTreeWalkerParser::StepNext4Context * ctx) {
        return doStepNextN(ctx->nextStep, 4);
    }

    antlrcpp::Any WalkListBuilder::visitStepPrev(UserAgentTreeWalkerParser::StepPrevContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepPrev()));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepPrev2(UserAgentTreeWalkerParser::StepPrev2Context * ctx) {
        return doStepPrevN(ctx->nextStep, 2);
    }

    antlrcpp::Any WalkListBuilder::visitStepPrev3(UserAgentTreeWalkerParser::StepPrev3Context * ctx) {
        return doStepPrevN(ctx->nextStep, 3);
    }

    antlrcpp::Any WalkListBuilder::visitStepPrev4(UserAgentTreeWalkerParser::StepPrev4Context * ctx) {
        return doStepPrevN(ctx->nextStep, 4);
    }

    antlrcpp::Any WalkListBuilder::visitStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext * ctx) {
        add(std::shared_ptr<Step>(new StepEquals(ctx->value->getText())));
        fromHereItCannotBeInHashMapAnymore();
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepNotEquals(ctx->value->getText())));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepIsInSet(UserAgentTreeWalkerParser::StepIsInSetContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        std::string      lookupSetName = ctx->set->getText();
        add(std::shared_ptr<Step>(new StepIsInSet(lookupSetName, getLookupSet(lookupSetName))));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepIsNotInSet(UserAgentTreeWalkerParser::StepIsNotInSetContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        std::string      lookupSetName = ctx->set->getText();
        add(std::shared_ptr<Step>(new StepIsNotInSet(lookupSetName, getLookupSet(lookupSetName))));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext * ctx) {
        bool skipIfShortEnough = stillGoingToHashMap();
        fromHereItCannotBeInHashMapAnymore();
        std::string value = ctx->value->getText();

        bool addTheStep = true;
        if (skipIfShortEnough) {
            // If the compare value is short enough that the ENTIRE value was in the hashmap then
            // the actual compare is not longer required
            if (value.length() <= AbstractUserAgentAnalyzerDirect::MAX_PREFIX_HASH_MATCH) {
                addTheStep = false;
            }
        }

        if (addTheStep) {
            add(std::shared_ptr<Step>(new StepStartsWith(value)));
        }
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepEndsWith(ctx->value->getText())));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepContains(ctx->value->getText())));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext * ctx) {
        fromHereItCannotBeInHashMapAnymore();
        add(std::shared_ptr<Step>(new StepNotContains(ctx->value->getText())));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepWordRange(UserAgentTreeWalkerParser::StepWordRangeContext * ctx) {
        add(std::shared_ptr<Step>(new StepWordRange(*WordRangeVisitor::getRange(ctx->wordRange()))));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }

    antlrcpp::Any WalkListBuilder::visitStepBackToFull(UserAgentTreeWalkerParser::StepBackToFullContext * ctx) {
        add(std::shared_ptr<Step>(new StepBackToFull()));
        visitNext(ctx->nextStep);
        return nullptr;; // antlrcpp::Any
    }
}
