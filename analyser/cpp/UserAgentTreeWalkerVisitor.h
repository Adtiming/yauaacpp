
// Generated from UserAgentTreeWalker.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "UserAgentTreeWalkerParser.h"


namespace ycpp {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by UserAgentTreeWalkerParser.
 */
class  UserAgentTreeWalkerVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by UserAgentTreeWalkerParser.
   */
    virtual std::any visitMatcherBase(UserAgentTreeWalkerParser::MatcherBaseContext *context) = 0;

    virtual std::any visitIsSyntaxError(UserAgentTreeWalkerParser::IsSyntaxErrorContext *context) = 0;

    virtual std::any visitMatcherPathIsNull(UserAgentTreeWalkerParser::MatcherPathIsNullContext *context) = 0;

    virtual std::any visitMatcherExtract(UserAgentTreeWalkerParser::MatcherExtractContext *context) = 0;

    virtual std::any visitMatcherVariable(UserAgentTreeWalkerParser::MatcherVariableContext *context) = 0;

    virtual std::any visitMatcherCleanVersion(UserAgentTreeWalkerParser::MatcherCleanVersionContext *context) = 0;

    virtual std::any visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext *context) = 0;

    virtual std::any visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext *context) = 0;

    virtual std::any visitMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext *context) = 0;

    virtual std::any visitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext *context) = 0;

    virtual std::any visitMatcherWordRange(UserAgentTreeWalkerParser::MatcherWordRangeContext *context) = 0;

    virtual std::any visitMatcherSegmentRange(UserAgentTreeWalkerParser::MatcherSegmentRangeContext *context) = 0;

    virtual std::any visitMatcherNormalizeBrand(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext *context) = 0;

    virtual std::any visitMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext *context) = 0;

    virtual std::any visitMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext *context) = 0;

    virtual std::any visitMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext *context) = 0;

    virtual std::any visitMatcherPath(UserAgentTreeWalkerParser::MatcherPathContext *context) = 0;

    virtual std::any visitMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext *context) = 0;

    virtual std::any visitMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext *context) = 0;

    virtual std::any visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext *context) = 0;

    virtual std::any visitMatcherExtractBrandFromUrl(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext *context) = 0;

    virtual std::any visitMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext *context) = 0;

    virtual std::any visitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext *context) = 0;

    virtual std::any visitPathFixedValue(UserAgentTreeWalkerParser::PathFixedValueContext *context) = 0;

    virtual std::any visitPathVariable(UserAgentTreeWalkerParser::PathVariableContext *context) = 0;

    virtual std::any visitPathWalk(UserAgentTreeWalkerParser::PathWalkContext *context) = 0;

    virtual std::any visitStepDown(UserAgentTreeWalkerParser::StepDownContext *context) = 0;

    virtual std::any visitStepUp(UserAgentTreeWalkerParser::StepUpContext *context) = 0;

    virtual std::any visitStepNext(UserAgentTreeWalkerParser::StepNextContext *context) = 0;

    virtual std::any visitStepNext2(UserAgentTreeWalkerParser::StepNext2Context *context) = 0;

    virtual std::any visitStepNext3(UserAgentTreeWalkerParser::StepNext3Context *context) = 0;

    virtual std::any visitStepNext4(UserAgentTreeWalkerParser::StepNext4Context *context) = 0;

    virtual std::any visitStepPrev(UserAgentTreeWalkerParser::StepPrevContext *context) = 0;

    virtual std::any visitStepPrev2(UserAgentTreeWalkerParser::StepPrev2Context *context) = 0;

    virtual std::any visitStepPrev3(UserAgentTreeWalkerParser::StepPrev3Context *context) = 0;

    virtual std::any visitStepPrev4(UserAgentTreeWalkerParser::StepPrev4Context *context) = 0;

    virtual std::any visitStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext *context) = 0;

    virtual std::any visitStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext *context) = 0;

    virtual std::any visitStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext *context) = 0;

    virtual std::any visitStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext *context) = 0;

    virtual std::any visitStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext *context) = 0;

    virtual std::any visitStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext *context) = 0;

    virtual std::any visitStepIsInSet(UserAgentTreeWalkerParser::StepIsInSetContext *context) = 0;

    virtual std::any visitStepIsNotInSet(UserAgentTreeWalkerParser::StepIsNotInSetContext *context) = 0;

    virtual std::any visitStepWordRange(UserAgentTreeWalkerParser::StepWordRangeContext *context) = 0;

    virtual std::any visitStepBackToFull(UserAgentTreeWalkerParser::StepBackToFullContext *context) = 0;

    virtual std::any visitNumberRangeStartToEnd(UserAgentTreeWalkerParser::NumberRangeStartToEndContext *context) = 0;

    virtual std::any visitNumberRangeOpenStartToEnd(UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext *context) = 0;

    virtual std::any visitNumberRangeStartToOpenEnd(UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext *context) = 0;

    virtual std::any visitNumberRangeSingleValue(UserAgentTreeWalkerParser::NumberRangeSingleValueContext *context) = 0;

    virtual std::any visitNumberRangeAll(UserAgentTreeWalkerParser::NumberRangeAllContext *context) = 0;

    virtual std::any visitNumberRangeEmpty(UserAgentTreeWalkerParser::NumberRangeEmptyContext *context) = 0;

    virtual std::any visitWordRangeStartToEnd(UserAgentTreeWalkerParser::WordRangeStartToEndContext *context) = 0;

    virtual std::any visitWordRangeFirstWords(UserAgentTreeWalkerParser::WordRangeFirstWordsContext *context) = 0;

    virtual std::any visitWordRangeLastWords(UserAgentTreeWalkerParser::WordRangeLastWordsContext *context) = 0;

    virtual std::any visitWordRangeSingleWord(UserAgentTreeWalkerParser::WordRangeSingleWordContext *context) = 0;


};

}  // namespace ycpp
