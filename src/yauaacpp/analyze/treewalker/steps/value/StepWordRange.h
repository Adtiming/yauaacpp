//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPWORDRANGE_H
#define YAUAACPP_STEPWORDRANGE_H

#include <utils/VersionSplitter.h>
#include <utils/WordSplitter.h>
#include <UserAgentParser.h>
#include "yauaacpp_def.h"


namespace ycpp {
    class StepWordRange :public Step {

    private:
        int firstWord;
        int lastWord;

        // Private constructor for serialization systems ONLY (like Kryo)
        StepWordRange() {
            firstWord = -1;
            lastWord = -1;
        }

    public:
        explicit StepWordRange(Range range) {
            firstWord = range.getFirst();
            lastWord = range.getLast();
        }


        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override {
            std::string actualValue = getActualValue(tree, value);

            std::string filteredValue;
            if (tree->children.size() == 1 &&
                    (nullptr != dynamic_cast<UserAgentParser::SingleVersionContext*>(tree->children[0])  ||
                        nullptr != dynamic_cast<UserAgentParser::SingleVersionWithCommasContext*>(tree->children[0]))
                ) {
                    filteredValue = VersionSplitter::getInstance()->getSplitRange(actualValue, firstWord, lastWord);
                } else {
                    filteredValue = WordSplitter::getInstance()->getSplitRange(actualValue, firstWord, lastWord);
                }
                if (filteredValue.empty()) {
                    return nullptr;
            }
            return walkNextStep(tree, filteredValue);
        }


        bool canFail() override {
            // If you want the first word it cannot fail.
            // For all other numbers it can.
            return !(firstWord==1 && lastWord==1);
        }


        std::string toString() const override {
            std::ostringstream o;
            o << "WordRange([" << firstWord << ":" << lastWord << "])";
            return o.str();
        }

    };
}

#endif //YAUAACPP_STEPWORDRANGE_H
