
// Generated from UserAgentTreeWalker.g4 by ANTLR 4.12.0

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

  virtual std::any visitMatcherBase(UserAgentTreeWalkerParser::MatcherBaseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIsSyntaxError(UserAgentTreeWalkerParser::IsSyntaxErrorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherPathIsNull(UserAgentTreeWalkerParser::MatcherPathIsNullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherExtract(UserAgentTreeWalkerParser::MatcherExtractContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherVariable(UserAgentTreeWalkerParser::MatcherVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherCleanVersion(UserAgentTreeWalkerParser::MatcherCleanVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherPathLookupPrefix(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherPathLookupContains(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherConcatPrefix(UserAgentTreeWalkerParser::MatcherConcatPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherPathIsInLookup(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherWordRange(UserAgentTreeWalkerParser::MatcherWordRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherSegmentRange(UserAgentTreeWalkerParser::MatcherSegmentRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherNormalizeBrand(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherConcat(UserAgentTreeWalkerParser::MatcherConcatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherPathIsInLookupContains(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherDefaultIfNull(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherPath(UserAgentTreeWalkerParser::MatcherPathContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherPathIsNotInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherReplaceString(UserAgentTreeWalkerParser::MatcherReplaceStringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherPathLookup(UserAgentTreeWalkerParser::MatcherPathLookupContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherExtractBrandFromUrl(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherConcatPostfix(UserAgentTreeWalkerParser::MatcherConcatPostfixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMatcherPathIsInLookupPrefix(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathFixedValue(UserAgentTreeWalkerParser::PathFixedValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathVariable(UserAgentTreeWalkerParser::PathVariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPathWalk(UserAgentTreeWalkerParser::PathWalkContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepDown(UserAgentTreeWalkerParser::StepDownContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepUp(UserAgentTreeWalkerParser::StepUpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepNext(UserAgentTreeWalkerParser::StepNextContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepNext2(UserAgentTreeWalkerParser::StepNext2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepNext3(UserAgentTreeWalkerParser::StepNext3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepNext4(UserAgentTreeWalkerParser::StepNext4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepPrev(UserAgentTreeWalkerParser::StepPrevContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepPrev2(UserAgentTreeWalkerParser::StepPrev2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepPrev3(UserAgentTreeWalkerParser::StepPrev3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepPrev4(UserAgentTreeWalkerParser::StepPrev4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepEqualsValue(UserAgentTreeWalkerParser::StepEqualsValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepNotEqualsValue(UserAgentTreeWalkerParser::StepNotEqualsValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepStartsWithValue(UserAgentTreeWalkerParser::StepStartsWithValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepEndsWithValue(UserAgentTreeWalkerParser::StepEndsWithValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepContainsValue(UserAgentTreeWalkerParser::StepContainsValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepNotContainsValue(UserAgentTreeWalkerParser::StepNotContainsValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepIsInSet(UserAgentTreeWalkerParser::StepIsInSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepIsNotInSet(UserAgentTreeWalkerParser::StepIsNotInSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepWordRange(UserAgentTreeWalkerParser::StepWordRangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStepBackToFull(UserAgentTreeWalkerParser::StepBackToFullContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberRangeStartToEnd(UserAgentTreeWalkerParser::NumberRangeStartToEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberRangeOpenStartToEnd(UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberRangeStartToOpenEnd(UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberRangeSingleValue(UserAgentTreeWalkerParser::NumberRangeSingleValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberRangeAll(UserAgentTreeWalkerParser::NumberRangeAllContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumberRangeEmpty(UserAgentTreeWalkerParser::NumberRangeEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWordRangeStartToEnd(UserAgentTreeWalkerParser::WordRangeStartToEndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWordRangeFirstWords(UserAgentTreeWalkerParser::WordRangeFirstWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWordRangeLastWords(UserAgentTreeWalkerParser::WordRangeLastWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWordRangeSingleWord(UserAgentTreeWalkerParser::WordRangeSingleWordContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace ycpp
