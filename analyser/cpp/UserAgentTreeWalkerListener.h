
// Generated from UserAgentTreeWalker.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "UserAgentTreeWalkerParser.h"


namespace ycpp {

/**
 * This interface defines an abstract listener for a parse tree produced by UserAgentTreeWalkerParser.
 */
class  UserAgentTreeWalkerListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterMatcherBase(UserAgentTreeWalkerParser::MatcherBaseContext *ctx) = 0;
  virtual void exitMatcherBase(UserAgentTreeWalkerParser::MatcherBaseContext *ctx) = 0;

  virtual void enterIsSyntaxError(UserAgentTreeWalkerParser::IsSyntaxErrorContext *ctx) = 0;
  virtual void exitIsSyntaxError(UserAgentTreeWalkerParser::IsSyntaxErrorContext *ctx) = 0;

  virtual void enterMatcherPathIsNull(UserAgentTreeWalkerParser::MatcherPathIsNullContext *ctx) = 0;
  virtual void exitMatcherPathIsNull(UserAgentTreeWalkerParser::MatcherPathIsNullContext *ctx) = 0;

  virtual void enterMatcherExtract(UserAgentTreeWalkerParser::MatcherExtractContext *ctx) = 0;
  virtual void exitMatcherExtract(UserAgentTreeWalkerParser::MatcherExtractContext *ctx) = 0;

  virtual void enterMatcherVariable(UserAgentTreeWalkerParser::MatcherVariableContext *ctx) = 0;
  virtual void exitMatcherVariable(UserAgentTreeWalkerParser::MatcherVariableContext *ctx) = 0;

  virtual void enterMatcherCleanVersion(UserAgentTreeWalkerParser::MatcherCleanVersionContext *ctx) = 0;
  virtual void exitMatcherCleanVersion(UserAgentTreeWalkerParser::MatcherCleanVersionContext *ctx) = 0;

