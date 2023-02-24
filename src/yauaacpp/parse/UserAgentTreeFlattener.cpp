//
// Created by sunxg on 22-2-3.
//

#include "yauaacpp_def.h"
#include "tool/dir.h"
#include <utils/AntlrUtils.h>
#include "UserAgentTreeFlattener.h"
#include "UserAgentParser.h"
#include "UserAgentAnalyzerDirect.h"


namespace ycpp {
    std::shared_ptr<MutableUserAgent> UserAgentTreeFlattener::parseIntoCleanUserAgent(std::shared_ptr<MutableUserAgent> userAgent) {
        if (userAgent->getUserAgentString().empty()) {
            userAgent->set(SYNTAX_ERROR, "true", 1);
            return userAgent; // Cannot parse this
        }

        // Parse the userAgent into tree
        UserAgentParser::UserAgentContext * userAgentContext = parseUserAgent(userAgent);
        // Walk the tree an inform the calling analyzer about all the nodes found
        if(state != nullptr)
            delete state;
        state = new antlr4::tree::ParseTreeProperty<std::shared_ptr<State> >();

        std::shared_ptr<State> rootState = std::shared_ptr<State>(new State(AGENT,this));
        rootState->calculatePath(PathType::CHILD, false);
        state->put(userAgentContext, rootState);

        if (userAgent->hasSyntaxError()) {
            inform(nullptr, SYNTAX_ERROR, "true");
        } else {
            inform(nullptr, SYNTAX_ERROR, "false");
        }

        antlr4::tree::ParseTreeWalker::DEFAULT.walk(this, userAgentContext);
        return userAgent;
    }

    UserAgentTreeFlattener::UserAgentTreeFlattener() {
        analyzer = new UserAgentAnalyzerDirect(); // Set unused value
    }

    void UserAgentTreeFlattener::informSubstrings(antlr4::ParserRuleContext *ctx, const std::string &name, bool fakeChild,
                                             Splitter *splitter) {
        std::string text = AntlrUtils::getSourceText(ctx);
        std::string path = inform(ctx, name, text, fakeChild);
        linked_hash_set<Range> ranges = analyzer->getRequiredInformRanges(path);

        if (ranges.size() > 4) { // Benchmarks showed this to be the breakeven point. (see below)
            std::vector<std::pair<int, int>> splitList = splitter->createSplitList(text);
            for (const Range & range : ranges) {
                std::string value = splitter->getSplitRange(text, splitList, range);
                if (!value.empty()) {
                    inform(ctx, ctx, name + range.toString(), value, true);
                }
            }
        } else {
            for (const Range & range : ranges) {
                std::string value = splitter->getSplitRange(text, range);
                if (!value.empty()) {
                    inform(ctx, ctx, name + range.toString(), value, true);
                }
            }
        }
    }

    UserAgentParser::UserAgentContext *UserAgentTreeFlattener::parseUserAgent(std::shared_ptr<MutableUserAgent>userAgent) {
        std::string userAgentString = EvilManualUseragentStringHacks::fixIt(userAgent->getUserAgentString());

        if(parser)
            delete parser;
        parser = nullptr;
        if(tokens)
            delete tokens;
        tokens = nullptr;
        if(lexer)
            delete lexer;
        lexer = nullptr;
        if(input)
            delete input;
        input = nullptr;

        input = new antlr4::ANTLRInputStream(userAgentString);
        lexer = new UserAgentLexer(input);
        tokens = new antlr4::CommonTokenStream(lexer);
        parser = new UserAgentParser(tokens);

        if (!verbose) {
            lexer->removeErrorListeners();
            parser->removeErrorListeners();
        }
        lexer->addErrorListener(userAgent.get());
        parser->addErrorListener(userAgent.get());

        return parser->userAgent();
    }

    std::string UserAgentTreeFlattener::inform(antlr4::tree::ParseTree *stateCtx, antlr4::tree::ParseTree *ctx,
                                               const std::string &name, const std::string &value, bool fakeChild) {
        std::string path = name;
        if (stateCtx != nullptr) {
            std::shared_ptr<State> myState(new State(stateCtx, name, this));

            if (!fakeChild) {
                state->put(stateCtx, myState);
            }

            PathType childType;
            if (name == COMMENTS) {
                childType = PathType::COMMENT;
            } else if(name == VERSION_STR) {
                childType = PathType::VERSION;
            } else {
                childType = PathType::CHILD;
            }

            path = myState->calculatePath(childType, fakeChild);
        }
        analyzer->inform(path, value, ctx);
        return path;
    }

    UserAgentTreeFlattener::~UserAgentTreeFlattener() {
        clear();
    }

    void UserAgentTreeFlattener::clear() {
        if(state)
            delete state;
        state = nullptr;
        if(parser)
            delete parser;
        parser = nullptr;
        if(tokens)
            delete tokens;
        tokens = nullptr;
        if(lexer)
            delete lexer;
        lexer = nullptr;
        if(input)
            delete input;
        input = nullptr;
    }

    std::string UserAgentTreeFlattener::State::calculatePath(UserAgentTreeFlattener::PathType type, bool fakeChild) {
        antlr4::tree::ParseTree * node = ctx;
        path = name;
        if (node == nullptr) {
            return path;
        }
        std::shared_ptr<State> parentState;

        while (parentState == nullptr) {
            node = node->parent;
            if (node == nullptr) {
                return path;
            }
            parentState = uatf->state->get(node);
        }

        long counter = 0;
        switch (type) {
            case CHILD:
                if (!fakeChild) {
                    parentState->child++;
                }
                counter = parentState->child;
                break;
            case COMMENT:
                if (!fakeChild) {
                    parentState->comment++;
                }
                counter = parentState->comment;
                break;
            case VERSION:
                if (!fakeChild) {
                    parentState->version++;
                }
                counter = parentState->version;
                break;
            default:
                break;
        }

        this->path = parentState->path + ".(" + uitos((size_t)counter) + ')' + name;

        return this->path;
    }

    int g_State_cnt= 0;

    UserAgentTreeFlattener::State::State() {
        ctx = nullptr;
        g_State_cnt ++;
    }

    UserAgentTreeFlattener::State::State(const std::string &name, UserAgentTreeFlattener *uatf) {
        this->name = name;
        this->ctx = nullptr;
        this->uatf = uatf;
        g_State_cnt ++;
    }

    UserAgentTreeFlattener::State::State(antlr4::tree::ParseTree *ctx, const std::string &name,
                                         UserAgentTreeFlattener *uatf) {
        this->ctx = ctx;
        this->name = name;
        this->uatf = uatf;
        g_State_cnt ++;
    }

    UserAgentTreeFlattener::State::~State() {
        g_State_cnt --;
    }
}
