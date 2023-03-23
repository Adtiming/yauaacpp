
// Generated from UserAgent.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"
#include "UserAgentParser.h"


namespace ycpp {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by UserAgentParser.
 */
class  UserAgentVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by UserAgentParser.
   */
    virtual std::any visitUserAgent(UserAgentParser::UserAgentContext *context) = 0;

    virtual std::any visitRootElements(UserAgentParser::RootElementsContext *context) = 0;

    virtual std::any visitRootText(UserAgentParser::RootTextContext *context) = 0;

    virtual std::any visitProduct(UserAgentParser::ProductContext *context) = 0;

    virtual std::any visitCommentProduct(UserAgentParser::CommentProductContext *context) = 0;

    virtual std::any visitProductVersionWords(UserAgentParser::ProductVersionWordsContext *context) = 0;

    virtual std::any visitProductName(UserAgentParser::ProductNameContext *context) = 0;

    virtual std::any visitProductNameWords(UserAgentParser::ProductNameWordsContext *context) = 0;

    virtual std::any visitProductVersion(UserAgentParser::ProductVersionContext *context) = 0;

    virtual std::any visitProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext *context) = 0;

    virtual std::any visitProductVersionSingleWord(UserAgentParser::ProductVersionSingleWordContext *context) = 0;

    virtual std::any visitSingleVersion(UserAgentParser::SingleVersionContext *context) = 0;

    virtual std::any visitSingleVersionWithCommas(UserAgentParser::SingleVersionWithCommasContext *context) = 0;

    virtual std::any visitProductNameVersion(UserAgentParser::ProductNameVersionContext *context) = 0;

    virtual std::any visitProductNameEmail(UserAgentParser::ProductNameEmailContext *context) = 0;

    virtual std::any visitProductNameUrl(UserAgentParser::ProductNameUrlContext *context) = 0;

    virtual std::any visitProductNameUuid(UserAgentParser::ProductNameUuidContext *context) = 0;

    virtual std::any visitUuId(UserAgentParser::UuIdContext *context) = 0;

    virtual std::any visitEmailAddress(UserAgentParser::EmailAddressContext *context) = 0;

    virtual std::any visitSiteUrl(UserAgentParser::SiteUrlContext *context) = 0;

    virtual std::any visitBase64(UserAgentParser::Base64Context *context) = 0;

    virtual std::any visitCommentSeparator(UserAgentParser::CommentSeparatorContext *context) = 0;

    virtual std::any visitCommentBlock(UserAgentParser::CommentBlockContext *context) = 0;

    virtual std::any visitCommentEntry(UserAgentParser::CommentEntryContext *context) = 0;

    virtual std::any visitProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext *context) = 0;

    virtual std::any visitProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext *context) = 0;

    virtual std::any visitKeyValueProductVersionName(UserAgentParser::KeyValueProductVersionNameContext *context) = 0;

    virtual std::any visitKeyValue(UserAgentParser::KeyValueContext *context) = 0;

    virtual std::any visitKeyWithoutValue(UserAgentParser::KeyWithoutValueContext *context) = 0;

    virtual std::any visitKeyValueVersionName(UserAgentParser::KeyValueVersionNameContext *context) = 0;

    virtual std::any visitKeyName(UserAgentParser::KeyNameContext *context) = 0;

    virtual std::any visitEmptyWord(UserAgentParser::EmptyWordContext *context) = 0;

    virtual std::any visitMultipleWords(UserAgentParser::MultipleWordsContext *context) = 0;

    virtual std::any visitVersionWords(UserAgentParser::VersionWordsContext *context) = 0;


};

}  // namespace ycpp
