
// Generated from UserAgent.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "UserAgentVisitor.h"


namespace ycpp {

/**
 * This class provides an empty implementation of UserAgentVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  UserAgentBaseVisitor : public UserAgentVisitor {
public:

  virtual antlrcpp::Any visitUserAgent(UserAgentParser::UserAgentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRootElements(UserAgentParser::RootElementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRootText(UserAgentParser::RootTextContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProduct(UserAgentParser::ProductContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommentProduct(UserAgentParser::CommentProductContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductVersionWords(UserAgentParser::ProductVersionWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductName(UserAgentParser::ProductNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductNameWords(UserAgentParser::ProductNameWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductVersion(UserAgentParser::ProductVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductVersionSingleWord(UserAgentParser::ProductVersionSingleWordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleVersion(UserAgentParser::SingleVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleVersionWithCommas(UserAgentParser::SingleVersionWithCommasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductNameVersion(UserAgentParser::ProductNameVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductNameEmail(UserAgentParser::ProductNameEmailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductNameUrl(UserAgentParser::ProductNameUrlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductNameUuid(UserAgentParser::ProductNameUuidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUuId(UserAgentParser::UuIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmailAddress(UserAgentParser::EmailAddressContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSiteUrl(UserAgentParser::SiteUrlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBase64(UserAgentParser::Base64Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommentSeparator(UserAgentParser::CommentSeparatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommentBlock(UserAgentParser::CommentBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCommentEntry(UserAgentParser::CommentEntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyValueProductVersionName(UserAgentParser::KeyValueProductVersionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyValue(UserAgentParser::KeyValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyWithoutValue(UserAgentParser::KeyWithoutValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyValueVersionName(UserAgentParser::KeyValueVersionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyName(UserAgentParser::KeyNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyWord(UserAgentParser::EmptyWordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultipleWords(UserAgentParser::MultipleWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVersionWords(UserAgentParser::VersionWordsContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace ycpp
