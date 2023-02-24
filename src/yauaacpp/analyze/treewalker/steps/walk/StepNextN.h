//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPNEXTN_H
#define YAUAACPP_STEPNEXTN_H

#include <analyze/treewalker/steps/Step.h>
#include "yauaacpp_def.h"


namespace ycpp {

    class StepNextN :public Step {

    private:
        int steps;

     // Private constructor for serialization systems ONLY (like Kryo)
        StepNextN() {
            steps = -1;
        }

        antlr4::tree::ParseTree * next(antlr4::tree::ParseTree * tree);


    public:
        StepNextN(int steps) {
            this->steps = steps;
        }



        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) override;


        std::string toString() const override {
            std::ostringstream o;
            o<< "Next(" << steps << ")";
            return o.str();
        }

};
}

#endif //YAUAACPP_STEPNEXTN_H
