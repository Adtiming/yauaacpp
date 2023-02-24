//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_CONCATNONDUPLICATEDCALCULATOR_H
#define YAUAACPP_CONCATNONDUPLICATEDCALCULATOR_H

#include "yauaacpp_def.h"

namespace ycpp {

    class ConcatNONDuplicatedCalculator : public FieldCalculator {

    private:
        std::string targetName;
        std::string firstName;
        std::string secondName;
        ConcatNONDuplicatedCalculator() {
            targetName  = "Dummy";
            firstName   = "Dummy";
            secondName  = "Dummy";
        }

    public:
        ConcatNONDuplicatedCalculator(const std::string & targetName, const std::string & firstName, const std::string & secondName) {
            this->targetName = targetName;
            this->firstName = firstName;
            this->secondName = secondName;

            if (targetName  == "" ||
                firstName   == "" ||
                secondName  == "") {
                throw antlr4::RuntimeException("Target, first and second name may not be null");
            }
        }



        void calculate(std::shared_ptr<MutableUserAgent> userAgent) override {
            const AgentField & firstField  = userAgent->get(firstName);
            const AgentField & secondField = userAgent->get(secondName);

            std::string  first          = firstField.getValue();
            long    firstConfidence     = firstField.getConfidence();
            std::string  second         = secondField.getValue();
            long    secondConfidence    = secondField.getConfidence();
            long    confidence          = std::max(firstConfidence, secondConfidence);

            if (firstField.isDefaultValue() && secondField.isDefaultValue()) {
                userAgent->set(targetName, NULL_VALUE, confidence);
                return;
            }

            if (first == second) {
                userAgent->setForced(targetName, first, firstConfidence);
                return;
            }

            if (starts_with(second,first)) {
                userAgent->setForced(targetName, second, secondConfidence);
                return;
            }

            std::string value      = first + " " + second;
            userAgent->set(targetName, value, confidence);
        }


        std::string getCalculatedFieldName() {
            return targetName;
        }


        std::set<std::string> getDependencies() {
            std::set<std::string> t;
            t.insert(firstName);
            t.insert(secondName);
            return t;
        }


        std::string toString() {
            return "Calculate [ " + firstName + " + " + secondName + " ] --> " + targetName;
        }

    };

}
#endif //YAUAACPP_CONCATNONDUPLICATEDCALCULATOR_H