  virtual void enterMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext *ctx) = 0;
  virtual void exitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext *ctx) = 0;

  virtual void enterMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext *ctx) = 0;
  virtual void exitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext *ctx) = 0;

  virtual void enterMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext *ctx) = 0;
  virtual void exitMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext *ctx) = 0;

  virtual void enterMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext *ctx) = 0;
  virtual void exitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext *ctx) = 0;

  virtual void enterMatcherWordRange(UserAgentTreeWalkerParser::MatcherWordRangeContext *ctx) = 0;
  virtual void exitMatcherWordRange(UserAgentTreeWalkerParser::MatcherWordRangeContext *ctx) = 0;

  virtual void enterMatcherSegmentRange(UserAgentTreeWalkerParser::MatcherSegmentRangeContext *ctx) = 0;
  virtual void exitMatcherSegmentRange(UserAgentTreeWalkerParser::MatcherSegmentRangeContext *ctx) = 0;

  virtual void enterMatcherNormalizeBrand(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext *ctx) = 0;
  virtual void exitMatcherNormalizeBrand(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext *ctx) = 0;

  virtual void enterMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext *ctx) = 0;
  virtual void exitMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext *ctx) = 0;

  virtual void enterMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext *ctx) = 0;
  virtual void exitMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext *ctx) = 0;

  virtual void enterMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext *ctx) = 0;
  virtual void exitMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext *ctx) = 0;

  virtual void enterMatcherPath(UserAgentTreeWalkerParser::MatcherPathContext *ctx) = 0;
  virtual void exitMatcherPath(UserAgentTreeWalkerParser::MatcherPathContext *ctx) = 0;

  virtual void enterMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext *ctx) = 0;
  virtual void exitMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext *ctx) = 0;

  virtual void enterMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext *ctx) = 0;
  virtual void exitMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext *ctx) = 0;

  virtual void enterMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext *ctx) = 0;
  virtual void exitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext *ctx) = 0;

  virtual void enterMatcherExtractBrandFromUrl(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext *ctx) = 0;
  virtual void exitMatcherExtractBrandFromUrl(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext *ctx) = 0;

  virtual void enterMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext *ctx) = 0;
  virtual void exitMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext *ctx) = 0;

  virtual void enterMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext *ctx) = 0;
  virtual void exitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext *ctx) = 0;

  virtual void enterPathFixedValue(UserAgentTreeWalkerParser::PathFixedValueContext *ctx) = 0;
  virtual void exitPathFixedValue(UserAgentTreeWalkerParser::PathFixedValueContext *ctx) = 0;

  virtual void enterPathVariable(UserAgentTreeWalkerParser::PathVariableContext *ctx) = 0;
  virtual void exitPathVariable(UserAgentTreeWalkerParser::PathVariableContext *ctx) = 0;

  virtual void enterPathWalk(UserAgentTreeWalkerParser::PathWalkContext *ctx) = 0;
  virtual void exitPathWalk(UserAgentTreeWalkerParser::PathWalkContext *ctx) = 0;

  virtual void enterStepDown(UserAgentTreeWalkerParser::StepDownContext *ctx) = 0;
  virtual void exitStepDown(UserAgentTreeWalkerParser::StepDownContext *ctx) = 0;

  virtual void enterStepUp(UserAgentTreeWalkerParser::StepUpContext *ctx) = 0;
  virtual void exitStepUp(UserAgentTreeWalkerParser::StepUpContext *ctx) = 0;

  virtual void enterStepNext(UserAgentTreeWalkerParser::StepNextContext *ctx) = 0;
  virtual void exitStepNext(UserAgentTreeWalkerParser::StepNextContext *ctx) = 0;

  virtual void enterStepNext2(UserAgentTreeWalkerParser::StepNext2Context *ctx) = 0;
  virtual void exitStepNext2(UserAgentTreeWalkerParser::StepNext2Context *ctx) = 0;

  virtual void enterStepNext3(UserAgentTreeWalkerParser::StepNext3Context *ctx) = 0;
  virtual void exitStepNext3(UserAgentTreeWalkerParser::StepNext3Context *ctx) = 0;

  virtual void enterStepNext4(UserAgentTreeWalkerParser::StepNext4Context *ctx) = 0;
  virtual void exitStepNext4(UserAgentTreeWalkerParser::StepNext4Context *ctx) = 0;

  virtual void enterStepPrev(UserAgentTreeWalkerParser::StepPrevContext *ctx) = 0;
  virtual void exitStepPrev(UserAgentTreeWalkerParser::StepPrevContext *ctx) = 0;

  virtual void enterStepPrev2(UserAgentTreeWalkerParser::StepPrev2Context *ctx) = 0;
  virtual void exitStepPrev2(UserAgentTreeWalkerParser::StepPrev2Context *ctx) = 0;

  virtual void enterStepPrev3(UserAgentTreeWalkerParser::StepPrev3Context *ctx) = 0;
  virtual void exitStepPrev3(UserAgentTreeWalkerParser::StepPrev3Context *ctx) = 0;

  virtual void enterStepPrev4(UserAgentTreeWalkerParser::StepPrev4Context *ctx) = 0;
  virtual void exitStepPrev4(UserAgentTreeWalkerParser::StepPrev4Context *ctx) = 0;

  virtual void enterStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext *ctx) = 0;
  virtual void exitStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext *ctx) = 0;

  virtual void enterStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext *ctx) = 0;
  virtual void exitStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext *ctx) = 0;

  virtual void enterStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext *ctx) = 0;
  virtual void exitStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext *ctx) = 0;

  virtual void enterStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext *ctx) = 0;
  virtual void exitStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext *ctx) = 0;

  virtual void enterStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext *ctx) = 0;
  virtual void exitStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext *ctx) = 0;

  virtual void enterStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext *ctx) = 0;
  virtual void exitStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext *ctx) = 0;

  virtual void enterStepIsInSet(UserAgentTreeWalkerParser::StepIsInSetContext *ctx) = 0;
  virtual void exitStepIsInSet(UserAgentTreeWalkerParser::StepIsInSetContext *ctx) = 0;

  virtual void enterStepIsNotInSet(UserAgentTreeWalkerParser::StepIsNotInSetContext *ctx) = 0;
  virtual void exitStepIsNotInSet(UserAgentTreeWalkerParser::StepIsNotInSetContext *ctx) = 0;

  virtual void enterStepWordRange(UserAgentTreeWalkerParser::StepWordRangeContext *ctx) = 0;
  virtual void exitStepWordRange(UserAgentTreeWalkerParser::StepWordRangeContext *ctx) = 0;

  virtual void enterStepBackToFull(UserAgentTreeWalkerParser::StepBackToFullContext *ctx) = 0;
  virtual void exitStepBackToFull(UserAgentTreeWalkerParser::StepBackToFullContext *ctx) = 0;

  virtual void enterNumberRangeStartToEnd(UserAgentTreeWalkerParser::NumberRangeStartToEndContext *ctx) = 0;
  virtual void exitNumberRangeStartToEnd(UserAgentTreeWalkerParser::NumberRangeStartToEndContext *ctx) = 0;

  virtual void enterNumberRangeOpenStartToEnd(UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext *ctx) = 0;
  virtual void exitNumberRangeOpenStartToEnd(UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext *ctx) = 0;

  virtual void enterNumberRangeStartToOpenEnd(UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext *ctx) = 0;
  virtual void exitNumberRangeStartToOpenEnd(UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext *ctx) = 0;

  virtual void enterNumberRangeSingleValue(UserAgentTreeWalkerParser::NumberRangeSingleValueContext *ctx) = 0;
  virtual void exitNumberRangeSingleValue(UserAgentTreeWalkerParser::NumberRangeSingleValueContext *ctx) = 0;

  virtual void enterNumberRangeAll(UserAgentTreeWalkerParser::NumberRangeAllContext *ctx) = 0;
  virtual void exitNumberRangeAll(UserAgentTreeWalkerParser::NumberRangeAllContext *ctx) = 0;

  virtual void enterNumberRangeEmpty(UserAgentTreeWalkerParser::NumberRangeEmptyContext *ctx) = 0;
  virtual void exitNumberRangeEmpty(UserAgentTreeWalkerParser::NumberRangeEmptyContext *ctx) = 0;

  virtual void enterWordRangeStartToEnd(UserAgentTreeWalkerParser::WordRangeStartToEndContext *ctx) = 0;
  virtual void exitWordRangeStartToEnd(UserAgentTreeWalkerParser::WordRangeStartToEndContext *ctx) = 0;

  virtual void enterWordRangeFirstWords(UserAgentTreeWalkerParser::WordRangeFirstWordsContext *ctx) = 0;
  virtual void exitWordRangeFirstWords(UserAgentTreeWalkerParser::WordRangeFirstWordsContext *ctx) = 0;

  virtual void enterWordRangeLastWords(UserAgentTreeWalkerParser::WordRangeLastWordsContext *ctx) = 0;
  virtual void exitWordRangeLastWords(UserAgentTreeWalkerParser::WordRangeLastWordsContext *ctx) = 0;

  virtual void enterWordRangeSingleWord(UserAgentTreeWalkerParser::WordRangeSingleWordContext *ctx) = 0;
  virtual void exitWordRangeSingleWord(UserAgentTreeWalkerParser::WordRangeSingleWordContext *ctx) = 0;


};

}  // namespace ycpp
