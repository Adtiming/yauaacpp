
// Generated from UserAgent.g4 by ANTLR 4.7.2


#include "UserAgentListener.h"
#include "UserAgentVisitor.h"

#include "UserAgentParser.h"


using namespace antlrcpp;
using namespace ycpp;
using namespace antlr4;

UserAgentParser::UserAgentParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

UserAgentParser::~UserAgentParser() {
  delete _interpreter;
}

std::string UserAgentParser::getGrammarFileName() const {
  return "UserAgent.g4";
}

const std::vector<std::string>& UserAgentParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& UserAgentParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- UserAgentContext ------------------------------------------------------------------

UserAgentParser::UserAgentContext::UserAgentContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::SEMICOLON() {
  return getTokens(UserAgentParser::SEMICOLON);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::SEMICOLON(size_t i) {
  return getToken(UserAgentParser::SEMICOLON, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::COMMA() {
  return getTokens(UserAgentParser::COMMA);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::COMMA(size_t i) {
  return getToken(UserAgentParser::COMMA, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::MINUS() {
  return getTokens(UserAgentParser::MINUS);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::MINUS(size_t i) {
  return getToken(UserAgentParser::MINUS, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::PLUS() {
  return getTokens(UserAgentParser::PLUS);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::PLUS(size_t i) {
  return getToken(UserAgentParser::PLUS, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::QUOTE4() {
  return getTokens(UserAgentParser::QUOTE4);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::QUOTE4(size_t i) {
  return getToken(UserAgentParser::QUOTE4, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::QUOTE2() {
  return getTokens(UserAgentParser::QUOTE2);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::QUOTE2(size_t i) {
  return getToken(UserAgentParser::QUOTE2, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::EQUALS() {
  return getTokens(UserAgentParser::EQUALS);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::EQUALS(size_t i) {
  return getToken(UserAgentParser::EQUALS, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::BRACEOPEN() {
  return getTokens(UserAgentParser::BRACEOPEN);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::BRACEOPEN(size_t i) {
  return getToken(UserAgentParser::BRACEOPEN, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::BLOCKOPEN() {
  return getTokens(UserAgentParser::BLOCKOPEN);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::BLOCKOPEN(size_t i) {
  return getToken(UserAgentParser::BLOCKOPEN, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::BRACECLOSE() {
  return getTokens(UserAgentParser::BRACECLOSE);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::BRACECLOSE(size_t i) {
  return getToken(UserAgentParser::BRACECLOSE, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::UserAgentContext::BLOCKCLOSE() {
  return getTokens(UserAgentParser::BLOCKCLOSE);
}

tree::TerminalNode* UserAgentParser::UserAgentContext::BLOCKCLOSE(size_t i) {
  return getToken(UserAgentParser::BLOCKCLOSE, i);
}

std::vector<UserAgentParser::ProductContext *> UserAgentParser::UserAgentContext::product() {
  return getRuleContexts<UserAgentParser::ProductContext>();
}

UserAgentParser::ProductContext* UserAgentParser::UserAgentContext::product(size_t i) {
  return getRuleContext<UserAgentParser::ProductContext>(i);
}

std::vector<UserAgentParser::RootElementsContext *> UserAgentParser::UserAgentContext::rootElements() {
  return getRuleContexts<UserAgentParser::RootElementsContext>();
}

UserAgentParser::RootElementsContext* UserAgentParser::UserAgentContext::rootElements(size_t i) {
  return getRuleContext<UserAgentParser::RootElementsContext>(i);
}


size_t UserAgentParser::UserAgentContext::getRuleIndex() const {
  return UserAgentParser::RuleUserAgent;
}

void UserAgentParser::UserAgentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUserAgent(this);
}

void UserAgentParser::UserAgentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUserAgent(this);
}


antlrcpp::Any UserAgentParser::UserAgentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitUserAgent(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::UserAgentContext* UserAgentParser::userAgent() {
  UserAgentContext *_localctx = _tracker.createInstance<UserAgentContext>(_ctx, getState());
  enterRule(_localctx, 0, UserAgentParser::RuleUserAgent);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(71);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(68);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << UserAgentParser::T__0)
          | (1ULL << UserAgentParser::QUOTE2)
          | (1ULL << UserAgentParser::QUOTE4)
          | (1ULL << UserAgentParser::BRACEOPEN)
          | (1ULL << UserAgentParser::BLOCKOPEN)
          | (1ULL << UserAgentParser::SEMICOLON)
          | (1ULL << UserAgentParser::COMMA)
          | (1ULL << UserAgentParser::EQUALS)
          | (1ULL << UserAgentParser::MINUS)
          | (1ULL << UserAgentParser::PLUS))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        } 
      }
      setState(73);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
    setState(83);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(75);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          setState(74);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << UserAgentParser::SEMICOLON)
            | (1ULL << UserAgentParser::COMMA)
            | (1ULL << UserAgentParser::MINUS))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        }
        setState(79);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          setState(77);
          product();
          break;
        }

        case 2: {
          setState(78);
          rootElements();
          break;
        }

        } 
      }
      setState(85);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
    setState(89);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << UserAgentParser::T__0)
      | (1ULL << UserAgentParser::QUOTE2)
      | (1ULL << UserAgentParser::QUOTE4)
      | (1ULL << UserAgentParser::BRACECLOSE)
      | (1ULL << UserAgentParser::BLOCKCLOSE)
      | (1ULL << UserAgentParser::SEMICOLON)
      | (1ULL << UserAgentParser::COMMA)
      | (1ULL << UserAgentParser::EQUALS)
      | (1ULL << UserAgentParser::MINUS)
      | (1ULL << UserAgentParser::PLUS))) != 0)) {
      setState(86);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << UserAgentParser::T__0)
        | (1ULL << UserAgentParser::QUOTE2)
        | (1ULL << UserAgentParser::QUOTE4)
        | (1ULL << UserAgentParser::BRACECLOSE)
        | (1ULL << UserAgentParser::BLOCKCLOSE)
        | (1ULL << UserAgentParser::SEMICOLON)
        | (1ULL << UserAgentParser::COMMA)
        | (1ULL << UserAgentParser::EQUALS)
        | (1ULL << UserAgentParser::MINUS)
        | (1ULL << UserAgentParser::PLUS))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(91);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RootElementsContext ------------------------------------------------------------------

UserAgentParser::RootElementsContext::RootElementsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::KeyValueContext* UserAgentParser::RootElementsContext::keyValue() {
  return getRuleContext<UserAgentParser::KeyValueContext>(0);
}

UserAgentParser::SiteUrlContext* UserAgentParser::RootElementsContext::siteUrl() {
  return getRuleContext<UserAgentParser::SiteUrlContext>(0);
}

UserAgentParser::EmailAddressContext* UserAgentParser::RootElementsContext::emailAddress() {
  return getRuleContext<UserAgentParser::EmailAddressContext>(0);
}

UserAgentParser::UuIdContext* UserAgentParser::RootElementsContext::uuId() {
  return getRuleContext<UserAgentParser::UuIdContext>(0);
}

UserAgentParser::RootTextContext* UserAgentParser::RootElementsContext::rootText() {
  return getRuleContext<UserAgentParser::RootTextContext>(0);
}


size_t UserAgentParser::RootElementsContext::getRuleIndex() const {
  return UserAgentParser::RuleRootElements;
}

void UserAgentParser::RootElementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRootElements(this);
}

void UserAgentParser::RootElementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRootElements(this);
}


antlrcpp::Any UserAgentParser::RootElementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitRootElements(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::RootElementsContext* UserAgentParser::rootElements() {
  RootElementsContext *_localctx = _tracker.createInstance<RootElementsContext>(_ctx, getState());
  enterRule(_localctx, 2, UserAgentParser::RuleRootElements);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(97);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(92);
      keyValue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(93);
      siteUrl();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(94);
      emailAddress();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(95);
      uuId();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(96);
      rootText();
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

//----------------- RootTextContext ------------------------------------------------------------------

UserAgentParser::RootTextContext::RootTextContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::RootTextContext::VERSION() {
  return getToken(UserAgentParser::VERSION, 0);
}

std::vector<tree::TerminalNode *> UserAgentParser::RootTextContext::WORD() {
  return getTokens(UserAgentParser::WORD);
}

tree::TerminalNode* UserAgentParser::RootTextContext::WORD(size_t i) {
  return getToken(UserAgentParser::WORD, i);
}

tree::TerminalNode* UserAgentParser::RootTextContext::GIBBERISH() {
  return getToken(UserAgentParser::GIBBERISH, 0);
}

tree::TerminalNode* UserAgentParser::RootTextContext::MINUS() {
  return getToken(UserAgentParser::MINUS, 0);
}


size_t UserAgentParser::RootTextContext::getRuleIndex() const {
  return UserAgentParser::RuleRootText;
}

void UserAgentParser::RootTextContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRootText(this);
}

void UserAgentParser::RootTextContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRootText(this);
}


antlrcpp::Any UserAgentParser::RootTextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitRootText(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::RootTextContext* UserAgentParser::rootText() {
  RootTextContext *_localctx = _tracker.createInstance<RootTextContext>(_ctx, getState());
  enterRule(_localctx, 4, UserAgentParser::RuleRootText);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(107);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::VERSION: {
        enterOuterAlt(_localctx, 1);
        setState(99);
        match(UserAgentParser::VERSION);
        break;
      }

      case UserAgentParser::WORD: {
        enterOuterAlt(_localctx, 2);
        setState(101); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(100);
                  match(UserAgentParser::WORD);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(103); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case UserAgentParser::GIBBERISH: {
        enterOuterAlt(_localctx, 3);
        setState(105);
        match(UserAgentParser::GIBBERISH);
        break;
      }

      case UserAgentParser::MINUS: {
        enterOuterAlt(_localctx, 4);
        setState(106);
        match(UserAgentParser::MINUS);
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

//----------------- ProductContext ------------------------------------------------------------------

UserAgentParser::ProductContext::ProductContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::ProductNameContext* UserAgentParser::ProductContext::productName() {
  return getRuleContext<UserAgentParser::ProductNameContext>(0);
}

std::vector<UserAgentParser::ProductVersionContext *> UserAgentParser::ProductContext::productVersion() {
  return getRuleContexts<UserAgentParser::ProductVersionContext>();
}

UserAgentParser::ProductVersionContext* UserAgentParser::ProductContext::productVersion(size_t i) {
  return getRuleContext<UserAgentParser::ProductVersionContext>(i);
}

std::vector<UserAgentParser::CommentBlockContext *> UserAgentParser::ProductContext::commentBlock() {
  return getRuleContexts<UserAgentParser::CommentBlockContext>();
}

UserAgentParser::CommentBlockContext* UserAgentParser::ProductContext::commentBlock(size_t i) {
  return getRuleContext<UserAgentParser::CommentBlockContext>(i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductContext::SLASH() {
  return getTokens(UserAgentParser::SLASH);
}

tree::TerminalNode* UserAgentParser::ProductContext::SLASH(size_t i) {
  return getToken(UserAgentParser::SLASH, i);
}

tree::TerminalNode* UserAgentParser::ProductContext::EOF() {
  return getToken(UserAgentParser::EOF, 0);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductContext::MINUS() {
  return getTokens(UserAgentParser::MINUS);
}

tree::TerminalNode* UserAgentParser::ProductContext::MINUS(size_t i) {
  return getToken(UserAgentParser::MINUS, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductContext::ATSIGN() {
  return getTokens(UserAgentParser::ATSIGN);
}

tree::TerminalNode* UserAgentParser::ProductContext::ATSIGN(size_t i) {
  return getToken(UserAgentParser::ATSIGN, i);
}

std::vector<UserAgentParser::ProductVersionWithCommasContext *> UserAgentParser::ProductContext::productVersionWithCommas() {
  return getRuleContexts<UserAgentParser::ProductVersionWithCommasContext>();
}

UserAgentParser::ProductVersionWithCommasContext* UserAgentParser::ProductContext::productVersionWithCommas(size_t i) {
  return getRuleContext<UserAgentParser::ProductVersionWithCommasContext>(i);
}

std::vector<UserAgentParser::ProductVersionSingleWordContext *> UserAgentParser::ProductContext::productVersionSingleWord() {
  return getRuleContexts<UserAgentParser::ProductVersionSingleWordContext>();
}

UserAgentParser::ProductVersionSingleWordContext* UserAgentParser::ProductContext::productVersionSingleWord(size_t i) {
  return getRuleContext<UserAgentParser::ProductVersionSingleWordContext>(i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductContext::COLON() {
  return getTokens(UserAgentParser::COLON);
}

tree::TerminalNode* UserAgentParser::ProductContext::COLON(size_t i) {
  return getToken(UserAgentParser::COLON, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductContext::EQUALS() {
  return getTokens(UserAgentParser::EQUALS);
}

tree::TerminalNode* UserAgentParser::ProductContext::EQUALS(size_t i) {
  return getToken(UserAgentParser::EQUALS, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductContext::COMMA() {
  return getTokens(UserAgentParser::COMMA);
}

tree::TerminalNode* UserAgentParser::ProductContext::COMMA(size_t i) {
  return getToken(UserAgentParser::COMMA, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductContext::SEMICOLON() {
  return getTokens(UserAgentParser::SEMICOLON);
}

tree::TerminalNode* UserAgentParser::ProductContext::SEMICOLON(size_t i) {
  return getToken(UserAgentParser::SEMICOLON, i);
}

std::vector<UserAgentParser::ProductVersionWordsContext *> UserAgentParser::ProductContext::productVersionWords() {
  return getRuleContexts<UserAgentParser::ProductVersionWordsContext>();
}

UserAgentParser::ProductVersionWordsContext* UserAgentParser::ProductContext::productVersionWords(size_t i) {
  return getRuleContext<UserAgentParser::ProductVersionWordsContext>(i);
}


size_t UserAgentParser::ProductContext::getRuleIndex() const {
  return UserAgentParser::RuleProduct;
}

void UserAgentParser::ProductContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProduct(this);
}

void UserAgentParser::ProductContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProduct(this);
}


antlrcpp::Any UserAgentParser::ProductContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProduct(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductContext* UserAgentParser::product() {
  ProductContext *_localctx = _tracker.createInstance<ProductContext>(_ctx, getState());
  enterRule(_localctx, 6, UserAgentParser::RuleProduct);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(327);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(109);
      productName();
      setState(111); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(110);
                productVersion();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(113); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(139);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(116);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::COLON) {
            setState(115);
            match(UserAgentParser::COLON);
          }
          setState(125);
          _errHandler->sync(this);
          switch (_input->LA(1)) {
            case UserAgentParser::SLASH: {
              setState(119); 
              _errHandler->sync(this);
              _la = _input->LA(1);
              do {
                setState(118);
                match(UserAgentParser::SLASH);
                setState(121); 
                _errHandler->sync(this);
                _la = _input->LA(1);
              } while (_la == UserAgentParser::SLASH);
              break;
            }

            case UserAgentParser::MINUS: {
              setState(123);
              match(UserAgentParser::MINUS);
              break;
            }

            case UserAgentParser::ATSIGN: {
              setState(124);
              match(UserAgentParser::ATSIGN);
              break;
            }

          default:
            throw NoViableAltException(this);
          }
          setState(128);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::EQUALS) {
            setState(127);
            match(UserAgentParser::EQUALS);
          }
          setState(132);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
          case 1: {
            setState(130);
            productVersionWithCommas();
            break;
          }

          case 2: {
            setState(131);
            productVersionSingleWord();
            break;
          }

          }
          setState(135);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
          case 1: {
            setState(134);
            match(UserAgentParser::COMMA);
            break;
          }

          } 
        }
        setState(141);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
      }
      setState(171);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(143);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::SLASH

          || _la == UserAgentParser::ATSIGN) {
            setState(142);
            _la = _input->LA(1);
            if (!(_la == UserAgentParser::SLASH

            || _la == UserAgentParser::ATSIGN)) {
            _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
          }
          setState(146);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::SEMICOLON

          || _la == UserAgentParser::MINUS) {
            setState(145);
            _la = _input->LA(1);
            if (!(_la == UserAgentParser::SEMICOLON

            || _la == UserAgentParser::MINUS)) {
            _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
          }
          setState(148);
          commentBlock();
          setState(166);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(150); 
              _errHandler->sync(this);
              _la = _input->LA(1);
              do {
                setState(149);
                _la = _input->LA(1);
                if (!(_la == UserAgentParser::SLASH

                || _la == UserAgentParser::ATSIGN)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                setState(152); 
                _errHandler->sync(this);
                _la = _input->LA(1);
              } while (_la == UserAgentParser::SLASH

              || _la == UserAgentParser::ATSIGN);
              setState(155);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == UserAgentParser::EQUALS) {
                setState(154);
                match(UserAgentParser::EQUALS);
              }
              setState(159);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
              case 1: {
                setState(157);
                productVersionWithCommas();
                break;
              }

              case 2: {
                setState(158);
                productVersionSingleWord();
                break;
              }

              }
              setState(162);
              _errHandler->sync(this);

              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
              case 1: {
                setState(161);
                match(UserAgentParser::COMMA);
                break;
              }

              } 
            }
            setState(168);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
          } 
        }
        setState(173);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      }
      setState(176);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentParser::SLASH) {
        setState(174);
        match(UserAgentParser::SLASH);
        setState(175);
        match(UserAgentParser::EOF);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(178);
      productName();
      setState(206); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(180);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::SLASH

                || _la == UserAgentParser::ATSIGN) {
                  setState(179);
                  _la = _input->LA(1);
                  if (!(_la == UserAgentParser::SLASH

                  || _la == UserAgentParser::ATSIGN)) {
                  _errHandler->recoverInline(this);
                  }
                  else {
                    _errHandler->reportMatch(this);
                    consume();
                  }
                }
                setState(183);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::SEMICOLON

                || _la == UserAgentParser::MINUS) {
                  setState(182);
                  _la = _input->LA(1);
                  if (!(_la == UserAgentParser::SEMICOLON

                  || _la == UserAgentParser::MINUS)) {
                  _errHandler->recoverInline(this);
                  }
                  else {
                    _errHandler->reportMatch(this);
                    consume();
                  }
                }
                setState(185);
                commentBlock();
                setState(203);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                  if (alt == 1) {
                    setState(187); 
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    do {
                      setState(186);
                      _la = _input->LA(1);
                      if (!(_la == UserAgentParser::SLASH

                      || _la == UserAgentParser::ATSIGN)) {
                      _errHandler->recoverInline(this);
                      }
                      else {
                        _errHandler->reportMatch(this);
                        consume();
                      }
                      setState(189); 
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    } while (_la == UserAgentParser::SLASH

                    || _la == UserAgentParser::ATSIGN);
                    setState(192);
                    _errHandler->sync(this);

                    _la = _input->LA(1);
                    if (_la == UserAgentParser::EQUALS) {
                      setState(191);
                      match(UserAgentParser::EQUALS);
                    }
                    setState(196);
                    _errHandler->sync(this);
                    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
                    case 1: {
                      setState(194);
                      productVersionWithCommas();
                      break;
                    }

                    case 2: {
                      setState(195);
                      productVersionSingleWord();
                      break;
                    }

                    }
                    setState(199);
                    _errHandler->sync(this);

                    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
                    case 1: {
                      setState(198);
                      match(UserAgentParser::COMMA);
                      break;
                    }

                    } 
                  }
                  setState(205);
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(208); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(212);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentParser::SLASH) {
        setState(210);
        match(UserAgentParser::SLASH);
        setState(211);
        match(UserAgentParser::EOF);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(214);
      productName();
      setState(252); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(216);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::COLON) {
                  setState(215);
                  match(UserAgentParser::COLON);
                }
                setState(225);
                _errHandler->sync(this);
                switch (_input->LA(1)) {
                  case UserAgentParser::SLASH: {
                    setState(219); 
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    do {
                      setState(218);
                      match(UserAgentParser::SLASH);
                      setState(221); 
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    } while (_la == UserAgentParser::SLASH);
                    break;
                  }

                  case UserAgentParser::MINUS: {
                    setState(223);
                    match(UserAgentParser::MINUS);
                    break;
                  }

                  case UserAgentParser::ATSIGN: {
                    setState(224);
                    match(UserAgentParser::ATSIGN);
                    break;
                  }

                default:
                  throw NoViableAltException(this);
                }
                setState(227);
                productVersionWords();
                setState(240);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                  if (alt == 1) {
                    setState(231);
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    while (_la == UserAgentParser::SLASH

                    || _la == UserAgentParser::ATSIGN) {
                      setState(228);
                      _la = _input->LA(1);
                      if (!(_la == UserAgentParser::SLASH

                      || _la == UserAgentParser::ATSIGN)) {
                      _errHandler->recoverInline(this);
                      }
                      else {
                        _errHandler->reportMatch(this);
                        consume();
                      }
                      setState(233);
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    }
                    setState(234);
                    productVersionWithCommas();
                    setState(236);
                    _errHandler->sync(this);

                    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
                    case 1: {
                      setState(235);
                      match(UserAgentParser::COMMA);
                      break;
                    }

                    } 
                  }
                  setState(242);
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
                }
                setState(244);
                _errHandler->sync(this);

                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
                case 1: {
                  setState(243);
                  _la = _input->LA(1);
                  if (!(_la == UserAgentParser::SLASH

                  || _la == UserAgentParser::ATSIGN)) {
                  _errHandler->recoverInline(this);
                  }
                  else {
                    _errHandler->reportMatch(this);
                    consume();
                  }
                  break;
                }

                }
                setState(247);
                _errHandler->sync(this);

                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
                case 1: {
                  setState(246);
                  _la = _input->LA(1);
                  if (!(_la == UserAgentParser::SEMICOLON

                  || _la == UserAgentParser::MINUS)) {
                  _errHandler->recoverInline(this);
                  }
                  else {
                    _errHandler->reportMatch(this);
                    consume();
                  }
                  break;
                }

                }
                setState(250);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::BRACEOPEN

                || _la == UserAgentParser::BLOCKOPEN) {
                  setState(249);
                  commentBlock();
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(254); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(258);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentParser::SLASH) {
        setState(256);
        match(UserAgentParser::SLASH);
        setState(257);
        match(UserAgentParser::EOF);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(260);
      productName();
      setState(283); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(262);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::COLON) {
                  setState(261);
                  match(UserAgentParser::COLON);
                }
                setState(271);
                _errHandler->sync(this);
                switch (_input->LA(1)) {
                  case UserAgentParser::SLASH: {
                    setState(265); 
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    do {
                      setState(264);
                      match(UserAgentParser::SLASH);
                      setState(267); 
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    } while (_la == UserAgentParser::SLASH);
                    break;
                  }

                  case UserAgentParser::MINUS: {
                    setState(269);
                    match(UserAgentParser::MINUS);
                    break;
                  }

                  case UserAgentParser::ATSIGN: {
                    setState(270);
                    match(UserAgentParser::ATSIGN);
                    break;
                  }

                default:
                  throw NoViableAltException(this);
                }
                setState(274);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::EQUALS) {
                  setState(273);
                  match(UserAgentParser::EQUALS);
                }
                setState(278);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
                case 1: {
                  setState(276);
                  productVersionWithCommas();
                  break;
                }

                case 2: {
                  setState(277);
                  productVersionSingleWord();
                  break;
                }

                }
                setState(281);
                _errHandler->sync(this);

                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
                case 1: {
                  setState(280);
                  match(UserAgentParser::COMMA);
                  break;
                }

                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(285); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(316);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(288);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::SLASH

          || _la == UserAgentParser::ATSIGN) {
            setState(287);
            _la = _input->LA(1);
            if (!(_la == UserAgentParser::SLASH

            || _la == UserAgentParser::ATSIGN)) {
            _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
          }
          setState(291);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::SEMICOLON

          || _la == UserAgentParser::MINUS) {
            setState(290);
            _la = _input->LA(1);
            if (!(_la == UserAgentParser::SEMICOLON

            || _la == UserAgentParser::MINUS)) {
            _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
          }
          setState(293);
          commentBlock();
          setState(311);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(295); 
              _errHandler->sync(this);
              _la = _input->LA(1);
              do {
                setState(294);
                _la = _input->LA(1);
                if (!(_la == UserAgentParser::SLASH

                || _la == UserAgentParser::ATSIGN)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                setState(297); 
                _errHandler->sync(this);
                _la = _input->LA(1);
              } while (_la == UserAgentParser::SLASH

              || _la == UserAgentParser::ATSIGN);
              setState(300);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == UserAgentParser::EQUALS) {
                setState(299);
                match(UserAgentParser::EQUALS);
              }
              setState(304);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
              case 1: {
                setState(302);
                productVersionWithCommas();
                break;
              }

              case 2: {
                setState(303);
                productVersionSingleWord();
                break;
              }

              }
              setState(307);
              _errHandler->sync(this);

              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
              case 1: {
                setState(306);
                match(UserAgentParser::COMMA);
                break;
              }

              } 
            }
            setState(313);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
          } 
        }
        setState(318);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx);
      }
      setState(321);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentParser::SLASH) {
        setState(319);
        match(UserAgentParser::SLASH);
        setState(320);
        match(UserAgentParser::EOF);
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(323);
      productName();

      setState(324);
      match(UserAgentParser::SLASH);
      setState(325);
      match(UserAgentParser::EOF);
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

//----------------- CommentProductContext ------------------------------------------------------------------

UserAgentParser::CommentProductContext::CommentProductContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::ProductNameContext* UserAgentParser::CommentProductContext::productName() {
  return getRuleContext<UserAgentParser::ProductNameContext>(0);
}

std::vector<UserAgentParser::ProductVersionWithCommasContext *> UserAgentParser::CommentProductContext::productVersionWithCommas() {
  return getRuleContexts<UserAgentParser::ProductVersionWithCommasContext>();
}

UserAgentParser::ProductVersionWithCommasContext* UserAgentParser::CommentProductContext::productVersionWithCommas(size_t i) {
  return getRuleContext<UserAgentParser::ProductVersionWithCommasContext>(i);
}

std::vector<UserAgentParser::CommentBlockContext *> UserAgentParser::CommentProductContext::commentBlock() {
  return getRuleContexts<UserAgentParser::CommentBlockContext>();
}

UserAgentParser::CommentBlockContext* UserAgentParser::CommentProductContext::commentBlock(size_t i) {
  return getRuleContext<UserAgentParser::CommentBlockContext>(i);
}

std::vector<UserAgentParser::ProductVersionSingleWordContext *> UserAgentParser::CommentProductContext::productVersionSingleWord() {
  return getRuleContexts<UserAgentParser::ProductVersionSingleWordContext>();
}

UserAgentParser::ProductVersionSingleWordContext* UserAgentParser::CommentProductContext::productVersionSingleWord(size_t i) {
  return getRuleContext<UserAgentParser::ProductVersionSingleWordContext>(i);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentProductContext::EQUALS() {
  return getTokens(UserAgentParser::EQUALS);
}

tree::TerminalNode* UserAgentParser::CommentProductContext::EQUALS(size_t i) {
  return getToken(UserAgentParser::EQUALS, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentProductContext::COMMA() {
  return getTokens(UserAgentParser::COMMA);
}

tree::TerminalNode* UserAgentParser::CommentProductContext::COMMA(size_t i) {
  return getToken(UserAgentParser::COMMA, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentProductContext::MINUS() {
  return getTokens(UserAgentParser::MINUS);
}

tree::TerminalNode* UserAgentParser::CommentProductContext::MINUS(size_t i) {
  return getToken(UserAgentParser::MINUS, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentProductContext::SLASH() {
  return getTokens(UserAgentParser::SLASH);
}

tree::TerminalNode* UserAgentParser::CommentProductContext::SLASH(size_t i) {
  return getToken(UserAgentParser::SLASH, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentProductContext::ATSIGN() {
  return getTokens(UserAgentParser::ATSIGN);
}

tree::TerminalNode* UserAgentParser::CommentProductContext::ATSIGN(size_t i) {
  return getToken(UserAgentParser::ATSIGN, i);
}

std::vector<UserAgentParser::ProductVersionWordsContext *> UserAgentParser::CommentProductContext::productVersionWords() {
  return getRuleContexts<UserAgentParser::ProductVersionWordsContext>();
}

UserAgentParser::ProductVersionWordsContext* UserAgentParser::CommentProductContext::productVersionWords(size_t i) {
  return getRuleContext<UserAgentParser::ProductVersionWordsContext>(i);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentProductContext::COLON() {
  return getTokens(UserAgentParser::COLON);
}

tree::TerminalNode* UserAgentParser::CommentProductContext::COLON(size_t i) {
  return getToken(UserAgentParser::COLON, i);
}


size_t UserAgentParser::CommentProductContext::getRuleIndex() const {
  return UserAgentParser::RuleCommentProduct;
}

void UserAgentParser::CommentProductContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommentProduct(this);
}

void UserAgentParser::CommentProductContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommentProduct(this);
}


antlrcpp::Any UserAgentParser::CommentProductContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitCommentProduct(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::CommentProductContext* UserAgentParser::commentProduct() {
  CommentProductContext *_localctx = _tracker.createInstance<CommentProductContext>(_ctx, getState());
  enterRule(_localctx, 8, UserAgentParser::RuleCommentProduct);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(531);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 110, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(329);
      productName();
      setState(331); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(330);
                productVersionWithCommas();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(333); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(352);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(336); 
          _errHandler->sync(this);
          _la = _input->LA(1);
          do {
            setState(335);
            _la = _input->LA(1);
            if (!(_la == UserAgentParser::SLASH

            || _la == UserAgentParser::ATSIGN)) {
            _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(338); 
            _errHandler->sync(this);
            _la = _input->LA(1);
          } while (_la == UserAgentParser::SLASH

          || _la == UserAgentParser::ATSIGN);
          setState(341);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::EQUALS) {
            setState(340);
            match(UserAgentParser::EQUALS);
          }
          setState(345);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
          case 1: {
            setState(343);
            productVersionWithCommas();
            break;
          }

          case 2: {
            setState(344);
            productVersionSingleWord();
            break;
          }

          }
          setState(348);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
          case 1: {
            setState(347);
            match(UserAgentParser::COMMA);
            break;
          }

          } 
        }
        setState(354);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      }
      setState(384);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(356);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::SLASH

          || _la == UserAgentParser::ATSIGN) {
            setState(355);
            _la = _input->LA(1);
            if (!(_la == UserAgentParser::SLASH

            || _la == UserAgentParser::ATSIGN)) {
            _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
          }
          setState(359);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::MINUS) {
            setState(358);
            match(UserAgentParser::MINUS);
          }
          setState(361);
          commentBlock();
          setState(379);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(363); 
              _errHandler->sync(this);
              _la = _input->LA(1);
              do {
                setState(362);
                _la = _input->LA(1);
                if (!(_la == UserAgentParser::SLASH

                || _la == UserAgentParser::ATSIGN)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                setState(365); 
                _errHandler->sync(this);
                _la = _input->LA(1);
              } while (_la == UserAgentParser::SLASH

              || _la == UserAgentParser::ATSIGN);
              setState(368);
              _errHandler->sync(this);

              _la = _input->LA(1);
              if (_la == UserAgentParser::EQUALS) {
                setState(367);
                match(UserAgentParser::EQUALS);
              }
              setState(372);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
              case 1: {
                setState(370);
                productVersionWithCommas();
                break;
              }

              case 2: {
                setState(371);
                productVersionSingleWord();
                break;
              }

              }
              setState(375);
              _errHandler->sync(this);

              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
              case 1: {
                setState(374);
                match(UserAgentParser::COMMA);
                break;
              }

              } 
            }
            setState(381);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
          } 
        }
        setState(386);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 75, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(387);
      productName();
      setState(415); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(389);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::SLASH

                || _la == UserAgentParser::ATSIGN) {
                  setState(388);
                  _la = _input->LA(1);
                  if (!(_la == UserAgentParser::SLASH

                  || _la == UserAgentParser::ATSIGN)) {
                  _errHandler->recoverInline(this);
                  }
                  else {
                    _errHandler->reportMatch(this);
                    consume();
                  }
                }
                setState(392);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::MINUS) {
                  setState(391);
                  match(UserAgentParser::MINUS);
                }
                setState(394);
                commentBlock();
                setState(412);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                  if (alt == 1) {
                    setState(396); 
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    do {
                      setState(395);
                      _la = _input->LA(1);
                      if (!(_la == UserAgentParser::SLASH

                      || _la == UserAgentParser::ATSIGN)) {
                      _errHandler->recoverInline(this);
                      }
                      else {
                        _errHandler->reportMatch(this);
                        consume();
                      }
                      setState(398); 
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    } while (_la == UserAgentParser::SLASH

                    || _la == UserAgentParser::ATSIGN);
                    setState(401);
                    _errHandler->sync(this);

                    _la = _input->LA(1);
                    if (_la == UserAgentParser::EQUALS) {
                      setState(400);
                      match(UserAgentParser::EQUALS);
                    }
                    setState(405);
                    _errHandler->sync(this);
                    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
                    case 1: {
                      setState(403);
                      productVersionWithCommas();
                      break;
                    }

                    case 2: {
                      setState(404);
                      productVersionSingleWord();
                      break;
                    }

                    }
                    setState(408);
                    _errHandler->sync(this);

                    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx)) {
                    case 1: {
                      setState(407);
                      match(UserAgentParser::COMMA);
                      break;
                    }

                    } 
                  }
                  setState(414);
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(417); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(419);
      productName();
      setState(448); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(421);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::COLON) {
                  setState(420);
                  match(UserAgentParser::COLON);
                }
                setState(430);
                _errHandler->sync(this);
                switch (_input->LA(1)) {
                  case UserAgentParser::SLASH: {
                    setState(424); 
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    do {
                      setState(423);
                      match(UserAgentParser::SLASH);
                      setState(426); 
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    } while (_la == UserAgentParser::SLASH);
                    break;
                  }

                  case UserAgentParser::MINUS: {
                    setState(428);
                    match(UserAgentParser::MINUS);
                    break;
                  }

                  case UserAgentParser::ATSIGN: {
                    setState(429);
                    match(UserAgentParser::ATSIGN);
                    break;
                  }

                default:
                  throw NoViableAltException(this);
                }
                setState(432);
                productVersionWords();
                setState(445);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                  if (alt == 1) {
                    setState(436);
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    while (_la == UserAgentParser::SLASH

                    || _la == UserAgentParser::ATSIGN) {
                      setState(433);
                      _la = _input->LA(1);
                      if (!(_la == UserAgentParser::SLASH

                      || _la == UserAgentParser::ATSIGN)) {
                      _errHandler->recoverInline(this);
                      }
                      else {
                        _errHandler->reportMatch(this);
                        consume();
                      }
                      setState(438);
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    }
                    setState(439);
                    productVersionWithCommas();
                    setState(441);
                    _errHandler->sync(this);

                    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 88, _ctx)) {
                    case 1: {
                      setState(440);
                      match(UserAgentParser::COMMA);
                      break;
                    }

                    } 
                  }
                  setState(447);
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 89, _ctx);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(450); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(478);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(453);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::MINUS) {
            setState(452);
            match(UserAgentParser::MINUS);
          }
          setState(455);
          commentBlock();
          setState(473);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == UserAgentParser::SLASH

          || _la == UserAgentParser::ATSIGN) {
            setState(457); 
            _errHandler->sync(this);
            _la = _input->LA(1);
            do {
              setState(456);
              _la = _input->LA(1);
              if (!(_la == UserAgentParser::SLASH

              || _la == UserAgentParser::ATSIGN)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              setState(459); 
              _errHandler->sync(this);
              _la = _input->LA(1);
            } while (_la == UserAgentParser::SLASH

            || _la == UserAgentParser::ATSIGN);
            setState(462);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == UserAgentParser::EQUALS) {
              setState(461);
              match(UserAgentParser::EQUALS);
            }
            setState(466);
            _errHandler->sync(this);
            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
            case 1: {
              setState(464);
              productVersionWithCommas();
              break;
            }

            case 2: {
              setState(465);
              productVersionSingleWord();
              break;
            }

            }
            setState(469);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 95, _ctx)) {
            case 1: {
              setState(468);
              match(UserAgentParser::COMMA);
              break;
            }

            }
            setState(475);
            _errHandler->sync(this);
            _la = _input->LA(1);
          } 
        }
        setState(480);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 97, _ctx);
      }
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(481);
      productName();
      setState(498); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(489);
                _errHandler->sync(this);
                switch (_input->LA(1)) {
                  case UserAgentParser::SLASH: {
                    setState(483); 
                    _errHandler->sync(this);
                    _la = _input->LA(1);
                    do {
                      setState(482);
                      match(UserAgentParser::SLASH);
                      setState(485); 
                      _errHandler->sync(this);
                      _la = _input->LA(1);
                    } while (_la == UserAgentParser::SLASH);
                    break;
                  }

                  case UserAgentParser::MINUS: {
                    setState(487);
                    match(UserAgentParser::MINUS);
                    break;
                  }

                  case UserAgentParser::ATSIGN: {
                    setState(488);
                    match(UserAgentParser::ATSIGN);
                    break;
                  }

                default:
                  throw NoViableAltException(this);
                }
                setState(492);
                _errHandler->sync(this);

                _la = _input->LA(1);
                if (_la == UserAgentParser::EQUALS) {
                  setState(491);
                  match(UserAgentParser::EQUALS);
                }

                setState(494);
                productVersionWithCommas();
                setState(496);
                _errHandler->sync(this);

                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 101, _ctx)) {
                case 1: {
                  setState(495);
                  match(UserAgentParser::COMMA);
                  break;
                }

                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(500); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 102, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(528);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(503);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (_la == UserAgentParser::MINUS) {
            setState(502);
            match(UserAgentParser::MINUS);
          }
          setState(505);
          commentBlock();
          setState(523);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == UserAgentParser::SLASH

          || _la == UserAgentParser::ATSIGN) {
            setState(507); 
            _errHandler->sync(this);
            _la = _input->LA(1);
            do {
              setState(506);
              _la = _input->LA(1);
              if (!(_la == UserAgentParser::SLASH

              || _la == UserAgentParser::ATSIGN)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              setState(509); 
              _errHandler->sync(this);
              _la = _input->LA(1);
            } while (_la == UserAgentParser::SLASH

            || _la == UserAgentParser::ATSIGN);
            setState(512);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == UserAgentParser::EQUALS) {
              setState(511);
              match(UserAgentParser::EQUALS);
            }
            setState(516);
            _errHandler->sync(this);
            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx)) {
            case 1: {
              setState(514);
              productVersionWithCommas();
              break;
            }

            case 2: {
              setState(515);
              productVersionSingleWord();
              break;
            }

            }
            setState(519);
            _errHandler->sync(this);

            switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 107, _ctx)) {
            case 1: {
              setState(518);
              match(UserAgentParser::COMMA);
              break;
            }

            }
            setState(525);
            _errHandler->sync(this);
            _la = _input->LA(1);
          } 
        }
        setState(530);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 109, _ctx);
      }
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

