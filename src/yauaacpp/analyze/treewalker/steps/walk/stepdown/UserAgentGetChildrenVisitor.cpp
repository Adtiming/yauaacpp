//
// Created by sunxg on 22-1-30.
//

#include "UserAgentGetChildrenVisitor.h"

namespace ycpp {
    BlankIterator<antlr4::tree::ParseTree*> UserAgentGetChildrenVisitor::EMPTY;

    UserAgentGetChildrenVisitor::UserAgentGetChildrenVisitor(const std::string &name, int start, int end) {
        iterator = nullptr;
        this->name = name;
            if(name == "keyvalue") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::KeyValueContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::KeyWithoutValueContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::ProductNameKeyValueContext*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "product") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::ProductContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::CommentProductContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::ProductNameNoVersionContext*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "uuid") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::UuIdContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::ProductNameUuidContext*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "base64") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::Base64Context*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "url") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::SiteUrlContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::ProductNameUrlContext*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "email") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::EmailAddressContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::ProductNameEmailContext*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "text") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::MultipleWordsContext*>(clazz) ||
                            nullptr != dynamic_cast<UserAgentParser::VersionWordsContext*>(clazz) ||
                            nullptr != dynamic_cast<UserAgentParser::EmptyWordContext*>(clazz) ||
                            nullptr != dynamic_cast<UserAgentParser::RootTextContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::KeyValueVersionNameContext*>(clazz);
                };

                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "name") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::ProductNameContext*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "version") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::ProductVersionContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::ProductVersionWithCommasContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::ProductVersionWordsContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::ProductVersionSingleWordContext*>(clazz);
                };
                childIterable = new ChildIterable(true, start, end, func);
            }else if(name == "comments") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::CommentBlockContext*>(clazz);
                };
                childIterable = new ChildIterable(true, start, end, func);
            }else if(name == "key") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::KeyNameContext*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "value") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::UuIdContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::MultipleWordsContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::SiteUrlContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::EmailAddressContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::KeyValueVersionNameContext*>(clazz) ||
                           nullptr != dynamic_cast<UserAgentParser::KeyValueProductVersionNameContext*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }else if(name == "entry") {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return nullptr != dynamic_cast<UserAgentParser::CommentEntryContext*>(clazz);
                };
                childIterable = new ChildIterable(false, start, end, func);
            }
            else {
                auto func = [](antlr4::tree::ParseTree *clazz)->bool{
                    return false;
                };
                childIterable = new ChildIterable(false, start, end, func);
            }

    }

    UserAgentGetChildrenVisitor::~UserAgentGetChildrenVisitor() {
        delete childIterable;
    }

    antlrcpp::Any UserAgentGetChildrenVisitor::getChildrenByName(antlr4::ParserRuleContext *ctx) {
        return childIterable->iterator(ctx);
    }

    antlrcpp::Any UserAgentGetChildrenVisitor::visitUserAgent(UserAgentParser::UserAgentContext *ctx) {
        Iterator<antlr4::tree::ParseTree *> *  children = getChildrenByName(ctx).as< Iterator<antlr4::tree::ParseTree *> * >();
        if (children->hasNext()) {
            return children;
        }
        return visitChildren(ctx);
    }

    antlrcpp::Any UserAgentGetChildrenVisitor::visitProductNameKeyValue(UserAgentParser::ProductNameKeyValueContext *ctx) {
        if(name == "key") {
            auto * pv = new std::vector<antlr4::ParserRuleContext*>();
            pv->push_back(dynamic_cast<antlr4::ParserRuleContext*>(ctx->key));
            iterator = new ContenerIterator< std::vector<antlr4::ParserRuleContext*>, antlr4::ParserRuleContext*>(pv);
            ppv = pv;
            return iterator;
        }
        if(name == "value") {
            {
                auto children = ctx->multipleWords();
                if (!children.empty()) {
                    auto * pv = new std::vector<UserAgentParser::MultipleWordsContext*>(children);
                    iterator = new ContenerIterator< std::vector<UserAgentParser::MultipleWordsContext*>, antlr4::ParserRuleContext*>(pv);
                    ppv = pv;
                    return iterator;
                }
            }

            {
                auto children = ctx->keyValueProductVersionName();
                if (!children.empty()) {
                    auto * pv = new std::vector<UserAgentParser::KeyValueProductVersionNameContext*>(children);
                    iterator = new ContenerIterator< std::vector<UserAgentParser::KeyValueProductVersionNameContext*>, antlr4::ParserRuleContext*>(pv);
                    ppv = pv;
                    return iterator;
                }
            }

            {
                auto children = ctx->siteUrl();
                if (!children.empty()) {
                    auto * pv = new std::vector<UserAgentParser::SiteUrlContext*>(children);
                    iterator = new ContenerIterator< std::vector<UserAgentParser::SiteUrlContext*>, antlr4::ParserRuleContext*>(pv);
                    ppv = pv;
                    return iterator;
                }
            }

            {
                auto children = ctx->emailAddress();
                if (!children.empty()) {
                    auto * pv = new std::vector<UserAgentParser::EmailAddressContext*>(children);
                    iterator = new ContenerIterator< std::vector<UserAgentParser::EmailAddressContext*>, antlr4::ParserRuleContext*>(pv);
                    ppv = pv;
                    return iterator;
                }
            }

            auto children = ctx->uuId();
            auto * pv = new std::vector<UserAgentParser::UuIdContext*>(children);
            iterator = new ContenerIterator< std::vector<UserAgentParser::UuIdContext*>, antlr4::ParserRuleContext*>(pv);
            ppv = pv;
            return iterator;
        }
        else
            return getChildrenByName(ctx);

    }
}
