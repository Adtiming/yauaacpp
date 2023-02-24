
// Generated from UserAgentTreeWalker.g4 by ANTLR 4.7.2


#include "UserAgentTreeWalkerListener.h"
#include "UserAgentTreeWalkerVisitor.h"

#include "UserAgentTreeWalkerParser.h"


using namespace antlrcpp;
using namespace ycpp;
using namespace antlr4;

UserAgentTreeWalkerParser::UserAgentTreeWalkerParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

UserAgentTreeWalkerParser::~UserAgentTreeWalkerParser() {
  delete _interpreter;
}

std::string UserAgentTreeWalkerParser::getGrammarFileName() const {
  return "UserAgentTreeWalker.g4";
}

const std::vector<std::string>& UserAgentTreeWalkerParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& UserAgentTreeWalkerParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- MatcherRequireContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherRequireContext::MatcherRequireContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::MatcherRequireContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleMatcherRequire;
}

void UserAgentTreeWalkerParser::MatcherRequireContext::copyFrom(MatcherRequireContext *ctx) {
  antlr4::ParserRuleContext::copyFrom(ctx);
}

//----------------- IsSyntaxErrorContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::IsSyntaxErrorContext::EQUALS() {
  return getToken(UserAgentTreeWalkerParser::EQUALS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::IsSyntaxErrorContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::IsSyntaxErrorContext::IsSyntaxErrorContext(MatcherRequireContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::IsSyntaxErrorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIsSyntaxError(this);
}
void UserAgentTreeWalkerParser::IsSyntaxErrorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIsSyntaxError(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::IsSyntaxErrorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitIsSyntaxError(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherBaseContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherBaseContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherBaseContext::EOF() {
  return getToken(UserAgentTreeWalkerParser::EOF, 0);
}

UserAgentTreeWalkerParser::MatcherBaseContext::MatcherBaseContext(MatcherRequireContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherBaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherBase(this);
}
void UserAgentTreeWalkerParser::MatcherBaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherBase(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherBaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherBase(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsNullContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNullContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsNullContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNullContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNullContext::EOF() {
  return getToken(UserAgentTreeWalkerParser::EOF, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsNullContext::MatcherPathIsNullContext(MatcherRequireContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsNullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsNull(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsNullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsNull(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherPathIsNullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsNull(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::MatcherRequireContext* UserAgentTreeWalkerParser::matcherRequire() {
  MatcherRequireContext *_localctx = _tracker.createInstance<MatcherRequireContext>(_ctx, getState());
  enterRule(_localctx, 0, UserAgentTreeWalkerParser::RuleMatcherRequire);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(28);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentTreeWalkerParser::T__2:
      case UserAgentTreeWalkerParser::T__3:
      case UserAgentTreeWalkerParser::T__4:
      case UserAgentTreeWalkerParser::T__5:
      case UserAgentTreeWalkerParser::T__6:
      case UserAgentTreeWalkerParser::T__7:
      case UserAgentTreeWalkerParser::T__8:
      case UserAgentTreeWalkerParser::T__9:
      case UserAgentTreeWalkerParser::T__10:
      case UserAgentTreeWalkerParser::T__11:
      case UserAgentTreeWalkerParser::T__12:
      case UserAgentTreeWalkerParser::T__13:
      case UserAgentTreeWalkerParser::T__14:
      case UserAgentTreeWalkerParser::T__15:
      case UserAgentTreeWalkerParser::VALUE:
      case UserAgentTreeWalkerParser::BACKTOFULL: {
        _localctx = dynamic_cast<MatcherRequireContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::MatcherBaseContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(16);
        matcher(0);
        setState(17);
        match(UserAgentTreeWalkerParser::EOF);
        break;
      }

      case UserAgentTreeWalkerParser::T__0: {
        _localctx = dynamic_cast<MatcherRequireContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::IsSyntaxErrorContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(19);
        match(UserAgentTreeWalkerParser::T__0);
        setState(20);
        match(UserAgentTreeWalkerParser::EQUALS);
        setState(21);
        dynamic_cast<IsSyntaxErrorContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        break;
      }

      case UserAgentTreeWalkerParser::T__1: {
        _localctx = dynamic_cast<MatcherRequireContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::MatcherPathIsNullContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(22);
        match(UserAgentTreeWalkerParser::T__1);
        setState(23);
        match(UserAgentTreeWalkerParser::BLOCKOPEN);
        setState(24);
        matcher(0);
        setState(25);
        match(UserAgentTreeWalkerParser::BLOCKCLOSE);
        setState(26);
        match(UserAgentTreeWalkerParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatcherExtractContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherExtractContext::MatcherExtractContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherExtractContext::EOF() {
  return getToken(UserAgentTreeWalkerParser::EOF, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherExtractContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}


size_t UserAgentTreeWalkerParser::MatcherExtractContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleMatcherExtract;
}

void UserAgentTreeWalkerParser::MatcherExtractContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherExtract(this);
}

void UserAgentTreeWalkerParser::MatcherExtractContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherExtract(this);
}


antlrcpp::Any UserAgentTreeWalkerParser::MatcherExtractContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherExtract(this);
  else
    return visitor->visitChildren(this);
}

UserAgentTreeWalkerParser::MatcherExtractContext* UserAgentTreeWalkerParser::matcherExtract() {
  MatcherExtractContext *_localctx = _tracker.createInstance<MatcherExtractContext>(_ctx, getState());
  enterRule(_localctx, 2, UserAgentTreeWalkerParser::RuleMatcherExtract);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    dynamic_cast<MatcherExtractContext *>(_localctx)->expression = matcher(0);
    setState(31);
    match(UserAgentTreeWalkerParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatcherVariableContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherVariableContext::MatcherVariableContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherVariableContext::EOF() {
  return getToken(UserAgentTreeWalkerParser::EOF, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherVariableContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}


size_t UserAgentTreeWalkerParser::MatcherVariableContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleMatcherVariable;
}

void UserAgentTreeWalkerParser::MatcherVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherVariable(this);
}

void UserAgentTreeWalkerParser::MatcherVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherVariable(this);
}


antlrcpp::Any UserAgentTreeWalkerParser::MatcherVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherVariable(this);
  else
    return visitor->visitChildren(this);
}

UserAgentTreeWalkerParser::MatcherVariableContext* UserAgentTreeWalkerParser::matcherVariable() {
  MatcherVariableContext *_localctx = _tracker.createInstance<MatcherVariableContext>(_ctx, getState());
  enterRule(_localctx, 4, UserAgentTreeWalkerParser::RuleMatcherVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    dynamic_cast<MatcherVariableContext *>(_localctx)->expression = matcher(0);
    setState(34);
    match(UserAgentTreeWalkerParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatcherContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherContext::MatcherContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::MatcherContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleMatcher;
}

void UserAgentTreeWalkerParser::MatcherContext::copyFrom(MatcherContext *ctx) {
  antlr4::ParserRuleContext::copyFrom(ctx);
}

//----------------- MatcherCleanVersionContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherCleanVersionContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherCleanVersionContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherCleanVersionContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

UserAgentTreeWalkerParser::MatcherCleanVersionContext::MatcherCleanVersionContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherCleanVersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherCleanVersion(this);
}
void UserAgentTreeWalkerParser::MatcherCleanVersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherCleanVersion(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherCleanVersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherCleanVersion(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathLookupPrefixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::MatcherPathLookupPrefixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathLookupPrefix(this);
}
void UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathLookupPrefix(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathLookupPrefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathLookupContainsContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::MatcherPathLookupContainsContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathLookupContains(this);
}
void UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathLookupContains(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathLookupContains(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherConcatPrefixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherConcatPrefixContext::MatcherConcatPrefixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherConcatPrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherConcatPrefix(this);
}
void UserAgentTreeWalkerParser::MatcherConcatPrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherConcatPrefix(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherConcatPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherConcatPrefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsInLookupContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::MatcherPathIsInLookupContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsInLookup(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsInLookup(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsInLookup(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherWordRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherWordRangeContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

UserAgentTreeWalkerParser::WordRangeContext* UserAgentTreeWalkerParser::MatcherWordRangeContext::wordRange() {
  return getRuleContext<UserAgentTreeWalkerParser::WordRangeContext>(0);
}

UserAgentTreeWalkerParser::MatcherWordRangeContext::MatcherWordRangeContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherWordRangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherWordRange(this);
}
void UserAgentTreeWalkerParser::MatcherWordRangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherWordRange(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherWordRangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherWordRange(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherSegmentRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherSegmentRangeContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherSegmentRangeContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::WordRangeContext* UserAgentTreeWalkerParser::MatcherSegmentRangeContext::wordRange() {
  return getRuleContext<UserAgentTreeWalkerParser::WordRangeContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherSegmentRangeContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

UserAgentTreeWalkerParser::MatcherSegmentRangeContext::MatcherSegmentRangeContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherSegmentRangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherSegmentRange(this);
}
void UserAgentTreeWalkerParser::MatcherSegmentRangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherSegmentRange(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherSegmentRangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherSegmentRange(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherNormalizeBrandContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::MatcherNormalizeBrandContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherNormalizeBrand(this);
}
void UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherNormalizeBrand(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherNormalizeBrand(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherConcatContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherConcatContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherConcatContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherConcatContext::VALUE() {
  return getTokens(UserAgentTreeWalkerParser::VALUE);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatContext::VALUE(size_t i) {
  return getToken(UserAgentTreeWalkerParser::VALUE, i);
}

UserAgentTreeWalkerParser::MatcherConcatContext::MatcherConcatContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherConcatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherConcat(this);
}
void UserAgentTreeWalkerParser::MatcherConcatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherConcat(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherConcatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherConcat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsInLookupContainsContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::MatcherPathIsInLookupContainsContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsInLookupContains(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsInLookupContains(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsInLookupContains(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherDefaultIfNullContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::MatcherDefaultIfNullContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherDefaultIfNull(this);
}
void UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherDefaultIfNull(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherDefaultIfNull(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::BasePathContext* UserAgentTreeWalkerParser::MatcherPathContext::basePath() {
  return getRuleContext<UserAgentTreeWalkerParser::BasePathContext>(0);
}

UserAgentTreeWalkerParser::MatcherPathContext::MatcherPathContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPath(this);
}
void UserAgentTreeWalkerParser::MatcherPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPath(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherPathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPath(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsNotInLookupPrefixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::MatcherPathIsNotInLookupPrefixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsNotInLookupPrefix(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsNotInLookupPrefix(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsNotInLookupPrefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherReplaceStringContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherReplaceStringContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherReplaceStringContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherReplaceStringContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherReplaceStringContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherReplaceStringContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherReplaceStringContext::VALUE() {
  return getTokens(UserAgentTreeWalkerParser::VALUE);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherReplaceStringContext::VALUE(size_t i) {
  return getToken(UserAgentTreeWalkerParser::VALUE, i);
}

UserAgentTreeWalkerParser::MatcherReplaceStringContext::MatcherReplaceStringContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherReplaceStringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherReplaceString(this);
}
void UserAgentTreeWalkerParser::MatcherReplaceStringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherReplaceString(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherReplaceStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherReplaceString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathLookupContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherPathLookupContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathLookupContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherPathLookupContext::MatcherPathLookupContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathLookupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathLookup(this);
}
void UserAgentTreeWalkerParser::MatcherPathLookupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathLookup(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherPathLookupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathLookup(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherExtractBrandFromUrlContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::MatcherExtractBrandFromUrlContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherExtractBrandFromUrl(this);
}
void UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherExtractBrandFromUrl(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherExtractBrandFromUrl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherConcatPostfixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherConcatPostfixContext::MatcherConcatPostfixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherConcatPostfixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherConcatPostfix(this);
}
void UserAgentTreeWalkerParser::MatcherConcatPostfixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherConcatPostfix(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherConcatPostfixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherConcatPostfix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsInLookupPrefixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::MatcherPathIsInLookupPrefixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsInLookupPrefix(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsInLookupPrefix(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsInLookupPrefix(this);
  else
    return visitor->visitChildren(this);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::matcher() {
   return matcher(0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::matcher(int precedence) {
  antlr4::ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  UserAgentTreeWalkerParser::MatcherContext *_localctx = _tracker.createInstance<MatcherContext>(_ctx, parentState);
  UserAgentTreeWalkerParser::MatcherContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, UserAgentTreeWalkerParser::RuleMatcher, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MatcherPathContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(37);
      basePath();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MatcherConcatContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(38);
      match(UserAgentTreeWalkerParser::T__2);
      setState(39);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(40);
      dynamic_cast<MatcherConcatContext *>(_localctx)->prefix = match(UserAgentTreeWalkerParser::VALUE);
      setState(41);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(42);
      matcher(0);
      setState(43);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(44);
      dynamic_cast<MatcherConcatContext *>(_localctx)->postfix = match(UserAgentTreeWalkerParser::VALUE);
      setState(45);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MatcherConcatPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(47);
      match(UserAgentTreeWalkerParser::T__2);
      setState(48);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(49);
      dynamic_cast<MatcherConcatPrefixContext *>(_localctx)->prefix = match(UserAgentTreeWalkerParser::VALUE);
      setState(50);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(51);
      matcher(0);
      setState(52);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MatcherConcatPostfixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(54);
      match(UserAgentTreeWalkerParser::T__2);
      setState(55);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(56);
      matcher(0);
      setState(57);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(58);
      dynamic_cast<MatcherConcatPostfixContext *>(_localctx)->postfix = match(UserAgentTreeWalkerParser::VALUE);
      setState(59);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MatcherNormalizeBrandContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(61);
      match(UserAgentTreeWalkerParser::T__3);
      setState(62);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(63);
      matcher(0);
      setState(64);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MatcherExtractBrandFromUrlContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(66);
      match(UserAgentTreeWalkerParser::T__4);
      setState(67);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(68);
      matcher(0);
      setState(69);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<MatcherCleanVersionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(71);
      match(UserAgentTreeWalkerParser::T__5);
      setState(72);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(73);
      matcher(0);
      setState(74);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<MatcherReplaceStringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(76);
      match(UserAgentTreeWalkerParser::T__6);
      setState(77);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(78);
      matcher(0);
      setState(79);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(80);
      dynamic_cast<MatcherReplaceStringContext *>(_localctx)->search = match(UserAgentTreeWalkerParser::VALUE);
      setState(81);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(82);
      dynamic_cast<MatcherReplaceStringContext *>(_localctx)->replace = match(UserAgentTreeWalkerParser::VALUE);
      setState(83);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<MatcherPathLookupContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(85);
      match(UserAgentTreeWalkerParser::T__7);
      setState(86);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(87);
      dynamic_cast<MatcherPathLookupContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(88);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(89);
      matcher(0);
      setState(92);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentTreeWalkerParser::SEMICOLON) {
        setState(90);
        match(UserAgentTreeWalkerParser::SEMICOLON);
        setState(91);
        dynamic_cast<MatcherPathLookupContext *>(_localctx)->defaultValue = match(UserAgentTreeWalkerParser::VALUE);
      }
      setState(94);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<MatcherPathIsInLookupContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(96);
      match(UserAgentTreeWalkerParser::T__8);
      setState(97);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(98);
      dynamic_cast<MatcherPathIsInLookupContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(99);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(100);
      matcher(0);
      setState(101);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<MatcherPathLookupContainsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(103);
      match(UserAgentTreeWalkerParser::T__9);
      setState(104);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(105);
      dynamic_cast<MatcherPathLookupContainsContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(106);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(107);
      matcher(0);
      setState(110);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentTreeWalkerParser::SEMICOLON) {
        setState(108);
        match(UserAgentTreeWalkerParser::SEMICOLON);
        setState(109);
        dynamic_cast<MatcherPathLookupContainsContext *>(_localctx)->defaultValue = match(UserAgentTreeWalkerParser::VALUE);
      }
      setState(112);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<MatcherPathIsInLookupContainsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(114);
      match(UserAgentTreeWalkerParser::T__10);
      setState(115);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(116);
      dynamic_cast<MatcherPathIsInLookupContainsContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(117);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(118);
      matcher(0);
      setState(119);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<MatcherPathLookupPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(121);
      match(UserAgentTreeWalkerParser::T__11);
      setState(122);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(123);
      dynamic_cast<MatcherPathLookupPrefixContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(124);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(125);
      matcher(0);
      setState(128);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentTreeWalkerParser::SEMICOLON) {
        setState(126);
        match(UserAgentTreeWalkerParser::SEMICOLON);
        setState(127);
        dynamic_cast<MatcherPathLookupPrefixContext *>(_localctx)->defaultValue = match(UserAgentTreeWalkerParser::VALUE);
      }
      setState(130);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<MatcherPathIsInLookupPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(132);
      match(UserAgentTreeWalkerParser::T__12);
      setState(133);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(134);
      dynamic_cast<MatcherPathIsInLookupPrefixContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(135);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(136);
      matcher(0);
      setState(137);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<MatcherPathIsNotInLookupPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(139);
      match(UserAgentTreeWalkerParser::T__13);
      setState(140);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(141);
      dynamic_cast<MatcherPathIsNotInLookupPrefixContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(142);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(143);
      matcher(0);
      setState(144);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<MatcherDefaultIfNullContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(146);
      match(UserAgentTreeWalkerParser::T__14);
      setState(147);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(148);
      matcher(0);
      setState(149);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(150);
      dynamic_cast<MatcherDefaultIfNullContext *>(_localctx)->defaultValue = match(UserAgentTreeWalkerParser::VALUE);
      setState(151);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(164);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(162);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MatcherWordRangeContext>(_tracker.createInstance<MatcherContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleMatcher);
          setState(155);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(156);
          wordRange();
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MatcherSegmentRangeContext>(_tracker.createInstance<MatcherContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleMatcher);
          setState(157);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(158);
          match(UserAgentTreeWalkerParser::BLOCKOPEN);
          setState(159);
          wordRange();
          setState(160);
          match(UserAgentTreeWalkerParser::BLOCKCLOSE);
          break;
        }

        } 
      }
      setState(166);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BasePathContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::BasePathContext::BasePathContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::BasePathContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleBasePath;
}

void UserAgentTreeWalkerParser::BasePathContext::copyFrom(BasePathContext *ctx) {
  antlr4::ParserRuleContext::copyFrom(ctx);
}

//----------------- PathVariableContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::PathVariableContext::BACKTOFULL() {
  return getToken(UserAgentTreeWalkerParser::BACKTOFULL, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::PathVariableContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::PathVariableContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::PathVariableContext::PathVariableContext(BasePathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::PathVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathVariable(this);
}
void UserAgentTreeWalkerParser::PathVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathVariable(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::PathVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitPathVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PathWalkContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::PathWalkContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::PathWalkContext::PathWalkContext(BasePathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::PathWalkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathWalk(this);
}
void UserAgentTreeWalkerParser::PathWalkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathWalk(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::PathWalkContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitPathWalk(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PathFixedValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::PathFixedValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathFixedValueContext::PathFixedValueContext(BasePathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::PathFixedValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathFixedValue(this);
}
void UserAgentTreeWalkerParser::PathFixedValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathFixedValue(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::PathFixedValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitPathFixedValue(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::BasePathContext* UserAgentTreeWalkerParser::basePath() {
  BasePathContext *_localctx = _tracker.createInstance<BasePathContext>(_ctx, getState());
  enterRule(_localctx, 8, UserAgentTreeWalkerParser::RuleBasePath);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentTreeWalkerParser::VALUE: {
        _localctx = dynamic_cast<BasePathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::PathFixedValueContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(167);
        dynamic_cast<PathFixedValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        break;
      }

      case UserAgentTreeWalkerParser::BACKTOFULL: {
        _localctx = dynamic_cast<BasePathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::PathVariableContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(168);
        match(UserAgentTreeWalkerParser::BACKTOFULL);
        setState(169);
        dynamic_cast<PathVariableContext *>(_localctx)->variable = match(UserAgentTreeWalkerParser::VALUENAME);
        setState(171);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          setState(170);
          dynamic_cast<PathVariableContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::T__15: {
        _localctx = dynamic_cast<BasePathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::PathWalkContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(173);
        match(UserAgentTreeWalkerParser::T__15);
        setState(175);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          setState(174);
          dynamic_cast<PathWalkContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::PathContext::PathContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::PathContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RulePath;
}

void UserAgentTreeWalkerParser::PathContext::copyFrom(PathContext *ctx) {
  antlr4::ParserRuleContext::copyFrom(ctx);
}

//----------------- StepNext4Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNext4Context::NEXT4() {
  return getToken(UserAgentTreeWalkerParser::NEXT4, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNext4Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNext4Context::StepNext4Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNext4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNext4(this);
}
void UserAgentTreeWalkerParser::StepNext4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNext4(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepNext4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNext4(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepStartsWithValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepStartsWithValueContext::STARTSWITH() {
  return getToken(UserAgentTreeWalkerParser::STARTSWITH, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepStartsWithValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepStartsWithValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepStartsWithValueContext::StepStartsWithValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepStartsWithValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepStartsWithValue(this);
}
void UserAgentTreeWalkerParser::StepStartsWithValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepStartsWithValue(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepStartsWithValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepStartsWithValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNext3Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNext3Context::NEXT3() {
  return getToken(UserAgentTreeWalkerParser::NEXT3, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNext3Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNext3Context::StepNext3Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNext3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNext3(this);
}
void UserAgentTreeWalkerParser::StepNext3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNext3(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepNext3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNext3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepPrev4Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepPrev4Context::PREV4() {
  return getToken(UserAgentTreeWalkerParser::PREV4, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepPrev4Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepPrev4Context::StepPrev4Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepPrev4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepPrev4(this);
}
void UserAgentTreeWalkerParser::StepPrev4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepPrev4(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepPrev4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepPrev4(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepPrev3Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepPrev3Context::PREV3() {
  return getToken(UserAgentTreeWalkerParser::PREV3, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepPrev3Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepPrev3Context::StepPrev3Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepPrev3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepPrev3(this);
}
void UserAgentTreeWalkerParser::StepPrev3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepPrev3(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepPrev3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepPrev3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepPrev2Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepPrev2Context::PREV2() {
  return getToken(UserAgentTreeWalkerParser::PREV2, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepPrev2Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepPrev2Context::StepPrev2Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepPrev2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepPrev2(this);
}
void UserAgentTreeWalkerParser::StepPrev2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepPrev2(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepPrev2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepPrev2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepIsInSetContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepIsInSetContext::IN() {
  return getToken(UserAgentTreeWalkerParser::IN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepIsInSetContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepIsInSetContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepIsInSetContext::StepIsInSetContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepIsInSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepIsInSet(this);
}
void UserAgentTreeWalkerParser::StepIsInSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepIsInSet(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepIsInSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepIsInSet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNext2Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNext2Context::NEXT2() {
  return getToken(UserAgentTreeWalkerParser::NEXT2, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNext2Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNext2Context::StepNext2Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNext2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNext2(this);
}
void UserAgentTreeWalkerParser::StepNext2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNext2(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepNext2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNext2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepUpContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepUpContext::UP() {
  return getToken(UserAgentTreeWalkerParser::UP, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepUpContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepUpContext::StepUpContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepUpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepUp(this);
}
void UserAgentTreeWalkerParser::StepUpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepUp(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepUpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepUp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepEndsWithValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepEndsWithValueContext::ENDSWITH() {
  return getToken(UserAgentTreeWalkerParser::ENDSWITH, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepEndsWithValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepEndsWithValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepEndsWithValueContext::StepEndsWithValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepEndsWithValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepEndsWithValue(this);
}
void UserAgentTreeWalkerParser::StepEndsWithValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepEndsWithValue(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepEndsWithValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepEndsWithValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepIsNotInSetContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepIsNotInSetContext::NOTIN() {
  return getToken(UserAgentTreeWalkerParser::NOTIN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepIsNotInSetContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepIsNotInSetContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepIsNotInSetContext::StepIsNotInSetContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepIsNotInSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepIsNotInSet(this);
}
void UserAgentTreeWalkerParser::StepIsNotInSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepIsNotInSet(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepIsNotInSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepIsNotInSet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepEqualsValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepEqualsValueContext::EQUALS() {
  return getToken(UserAgentTreeWalkerParser::EQUALS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepEqualsValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepEqualsValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepEqualsValueContext::StepEqualsValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepEqualsValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepEqualsValue(this);
}
void UserAgentTreeWalkerParser::StepEqualsValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepEqualsValue(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepEqualsValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepEqualsValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepDownContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepDownContext::DOT() {
  return getToken(UserAgentTreeWalkerParser::DOT, 0);
}

UserAgentTreeWalkerParser::NumberRangeContext* UserAgentTreeWalkerParser::StepDownContext::numberRange() {
  return getRuleContext<UserAgentTreeWalkerParser::NumberRangeContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepDownContext::PATHTOKENNAME() {
  return getToken(UserAgentTreeWalkerParser::PATHTOKENNAME, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepDownContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepDownContext::StepDownContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepDownContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepDown(this);
}
void UserAgentTreeWalkerParser::StepDownContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepDown(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepDownContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepDown(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepWordRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::WordRangeContext* UserAgentTreeWalkerParser::StepWordRangeContext::wordRange() {
  return getRuleContext<UserAgentTreeWalkerParser::WordRangeContext>(0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepWordRangeContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepWordRangeContext::StepWordRangeContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepWordRangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepWordRange(this);
}
void UserAgentTreeWalkerParser::StepWordRangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepWordRange(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepWordRangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepWordRange(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNotEqualsValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNotEqualsValueContext::NOTEQUALS() {
  return getToken(UserAgentTreeWalkerParser::NOTEQUALS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepNotEqualsValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNotEqualsValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNotEqualsValueContext::StepNotEqualsValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNotEqualsValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNotEqualsValue(this);
}
void UserAgentTreeWalkerParser::StepNotEqualsValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNotEqualsValue(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepNotEqualsValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNotEqualsValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepBackToFullContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepBackToFullContext::BACKTOFULL() {
  return getToken(UserAgentTreeWalkerParser::BACKTOFULL, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepBackToFullContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepBackToFullContext::StepBackToFullContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepBackToFullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepBackToFull(this);
}
void UserAgentTreeWalkerParser::StepBackToFullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepBackToFull(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepBackToFullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepBackToFull(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepPrevContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepPrevContext::PREV() {
  return getToken(UserAgentTreeWalkerParser::PREV, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepPrevContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepPrevContext::StepPrevContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepPrevContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepPrev(this);
}
void UserAgentTreeWalkerParser::StepPrevContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepPrev(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepPrevContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepPrev(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNextContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNextContext::NEXT() {
  return getToken(UserAgentTreeWalkerParser::NEXT, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNextContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNextContext::StepNextContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNextContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNext(this);
}
void UserAgentTreeWalkerParser::StepNextContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNext(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepNextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNext(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepContainsValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepContainsValueContext::CONTAINS() {
  return getToken(UserAgentTreeWalkerParser::CONTAINS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepContainsValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepContainsValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepContainsValueContext::StepContainsValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepContainsValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepContainsValue(this);
}
void UserAgentTreeWalkerParser::StepContainsValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepContainsValue(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepContainsValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepContainsValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNotContainsValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNotContainsValueContext::NOTCONTAINS() {
  return getToken(UserAgentTreeWalkerParser::NOTCONTAINS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepNotContainsValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNotContainsValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNotContainsValueContext::StepNotContainsValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNotContainsValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNotContainsValue(this);
}
void UserAgentTreeWalkerParser::StepNotContainsValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNotContainsValue(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::StepNotContainsValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNotContainsValue(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::path() {
  PathContext *_localctx = _tracker.createInstance<PathContext>(_ctx, getState());
  enterRule(_localctx, 10, UserAgentTreeWalkerParser::RulePath);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(269);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentTreeWalkerParser::DOT: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepDownContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(179);
        match(UserAgentTreeWalkerParser::DOT);
        setState(180);
        numberRange();
        setState(181);
        dynamic_cast<StepDownContext *>(_localctx)->name = match(UserAgentTreeWalkerParser::PATHTOKENNAME);
        setState(183);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          setState(182);
          dynamic_cast<StepDownContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::UP: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepUpContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(185);
        match(UserAgentTreeWalkerParser::UP);
        setState(187);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          setState(186);
          dynamic_cast<StepUpContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::NEXT: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepNextContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(189);
        match(UserAgentTreeWalkerParser::NEXT);
        setState(191);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          setState(190);
          dynamic_cast<StepNextContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::NEXT2: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepNext2Context>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(193);
        match(UserAgentTreeWalkerParser::NEXT2);
        setState(195);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          setState(194);
          dynamic_cast<StepNext2Context *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::NEXT3: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepNext3Context>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(197);
        match(UserAgentTreeWalkerParser::NEXT3);
        setState(199);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          setState(198);
          dynamic_cast<StepNext3Context *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::NEXT4: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepNext4Context>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(201);
        match(UserAgentTreeWalkerParser::NEXT4);
        setState(203);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          setState(202);
          dynamic_cast<StepNext4Context *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::PREV: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepPrevContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(205);
        match(UserAgentTreeWalkerParser::PREV);
        setState(207);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          setState(206);
          dynamic_cast<StepPrevContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::PREV2: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepPrev2Context>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(209);
        match(UserAgentTreeWalkerParser::PREV2);
        setState(211);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          setState(210);
          dynamic_cast<StepPrev2Context *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::PREV3: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepPrev3Context>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(213);
        match(UserAgentTreeWalkerParser::PREV3);
        setState(215);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          setState(214);
          dynamic_cast<StepPrev3Context *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::PREV4: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepPrev4Context>(_localctx));
        enterOuterAlt(_localctx, 10);
        setState(217);
        match(UserAgentTreeWalkerParser::PREV4);
        setState(219);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          setState(218);
          dynamic_cast<StepPrev4Context *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::EQUALS: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepEqualsValueContext>(_localctx));
        enterOuterAlt(_localctx, 11);
        setState(221);
        match(UserAgentTreeWalkerParser::EQUALS);
        setState(222);
        dynamic_cast<StepEqualsValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(224);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          setState(223);
          dynamic_cast<StepEqualsValueContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::NOTEQUALS: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepNotEqualsValueContext>(_localctx));
        enterOuterAlt(_localctx, 12);
        setState(226);
        match(UserAgentTreeWalkerParser::NOTEQUALS);
        setState(227);
        dynamic_cast<StepNotEqualsValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(229);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(228);
          dynamic_cast<StepNotEqualsValueContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::STARTSWITH: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepStartsWithValueContext>(_localctx));
        enterOuterAlt(_localctx, 13);
        setState(231);
        match(UserAgentTreeWalkerParser::STARTSWITH);
        setState(232);
        dynamic_cast<StepStartsWithValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(234);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          setState(233);
          dynamic_cast<StepStartsWithValueContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::ENDSWITH: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepEndsWithValueContext>(_localctx));
        enterOuterAlt(_localctx, 14);
        setState(236);
        match(UserAgentTreeWalkerParser::ENDSWITH);
        setState(237);
        dynamic_cast<StepEndsWithValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(239);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          setState(238);
          dynamic_cast<StepEndsWithValueContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::CONTAINS: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepContainsValueContext>(_localctx));
        enterOuterAlt(_localctx, 15);
        setState(241);
        match(UserAgentTreeWalkerParser::CONTAINS);
        setState(242);
        dynamic_cast<StepContainsValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(244);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          setState(243);
          dynamic_cast<StepContainsValueContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::NOTCONTAINS: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepNotContainsValueContext>(_localctx));
        enterOuterAlt(_localctx, 16);
        setState(246);
        match(UserAgentTreeWalkerParser::NOTCONTAINS);
        setState(247);
        dynamic_cast<StepNotContainsValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(249);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          setState(248);
          dynamic_cast<StepNotContainsValueContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::IN: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepIsInSetContext>(_localctx));
        enterOuterAlt(_localctx, 17);
        setState(251);
        match(UserAgentTreeWalkerParser::IN);
        setState(252);
        dynamic_cast<StepIsInSetContext *>(_localctx)->set = match(UserAgentTreeWalkerParser::VALUENAME);
        setState(254);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          setState(253);
          dynamic_cast<StepIsInSetContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::NOTIN: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepIsNotInSetContext>(_localctx));
        enterOuterAlt(_localctx, 18);
        setState(256);
        match(UserAgentTreeWalkerParser::NOTIN);
        setState(257);
        dynamic_cast<StepIsNotInSetContext *>(_localctx)->set = match(UserAgentTreeWalkerParser::VALUENAME);
        setState(259);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
        case 1: {
          setState(258);
          dynamic_cast<StepIsNotInSetContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::BLOCKOPEN: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepWordRangeContext>(_localctx));
        enterOuterAlt(_localctx, 19);
        setState(261);
        wordRange();
        setState(263);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          setState(262);
          dynamic_cast<StepWordRangeContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

      case UserAgentTreeWalkerParser::BACKTOFULL: {
        _localctx = dynamic_cast<PathContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::StepBackToFullContext>(_localctx));
        enterOuterAlt(_localctx, 20);
        setState(265);
        match(UserAgentTreeWalkerParser::BACKTOFULL);
        setState(267);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
        case 1: {
          setState(266);
          dynamic_cast<StepBackToFullContext *>(_localctx)->nextStep = path();
          break;
        }

        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::NumberRangeContext::NumberRangeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::NumberRangeContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleNumberRange;
}

void UserAgentTreeWalkerParser::NumberRangeContext::copyFrom(NumberRangeContext *ctx) {
  antlr4::ParserRuleContext::copyFrom(ctx);
}

//----------------- NumberRangeAllContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeAllContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeAllContext::STAR() {
  return getToken(UserAgentTreeWalkerParser::STAR, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeAllContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

UserAgentTreeWalkerParser::NumberRangeAllContext::NumberRangeAllContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeAllContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeAll(this);
}
void UserAgentTreeWalkerParser::NumberRangeAllContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeAll(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::NumberRangeAllContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeAll(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeSingleValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeSingleValueContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeSingleValueContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeSingleValueContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::NumberRangeSingleValueContext::NumberRangeSingleValueContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeSingleValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeSingleValue(this);
}
void UserAgentTreeWalkerParser::NumberRangeSingleValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeSingleValue(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::NumberRangeSingleValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeSingleValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeStartToEndContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToEndContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToEndContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToEndContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::NumberRangeStartToEndContext::NUMBER() {
  return getTokens(UserAgentTreeWalkerParser::NUMBER);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToEndContext::NUMBER(size_t i) {
  return getToken(UserAgentTreeWalkerParser::NUMBER, i);
}

UserAgentTreeWalkerParser::NumberRangeStartToEndContext::NumberRangeStartToEndContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeStartToEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeStartToEnd(this);
}
void UserAgentTreeWalkerParser::NumberRangeStartToEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeStartToEnd(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::NumberRangeStartToEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeStartToEnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeEmptyContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::NumberRangeEmptyContext::NumberRangeEmptyContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeEmpty(this);
}
void UserAgentTreeWalkerParser::NumberRangeEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeEmpty(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::NumberRangeEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeEmpty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeOpenStartToEndContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::NumberRangeOpenStartToEndContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeOpenStartToEnd(this);
}
void UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeOpenStartToEnd(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeOpenStartToEnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeStartToOpenEndContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::NumberRangeStartToOpenEndContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeStartToOpenEnd(this);
}
void UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeStartToOpenEnd(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeStartToOpenEnd(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::NumberRangeContext* UserAgentTreeWalkerParser::numberRange() {
  NumberRangeContext *_localctx = _tracker.createInstance<NumberRangeContext>(_ctx, getState());
  enterRule(_localctx, 12, UserAgentTreeWalkerParser::RuleNumberRange);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(291);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<NumberRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeStartToEndContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(271);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(272);
      dynamic_cast<NumberRangeStartToEndContext *>(_localctx)->rangeStart = match(UserAgentTreeWalkerParser::NUMBER);
      setState(273);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(274);
      dynamic_cast<NumberRangeStartToEndContext *>(_localctx)->rangeEnd = match(UserAgentTreeWalkerParser::NUMBER);
      setState(275);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<NumberRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(276);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(277);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(278);
      dynamic_cast<NumberRangeOpenStartToEndContext *>(_localctx)->rangeEnd = match(UserAgentTreeWalkerParser::NUMBER);
      setState(279);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<NumberRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(280);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(281);
      dynamic_cast<NumberRangeStartToOpenEndContext *>(_localctx)->rangeStart = match(UserAgentTreeWalkerParser::NUMBER);
      setState(282);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(283);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<NumberRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeSingleValueContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(284);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(285);
      dynamic_cast<NumberRangeSingleValueContext *>(_localctx)->count = match(UserAgentTreeWalkerParser::NUMBER);
      setState(286);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<NumberRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeAllContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(287);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(288);
      match(UserAgentTreeWalkerParser::STAR);
      setState(289);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 6: {
      _localctx = dynamic_cast<NumberRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeEmptyContext>(_localctx));
      enterOuterAlt(_localctx, 6);

      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WordRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::WordRangeContext::WordRangeContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::WordRangeContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleWordRange;
}

void UserAgentTreeWalkerParser::WordRangeContext::copyFrom(WordRangeContext *ctx) {
  antlr4::ParserRuleContext::copyFrom(ctx);
}

//----------------- WordRangeFirstWordsContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeFirstWordsContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeFirstWordsContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeFirstWordsContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeFirstWordsContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::WordRangeFirstWordsContext::WordRangeFirstWordsContext(WordRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::WordRangeFirstWordsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWordRangeFirstWords(this);
}
void UserAgentTreeWalkerParser::WordRangeFirstWordsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWordRangeFirstWords(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::WordRangeFirstWordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitWordRangeFirstWords(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WordRangeLastWordsContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeLastWordsContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeLastWordsContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeLastWordsContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeLastWordsContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::WordRangeLastWordsContext::WordRangeLastWordsContext(WordRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::WordRangeLastWordsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWordRangeLastWords(this);
}
void UserAgentTreeWalkerParser::WordRangeLastWordsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWordRangeLastWords(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::WordRangeLastWordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitWordRangeLastWords(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WordRangeStartToEndContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeStartToEndContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeStartToEndContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeStartToEndContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::WordRangeStartToEndContext::NUMBER() {
  return getTokens(UserAgentTreeWalkerParser::NUMBER);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeStartToEndContext::NUMBER(size_t i) {
  return getToken(UserAgentTreeWalkerParser::NUMBER, i);
}

UserAgentTreeWalkerParser::WordRangeStartToEndContext::WordRangeStartToEndContext(WordRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::WordRangeStartToEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWordRangeStartToEnd(this);
}
void UserAgentTreeWalkerParser::WordRangeStartToEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWordRangeStartToEnd(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::WordRangeStartToEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitWordRangeStartToEnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WordRangeSingleWordContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeSingleWordContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeSingleWordContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeSingleWordContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::WordRangeSingleWordContext::WordRangeSingleWordContext(WordRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::WordRangeSingleWordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWordRangeSingleWord(this);
}
void UserAgentTreeWalkerParser::WordRangeSingleWordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWordRangeSingleWord(this);
}

antlrcpp::Any UserAgentTreeWalkerParser::WordRangeSingleWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitWordRangeSingleWord(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::WordRangeContext* UserAgentTreeWalkerParser::wordRange() {
  WordRangeContext *_localctx = _tracker.createInstance<WordRangeContext>(_ctx, getState());
  enterRule(_localctx, 14, UserAgentTreeWalkerParser::RuleWordRange);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(309);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<WordRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::WordRangeStartToEndContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(293);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(294);
      dynamic_cast<WordRangeStartToEndContext *>(_localctx)->firstWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(295);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(296);
      dynamic_cast<WordRangeStartToEndContext *>(_localctx)->lastWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(297);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<WordRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::WordRangeFirstWordsContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(298);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(299);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(300);
      dynamic_cast<WordRangeFirstWordsContext *>(_localctx)->lastWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(301);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<WordRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::WordRangeLastWordsContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(302);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(303);
      dynamic_cast<WordRangeLastWordsContext *>(_localctx)->firstWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(304);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(305);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<WordRangeContext *>(_tracker.createInstance<UserAgentTreeWalkerParser::WordRangeSingleWordContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(306);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(307);
      dynamic_cast<WordRangeSingleWordContext *>(_localctx)->singleWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(308);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool UserAgentTreeWalkerParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return matcherSempred(dynamic_cast<MatcherContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool UserAgentTreeWalkerParser::matcherSempred(MatcherContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> UserAgentTreeWalkerParser::_decisionToDFA;
atn::PredictionContextCache UserAgentTreeWalkerParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN UserAgentTreeWalkerParser::_atn;
std::vector<uint16_t> UserAgentTreeWalkerParser::_serializedATN;

std::vector<std::string> UserAgentTreeWalkerParser::_ruleNames = {
  "matcherRequire", "matcherExtract", "matcherVariable", "matcher", "basePath", 
  "path", "numberRange", "wordRange"
};

std::vector<std::string> UserAgentTreeWalkerParser::_literalNames = {
  "", "'__SyntaxError__'", "'IsNull'", "'Concat'", "'NormalizeBrand'", "'ExtractBrandFromUrl'", 
  "'CleanVersion'", "'ReplaceString'", "'LookUp'", "'IsInLookUp'", "'LookUpContains'", 
  "'IsInLookUpContains'", "'LookUpPrefix'", "'IsInLookUpPrefix'", "'IsNotInLookUpPrefix'", 
  "'DefaultIfNull'", "'agent'", "", "", "", "'^'", "'>'", "'>>'", "'>>>'", 
  "'>>>>'", "'<'", "'<<'", "'<<<'", "'<<<<'", "'.'", "'-'", "'*'", "'?'", 
  "'?!'", "", "'['", "']'", "'('", "')'", "'\"'", "':'", "';'", "", "'!='", 
  "'='", "'~'", "'!~'", "'{'", "'}'", "'@'"
};

std::vector<std::string> UserAgentTreeWalkerParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "PATHTOKENNAME", 
  "VALUENAME", "VALUE", "UP", "NEXT", "NEXT2", "NEXT3", "NEXT4", "PREV", 
  "PREV2", "PREV3", "PREV4", "DOT", "MINUS", "STAR", "IN", "NOTIN", "NUMBER", 
  "BLOCKOPEN", "BLOCKCLOSE", "BRACEOPEN", "BRACECLOSE", "DOUBLEQUOTE", "COLON", 
  "SEMICOLON", "SPACE", "NOTEQUALS", "EQUALS", "CONTAINS", "NOTCONTAINS", 
  "STARTSWITH", "ENDSWITH", "BACKTOFULL"
};

dfa::Vocabulary UserAgentTreeWalkerParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> UserAgentTreeWalkerParser::_tokenNames;

UserAgentTreeWalkerParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x33, 0x13a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x1f, 0xa, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x5f, 0xa, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x71, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x83, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x9c, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0xa5, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xa8, 0xb, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0xae, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 
    0xb2, 0xa, 0x6, 0x5, 0x6, 0xb4, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x5, 0x7, 0xba, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xbe, 
    0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xc2, 0xa, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0xc6, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xca, 0xa, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xce, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0xd2, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xd6, 0xa, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xda, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
    0x7, 0xde, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xe3, 0xa, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xe8, 0xa, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xed, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x5, 0x7, 0xf2, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0xf7, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0xfc, 0xa, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x101, 0xa, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x5, 0x7, 0x106, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
    0x10a, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x10e, 0xa, 0x7, 0x5, 
    0x7, 0x110, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0x126, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x138, 
    0xa, 0x9, 0x3, 0x9, 0x2, 0x3, 0x8, 0xa, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x2, 0x2, 0x2, 0x17a, 0x2, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x20, 0x3, 0x2, 0x2, 0x2, 0x6, 0x23, 0x3, 0x2, 0x2, 0x2, 0x8, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xc, 0x10f, 0x3, 
    0x2, 0x2, 0x2, 0xe, 0x125, 0x3, 0x2, 0x2, 0x2, 0x10, 0x137, 0x3, 0x2, 
    0x2, 0x2, 0x12, 0x13, 0x5, 0x8, 0x5, 0x2, 0x13, 0x14, 0x7, 0x2, 0x2, 
    0x3, 0x14, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x15, 0x16, 0x7, 0x3, 0x2, 0x2, 
    0x16, 0x17, 0x7, 0x2e, 0x2, 0x2, 0x17, 0x1f, 0x7, 0x15, 0x2, 0x2, 0x18, 
    0x19, 0x7, 0x4, 0x2, 0x2, 0x19, 0x1a, 0x7, 0x25, 0x2, 0x2, 0x1a, 0x1b, 
    0x5, 0x8, 0x5, 0x2, 0x1b, 0x1c, 0x7, 0x26, 0x2, 0x2, 0x1c, 0x1d, 0x7, 
    0x2, 0x2, 0x3, 0x1d, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x12, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x15, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x18, 0x3, 0x2, 0x2, 
    0x2, 0x1f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x5, 0x8, 0x5, 0x2, 
    0x21, 0x22, 0x7, 0x2, 0x2, 0x3, 0x22, 0x5, 0x3, 0x2, 0x2, 0x2, 0x23, 
    0x24, 0x5, 0x8, 0x5, 0x2, 0x24, 0x25, 0x7, 0x2, 0x2, 0x3, 0x25, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x8, 0x5, 0x1, 0x2, 0x27, 0x9c, 0x5, 
    0xa, 0x6, 0x2, 0x28, 0x29, 0x7, 0x5, 0x2, 0x2, 0x29, 0x2a, 0x7, 0x25, 
    0x2, 0x2, 0x2a, 0x2b, 0x7, 0x15, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x2b, 0x2, 
    0x2, 0x2c, 0x2d, 0x5, 0x8, 0x5, 0x2, 0x2d, 0x2e, 0x7, 0x2b, 0x2, 0x2, 
    0x2e, 0x2f, 0x7, 0x15, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x26, 0x2, 0x2, 0x30, 
    0x9c, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x5, 0x2, 0x2, 0x32, 0x33, 
    0x7, 0x25, 0x2, 0x2, 0x33, 0x34, 0x7, 0x15, 0x2, 0x2, 0x34, 0x35, 0x7, 
    0x2b, 0x2, 0x2, 0x35, 0x36, 0x5, 0x8, 0x5, 0x2, 0x36, 0x37, 0x7, 0x26, 
    0x2, 0x2, 0x37, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x5, 0x2, 
    0x2, 0x39, 0x3a, 0x7, 0x25, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x8, 0x5, 0x2, 
    0x3b, 0x3c, 0x7, 0x2b, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x15, 0x2, 0x2, 0x3d, 
    0x3e, 0x7, 0x26, 0x2, 0x2, 0x3e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 
    0x7, 0x6, 0x2, 0x2, 0x40, 0x41, 0x7, 0x25, 0x2, 0x2, 0x41, 0x42, 0x5, 
    0x8, 0x5, 0x2, 0x42, 0x43, 0x7, 0x26, 0x2, 0x2, 0x43, 0x9c, 0x3, 0x2, 
    0x2, 0x2, 0x44, 0x45, 0x7, 0x7, 0x2, 0x2, 0x45, 0x46, 0x7, 0x25, 0x2, 
    0x2, 0x46, 0x47, 0x5, 0x8, 0x5, 0x2, 0x47, 0x48, 0x7, 0x26, 0x2, 0x2, 
    0x48, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x8, 0x2, 0x2, 0x4a, 
    0x4b, 0x7, 0x25, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x8, 0x5, 0x2, 0x4c, 0x4d, 
    0x7, 0x26, 0x2, 0x2, 0x4d, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x7, 
    0x9, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x25, 0x2, 0x2, 0x50, 0x51, 0x5, 0x8, 
    0x5, 0x2, 0x51, 0x52, 0x7, 0x2b, 0x2, 0x2, 0x52, 0x53, 0x7, 0x15, 0x2, 
    0x2, 0x53, 0x54, 0x7, 0x2b, 0x2, 0x2, 0x54, 0x55, 0x7, 0x15, 0x2, 0x2, 
    0x55, 0x56, 0x7, 0x26, 0x2, 0x2, 0x56, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x58, 0x7, 0xa, 0x2, 0x2, 0x58, 0x59, 0x7, 0x25, 0x2, 0x2, 0x59, 0x5a, 
    0x7, 0x14, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x2b, 0x2, 0x2, 0x5b, 0x5e, 0x5, 
    0x8, 0x5, 0x2, 0x5c, 0x5d, 0x7, 0x2b, 0x2, 0x2, 0x5d, 0x5f, 0x7, 0x15, 
    0x2, 0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 0x3, 0x2, 0x2, 
    0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x26, 0x2, 0x2, 
    0x61, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x62, 0x63, 0x7, 0xb, 0x2, 0x2, 0x63, 
    0x64, 0x7, 0x25, 0x2, 0x2, 0x64, 0x65, 0x7, 0x14, 0x2, 0x2, 0x65, 0x66, 
    0x7, 0x2b, 0x2, 0x2, 0x66, 0x67, 0x5, 0x8, 0x5, 0x2, 0x67, 0x68, 0x7, 
    0x26, 0x2, 0x2, 0x68, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0xc, 
    0x2, 0x2, 0x6a, 0x6b, 0x7, 0x25, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x14, 0x2, 
    0x2, 0x6c, 0x6d, 0x7, 0x2b, 0x2, 0x2, 0x6d, 0x70, 0x5, 0x8, 0x5, 0x2, 
    0x6e, 0x6f, 0x7, 0x2b, 0x2, 0x2, 0x6f, 0x71, 0x7, 0x15, 0x2, 0x2, 0x70, 
    0x6e, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x73, 0x7, 0x26, 0x2, 0x2, 0x73, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x74, 0x75, 0x7, 0xd, 0x2, 0x2, 0x75, 0x76, 0x7, 0x25, 
    0x2, 0x2, 0x76, 0x77, 0x7, 0x14, 0x2, 0x2, 0x77, 0x78, 0x7, 0x2b, 0x2, 
    0x2, 0x78, 0x79, 0x5, 0x8, 0x5, 0x2, 0x79, 0x7a, 0x7, 0x26, 0x2, 0x2, 
    0x7a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0xe, 0x2, 0x2, 0x7c, 
    0x7d, 0x7, 0x25, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x14, 0x2, 0x2, 0x7e, 0x7f, 
    0x7, 0x2b, 0x2, 0x2, 0x7f, 0x82, 0x5, 0x8, 0x5, 0x2, 0x80, 0x81, 0x7, 
    0x2b, 0x2, 0x2, 0x81, 0x83, 0x7, 0x15, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 
    0x2, 0x84, 0x85, 0x7, 0x26, 0x2, 0x2, 0x85, 0x9c, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x87, 0x7, 0xf, 0x2, 0x2, 0x87, 0x88, 0x7, 0x25, 0x2, 0x2, 0x88, 
    0x89, 0x7, 0x14, 0x2, 0x2, 0x89, 0x8a, 0x7, 0x2b, 0x2, 0x2, 0x8a, 0x8b, 
    0x5, 0x8, 0x5, 0x2, 0x8b, 0x8c, 0x7, 0x26, 0x2, 0x2, 0x8c, 0x9c, 0x3, 
    0x2, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x10, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x25, 
    0x2, 0x2, 0x8f, 0x90, 0x7, 0x14, 0x2, 0x2, 0x90, 0x91, 0x7, 0x2b, 0x2, 
    0x2, 0x91, 0x92, 0x5, 0x8, 0x5, 0x2, 0x92, 0x93, 0x7, 0x26, 0x2, 0x2, 
    0x93, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0x11, 0x2, 0x2, 0x95, 
    0x96, 0x7, 0x25, 0x2, 0x2, 0x96, 0x97, 0x5, 0x8, 0x5, 0x2, 0x97, 0x98, 
    0x7, 0x2b, 0x2, 0x2, 0x98, 0x99, 0x7, 0x15, 0x2, 0x2, 0x99, 0x9a, 0x7, 
    0x26, 0x2, 0x2, 0x9a, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x26, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x28, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0x38, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x3f, 0x3, 0x2, 0x2, 0x2, 
    0x9b, 0x44, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x4e, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x57, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x9b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x74, 0x3, 
    0x2, 0x2, 0x2, 0x9b, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x86, 0x3, 0x2, 
    0x2, 0x2, 0x9b, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x9e, 0xc, 0x4, 0x2, 0x2, 
    0x9e, 0xa5, 0x5, 0x10, 0x9, 0x2, 0x9f, 0xa0, 0xc, 0x3, 0x2, 0x2, 0xa0, 
    0xa1, 0x7, 0x25, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x10, 0x9, 0x2, 0xa2, 0xa3, 
    0x7, 0x26, 0x2, 0x2, 0xa3, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x9d, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0x9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xa9, 0xb4, 0x7, 0x15, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x33, 0x2, 0x2, 0xab, 
    0xad, 0x7, 0x14, 0x2, 0x2, 0xac, 0xae, 0x5, 0xc, 0x7, 0x2, 0xad, 0xac, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb4, 0x3, 
    0x2, 0x2, 0x2, 0xaf, 0xb1, 0x7, 0x12, 0x2, 0x2, 0xb0, 0xb2, 0x5, 0xc, 
    0x7, 0x2, 0xb1, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xb2, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xa9, 0x3, 0x2, 0x2, 0x2, 
    0xb3, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xb4, 
    0xb, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x7, 0x1f, 0x2, 0x2, 0xb6, 0xb7, 
    0x5, 0xe, 0x8, 0x2, 0xb7, 0xb9, 0x7, 0x13, 0x2, 0x2, 0xb8, 0xba, 0x5, 
    0xc, 0x7, 0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 
    0x2, 0x2, 0xba, 0x110, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xbd, 0x7, 0x16, 0x2, 
    0x2, 0xbc, 0xbe, 0x5, 0xc, 0x7, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xbd, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x110, 0x3, 0x2, 0x2, 0x2, 0xbf, 
    0xc1, 0x7, 0x17, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0xc, 0x7, 0x2, 0xc1, 0xc0, 
    0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x110, 0x3, 
    0x2, 0x2, 0x2, 0xc3, 0xc5, 0x7, 0x18, 0x2, 0x2, 0xc4, 0xc6, 0x5, 0xc, 
    0x7, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2, 0x2, 
    0x2, 0xc6, 0x110, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc9, 0x7, 0x19, 0x2, 0x2, 
    0xc8, 0xca, 0x5, 0xc, 0x7, 0x2, 0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc9, 
    0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 0x110, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcd, 
    0x7, 0x1a, 0x2, 0x2, 0xcc, 0xce, 0x5, 0xc, 0x7, 0x2, 0xcd, 0xcc, 0x3, 
    0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0xcf, 0xd1, 0x7, 0x1b, 0x2, 0x2, 0xd0, 0xd2, 0x5, 0xc, 0x7, 
    0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 
    0xd2, 0x110, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd5, 0x7, 0x1c, 0x2, 0x2, 0xd4, 
    0xd6, 0x5, 0xc, 0x7, 0x2, 0xd5, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 
    0x3, 0x2, 0x2, 0x2, 0xd6, 0x110, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd9, 0x7, 
    0x1d, 0x2, 0x2, 0xd8, 0xda, 0x5, 0xc, 0x7, 0x2, 0xd9, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0x110, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xdd, 0x7, 0x1e, 0x2, 0x2, 0xdc, 0xde, 0x5, 0xc, 0x7, 0x2, 
    0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 
    0x110, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xe0, 0x7, 0x2e, 0x2, 0x2, 0xe0, 0xe2, 
    0x7, 0x15, 0x2, 0x2, 0xe1, 0xe3, 0x5, 0xc, 0x7, 0x2, 0xe2, 0xe1, 0x3, 
    0x2, 0x2, 0x2, 0xe2, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe3, 0x110, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe5, 0x7, 0x2d, 0x2, 0x2, 0xe5, 0xe7, 0x7, 0x15, 0x2, 
    0x2, 0xe6, 0xe8, 0x5, 0xc, 0x7, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0x110, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xea, 0x7, 0x31, 0x2, 0x2, 0xea, 0xec, 0x7, 0x15, 0x2, 0x2, 0xeb, 0xed, 
    0x5, 0xc, 0x7, 0x2, 0xec, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 
    0x2, 0x2, 0x2, 0xed, 0x110, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x32, 
    0x2, 0x2, 0xef, 0xf1, 0x7, 0x15, 0x2, 0x2, 0xf0, 0xf2, 0x5, 0xc, 0x7, 
    0x2, 0xf1, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x3, 0x2, 0x2, 0x2, 
    0xf2, 0x110, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x2f, 0x2, 0x2, 0xf4, 
    0xf6, 0x7, 0x15, 0x2, 0x2, 0xf5, 0xf7, 0x5, 0xc, 0x7, 0x2, 0xf6, 0xf5, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 0x110, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x30, 0x2, 0x2, 0xf9, 0xfb, 0x7, 0x15, 
    0x2, 0x2, 0xfa, 0xfc, 0x5, 0xc, 0x7, 0x2, 0xfb, 0xfa, 0x3, 0x2, 0x2, 
    0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0x110, 0x3, 0x2, 0x2, 0x2, 
    0xfd, 0xfe, 0x7, 0x22, 0x2, 0x2, 0xfe, 0x100, 0x7, 0x14, 0x2, 0x2, 0xff, 
    0x101, 0x5, 0xc, 0x7, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 
    0x3, 0x2, 0x2, 0x2, 0x101, 0x110, 0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 
    0x7, 0x23, 0x2, 0x2, 0x103, 0x105, 0x7, 0x14, 0x2, 0x2, 0x104, 0x106, 
    0x5, 0xc, 0x7, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 
    0x3, 0x2, 0x2, 0x2, 0x106, 0x110, 0x3, 0x2, 0x2, 0x2, 0x107, 0x109, 
    0x5, 0x10, 0x9, 0x2, 0x108, 0x10a, 0x5, 0xc, 0x7, 0x2, 0x109, 0x108, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x110, 
    0x3, 0x2, 0x2, 0x2, 0x10b, 0x10d, 0x7, 0x33, 0x2, 0x2, 0x10c, 0x10e, 
    0x5, 0xc, 0x7, 0x2, 0x10d, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 
    0x3, 0x2, 0x2, 0x2, 0x10e, 0x110, 0x3, 0x2, 0x2, 0x2, 0x10f, 0xb5, 0x3, 
    0x2, 0x2, 0x2, 0x10f, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x10f, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0xc3, 0x3, 0x2, 0x2, 0x2, 0x10f, 0xc7, 0x3, 0x2, 0x2, 
    0x2, 0x10f, 0xcb, 0x3, 0x2, 0x2, 0x2, 0x10f, 0xcf, 0x3, 0x2, 0x2, 0x2, 
    0x10f, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x10f, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x10f, 
    0xdb, 0x3, 0x2, 0x2, 0x2, 0x10f, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x10f, 0xe4, 
    0x3, 0x2, 0x2, 0x2, 0x10f, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x10f, 0xee, 0x3, 
    0x2, 0x2, 0x2, 0x10f, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x10f, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0x10f, 0xfd, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0x10f, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10b, 0x3, 0x2, 0x2, 
    0x2, 0x110, 0xd, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x7, 0x27, 0x2, 0x2, 
    0x112, 0x113, 0x7, 0x24, 0x2, 0x2, 0x113, 0x114, 0x7, 0x20, 0x2, 0x2, 
    0x114, 0x115, 0x7, 0x24, 0x2, 0x2, 0x115, 0x126, 0x7, 0x28, 0x2, 0x2, 
    0x116, 0x117, 0x7, 0x27, 0x2, 0x2, 0x117, 0x118, 0x7, 0x20, 0x2, 0x2, 
    0x118, 0x119, 0x7, 0x24, 0x2, 0x2, 0x119, 0x126, 0x7, 0x28, 0x2, 0x2, 
    0x11a, 0x11b, 0x7, 0x27, 0x2, 0x2, 0x11b, 0x11c, 0x7, 0x24, 0x2, 0x2, 
    0x11c, 0x11d, 0x7, 0x20, 0x2, 0x2, 0x11d, 0x126, 0x7, 0x28, 0x2, 0x2, 
    0x11e, 0x11f, 0x7, 0x27, 0x2, 0x2, 0x11f, 0x120, 0x7, 0x24, 0x2, 0x2, 
    0x120, 0x126, 0x7, 0x28, 0x2, 0x2, 0x121, 0x122, 0x7, 0x27, 0x2, 0x2, 
    0x122, 0x123, 0x7, 0x21, 0x2, 0x2, 0x123, 0x126, 0x7, 0x28, 0x2, 0x2, 
    0x124, 0x126, 0x3, 0x2, 0x2, 0x2, 0x125, 0x111, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x116, 0x3, 0x2, 0x2, 0x2, 0x125, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x125, 0x121, 0x3, 0x2, 0x2, 0x2, 
    0x125, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0xf, 0x3, 0x2, 0x2, 0x2, 0x127, 
    0x128, 0x7, 0x25, 0x2, 0x2, 0x128, 0x129, 0x7, 0x24, 0x2, 0x2, 0x129, 
    0x12a, 0x7, 0x20, 0x2, 0x2, 0x12a, 0x12b, 0x7, 0x24, 0x2, 0x2, 0x12b, 
    0x138, 0x7, 0x26, 0x2, 0x2, 0x12c, 0x12d, 0x7, 0x25, 0x2, 0x2, 0x12d, 
    0x12e, 0x7, 0x20, 0x2, 0x2, 0x12e, 0x12f, 0x7, 0x24, 0x2, 0x2, 0x12f, 
    0x138, 0x7, 0x26, 0x2, 0x2, 0x130, 0x131, 0x7, 0x25, 0x2, 0x2, 0x131, 
    0x132, 0x7, 0x24, 0x2, 0x2, 0x132, 0x133, 0x7, 0x20, 0x2, 0x2, 0x133, 
    0x138, 0x7, 0x26, 0x2, 0x2, 0x134, 0x135, 0x7, 0x25, 0x2, 0x2, 0x135, 
    0x136, 0x7, 0x24, 0x2, 0x2, 0x136, 0x138, 0x7, 0x26, 0x2, 0x2, 0x137, 
    0x127, 0x3, 0x2, 0x2, 0x2, 0x137, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x137, 
    0x130, 0x3, 0x2, 0x2, 0x2, 0x137, 0x134, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x23, 0x1e, 0x5e, 0x70, 0x82, 0x9b, 0xa4, 
    0xa6, 0xad, 0xb1, 0xb3, 0xb9, 0xbd, 0xc1, 0xc5, 0xc9, 0xcd, 0xd1, 0xd5, 
    0xd9, 0xdd, 0xe2, 0xe7, 0xec, 0xf1, 0xf6, 0xfb, 0x100, 0x105, 0x109, 
    0x10d, 0x10f, 0x125, 0x137, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

UserAgentTreeWalkerParser::Initializer UserAgentTreeWalkerParser::_init;
