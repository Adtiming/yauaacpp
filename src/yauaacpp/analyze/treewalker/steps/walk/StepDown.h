//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPDOWN_H
#define YAUAACPP_STEPDOWN_H

#include "yauaacpp_def.h"
#include "analyze/NumberRangeList.h"
#include "../Step.h"

namespace ycpp {
    class UserAgentGetChildrenVisitor;

    class StepDown :public Step {

    private:
        int start;
        int end;
        std::string name;
        UserAgentGetChildrenVisitor * userAgentGetChildrenVisitor;

        /**
         * Initialize the transient default values
         */
        void setDefaultFieldValues();

//        void readObject(java.io.ObjectInputStream stream)
//            throws java.io.IOException, ClassNotFoundException {
//            stream.defaultReadObject();
//            setDefaultFieldValues();
//        }

        // Private constructor for serialization systems ONLY (like Kryo)
        StepDown() {
            start = -1;
            end = -1;
        }
    public:

        StepDown(UserAgentTreeWalkerParser::NumberRangeContext * numberRange, const std::string & name);

        StepDown(const NumberRangeList & numberRange, const std::string & name);

        ~StepDown();


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);


        std::string toString() const override {
            std::ostringstream o;
            o << "Down([" << start << ":" << end << "]" << name << ")";
            return o.str();
        }

    };
}

#endif //YAUAACPP_STEPDOWN_H
