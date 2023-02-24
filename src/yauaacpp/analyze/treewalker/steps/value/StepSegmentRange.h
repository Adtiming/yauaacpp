//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPSEGMENTRANGE_H
#define YAUAACPP_STEPSEGMENTRANGE_H

#include <utils/ListSplitter.h>
#include "yauaacpp_def.h"


namespace ycpp {
    class StepSegmentRange :public Step {
    private:
        int firstSegment;
        int lastSegment;

        // Private constructor for serialization systems ONLY (like Kryo)
        StepSegmentRange() {
            firstSegment = -1;
            lastSegment = -1;
        }

    public:
        explicit StepSegmentRange(Range range) {
            firstSegment = range.getFirst();
            lastSegment = range.getLast();
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override {
            std::string actualValue = getActualValue(tree, value);
            std::string filteredValue = ListSplitter::getInstance()->getSplitRange(actualValue, firstSegment, lastSegment);
            if (filteredValue.empty()) {
                return nullptr;
            }
            return walkNextStep(tree, filteredValue);
        }


        bool canFail() override {
            // If you want the first word it cannot fail.
            // For all other numbers it can.
            return !(firstSegment ==1 && lastSegment ==1);
        }


        std::string toString() const override {
            std::ostringstream o;
            o << "SegmentRange([" << firstSegment << ":" << lastSegment << "])";
            return o.str();
        }

    };

}

#endif //YAUAACPP_STEPSEGMENTRANGE_H
