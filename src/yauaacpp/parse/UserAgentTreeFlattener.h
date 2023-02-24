//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_USERAGENTTREEFLATTENER_H
#define YAUAACPP_USERAGENTTREEFLATTENER_H

#include <utils/AntlrUtils.h>
#include <UserAgentLexer.h>
#include <utils/WordSplitter.h>
#include <utils/VersionSplitter.h>
#include "yauaacpp_def.h"
#include "UserAgent.h"
#include "utils/Splitter.h"
#include "EvilManualUseragentStringHacks.h"
#include "ImmutableUserAgent.h"

namespace ycpp {
    class UserAgentAnalyzerDirect;
    class Splitter;
    class Analyzer;

    class UserAgentTreeFlattener : public UserAgentBaseListener {
    private:
        Analyzer*                   analyzer;
        antlr4::ANTLRInputStream *  input;
        UserAgentLexer *            lexer;
        antlr4::CommonTokenStream * tokens;
        UserAgentParser *           parser;

        const char * AGENT    = "agent";
        const char * PRODUCT  = "product";
        const char * NAME     = "name";
        const char * VERSION_STR  = "version";
        const char * COMMENTS = "comments";
        const char * KEYVALUE = "keyvalue";
        const char * KEY      = "key";
        const char * TEXT     = "text";
        const char * URL      = "url";
        const char * UUID     = "uuid";
        const char * EMAIL    = "email";
        const char * BASE64   = "base64";

    public:
        typedef  enum {
            CHILD,
            COMMENT,
            VERSION
        } PathType ;

        class State {
        private:
            // Private constructor for serialization systems ONLY (like Kryo)
            State();

        public:
            long child = 0;
            long version = 0;
            long comment = 0;
            std::string name;
            std::string path;
            antlr4::tree::ParseTree * ctx;
            UserAgentTreeFlattener * uatf;


            State(const std::string & name,UserAgentTreeFlattener * uatf);

            State(antlr4::tree::ParseTree * ctx, const std::string & name,UserAgentTreeFlattener * uatf);
            ~State();

            std::string calculatePath(PathType type, bool fakeChild);
        };

    private:
        antlr4::tree::ParseTreeProperty<std::shared_ptr<State> > *state;

         // Private constructor for serialization systems ONLY (like Kryo)
        UserAgentTreeFlattener();
        bool verbose = false;

        /**
         * Parse the useragent and return every part that was found.
         *
         * @param userAgent The useragent instance that needs to be parsed
         * @return If the parse was valid (i.e. were there any parser errors: true=valid; false=has errors
         */
        std::shared_ptr<MutableUserAgent> parseIntoCleanUserAgent(std::shared_ptr<MutableUserAgent> userAgent);

        // =================================================================================

        std::string inform(antlr4::tree::ParseTree * ctx, const std::string & path) {
            return inform(ctx, path, AntlrUtils::getSourceText((antlr4::ParserRuleContext*)ctx));
        }

        std::string inform(antlr4::tree::ParseTree * ctx, const std::string & name, const std::string & value) {
            return inform(ctx, ctx, name, value, false);
        }

        std::string inform(antlr4::tree::ParseTree * ctx, const std::string & name, const std::string & value, bool fakeChild) {
            return inform(ctx, ctx, name, value, fakeChild);
        }

        std::string inform(antlr4::tree::ParseTree * stateCtx, antlr4::tree::ParseTree * ctx, const std::string & name, const std::string & value, bool fakeChild);

//  =================================================================================

        UserAgentParser::UserAgentContext * parseUserAgent(std::shared_ptr<MutableUserAgent> userAgent);

        void informSubstrings(antlr4::ParserRuleContext * ctx, const std::string & name) {
            informSubstrings(ctx, name, false);
        }

        void informSubstrings(antlr4::ParserRuleContext * ctx, const std::string & name, bool fakeChild) {
            informSubstrings(ctx, name, fakeChild, WordSplitter::getInstance());
        }

        void informSubVersions(antlr4::ParserRuleContext * ctx) {
            informSubstrings(ctx, VERSION_STR, false, VersionSplitter::getInstance());
        }

        void informSubstrings(antlr4::ParserRuleContext * ctx, const std::string & name, bool fakeChild, Splitter * splitter);

        void enterProductVersion(antlr4::tree::ParseTree * ctx) {
            antlr4::tree::ParseTree * child = ctx->children[0];
            // Only for the SingleVersion edition we want to have splits of the version.
            if (nullptr == dynamic_cast<UserAgentParser::SingleVersionContext *>(child) ||
                    nullptr == dynamic_cast<UserAgentParser::SingleVersionWithCommasContext*>(child) ) {
                return;
            }

            inform(ctx, VERSION_STR);
        }
    public:
        UserAgentTreeFlattener(Analyzer * analyzer) {
            this->analyzer = analyzer;
            this->state = nullptr;
            this->input = nullptr;
            this->lexer = nullptr;
            this->tokens = nullptr;
            this->parser = nullptr;
        }

        ~UserAgentTreeFlattener();

        void clear();



        void setVerbose(bool newVerbose) {
            this->verbose = newVerbose;
        }

        UserAgent * parse(const std::string & userAgentString) {
            std::shared_ptr<MutableUserAgent> userAgent = std::make_shared<MutableUserAgent>(userAgentString);
            return parseIntoCleanUserAgent(userAgent).get();
        }

        std::shared_ptr<MutableUserAgent> parse(std::shared_ptr<MutableUserAgent> userAgent) {
            userAgent->reset();
            return parseIntoCleanUserAgent(userAgent);
        }

        //  =================================================================================


