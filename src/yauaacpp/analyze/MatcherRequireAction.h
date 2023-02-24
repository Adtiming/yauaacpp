//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MATCHERREQUIREACTION_H
#define YAUAACPP_MATCHERREQUIREACTION_H

#include "yauaacpp_def.h"
#include "MatcherAction.h"
#include "Matcher.h"

namespace ycpp {

    class MatcherRequireAction : public MatcherAction {
    private:
        MatcherRequireAction();
        bool foundRequiredValue = false;

    public:
        MatcherRequireAction(const std::string & config, Matcher * matcher);
        virtual ~MatcherRequireAction();

        antlr4::ParserRuleContext * parseWalkerExpression(UserAgentTreeWalkerParser * parser) {
            return parser->matcherRequire();
        }


        long initialize(MatcherAction * this_action);

        void setFixedValue(const std::string & fixedValue) {
            throw InvalidParserConfigurationException(
                    "It is useless to put a fixed value \"" + fixedValue + "\" in the require section.");
        }




        void inform(const std::string & key, std::shared_ptr<WalkResult> foundValue) {
            foundRequiredValue = true;
            if (verbose) {
                LOG::error( "Info REQUIRE: %s", key.c_str());
                LOG::error( "NEED REQUIRE: %s", getMatchExpression().c_str());
                LOG::error( "KEPT REQUIRE: %s", key.c_str());
            }
        }


        bool obtainResult() override {
            processInformedMatches();
            return foundRequiredValue;
        }


        void reset() {
                    MatcherAction::reset();
            foundRequiredValue = false;
        }


        std::string toString() {
            std::ostringstream o;
            o << "Require.("<<matcher->getMatcherSourceLocation()<<"): " << getMatchExpression();
            return o.str();
        }
    };

}
#endif //YAUAACPP_MATCHERREQUIREACTION_H
