//
// Created by sunxg on 22-1-29.
//

#include <UserAgentTreeWalkerLexer.h>
#include <utils/AntlrUtils.h>
#include "MatcherAction.h"
#include "treewalker/TreeExpressionEvaluator.h"
#include "MatcherFailIfFoundAction.h"
#include "NumberRangeVisitor.h"
#include "Matcher.h"
#include "WordRangeVisitor.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    class InitErrorListener :public DefaultANTLRErrorListener {
    public:
        MatcherAction * parent;
        explicit InitErrorListener(MatcherAction * parent){
            this->parent = parent;
        }
        void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                         size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
                LOG::error("Syntax error");
                LOG::error("Source %s: %s", parent->matcher->getMatcherSourceLocation().c_str(), parent->matchExpression.c_str());
                LOG::error("Message: %s", msg.c_str());
                throw InvalidParserConfigurationException("Syntax error \"" + msg + "\" caused by \"" + parent->matchExpression + "\".");
            }
        // Ignore all other types of problems
    };


    long MatcherAction::initialize(MatcherAction * this_action) {
        assert(errorListener == nullptr);
        assert(input == nullptr);
        assert(lexer == nullptr);
        assert(tokens == nullptr);
        assert(parser == nullptr);

        errorListener = new InitErrorListener(this);

        input = new antlr4::ANTLRInputStream(this->matchExpression);
        lexer = new UserAgentTreeWalkerLexer(input);

        lexer->addErrorListener(errorListener);

        tokens = new antlr4::BufferedTokenStream(lexer);
        parser = new UserAgentTreeWalkerParser(tokens);

        parser->addErrorListener(errorListener);

        antlr4::ParserRuleContext * requiredPattern = parseWalkerExpression(parser);

        // We couldn't ditch the double quotes around the fixed values in the parsing phase.
        // So we ditch them here. We simply walk the tree and modify some of the tokens.
        uqvs = new UnQuoteValues();
        uqvs->visit(requiredPattern);

        // Now we create an evaluator instance
        evaluator = new TreeExpressionEvaluator(requiredPattern, matcher, verbose);

        // Is a fixed value (i.e. no events will ever be fired)?
        std::string fixedValue = evaluator->getFixedValue();
        if (!fixedValue.empty()) {
            setFixedValue(fixedValue);
            _mustHaveMatches = false;
            matches = new MatchesList(0);
            return 0; // Not interested in any patterns
        }

        // If this is a failIfFound we do not need any matches from the hashmap.
        if (nullptr != dynamic_cast<MatcherFailIfFoundAction*>(this)) {
            _mustHaveMatches = false;
        } else {
            _mustHaveMatches = evaluator->mustHaveMatches();
        }

        int informs = calculateInformPath(this_action, "agent", requiredPattern);

        // If this is based on a variable we do not need any matches from the hashmap.
        if (_mustHaveMatches && informs == 0) {
            _mustHaveMatches = false;
        }

        int listSize = 0;
        if (informs > 0) {
            listSize = 1;
        }
        this->matches = new MatchesList(listSize);
        return informs;
    }

    void MatcherAction::destroy() {
        if(evaluator)
            evaluator->destroy();
    }

    std::map<std::string, MatcherAction::CalculateInformPathFunction> MatcherAction::CALCULATE_INFORM_PATH = initCALCULATE_INFORM_PATH();
    std::map<std::string, MatcherAction::CalculateInformPathFunction> MatcherAction::initCALCULATE_INFORM_PATH() {
        std::map<std::string, MatcherAction::CalculateInformPathFunction> t;

        t[typeid(UserAgentTreeWalkerParser::MatcherBaseContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherBaseContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherPathIsNullContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherPathIsNullContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::IsSyntaxErrorContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            action->matcher->informMeAbout(action, std::string(SYNTAX_ERROR) + "=" + ((UserAgentTreeWalkerParser::IsSyntaxErrorContext *) tree)->value->getText());
            return 1;
        };
        // -------------
        t[typeid(UserAgentTreeWalkerParser::MatcherExtractContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherExtractContext*) tree)->expression);
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherVariableContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherVariableContext*) tree)->expression);
        };
        // -------------
        t[typeid(UserAgentTreeWalkerParser::MatcherPathContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherPathContext*) tree)->basePath());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherConcatContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherConcatContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherConcatPrefixContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherConcatPrefixContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherConcatPostfixContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherConcatPostfixContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherNormalizeBrandContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherNormalizeBrandContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherCleanVersionContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherCleanVersionContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherReplaceStringContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherReplaceStringContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherPathLookupContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherPathLookupContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherPathIsInLookupContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherPathIsInLookupContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherPathLookupContainsContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherPathLookupContainsContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherDefaultIfNullContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherDefaultIfNullContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherWordRangeContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherWordRangeContext*) tree)->matcher());
        };
        t[typeid(UserAgentTreeWalkerParser::MatcherSegmentRangeContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::MatcherSegmentRangeContext*) tree)->matcher());
        };
        // -------------
        t[typeid(UserAgentTreeWalkerParser::PathVariableContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            action->matcher->informMeAboutVariable(action, ((UserAgentTreeWalkerParser::PathVariableContext*) tree)->variable->getText());
            return 0;
        };
        t[typeid(UserAgentTreeWalkerParser::PathWalkContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            return calculateInformPath(action, treeName, ((UserAgentTreeWalkerParser::PathWalkContext*) tree)->nextStep);
        };

        // -------------
        t[typeid(UserAgentTreeWalkerParser::StepDownContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            UserAgentTreeWalkerParser::StepDownContext * thisTree = ((UserAgentTreeWalkerParser::StepDownContext*) tree);
            int informs = 0;
            std::shared_ptr<NumberRangeList> l = std::any_cast<std::shared_ptr<NumberRangeList>>(NumberRangeVisitor::NUMBER_RANGE_VISITOR.visit(thisTree->numberRange()));
            for (const int number : *l) {
                informs += calculateInformPath(action, treeName + '.' + "(" + itos(number) + ")" + thisTree->name->getText(), thisTree->nextStep);
            }
            return informs;
        };

        t[typeid(UserAgentTreeWalkerParser::StepEqualsValueContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            UserAgentTreeWalkerParser::StepEqualsValueContext * thisTree = ((UserAgentTreeWalkerParser::StepEqualsValueContext*) tree);
            action->matcher->informMeAbout(action, treeName + "=\"" + thisTree->value->getText() + "\"");
            return 1;
        };
        t[typeid(UserAgentTreeWalkerParser::StepStartsWithValueContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            UserAgentTreeWalkerParser::StepStartsWithValueContext * thisTree = ((UserAgentTreeWalkerParser::StepStartsWithValueContext*) tree);
            action->matcher->informMeAboutPrefix(action, treeName, thisTree->value->getText());
            return 1;
        };
        t[typeid(UserAgentTreeWalkerParser::StepWordRangeContext).name()] = [](MatcherAction * action, const std::string & treeName, antlr4::ParserRuleContext * tree)->int{
            UserAgentTreeWalkerParser::StepWordRangeContext * thisTree = ((UserAgentTreeWalkerParser::StepWordRangeContext*) tree);
            std::shared_ptr<Range> range = WordRangeVisitor::getRange(thisTree->wordRange());
            action->matcher->lookingForRange(treeName, *range.get());
            return calculateInformPath(action, treeName + range->toString(), thisTree->nextStep);
        };
        return t;
    }

    void MatcherAction::inform(const std::string &key, const std::string &value, antlr4::tree::ParseTree *result) {
        matcher->receivedInput();

        // Only if this needs input we tell the matcher on the first one.
        if (_mustHaveMatches && matches->empty()) {
            matcher->gotMyFirstStartingPoint();
        }
        matches->add(key, value, result);
    }

    bool MatcherAction::isValidWithoutMatches() {
        return matches->empty() && !evaluator->mustHaveMatches();
    }

    void MatcherAction::processInformedMatches() {
        for (Match match : *matches) {
            std::shared_ptr<WalkResult> matchedValue = evaluator->evaluate(match.getResult(), match.getKey(), match.getValue());
            if (matchedValue != nullptr) {
                inform(match.getKey(), matchedValue);
                return; // We always stick to the first match
            }
        }

        if (isValidWithoutMatches()) {
            std::shared_ptr<WalkResult> matchedValue = evaluator->evaluate(AntlrUtils::NULL_PARSE_TREE, "", "");
            if (matchedValue != nullptr) {
                inform("", matchedValue);
            }
        }
    }

    int MatcherAction::calculateInformPath(MatcherAction *action, const std::string &treeName, antlr4::ParserRuleContext *tree) {
        if (tree == nullptr) {
            action->matcher->informMeAbout(action, treeName);
            return 1;
        }

        auto it = CALCULATE_INFORM_PATH.find(typeid(*tree).name());
        if(it != CALCULATE_INFORM_PATH.end()) {
            CalculateInformPathFunction & function = it->second;
            return function(action, treeName, tree);
        }

        action->matcher->informMeAbout(action, treeName);
        return 1;
    }


    void MatcherAction::init(const std::string & newMatchExpression, Matcher * newMatcher) {
        this->matcher = newMatcher;
        this->matchExpression = newMatchExpression;
        setVerbose(newMatcher->getVerbose());
    }

    static int g_MatcherAction_cnt = 0;
    MatcherAction::MatcherAction() {
        errorListener = nullptr;
        input = nullptr;
        lexer = nullptr;
        tokens = nullptr;
        parser = nullptr;
        uqvs = nullptr;
        evaluator = nullptr;
        matches = nullptr;
        matcher = nullptr;
        g_MatcherAction_cnt ++;
    }


    MatcherAction::~MatcherAction() {
        destroy();
        g_MatcherAction_cnt --;
        //printf("g_MatcherAction_cnt = %d\n",g_MatcherAction_cnt);
        delete errorListener;
        delete input;
        delete lexer;
        delete tokens;
        delete parser;
        delete uqvs;
        delete evaluator;
        delete matches;
    }

    bool MatcherAction::cannotBeValid() {
        if (_mustHaveMatches) {
            return matches->empty();
        }
        return false;
    }

    void MatcherAction::reset() {
        matches->clear();
        if (verboseTemporary) {
            verbose = verbosePermanent;
        }
    }

    std::string MatcherAction::toString() {
        std::ostringstream o;
        o << "MatcherAction{" <<
          "matchExpression='" << matchExpression << '\'' <<
          ", evaluator=" << evaluator <<
          //            ", matcher=" << matcher <<
          ", matches=" << (matches== nullptr?"":matches->toString().c_str()) <<
          ", mustHaveMatches=" << _mustHaveMatches <<
          ", verbose=" << verbose <<
          ", verbosePermanent=" << verbosePermanent <<
          ", verboseTemporary=" << verboseTemporary <<
          '}';
        return o.str();
    }

    void UnQuoteValues::unQuoteToken(antlr4::Token *token) {
        if (nullptr != dynamic_cast<antlr4::CommonToken*>(token)) {
            antlr4::CommonToken *commonToken = (antlr4::CommonToken *) token;
            commonToken->setStartIndex(commonToken->getStartIndex() + 1);
            commonToken->setStopIndex(commonToken->getStopIndex() - 1);
        }
    }
}