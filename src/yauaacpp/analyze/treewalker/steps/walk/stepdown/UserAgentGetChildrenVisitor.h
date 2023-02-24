//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_USERAGENTGETCHILDRENVISITOR_H
#define YAUAACPP_USERAGENTGETCHILDRENVISITOR_H

#include <UserAgentBaseVisitor.h>
#include "yauaacpp_def.h"
#include "ChildIterable.h"


namespace ycpp {

    class UserAgentGetChildrenVisitor : public UserAgentBaseVisitor {

    private:
        std::string name;
        ChildIterable *childIterable;
        BaseIterator * iterator;
        antlrcpp::Any ppv;


        static BlankIterator<antlr4::tree::ParseTree*> EMPTY;

    protected:
        antlrcpp::Any defaultResult() {
            return EMPTY;
        }
    public:
        ~UserAgentGetChildrenVisitor();
        UserAgentGetChildrenVisitor(const std::string & name, int start, int end);


        antlrcpp::Any getChildrenByName(antlr4::ParserRuleContext * ctx);


        antlrcpp::Any visitUserAgent(UserAgentParser::UserAgentContext * ctx) override;


        antlrcpp::Any visitRootElements(UserAgentParser::RootElementsContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitProduct(UserAgentParser::ProductContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitCommentProduct(UserAgentParser::CommentProductContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitProductName(UserAgentParser::ProductNameContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext * ctx) override;


        antlrcpp::Any visitProductVersion(UserAgentParser::ProductVersionContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitKeyValue(UserAgentParser::KeyValueContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitKeyWithoutValue(UserAgentParser::KeyWithoutValueContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitCommentBlock(UserAgentParser::CommentBlockContext * ctx) override {
            return getChildrenByName(ctx);
        }


        antlrcpp::Any visitCommentEntry(UserAgentParser::CommentEntryContext * ctx) override {
            return getChildrenByName(ctx);
        }
    };

}

#endif //YAUAACPP_USERAGENTGETCHILDRENVISITOR_H
