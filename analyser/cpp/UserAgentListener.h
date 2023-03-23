
// Generated from UserAgent.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "UserAgentParser.h"


namespace ycpp {

/**
 * This interface defines an abstract listener for a parse tree produced by UserAgentParser.
 */
class  UserAgentListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterUserAgent(UserAgentParser::UserAgentContext *ctx) = 0;
  virtual void exitUserAgent(UserAgentParser::UserAgentContext *ctx) = 0;

  virtual void enterRootElements(UserAgentParser::RootElementsContext *ctx) = 0;
  virtual void exitRootElements(UserAgentParser::RootElementsContext *ctx) = 0;

  virtual void enterRootText(UserAgentParser::RootTextContext *ctx) = 0;
  virtual void exitRootText(UserAgentParser::RootTextContext *ctx) = 0;

  virtual void enterProduct(UserAgentParser::ProductContext *ctx) = 0;
  virtual void exitProduct(UserAgentParser::ProductContext *ctx) = 0;

  virtual void enterCommentProduct(UserAgentParser::CommentProductContext *ctx) = 0;
  virtual void exitCommentProduct(UserAgentParser::CommentProductContext *ctx) = 0;

  virtual void enterProductVersionWords(UserAgentParser::ProductVersionWordsContext *ctx) = 0;
  virtual void exitProductVersionWords(UserAgentParser::ProductVersionWordsContext *ctx) = 0;

  virtual void enterProductName(UserAgentParser::ProductNameContext *ctx) = 0;
  virtual void exitProductName(UserAgentParser::ProductNameContext *ctx) = 0;

  virtual void enterProductNameWords(UserAgentParser::ProductNameWordsContext *ctx) = 0;
  virtual void exitProductNameWords(UserAgentParser::ProductNameWordsContext *ctx) = 0;

  virtual void enterProductVersion(UserAgentParser::ProductVersionContext *ctx) = 0;
  virtual void exitProductVersion(UserAgentParser::ProductVersionContext *ctx) = 0;

  virtual void enterProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext *ctx) = 0;
  virtual void exitProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext *ctx) = 0;

  virtual void enterProductVersionSingleWord(UserAgentParser::ProductVersionSingleWordContext *ctx) = 0;
  virtual void exitProductVersionSingleWord(UserAgentParser::ProductVersionSingleWordContext *ctx) = 0;

  virtual void enterSingleVersion(UserAgentParser::SingleVersionContext *ctx) = 0;
  virtual void exitSingleVersion(UserAgentParser::SingleVersionContext *ctx) = 0;

  virtual void enterSingleVersionWithCommas(UserAgentParser::SingleVersionWithCommasContext *ctx) = 0;
  virtual void exitSingleVersionWithCommas(UserAgentParser::SingleVersionWithCommasContext *ctx) = 0;

  virtual void enterProductNameVersion(UserAgentParser::ProductNameVersionContext *ctx) = 0;
  virtual void exitProductNameVersion(UserAgentParser::ProductNameVersionContext *ctx) = 0;

  virtual void enterProductNameEmail(UserAgentParser::ProductNameEmailContext *ctx) = 0;
  virtual void exitProductNameEmail(UserAgentParser::ProductNameEmailContext *ctx) = 0;

  virtual void enterProductNameUrl(UserAgentParser::ProductNameUrlContext *ctx) = 0;
  virtual void exitProductNameUrl(UserAgentParser::ProductNameUrlContext *ctx) = 0;

  virtual void enterProductNameUuid(UserAgentParser::ProductNameUuidContext *ctx) = 0;
  virtual void exitProductNameUuid(UserAgentParser::ProductNameUuidContext *ctx) = 0;

  virtual void enterUuId(UserAgentParser::UuIdContext *ctx) = 0;
  virtual void exitUuId(UserAgentParser::UuIdContext *ctx) = 0;

  virtual void enterEmailAddress(UserAgentParser::EmailAddressContext *ctx) = 0;
  virtual void exitEmailAddress(UserAgentParser::EmailAddressContext *ctx) = 0;

  virtual void enterSiteUrl(UserAgentParser::SiteUrlContext *ctx) = 0;
  virtual void exitSiteUrl(UserAgentParser::SiteUrlContext *ctx) = 0;

  virtual void enterBase64(UserAgentParser::Base64Context *ctx) = 0;
  virtual void exitBase64(UserAgentParser::Base64Context *ctx) = 0;

  virtual void enterCommentSeparator(UserAgentParser::CommentSeparatorContext *ctx) = 0;
  virtual void exitCommentSeparator(UserAgentParser::CommentSeparatorContext *ctx) = 0;

  virtual void enterCommentBlock(UserAgentParser::CommentBlockContext *ctx) = 0;
  virtual void exitCommentBlock(UserAgentParser::CommentBlockContext *ctx) = 0;

  virtual void enterCommentEntry(UserAgentParser::CommentEntryContext *ctx) = 0;
  virtual void exitCommentEntry(UserAgentParser::CommentEntryContext *ctx) = 0;

  virtual void enterProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext *ctx) = 0;
  virtual void exitProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext *ctx) = 0;

  virtual void enterProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext *ctx) = 0;
  virtual void exitProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext *ctx) = 0;

  virtual void enterKeyValueProductVersionName(UserAgentParser::KeyValueProductVersionNameContext *ctx) = 0;
  virtual void exitKeyValueProductVersionName(UserAgentParser::KeyValueProductVersionNameContext *ctx) = 0;

  virtual void enterKeyValue(UserAgentParser::KeyValueContext *ctx) = 0;
  virtual void exitKeyValue(UserAgentParser::KeyValueContext *ctx) = 0;

  virtual void enterKeyWithoutValue(UserAgentParser::KeyWithoutValueContext *ctx) = 0;
  virtual void exitKeyWithoutValue(UserAgentParser::KeyWithoutValueContext *ctx) = 0;

  virtual void enterKeyValueVersionName(UserAgentParser::KeyValueVersionNameContext *ctx) = 0;
  virtual void exitKeyValueVersionName(UserAgentParser::KeyValueVersionNameContext *ctx) = 0;

  virtual void enterKeyName(UserAgentParser::KeyNameContext *ctx) = 0;
  virtual void exitKeyName(UserAgentParser::KeyNameContext *ctx) = 0;

  virtual void enterEmptyWord(UserAgentParser::EmptyWordContext *ctx) = 0;
  virtual void exitEmptyWord(UserAgentParser::EmptyWordContext *ctx) = 0;

  virtual void enterMultipleWords(UserAgentParser::MultipleWordsContext *ctx) = 0;
  virtual void exitMultipleWords(UserAgentParser::MultipleWordsContext *ctx) = 0;

  virtual void enterVersionWords(UserAgentParser::VersionWordsContext *ctx) = 0;
  virtual void exitVersionWords(UserAgentParser::VersionWordsContext *ctx) = 0;


};

}  // namespace ycpp
