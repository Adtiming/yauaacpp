
// Generated from UserAgent.g4 by ANTLR 4.7.2

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
    virtual antlrcpp::Any visitUserAgent(UserAgentParser::UserAgentContext *context) = 0;

    virtual antlrcpp::Any visitRootElements(UserAgentParser::RootElementsContext *context) = 0;

    virtual antlrcpp::Any visitRootText(UserAgentParser::RootTextContext *context) = 0;

    virtual antlrcpp::Any visitProduct(UserAgentParser::ProductContext *context) = 0;

    virtual antlrcpp::Any visitCommentProduct(UserAgentParser::CommentProductContext *context) = 0;

    virtual antlrcpp::Any visitProductVersionWords(UserAgentParser::ProductVersionWordsContext *context) = 0;

    virtual antlrcpp::Any visitProductName(UserAgentParser::ProductNameContext *context) = 0;

    virtual antlrcpp::Any visitProductNameWords(UserAgentParser::ProductNameWordsContext *context) = 0;

    virtual antlrcpp::Any visitProductVersion(UserAgentParser::ProductVersionContext *context) = 0;

    virtual antlrcpp::Any visitProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext *context) = 0;

    virtual antlrcpp::Any visitProductVersionSingleWord(UserAgentParser::ProductVersionSingleWordContext *context) = 0;

    virtual antlrcpp::Any visitSingleVersion(UserAgentParser::SingleVersionContext *context) = 0;

    virtual antlrcpp::Any visitSingleVersionWithCommas(UserAgentParser::SingleVersionWithCommasContext *context) = 0;

    virtual antlrcpp::Any visitProductNameVersion(UserAgentParser::ProductNameVersionContext *context) = 0;

    virtual antlrcpp::Any visitProductNameEmail(UserAgentParser::ProductNameEmailContext *context) = 0;

    virtual antlrcpp::Any visitProductNameUrl(UserAgentParser::ProductNameUrlContext *context) = 0;

    virtual antlrcpp::Any visitProductNameUuid(UserAgentParser::ProductNameUuidContext *context) = 0;

    virtual antlrcpp::Any visitUuId(UserAgentParser::UuIdContext *context) = 0;

    virtual antlrcpp::Any visitEmailAddress(UserAgentParser::EmailAddressContext *context) = 0;

    virtual antlrcpp::Any visitSiteUrl(UserAgentParser::SiteUrlContext *context) = 0;

    virtual antlrcpp::Any visitBase64(UserAgentParser::Base64Context *context) = 0;

    virtual antlrcpp::Any visitCommentSeparator(UserAgentParser::CommentSeparatorContext *context) = 0;

    virtual antlrcpp::Any visitCommentBlock(UserAgentParser::CommentBlockContext *context) = 0;

    virtual antlrcpp::Any visitCommentEntry(UserAgentParser::CommentEntryContext *context) = 0;

    virtual antlrcpp::Any visitProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext *context) = 0;

    virtual antlrcpp::Any visitProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext *context) = 0;

    virtual antlrcpp::Any visitKeyValueProductVersionName(UserAgentParser::KeyValueProductVersionNameContext *context) = 0;

    virtual antlrcpp::Any visitKeyValue(UserAgentParser::KeyValueContext *context) = 0;

    virtual antlrcpp::Any visitKeyWithoutValue(UserAgentParser::KeyWithoutValueContext *context) = 0;

    virtual antlrcpp::Any visitKeyValueVersionName(UserAgentParser::KeyValueVersionNameContext *context) = 0;

    virtual antlrcpp::Any visitKeyName(UserAgentParser::KeyNameContext *context) = 0;

    virtual antlrcpp::Any visitEmptyWord(UserAgentParser::EmptyWordContext *context) = 0;

    virtual antlrcpp::Any visitMultipleWords(UserAgentParser::MultipleWordsContext *context) = 0;

    virtual antlrcpp::Any visitVersionWords(UserAgentParser::VersionWordsContext *context) = 0;


};

}  // namespace ycpp
