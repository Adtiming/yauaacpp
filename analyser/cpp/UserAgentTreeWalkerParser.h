
// Generated from UserAgentTreeWalker.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"


namespace ycpp {


class  UserAgentTreeWalkerParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, PATHTOKENNAME = 17, VALUENAME = 18, VALUE = 19, 
    UP = 20, NEXT = 21, NEXT2 = 22, NEXT3 = 23, NEXT4 = 24, PREV = 25, PREV2 = 26, 
    PREV3 = 27, PREV4 = 28, DOT = 29, MINUS = 30, STAR = 31, IN = 32, NOTIN = 33, 
    NUMBER = 34, BLOCKOPEN = 35, BLOCKCLOSE = 36, BRACEOPEN = 37, BRACECLOSE = 38, 
    DOUBLEQUOTE = 39, COLON = 40, SEMICOLON = 41, SPACE = 42, NOTEQUALS = 43, 
    EQUALS = 44, CONTAINS = 45, NOTCONTAINS = 46, STARTSWITH = 47, ENDSWITH = 48, 
    BACKTOFULL = 49
  };

  enum {
    RuleMatcherRequire = 0, RuleMatcherExtract = 1, RuleMatcherVariable = 2, 
    RuleMatcher = 3, RuleBasePath = 4, RulePath = 5, RuleNumberRange = 6, 
    RuleWordRange = 7
  };

  explicit UserAgentTreeWalkerParser(antlr4::TokenStream *input);

  UserAgentTreeWalkerParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~UserAgentTreeWalkerParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class MatcherRequireContext;
  class MatcherExtractContext;
  class MatcherVariableContext;
  class MatcherContext;
  class BasePathContext;
  class PathContext;
  class NumberRangeContext;
  class WordRangeContext; 

  class  MatcherRequireContext : public antlr4::ParserRuleContext {
  public:
    MatcherRequireContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MatcherRequireContext() = default;
    void copyFrom(MatcherRequireContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IsSyntaxErrorContext : public MatcherRequireContext {
  public:
    IsSyntaxErrorContext(MatcherRequireContext *ctx);

    antlr4::Token *value = nullptr;
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherBaseContext : public MatcherRequireContext {
  public:
    MatcherBaseContext(MatcherRequireContext *ctx);

    MatcherContext *matcher();
    antlr4::tree::TerminalNode *EOF();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherPathIsNullContext : public MatcherRequireContext {
  public:
    MatcherPathIsNullContext(MatcherRequireContext *ctx);

    antlr4::tree::TerminalNode *BLOCKOPEN();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *EOF();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MatcherRequireContext* matcherRequire();

  class  MatcherExtractContext : public antlr4::ParserRuleContext {
  public:
    UserAgentTreeWalkerParser::MatcherContext *expression = nullptr;
    MatcherExtractContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    MatcherContext *matcher();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatcherExtractContext* matcherExtract();

  class  MatcherVariableContext : public antlr4::ParserRuleContext {
  public:
    UserAgentTreeWalkerParser::MatcherContext *expression = nullptr;
    MatcherVariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    MatcherContext *matcher();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MatcherVariableContext* matcherVariable();

  class  MatcherContext : public antlr4::ParserRuleContext {
  public:
    MatcherContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MatcherContext() = default;
    void copyFrom(MatcherContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MatcherCleanVersionContext : public MatcherContext {
  public:
    MatcherCleanVersionContext(MatcherContext *ctx);

    antlr4::tree::TerminalNode *BLOCKOPEN();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherPathLookupPrefixContext : public MatcherContext {
  public:
    MatcherPathLookupPrefixContext(MatcherContext *ctx);

    antlr4::Token *lookup = nullptr;
    antlr4::Token *defaultValue = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUENAME();
    antlr4::tree::TerminalNode *VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherPathLookupContainsContext : public MatcherContext {
  public:
    MatcherPathLookupContainsContext(MatcherContext *ctx);

    antlr4::Token *lookup = nullptr;
    antlr4::Token *defaultValue = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUENAME();
    antlr4::tree::TerminalNode *VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherConcatPrefixContext : public MatcherContext {
  public:
    MatcherConcatPrefixContext(MatcherContext *ctx);

    antlr4::Token *prefix = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *SEMICOLON();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherPathIsInLookupContext : public MatcherContext {
  public:
    MatcherPathIsInLookupContext(MatcherContext *ctx);

    antlr4::Token *lookup = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *SEMICOLON();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUENAME();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherWordRangeContext : public MatcherContext {
  public:
    MatcherWordRangeContext(MatcherContext *ctx);

    MatcherContext *matcher();
    WordRangeContext *wordRange();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherSegmentRangeContext : public MatcherContext {
  public:
    MatcherSegmentRangeContext(MatcherContext *ctx);

    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKOPEN();
    WordRangeContext *wordRange();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherNormalizeBrandContext : public MatcherContext {
  public:
    MatcherNormalizeBrandContext(MatcherContext *ctx);

    antlr4::tree::TerminalNode *BLOCKOPEN();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherConcatContext : public MatcherContext {
  public:
    MatcherConcatContext(MatcherContext *ctx);

    antlr4::Token *prefix = nullptr;
    antlr4::Token *postfix = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    std::vector<antlr4::tree::TerminalNode *> VALUE();
    antlr4::tree::TerminalNode* VALUE(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherPathIsInLookupContainsContext : public MatcherContext {
  public:
    MatcherPathIsInLookupContainsContext(MatcherContext *ctx);

    antlr4::Token *lookup = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *SEMICOLON();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUENAME();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherDefaultIfNullContext : public MatcherContext {
  public:
    MatcherDefaultIfNullContext(MatcherContext *ctx);

    antlr4::Token *defaultValue = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherPathContext : public MatcherContext {
  public:
    MatcherPathContext(MatcherContext *ctx);

    BasePathContext *basePath();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherPathIsNotInLookupPrefixContext : public MatcherContext {
  public:
    MatcherPathIsNotInLookupPrefixContext(MatcherContext *ctx);

    antlr4::Token *lookup = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *SEMICOLON();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUENAME();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherReplaceStringContext : public MatcherContext {
  public:
    MatcherReplaceStringContext(MatcherContext *ctx);

    antlr4::Token *search = nullptr;
    antlr4::Token *replace = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    MatcherContext *matcher();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    std::vector<antlr4::tree::TerminalNode *> VALUE();
    antlr4::tree::TerminalNode* VALUE(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherPathLookupContext : public MatcherContext {
  public:
    MatcherPathLookupContext(MatcherContext *ctx);

    antlr4::Token *lookup = nullptr;
    antlr4::Token *defaultValue = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUENAME();
    antlr4::tree::TerminalNode *VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherExtractBrandFromUrlContext : public MatcherContext {
  public:
    MatcherExtractBrandFromUrlContext(MatcherContext *ctx);

    antlr4::tree::TerminalNode *BLOCKOPEN();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherConcatPostfixContext : public MatcherContext {
  public:
    MatcherConcatPostfixContext(MatcherContext *ctx);

    antlr4::Token *postfix = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MatcherPathIsInLookupPrefixContext : public MatcherContext {
  public:
    MatcherPathIsInLookupPrefixContext(MatcherContext *ctx);

    antlr4::Token *lookup = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *SEMICOLON();
    MatcherContext *matcher();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *VALUENAME();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MatcherContext* matcher();
  MatcherContext* matcher(int precedence);
  class  BasePathContext : public antlr4::ParserRuleContext {
  public:
    BasePathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    BasePathContext() = default;
    void copyFrom(BasePathContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PathVariableContext : public BasePathContext {
  public:
    PathVariableContext(BasePathContext *ctx);

    antlr4::Token *variable = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *BACKTOFULL();
    antlr4::tree::TerminalNode *VALUENAME();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PathWalkContext : public BasePathContext {
  public:
    PathWalkContext(BasePathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PathFixedValueContext : public BasePathContext {
  public:
    PathFixedValueContext(BasePathContext *ctx);

    antlr4::Token *value = nullptr;
    antlr4::tree::TerminalNode *VALUE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  BasePathContext* basePath();

  class  PathContext : public antlr4::ParserRuleContext {
  public:
    PathContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PathContext() = default;
    void copyFrom(PathContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  StepNext4Context : public PathContext {
  public:
    StepNext4Context(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *NEXT4();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepStartsWithValueContext : public PathContext {
  public:
    StepStartsWithValueContext(PathContext *ctx);

    antlr4::Token *value = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *STARTSWITH();
    antlr4::tree::TerminalNode *VALUE();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepNext3Context : public PathContext {
  public:
    StepNext3Context(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *NEXT3();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepPrev4Context : public PathContext {
  public:
    StepPrev4Context(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *PREV4();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepPrev3Context : public PathContext {
  public:
    StepPrev3Context(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *PREV3();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepPrev2Context : public PathContext {
  public:
    StepPrev2Context(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *PREV2();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepIsInSetContext : public PathContext {
  public:
    StepIsInSetContext(PathContext *ctx);

    antlr4::Token *set = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *IN();
    antlr4::tree::TerminalNode *VALUENAME();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepNext2Context : public PathContext {
  public:
    StepNext2Context(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *NEXT2();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepUpContext : public PathContext {
  public:
    StepUpContext(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *UP();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepEndsWithValueContext : public PathContext {
  public:
    StepEndsWithValueContext(PathContext *ctx);

    antlr4::Token *value = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *ENDSWITH();
    antlr4::tree::TerminalNode *VALUE();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepIsNotInSetContext : public PathContext {
  public:
    StepIsNotInSetContext(PathContext *ctx);

    antlr4::Token *set = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *NOTIN();
    antlr4::tree::TerminalNode *VALUENAME();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepEqualsValueContext : public PathContext {
  public:
    StepEqualsValueContext(PathContext *ctx);

    antlr4::Token *value = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *EQUALS();
    antlr4::tree::TerminalNode *VALUE();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepDownContext : public PathContext {
  public:
    StepDownContext(PathContext *ctx);

    antlr4::Token *name = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *DOT();
    NumberRangeContext *numberRange();
    antlr4::tree::TerminalNode *PATHTOKENNAME();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepWordRangeContext : public PathContext {
  public:
    StepWordRangeContext(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    WordRangeContext *wordRange();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepNotEqualsValueContext : public PathContext {
  public:
    StepNotEqualsValueContext(PathContext *ctx);

    antlr4::Token *value = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *NOTEQUALS();
    antlr4::tree::TerminalNode *VALUE();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepBackToFullContext : public PathContext {
  public:
    StepBackToFullContext(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *BACKTOFULL();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepPrevContext : public PathContext {
  public:
    StepPrevContext(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *PREV();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepNextContext : public PathContext {
  public:
    StepNextContext(PathContext *ctx);

    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *NEXT();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepContainsValueContext : public PathContext {
  public:
    StepContainsValueContext(PathContext *ctx);

    antlr4::Token *value = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *CONTAINS();
    antlr4::tree::TerminalNode *VALUE();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StepNotContainsValueContext : public PathContext {
  public:
    StepNotContainsValueContext(PathContext *ctx);

    antlr4::Token *value = nullptr;
    UserAgentTreeWalkerParser::PathContext *nextStep = nullptr;
    antlr4::tree::TerminalNode *NOTCONTAINS();
    antlr4::tree::TerminalNode *VALUE();
    PathContext *path();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PathContext* path();

  class  NumberRangeContext : public antlr4::ParserRuleContext {
  public:
    NumberRangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NumberRangeContext() = default;
    void copyFrom(NumberRangeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumberRangeAllContext : public NumberRangeContext {
  public:
    NumberRangeAllContext(NumberRangeContext *ctx);

    antlr4::tree::TerminalNode *BRACEOPEN();
    antlr4::tree::TerminalNode *STAR();
    antlr4::tree::TerminalNode *BRACECLOSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberRangeSingleValueContext : public NumberRangeContext {
  public:
    NumberRangeSingleValueContext(NumberRangeContext *ctx);

    antlr4::Token *count = nullptr;
    antlr4::tree::TerminalNode *BRACEOPEN();
    antlr4::tree::TerminalNode *BRACECLOSE();
    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberRangeStartToEndContext : public NumberRangeContext {
  public:
    NumberRangeStartToEndContext(NumberRangeContext *ctx);

    antlr4::Token *rangeStart = nullptr;
    antlr4::Token *rangeEnd = nullptr;
    antlr4::tree::TerminalNode *BRACEOPEN();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *BRACECLOSE();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberRangeEmptyContext : public NumberRangeContext {
  public:
    NumberRangeEmptyContext(NumberRangeContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberRangeOpenStartToEndContext : public NumberRangeContext {
  public:
    NumberRangeOpenStartToEndContext(NumberRangeContext *ctx);

    antlr4::Token *rangeEnd = nullptr;
    antlr4::tree::TerminalNode *BRACEOPEN();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *BRACECLOSE();
    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberRangeStartToOpenEndContext : public NumberRangeContext {
  public:
    NumberRangeStartToOpenEndContext(NumberRangeContext *ctx);

    antlr4::Token *rangeStart = nullptr;
    antlr4::tree::TerminalNode *BRACEOPEN();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *BRACECLOSE();
    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  NumberRangeContext* numberRange();

  class  WordRangeContext : public antlr4::ParserRuleContext {
  public:
    WordRangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    WordRangeContext() = default;
    void copyFrom(WordRangeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  WordRangeFirstWordsContext : public WordRangeContext {
  public:
    WordRangeFirstWordsContext(WordRangeContext *ctx);

    antlr4::Token *lastWord = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WordRangeLastWordsContext : public WordRangeContext {
  public:
    WordRangeLastWordsContext(WordRangeContext *ctx);

    antlr4::Token *firstWord = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WordRangeStartToEndContext : public WordRangeContext {
  public:
    WordRangeStartToEndContext(WordRangeContext *ctx);

    antlr4::Token *firstWord = nullptr;
    antlr4::Token *lastWord = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *MINUS();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    std::vector<antlr4::tree::TerminalNode *> NUMBER();
    antlr4::tree::TerminalNode* NUMBER(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WordRangeSingleWordContext : public WordRangeContext {
  public:
    WordRangeSingleWordContext(WordRangeContext *ctx);

    antlr4::Token *singleWord = nullptr;
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *BLOCKCLOSE();
    antlr4::tree::TerminalNode *NUMBER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  WordRangeContext* wordRange();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool matcherSempred(MatcherContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace ycpp