//----------------- ProductVersionWordsContext ------------------------------------------------------------------

UserAgentParser::ProductVersionWordsContext::ProductVersionWordsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductVersionWordsContext::WORD() {
  return getTokens(UserAgentParser::WORD);
}

tree::TerminalNode* UserAgentParser::ProductVersionWordsContext::WORD(size_t i) {
  return getToken(UserAgentParser::WORD, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductVersionWordsContext::MINUS() {
  return getTokens(UserAgentParser::MINUS);
}

tree::TerminalNode* UserAgentParser::ProductVersionWordsContext::MINUS(size_t i) {
  return getToken(UserAgentParser::MINUS, i);
}

tree::TerminalNode* UserAgentParser::ProductVersionWordsContext::UNASSIGNEDVARIABLE() {
  return getToken(UserAgentParser::UNASSIGNEDVARIABLE, 0);
}

tree::TerminalNode* UserAgentParser::ProductVersionWordsContext::SPECIALVERSIONWORDS() {
  return getToken(UserAgentParser::SPECIALVERSIONWORDS, 0);
}


size_t UserAgentParser::ProductVersionWordsContext::getRuleIndex() const {
  return UserAgentParser::RuleProductVersionWords;
}

void UserAgentParser::ProductVersionWordsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductVersionWords(this);
}

void UserAgentParser::ProductVersionWordsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductVersionWords(this);
}


antlrcpp::Any UserAgentParser::ProductVersionWordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductVersionWords(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductVersionWordsContext* UserAgentParser::productVersionWords() {
  ProductVersionWordsContext *_localctx = _tracker.createInstance<ProductVersionWordsContext>(_ctx, getState());
  enterRule(_localctx, 10, UserAgentParser::RuleProductVersionWords);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(545);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::WORD: {
        enterOuterAlt(_localctx, 1);
        setState(533);
        match(UserAgentParser::WORD);
        setState(540);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(535);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == UserAgentParser::MINUS) {
              setState(534);
              match(UserAgentParser::MINUS);
            }
            setState(537);
            match(UserAgentParser::WORD); 
          }
          setState(542);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 112, _ctx);
        }
        break;
      }

      case UserAgentParser::UNASSIGNEDVARIABLE: {
        enterOuterAlt(_localctx, 2);
        setState(543);
        match(UserAgentParser::UNASSIGNEDVARIABLE);
        break;
      }

      case UserAgentParser::SPECIALVERSIONWORDS: {
        enterOuterAlt(_localctx, 3);
        setState(544);
        match(UserAgentParser::SPECIALVERSIONWORDS);
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

//----------------- ProductNameContext ------------------------------------------------------------------

UserAgentParser::ProductNameContext::ProductNameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::ProductNameKeyValueContext* UserAgentParser::ProductNameContext::productNameKeyValue() {
  return getRuleContext<UserAgentParser::ProductNameKeyValueContext>(0);
}

UserAgentParser::ProductNameEmailContext* UserAgentParser::ProductNameContext::productNameEmail() {
  return getRuleContext<UserAgentParser::ProductNameEmailContext>(0);
}

UserAgentParser::ProductNameUrlContext* UserAgentParser::ProductNameContext::productNameUrl() {
  return getRuleContext<UserAgentParser::ProductNameUrlContext>(0);
}

UserAgentParser::ProductNameVersionContext* UserAgentParser::ProductNameContext::productNameVersion() {
  return getRuleContext<UserAgentParser::ProductNameVersionContext>(0);
}

UserAgentParser::ProductNameUuidContext* UserAgentParser::ProductNameContext::productNameUuid() {
  return getRuleContext<UserAgentParser::ProductNameUuidContext>(0);
}

UserAgentParser::ProductNameWordsContext* UserAgentParser::ProductNameContext::productNameWords() {
  return getRuleContext<UserAgentParser::ProductNameWordsContext>(0);
}


size_t UserAgentParser::ProductNameContext::getRuleIndex() const {
  return UserAgentParser::RuleProductName;
}

void UserAgentParser::ProductNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductName(this);
}

void UserAgentParser::ProductNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductName(this);
}


antlrcpp::Any UserAgentParser::ProductNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductName(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductNameContext* UserAgentParser::productName() {
  ProductNameContext *_localctx = _tracker.createInstance<ProductNameContext>(_ctx, getState());
  enterRule(_localctx, 12, UserAgentParser::RuleProductName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(553);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 114, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(547);
      productNameKeyValue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(548);
      productNameEmail();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(549);
      productNameUrl();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(550);
      productNameVersion();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(551);
      productNameUuid();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(552);
      productNameWords();
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

//----------------- ProductNameWordsContext ------------------------------------------------------------------

UserAgentParser::ProductNameWordsContext::ProductNameWordsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductNameWordsContext::WORD() {
  return getTokens(UserAgentParser::WORD);
}

tree::TerminalNode* UserAgentParser::ProductNameWordsContext::WORD(size_t i) {
  return getToken(UserAgentParser::WORD, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductNameWordsContext::MINUS() {
  return getTokens(UserAgentParser::MINUS);
}

tree::TerminalNode* UserAgentParser::ProductNameWordsContext::MINUS(size_t i) {
  return getToken(UserAgentParser::MINUS, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductNameWordsContext::COMMA() {
  return getTokens(UserAgentParser::COMMA);
}

tree::TerminalNode* UserAgentParser::ProductNameWordsContext::COMMA(size_t i) {
  return getToken(UserAgentParser::COMMA, i);
}

tree::TerminalNode* UserAgentParser::ProductNameWordsContext::CURLYBRACEOPEN() {
  return getToken(UserAgentParser::CURLYBRACEOPEN, 0);
}

tree::TerminalNode* UserAgentParser::ProductNameWordsContext::CURLYBRACECLOSE() {
  return getToken(UserAgentParser::CURLYBRACECLOSE, 0);
}


size_t UserAgentParser::ProductNameWordsContext::getRuleIndex() const {
  return UserAgentParser::RuleProductNameWords;
}

void UserAgentParser::ProductNameWordsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductNameWords(this);
}

void UserAgentParser::ProductNameWordsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductNameWords(this);
}


antlrcpp::Any UserAgentParser::ProductNameWordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductNameWords(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductNameWordsContext* UserAgentParser::productNameWords() {
  ProductNameWordsContext *_localctx = _tracker.createInstance<ProductNameWordsContext>(_ctx, getState());
  enterRule(_localctx, 14, UserAgentParser::RuleProductNameWords);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(613);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 125, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(555);
      match(UserAgentParser::WORD);
      setState(565);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(559);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == UserAgentParser::COMMA

          || _la == UserAgentParser::MINUS) {
            setState(556);
            _la = _input->LA(1);
            if (!(_la == UserAgentParser::COMMA

            || _la == UserAgentParser::MINUS)) {
            _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(561);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(562);
          match(UserAgentParser::WORD); 
        }
        setState(567);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 116, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(581);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentParser::WORD) {
        setState(568);
        match(UserAgentParser::WORD);
        setState(578);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << UserAgentParser::COMMA)
          | (1ULL << UserAgentParser::MINUS)
          | (1ULL << UserAgentParser::WORD))) != 0)) {
          setState(572);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == UserAgentParser::COMMA

          || _la == UserAgentParser::MINUS) {
            setState(569);
            _la = _input->LA(1);
            if (!(_la == UserAgentParser::COMMA

            || _la == UserAgentParser::MINUS)) {
            _errHandler->recoverInline(this);
            }
            else {
              _errHandler->reportMatch(this);
              consume();
            }
            setState(574);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(575);
          match(UserAgentParser::WORD);
          setState(580);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(583);
      match(UserAgentParser::CURLYBRACEOPEN);
      setState(584);
      match(UserAgentParser::WORD);
      setState(594);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << UserAgentParser::COMMA)
        | (1ULL << UserAgentParser::MINUS)
        | (1ULL << UserAgentParser::WORD))) != 0)) {
        setState(588);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == UserAgentParser::COMMA

        || _la == UserAgentParser::MINUS) {
          setState(585);
          _la = _input->LA(1);
          if (!(_la == UserAgentParser::COMMA

          || _la == UserAgentParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(590);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(591);
        match(UserAgentParser::WORD);
        setState(596);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(597);
      match(UserAgentParser::CURLYBRACECLOSE);
      setState(611);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 124, _ctx)) {
      case 1: {
        setState(598);
        match(UserAgentParser::WORD);
        setState(608);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(602);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == UserAgentParser::COMMA

            || _la == UserAgentParser::MINUS) {
              setState(599);
              _la = _input->LA(1);
              if (!(_la == UserAgentParser::COMMA

              || _la == UserAgentParser::MINUS)) {
              _errHandler->recoverInline(this);
              }
              else {
                _errHandler->reportMatch(this);
                consume();
              }
              setState(604);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            setState(605);
            match(UserAgentParser::WORD); 
          }
          setState(610);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 123, _ctx);
        }
        break;
      }

      }
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

