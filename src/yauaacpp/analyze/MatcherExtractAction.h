//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MATCHEREXTRACTACTION_H
#define YAUAACPP_MATCHEREXTRACTACTION_H

#include "yauaacpp_def.h"
#include "MatcherAction.h"

namespace ycpp {

    class MatcherExtractAction : public MatcherAction {

    private:
        std::string attribute;
        long confidence;
        std::string foundValue;
        std::string fixedValue;
        std::string expression;
        MutableAgentField * resultAgentField;

        MatcherExtractAction();

    public:
        MatcherExtractAction(const std::string & attribute, long confidence, const std::string & config, Matcher * matcher);

        virtual ~MatcherExtractAction();

        void setResultAgentField(MutableAgentField * newResultAgentField){
            resultAgentField = newResultAgentField;
        }

        antlr4::ParserRuleContext * parseWalkerExpression(UserAgentTreeWalkerParser * parser) {
            return parser->matcherExtract();
        }

        bool isFixedValue() {
            return !this->fixedValue.empty();
        }

        void setFixedValue(const std::string & newFixedValue) override {
            if (verbose) {
                LOG::error( "-- set Fixed value(%s , %ld , %s)", attribute.c_str(), confidence, newFixedValue.c_str());
            }
            this->fixedValue = newFixedValue;
        }

        std::string getAttribute() {
            return attribute;
        }

        void inform(const std::string & key, std::shared_ptr<WalkResult> newlyFoundValue) {
            if (verbose) {
                LOG::error( "INFO  : EXTRACT (%s): %s", attribute.c_str(), key.c_str());
                LOG::error( "NEED  : EXTRACT (%s): %s", attribute.c_str(), getMatchExpression().c_str());
            }
            /*
             * We know the tree is parsed from left to right.
             * This is also the priority in the fields.
             * So we always use the first value we find.
             */
            if (this->foundValue.empty()) {
                this->foundValue = newlyFoundValue->getValue();
                if (verbose) {
                    LOG::error( "KEPT  : EXTRACT (%s): %s", attribute.c_str(), key.c_str());
                }
            }
        }

        bool obtainResult() override {
            processInformedMatches();
            if (!fixedValue.empty()) {
                if (verbose) {
                    LOG::error( "Set fixedvalue (%s)[%ld]: %s", attribute.c_str(), confidence, fixedValue.c_str());
                }
                resultAgentField->setValueForced(fixedValue, confidence);
                return true;
            }
            if (!foundValue.empty()) {
                if (verbose) {
                    LOG::error( "Set parsevalue (%s)[%ld]: %s", attribute.c_str(), confidence, foundValue.c_str());
                }
                resultAgentField->setValueForced(foundValue, confidence);
                return true;
            }
            if (verbose) {
                LOG::error( "Nothing found for %s", attribute.c_str());
            }

            return false;
        }


        void reset() override {
            MatcherAction::reset();
            this->foundValue.clear();
        }


        std::string toString() override {
            std::ostringstream o;
            if (isFixedValue()) {
                o<< "Extract FIXED.("<<matcher->getMatcherSourceLocation()<<"): (" << attribute << ", " << confidence << ") =   \"" << fixedValue << "\"";
            } else {
                o<< "Extract DYNAMIC.("<<matcher->getMatcherSourceLocation()<<"): (" << attribute << ", " << confidence << "):    " << expression;
            }
            return o.str();
        }
    };

    int g_MatcherExtractAction_cnt = 0;
    MatcherExtractAction::~MatcherExtractAction() {
        g_MatcherExtractAction_cnt --;
        //printf("g_MatcherExtractAction_cnt = %d\n",g_MatcherExtractAction_cnt);
    }

    MatcherExtractAction::MatcherExtractAction() {
        g_MatcherExtractAction_cnt ++;
        confidence = -1;
        resultAgentField = nullptr;
    }

    MatcherExtractAction::MatcherExtractAction(const std::string &attribute, long confidence, const std::string &config,
                                               Matcher *matcher) {
        g_MatcherExtractAction_cnt ++;
        this->attribute = attribute;
        this->confidence = confidence;
        expression = config;
        resultAgentField = nullptr;
        init(config, matcher);
    }

}

#endif //YAUAACPP_MATCHEREXTRACTACTION_H
