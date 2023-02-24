
// Generated from UserAgentTreeWalker.g4 by ANTLR 4.7.2

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
    virtual antlrcpp::Any visitMatcherBase(UserAgentTreeWalkerParser::MatcherBaseContext *context) = 0;

    virtual antlrcpp::Any visitIsSyntaxError(UserAgentTreeWalkerParser::IsSyntaxErrorContext *context) = 0;

    virtual antlrcpp::Any visitMatcherPathIsNull(UserAgentTreeWalkerParser::MatcherPathIsNullContext *context) = 0;

    virtual antlrcpp::Any visitMatcherExtract(UserAgentTreeWalkerParser::MatcherExtractContext *context) = 0;

    virtual antlrcpp::Any visitMatcherVariable(UserAgentTreeWalkerParser::MatcherVariableContext *context) = 0;

    virtual antlrcpp::Any visitMatcherCleanVersion(UserAgentTreeWalkerParser::MatcherCleanVersionContext *context) = 0;

    virtual antlrcpp::Any visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext *context) = 0;

    virtual antlrcpp::Any visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext *context) = 0;

    virtual antlrcpp::Any visitMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext *context) = 0;

    virtual antlrcpp::Any visitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext *context) = 0;

    virtual antlrcpp::Any visitMatcherWordRange(UserAgentTreeWalkerParser::MatcherWordRangeContext *context) = 0;

    virtual antlrcpp::Any visitMatcherSegmentRange(UserAgentTreeWalkerParser::MatcherSegmentRangeContext *context) = 0;

    virtual antlrcpp::Any visitMatcherNormalizeBrand(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext *context) = 0;

    virtual antlrcpp::Any visitMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext *context) = 0;

    virtual antlrcpp::Any visitMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext *context) = 0;

    virtual antlrcpp::Any visitMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext *context) = 0;

    virtual antlrcpp::Any visitMatcherPath(UserAgentTreeWalkerParser::MatcherPathContext *context) = 0;

    virtual antlrcpp::Any visitMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext *context) = 0;

    virtual antlrcpp::Any visitMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext *context) = 0;

    virtual antlrcpp::Any visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext *context) = 0;

    virtual antlrcpp::Any visitMatcherExtractBrandFromUrl(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext *context) = 0;

    virtual antlrcpp::Any visitMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext *context) = 0;

    virtual antlrcpp::Any visitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext *context) = 0;

    virtual antlrcpp::Any visitPathFixedValue(UserAgentTreeWalkerParser::PathFixedValueContext *context) = 0;

    virtual antlrcpp::Any visitPathVariable(UserAgentTreeWalkerParser::PathVariableContext *context) = 0;

    virtual antlrcpp::Any visitPathWalk(UserAgentTreeWalkerParser::PathWalkContext *context) = 0;

    virtual antlrcpp::Any visitStepDown(UserAgentTreeWalkerParser::StepDownContext *context) = 0;

    virtual antlrcpp::Any visitStepUp(UserAgentTreeWalkerParser::StepUpContext *context) = 0;

    virtual antlrcpp::Any visitStepNext(UserAgentTreeWalkerParser::StepNextContext *context) = 0;

    virtual antlrcpp::Any visitStepNext2(UserAgentTreeWalkerParser::StepNext2Context *context) = 0;

    virtual antlrcpp::Any visitStepNext3(UserAgentTreeWalkerParser::StepNext3Context *context) = 0;

    virtual antlrcpp::Any visitStepNext4(UserAgentTreeWalkerParser::StepNext4Context *context) = 0;

    virtual antlrcpp::Any visitStepPrev(UserAgentTreeWalkerParser::StepPrevContext *context) = 0;

    virtual antlrcpp::Any visitStepPrev2(UserAgentTreeWalkerParser::StepPrev2Context *context) = 0;

    virtual antlrcpp::Any visitStepPrev3(UserAgentTreeWalkerParser::StepPrev3Context *context) = 0;

    virtual antlrcpp::Any visitStepPrev4(UserAgentTreeWalkerParser::StepPrev4Context *context) = 0;

    virtual antlrcpp::Any visitStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext *context) = 0;

    virtual antlrcpp::Any visitStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext *context) = 0;

    virtual antlrcpp::Any visitStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext *context) = 0;

    virtual antlrcpp::Any visitStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext *context) = 0;

    virtual antlrcpp::Any visitStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext *context) = 0;

    virtual antlrcpp::Any visitStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext *context) = 0;

    virtual antlrcpp::Any visitStepIsInSet(UserAgentTreeWalkerParser::StepIsInSetContext *context) = 0;

    virtual antlrcpp::Any visitStepIsNotInSet(UserAgentTreeWalkerParser::StepIsNotInSetContext *context) = 0;

    virtual antlrcpp::Any visitStepWordRange(UserAgentTreeWalkerParser::StepWordRangeContext *context) = 0;

    virtual antlrcpp::Any visitStepBackToFull(UserAgentTreeWalkerParser::StepBackToFullContext *context) = 0;

    virtual antlrcpp::Any visitNumberRangeStartToEnd(UserAgentTreeWalkerParser::NumberRangeStartToEndContext *context) = 0;

    virtual antlrcpp::Any visitNumberRangeOpenStartToEnd(UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext *context) = 0;

    virtual antlrcpp::Any visitNumberRangeStartToOpenEnd(UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext *context) = 0;

    virtual antlrcpp::Any visitNumberRangeSingleValue(UserAgentTreeWalkerParser::NumberRangeSingleValueContext *context) = 0;

    virtual antlrcpp::Any visitNumberRangeAll(UserAgentTreeWalkerParser::NumberRangeAllContext *context) = 0;

    virtual antlrcpp::Any visitNumberRangeEmpty(UserAgentTreeWalkerParser::NumberRangeEmptyContext *context) = 0;

    virtual antlrcpp::Any visitWordRangeStartToEnd(UserAgentTreeWalkerParser::WordRangeStartToEndContext *context) = 0;

    virtual antlrcpp::Any visitWordRangeFirstWords(UserAgentTreeWalkerParser::WordRangeFirstWordsContext *context) = 0;

    virtual antlrcpp::Any visitWordRangeLastWords(UserAgentTreeWalkerParser::WordRangeLastWordsContext *context) = 0;

    virtual antlrcpp::Any visitWordRangeSingleWord(UserAgentTreeWalkerParser::WordRangeSingleWordContext *context) = 0;


};

}  // namespace ycpp
