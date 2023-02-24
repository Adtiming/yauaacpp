
// Generated from UserAgent.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"


namespace ycpp {


class  UserAgentParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, QUOTE1 = 2, QUOTE2 = 3, QUOTE3 = 4, QUOTE4 = 5, BAD_ESC_TAB = 6, 
    MIME_TYPE_1 = 7, MIME_TYPE_2 = 8, SPACE = 9, USERAGENT1 = 10, USERAGENT2 = 11, 
    EMAIL = 12, CURLYBRACEOPEN = 13, CURLYBRACECLOSE = 14, BRACEOPEN = 15, 
    BRACECLOSE = 16, BLOCKOPEN = 17, BLOCKCLOSE = 18, SEMICOLON = 19, COLON = 20, 
    COMMA = 21, SLASH = 22, EQUALS = 23, MINUS = 24, PLUS = 25, UUID = 26, 
    URL = 27, SPECIALVERSIONWORDS = 28, UNASSIGNEDVARIABLE = 29, GIBBERISH = 30, 
    ATSIGN = 31, VERSION = 32, WORD = 33, BASE64 = 34
  };

  enum {
    RuleUserAgent = 0, RuleRootElements = 1, RuleRootText = 2, RuleProduct = 3, 
    RuleCommentProduct = 4, RuleProductVersionWords = 5, RuleProductName = 6, 
    RuleProductNameWords = 7, RuleProductVersion = 8, RuleProductVersionWithCommas = 9, 
    RuleProductVersionSingleWord = 10, RuleSingleVersion = 11, RuleSingleVersionWithCommas = 12, 
    RuleProductNameVersion = 13, RuleProductNameEmail = 14, RuleProductNameUrl = 15, 
    RuleProductNameUuid = 16, RuleUuId = 17, RuleEmailAddress = 18, RuleSiteUrl = 19, 
    RuleBase64 = 20, RuleCommentSeparator = 21, RuleCommentBlock = 22, RuleCommentEntry = 23, 
    RuleProductNameKeyValue = 24, RuleProductNameNoVersion = 25, RuleKeyValueProductVersionName = 26, 
    RuleKeyValue = 27, RuleKeyWithoutValue = 28, RuleKeyValueVersionName = 29, 
    RuleKeyName = 30, RuleEmptyWord = 31, RuleMultipleWords = 32, RuleVersionWords = 33
  };

  UserAgentParser(antlr4::TokenStream *input);
  ~UserAgentParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class UserAgentContext;
  class RootElementsContext;
  class RootTextContext;
  class ProductContext;
  class CommentProductContext;
  class ProductVersionWordsContext;
  class ProductNameContext;
  class ProductNameWordsContext;
  class ProductVersionContext;
  class ProductVersionWithCommasContext;
  class ProductVersionSingleWordContext;
  class SingleVersionContext;
  class SingleVersionWithCommasContext;
  class ProductNameVersionContext;
  class ProductNameEmailContext;
  class ProductNameUrlContext;
  class ProductNameUuidContext;
  class UuIdContext;
  class EmailAddressContext;
  class SiteUrlContext;
  class Base64Context;
  class CommentSeparatorContext;
  class CommentBlockContext;
  class CommentEntryContext;
  class ProductNameKeyValueContext;
  class ProductNameNoVersionContext;
  class KeyValueProductVersionNameContext;
  class KeyValueContext;
  class KeyWithoutValueContext;
  class KeyValueVersionNameContext;
  class KeyNameContext;
  class EmptyWordContext;
  class MultipleWordsContext;
  class VersionWordsContext; 

  class  UserAgentContext : public antlr4::ParserRuleContext {
  public:
    UserAgentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUS();
    antlr4::tree::TerminalNode* PLUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QUOTE4();
    antlr4::tree::TerminalNode* QUOTE4(size_t i);
    std::vector<antlr4::tree::TerminalNode *> QUOTE2();
    antlr4::tree::TerminalNode* QUOTE2(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALS();
    antlr4::tree::TerminalNode* EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BRACEOPEN();
    antlr4::tree::TerminalNode* BRACEOPEN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BLOCKOPEN();
    antlr4::tree::TerminalNode* BLOCKOPEN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BRACECLOSE();
    antlr4::tree::TerminalNode* BRACECLOSE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> BLOCKCLOSE();
    antlr4::tree::TerminalNode* BLOCKCLOSE(size_t i);
    std::vector<ProductContext *> product();
    ProductContext* product(size_t i);
    std::vector<RootElementsContext *> rootElements();
    RootElementsContext* rootElements(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UserAgentContext* userAgent();

  class  RootElementsContext : public antlr4::ParserRuleContext {
  public:
    RootElementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KeyValueContext *keyValue();
    SiteUrlContext *siteUrl();
    EmailAddressContext *emailAddress();
    UuIdContext *uuId();
    RootTextContext *rootText();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RootElementsContext* rootElements();

  class  RootTextContext : public antlr4::ParserRuleContext {
  public:
    RootTextContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERSION();
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    antlr4::tree::TerminalNode *GIBBERISH();
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RootTextContext* rootText();

  class  ProductContext : public antlr4::ParserRuleContext {
  public:
    ProductContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProductNameContext *productName();
    std::vector<ProductVersionContext *> productVersion();
    ProductVersionContext* productVersion(size_t i);
    std::vector<CommentBlockContext *> commentBlock();
    CommentBlockContext* commentBlock(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SLASH();
    antlr4::tree::TerminalNode* SLASH(size_t i);
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ATSIGN();
    antlr4::tree::TerminalNode* ATSIGN(size_t i);
    std::vector<ProductVersionWithCommasContext *> productVersionWithCommas();
    ProductVersionWithCommasContext* productVersionWithCommas(size_t i);
    std::vector<ProductVersionSingleWordContext *> productVersionSingleWord();
    ProductVersionSingleWordContext* productVersionSingleWord(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALS();
    antlr4::tree::TerminalNode* EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    std::vector<ProductVersionWordsContext *> productVersionWords();
    ProductVersionWordsContext* productVersionWords(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductContext* product();

  class  CommentProductContext : public antlr4::ParserRuleContext {
  public:
    CommentProductContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProductNameContext *productName();
    std::vector<ProductVersionWithCommasContext *> productVersionWithCommas();
    ProductVersionWithCommasContext* productVersionWithCommas(size_t i);
    std::vector<CommentBlockContext *> commentBlock();
    CommentBlockContext* commentBlock(size_t i);
    std::vector<ProductVersionSingleWordContext *> productVersionSingleWord();
    ProductVersionSingleWordContext* productVersionSingleWord(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALS();
    antlr4::tree::TerminalNode* EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SLASH();
    antlr4::tree::TerminalNode* SLASH(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ATSIGN();
    antlr4::tree::TerminalNode* ATSIGN(size_t i);
    std::vector<ProductVersionWordsContext *> productVersionWords();
    ProductVersionWordsContext* productVersionWords(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommentProductContext* commentProduct();

  class  ProductVersionWordsContext : public antlr4::ParserRuleContext {
  public:
    ProductVersionWordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    antlr4::tree::TerminalNode *UNASSIGNEDVARIABLE();
    antlr4::tree::TerminalNode *SPECIALVERSIONWORDS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductVersionWordsContext* productVersionWords();

  class  ProductNameContext : public antlr4::ParserRuleContext {
  public:
    ProductNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProductNameKeyValueContext *productNameKeyValue();
    ProductNameEmailContext *productNameEmail();
    ProductNameUrlContext *productNameUrl();
    ProductNameVersionContext *productNameVersion();
    ProductNameUuidContext *productNameUuid();
    ProductNameWordsContext *productNameWords();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductNameContext* productName();

  class  ProductNameWordsContext : public antlr4::ParserRuleContext {
  public:
    ProductNameWordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);
    antlr4::tree::TerminalNode *CURLYBRACEOPEN();
    antlr4::tree::TerminalNode *CURLYBRACECLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductNameWordsContext* productNameWords();

  class  ProductVersionContext : public antlr4::ParserRuleContext {
  public:
    ProductVersionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KeyValueContext *keyValue();
    EmailAddressContext *emailAddress();
    SiteUrlContext *siteUrl();
    UuIdContext *uuId();
    Base64Context *base64();
    SingleVersionContext *singleVersion();
    antlr4::tree::TerminalNode *SPECIALVERSIONWORDS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductVersionContext* productVersion();

  class  ProductVersionWithCommasContext : public antlr4::ParserRuleContext {
  public:
    ProductVersionWithCommasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<KeyValueContext *> keyValue();
    KeyValueContext* keyValue(size_t i);
    EmailAddressContext *emailAddress();
    SiteUrlContext *siteUrl();
    UuIdContext *uuId();
    Base64Context *base64();
    SingleVersionWithCommasContext *singleVersionWithCommas();
    antlr4::tree::TerminalNode *SPECIALVERSIONWORDS();
    antlr4::tree::TerminalNode *CURLYBRACEOPEN();
    antlr4::tree::TerminalNode *CURLYBRACECLOSE();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductVersionWithCommasContext* productVersionWithCommas();

  class  ProductVersionSingleWordContext : public antlr4::ParserRuleContext {
  public:
    ProductVersionSingleWordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WORD();
    antlr4::tree::TerminalNode *CURLYBRACEOPEN();
    antlr4::tree::TerminalNode *CURLYBRACECLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductVersionSingleWordContext* productVersionSingleWord();

  class  SingleVersionContext : public antlr4::ParserRuleContext {
  public:
    SingleVersionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERSION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SingleVersionContext* singleVersion();

  class  SingleVersionWithCommasContext : public antlr4::ParserRuleContext {
  public:
    SingleVersionWithCommasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> VERSION();
    antlr4::tree::TerminalNode* VERSION(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SingleVersionWithCommasContext* singleVersionWithCommas();

  class  ProductNameVersionContext : public antlr4::ParserRuleContext {
  public:
    ProductNameVersionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERSION();
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductNameVersionContext* productNameVersion();

  class  ProductNameEmailContext : public antlr4::ParserRuleContext {
  public:
    ProductNameEmailContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EmailAddressContext *emailAddress();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductNameEmailContext* productNameEmail();

  class  ProductNameUrlContext : public antlr4::ParserRuleContext {
  public:
    ProductNameUrlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SiteUrlContext *siteUrl();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductNameUrlContext* productNameUrl();

  class  ProductNameUuidContext : public antlr4::ParserRuleContext {
  public:
    ProductNameUuidContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UuIdContext *uuId();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductNameUuidContext* productNameUuid();

  class  UuIdContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *uuid = nullptr;;
    UuIdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *UUID();
    antlr4::tree::TerminalNode *CURLYBRACEOPEN();
    antlr4::tree::TerminalNode *CURLYBRACECLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UuIdContext* uuId();

  class  EmailAddressContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *email = nullptr;;
    EmailAddressContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EMAIL();
    antlr4::tree::TerminalNode *CURLYBRACEOPEN();
    antlr4::tree::TerminalNode *CURLYBRACECLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmailAddressContext* emailAddress();

  class  SiteUrlContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *url = nullptr;;
    SiteUrlContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *URL();
    antlr4::tree::TerminalNode *CURLYBRACEOPEN();
    antlr4::tree::TerminalNode *CURLYBRACECLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SiteUrlContext* siteUrl();

  class  Base64Context : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *value = nullptr;;
    Base64Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BASE64();
    antlr4::tree::TerminalNode *CURLYBRACEOPEN();
    antlr4::tree::TerminalNode *CURLYBRACECLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Base64Context* base64();

  class  CommentSeparatorContext : public antlr4::ParserRuleContext {
  public:
    CommentSeparatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommentSeparatorContext* commentSeparator();

  class  CommentBlockContext : public antlr4::ParserRuleContext {
  public:
    CommentBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BRACEOPEN();
    std::vector<CommentEntryContext *> commentEntry();
    CommentEntryContext* commentEntry(size_t i);
    antlr4::tree::TerminalNode *BRACECLOSE();
    antlr4::tree::TerminalNode *EOF();
    std::vector<CommentSeparatorContext *> commentSeparator();
    CommentSeparatorContext* commentSeparator(size_t i);
    antlr4::tree::TerminalNode *BLOCKOPEN();
    antlr4::tree::TerminalNode *BLOCKCLOSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommentBlockContext* commentBlock();

  class  CommentEntryContext : public antlr4::ParserRuleContext {
  public:
    CommentEntryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    EmptyWordContext *emptyWord();
    std::vector<MultipleWordsContext *> multipleWords();
    MultipleWordsContext* multipleWords(size_t i);
    ProductNameNoVersionContext *productNameNoVersion();
    KeyWithoutValueContext *keyWithoutValue();
    std::vector<antlr4::tree::TerminalNode *> CURLYBRACEOPEN();
    antlr4::tree::TerminalNode* CURLYBRACEOPEN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CURLYBRACECLOSE();
    antlr4::tree::TerminalNode* CURLYBRACECLOSE(size_t i);
    std::vector<CommentProductContext *> commentProduct();
    CommentProductContext* commentProduct(size_t i);
    std::vector<KeyValueContext *> keyValue();
    KeyValueContext* keyValue(size_t i);
    std::vector<UuIdContext *> uuId();
    UuIdContext* uuId(size_t i);
    std::vector<SiteUrlContext *> siteUrl();
    SiteUrlContext* siteUrl(size_t i);
    std::vector<EmailAddressContext *> emailAddress();
    EmailAddressContext* emailAddress(size_t i);
    std::vector<VersionWordsContext *> versionWords();
    VersionWordsContext* versionWords(size_t i);
    std::vector<Base64Context *> base64();
    Base64Context* base64(size_t i);
    std::vector<CommentBlockContext *> commentBlock();
    CommentBlockContext* commentBlock(size_t i);
    std::vector<antlr4::tree::TerminalNode *> UNASSIGNEDVARIABLE();
    antlr4::tree::TerminalNode* UNASSIGNEDVARIABLE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CommentEntryContext* commentEntry();

  class  ProductNameKeyValueContext : public antlr4::ParserRuleContext {
  public:
    UserAgentParser::KeyNameContext *key = nullptr;;
    ProductNameKeyValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KeyNameContext *keyName();
    std::vector<UuIdContext *> uuId();
    UuIdContext* uuId(size_t i);
    std::vector<SiteUrlContext *> siteUrl();
    SiteUrlContext* siteUrl(size_t i);
    std::vector<EmailAddressContext *> emailAddress();
    EmailAddressContext* emailAddress(size_t i);
    std::vector<MultipleWordsContext *> multipleWords();
    MultipleWordsContext* multipleWords(size_t i);
    std::vector<Base64Context *> base64();
    Base64Context* base64(size_t i);
    std::vector<KeyValueProductVersionNameContext *> keyValueProductVersionName();
    KeyValueProductVersionNameContext* keyValueProductVersionName(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALS();
    antlr4::tree::TerminalNode* EQUALS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductNameKeyValueContext* productNameKeyValue();

  class  ProductNameNoVersionContext : public antlr4::ParserRuleContext {
  public:
    ProductNameNoVersionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProductNameContext *productName();
    antlr4::tree::TerminalNode *SLASH();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProductNameNoVersionContext* productNameNoVersion();

  class  KeyValueProductVersionNameContext : public antlr4::ParserRuleContext {
  public:
    KeyValueProductVersionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERSION();
    std::vector<antlr4::tree::TerminalNode *> SLASH();
    antlr4::tree::TerminalNode* SLASH(size_t i);
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeyValueProductVersionNameContext* keyValueProductVersionName();

  class  KeyValueContext : public antlr4::ParserRuleContext {
  public:
    UserAgentParser::KeyNameContext *key = nullptr;;
    KeyValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KeyNameContext *keyName();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALS();
    antlr4::tree::TerminalNode* EQUALS(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CURLYBRACEOPEN();
    antlr4::tree::TerminalNode* CURLYBRACEOPEN(size_t i);
    std::vector<antlr4::tree::TerminalNode *> CURLYBRACECLOSE();
    antlr4::tree::TerminalNode* CURLYBRACECLOSE(size_t i);
    std::vector<UuIdContext *> uuId();
    UuIdContext* uuId(size_t i);
    std::vector<SiteUrlContext *> siteUrl();
    SiteUrlContext* siteUrl(size_t i);
    std::vector<EmailAddressContext *> emailAddress();
    EmailAddressContext* emailAddress(size_t i);
    std::vector<MultipleWordsContext *> multipleWords();
    MultipleWordsContext* multipleWords(size_t i);
    std::vector<Base64Context *> base64();
    Base64Context* base64(size_t i);
    std::vector<KeyValueVersionNameContext *> keyValueVersionName();
    KeyValueVersionNameContext* keyValueVersionName(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeyValueContext* keyValue();

  class  KeyWithoutValueContext : public antlr4::ParserRuleContext {
  public:
    UserAgentParser::KeyNameContext *key = nullptr;;
    KeyWithoutValueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    KeyNameContext *keyName();
    std::vector<antlr4::tree::TerminalNode *> COLON();
    antlr4::tree::TerminalNode* COLON(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EQUALS();
    antlr4::tree::TerminalNode* EQUALS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeyWithoutValueContext* keyWithoutValue();

  class  KeyValueVersionNameContext : public antlr4::ParserRuleContext {
  public:
    KeyValueVersionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VERSION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeyValueVersionNameContext* keyValueVersionName();

  class  KeyNameContext : public antlr4::ParserRuleContext {
  public:
    KeyNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    antlr4::tree::TerminalNode *VERSION();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeyNameContext* keyName();

  class  EmptyWordContext : public antlr4::ParserRuleContext {
  public:
    EmptyWordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MINUS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmptyWordContext* emptyWord();

  class  MultipleWordsContext : public antlr4::ParserRuleContext {
  public:
    MultipleWordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> WORD();
    antlr4::tree::TerminalNode* WORD(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUS();
    antlr4::tree::TerminalNode* MINUS(size_t i);
    antlr4::tree::TerminalNode *GIBBERISH();
    antlr4::tree::TerminalNode *UNASSIGNEDVARIABLE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MultipleWordsContext* multipleWords();

  class  VersionWordsContext : public antlr4::ParserRuleContext {
  public:
    VersionWordsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> VERSION();
    antlr4::tree::TerminalNode* VERSION(size_t i);
    antlr4::tree::TerminalNode *SPECIALVERSIONWORDS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VersionWordsContext* versionWords();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace ycpp
