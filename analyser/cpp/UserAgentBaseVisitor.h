
// Generated from UserAgent.g4 by ANTLR 4.12.0

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

  virtual std::any visitUserAgent(UserAgentParser::UserAgentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRootElements(UserAgentParser::RootElementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRootText(UserAgentParser::RootTextContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProduct(UserAgentParser::ProductContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommentProduct(UserAgentParser::CommentProductContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductVersionWords(UserAgentParser::ProductVersionWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductName(UserAgentParser::ProductNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductNameWords(UserAgentParser::ProductNameWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductVersion(UserAgentParser::ProductVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductVersionSingleWord(UserAgentParser::ProductVersionSingleWordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleVersion(UserAgentParser::SingleVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSingleVersionWithCommas(UserAgentParser::SingleVersionWithCommasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductNameVersion(UserAgentParser::ProductNameVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductNameEmail(UserAgentParser::ProductNameEmailContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductNameUrl(UserAgentParser::ProductNameUrlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductNameUuid(UserAgentParser::ProductNameUuidContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUuId(UserAgentParser::UuIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmailAddress(UserAgentParser::EmailAddressContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSiteUrl(UserAgentParser::SiteUrlContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBase64(UserAgentParser::Base64Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommentSeparator(UserAgentParser::CommentSeparatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommentBlock(UserAgentParser::CommentBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCommentEntry(UserAgentParser::CommentEntryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyValueProductVersionName(UserAgentParser::KeyValueProductVersionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyValue(UserAgentParser::KeyValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyWithoutValue(UserAgentParser::KeyWithoutValueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyValueVersionName(UserAgentParser::KeyValueVersionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitKeyName(UserAgentParser::KeyNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEmptyWord(UserAgentParser::EmptyWordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMultipleWords(UserAgentParser::MultipleWordsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVersionWords(UserAgentParser::VersionWordsContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace ycpp
