//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_FIELDCALCULATOR_H
#define YAUAACPP_FIELDCALCULATOR_H

#include "yauaacpp_def.h"

namespace ycpp {
    class MutableUserAgent;

    class FieldCalculator {
    public:
        virtual ~FieldCalculator(){}
        virtual void calculate(std::shared_ptr<MutableUserAgent> userAgent) = 0;

        virtual std::string getCalculatedFieldName() = 0;

        virtual std::set<std::string> getDependencies() {
            return std::set<std::string>();
        }


        virtual std::string toString() {
            std::ostringstream o;
            o << "Calculate ";
            o << '[';
            for(const std::string &s : getDependencies()){
                o << s.c_str();
            }
            o << " ==> " << getCalculatedFieldName();
            return o.str();
        }
};

}
#endif //YAUAACPP_FIELDCALCULATOR_H
