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
        std::any ppv;


        static BlankIterator<antlr4::tree::ParseTree*> EMPTY;

    protected:
        std::any defaultResult() {
            return EMPTY;
        }
    public:
        ~UserAgentGetChildrenVisitor();
        UserAgentGetChildrenVisitor(const std::string & name, int start, int end);


        std::any getChildrenByName(antlr4::ParserRuleContext * ctx);


        std::any visitUserAgent(UserAgentParser::UserAgentContext * ctx) override;


        std::any visitRootElements(UserAgentParser::RootElementsContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitProduct(UserAgentParser::ProductContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitProductNameNoVersion(UserAgentParser::ProductNameNoVersionContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitCommentProduct(UserAgentParser::CommentProductContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitProductName(UserAgentParser::ProductNameContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext * ctx) override;


        std::any visitProductVersion(UserAgentParser::ProductVersionContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitProductVersionWithCommas(UserAgentParser::ProductVersionWithCommasContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitKeyValue(UserAgentParser::KeyValueContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitKeyWithoutValue(UserAgentParser::KeyWithoutValueContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitCommentBlock(UserAgentParser::CommentBlockContext * ctx) override {
            return getChildrenByName(ctx);
        }


        std::any visitCommentEntry(UserAgentParser::CommentEntryContext * ctx) override {
            return getChildrenByName(ctx);
        }
    };

}

#endif //YAUAACPP_USERAGENTGETCHILDRENVISITOR_H
