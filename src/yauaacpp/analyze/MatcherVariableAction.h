//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MATCHERVARIABLEACTION_H
#define YAUAACPP_MATCHERVARIABLEACTION_H

#include "yauaacpp_def.h"
#include "MatcherAction.h"

namespace ycpp {

    class MatcherVariableAction : public MatcherAction {
    private:
        std::string variableName;
        std::shared_ptr<WalkResult> foundValue;
        std::set<MatcherAction * > interestedActions;

        MatcherVariableAction();

    public:
        MatcherVariableAction(const std::string & variableName, const std::string & config, Matcher * matcher) {
            this->variableName = variableName;
            init(config, matcher);
        }
        virtual ~MatcherVariableAction();

        antlr4::ParserRuleContext * parseWalkerExpression(UserAgentTreeWalkerParser * parser) {
            return parser->matcherVariable();
        }

        void setFixedValue(const std::string & fixedValue) {
            throw InvalidParserConfigurationException(
                    "It is useless to put a fixed value \"" + fixedValue + "\" in the variable section.");
        }

        std::string getVariableName() {
            return variableName;
        }

        void inform(const std::string & key, std::shared_ptr<WalkResult> newlyFoundValue) {
            if (verbose) {
                LOG::error( "INFO  : VARIABLE (%s): %s", variableName.c_str(), key.c_str());
                LOG::error( "NEED  : VARIABLE (%s): %s", variableName.c_str(), getMatchExpression().c_str());
            }
            /*
             * We know the tree is parsed from left to right.
             * This is also the priority in the fields.
             * So we always use the first value we find.
             */
            if (this->foundValue == nullptr) {
                this->foundValue = newlyFoundValue;
                if (verbose) {
                    LOG::error( "KEPT  : VARIABLE (%s): %s", variableName.c_str(), key.c_str());
                }

                if (!interestedActions.empty()) {
                    for (MatcherAction * action : interestedActions) {
                        action->inform(variableName, newlyFoundValue->getValue(), newlyFoundValue->getTree());
                    }
                }
            }
        }

        bool obtainResult() override {
            processInformedMatches();
            return this->foundValue != nullptr;
        }


        void reset() {
            MatcherAction::reset();
            this->foundValue = nullptr;
        }


        std::string toString() {
            std::ostringstream o;
            o << "Variable.("<<matcher->getMatcherSourceLocation()<<"): (" << variableName << "): " << getMatchExpression();
            return o.str();
        }

        void setInterestedActions(std::set<MatcherAction * > newInterestedActions) {
            this->interestedActions = newInterestedActions;
        }
    };

    int g_MatcherVariableAction_cnt = 0;
    MatcherVariableAction::~MatcherVariableAction() {
        g_MatcherVariableAction_cnt --;
        //printf("g_MatcherVariableAction_cnt = %d\n",g_MatcherVariableAction_cnt);
    }

    MatcherVariableAction::MatcherVariableAction() {
        g_MatcherVariableAction_cnt ++;
        foundValue = nullptr;
    }

    std::ostringstream &operator<<(std::ostringstream &o, Matcher &m) {
        o << m.toString().c_str();
        return o;
    }

    std::ostringstream &operator<<(std::ostringstream &o, Matcher *&m) {
        o << m->toString().c_str();
        return o;
    }

    std::ostringstream &operator<<(std::ostringstream &o, std::vector<Matcher *> &v) {
        for(Matcher *m : v)
            o << m << "\n";
        return o;
    }

    std::ostringstream &operator<<(std::ostringstream &o, const std::vector<Matcher *> &v) {
        for(Matcher *m : v)
            o << m << "\n";
        return o;
    }
}
#endif //YAUAACPP_MATCHERVARIABLEACTION_H