//----------------- ProductVersionContext ------------------------------------------------------------------

UserAgentParser::ProductVersionContext::ProductVersionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::KeyValueContext* UserAgentParser::ProductVersionContext::keyValue() {
  return getRuleContext<UserAgentParser::KeyValueContext>(0);
}

UserAgentParser::EmailAddressContext* UserAgentParser::ProductVersionContext::emailAddress() {
  return getRuleContext<UserAgentParser::EmailAddressContext>(0);
}

UserAgentParser::SiteUrlContext* UserAgentParser::ProductVersionContext::siteUrl() {
  return getRuleContext<UserAgentParser::SiteUrlContext>(0);
}

UserAgentParser::UuIdContext* UserAgentParser::ProductVersionContext::uuId() {
  return getRuleContext<UserAgentParser::UuIdContext>(0);
}

UserAgentParser::Base64Context* UserAgentParser::ProductVersionContext::base64() {
  return getRuleContext<UserAgentParser::Base64Context>(0);
}

UserAgentParser::SingleVersionContext* UserAgentParser::ProductVersionContext::singleVersion() {
  return getRuleContext<UserAgentParser::SingleVersionContext>(0);
}

tree::TerminalNode* UserAgentParser::ProductVersionContext::SPECIALVERSIONWORDS() {
  return getToken(UserAgentParser::SPECIALVERSIONWORDS, 0);
}


size_t UserAgentParser::ProductVersionContext::getRuleIndex() const {
  return UserAgentParser::RuleProductVersion;
}

void UserAgentParser::ProductVersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductVersion(this);
}

void UserAgentParser::ProductVersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductVersion(this);
}


