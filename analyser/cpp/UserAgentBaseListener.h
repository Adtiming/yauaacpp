
// Generated from UserAgent.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "UserAgentListener.h"


namespace ycpp {

/**
 * This class provides an empty implementation of UserAgentListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  UserAgentBaseListener : public UserAgentListener {
public:

  virtual void enterUserAgent(UserAgentParser::UserAgentContext * /*ctx*/) override { }
  virtual void exitUserAgent(UserAgentParser::UserAgentContext * /*ctx*/) override { }

  virtual void enterRootElements(UserAgentParser::RootElementsContext * /*ctx*/) override { }
  virtual void exitRootElements(UserAgentParser::RootElementsContext * /*ctx*/) override { }

  virtual void enterRootText(UserAgentParser::RootTextContext * /*ctx*/) override { }
  virtual void exitRootText(UserAgentParser::RootTextContext * /*ctx*/) override { }

  virtual void enterProduct(UserAgentParser::ProductContext * /*ctx*/) override { }
  virtual void exitProduct(UserAgentParser::ProductContext * /*ctx*/) override { }

  virtual void enterCommentProduct(UserAgentParser::CommentProductContext * /*ctx*/) override { }
  virtual void exitCommentProduct(UserAgentParser::CommentProductContext * /*ctx*/) override { }

  virtual void enterProductVersionWords(UserAgentParser::ProductVersionWordsContext * /*ctx*/) override { }
  virtual void exitProductVersionWords(UserAgentParser::ProductVersionWordsContext * /*ctx*/) override { }

  virtual void enterProductName(UserAgentParser::ProductNameContext * /*ctx*/) override { }
  virtual void exitProductName(UserAgentParser::ProductNameContext * /*ctx*/) override { }

  virtual void enterProductNameWords(UserAgentParser::ProductNameWordsContext * /*ctx*/) override { }
  virtual void exitProductNameWords(UserAgentParser::ProductNameWordsContext * /*ctx*/) override { }

  virtual void enterProductVersion(UserAgentParser::ProductVersionContext * /*ctx*/) override { }
  virtual void exitProductVersion(UserAgentParser::ProductVersionContext * /*ctx*/) override { }

  virtual void enterProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext * /*ctx*/) override { }
  virtual void exitProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext * /*ctx*/) override { }

  virtual void enterProductVersionSingleWord(UserAgentParser::ProductVersionSingleWordContext * /*ctx*/) override { }
  virtual void exitProductVersionSingleWord(UserAgentParser::ProductVersionSingleWordContext * /*ctx*/) override { }

  virtual void enterSingleVersion(UserAgentParser::SingleVersionContext * /*ctx*/) override { }
  virtual void exitSingleVersion(UserAgentParser::SingleVersionContext * /*ctx*/) override { }

  virtual void enterSingleVersionWithCommas(UserAgentParser::SingleVersionWithCommasContext * /*ctx*/) override { }
  virtual void exitSingleVersionWithCommas(UserAgentParser::SingleVersionWithCommasContext * /*ctx*/) override { }

  virtual void enterProductNameVersion(UserAgentParser::ProductNameVersionContext * /*ctx*/) override { }
  virtual void exitProductNameVersion(UserAgentParser::ProductNameVersionContext * /*ctx*/) override { }

  virtual void enterProductNameEmail(UserAgentParser::ProductNameEmailContext * /*ctx*/) override { }
  virtual void exitProductNameEmail(UserAgentParser::ProductNameEmailContext * /*ctx*/) override { }

  virtual void enterProductNameUrl(UserAgentParser::ProductNameUrlContext * /*ctx*/) override { }
  virtual void exitProductNameUrl(UserAgentParser::ProductNameUrlContext * /*ctx*/) override { }

  virtual void enterProductNameUuid(UserAgentParser::ProductNameUuidContext * /*ctx*/) override { }
  virtual void exitProductNameUuid(UserAgentParser::ProductNameUuidContext * /*ctx*/) override { }

  virtual void enterUuId(UserAgentParser::UuIdContext * /*ctx*/) override { }
  virtual void exitUuId(UserAgentParser::UuIdContext * /*ctx*/) override { }

  virtual void enterEmailAddress(UserAgentParser::EmailAddressContext * /*ctx*/) override { }
  virtual void exitEmailAddress(UserAgentParser::EmailAddressContext * /*ctx*/) override { }

  virtual void enterSiteUrl(UserAgentParser::SiteUrlContext * /*ctx*/) override { }
  virtual void exitSiteUrl(UserAgentParser::SiteUrlContext * /*ctx*/) override { }

  virtual void enterBase64(UserAgentParser::Base64Context * /*ctx*/) override { }
  virtual void exitBase64(UserAgentParser::Base64Context * /*ctx*/) override { }

  virtual void enterCommentSeparator(UserAgentParser::CommentSeparatorContext * /*ctx*/) override { }
  virtual void exitCommentSeparator(UserAgentParser::CommentSeparatorContext * /*ctx*/) override { }

  virtual void enterCommentBlock(UserAgentParser::CommentBlockContext * /*ctx*/) override { }
  virtual void exitCommentBlock(UserAgentParser::CommentBlockContext * /*ctx*/) override { }

  virtual void enterCommentEntry(UserAgentParser::CommentEntryContext * /*ctx*/) override { }
  virtual void exitCommentEntry(UserAgentParser::CommentEntryContext * /*ctx*/) override { }

  virtual void enterProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext * /*ctx*/) override { }
  virtual void exitProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext * /*ctx*/) override { }

  virtual void enterProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext * /*ctx*/) override { }
  virtual void exitProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext * /*ctx*/) override { }

  virtual void enterKeyValueProductVersionName(UserAgentParser::KeyValueProductVersionNameContext * /*ctx*/) override { }
  virtual void exitKeyValueProductVersionName(UserAgentParser::KeyValueProductVersionNameContext * /*ctx*/) override { }

  virtual void enterKeyValue(UserAgentParser::KeyValueContext * /*ctx*/) override { }
  virtual void exitKeyValue(UserAgentParser::KeyValueContext * /*ctx*/) override { }

  virtual void enterKeyWithoutValue(UserAgentParser::KeyWithoutValueContext * /*ctx*/) override { }
  virtual void exitKeyWithoutValue(UserAgentParser::KeyWithoutValueContext * /*ctx*/) override { }

  virtual void enterKeyValueVersionName(UserAgentParser::KeyValueVersionNameContext * /*ctx*/) override { }
  virtual void exitKeyValueVersionName(UserAgentParser::KeyValueVersionNameContext * /*ctx*/) override { }

  virtual void enterKeyName(UserAgentParser::KeyNameContext * /*ctx*/) override { }
  virtual void exitKeyName(UserAgentParser::KeyNameContext * /*ctx*/) override { }

  virtual void enterEmptyWord(UserAgentParser::EmptyWordContext * /*ctx*/) override { }
  virtual void exitEmptyWord(UserAgentParser::EmptyWordContext * /*ctx*/) override { }

  virtual void enterMultipleWords(UserAgentParser::MultipleWordsContext * /*ctx*/) override { }
  virtual void exitMultipleWords(UserAgentParser::MultipleWordsContext * /*ctx*/) override { }

  virtual void enterVersionWords(UserAgentParser::VersionWordsContext * /*ctx*/) override { }
  virtual void exitVersionWords(UserAgentParser::VersionWordsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace ycpp
