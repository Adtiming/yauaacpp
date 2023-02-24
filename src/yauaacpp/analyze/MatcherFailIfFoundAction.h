//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MATCHERFAILIFFOUNDACTION_H
#define YAUAACPP_MATCHERFAILIFFOUNDACTION_H

#include "yauaacpp_def.h"
#include "MatcherAction.h"

namespace ycpp {

    class MatcherFailIfFoundAction : public MatcherAction {
    private:
        bool foundRequiredValue = false;
        MatcherFailIfFoundAction();

    public:
        explicit MatcherFailIfFoundAction(const std::string & config, Matcher * matcher);
        virtual ~MatcherFailIfFoundAction();

        antlr4::ParserRuleContext * parseWalkerExpression(UserAgentTreeWalkerParser * parser) {
            return parser->matcherRequire();
        }


        long initialize(MatcherAction * this_action);

        void setFixedValue(const std::string & fixedValue) {
            throw InvalidParserConfigurationException(
                    "It is useless to put a fixed value \"" + fixedValue + "\" in the failIfFound section.");
        }



        void inform(const std::string & key, const std::string & value, antlr4::tree::ParseTree * result);


        void inform(const std::string & key, std::shared_ptr<WalkResult> foundValue);


        bool obtainResult() override {
            processInformedMatches();
            return !foundRequiredValue;
        }


        void reset() {
            MatcherAction::reset();
            foundRequiredValue = false;
        }


        std::string toString();
    };


}
#endif //YAUAACPP_MATCHERFAILIFFOUNDACTION_H