antlrcpp::Any UserAgentParser::ProductVersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductVersion(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductVersionContext* UserAgentParser::productVersion() {
  ProductVersionContext *_localctx = _tracker.createInstance<ProductVersionContext>(_ctx, getState());
  enterRule(_localctx, 16, UserAgentParser::RuleProductVersion);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(622);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 126, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(615);
      keyValue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(616);
      emailAddress();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(617);
      siteUrl();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(618);
      uuId();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(619);
      base64();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(620);
      singleVersion();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(621);
      match(UserAgentParser::SPECIALVERSIONWORDS);
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

//----------------- ProductVersionWithCommasContext ------------------------------------------------------------------

UserAgentParser::ProductVersionWithCommasContext::ProductVersionWithCommasContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

std::vector<UserAgentParser::KeyValueContext *> UserAgentParser::ProductVersionWithCommasContext::keyValue() {
  return getRuleContexts<UserAgentParser::KeyValueContext>();
}

UserAgentParser::KeyValueContext* UserAgentParser::ProductVersionWithCommasContext::keyValue(size_t i) {
  return getRuleContext<UserAgentParser::KeyValueContext>(i);
}

UserAgentParser::EmailAddressContext* UserAgentParser::ProductVersionWithCommasContext::emailAddress() {
  return getRuleContext<UserAgentParser::EmailAddressContext>(0);
}

UserAgentParser::SiteUrlContext* UserAgentParser::ProductVersionWithCommasContext::siteUrl() {
  return getRuleContext<UserAgentParser::SiteUrlContext>(0);
}

UserAgentParser::UuIdContext* UserAgentParser::ProductVersionWithCommasContext::uuId() {
  return getRuleContext<UserAgentParser::UuIdContext>(0);
}

UserAgentParser::Base64Context* UserAgentParser::ProductVersionWithCommasContext::base64() {
  return getRuleContext<UserAgentParser::Base64Context>(0);
}

UserAgentParser::SingleVersionWithCommasContext* UserAgentParser::ProductVersionWithCommasContext::singleVersionWithCommas() {
  return getRuleContext<UserAgentParser::SingleVersionWithCommasContext>(0);
}

tree::TerminalNode* UserAgentParser::ProductVersionWithCommasContext::SPECIALVERSIONWORDS() {
  return getToken(UserAgentParser::SPECIALVERSIONWORDS, 0);
}

tree::TerminalNode* UserAgentParser::ProductVersionWithCommasContext::CURLYBRACEOPEN() {
  return getToken(UserAgentParser::CURLYBRACEOPEN, 0);
}

tree::TerminalNode* UserAgentParser::ProductVersionWithCommasContext::CURLYBRACECLOSE() {
  return getToken(UserAgentParser::CURLYBRACECLOSE, 0);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductVersionWithCommasContext::COMMA() {
  return getTokens(UserAgentParser::COMMA);
}

tree::TerminalNode* UserAgentParser::ProductVersionWithCommasContext::COMMA(size_t i) {
  return getToken(UserAgentParser::COMMA, i);
}


size_t UserAgentParser::ProductVersionWithCommasContext::getRuleIndex() const {
  return UserAgentParser::RuleProductVersionWithCommas;
}

void UserAgentParser::ProductVersionWithCommasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductVersionWithCommas(this);
}

void UserAgentParser::ProductVersionWithCommasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductVersionWithCommas(this);
}


antlrcpp::Any UserAgentParser::ProductVersionWithCommasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductVersionWithCommas(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductVersionWithCommasContext* UserAgentParser::productVersionWithCommas() {
  ProductVersionWithCommasContext *_localctx = _tracker.createInstance<ProductVersionWithCommasContext>(_ctx, getState());
  enterRule(_localctx, 18, UserAgentParser::RuleProductVersionWithCommas);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(642);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 128, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(624);
      keyValue();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(625);
      emailAddress();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(626);
      siteUrl();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(627);
      uuId();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(628);
      base64();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(629);
      singleVersionWithCommas();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(630);
      match(UserAgentParser::SPECIALVERSIONWORDS);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(631);
      match(UserAgentParser::CURLYBRACEOPEN);
      setState(632);
      keyValue();
      setState(637);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == UserAgentParser::COMMA) {
        setState(633);
        match(UserAgentParser::COMMA);
        setState(634);
        keyValue();
        setState(639);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(640);
      match(UserAgentParser::CURLYBRACECLOSE);
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

//----------------- ProductVersionSingleWordContext ------------------------------------------------------------------

UserAgentParser::ProductVersionSingleWordContext::ProductVersionSingleWordContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::ProductVersionSingleWordContext::WORD() {
  return getToken(UserAgentParser::WORD, 0);
}

tree::TerminalNode* UserAgentParser::ProductVersionSingleWordContext::CURLYBRACEOPEN() {
  return getToken(UserAgentParser::CURLYBRACEOPEN, 0);
}

tree::TerminalNode* UserAgentParser::ProductVersionSingleWordContext::CURLYBRACECLOSE() {
  return getToken(UserAgentParser::CURLYBRACECLOSE, 0);
}


size_t UserAgentParser::ProductVersionSingleWordContext::getRuleIndex() const {
  return UserAgentParser::RuleProductVersionSingleWord;
}

void UserAgentParser::ProductVersionSingleWordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductVersionSingleWord(this);
}

void UserAgentParser::ProductVersionSingleWordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductVersionSingleWord(this);
}


antlrcpp::Any UserAgentParser::ProductVersionSingleWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductVersionSingleWord(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductVersionSingleWordContext* UserAgentParser::productVersionSingleWord() {
  ProductVersionSingleWordContext *_localctx = _tracker.createInstance<ProductVersionSingleWordContext>(_ctx, getState());
  enterRule(_localctx, 20, UserAgentParser::RuleProductVersionSingleWord);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(648);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::WORD: {
        enterOuterAlt(_localctx, 1);
        setState(644);
        match(UserAgentParser::WORD);
        break;
      }

      case UserAgentParser::CURLYBRACEOPEN: {
        enterOuterAlt(_localctx, 2);
        setState(645);
        match(UserAgentParser::CURLYBRACEOPEN);
        setState(646);
        match(UserAgentParser::WORD);
        setState(647);
        match(UserAgentParser::CURLYBRACECLOSE);
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

//----------------- SingleVersionContext ------------------------------------------------------------------

UserAgentParser::SingleVersionContext::SingleVersionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::SingleVersionContext::VERSION() {
  return getToken(UserAgentParser::VERSION, 0);
}


size_t UserAgentParser::SingleVersionContext::getRuleIndex() const {
  return UserAgentParser::RuleSingleVersion;
}

void UserAgentParser::SingleVersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleVersion(this);
}

void UserAgentParser::SingleVersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleVersion(this);
}


antlrcpp::Any UserAgentParser::SingleVersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitSingleVersion(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::SingleVersionContext* UserAgentParser::singleVersion() {
  SingleVersionContext *_localctx = _tracker.createInstance<SingleVersionContext>(_ctx, getState());
  enterRule(_localctx, 22, UserAgentParser::RuleSingleVersion);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(650);
    match(UserAgentParser::VERSION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleVersionWithCommasContext ------------------------------------------------------------------

UserAgentParser::SingleVersionWithCommasContext::SingleVersionWithCommasContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> UserAgentParser::SingleVersionWithCommasContext::VERSION() {
  return getTokens(UserAgentParser::VERSION);
}

tree::TerminalNode* UserAgentParser::SingleVersionWithCommasContext::VERSION(size_t i) {
  return getToken(UserAgentParser::VERSION, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::SingleVersionWithCommasContext::COMMA() {
  return getTokens(UserAgentParser::COMMA);
}

tree::TerminalNode* UserAgentParser::SingleVersionWithCommasContext::COMMA(size_t i) {
  return getToken(UserAgentParser::COMMA, i);
}


size_t UserAgentParser::SingleVersionWithCommasContext::getRuleIndex() const {
  return UserAgentParser::RuleSingleVersionWithCommas;
}

void UserAgentParser::SingleVersionWithCommasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleVersionWithCommas(this);
}

void UserAgentParser::SingleVersionWithCommasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleVersionWithCommas(this);
}


antlrcpp::Any UserAgentParser::SingleVersionWithCommasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitSingleVersionWithCommas(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::SingleVersionWithCommasContext* UserAgentParser::singleVersionWithCommas() {
  SingleVersionWithCommasContext *_localctx = _tracker.createInstance<SingleVersionWithCommasContext>(_ctx, getState());
  enterRule(_localctx, 24, UserAgentParser::RuleSingleVersionWithCommas);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(652);
    match(UserAgentParser::VERSION);
    setState(657);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(653);
        match(UserAgentParser::COMMA);
        setState(654);
        match(UserAgentParser::VERSION); 
      }
      setState(659);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 130, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProductNameVersionContext ------------------------------------------------------------------

UserAgentParser::ProductNameVersionContext::ProductNameVersionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::ProductNameVersionContext::VERSION() {
  return getToken(UserAgentParser::VERSION, 0);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductNameVersionContext::WORD() {
  return getTokens(UserAgentParser::WORD);
}

tree::TerminalNode* UserAgentParser::ProductNameVersionContext::WORD(size_t i) {
  return getToken(UserAgentParser::WORD, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductNameVersionContext::MINUS() {
  return getTokens(UserAgentParser::MINUS);
}

tree::TerminalNode* UserAgentParser::ProductNameVersionContext::MINUS(size_t i) {
  return getToken(UserAgentParser::MINUS, i);
}


size_t UserAgentParser::ProductNameVersionContext::getRuleIndex() const {
  return UserAgentParser::RuleProductNameVersion;
}

void UserAgentParser::ProductNameVersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductNameVersion(this);
}

void UserAgentParser::ProductNameVersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductNameVersion(this);
}


antlrcpp::Any UserAgentParser::ProductNameVersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductNameVersion(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductNameVersionContext* UserAgentParser::productNameVersion() {
  ProductNameVersionContext *_localctx = _tracker.createInstance<ProductNameVersionContext>(_ctx, getState());
  enterRule(_localctx, 26, UserAgentParser::RuleProductNameVersion);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(660);
    match(UserAgentParser::VERSION);
    setState(667);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(662);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == UserAgentParser::MINUS) {
          setState(661);
          match(UserAgentParser::MINUS);
        }
        setState(664);
        match(UserAgentParser::WORD); 
      }
      setState(669);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 132, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProductNameEmailContext ------------------------------------------------------------------

UserAgentParser::ProductNameEmailContext::ProductNameEmailContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::EmailAddressContext* UserAgentParser::ProductNameEmailContext::emailAddress() {
  return getRuleContext<UserAgentParser::EmailAddressContext>(0);
}


size_t UserAgentParser::ProductNameEmailContext::getRuleIndex() const {
  return UserAgentParser::RuleProductNameEmail;
}

void UserAgentParser::ProductNameEmailContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductNameEmail(this);
}

void UserAgentParser::ProductNameEmailContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductNameEmail(this);
}


antlrcpp::Any UserAgentParser::ProductNameEmailContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductNameEmail(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductNameEmailContext* UserAgentParser::productNameEmail() {
  ProductNameEmailContext *_localctx = _tracker.createInstance<ProductNameEmailContext>(_ctx, getState());
  enterRule(_localctx, 28, UserAgentParser::RuleProductNameEmail);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(670);
    emailAddress();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProductNameUrlContext ------------------------------------------------------------------

UserAgentParser::ProductNameUrlContext::ProductNameUrlContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::SiteUrlContext* UserAgentParser::ProductNameUrlContext::siteUrl() {
  return getRuleContext<UserAgentParser::SiteUrlContext>(0);
}


size_t UserAgentParser::ProductNameUrlContext::getRuleIndex() const {
  return UserAgentParser::RuleProductNameUrl;
}

void UserAgentParser::ProductNameUrlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductNameUrl(this);
}

void UserAgentParser::ProductNameUrlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductNameUrl(this);
}


antlrcpp::Any UserAgentParser::ProductNameUrlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductNameUrl(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductNameUrlContext* UserAgentParser::productNameUrl() {
  ProductNameUrlContext *_localctx = _tracker.createInstance<ProductNameUrlContext>(_ctx, getState());
  enterRule(_localctx, 30, UserAgentParser::RuleProductNameUrl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(672);
    siteUrl();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProductNameUuidContext ------------------------------------------------------------------

UserAgentParser::ProductNameUuidContext::ProductNameUuidContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::UuIdContext* UserAgentParser::ProductNameUuidContext::uuId() {
  return getRuleContext<UserAgentParser::UuIdContext>(0);
}


size_t UserAgentParser::ProductNameUuidContext::getRuleIndex() const {
  return UserAgentParser::RuleProductNameUuid;
}

void UserAgentParser::ProductNameUuidContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductNameUuid(this);
}

void UserAgentParser::ProductNameUuidContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductNameUuid(this);
}


antlrcpp::Any UserAgentParser::ProductNameUuidContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductNameUuid(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductNameUuidContext* UserAgentParser::productNameUuid() {
  ProductNameUuidContext *_localctx = _tracker.createInstance<ProductNameUuidContext>(_ctx, getState());
  enterRule(_localctx, 32, UserAgentParser::RuleProductNameUuid);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(674);
    uuId();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UuIdContext ------------------------------------------------------------------

UserAgentParser::UuIdContext::UuIdContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::UuIdContext::UUID() {
  return getToken(UserAgentParser::UUID, 0);
}

tree::TerminalNode* UserAgentParser::UuIdContext::CURLYBRACEOPEN() {
  return getToken(UserAgentParser::CURLYBRACEOPEN, 0);
}

tree::TerminalNode* UserAgentParser::UuIdContext::CURLYBRACECLOSE() {
  return getToken(UserAgentParser::CURLYBRACECLOSE, 0);
}


size_t UserAgentParser::UuIdContext::getRuleIndex() const {
  return UserAgentParser::RuleUuId;
}

void UserAgentParser::UuIdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUuId(this);
}

void UserAgentParser::UuIdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUuId(this);
}


antlrcpp::Any UserAgentParser::UuIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitUuId(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::UuIdContext* UserAgentParser::uuId() {
  UuIdContext *_localctx = _tracker.createInstance<UuIdContext>(_ctx, getState());
  enterRule(_localctx, 34, UserAgentParser::RuleUuId);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(680);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::UUID: {
        enterOuterAlt(_localctx, 1);
        setState(676);
        dynamic_cast<UuIdContext *>(_localctx)->uuid = match(UserAgentParser::UUID);
        break;
      }

      case UserAgentParser::CURLYBRACEOPEN: {
        enterOuterAlt(_localctx, 2);
        setState(677);
        match(UserAgentParser::CURLYBRACEOPEN);
        setState(678);
        dynamic_cast<UuIdContext *>(_localctx)->uuid = match(UserAgentParser::UUID);
        setState(679);
        match(UserAgentParser::CURLYBRACECLOSE);
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

//----------------- EmailAddressContext ------------------------------------------------------------------

UserAgentParser::EmailAddressContext::EmailAddressContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::EmailAddressContext::EMAIL() {
  return getToken(UserAgentParser::EMAIL, 0);
}

tree::TerminalNode* UserAgentParser::EmailAddressContext::CURLYBRACEOPEN() {
  return getToken(UserAgentParser::CURLYBRACEOPEN, 0);
}

tree::TerminalNode* UserAgentParser::EmailAddressContext::CURLYBRACECLOSE() {
  return getToken(UserAgentParser::CURLYBRACECLOSE, 0);
}


size_t UserAgentParser::EmailAddressContext::getRuleIndex() const {
  return UserAgentParser::RuleEmailAddress;
}

void UserAgentParser::EmailAddressContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmailAddress(this);
}

void UserAgentParser::EmailAddressContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmailAddress(this);
}


antlrcpp::Any UserAgentParser::EmailAddressContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitEmailAddress(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::EmailAddressContext* UserAgentParser::emailAddress() {
  EmailAddressContext *_localctx = _tracker.createInstance<EmailAddressContext>(_ctx, getState());
  enterRule(_localctx, 36, UserAgentParser::RuleEmailAddress);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(686);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::EMAIL: {
        enterOuterAlt(_localctx, 1);
        setState(682);
        dynamic_cast<EmailAddressContext *>(_localctx)->email = match(UserAgentParser::EMAIL);
        break;
      }

      case UserAgentParser::CURLYBRACEOPEN: {
        enterOuterAlt(_localctx, 2);
        setState(683);
        match(UserAgentParser::CURLYBRACEOPEN);
        setState(684);
        dynamic_cast<EmailAddressContext *>(_localctx)->email = match(UserAgentParser::EMAIL);
        setState(685);
        match(UserAgentParser::CURLYBRACECLOSE);
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

//----------------- SiteUrlContext ------------------------------------------------------------------

UserAgentParser::SiteUrlContext::SiteUrlContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::SiteUrlContext::URL() {
  return getToken(UserAgentParser::URL, 0);
}

tree::TerminalNode* UserAgentParser::SiteUrlContext::CURLYBRACEOPEN() {
  return getToken(UserAgentParser::CURLYBRACEOPEN, 0);
}

tree::TerminalNode* UserAgentParser::SiteUrlContext::CURLYBRACECLOSE() {
  return getToken(UserAgentParser::CURLYBRACECLOSE, 0);
}


size_t UserAgentParser::SiteUrlContext::getRuleIndex() const {
  return UserAgentParser::RuleSiteUrl;
}

void UserAgentParser::SiteUrlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSiteUrl(this);
}

void UserAgentParser::SiteUrlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSiteUrl(this);
}


antlrcpp::Any UserAgentParser::SiteUrlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitSiteUrl(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::SiteUrlContext* UserAgentParser::siteUrl() {
  SiteUrlContext *_localctx = _tracker.createInstance<SiteUrlContext>(_ctx, getState());
  enterRule(_localctx, 38, UserAgentParser::RuleSiteUrl);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(692);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::URL: {
        enterOuterAlt(_localctx, 1);
        setState(688);
        dynamic_cast<SiteUrlContext *>(_localctx)->url = match(UserAgentParser::URL);
        break;
      }

      case UserAgentParser::CURLYBRACEOPEN: {
        enterOuterAlt(_localctx, 2);
        setState(689);
        match(UserAgentParser::CURLYBRACEOPEN);
        setState(690);
        dynamic_cast<SiteUrlContext *>(_localctx)->url = match(UserAgentParser::URL);
        setState(691);
        match(UserAgentParser::CURLYBRACECLOSE);
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

//----------------- Base64Context ------------------------------------------------------------------

UserAgentParser::Base64Context::Base64Context(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::Base64Context::BASE64() {
  return getToken(UserAgentParser::BASE64, 0);
}

tree::TerminalNode* UserAgentParser::Base64Context::CURLYBRACEOPEN() {
  return getToken(UserAgentParser::CURLYBRACEOPEN, 0);
}

tree::TerminalNode* UserAgentParser::Base64Context::CURLYBRACECLOSE() {
  return getToken(UserAgentParser::CURLYBRACECLOSE, 0);
}


size_t UserAgentParser::Base64Context::getRuleIndex() const {
  return UserAgentParser::RuleBase64;
}

void UserAgentParser::Base64Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBase64(this);
}

void UserAgentParser::Base64Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBase64(this);
}


antlrcpp::Any UserAgentParser::Base64Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitBase64(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::Base64Context* UserAgentParser::base64() {
  Base64Context *_localctx = _tracker.createInstance<Base64Context>(_ctx, getState());
  enterRule(_localctx, 40, UserAgentParser::RuleBase64);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(698);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::BASE64: {
        enterOuterAlt(_localctx, 1);
        setState(694);
        dynamic_cast<Base64Context *>(_localctx)->value = match(UserAgentParser::BASE64);
        break;
      }

      case UserAgentParser::CURLYBRACEOPEN: {
        enterOuterAlt(_localctx, 2);
        setState(695);
        match(UserAgentParser::CURLYBRACEOPEN);
        setState(696);
        dynamic_cast<Base64Context *>(_localctx)->value = match(UserAgentParser::BASE64);
        setState(697);
        match(UserAgentParser::CURLYBRACECLOSE);
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

//----------------- CommentSeparatorContext ------------------------------------------------------------------

UserAgentParser::CommentSeparatorContext::CommentSeparatorContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::CommentSeparatorContext::SEMICOLON() {
  return getToken(UserAgentParser::SEMICOLON, 0);
}

tree::TerminalNode* UserAgentParser::CommentSeparatorContext::COMMA() {
  return getToken(UserAgentParser::COMMA, 0);
}


size_t UserAgentParser::CommentSeparatorContext::getRuleIndex() const {
  return UserAgentParser::RuleCommentSeparator;
}

void UserAgentParser::CommentSeparatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommentSeparator(this);
}

void UserAgentParser::CommentSeparatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommentSeparator(this);
}


antlrcpp::Any UserAgentParser::CommentSeparatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitCommentSeparator(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::CommentSeparatorContext* UserAgentParser::commentSeparator() {
  CommentSeparatorContext *_localctx = _tracker.createInstance<CommentSeparatorContext>(_ctx, getState());
  enterRule(_localctx, 42, UserAgentParser::RuleCommentSeparator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(700);
    _la = _input->LA(1);
    if (!(_la == UserAgentParser::SEMICOLON

    || _la == UserAgentParser::COMMA)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommentBlockContext ------------------------------------------------------------------

UserAgentParser::CommentBlockContext::CommentBlockContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::CommentBlockContext::BRACEOPEN() {
  return getToken(UserAgentParser::BRACEOPEN, 0);
}

std::vector<UserAgentParser::CommentEntryContext *> UserAgentParser::CommentBlockContext::commentEntry() {
  return getRuleContexts<UserAgentParser::CommentEntryContext>();
}

UserAgentParser::CommentEntryContext* UserAgentParser::CommentBlockContext::commentEntry(size_t i) {
  return getRuleContext<UserAgentParser::CommentEntryContext>(i);
}

tree::TerminalNode* UserAgentParser::CommentBlockContext::BRACECLOSE() {
  return getToken(UserAgentParser::BRACECLOSE, 0);
}

tree::TerminalNode* UserAgentParser::CommentBlockContext::EOF() {
  return getToken(UserAgentParser::EOF, 0);
}

std::vector<UserAgentParser::CommentSeparatorContext *> UserAgentParser::CommentBlockContext::commentSeparator() {
  return getRuleContexts<UserAgentParser::CommentSeparatorContext>();
}

UserAgentParser::CommentSeparatorContext* UserAgentParser::CommentBlockContext::commentSeparator(size_t i) {
  return getRuleContext<UserAgentParser::CommentSeparatorContext>(i);
}

tree::TerminalNode* UserAgentParser::CommentBlockContext::BLOCKOPEN() {
  return getToken(UserAgentParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentParser::CommentBlockContext::BLOCKCLOSE() {
  return getToken(UserAgentParser::BLOCKCLOSE, 0);
}


size_t UserAgentParser::CommentBlockContext::getRuleIndex() const {
  return UserAgentParser::RuleCommentBlock;
}

void UserAgentParser::CommentBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommentBlock(this);
}

void UserAgentParser::CommentBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommentBlock(this);
}


antlrcpp::Any UserAgentParser::CommentBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitCommentBlock(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::CommentBlockContext* UserAgentParser::commentBlock() {
  CommentBlockContext *_localctx = _tracker.createInstance<CommentBlockContext>(_ctx, getState());
  enterRule(_localctx, 44, UserAgentParser::RuleCommentBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(726);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::BRACEOPEN: {
        enterOuterAlt(_localctx, 1);
        setState(702);
        match(UserAgentParser::BRACEOPEN);
        setState(703);
        commentEntry();
        setState(709);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == UserAgentParser::SEMICOLON

        || _la == UserAgentParser::COMMA) {
          setState(704);
          commentSeparator();
          setState(705);
          commentEntry();
          setState(711);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(712);
        _la = _input->LA(1);
        if (!(_la == UserAgentParser::EOF

        || _la == UserAgentParser::BRACECLOSE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

      case UserAgentParser::BLOCKOPEN: {
        enterOuterAlt(_localctx, 2);
        setState(714);
        match(UserAgentParser::BLOCKOPEN);
        setState(715);
        commentEntry();
        setState(721);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == UserAgentParser::SEMICOLON

        || _la == UserAgentParser::COMMA) {
          setState(716);
          commentSeparator();
          setState(717);
          commentEntry();
          setState(723);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(724);
        _la = _input->LA(1);
        if (!(_la == UserAgentParser::EOF

        || _la == UserAgentParser::BLOCKCLOSE)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
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

//----------------- CommentEntryContext ------------------------------------------------------------------

UserAgentParser::CommentEntryContext::CommentEntryContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::EmptyWordContext* UserAgentParser::CommentEntryContext::emptyWord() {
  return getRuleContext<UserAgentParser::EmptyWordContext>(0);
}

std::vector<UserAgentParser::MultipleWordsContext *> UserAgentParser::CommentEntryContext::multipleWords() {
  return getRuleContexts<UserAgentParser::MultipleWordsContext>();
}

UserAgentParser::MultipleWordsContext* UserAgentParser::CommentEntryContext::multipleWords(size_t i) {
  return getRuleContext<UserAgentParser::MultipleWordsContext>(i);
}

UserAgentParser::ProductNameNoVersionContext* UserAgentParser::CommentEntryContext::productNameNoVersion() {
  return getRuleContext<UserAgentParser::ProductNameNoVersionContext>(0);
}

UserAgentParser::KeyWithoutValueContext* UserAgentParser::CommentEntryContext::keyWithoutValue() {
  return getRuleContext<UserAgentParser::KeyWithoutValueContext>(0);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentEntryContext::CURLYBRACEOPEN() {
  return getTokens(UserAgentParser::CURLYBRACEOPEN);
}

tree::TerminalNode* UserAgentParser::CommentEntryContext::CURLYBRACEOPEN(size_t i) {
  return getToken(UserAgentParser::CURLYBRACEOPEN, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentEntryContext::CURLYBRACECLOSE() {
  return getTokens(UserAgentParser::CURLYBRACECLOSE);
}

tree::TerminalNode* UserAgentParser::CommentEntryContext::CURLYBRACECLOSE(size_t i) {
  return getToken(UserAgentParser::CURLYBRACECLOSE, i);
}

std::vector<UserAgentParser::CommentProductContext *> UserAgentParser::CommentEntryContext::commentProduct() {
  return getRuleContexts<UserAgentParser::CommentProductContext>();
}

UserAgentParser::CommentProductContext* UserAgentParser::CommentEntryContext::commentProduct(size_t i) {
  return getRuleContext<UserAgentParser::CommentProductContext>(i);
}

std::vector<UserAgentParser::KeyValueContext *> UserAgentParser::CommentEntryContext::keyValue() {
  return getRuleContexts<UserAgentParser::KeyValueContext>();
}

UserAgentParser::KeyValueContext* UserAgentParser::CommentEntryContext::keyValue(size_t i) {
  return getRuleContext<UserAgentParser::KeyValueContext>(i);
}

std::vector<UserAgentParser::UuIdContext *> UserAgentParser::CommentEntryContext::uuId() {
  return getRuleContexts<UserAgentParser::UuIdContext>();
}

UserAgentParser::UuIdContext* UserAgentParser::CommentEntryContext::uuId(size_t i) {
  return getRuleContext<UserAgentParser::UuIdContext>(i);
}

std::vector<UserAgentParser::SiteUrlContext *> UserAgentParser::CommentEntryContext::siteUrl() {
  return getRuleContexts<UserAgentParser::SiteUrlContext>();
}

UserAgentParser::SiteUrlContext* UserAgentParser::CommentEntryContext::siteUrl(size_t i) {
  return getRuleContext<UserAgentParser::SiteUrlContext>(i);
}

std::vector<UserAgentParser::EmailAddressContext *> UserAgentParser::CommentEntryContext::emailAddress() {
  return getRuleContexts<UserAgentParser::EmailAddressContext>();
}

UserAgentParser::EmailAddressContext* UserAgentParser::CommentEntryContext::emailAddress(size_t i) {
  return getRuleContext<UserAgentParser::EmailAddressContext>(i);
}

std::vector<UserAgentParser::VersionWordsContext *> UserAgentParser::CommentEntryContext::versionWords() {
  return getRuleContexts<UserAgentParser::VersionWordsContext>();
}

UserAgentParser::VersionWordsContext* UserAgentParser::CommentEntryContext::versionWords(size_t i) {
  return getRuleContext<UserAgentParser::VersionWordsContext>(i);
}

std::vector<UserAgentParser::Base64Context *> UserAgentParser::CommentEntryContext::base64() {
  return getRuleContexts<UserAgentParser::Base64Context>();
}

UserAgentParser::Base64Context* UserAgentParser::CommentEntryContext::base64(size_t i) {
  return getRuleContext<UserAgentParser::Base64Context>(i);
}

std::vector<UserAgentParser::CommentBlockContext *> UserAgentParser::CommentEntryContext::commentBlock() {
  return getRuleContexts<UserAgentParser::CommentBlockContext>();
}

UserAgentParser::CommentBlockContext* UserAgentParser::CommentEntryContext::commentBlock(size_t i) {
  return getRuleContext<UserAgentParser::CommentBlockContext>(i);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentEntryContext::UNASSIGNEDVARIABLE() {
  return getTokens(UserAgentParser::UNASSIGNEDVARIABLE);
}

tree::TerminalNode* UserAgentParser::CommentEntryContext::UNASSIGNEDVARIABLE(size_t i) {
  return getToken(UserAgentParser::UNASSIGNEDVARIABLE, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::CommentEntryContext::MINUS() {
  return getTokens(UserAgentParser::MINUS);
}

tree::TerminalNode* UserAgentParser::CommentEntryContext::MINUS(size_t i) {
  return getToken(UserAgentParser::MINUS, i);
}


size_t UserAgentParser::CommentEntryContext::getRuleIndex() const {
  return UserAgentParser::RuleCommentEntry;
}

void UserAgentParser::CommentEntryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommentEntry(this);
}

void UserAgentParser::CommentEntryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommentEntry(this);
}


antlrcpp::Any UserAgentParser::CommentEntryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitCommentEntry(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::CommentEntryContext* UserAgentParser::commentEntry() {
  CommentEntryContext *_localctx = _tracker.createInstance<CommentEntryContext>(_ctx, getState());
  enterRule(_localctx, 46, UserAgentParser::RuleCommentEntry);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(813);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 146, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(728);
      emptyWord();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(783); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(732);
                _errHandler->sync(this);
                _la = _input->LA(1);
                while (_la == UserAgentParser::UNASSIGNEDVARIABLE) {
                  setState(729);
                  match(UserAgentParser::UNASSIGNEDVARIABLE);
                  setState(734);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                }
                setState(775);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 141, _ctx)) {
                case 1: {
                  setState(735);
                  commentProduct();
                  break;
                }

                case 2: {
                  setState(736);
                  keyValue();
                  break;
                }

                case 3: {
                  setState(737);
                  uuId();
                  break;
                }

                case 4: {
                  setState(738);
                  siteUrl();
                  break;
                }

                case 5: {
                  setState(739);
                  emailAddress();
                  break;
                }

                case 6: {
                  setState(740);
                  versionWords();
                  break;
                }

                case 7: {
                  setState(741);
                  base64();
                  break;
                }

                case 8: {
                  setState(742);
                  match(UserAgentParser::CURLYBRACEOPEN);
                  setState(743);
                  commentProduct();
                  setState(744);
                  match(UserAgentParser::CURLYBRACECLOSE);
                  break;
                }

                case 9: {
                  setState(746);
                  match(UserAgentParser::CURLYBRACEOPEN);
                  setState(747);
                  keyValue();
                  setState(748);
                  match(UserAgentParser::CURLYBRACECLOSE);
                  break;
                }

                case 10: {
                  setState(750);
                  match(UserAgentParser::CURLYBRACEOPEN);
                  setState(751);
                  uuId();
                  setState(752);
                  match(UserAgentParser::CURLYBRACECLOSE);
                  break;
                }

                case 11: {
                  setState(754);
                  match(UserAgentParser::CURLYBRACEOPEN);
                  setState(755);
                  siteUrl();
                  setState(756);
                  match(UserAgentParser::CURLYBRACECLOSE);
                  break;
                }

                case 12: {
                  setState(758);
                  match(UserAgentParser::CURLYBRACEOPEN);
                  setState(759);
                  emailAddress();
                  setState(760);
                  match(UserAgentParser::CURLYBRACECLOSE);
                  break;
                }

                case 13: {
                  setState(762);
                  match(UserAgentParser::CURLYBRACEOPEN);
                  setState(763);
                  multipleWords();
                  setState(764);
                  match(UserAgentParser::CURLYBRACECLOSE);
                  break;
                }

                case 14: {
                  setState(766);
                  match(UserAgentParser::CURLYBRACEOPEN);
                  setState(767);
                  versionWords();
                  setState(768);
                  match(UserAgentParser::CURLYBRACECLOSE);
                  break;
                }

                case 15: {
                  setState(770);
                  match(UserAgentParser::CURLYBRACEOPEN);
                  setState(771);
                  base64();
                  setState(772);
                  match(UserAgentParser::CURLYBRACECLOSE);
                  break;
                }

                case 16: {
                  setState(774);
                  commentBlock();
                  break;
                }

                }

                setState(780);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 142, _ctx);
                while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                  if (alt == 1) {
                    setState(777);
                    match(UserAgentParser::MINUS); 
                  }
                  setState(782);
                  _errHandler->sync(this);
                  alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 142, _ctx);
                }
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(785); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 143, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(798);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 144, _ctx)) {
      case 1: {
        setState(787);
        multipleWords();
        break;
      }

      case 2: {
        setState(788);
        productNameNoVersion();
        break;
      }

      case 3: {
        setState(789);
        keyWithoutValue();
        break;
      }

      case 4: {
        setState(790);
        match(UserAgentParser::CURLYBRACEOPEN);
        setState(791);
        productNameNoVersion();
        setState(792);
        match(UserAgentParser::CURLYBRACECLOSE);
        break;
      }

      case 5: {
        setState(794);
        match(UserAgentParser::CURLYBRACEOPEN);
        setState(795);
        keyWithoutValue();
        setState(796);
        match(UserAgentParser::CURLYBRACECLOSE);
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(811);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 145, _ctx)) {
      case 1: {
        setState(800);
        multipleWords();
        break;
      }

      case 2: {
        setState(801);
        productNameNoVersion();
        break;
      }

      case 3: {
        setState(802);
        keyWithoutValue();
        break;
      }

      case 4: {
        setState(803);
        match(UserAgentParser::CURLYBRACEOPEN);
        setState(804);
        productNameNoVersion();
        setState(805);
        match(UserAgentParser::CURLYBRACECLOSE);
        break;
      }

      case 5: {
        setState(807);
        match(UserAgentParser::CURLYBRACEOPEN);
        setState(808);
        keyWithoutValue();
        setState(809);
        match(UserAgentParser::CURLYBRACECLOSE);
        break;
      }

      }
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

//----------------- ProductNameKeyValueContext ------------------------------------------------------------------

UserAgentParser::ProductNameKeyValueContext::ProductNameKeyValueContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::KeyNameContext* UserAgentParser::ProductNameKeyValueContext::keyName() {
  return getRuleContext<UserAgentParser::KeyNameContext>(0);
}

std::vector<UserAgentParser::UuIdContext *> UserAgentParser::ProductNameKeyValueContext::uuId() {
  return getRuleContexts<UserAgentParser::UuIdContext>();
}

UserAgentParser::UuIdContext* UserAgentParser::ProductNameKeyValueContext::uuId(size_t i) {
  return getRuleContext<UserAgentParser::UuIdContext>(i);
}

std::vector<UserAgentParser::SiteUrlContext *> UserAgentParser::ProductNameKeyValueContext::siteUrl() {
  return getRuleContexts<UserAgentParser::SiteUrlContext>();
}

UserAgentParser::SiteUrlContext* UserAgentParser::ProductNameKeyValueContext::siteUrl(size_t i) {
  return getRuleContext<UserAgentParser::SiteUrlContext>(i);
}

std::vector<UserAgentParser::EmailAddressContext *> UserAgentParser::ProductNameKeyValueContext::emailAddress() {
  return getRuleContexts<UserAgentParser::EmailAddressContext>();
}

UserAgentParser::EmailAddressContext* UserAgentParser::ProductNameKeyValueContext::emailAddress(size_t i) {
  return getRuleContext<UserAgentParser::EmailAddressContext>(i);
}

std::vector<UserAgentParser::MultipleWordsContext *> UserAgentParser::ProductNameKeyValueContext::multipleWords() {
  return getRuleContexts<UserAgentParser::MultipleWordsContext>();
}

UserAgentParser::MultipleWordsContext* UserAgentParser::ProductNameKeyValueContext::multipleWords(size_t i) {
  return getRuleContext<UserAgentParser::MultipleWordsContext>(i);
}

std::vector<UserAgentParser::Base64Context *> UserAgentParser::ProductNameKeyValueContext::base64() {
  return getRuleContexts<UserAgentParser::Base64Context>();
}

UserAgentParser::Base64Context* UserAgentParser::ProductNameKeyValueContext::base64(size_t i) {
  return getRuleContext<UserAgentParser::Base64Context>(i);
}

std::vector<UserAgentParser::KeyValueProductVersionNameContext *> UserAgentParser::ProductNameKeyValueContext::keyValueProductVersionName() {
  return getRuleContexts<UserAgentParser::KeyValueProductVersionNameContext>();
}

UserAgentParser::KeyValueProductVersionNameContext* UserAgentParser::ProductNameKeyValueContext::keyValueProductVersionName(size_t i) {
  return getRuleContext<UserAgentParser::KeyValueProductVersionNameContext>(i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductNameKeyValueContext::COLON() {
  return getTokens(UserAgentParser::COLON);
}

tree::TerminalNode* UserAgentParser::ProductNameKeyValueContext::COLON(size_t i) {
  return getToken(UserAgentParser::COLON, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::ProductNameKeyValueContext::EQUALS() {
  return getTokens(UserAgentParser::EQUALS);
}

tree::TerminalNode* UserAgentParser::ProductNameKeyValueContext::EQUALS(size_t i) {
  return getToken(UserAgentParser::EQUALS, i);
}


size_t UserAgentParser::ProductNameKeyValueContext::getRuleIndex() const {
  return UserAgentParser::RuleProductNameKeyValue;
}

void UserAgentParser::ProductNameKeyValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductNameKeyValue(this);
}

void UserAgentParser::ProductNameKeyValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductNameKeyValue(this);
}


antlrcpp::Any UserAgentParser::ProductNameKeyValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductNameKeyValue(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductNameKeyValueContext* UserAgentParser::productNameKeyValue() {
  ProductNameKeyValueContext *_localctx = _tracker.createInstance<ProductNameKeyValueContext>(_ctx, getState());
  enterRule(_localctx, 48, UserAgentParser::RuleProductNameKeyValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(815);
    dynamic_cast<ProductNameKeyValueContext *>(_localctx)->key = keyName();
    setState(829); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(817); 
              _errHandler->sync(this);
              _la = _input->LA(1);
              do {
                setState(816);
                _la = _input->LA(1);
                if (!(_la == UserAgentParser::COLON

                || _la == UserAgentParser::EQUALS)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                setState(819); 
                _errHandler->sync(this);
                _la = _input->LA(1);
              } while (_la == UserAgentParser::COLON

              || _la == UserAgentParser::EQUALS);
              setState(827);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 148, _ctx)) {
              case 1: {
                setState(821);
                uuId();
                break;
              }

              case 2: {
                setState(822);
                siteUrl();
                break;
              }

              case 3: {
                setState(823);
                emailAddress();
                break;
              }

              case 4: {
                setState(824);
                multipleWords();
                break;
              }

              case 5: {
                setState(825);
                base64();
                break;
              }

              case 6: {
                setState(826);
                keyValueProductVersionName();
                break;
              }

              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(831); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 149, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProductNameNoVersionContext ------------------------------------------------------------------

UserAgentParser::ProductNameNoVersionContext::ProductNameNoVersionContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::ProductNameContext* UserAgentParser::ProductNameNoVersionContext::productName() {
  return getRuleContext<UserAgentParser::ProductNameContext>(0);
}

tree::TerminalNode* UserAgentParser::ProductNameNoVersionContext::SLASH() {
  return getToken(UserAgentParser::SLASH, 0);
}


size_t UserAgentParser::ProductNameNoVersionContext::getRuleIndex() const {
  return UserAgentParser::RuleProductNameNoVersion;
}

void UserAgentParser::ProductNameNoVersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProductNameNoVersion(this);
}

void UserAgentParser::ProductNameNoVersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProductNameNoVersion(this);
}


antlrcpp::Any UserAgentParser::ProductNameNoVersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitProductNameNoVersion(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::ProductNameNoVersionContext* UserAgentParser::productNameNoVersion() {
  ProductNameNoVersionContext *_localctx = _tracker.createInstance<ProductNameNoVersionContext>(_ctx, getState());
  enterRule(_localctx, 50, UserAgentParser::RuleProductNameNoVersion);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(833);
    productName();
    setState(834);
    match(UserAgentParser::SLASH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyValueProductVersionNameContext ------------------------------------------------------------------

UserAgentParser::KeyValueProductVersionNameContext::KeyValueProductVersionNameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::KeyValueProductVersionNameContext::VERSION() {
  return getToken(UserAgentParser::VERSION, 0);
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyValueProductVersionNameContext::SLASH() {
  return getTokens(UserAgentParser::SLASH);
}

tree::TerminalNode* UserAgentParser::KeyValueProductVersionNameContext::SLASH(size_t i) {
  return getToken(UserAgentParser::SLASH, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyValueProductVersionNameContext::WORD() {
  return getTokens(UserAgentParser::WORD);
}

tree::TerminalNode* UserAgentParser::KeyValueProductVersionNameContext::WORD(size_t i) {
  return getToken(UserAgentParser::WORD, i);
}


size_t UserAgentParser::KeyValueProductVersionNameContext::getRuleIndex() const {
  return UserAgentParser::RuleKeyValueProductVersionName;
}

void UserAgentParser::KeyValueProductVersionNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyValueProductVersionName(this);
}

void UserAgentParser::KeyValueProductVersionNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyValueProductVersionName(this);
}


antlrcpp::Any UserAgentParser::KeyValueProductVersionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitKeyValueProductVersionName(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::KeyValueProductVersionNameContext* UserAgentParser::keyValueProductVersionName() {
  KeyValueProductVersionNameContext *_localctx = _tracker.createInstance<KeyValueProductVersionNameContext>(_ctx, getState());
  enterRule(_localctx, 52, UserAgentParser::RuleKeyValueProductVersionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(845);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 151, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(836);
      match(UserAgentParser::VERSION);
      setState(841);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(837);
          match(UserAgentParser::SLASH);
          setState(838);
          match(UserAgentParser::WORD); 
        }
        setState(843);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 150, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(844);
      match(UserAgentParser::VERSION);
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

//----------------- KeyValueContext ------------------------------------------------------------------

UserAgentParser::KeyValueContext::KeyValueContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::KeyNameContext* UserAgentParser::KeyValueContext::keyName() {
  return getRuleContext<UserAgentParser::KeyNameContext>(0);
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyValueContext::COLON() {
  return getTokens(UserAgentParser::COLON);
}

tree::TerminalNode* UserAgentParser::KeyValueContext::COLON(size_t i) {
  return getToken(UserAgentParser::COLON, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyValueContext::EQUALS() {
  return getTokens(UserAgentParser::EQUALS);
}

tree::TerminalNode* UserAgentParser::KeyValueContext::EQUALS(size_t i) {
  return getToken(UserAgentParser::EQUALS, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyValueContext::CURLYBRACEOPEN() {
  return getTokens(UserAgentParser::CURLYBRACEOPEN);
}

tree::TerminalNode* UserAgentParser::KeyValueContext::CURLYBRACEOPEN(size_t i) {
  return getToken(UserAgentParser::CURLYBRACEOPEN, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyValueContext::CURLYBRACECLOSE() {
  return getTokens(UserAgentParser::CURLYBRACECLOSE);
}

tree::TerminalNode* UserAgentParser::KeyValueContext::CURLYBRACECLOSE(size_t i) {
  return getToken(UserAgentParser::CURLYBRACECLOSE, i);
}

std::vector<UserAgentParser::UuIdContext *> UserAgentParser::KeyValueContext::uuId() {
  return getRuleContexts<UserAgentParser::UuIdContext>();
}

UserAgentParser::UuIdContext* UserAgentParser::KeyValueContext::uuId(size_t i) {
  return getRuleContext<UserAgentParser::UuIdContext>(i);
}

std::vector<UserAgentParser::SiteUrlContext *> UserAgentParser::KeyValueContext::siteUrl() {
  return getRuleContexts<UserAgentParser::SiteUrlContext>();
}

UserAgentParser::SiteUrlContext* UserAgentParser::KeyValueContext::siteUrl(size_t i) {
  return getRuleContext<UserAgentParser::SiteUrlContext>(i);
}

std::vector<UserAgentParser::EmailAddressContext *> UserAgentParser::KeyValueContext::emailAddress() {
  return getRuleContexts<UserAgentParser::EmailAddressContext>();
}

UserAgentParser::EmailAddressContext* UserAgentParser::KeyValueContext::emailAddress(size_t i) {
  return getRuleContext<UserAgentParser::EmailAddressContext>(i);
}

std::vector<UserAgentParser::MultipleWordsContext *> UserAgentParser::KeyValueContext::multipleWords() {
  return getRuleContexts<UserAgentParser::MultipleWordsContext>();
}

UserAgentParser::MultipleWordsContext* UserAgentParser::KeyValueContext::multipleWords(size_t i) {
  return getRuleContext<UserAgentParser::MultipleWordsContext>(i);
}

std::vector<UserAgentParser::Base64Context *> UserAgentParser::KeyValueContext::base64() {
  return getRuleContexts<UserAgentParser::Base64Context>();
}

UserAgentParser::Base64Context* UserAgentParser::KeyValueContext::base64(size_t i) {
  return getRuleContext<UserAgentParser::Base64Context>(i);
}

std::vector<UserAgentParser::KeyValueVersionNameContext *> UserAgentParser::KeyValueContext::keyValueVersionName() {
  return getRuleContexts<UserAgentParser::KeyValueVersionNameContext>();
}

UserAgentParser::KeyValueVersionNameContext* UserAgentParser::KeyValueContext::keyValueVersionName(size_t i) {
  return getRuleContext<UserAgentParser::KeyValueVersionNameContext>(i);
}


size_t UserAgentParser::KeyValueContext::getRuleIndex() const {
  return UserAgentParser::RuleKeyValue;
}

void UserAgentParser::KeyValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyValue(this);
}

void UserAgentParser::KeyValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyValue(this);
}


antlrcpp::Any UserAgentParser::KeyValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitKeyValue(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::KeyValueContext* UserAgentParser::keyValue() {
  KeyValueContext *_localctx = _tracker.createInstance<KeyValueContext>(_ctx, getState());
  enterRule(_localctx, 54, UserAgentParser::RuleKeyValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(847);
    dynamic_cast<KeyValueContext *>(_localctx)->key = keyName();
    setState(874); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(849); 
              _errHandler->sync(this);
              _la = _input->LA(1);
              do {
                setState(848);
                _la = _input->LA(1);
                if (!(_la == UserAgentParser::COLON

                || _la == UserAgentParser::EQUALS)) {
                _errHandler->recoverInline(this);
                }
                else {
                  _errHandler->reportMatch(this);
                  consume();
                }
                setState(851); 
                _errHandler->sync(this);
                _la = _input->LA(1);
              } while (_la == UserAgentParser::COLON

              || _la == UserAgentParser::EQUALS);
              setState(872);
              _errHandler->sync(this);
              switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 155, _ctx)) {
              case 1: {
                setState(853);
                match(UserAgentParser::CURLYBRACEOPEN);
                setState(860);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 153, _ctx)) {
                case 1: {
                  setState(854);
                  uuId();
                  break;
                }

                case 2: {
                  setState(855);
                  siteUrl();
                  break;
                }

                case 3: {
                  setState(856);
                  emailAddress();
                  break;
                }

                case 4: {
                  setState(857);
                  multipleWords();
                  break;
                }

                case 5: {
                  setState(858);
                  base64();
                  break;
                }

                case 6: {
                  setState(859);
                  keyValueVersionName();
                  break;
                }

                }
                setState(862);
                match(UserAgentParser::CURLYBRACECLOSE);
                break;
              }

              case 2: {
                setState(870);
                _errHandler->sync(this);
                switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 154, _ctx)) {
                case 1: {
                  setState(864);
                  uuId();
                  break;
                }

                case 2: {
                  setState(865);
                  siteUrl();
                  break;
                }

                case 3: {
                  setState(866);
                  emailAddress();
                  break;
                }

                case 4: {
                  setState(867);
                  multipleWords();
                  break;
                }

                case 5: {
                  setState(868);
                  base64();
                  break;
                }

                case 6: {
                  setState(869);
                  keyValueVersionName();
                  break;
                }

                }
                break;
              }

              }
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(876); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 156, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyWithoutValueContext ------------------------------------------------------------------

UserAgentParser::KeyWithoutValueContext::KeyWithoutValueContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

UserAgentParser::KeyNameContext* UserAgentParser::KeyWithoutValueContext::keyName() {
  return getRuleContext<UserAgentParser::KeyNameContext>(0);
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyWithoutValueContext::COLON() {
  return getTokens(UserAgentParser::COLON);
}

tree::TerminalNode* UserAgentParser::KeyWithoutValueContext::COLON(size_t i) {
  return getToken(UserAgentParser::COLON, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyWithoutValueContext::EQUALS() {
  return getTokens(UserAgentParser::EQUALS);
}

tree::TerminalNode* UserAgentParser::KeyWithoutValueContext::EQUALS(size_t i) {
  return getToken(UserAgentParser::EQUALS, i);
}


size_t UserAgentParser::KeyWithoutValueContext::getRuleIndex() const {
  return UserAgentParser::RuleKeyWithoutValue;
}

void UserAgentParser::KeyWithoutValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyWithoutValue(this);
}

void UserAgentParser::KeyWithoutValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyWithoutValue(this);
}


antlrcpp::Any UserAgentParser::KeyWithoutValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitKeyWithoutValue(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::KeyWithoutValueContext* UserAgentParser::keyWithoutValue() {
  KeyWithoutValueContext *_localctx = _tracker.createInstance<KeyWithoutValueContext>(_ctx, getState());
  enterRule(_localctx, 56, UserAgentParser::RuleKeyWithoutValue);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(878);
    dynamic_cast<KeyWithoutValueContext *>(_localctx)->key = keyName();
    setState(880); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(879);
      _la = _input->LA(1);
      if (!(_la == UserAgentParser::COLON

      || _la == UserAgentParser::EQUALS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(882); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == UserAgentParser::COLON

    || _la == UserAgentParser::EQUALS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyValueVersionNameContext ------------------------------------------------------------------

UserAgentParser::KeyValueVersionNameContext::KeyValueVersionNameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::KeyValueVersionNameContext::VERSION() {
  return getToken(UserAgentParser::VERSION, 0);
}


size_t UserAgentParser::KeyValueVersionNameContext::getRuleIndex() const {
  return UserAgentParser::RuleKeyValueVersionName;
}

void UserAgentParser::KeyValueVersionNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyValueVersionName(this);
}

void UserAgentParser::KeyValueVersionNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyValueVersionName(this);
}


antlrcpp::Any UserAgentParser::KeyValueVersionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitKeyValueVersionName(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::KeyValueVersionNameContext* UserAgentParser::keyValueVersionName() {
  KeyValueVersionNameContext *_localctx = _tracker.createInstance<KeyValueVersionNameContext>(_ctx, getState());
  enterRule(_localctx, 58, UserAgentParser::RuleKeyValueVersionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(884);
    match(UserAgentParser::VERSION);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyNameContext ------------------------------------------------------------------

UserAgentParser::KeyNameContext::KeyNameContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyNameContext::WORD() {
  return getTokens(UserAgentParser::WORD);
}

tree::TerminalNode* UserAgentParser::KeyNameContext::WORD(size_t i) {
  return getToken(UserAgentParser::WORD, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::KeyNameContext::MINUS() {
  return getTokens(UserAgentParser::MINUS);
}

tree::TerminalNode* UserAgentParser::KeyNameContext::MINUS(size_t i) {
  return getToken(UserAgentParser::MINUS, i);
}

tree::TerminalNode* UserAgentParser::KeyNameContext::VERSION() {
  return getToken(UserAgentParser::VERSION, 0);
}


size_t UserAgentParser::KeyNameContext::getRuleIndex() const {
  return UserAgentParser::RuleKeyName;
}

void UserAgentParser::KeyNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyName(this);
}

void UserAgentParser::KeyNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyName(this);
}


antlrcpp::Any UserAgentParser::KeyNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitKeyName(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::KeyNameContext* UserAgentParser::keyName() {
  KeyNameContext *_localctx = _tracker.createInstance<KeyNameContext>(_ctx, getState());
  enterRule(_localctx, 60, UserAgentParser::RuleKeyName);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(895);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::WORD: {
        enterOuterAlt(_localctx, 1);
        setState(886);
        match(UserAgentParser::WORD);
        setState(891);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == UserAgentParser::MINUS) {
          setState(887);
          match(UserAgentParser::MINUS);
          setState(888);
          match(UserAgentParser::WORD);
          setState(893);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case UserAgentParser::VERSION: {
        enterOuterAlt(_localctx, 2);
        setState(894);
        match(UserAgentParser::VERSION);
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

//----------------- EmptyWordContext ------------------------------------------------------------------

UserAgentParser::EmptyWordContext::EmptyWordContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentParser::EmptyWordContext::MINUS() {
  return getToken(UserAgentParser::MINUS, 0);
}


size_t UserAgentParser::EmptyWordContext::getRuleIndex() const {
  return UserAgentParser::RuleEmptyWord;
}

void UserAgentParser::EmptyWordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyWord(this);
}

void UserAgentParser::EmptyWordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyWord(this);
}


antlrcpp::Any UserAgentParser::EmptyWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitEmptyWord(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::EmptyWordContext* UserAgentParser::emptyWord() {
  EmptyWordContext *_localctx = _tracker.createInstance<EmptyWordContext>(_ctx, getState());
  enterRule(_localctx, 62, UserAgentParser::RuleEmptyWord);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(899);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::EOF:
      case UserAgentParser::BRACECLOSE:
      case UserAgentParser::BLOCKCLOSE:
      case UserAgentParser::SEMICOLON:
      case UserAgentParser::COMMA: {
        enterOuterAlt(_localctx, 1);

        break;
      }

      case UserAgentParser::MINUS: {
        enterOuterAlt(_localctx, 2);
        setState(898);
        match(UserAgentParser::MINUS);
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

//----------------- MultipleWordsContext ------------------------------------------------------------------

UserAgentParser::MultipleWordsContext::MultipleWordsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> UserAgentParser::MultipleWordsContext::WORD() {
  return getTokens(UserAgentParser::WORD);
}

tree::TerminalNode* UserAgentParser::MultipleWordsContext::WORD(size_t i) {
  return getToken(UserAgentParser::WORD, i);
}

std::vector<tree::TerminalNode *> UserAgentParser::MultipleWordsContext::MINUS() {
  return getTokens(UserAgentParser::MINUS);
}

tree::TerminalNode* UserAgentParser::MultipleWordsContext::MINUS(size_t i) {
  return getToken(UserAgentParser::MINUS, i);
}

tree::TerminalNode* UserAgentParser::MultipleWordsContext::GIBBERISH() {
  return getToken(UserAgentParser::GIBBERISH, 0);
}

tree::TerminalNode* UserAgentParser::MultipleWordsContext::UNASSIGNEDVARIABLE() {
  return getToken(UserAgentParser::UNASSIGNEDVARIABLE, 0);
}


size_t UserAgentParser::MultipleWordsContext::getRuleIndex() const {
  return UserAgentParser::RuleMultipleWords;
}

void UserAgentParser::MultipleWordsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultipleWords(this);
}

void UserAgentParser::MultipleWordsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultipleWords(this);
}


antlrcpp::Any UserAgentParser::MultipleWordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitMultipleWords(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::MultipleWordsContext* UserAgentParser::multipleWords() {
  MultipleWordsContext *_localctx = _tracker.createInstance<MultipleWordsContext>(_ctx, getState());
  enterRule(_localctx, 64, UserAgentParser::RuleMultipleWords);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(933);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 166, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(908); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(904);
                _errHandler->sync(this);
                _la = _input->LA(1);
                while (_la == UserAgentParser::MINUS) {
                  setState(901);
                  match(UserAgentParser::MINUS);
                  setState(906);
                  _errHandler->sync(this);
                  _la = _input->LA(1);
                }
                setState(907);
                match(UserAgentParser::WORD);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(910); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 162, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(915);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(912);
          match(UserAgentParser::MINUS); 
        }
        setState(917);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 163, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(921);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == UserAgentParser::WORD) {
        setState(918);
        match(UserAgentParser::WORD);
        setState(923);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(924);
      match(UserAgentParser::GIBBERISH);
      setState(928);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(925);
          match(UserAgentParser::WORD); 
        }
        setState(930);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 165, _ctx);
      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(931);
      match(UserAgentParser::MINUS);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(932);
      match(UserAgentParser::UNASSIGNEDVARIABLE);
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

//----------------- VersionWordsContext ------------------------------------------------------------------

UserAgentParser::VersionWordsContext::VersionWordsContext(ParserRuleContext *parent, size_t invokingState)
  : antlr4::ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> UserAgentParser::VersionWordsContext::VERSION() {
  return getTokens(UserAgentParser::VERSION);
}

tree::TerminalNode* UserAgentParser::VersionWordsContext::VERSION(size_t i) {
  return getToken(UserAgentParser::VERSION, i);
}

tree::TerminalNode* UserAgentParser::VersionWordsContext::SPECIALVERSIONWORDS() {
  return getToken(UserAgentParser::SPECIALVERSIONWORDS, 0);
}


size_t UserAgentParser::VersionWordsContext::getRuleIndex() const {
  return UserAgentParser::RuleVersionWords;
}

void UserAgentParser::VersionWordsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVersionWords(this);
}

void UserAgentParser::VersionWordsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVersionWords(this);
}


antlrcpp::Any UserAgentParser::VersionWordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentVisitor*>(visitor))
    return parserVisitor->visitVersionWords(this);
  else
    return visitor->visitChildren(this);
}

UserAgentParser::VersionWordsContext* UserAgentParser::versionWords() {
  VersionWordsContext *_localctx = _tracker.createInstance<VersionWordsContext>(_ctx, getState());
  enterRule(_localctx, 66, UserAgentParser::RuleVersionWords);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(941);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentParser::VERSION: {
        enterOuterAlt(_localctx, 1);
        setState(936); 
        _errHandler->sync(this);
        alt = 1;
        do {
          switch (alt) {
            case 1: {
                  setState(935);
                  match(UserAgentParser::VERSION);
                  break;
                }

          default:
            throw NoViableAltException(this);
          }
          setState(938); 
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 167, _ctx);
        } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
        break;
      }

      case UserAgentParser::SPECIALVERSIONWORDS: {
        enterOuterAlt(_localctx, 2);
        setState(940);
        match(UserAgentParser::SPECIALVERSIONWORDS);
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

// Static vars and initialization.
std::vector<dfa::DFA> UserAgentParser::_decisionToDFA;
atn::PredictionContextCache UserAgentParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN UserAgentParser::_atn;
std::vector<uint16_t> UserAgentParser::_serializedATN;

std::vector<std::string> UserAgentParser::_ruleNames = {
  "userAgent", "rootElements", "rootText", "product", "commentProduct", 
  "productVersionWords", "productName", "productNameWords", "productVersion", 
  "productVersionWithCommas", "productVersionSingleWord", "singleVersion", 
  "singleVersionWithCommas", "productNameVersion", "productNameEmail", "productNameUrl", 
  "productNameUuid", "uuId", "emailAddress", "siteUrl", "base64", "commentSeparator", 
  "commentBlock", "commentEntry", "productNameKeyValue", "productNameNoVersion", 
  "keyValueProductVersionName", "keyValue", "keyWithoutValue", "keyValueVersionName", 
  "keyName", "emptyWord", "multipleWords", "versionWords"
};

std::vector<std::string> UserAgentParser::_literalNames = {
  "", "'\\'", "'\\\"'", "'\"'", "'\\\\'", "'''", "'\\t'", "'application/json'", 
  "'*/*'", "", "", "", "", "'{'", "'}'", "'('", "')'", "'['", "']'", "';'", 
  "':'", "','", "'/'", "'='", "'-'", "'+'", "", "", "", "", "", "'@'"
};

std::vector<std::string> UserAgentParser::_symbolicNames = {
  "", "", "QUOTE1", "QUOTE2", "QUOTE3", "QUOTE4", "BAD_ESC_TAB", "MIME_TYPE_1", 
  "MIME_TYPE_2", "SPACE", "USERAGENT1", "USERAGENT2", "EMAIL", "CURLYBRACEOPEN", 
  "CURLYBRACECLOSE", "BRACEOPEN", "BRACECLOSE", "BLOCKOPEN", "BLOCKCLOSE", 
  "SEMICOLON", "COLON", "COMMA", "SLASH", "EQUALS", "MINUS", "PLUS", "UUID", 
  "URL", "SPECIALVERSIONWORDS", "UNASSIGNEDVARIABLE", "GIBBERISH", "ATSIGN", 
  "VERSION", "WORD", "BASE64"
};

dfa::Vocabulary UserAgentParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> UserAgentParser::_tokenNames;

UserAgentParser::Initializer::Initializer() {
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
    0x3, 0x24, 0x3b2, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x3, 0x2, 0x7, 0x2, 0x48, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x4b, 0xb, 0x2, 0x3, 0x2, 0x5, 0x2, 0x4e, 0xa, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x52, 0xa, 0x2, 0x7, 0x2, 0x54, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x57, 0xb, 0x2, 0x3, 0x2, 0x7, 0x2, 0x5a, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x5d, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x64, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x6, 0x4, 
    0x68, 0xa, 0x4, 0xd, 0x4, 0xe, 0x4, 0x69, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x6e, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x72, 0xa, 0x5, 0xd, 0x5, 
    0xe, 0x5, 0x73, 0x3, 0x5, 0x5, 0x5, 0x77, 0xa, 0x5, 0x3, 0x5, 0x6, 0x5, 
    0x7a, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x7b, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x80, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x83, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x87, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x8a, 0xa, 0x5, 0x7, 0x5, 
    0x8c, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x8f, 0xb, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x92, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x95, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x6, 0x5, 0x99, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x9a, 0x3, 0x5, 0x5, 0x5, 
    0x9e, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xa2, 0xa, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0xa5, 0xa, 0x5, 0x7, 0x5, 0xa7, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 
    0xaa, 0xb, 0x5, 0x7, 0x5, 0xac, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xaf, 
    0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xb3, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0xb7, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0xba, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x6, 0x5, 0xbe, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0xbf, 0x3, 
    0x5, 0x5, 0x5, 0xc3, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xc7, 0xa, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0xca, 0xa, 0x5, 0x7, 0x5, 0xcc, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0xcf, 0xb, 0x5, 0x6, 0x5, 0xd1, 0xa, 0x5, 0xd, 0x5, 0xe, 
    0x5, 0xd2, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xd7, 0xa, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0xdb, 0xa, 0x5, 0x3, 0x5, 0x6, 0x5, 0xde, 0xa, 0x5, 0xd, 
    0x5, 0xe, 0x5, 0xdf, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xe4, 0xa, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x7, 0x5, 0xe8, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0xeb, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xef, 0xa, 0x5, 0x7, 0x5, 0xf1, 0xa, 
    0x5, 0xc, 0x5, 0xe, 0x5, 0xf4, 0xb, 0x5, 0x3, 0x5, 0x5, 0x5, 0xf7, 0xa, 
    0x5, 0x3, 0x5, 0x5, 0x5, 0xfa, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0xfd, 0xa, 
    0x5, 0x6, 0x5, 0xff, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x100, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x105, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x109, 
    0xa, 0x5, 0x3, 0x5, 0x6, 0x5, 0x10c, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0x10d, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x112, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x115, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x119, 0xa, 0x5, 0x3, 0x5, 0x5, 
    0x5, 0x11c, 0xa, 0x5, 0x6, 0x5, 0x11e, 0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 
    0x11f, 0x3, 0x5, 0x5, 0x5, 0x123, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x126, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0x12a, 0xa, 0x5, 0xd, 0x5, 0xe, 
    0x5, 0x12b, 0x3, 0x5, 0x5, 0x5, 0x12f, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x133, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x136, 0xa, 0x5, 0x7, 
    0x5, 0x138, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x13b, 0xb, 0x5, 0x7, 0x5, 
    0x13d, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x140, 0xb, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x144, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x5, 0x5, 0x14a, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x14e, 0xa, 
    0x6, 0xd, 0x6, 0xe, 0x6, 0x14f, 0x3, 0x6, 0x6, 0x6, 0x153, 0xa, 0x6, 
    0xd, 0x6, 0xe, 0x6, 0x154, 0x3, 0x6, 0x5, 0x6, 0x158, 0xa, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x15c, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x15f, 
    0xa, 0x6, 0x7, 0x6, 0x161, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x164, 0xb, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x167, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x16a, 
    0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x16e, 0xa, 0x6, 0xd, 0x6, 0xe, 
    0x6, 0x16f, 0x3, 0x6, 0x5, 0x6, 0x173, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0x177, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x17a, 0xa, 0x6, 0x7, 
    0x6, 0x17c, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x17f, 0xb, 0x6, 0x7, 0x6, 
    0x181, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x184, 0xb, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x188, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x18b, 0xa, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x18f, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x190, 
    0x3, 0x6, 0x5, 0x6, 0x194, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x198, 
    0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x19b, 0xa, 0x6, 0x7, 0x6, 0x19d, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x1a0, 0xb, 0x6, 0x6, 0x6, 0x1a2, 0xa, 0x6, 
    0xd, 0x6, 0xe, 0x6, 0x1a3, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x1a8, 0xa, 
    0x6, 0x3, 0x6, 0x6, 0x6, 0x1ab, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x1ac, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x1b1, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 
    0x6, 0x1b5, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x1b8, 0xb, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x5, 0x6, 0x1bc, 0xa, 0x6, 0x7, 0x6, 0x1be, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x1c1, 0xb, 0x6, 0x6, 0x6, 0x1c3, 0xa, 0x6, 0xd, 0x6, 
    0xe, 0x6, 0x1c4, 0x3, 0x6, 0x5, 0x6, 0x1c8, 0xa, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x6, 0x6, 0x1cc, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x1cd, 0x3, 0x6, 
    0x5, 0x6, 0x1d1, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x1d5, 0xa, 
    0x6, 0x3, 0x6, 0x5, 0x6, 0x1d8, 0xa, 0x6, 0x7, 0x6, 0x1da, 0xa, 0x6, 
    0xc, 0x6, 0xe, 0x6, 0x1dd, 0xb, 0x6, 0x7, 0x6, 0x1df, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x1e2, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 0x6, 0x1e6, 
    0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x1e7, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x1ec, 
    0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0x1ef, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0x1f3, 0xa, 0x6, 0x6, 0x6, 0x1f5, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 
    0x1f6, 0x3, 0x6, 0x5, 0x6, 0x1fa, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x6, 
    0x6, 0x1fe, 0xa, 0x6, 0xd, 0x6, 0xe, 0x6, 0x1ff, 0x3, 0x6, 0x5, 0x6, 
    0x203, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x207, 0xa, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x20a, 0xa, 0x6, 0x7, 0x6, 0x20c, 0xa, 0x6, 0xc, 0x6, 
    0xe, 0x6, 0x20f, 0xb, 0x6, 0x7, 0x6, 0x211, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x214, 0xb, 0x6, 0x5, 0x6, 0x216, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0x21a, 0xa, 0x7, 0x3, 0x7, 0x7, 0x7, 0x21d, 0xa, 0x7, 0xc, 
    0x7, 0xe, 0x7, 0x220, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x224, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x5, 0x8, 0x22c, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x230, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0x233, 0xb, 0x9, 0x3, 0x9, 0x7, 0x9, 0x236, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x239, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 
    0x9, 0x23d, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x240, 0xb, 0x9, 0x3, 0x9, 
    0x7, 0x9, 0x243, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x246, 0xb, 0x9, 0x5, 
    0x9, 0x248, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x24d, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x250, 0xb, 0x9, 0x3, 0x9, 0x7, 0x9, 0x253, 
    0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x256, 0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x7, 0x9, 0x25b, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x25e, 0xb, 0x9, 
    0x3, 0x9, 0x7, 0x9, 0x261, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x264, 0xb, 
    0x9, 0x5, 0x9, 0x266, 0xa, 0x9, 0x5, 0x9, 0x268, 0xa, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0x271, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x27e, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x281, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0x285, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0x28b, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 
    0xe, 0x292, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x295, 0xb, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x5, 0xf, 0x299, 0xa, 0xf, 0x3, 0xf, 0x7, 0xf, 0x29c, 0xa, 
    0xf, 0xc, 0xf, 0xe, 0xf, 0x29f, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x3, 0x13, 0x5, 0x13, 0x2ab, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0x2b1, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
    0x3, 0x15, 0x5, 0x15, 0x2b7, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x5, 0x16, 0x2bd, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x2c6, 0xa, 0x18, 
    0xc, 0x18, 0xe, 0x18, 0x2c9, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x2d2, 0xa, 0x18, 
    0xc, 0x18, 0xe, 0x18, 0x2d5, 0xb, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 0x18, 
    0x2d9, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x7, 0x19, 0x2dd, 0xa, 0x19, 
    0xc, 0x19, 0xe, 0x19, 0x2e0, 0xb, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x30a, 
    0xa, 0x19, 0x3, 0x19, 0x7, 0x19, 0x30d, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 
    0x310, 0xb, 0x19, 0x6, 0x19, 0x312, 0xa, 0x19, 0xd, 0x19, 0xe, 0x19, 
    0x313, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x321, 
    0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 
    0x32e, 0xa, 0x19, 0x5, 0x19, 0x330, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x6, 0x1a, 0x334, 0xa, 0x1a, 0xd, 0x1a, 0xe, 0x1a, 0x335, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x33e, 
    0xa, 0x1a, 0x6, 0x1a, 0x340, 0xa, 0x1a, 0xd, 0x1a, 0xe, 0x1a, 0x341, 
    0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 
    0x1c, 0x34a, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x34d, 0xb, 0x1c, 0x3, 
    0x1c, 0x5, 0x1c, 0x350, 0xa, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x6, 0x1d, 
    0x354, 0xa, 0x1d, 0xd, 0x1d, 0xe, 0x1d, 0x355, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x35f, 
    0xa, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 
    0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x369, 0xa, 0x1d, 0x5, 0x1d, 
    0x36b, 0xa, 0x1d, 0x6, 0x1d, 0x36d, 0xa, 0x1d, 0xd, 0x1d, 0xe, 0x1d, 
    0x36e, 0x3, 0x1e, 0x3, 0x1e, 0x6, 0x1e, 0x373, 0xa, 0x1e, 0xd, 0x1e, 
    0xe, 0x1e, 0x374, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x7, 0x20, 0x37c, 0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x37f, 0xb, 0x20, 
    0x3, 0x20, 0x5, 0x20, 0x382, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 
    0x386, 0xa, 0x21, 0x3, 0x22, 0x7, 0x22, 0x389, 0xa, 0x22, 0xc, 0x22, 
    0xe, 0x22, 0x38c, 0xb, 0x22, 0x3, 0x22, 0x6, 0x22, 0x38f, 0xa, 0x22, 
    0xd, 0x22, 0xe, 0x22, 0x390, 0x3, 0x22, 0x7, 0x22, 0x394, 0xa, 0x22, 
    0xc, 0x22, 0xe, 0x22, 0x397, 0xb, 0x22, 0x3, 0x22, 0x7, 0x22, 0x39a, 
    0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x39d, 0xb, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x7, 0x22, 0x3a1, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x3a4, 0xb, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x3a8, 0xa, 0x22, 0x3, 0x23, 0x6, 0x23, 
    0x3ab, 0xa, 0x23, 0xd, 0x23, 0xe, 0x23, 0x3ac, 0x3, 0x23, 0x5, 0x23, 
    0x3b0, 0xa, 0x23, 0x3, 0x23, 0x2, 0x2, 0x24, 0x2, 0x4, 0x6, 0x8, 0xa, 
    0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
    0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 
    0x3c, 0x3e, 0x40, 0x42, 0x44, 0x2, 0xc, 0xa, 0x2, 0x3, 0x3, 0x5, 0x5, 
    0x7, 0x7, 0x11, 0x11, 0x13, 0x13, 0x15, 0x15, 0x17, 0x17, 0x19, 0x1b, 
    0x5, 0x2, 0x15, 0x15, 0x17, 0x17, 0x1a, 0x1a, 0x9, 0x2, 0x3, 0x3, 0x5, 
    0x5, 0x7, 0x7, 0x12, 0x12, 0x14, 0x15, 0x17, 0x17, 0x19, 0x1b, 0x4, 
    0x2, 0x18, 0x18, 0x21, 0x21, 0x4, 0x2, 0x15, 0x15, 0x1a, 0x1a, 0x4, 
    0x2, 0x17, 0x17, 0x1a, 0x1a, 0x4, 0x2, 0x15, 0x15, 0x17, 0x17, 0x3, 
    0x3, 0x12, 0x12, 0x3, 0x3, 0x14, 0x14, 0x4, 0x2, 0x16, 0x16, 0x19, 0x19, 
    0x2, 0x47b, 0x2, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x8, 0x149, 0x3, 0x2, 0x2, 0x2, 
    0xa, 0x215, 0x3, 0x2, 0x2, 0x2, 0xc, 0x223, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x22b, 0x3, 0x2, 0x2, 0x2, 0x10, 0x267, 0x3, 0x2, 0x2, 0x2, 0x12, 0x270, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x284, 0x3, 0x2, 0x2, 0x2, 0x16, 0x28a, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x28c, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x28e, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x296, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x2a0, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x2a2, 0x3, 0x2, 0x2, 0x2, 0x22, 0x2a4, 0x3, 0x2, 0x2, 0x2, 
    0x24, 0x2aa, 0x3, 0x2, 0x2, 0x2, 0x26, 0x2b0, 0x3, 0x2, 0x2, 0x2, 0x28, 
    0x2b6, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x2bc, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2be, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x2d8, 0x3, 0x2, 0x2, 0x2, 0x30, 0x32f, 0x3, 
    0x2, 0x2, 0x2, 0x32, 0x331, 0x3, 0x2, 0x2, 0x2, 0x34, 0x343, 0x3, 0x2, 
    0x2, 0x2, 0x36, 0x34f, 0x3, 0x2, 0x2, 0x2, 0x38, 0x351, 0x3, 0x2, 0x2, 
    0x2, 0x3a, 0x370, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x376, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x381, 0x3, 0x2, 0x2, 0x2, 0x40, 0x385, 0x3, 0x2, 0x2, 0x2, 0x42, 
    0x3a7, 0x3, 0x2, 0x2, 0x2, 0x44, 0x3af, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 
    0x9, 0x2, 0x2, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x55, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x4c, 0x4e, 0x9, 0x3, 0x2, 0x2, 0x4d, 0x4c, 0x3, 0x2, 0x2, 0x2, 
    0x4d, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 
    0x52, 0x5, 0x8, 0x5, 0x2, 0x50, 0x52, 0x5, 0x4, 0x3, 0x2, 0x51, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0x51, 0x50, 0x3, 0x2, 0x2, 0x2, 0x52, 0x54, 0x3, 
    0x2, 0x2, 0x2, 0x53, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x54, 0x57, 0x3, 0x2, 
    0x2, 0x2, 0x55, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x56, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x58, 0x5a, 0x9, 0x4, 0x2, 0x2, 0x59, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5c, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x3, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5b, 0x3, 
    0x2, 0x2, 0x2, 0x5e, 0x64, 0x5, 0x38, 0x1d, 0x2, 0x5f, 0x64, 0x5, 0x28, 
    0x15, 0x2, 0x60, 0x64, 0x5, 0x26, 0x14, 0x2, 0x61, 0x64, 0x5, 0x24, 
    0x13, 0x2, 0x62, 0x64, 0x5, 0x6, 0x4, 0x2, 0x63, 0x5e, 0x3, 0x2, 0x2, 
    0x2, 0x63, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x63, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 0x62, 0x3, 0x2, 0x2, 0x2, 0x64, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x65, 0x6e, 0x7, 0x22, 0x2, 0x2, 0x66, 0x68, 
    0x7, 0x23, 0x2, 0x2, 0x67, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 0x7, 0x20, 0x2, 
    0x2, 0x6c, 0x6e, 0x7, 0x1a, 0x2, 0x2, 0x6d, 0x65, 0x3, 0x2, 0x2, 0x2, 
    0x6d, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6c, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x71, 
    0x5, 0xe, 0x8, 0x2, 0x70, 0x72, 0x5, 0x12, 0xa, 0x2, 0x71, 0x70, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x73, 0x3, 0x2, 0x2, 0x2, 0x73, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x73, 0x74, 0x3, 0x2, 0x2, 0x2, 0x74, 0x8d, 0x3, 0x2, 0x2, 
    0x2, 0x75, 0x77, 0x7, 0x16, 0x2, 0x2, 0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x7a, 0x7, 0x18, 0x2, 0x2, 0x79, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x80, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x80, 0x7, 0x1a, 
    0x2, 0x2, 0x7e, 0x80, 0x7, 0x21, 0x2, 0x2, 0x7f, 0x79, 0x3, 0x2, 0x2, 
    0x2, 0x7f, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7e, 0x3, 0x2, 0x2, 0x2, 
    0x80, 0x82, 0x3, 0x2, 0x2, 0x2, 0x81, 0x83, 0x7, 0x19, 0x2, 0x2, 0x82, 
    0x81, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x87, 0x5, 0x14, 0xb, 0x2, 0x85, 0x87, 0x5, 
    0x16, 0xc, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 0x2, 0x86, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x87, 0x89, 0x3, 0x2, 0x2, 0x2, 0x88, 0x8a, 0x7, 0x17, 0x2, 
    0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x8a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x76, 0x3, 0x2, 0x2, 0x2, 0x8c, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x8e, 0xad, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x90, 0x92, 0x9, 0x5, 0x2, 0x2, 0x91, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x94, 0x3, 0x2, 0x2, 
    0x2, 0x93, 0x95, 0x9, 0x6, 0x2, 0x2, 0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 
    0x94, 0x95, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0xa8, 0x5, 0x2e, 0x18, 0x2, 0x97, 0x99, 0x9, 0x5, 0x2, 0x2, 0x98, 0x97, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 
    0x2, 0x2, 0x2, 0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9d, 0x3, 0x2, 
    0x2, 0x2, 0x9c, 0x9e, 0x7, 0x19, 0x2, 0x2, 0x9d, 0x9c, 0x3, 0x2, 0x2, 
    0x2, 0x9d, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0xa2, 0x5, 0x14, 0xb, 0x2, 0xa0, 0xa2, 0x5, 0x16, 0xc, 0x2, 0xa1, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa4, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0xa5, 0x7, 0x17, 0x2, 0x2, 0xa4, 0xa3, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa7, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0x98, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xaa, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 
    0xa9, 0xac, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xab, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 
    0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb2, 0x3, 
    0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x7, 0x18, 
    0x2, 0x2, 0xb1, 0xb3, 0x7, 0x2, 0x2, 0x3, 0xb2, 0xb0, 0x3, 0x2, 0x2, 
    0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0x14a, 0x3, 0x2, 0x2, 0x2, 
    0xb4, 0xd0, 0x5, 0xe, 0x8, 0x2, 0xb5, 0xb7, 0x9, 0x5, 0x2, 0x2, 0xb6, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb9, 
    0x3, 0x2, 0x2, 0x2, 0xb8, 0xba, 0x9, 0x6, 0x2, 0x2, 0xb9, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0xb9, 0xba, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0xbb, 0xcd, 0x5, 0x2e, 0x18, 0x2, 0xbc, 0xbe, 0x9, 0x5, 0x2, 
    0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x3, 0x2, 0x2, 0x2, 
    0xbf, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 
    0xc2, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc3, 0x7, 0x19, 0x2, 0x2, 0xc2, 0xc1, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc6, 0x3, 
    0x2, 0x2, 0x2, 0xc4, 0xc7, 0x5, 0x14, 0xb, 0x2, 0xc5, 0xc7, 0x5, 0x16, 
    0xc, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xca, 0x7, 0x17, 0x2, 0x2, 
    0xc9, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 
    0xcc, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcf, 
    0x3, 0x2, 0x2, 0x2, 0xcd, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0x3, 
    0x2, 0x2, 0x2, 0xce, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcd, 0x3, 0x2, 
    0x2, 0x2, 0xd0, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 
    0x2, 0xd2, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0x3, 0x2, 0x2, 0x2, 
    0xd3, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x18, 0x2, 0x2, 0xd5, 
    0xd7, 0x7, 0x2, 0x2, 0x3, 0xd6, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 
    0x3, 0x2, 0x2, 0x2, 0xd7, 0x14a, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xfe, 0x5, 
    0xe, 0x8, 0x2, 0xd9, 0xdb, 0x7, 0x16, 0x2, 0x2, 0xda, 0xd9, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xe3, 0x3, 0x2, 0x2, 
    0x2, 0xdc, 0xde, 0x7, 0x18, 0x2, 0x2, 0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 
    0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 
    0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe4, 
    0x7, 0x1a, 0x2, 0x2, 0xe2, 0xe4, 0x7, 0x21, 0x2, 0x2, 0xe3, 0xdd, 0x3, 
    0x2, 0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe2, 0x3, 0x2, 
    0x2, 0x2, 0xe4, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xf2, 0x5, 0xc, 0x7, 
    0x2, 0xe6, 0xe8, 0x9, 0x5, 0x2, 0x2, 0xe7, 0xe6, 0x3, 0x2, 0x2, 0x2, 
    0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe9, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0xec, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0xec, 0xee, 0x5, 0x14, 0xb, 0x2, 0xed, 0xef, 0x7, 
    0x17, 0x2, 0x2, 0xee, 0xed, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x3, 0x2, 
    0x2, 0x2, 0xef, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xe9, 0x3, 0x2, 0x2, 
    0x2, 0xf1, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 
    0xf2, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf4, 
    0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf7, 0x9, 0x5, 0x2, 0x2, 0xf6, 0xf5, 
    0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf9, 0x3, 
    0x2, 0x2, 0x2, 0xf8, 0xfa, 0x9, 0x6, 0x2, 0x2, 0xf9, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0xf9, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfc, 0x3, 0x2, 0x2, 
    0x2, 0xfb, 0xfd, 0x5, 0x2e, 0x18, 0x2, 0xfc, 0xfb, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfe, 
    0xda, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfe, 
    0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 0x104, 
    0x3, 0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 0x18, 0x2, 0x2, 0x103, 0x105, 
    0x7, 0x2, 0x2, 0x3, 0x104, 0x102, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 
    0x3, 0x2, 0x2, 0x2, 0x105, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x106, 0x11d, 
    0x5, 0xe, 0x8, 0x2, 0x107, 0x109, 0x7, 0x16, 0x2, 0x2, 0x108, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x3, 0x2, 0x2, 0x2, 0x109, 0x111, 
    0x3, 0x2, 0x2, 0x2, 0x10a, 0x10c, 0x7, 0x18, 0x2, 0x2, 0x10b, 0x10a, 
    0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10b, 
    0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x112, 
    0x3, 0x2, 0x2, 0x2, 0x10f, 0x112, 0x7, 0x1a, 0x2, 0x2, 0x110, 0x112, 
    0x7, 0x21, 0x2, 0x2, 0x111, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x111, 0x10f, 
    0x3, 0x2, 0x2, 0x2, 0x111, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x114, 
    0x3, 0x2, 0x2, 0x2, 0x113, 0x115, 0x7, 0x19, 0x2, 0x2, 0x114, 0x113, 
    0x3, 0x2, 0x2, 0x2, 0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0x119, 0x5, 0x14, 0xb, 0x2, 0x117, 0x119, 
    0x5, 0x16, 0xc, 0x2, 0x118, 0x116, 0x3, 0x2, 0x2, 0x2, 0x118, 0x117, 
    0x3, 0x2, 0x2, 0x2, 0x119, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11c, 
    0x7, 0x17, 0x2, 0x2, 0x11b, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 
    0x3, 0x2, 0x2, 0x2, 0x11c, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x108, 
    0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11d, 
    0x3, 0x2, 0x2, 0x2, 0x11f, 0x120, 0x3, 0x2, 0x2, 0x2, 0x120, 0x13e, 
    0x3, 0x2, 0x2, 0x2, 0x121, 0x123, 0x9, 0x5, 0x2, 0x2, 0x122, 0x121, 
    0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x125, 
    0x3, 0x2, 0x2, 0x2, 0x124, 0x126, 0x9, 0x6, 0x2, 0x2, 0x125, 0x124, 
    0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 
    0x3, 0x2, 0x2, 0x2, 0x127, 0x139, 0x5, 0x2e, 0x18, 0x2, 0x128, 0x12a, 
    0x9, 0x5, 0x2, 0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 
    0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x12c, 
    0x3, 0x2, 0x2, 0x2, 0x12c, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12f, 
    0x7, 0x19, 0x2, 0x2, 0x12e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0x12f, 0x132, 0x3, 0x2, 0x2, 0x2, 0x130, 0x133, 
    0x5, 0x14, 0xb, 0x2, 0x131, 0x133, 0x5, 0x16, 0xc, 0x2, 0x132, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x135, 
    0x3, 0x2, 0x2, 0x2, 0x134, 0x136, 0x7, 0x17, 0x2, 0x2, 0x135, 0x134, 
    0x3, 0x2, 0x2, 0x2, 0x135, 0x136, 0x3, 0x2, 0x2, 0x2, 0x136, 0x138, 
    0x3, 0x2, 0x2, 0x2, 0x137, 0x129, 0x3, 0x2, 0x2, 0x2, 0x138, 0x13b, 
    0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x13a, 
    0x3, 0x2, 0x2, 0x2, 0x13a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 
    0x3, 0x2, 0x2, 0x2, 0x13c, 0x122, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x140, 
    0x3, 0x2, 0x2, 0x2, 0x13e, 0x13c, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13f, 
    0x3, 0x2, 0x2, 0x2, 0x13f, 0x143, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13e, 
    0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x7, 0x18, 0x2, 0x2, 0x142, 0x144, 
    0x7, 0x2, 0x2, 0x3, 0x143, 0x141, 0x3, 0x2, 0x2, 0x2, 0x143, 0x144, 
    0x3, 0x2, 0x2, 0x2, 0x144, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x145, 0x146, 
    0x5, 0xe, 0x8, 0x2, 0x146, 0x147, 0x7, 0x18, 0x2, 0x2, 0x147, 0x148, 
    0x7, 0x2, 0x2, 0x3, 0x148, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x149, 0x6f, 0x3, 
    0x2, 0x2, 0x2, 0x149, 0xb4, 0x3, 0x2, 0x2, 0x2, 0x149, 0xd8, 0x3, 0x2, 
    0x2, 0x2, 0x149, 0x106, 0x3, 0x2, 0x2, 0x2, 0x149, 0x145, 0x3, 0x2, 
    0x2, 0x2, 0x14a, 0x9, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x14d, 0x5, 0xe, 0x8, 
    0x2, 0x14c, 0x14e, 0x5, 0x14, 0xb, 0x2, 0x14d, 0x14c, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x14d, 0x3, 0x2, 0x2, 
    0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 0x150, 0x162, 0x3, 0x2, 0x2, 
    0x2, 0x151, 0x153, 0x9, 0x5, 0x2, 0x2, 0x152, 0x151, 0x3, 0x2, 0x2, 
    0x2, 0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 
    0x2, 0x154, 0x155, 0x3, 0x2, 0x2, 0x2, 0x155, 0x157, 0x3, 0x2, 0x2, 
    0x2, 0x156, 0x158, 0x7, 0x19, 0x2, 0x2, 0x157, 0x156, 0x3, 0x2, 0x2, 
    0x2, 0x157, 0x158, 0x3, 0x2, 0x2, 0x2, 0x158, 0x15b, 0x3, 0x2, 0x2, 
    0x2, 0x159, 0x15c, 0x5, 0x14, 0xb, 0x2, 0x15a, 0x15c, 0x5, 0x16, 0xc, 
    0x2, 0x15b, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x15a, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15f, 0x7, 0x17, 0x2, 
    0x2, 0x15e, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x15f, 0x3, 0x2, 0x2, 
    0x2, 0x15f, 0x161, 0x3, 0x2, 0x2, 0x2, 0x160, 0x152, 0x3, 0x2, 0x2, 
    0x2, 0x161, 0x164, 0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 
    0x2, 0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 0x163, 0x182, 0x3, 0x2, 0x2, 
    0x2, 0x164, 0x162, 0x3, 0x2, 0x2, 0x2, 0x165, 0x167, 0x9, 0x5, 0x2, 
    0x2, 0x166, 0x165, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x169, 0x3, 0x2, 0x2, 0x2, 0x168, 0x16a, 0x7, 0x1a, 0x2, 
    0x2, 0x169, 0x168, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16a, 0x3, 0x2, 0x2, 
    0x2, 0x16a, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x17d, 0x5, 0x2e, 0x18, 
    0x2, 0x16c, 0x16e, 0x9, 0x5, 0x2, 0x2, 0x16d, 0x16c, 0x3, 0x2, 0x2, 
    0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x172, 0x3, 0x2, 0x2, 
    0x2, 0x171, 0x173, 0x7, 0x19, 0x2, 0x2, 0x172, 0x171, 0x3, 0x2, 0x2, 
    0x2, 0x172, 0x173, 0x3, 0x2, 0x2, 0x2, 0x173, 0x176, 0x3, 0x2, 0x2, 
    0x2, 0x174, 0x177, 0x5, 0x14, 0xb, 0x2, 0x175, 0x177, 0x5, 0x16, 0xc, 
    0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x176, 0x175, 0x3, 0x2, 0x2, 
    0x2, 0x177, 0x179, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17a, 0x7, 0x17, 0x2, 
    0x2, 0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x3, 0x2, 0x2, 
    0x2, 0x17a, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x16d, 0x3, 0x2, 0x2, 
    0x2, 0x17c, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17b, 0x3, 0x2, 0x2, 
    0x2, 0x17d, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x181, 0x3, 0x2, 0x2, 
    0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x180, 0x166, 0x3, 0x2, 0x2, 
    0x2, 0x181, 0x184, 0x3, 0x2, 0x2, 0x2, 0x182, 0x180, 0x3, 0x2, 0x2, 
    0x2, 0x182, 0x183, 0x3, 0x2, 0x2, 0x2, 0x183, 0x216, 0x3, 0x2, 0x2, 
    0x2, 0x184, 0x182, 0x3, 0x2, 0x2, 0x2, 0x185, 0x1a1, 0x5, 0xe, 0x8, 
    0x2, 0x186, 0x188, 0x9, 0x5, 0x2, 0x2, 0x187, 0x186, 0x3, 0x2, 0x2, 
    0x2, 0x187, 0x188, 0x3, 0x2, 0x2, 0x2, 0x188, 0x18a, 0x3, 0x2, 0x2, 
    0x2, 0x189, 0x18b, 0x7, 0x1a, 0x2, 0x2, 0x18a, 0x189, 0x3, 0x2, 0x2, 
    0x2, 0x18a, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 
    0x2, 0x18c, 0x19e, 0x5, 0x2e, 0x18, 0x2, 0x18d, 0x18f, 0x9, 0x5, 0x2, 
    0x2, 0x18e, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 
    0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 0x2, 0x2, 
    0x2, 0x191, 0x193, 0x3, 0x2, 0x2, 0x2, 0x192, 0x194, 0x7, 0x19, 0x2, 
    0x2, 0x193, 0x192, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x3, 0x2, 0x2, 
    0x2, 0x194, 0x197, 0x3, 0x2, 0x2, 0x2, 0x195, 0x198, 0x5, 0x14, 0xb, 
    0x2, 0x196, 0x198, 0x5, 0x16, 0xc, 0x2, 0x197, 0x195, 0x3, 0x2, 0x2, 
    0x2, 0x197, 0x196, 0x3, 0x2, 0x2, 0x2, 0x198, 0x19a, 0x3, 0x2, 0x2, 
    0x2, 0x199, 0x19b, 0x7, 0x17, 0x2, 0x2, 0x19a, 0x199, 0x3, 0x2, 0x2, 
    0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19d, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x19e, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x19f, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x19e, 0x3, 0x2, 0x2, 
    0x2, 0x1a1, 0x187, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x3, 0x2, 0x2, 
    0x2, 0x1a3, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1a3, 0x1a4, 0x3, 0x2, 0x2, 
    0x2, 0x1a4, 0x216, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1c2, 0x5, 0xe, 0x8, 
    0x2, 0x1a6, 0x1a8, 0x7, 0x16, 0x2, 0x2, 0x1a7, 0x1a6, 0x3, 0x2, 0x2, 
    0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1b0, 0x3, 0x2, 0x2, 
    0x2, 0x1a9, 0x1ab, 0x7, 0x18, 0x2, 0x2, 0x1aa, 0x1a9, 0x3, 0x2, 0x2, 
    0x2, 0x1ab, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1aa, 0x3, 0x2, 0x2, 
    0x2, 0x1ac, 0x1ad, 0x3, 0x2, 0x2, 0x2, 0x1ad, 0x1b1, 0x3, 0x2, 0x2, 
    0x2, 0x1ae, 0x1b1, 0x7, 0x1a, 0x2, 0x2, 0x1af, 0x1b1, 0x7, 0x21, 0x2, 
    0x2, 0x1b0, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1ae, 0x3, 0x2, 0x2, 
    0x2, 0x1b0, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x3, 0x2, 0x2, 
    0x2, 0x1b2, 0x1bf, 0x5, 0xc, 0x7, 0x2, 0x1b3, 0x1b5, 0x9, 0x5, 0x2, 
    0x2, 0x1b4, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b8, 0x3, 0x2, 0x2, 
    0x2, 0x1b6, 0x1b4, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b7, 0x3, 0x2, 0x2, 
    0x2, 0x1b7, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b6, 0x3, 0x2, 0x2, 
    0x2, 0x1b9, 0x1bb, 0x5, 0x14, 0xb, 0x2, 0x1ba, 0x1bc, 0x7, 0x17, 0x2, 
    0x2, 0x1bb, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x3, 0x2, 0x2, 
    0x2, 0x1bc, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1b6, 0x3, 0x2, 0x2, 
    0x2, 0x1be, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1bd, 0x3, 0x2, 0x2, 
    0x2, 0x1bf, 0x1c0, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c3, 0x3, 0x2, 0x2, 
    0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1a7, 0x3, 0x2, 0x2, 
    0x2, 0x1c3, 0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 0x2, 
    0x2, 0x1c4, 0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1e0, 0x3, 0x2, 0x2, 
    0x2, 0x1c6, 0x1c8, 0x7, 0x1a, 0x2, 0x2, 0x1c7, 0x1c6, 0x3, 0x2, 0x2, 
    0x2, 0x1c7, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1c9, 0x3, 0x2, 0x2, 
    0x2, 0x1c9, 0x1db, 0x5, 0x2e, 0x18, 0x2, 0x1ca, 0x1cc, 0x9, 0x5, 0x2, 
    0x2, 0x1cb, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x3, 0x2, 0x2, 
    0x2, 0x1cd, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x3, 0x2, 0x2, 
    0x2, 0x1ce, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d1, 0x7, 0x19, 0x2, 
    0x2, 0x1d0, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 0x3, 0x2, 0x2, 
    0x2, 0x1d1, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d5, 0x5, 0x14, 0xb, 
    0x2, 0x1d3, 0x1d5, 0x5, 0x16, 0xc, 0x2, 0x1d4, 0x1d2, 0x3, 0x2, 0x2, 
    0x2, 0x1d4, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d7, 0x3, 0x2, 0x2, 
    0x2, 0x1d6, 0x1d8, 0x7, 0x17, 0x2, 0x2, 0x1d7, 0x1d6, 0x3, 0x2, 0x2, 
    0x2, 0x1d7, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1da, 0x3, 0x2, 0x2, 
    0x2, 0x1d9, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1dd, 0x3, 0x2, 0x2, 
    0x2, 0x1db, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x3, 0x2, 0x2, 
    0x2, 0x1dc, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1db, 0x3, 0x2, 0x2, 
    0x2, 0x1de, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1df, 0x1e2, 0x3, 0x2, 0x2, 
    0x2, 0x1e0, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1e1, 0x3, 0x2, 0x2, 
    0x2, 0x1e1, 0x216, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1e0, 0x3, 0x2, 0x2, 
    0x2, 0x1e3, 0x1f4, 0x5, 0xe, 0x8, 0x2, 0x1e4, 0x1e6, 0x7, 0x18, 0x2, 
    0x2, 0x1e5, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x3, 0x2, 0x2, 
    0x2, 0x1e7, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x3, 0x2, 0x2, 
    0x2, 0x1e8, 0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1e9, 0x1ec, 0x7, 0x1a, 0x2, 
    0x2, 0x1ea, 0x1ec, 0x7, 0x21, 0x2, 0x2, 0x1eb, 0x1e5, 0x3, 0x2, 0x2, 
    0x2, 0x1eb, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ea, 0x3, 0x2, 0x2, 
    0x2, 0x1ec, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ef, 0x7, 0x19, 0x2, 
    0x2, 0x1ee, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ef, 0x3, 0x2, 0x2, 
    0x2, 0x1ef, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f2, 0x5, 0x14, 0xb, 
    0x2, 0x1f1, 0x1f3, 0x7, 0x17, 0x2, 0x2, 0x1f2, 0x1f1, 0x3, 0x2, 0x2, 
    0x2, 0x1f2, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f5, 0x3, 0x2, 0x2, 
    0x2, 0x1f4, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x3, 0x2, 0x2, 
    0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x3, 0x2, 0x2, 
    0x2, 0x1f7, 0x212, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1fa, 0x7, 0x1a, 0x2, 
    0x2, 0x1f9, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 0x2, 
    0x2, 0x1fa, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x20d, 0x5, 0x2e, 0x18, 
    0x2, 0x1fc, 0x1fe, 0x9, 0x5, 0x2, 0x2, 0x1fd, 0x1fc, 0x3, 0x2, 0x2, 
    0x2, 0x1fe, 0x1ff, 0x3, 0x2, 0x2, 0x2, 0x1ff, 0x1fd, 0x3, 0x2, 0x2, 
    0x2, 0x1ff, 0x200, 0x3, 0x2, 0x2, 0x2, 0x200, 0x202, 0x3, 0x2, 0x2, 
    0x2, 0x201, 0x203, 0x7, 0x19, 0x2, 0x2, 0x202, 0x201, 0x3, 0x2, 0x2, 
    0x2, 0x202, 0x203, 0x3, 0x2, 0x2, 0x2, 0x203, 0x206, 0x3, 0x2, 0x2, 
    0x2, 0x204, 0x207, 0x5, 0x14, 0xb, 0x2, 0x205, 0x207, 0x5, 0x16, 0xc, 
    0x2, 0x206, 0x204, 0x3, 0x2, 0x2, 0x2, 0x206, 0x205, 0x3, 0x2, 0x2, 
    0x2, 0x207, 0x209, 0x3, 0x2, 0x2, 0x2, 0x208, 0x20a, 0x7, 0x17, 0x2, 
    0x2, 0x209, 0x208, 0x3, 0x2, 0x2, 0x2, 0x209, 0x20a, 0x3, 0x2, 0x2, 
    0x2, 0x20a, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x1fd, 0x3, 0x2, 0x2, 
    0x2, 0x20c, 0x20f, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20b, 0x3, 0x2, 0x2, 
    0x2, 0x20d, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x211, 0x3, 0x2, 0x2, 
    0x2, 0x20f, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x210, 0x1f9, 0x3, 0x2, 0x2, 
    0x2, 0x211, 0x214, 0x3, 0x2, 0x2, 0x2, 0x212, 0x210, 0x3, 0x2, 0x2, 
    0x2, 0x212, 0x213, 0x3, 0x2, 0x2, 0x2, 0x213, 0x216, 0x3, 0x2, 0x2, 
    0x2, 0x214, 0x212, 0x3, 0x2, 0x2, 0x2, 0x215, 0x14b, 0x3, 0x2, 0x2, 
    0x2, 0x215, 0x185, 0x3, 0x2, 0x2, 0x2, 0x215, 0x1a5, 0x3, 0x2, 0x2, 
    0x2, 0x215, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x216, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x217, 0x21e, 0x7, 0x23, 0x2, 0x2, 0x218, 0x21a, 0x7, 0x1a, 0x2, 0x2, 
    0x219, 0x218, 0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x3, 0x2, 0x2, 0x2, 
    0x21a, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x21d, 0x7, 0x23, 0x2, 0x2, 
    0x21c, 0x219, 0x3, 0x2, 0x2, 0x2, 0x21d, 0x220, 0x3, 0x2, 0x2, 0x2, 
    0x21e, 0x21c, 0x3, 0x2, 0x2, 0x2, 0x21e, 0x21f, 0x3, 0x2, 0x2, 0x2, 
    0x21f, 0x224, 0x3, 0x2, 0x2, 0x2, 0x220, 0x21e, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x224, 0x7, 0x1f, 0x2, 0x2, 0x222, 0x224, 0x7, 0x1e, 0x2, 0x2, 
    0x223, 0x217, 0x3, 0x2, 0x2, 0x2, 0x223, 0x221, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x222, 0x3, 0x2, 0x2, 0x2, 0x224, 0xd, 0x3, 0x2, 0x2, 0x2, 0x225, 
    0x22c, 0x5, 0x32, 0x1a, 0x2, 0x226, 0x22c, 0x5, 0x1e, 0x10, 0x2, 0x227, 
    0x22c, 0x5, 0x20, 0x11, 0x2, 0x228, 0x22c, 0x5, 0x1c, 0xf, 0x2, 0x229, 
    0x22c, 0x5, 0x22, 0x12, 0x2, 0x22a, 0x22c, 0x5, 0x10, 0x9, 0x2, 0x22b, 
    0x225, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x226, 0x3, 0x2, 0x2, 0x2, 0x22b, 
    0x227, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x228, 0x3, 0x2, 0x2, 0x2, 0x22b, 
    0x229, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22a, 0x3, 0x2, 0x2, 0x2, 0x22c, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x237, 0x7, 0x23, 0x2, 0x2, 0x22e, 0x230, 
    0x9, 0x7, 0x2, 0x2, 0x22f, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 0x233, 
    0x3, 0x2, 0x2, 0x2, 0x231, 0x22f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 
    0x3, 0x2, 0x2, 0x2, 0x232, 0x234, 0x3, 0x2, 0x2, 0x2, 0x233, 0x231, 
    0x3, 0x2, 0x2, 0x2, 0x234, 0x236, 0x7, 0x23, 0x2, 0x2, 0x235, 0x231, 
    0x3, 0x2, 0x2, 0x2, 0x236, 0x239, 0x3, 0x2, 0x2, 0x2, 0x237, 0x235, 
    0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 0x3, 0x2, 0x2, 0x2, 0x238, 0x268, 
    0x3, 0x2, 0x2, 0x2, 0x239, 0x237, 0x3, 0x2, 0x2, 0x2, 0x23a, 0x244, 
    0x7, 0x23, 0x2, 0x2, 0x23b, 0x23d, 0x9, 0x7, 0x2, 0x2, 0x23c, 0x23b, 
    0x3, 0x2, 0x2, 0x2, 0x23d, 0x240, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23c, 
    0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x23f, 0x241, 
    0x3, 0x2, 0x2, 0x2, 0x240, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x241, 0x243, 
    0x7, 0x23, 0x2, 0x2, 0x242, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x243, 0x246, 
    0x3, 0x2, 0x2, 0x2, 0x244, 0x242, 0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 
    0x3, 0x2, 0x2, 0x2, 0x245, 0x248, 0x3, 0x2, 0x2, 0x2, 0x246, 0x244, 
    0x3, 0x2, 0x2, 0x2, 0x247, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x247, 0x248, 
    0x3, 0x2, 0x2, 0x2, 0x248, 0x249, 0x3, 0x2, 0x2, 0x2, 0x249, 0x24a, 
    0x7, 0xf, 0x2, 0x2, 0x24a, 0x254, 0x7, 0x23, 0x2, 0x2, 0x24b, 0x24d, 
    0x9, 0x7, 0x2, 0x2, 0x24c, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24d, 0x250, 
    0x3, 0x2, 0x2, 0x2, 0x24e, 0x24c, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 
    0x3, 0x2, 0x2, 0x2, 0x24f, 0x251, 0x3, 0x2, 0x2, 0x2, 0x250, 0x24e, 
    0x3, 0x2, 0x2, 0x2, 0x251, 0x253, 0x7, 0x23, 0x2, 0x2, 0x252, 0x24e, 
    0x3, 0x2, 0x2, 0x2, 0x253, 0x256, 0x3, 0x2, 0x2, 0x2, 0x254, 0x252, 
    0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x3, 0x2, 0x2, 0x2, 0x255, 0x257, 
    0x3, 0x2, 0x2, 0x2, 0x256, 0x254, 0x3, 0x2, 0x2, 0x2, 0x257, 0x265, 
    0x7, 0x10, 0x2, 0x2, 0x258, 0x262, 0x7, 0x23, 0x2, 0x2, 0x259, 0x25b, 
    0x9, 0x7, 0x2, 0x2, 0x25a, 0x259, 0x3, 0x2, 0x2, 0x2, 0x25b, 0x25e, 
    0x3, 0x2, 0x2, 0x2, 0x25c, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25d, 
    0x3, 0x2, 0x2, 0x2, 0x25d, 0x25f, 0x3, 0x2, 0x2, 0x2, 0x25e, 0x25c, 
    0x3, 0x2, 0x2, 0x2, 0x25f, 0x261, 0x7, 0x23, 0x2, 0x2, 0x260, 0x25c, 
    0x3, 0x2, 0x2, 0x2, 0x261, 0x264, 0x3, 0x2, 0x2, 0x2, 0x262, 0x260, 
    0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x3, 0x2, 0x2, 0x2, 0x263, 0x266, 
    0x3, 0x2, 0x2, 0x2, 0x264, 0x262, 0x3, 0x2, 0x2, 0x2, 0x265, 0x258, 
    0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 0x3, 0x2, 0x2, 0x2, 0x266, 0x268, 
    0x3, 0x2, 0x2, 0x2, 0x267, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x267, 0x247, 
    0x3, 0x2, 0x2, 0x2, 0x268, 0x11, 0x3, 0x2, 0x2, 0x2, 0x269, 0x271, 0x5, 
    0x38, 0x1d, 0x2, 0x26a, 0x271, 0x5, 0x26, 0x14, 0x2, 0x26b, 0x271, 0x5, 
    0x28, 0x15, 0x2, 0x26c, 0x271, 0x5, 0x24, 0x13, 0x2, 0x26d, 0x271, 0x5, 
    0x2a, 0x16, 0x2, 0x26e, 0x271, 0x5, 0x18, 0xd, 0x2, 0x26f, 0x271, 0x7, 
    0x1e, 0x2, 0x2, 0x270, 0x269, 0x3, 0x2, 0x2, 0x2, 0x270, 0x26a, 0x3, 
    0x2, 0x2, 0x2, 0x270, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x270, 0x26c, 0x3, 
    0x2, 0x2, 0x2, 0x270, 0x26d, 0x3, 0x2, 0x2, 0x2, 0x270, 0x26e, 0x3, 
    0x2, 0x2, 0x2, 0x270, 0x26f, 0x3, 0x2, 0x2, 0x2, 0x271, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x272, 0x285, 0x5, 0x38, 0x1d, 0x2, 0x273, 0x285, 0x5, 0x26, 
    0x14, 0x2, 0x274, 0x285, 0x5, 0x28, 0x15, 0x2, 0x275, 0x285, 0x5, 0x24, 
    0x13, 0x2, 0x276, 0x285, 0x5, 0x2a, 0x16, 0x2, 0x277, 0x285, 0x5, 0x1a, 
    0xe, 0x2, 0x278, 0x285, 0x7, 0x1e, 0x2, 0x2, 0x279, 0x27a, 0x7, 0xf, 
    0x2, 0x2, 0x27a, 0x27f, 0x5, 0x38, 0x1d, 0x2, 0x27b, 0x27c, 0x7, 0x17, 
    0x2, 0x2, 0x27c, 0x27e, 0x5, 0x38, 0x1d, 0x2, 0x27d, 0x27b, 0x3, 0x2, 
    0x2, 0x2, 0x27e, 0x281, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x27d, 0x3, 0x2, 
    0x2, 0x2, 0x27f, 0x280, 0x3, 0x2, 0x2, 0x2, 0x280, 0x282, 0x3, 0x2, 
    0x2, 0x2, 0x281, 0x27f, 0x3, 0x2, 0x2, 0x2, 0x282, 0x283, 0x7, 0x10, 
    0x2, 0x2, 0x283, 0x285, 0x3, 0x2, 0x2, 0x2, 0x284, 0x272, 0x3, 0x2, 
    0x2, 0x2, 0x284, 0x273, 0x3, 0x2, 0x2, 0x2, 0x284, 0x274, 0x3, 0x2, 
    0x2, 0x2, 0x284, 0x275, 0x3, 0x2, 0x2, 0x2, 0x284, 0x276, 0x3, 0x2, 
    0x2, 0x2, 0x284, 0x277, 0x3, 0x2, 0x2, 0x2, 0x284, 0x278, 0x3, 0x2, 
    0x2, 0x2, 0x284, 0x279, 0x3, 0x2, 0x2, 0x2, 0x285, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x286, 0x28b, 0x7, 0x23, 0x2, 0x2, 0x287, 0x288, 0x7, 0xf, 0x2, 
    0x2, 0x288, 0x289, 0x7, 0x23, 0x2, 0x2, 0x289, 0x28b, 0x7, 0x10, 0x2, 
    0x2, 0x28a, 0x286, 0x3, 0x2, 0x2, 0x2, 0x28a, 0x287, 0x3, 0x2, 0x2, 
    0x2, 0x28b, 0x17, 0x3, 0x2, 0x2, 0x2, 0x28c, 0x28d, 0x7, 0x22, 0x2, 
    0x2, 0x28d, 0x19, 0x3, 0x2, 0x2, 0x2, 0x28e, 0x293, 0x7, 0x22, 0x2, 
    0x2, 0x28f, 0x290, 0x7, 0x17, 0x2, 0x2, 0x290, 0x292, 0x7, 0x22, 0x2, 
    0x2, 0x291, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x292, 0x295, 0x3, 0x2, 0x2, 
    0x2, 0x293, 0x291, 0x3, 0x2, 0x2, 0x2, 0x293, 0x294, 0x3, 0x2, 0x2, 
    0x2, 0x294, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x295, 0x293, 0x3, 0x2, 0x2, 0x2, 
    0x296, 0x29d, 0x7, 0x22, 0x2, 0x2, 0x297, 0x299, 0x7, 0x1a, 0x2, 0x2, 
    0x298, 0x297, 0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 0x3, 0x2, 0x2, 0x2, 
    0x299, 0x29a, 0x3, 0x2, 0x2, 0x2, 0x29a, 0x29c, 0x7, 0x23, 0x2, 0x2, 
    0x29b, 0x298, 0x3, 0x2, 0x2, 0x2, 0x29c, 0x29f, 0x3, 0x2, 0x2, 0x2, 
    0x29d, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x29d, 0x29e, 0x3, 0x2, 0x2, 0x2, 
    0x29e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x29d, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
    0x2a1, 0x5, 0x26, 0x14, 0x2, 0x2a1, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x2a2, 
    0x2a3, 0x5, 0x28, 0x15, 0x2, 0x2a3, 0x21, 0x3, 0x2, 0x2, 0x2, 0x2a4, 
    0x2a5, 0x5, 0x24, 0x13, 0x2, 0x2a5, 0x23, 0x3, 0x2, 0x2, 0x2, 0x2a6, 
    0x2ab, 0x7, 0x1c, 0x2, 0x2, 0x2a7, 0x2a8, 0x7, 0xf, 0x2, 0x2, 0x2a8, 
    0x2a9, 0x7, 0x1c, 0x2, 0x2, 0x2a9, 0x2ab, 0x7, 0x10, 0x2, 0x2, 0x2aa, 
    0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2ab, 
    0x25, 0x3, 0x2, 0x2, 0x2, 0x2ac, 0x2b1, 0x7, 0xe, 0x2, 0x2, 0x2ad, 0x2ae, 
    0x7, 0xf, 0x2, 0x2, 0x2ae, 0x2af, 0x7, 0xe, 0x2, 0x2, 0x2af, 0x2b1, 
    0x7, 0x10, 0x2, 0x2, 0x2b0, 0x2ac, 0x3, 0x2, 0x2, 0x2, 0x2b0, 0x2ad, 
    0x3, 0x2, 0x2, 0x2, 0x2b1, 0x27, 0x3, 0x2, 0x2, 0x2, 0x2b2, 0x2b7, 0x7, 
    0x1d, 0x2, 0x2, 0x2b3, 0x2b4, 0x7, 0xf, 0x2, 0x2, 0x2b4, 0x2b5, 0x7, 
    0x1d, 0x2, 0x2, 0x2b5, 0x2b7, 0x7, 0x10, 0x2, 0x2, 0x2b6, 0x2b2, 0x3, 
    0x2, 0x2, 0x2, 0x2b6, 0x2b3, 0x3, 0x2, 0x2, 0x2, 0x2b7, 0x29, 0x3, 0x2, 
    0x2, 0x2, 0x2b8, 0x2bd, 0x7, 0x24, 0x2, 0x2, 0x2b9, 0x2ba, 0x7, 0xf, 
    0x2, 0x2, 0x2ba, 0x2bb, 0x7, 0x24, 0x2, 0x2, 0x2bb, 0x2bd, 0x7, 0x10, 
    0x2, 0x2, 0x2bc, 0x2b8, 0x3, 0x2, 0x2, 0x2, 0x2bc, 0x2b9, 0x3, 0x2, 
    0x2, 0x2, 0x2bd, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2be, 0x2bf, 0x9, 0x8, 0x2, 
    0x2, 0x2bf, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2c0, 0x2c1, 0x7, 0x11, 0x2, 
    0x2, 0x2c1, 0x2c7, 0x5, 0x30, 0x19, 0x2, 0x2c2, 0x2c3, 0x5, 0x2c, 0x17, 
    0x2, 0x2c3, 0x2c4, 0x5, 0x30, 0x19, 0x2, 0x2c4, 0x2c6, 0x3, 0x2, 0x2, 
    0x2, 0x2c5, 0x2c2, 0x3, 0x2, 0x2, 0x2, 0x2c6, 0x2c9, 0x3, 0x2, 0x2, 
    0x2, 0x2c7, 0x2c5, 0x3, 0x2, 0x2, 0x2, 0x2c7, 0x2c8, 0x3, 0x2, 0x2, 
    0x2, 0x2c8, 0x2ca, 0x3, 0x2, 0x2, 0x2, 0x2c9, 0x2c7, 0x3, 0x2, 0x2, 
    0x2, 0x2ca, 0x2cb, 0x9, 0x9, 0x2, 0x2, 0x2cb, 0x2d9, 0x3, 0x2, 0x2, 
    0x2, 0x2cc, 0x2cd, 0x7, 0x13, 0x2, 0x2, 0x2cd, 0x2d3, 0x5, 0x30, 0x19, 
    0x2, 0x2ce, 0x2cf, 0x5, 0x2c, 0x17, 0x2, 0x2cf, 0x2d0, 0x5, 0x30, 0x19, 
    0x2, 0x2d0, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x2ce, 0x3, 0x2, 0x2, 
    0x2, 0x2d2, 0x2d5, 0x3, 0x2, 0x2, 0x2, 0x2d3, 0x2d1, 0x3, 0x2, 0x2, 
    0x2, 0x2d3, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d4, 0x2d6, 0x3, 0x2, 0x2, 
    0x2, 0x2d5, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2d6, 0x2d7, 0x9, 0xa, 0x2, 
    0x2, 0x2d7, 0x2d9, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2c0, 0x3, 0x2, 0x2, 
    0x2, 0x2d8, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2f, 0x3, 0x2, 0x2, 0x2, 
    0x2da, 0x330, 0x5, 0x40, 0x21, 0x2, 0x2db, 0x2dd, 0x7, 0x1f, 0x2, 0x2, 
    0x2dc, 0x2db, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2e0, 0x3, 0x2, 0x2, 0x2, 
    0x2de, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 0x3, 0x2, 0x2, 0x2, 
    0x2df, 0x309, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2de, 0x3, 0x2, 0x2, 0x2, 
    0x2e1, 0x30a, 0x5, 0xa, 0x6, 0x2, 0x2e2, 0x30a, 0x5, 0x38, 0x1d, 0x2, 
    0x2e3, 0x30a, 0x5, 0x24, 0x13, 0x2, 0x2e4, 0x30a, 0x5, 0x28, 0x15, 0x2, 
    0x2e5, 0x30a, 0x5, 0x26, 0x14, 0x2, 0x2e6, 0x30a, 0x5, 0x44, 0x23, 0x2, 
    0x2e7, 0x30a, 0x5, 0x2a, 0x16, 0x2, 0x2e8, 0x2e9, 0x7, 0xf, 0x2, 0x2, 
    0x2e9, 0x2ea, 0x5, 0xa, 0x6, 0x2, 0x2ea, 0x2eb, 0x7, 0x10, 0x2, 0x2, 
    0x2eb, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x2ec, 0x2ed, 0x7, 0xf, 0x2, 0x2, 
    0x2ed, 0x2ee, 0x5, 0x38, 0x1d, 0x2, 0x2ee, 0x2ef, 0x7, 0x10, 0x2, 0x2, 
    0x2ef, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 0x7, 0xf, 0x2, 0x2, 
    0x2f1, 0x2f2, 0x5, 0x24, 0x13, 0x2, 0x2f2, 0x2f3, 0x7, 0x10, 0x2, 0x2, 
    0x2f3, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x2f4, 0x2f5, 0x7, 0xf, 0x2, 0x2, 
    0x2f5, 0x2f6, 0x5, 0x28, 0x15, 0x2, 0x2f6, 0x2f7, 0x7, 0x10, 0x2, 0x2, 
    0x2f7, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x2f8, 0x2f9, 0x7, 0xf, 0x2, 0x2, 
    0x2f9, 0x2fa, 0x5, 0x26, 0x14, 0x2, 0x2fa, 0x2fb, 0x7, 0x10, 0x2, 0x2, 
    0x2fb, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x2fc, 0x2fd, 0x7, 0xf, 0x2, 0x2, 
    0x2fd, 0x2fe, 0x5, 0x42, 0x22, 0x2, 0x2fe, 0x2ff, 0x7, 0x10, 0x2, 0x2, 
    0x2ff, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x300, 0x301, 0x7, 0xf, 0x2, 0x2, 
    0x301, 0x302, 0x5, 0x44, 0x23, 0x2, 0x302, 0x303, 0x7, 0x10, 0x2, 0x2, 
    0x303, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x304, 0x305, 0x7, 0xf, 0x2, 0x2, 
    0x305, 0x306, 0x5, 0x2a, 0x16, 0x2, 0x306, 0x307, 0x7, 0x10, 0x2, 0x2, 
    0x307, 0x30a, 0x3, 0x2, 0x2, 0x2, 0x308, 0x30a, 0x5, 0x2e, 0x18, 0x2, 
    0x309, 0x2e1, 0x3, 0x2, 0x2, 0x2, 0x309, 0x2e2, 0x3, 0x2, 0x2, 0x2, 
    0x309, 0x2e3, 0x3, 0x2, 0x2, 0x2, 0x309, 0x2e4, 0x3, 0x2, 0x2, 0x2, 
    0x309, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x309, 0x2e6, 0x3, 0x2, 0x2, 0x2, 
    0x309, 0x2e7, 0x3, 0x2, 0x2, 0x2, 0x309, 0x2e8, 0x3, 0x2, 0x2, 0x2, 
    0x309, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x309, 0x2f0, 0x3, 0x2, 0x2, 0x2, 
    0x309, 0x2f4, 0x3, 0x2, 0x2, 0x2, 0x309, 0x2f8, 0x3, 0x2, 0x2, 0x2, 
    0x309, 0x2fc, 0x3, 0x2, 0x2, 0x2, 0x309, 0x300, 0x3, 0x2, 0x2, 0x2, 
    0x309, 0x304, 0x3, 0x2, 0x2, 0x2, 0x309, 0x308, 0x3, 0x2, 0x2, 0x2, 
    0x30a, 0x30e, 0x3, 0x2, 0x2, 0x2, 0x30b, 0x30d, 0x7, 0x1a, 0x2, 0x2, 
    0x30c, 0x30b, 0x3, 0x2, 0x2, 0x2, 0x30d, 0x310, 0x3, 0x2, 0x2, 0x2, 
    0x30e, 0x30c, 0x3, 0x2, 0x2, 0x2, 0x30e, 0x30f, 0x3, 0x2, 0x2, 0x2, 
    0x30f, 0x312, 0x3, 0x2, 0x2, 0x2, 0x310, 0x30e, 0x3, 0x2, 0x2, 0x2, 
    0x311, 0x2de, 0x3, 0x2, 0x2, 0x2, 0x312, 0x313, 0x3, 0x2, 0x2, 0x2, 
    0x313, 0x311, 0x3, 0x2, 0x2, 0x2, 0x313, 0x314, 0x3, 0x2, 0x2, 0x2, 
    0x314, 0x320, 0x3, 0x2, 0x2, 0x2, 0x315, 0x321, 0x5, 0x42, 0x22, 0x2, 
    0x316, 0x321, 0x5, 0x34, 0x1b, 0x2, 0x317, 0x321, 0x5, 0x3a, 0x1e, 0x2, 
    0x318, 0x319, 0x7, 0xf, 0x2, 0x2, 0x319, 0x31a, 0x5, 0x34, 0x1b, 0x2, 
    0x31a, 0x31b, 0x7, 0x10, 0x2, 0x2, 0x31b, 0x321, 0x3, 0x2, 0x2, 0x2, 
    0x31c, 0x31d, 0x7, 0xf, 0x2, 0x2, 0x31d, 0x31e, 0x5, 0x3a, 0x1e, 0x2, 
    0x31e, 0x31f, 0x7, 0x10, 0x2, 0x2, 0x31f, 0x321, 0x3, 0x2, 0x2, 0x2, 
    0x320, 0x315, 0x3, 0x2, 0x2, 0x2, 0x320, 0x316, 0x3, 0x2, 0x2, 0x2, 
    0x320, 0x317, 0x3, 0x2, 0x2, 0x2, 0x320, 0x318, 0x3, 0x2, 0x2, 0x2, 
    0x320, 0x31c, 0x3, 0x2, 0x2, 0x2, 0x320, 0x321, 0x3, 0x2, 0x2, 0x2, 
    0x321, 0x330, 0x3, 0x2, 0x2, 0x2, 0x322, 0x32e, 0x5, 0x42, 0x22, 0x2, 
    0x323, 0x32e, 0x5, 0x34, 0x1b, 0x2, 0x324, 0x32e, 0x5, 0x3a, 0x1e, 0x2, 
    0x325, 0x326, 0x7, 0xf, 0x2, 0x2, 0x326, 0x327, 0x5, 0x34, 0x1b, 0x2, 
    0x327, 0x328, 0x7, 0x10, 0x2, 0x2, 0x328, 0x32e, 0x3, 0x2, 0x2, 0x2, 
    0x329, 0x32a, 0x7, 0xf, 0x2, 0x2, 0x32a, 0x32b, 0x5, 0x3a, 0x1e, 0x2, 
    0x32b, 0x32c, 0x7, 0x10, 0x2, 0x2, 0x32c, 0x32e, 0x3, 0x2, 0x2, 0x2, 
    0x32d, 0x322, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x323, 0x3, 0x2, 0x2, 0x2, 
    0x32d, 0x324, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x325, 0x3, 0x2, 0x2, 0x2, 
    0x32d, 0x329, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x330, 0x3, 0x2, 0x2, 0x2, 
    0x32f, 0x2da, 0x3, 0x2, 0x2, 0x2, 0x32f, 0x311, 0x3, 0x2, 0x2, 0x2, 
    0x32f, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x330, 0x31, 0x3, 0x2, 0x2, 0x2, 0x331, 
    0x33f, 0x5, 0x3e, 0x20, 0x2, 0x332, 0x334, 0x9, 0xb, 0x2, 0x2, 0x333, 
    0x332, 0x3, 0x2, 0x2, 0x2, 0x334, 0x335, 0x3, 0x2, 0x2, 0x2, 0x335, 
    0x333, 0x3, 0x2, 0x2, 0x2, 0x335, 0x336, 0x3, 0x2, 0x2, 0x2, 0x336, 
    0x33d, 0x3, 0x2, 0x2, 0x2, 0x337, 0x33e, 0x5, 0x24, 0x13, 0x2, 0x338, 
    0x33e, 0x5, 0x28, 0x15, 0x2, 0x339, 0x33e, 0x5, 0x26, 0x14, 0x2, 0x33a, 
    0x33e, 0x5, 0x42, 0x22, 0x2, 0x33b, 0x33e, 0x5, 0x2a, 0x16, 0x2, 0x33c, 
    0x33e, 0x5, 0x36, 0x1c, 0x2, 0x33d, 0x337, 0x3, 0x2, 0x2, 0x2, 0x33d, 
    0x338, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x339, 0x3, 0x2, 0x2, 0x2, 0x33d, 
    0x33a, 0x3, 0x2, 0x2, 0x2, 0x33d, 0x33b, 0x3, 0x2, 0x2, 0x2, 0x33d, 
    0x33c, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x340, 0x3, 0x2, 0x2, 0x2, 0x33f, 
    0x333, 0x3, 0x2, 0x2, 0x2, 0x340, 0x341, 0x3, 0x2, 0x2, 0x2, 0x341, 
    0x33f, 0x3, 0x2, 0x2, 0x2, 0x341, 0x342, 0x3, 0x2, 0x2, 0x2, 0x342, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x343, 0x344, 0x5, 0xe, 0x8, 0x2, 0x344, 0x345, 
    0x7, 0x18, 0x2, 0x2, 0x345, 0x35, 0x3, 0x2, 0x2, 0x2, 0x346, 0x34b, 
    0x7, 0x22, 0x2, 0x2, 0x347, 0x348, 0x7, 0x18, 0x2, 0x2, 0x348, 0x34a, 
    0x7, 0x23, 0x2, 0x2, 0x349, 0x347, 0x3, 0x2, 0x2, 0x2, 0x34a, 0x34d, 
    0x3, 0x2, 0x2, 0x2, 0x34b, 0x349, 0x3, 0x2, 0x2, 0x2, 0x34b, 0x34c, 
    0x3, 0x2, 0x2, 0x2, 0x34c, 0x350, 0x3, 0x2, 0x2, 0x2, 0x34d, 0x34b, 
    0x3, 0x2, 0x2, 0x2, 0x34e, 0x350, 0x7, 0x22, 0x2, 0x2, 0x34f, 0x346, 
    0x3, 0x2, 0x2, 0x2, 0x34f, 0x34e, 0x3, 0x2, 0x2, 0x2, 0x350, 0x37, 0x3, 
    0x2, 0x2, 0x2, 0x351, 0x36c, 0x5, 0x3e, 0x20, 0x2, 0x352, 0x354, 0x9, 
    0xb, 0x2, 0x2, 0x353, 0x352, 0x3, 0x2, 0x2, 0x2, 0x354, 0x355, 0x3, 
    0x2, 0x2, 0x2, 0x355, 0x353, 0x3, 0x2, 0x2, 0x2, 0x355, 0x356, 0x3, 
    0x2, 0x2, 0x2, 0x356, 0x36a, 0x3, 0x2, 0x2, 0x2, 0x357, 0x35e, 0x7, 
    0xf, 0x2, 0x2, 0x358, 0x35f, 0x5, 0x24, 0x13, 0x2, 0x359, 0x35f, 0x5, 
    0x28, 0x15, 0x2, 0x35a, 0x35f, 0x5, 0x26, 0x14, 0x2, 0x35b, 0x35f, 0x5, 
    0x42, 0x22, 0x2, 0x35c, 0x35f, 0x5, 0x2a, 0x16, 0x2, 0x35d, 0x35f, 0x5, 
    0x3c, 0x1f, 0x2, 0x35e, 0x358, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x359, 0x3, 
    0x2, 0x2, 0x2, 0x35e, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35b, 0x3, 
    0x2, 0x2, 0x2, 0x35e, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35d, 0x3, 
    0x2, 0x2, 0x2, 0x35f, 0x360, 0x3, 0x2, 0x2, 0x2, 0x360, 0x361, 0x7, 
    0x10, 0x2, 0x2, 0x361, 0x36b, 0x3, 0x2, 0x2, 0x2, 0x362, 0x369, 0x5, 
    0x24, 0x13, 0x2, 0x363, 0x369, 0x5, 0x28, 0x15, 0x2, 0x364, 0x369, 0x5, 
    0x26, 0x14, 0x2, 0x365, 0x369, 0x5, 0x42, 0x22, 0x2, 0x366, 0x369, 0x5, 
    0x2a, 0x16, 0x2, 0x367, 0x369, 0x5, 0x3c, 0x1f, 0x2, 0x368, 0x362, 0x3, 
    0x2, 0x2, 0x2, 0x368, 0x363, 0x3, 0x2, 0x2, 0x2, 0x368, 0x364, 0x3, 
    0x2, 0x2, 0x2, 0x368, 0x365, 0x3, 0x2, 0x2, 0x2, 0x368, 0x366, 0x3, 
    0x2, 0x2, 0x2, 0x368, 0x367, 0x3, 0x2, 0x2, 0x2, 0x369, 0x36b, 0x3, 
    0x2, 0x2, 0x2, 0x36a, 0x357, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x368, 0x3, 
    0x2, 0x2, 0x2, 0x36b, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x353, 0x3, 
    0x2, 0x2, 0x2, 0x36d, 0x36e, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36c, 0x3, 
    0x2, 0x2, 0x2, 0x36e, 0x36f, 0x3, 0x2, 0x2, 0x2, 0x36f, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x370, 0x372, 0x5, 0x3e, 0x20, 0x2, 0x371, 0x373, 0x9, 0xb, 
    0x2, 0x2, 0x372, 0x371, 0x3, 0x2, 0x2, 0x2, 0x373, 0x374, 0x3, 0x2, 
    0x2, 0x2, 0x374, 0x372, 0x3, 0x2, 0x2, 0x2, 0x374, 0x375, 0x3, 0x2, 
    0x2, 0x2, 0x375, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x376, 0x377, 0x7, 0x22, 
    0x2, 0x2, 0x377, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x378, 0x37d, 0x7, 0x23, 
    0x2, 0x2, 0x379, 0x37a, 0x7, 0x1a, 0x2, 0x2, 0x37a, 0x37c, 0x7, 0x23, 
    0x2, 0x2, 0x37b, 0x379, 0x3, 0x2, 0x2, 0x2, 0x37c, 0x37f, 0x3, 0x2, 
    0x2, 0x2, 0x37d, 0x37b, 0x3, 0x2, 0x2, 0x2, 0x37d, 0x37e, 0x3, 0x2, 
    0x2, 0x2, 0x37e, 0x382, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x37d, 0x3, 0x2, 
    0x2, 0x2, 0x380, 0x382, 0x7, 0x22, 0x2, 0x2, 0x381, 0x378, 0x3, 0x2, 
    0x2, 0x2, 0x381, 0x380, 0x3, 0x2, 0x2, 0x2, 0x382, 0x3f, 0x3, 0x2, 0x2, 
    0x2, 0x383, 0x386, 0x3, 0x2, 0x2, 0x2, 0x384, 0x386, 0x7, 0x1a, 0x2, 
    0x2, 0x385, 0x383, 0x3, 0x2, 0x2, 0x2, 0x385, 0x384, 0x3, 0x2, 0x2, 
    0x2, 0x386, 0x41, 0x3, 0x2, 0x2, 0x2, 0x387, 0x389, 0x7, 0x1a, 0x2, 
    0x2, 0x388, 0x387, 0x3, 0x2, 0x2, 0x2, 0x389, 0x38c, 0x3, 0x2, 0x2, 
    0x2, 0x38a, 0x388, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0x3, 0x2, 0x2, 
    0x2, 0x38b, 0x38d, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38a, 0x3, 0x2, 0x2, 
    0x2, 0x38d, 0x38f, 0x7, 0x23, 0x2, 0x2, 0x38e, 0x38a, 0x3, 0x2, 0x2, 
    0x2, 0x38f, 0x390, 0x3, 0x2, 0x2, 0x2, 0x390, 0x38e, 0x3, 0x2, 0x2, 
    0x2, 0x390, 0x391, 0x3, 0x2, 0x2, 0x2, 0x391, 0x395, 0x3, 0x2, 0x2, 
    0x2, 0x392, 0x394, 0x7, 0x1a, 0x2, 0x2, 0x393, 0x392, 0x3, 0x2, 0x2, 
    0x2, 0x394, 0x397, 0x3, 0x2, 0x2, 0x2, 0x395, 0x393, 0x3, 0x2, 0x2, 
    0x2, 0x395, 0x396, 0x3, 0x2, 0x2, 0x2, 0x396, 0x3a8, 0x3, 0x2, 0x2, 
    0x2, 0x397, 0x395, 0x3, 0x2, 0x2, 0x2, 0x398, 0x39a, 0x7, 0x23, 0x2, 
    0x2, 0x399, 0x398, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x39d, 0x3, 0x2, 0x2, 
    0x2, 0x39b, 0x399, 0x3, 0x2, 0x2, 0x2, 0x39b, 0x39c, 0x3, 0x2, 0x2, 
    0x2, 0x39c, 0x39e, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39b, 0x3, 0x2, 0x2, 
    0x2, 0x39e, 0x3a2, 0x7, 0x20, 0x2, 0x2, 0x39f, 0x3a1, 0x7, 0x23, 0x2, 
    0x2, 0x3a0, 0x39f, 0x3, 0x2, 0x2, 0x2, 0x3a1, 0x3a4, 0x3, 0x2, 0x2, 
    0x2, 0x3a2, 0x3a0, 0x3, 0x2, 0x2, 0x2, 0x3a2, 0x3a3, 0x3, 0x2, 0x2, 
    0x2, 0x3a3, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x3a2, 0x3, 0x2, 0x2, 
    0x2, 0x3a5, 0x3a8, 0x7, 0x1a, 0x2, 0x2, 0x3a6, 0x3a8, 0x7, 0x1f, 0x2, 
    0x2, 0x3a7, 0x38e, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x39b, 0x3, 0x2, 0x2, 
    0x2, 0x3a7, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x3a7, 0x3a6, 0x3, 0x2, 0x2, 
    0x2, 0x3a8, 0x43, 0x3, 0x2, 0x2, 0x2, 0x3a9, 0x3ab, 0x7, 0x22, 0x2, 
    0x2, 0x3aa, 0x3a9, 0x3, 0x2, 0x2, 0x2, 0x3ab, 0x3ac, 0x3, 0x2, 0x2, 
    0x2, 0x3ac, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3ac, 0x3ad, 0x3, 0x2, 0x2, 
    0x2, 0x3ad, 0x3b0, 0x3, 0x2, 0x2, 0x2, 0x3ae, 0x3b0, 0x7, 0x1e, 0x2, 
    0x2, 0x3af, 0x3aa, 0x3, 0x2, 0x2, 0x2, 0x3af, 0x3ae, 0x3, 0x2, 0x2, 
    0x2, 0x3b0, 0x45, 0x3, 0x2, 0x2, 0x2, 0xab, 0x49, 0x4d, 0x51, 0x55, 
    0x5b, 0x63, 0x69, 0x6d, 0x73, 0x76, 0x7b, 0x7f, 0x82, 0x86, 0x89, 0x8d, 
    0x91, 0x94, 0x9a, 0x9d, 0xa1, 0xa4, 0xa8, 0xad, 0xb2, 0xb6, 0xb9, 0xbf, 
    0xc2, 0xc6, 0xc9, 0xcd, 0xd2, 0xd6, 0xda, 0xdf, 0xe3, 0xe9, 0xee, 0xf2, 
    0xf6, 0xf9, 0xfc, 0x100, 0x104, 0x108, 0x10d, 0x111, 0x114, 0x118, 0x11b, 
    0x11f, 0x122, 0x125, 0x12b, 0x12e, 0x132, 0x135, 0x139, 0x13e, 0x143, 
    0x149, 0x14f, 0x154, 0x157, 0x15b, 0x15e, 0x162, 0x166, 0x169, 0x16f, 
    0x172, 0x176, 0x179, 0x17d, 0x182, 0x187, 0x18a, 0x190, 0x193, 0x197, 
    0x19a, 0x19e, 0x1a3, 0x1a7, 0x1ac, 0x1b0, 0x1b6, 0x1bb, 0x1bf, 0x1c4, 
    0x1c7, 0x1cd, 0x1d0, 0x1d4, 0x1d7, 0x1db, 0x1e0, 0x1e7, 0x1eb, 0x1ee, 
    0x1f2, 0x1f6, 0x1f9, 0x1ff, 0x202, 0x206, 0x209, 0x20d, 0x212, 0x215, 
    0x219, 0x21e, 0x223, 0x22b, 0x231, 0x237, 0x23e, 0x244, 0x247, 0x24e, 
    0x254, 0x25c, 0x262, 0x265, 0x267, 0x270, 0x27f, 0x284, 0x28a, 0x293, 
    0x298, 0x29d, 0x2aa, 0x2b0, 0x2b6, 0x2bc, 0x2c7, 0x2d3, 0x2d8, 0x2de, 
    0x309, 0x30e, 0x313, 0x320, 0x32d, 0x32f, 0x335, 0x33d, 0x341, 0x34b, 
    0x34f, 0x355, 0x35e, 0x368, 0x36a, 0x36e, 0x374, 0x37d, 0x381, 0x385, 
    0x38a, 0x390, 0x395, 0x39b, 0x3a2, 0x3a7, 0x3ac, 0x3af, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

UserAgentParser::Initializer UserAgentParser::_init;
