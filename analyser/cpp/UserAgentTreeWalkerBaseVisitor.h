
// Generated from UserAgentTreeWalker.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "UserAgentTreeWalkerVisitor.h"


namespace ycpp {

/**
 * This class provides an empty implementation of UserAgentTreeWalkerVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  UserAgentTreeWalkerBaseVisitor : public UserAgentTreeWalkerVisitor {
public:

  virtual antlrcpp::Any visitMatcherBase(UserAgentTreeWalkerParser::MatcherBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIsSyntaxError(UserAgentTreeWalkerParser::IsSyntaxErrorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherPathIsNull(UserAgentTreeWalkerParser::MatcherPathIsNullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherExtract(UserAgentTreeWalkerParser::MatcherExtractContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherVariable(UserAgentTreeWalkerParser::MatcherVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherCleanVersion(UserAgentTreeWalkerParser::MatcherCleanVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherWordRange(UserAgentTreeWalkerParser::MatcherWordRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherSegmentRange(UserAgentTreeWalkerParser::MatcherSegmentRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherNormalizeBrand(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherPath(UserAgentTreeWalkerParser::MatcherPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherExtractBrandFromUrl(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPathFixedValue(UserAgentTreeWalkerParser::PathFixedValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPathVariable(UserAgentTreeWalkerParser::PathVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPathWalk(UserAgentTreeWalkerParser::PathWalkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepDown(UserAgentTreeWalkerParser::StepDownContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepUp(UserAgentTreeWalkerParser::StepUpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepNext(UserAgentTreeWalkerParser::StepNextContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepNext2(UserAgentTreeWalkerParser::StepNext2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepNext3(UserAgentTreeWalkerParser::StepNext3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepNext4(UserAgentTreeWalkerParser::StepNext4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepPrev(UserAgentTreeWalkerParser::StepPrevContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepPrev2(UserAgentTreeWalkerParser::StepPrev2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepPrev3(UserAgentTreeWalkerParser::StepPrev3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepPrev4(UserAgentTreeWalkerParser::StepPrev4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepIsInSet(UserAgentTreeWalkerParser::StepIsInSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepIsNotInSet(UserAgentTreeWalkerParser::StepIsNotInSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepWordRange(UserAgentTreeWalkerParser::StepWordRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStepBackToFull(UserAgentTreeWalkerParser::StepBackToFullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberRangeStartToEnd(UserAgentTreeWalkerParser::NumberRangeStartToEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberRangeOpenStartToEnd(UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberRangeStartToOpenEnd(UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberRangeSingleValue(UserAgentTreeWalkerParser::NumberRangeSingleValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberRangeAll(UserAgentTreeWalkerParser::NumberRangeAllContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberRangeEmpty(UserAgentTreeWalkerParser::NumberRangeEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWordRangeStartToEnd(UserAgentTreeWalkerParser::WordRangeStartToEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWordRangeFirstWords(UserAgentTreeWalkerParser::WordRangeFirstWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWordRangeLastWords(UserAgentTreeWalkerParser::WordRangeLastWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWordRangeSingleWord(UserAgentTreeWalkerParser::WordRangeSingleWordContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace ycpp