        void enterUserAgent(UserAgentParser::UserAgentContext * ctx) override {
            // In case of a parse error the 'parsed' version of agent can be incomplete
            inform(ctx, AGENT, ctx->start->getTokenSource()->getInputStream()->toString());
        }


        void enterRootText(UserAgentParser::RootTextContext * ctx) override {
            informSubstrings(ctx, TEXT);
        }


        void enterProduct(UserAgentParser::ProductContext * ctx) override {
            informSubstrings(ctx, PRODUCT);
        }


        void enterCommentProduct(UserAgentParser::CommentProductContext * ctx) override {
            informSubstrings(ctx, PRODUCT);
        }


        void enterProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext * ctx) override {
        informSubstrings(ctx, PRODUCT);
        }


        void enterProductNameEmail(UserAgentParser::ProductNameEmailContext * ctx) override {
            inform(ctx, NAME);
        }


        void enterProductNameUrl(UserAgentParser::ProductNameUrlContext * ctx) override {
            inform(ctx, NAME);
        }


        void enterProductNameWords(UserAgentParser::ProductNameWordsContext * ctx) override {
            informSubstrings(ctx, NAME);
        }


        void enterProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext * ctx) override {
            inform(ctx, "name.(1)keyvalue", ctx->getText(), false);
            informSubstrings(ctx, NAME, true);
        }


        void enterProductNameVersion(UserAgentParser::ProductNameVersionContext * ctx) override {
            informSubstrings(ctx, NAME);
        }


        void enterProductNameUuid(UserAgentParser::ProductNameUuidContext * ctx) override {
            inform(ctx, NAME);
        }


        void enterProductVersion(UserAgentParser::ProductVersionContext * ctx) override {
            enterProductVersion((antlr4::tree::ParseTree *)ctx);
        }


        void enterProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext * ctx) override {
            enterProductVersion(ctx);
        }


        void enterProductVersionSingleWord(UserAgentParser::ProductVersionSingleWordContext * ctx) override {
            inform(ctx, VERSION_STR);
        }


        void enterSingleVersion(UserAgentParser::SingleVersionContext * ctx) override {
            informSubVersions(ctx);
        }


        void enterSingleVersionWithCommas(UserAgentParser::SingleVersionWithCommasContext * ctx) override {
            informSubVersions(ctx);
        }


        void enterProductVersionWords(UserAgentParser::ProductVersionWordsContext * ctx) override {
            informSubstrings(ctx, VERSION_STR);
        }


        void enterKeyValueProductVersionName(UserAgentParser::KeyValueProductVersionNameContext * ctx) override {
            informSubstrings(ctx, VERSION_STR);
        }


        void enterCommentBlock(UserAgentParser::CommentBlockContext * ctx) override {
            inform(ctx, COMMENTS);
        }


        void enterCommentEntry(UserAgentParser::CommentEntryContext * ctx) override {
            informSubstrings(ctx, "entry");
        }


        // # Ranges | Direct                   |  SplitList
        // 1        |    1.664 ± 0.010  ns/op  |    99.378 ± 1.548  ns/op
        // 2        |   38.103 ± 0.479  ns/op  |   115.808 ± 1.055  ns/op
        // 3        |  109.023 ± 0.849  ns/op  |   141.473 ± 6.702  ns/op
        // 4        |  162.917 ± 1.842  ns/op  |   166.120 ± 7.166  ns/op  <-- Break even
        // 5        |  264.877 ± 6.264  ns/op  |   176.334 ± 3.999  ns/op
        // 6        |  356.914 ± 2.573  ns/op  |   196.640 ± 1.306  ns/op
        // 7        |  446.930 ± 3.329  ns/op  |   215.499 ± 3.410  ns/op
        // 8        |  533.153 ± 2.250  ns/op  |   233.241 ± 5.311  ns/op
        // 9        |  519.130 ± 3.495  ns/op  |   250.921 ± 6.107  ns/op


        void enterMultipleWords(UserAgentParser::MultipleWordsContext * ctx) override {
            informSubstrings(ctx, TEXT);
        }


        void enterKeyValue(UserAgentParser::KeyValueContext * ctx) override {
            inform(ctx, KEYVALUE);
        }


        void enterKeyWithoutValue(UserAgentParser::KeyWithoutValueContext * ctx) override {
        inform(ctx, KEYVALUE);
        }


        void enterKeyName(UserAgentParser::KeyNameContext * ctx) override {
            informSubstrings(ctx, KEY);
        }


        void enterKeyValueVersionName(UserAgentParser::KeyValueVersionNameContext * ctx) override {
            informSubstrings(ctx, VERSION_STR);
        }


        void enterVersionWords(UserAgentParser::VersionWordsContext * ctx) override {
            informSubstrings(ctx, TEXT);
        }


        void enterSiteUrl(UserAgentParser::SiteUrlContext * ctx) override {
            inform(ctx, URL, ctx->url->getText());
        }


        void enterUuId(UserAgentParser::UuIdContext * ctx) override {
            inform(ctx, UUID, ctx->uuid->getText());
        }


        void enterEmailAddress(UserAgentParser::EmailAddressContext * ctx) override {
            inform(ctx, EMAIL, ctx->email->getText());
        }


        void enterBase64(UserAgentParser::Base64Context * ctx) override {
            inform(ctx, BASE64, ctx->value->getText());
        }


        void enterEmptyWord(UserAgentParser::EmptyWordContext * ctx) override {
            inform(ctx, TEXT, "");
        }


        std::string toString() const {
            std::ostringstream o;
            o << "UserAgentTreeFlattener{" <<
                   " verbose=" << verbose <<
                   "} ";
            return o.str();
        }
    };



}
#endif //YAUAACPP_USERAGENTTREEFLATTENER_H
