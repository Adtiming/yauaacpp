//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPCLEANVERSION_H
#define YAUAACPP_STEPCLEANVERSION_H

namespace ycpp {
    class StepCleanVersion :public Step {
    public:

        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override {
            std::string actualValue = getActualValue(tree, value);

            if (!actualValue.empty()) {
                // Sanitize the provided value
                string_replace(actualValue, "_", ".");
                string_replace(actualValue, "/", " ");
                string_replace(actualValue, ", ", ".");
            }
            return walkNextStep(tree, actualValue);
        }


        bool canFail() override {
            return false;
        }


        std::string toString() const override {
            return "CleanVersion()";
        }
    };

}

#endif //YAUAACPP_STEPCLEANVERSION_H
