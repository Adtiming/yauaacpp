//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEPPREVN_H
#define YAUAACPP_STEPPREVN_H

#include "yauaacpp_def.h"
#include "../Step.h"

namespace ycpp {

    class StepPrevN :public Step {
    private:

        enum {SIZE = 20};
        PParseTree * children;

        int steps;

     // Private constructor for serialization systems ONLY (like Kryo)
        StepPrevN() {
            steps = -1;
            children = nullptr;
        }
        antlr4::tree::ParseTree * prev(antlr4::tree::ParseTree * tree);

    public:
        explicit StepPrevN(int steps) {
            this->steps = steps;
            children = nullptr;
        }
        ~StepPrevN(){
            if(children)
                delete []children;
        }

        std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value);


        std::string toString() const override {
            std::ostringstream o;
            o << "Prev(" << steps << ")";
            return o.str();
        }

};

}

#endif //YAUAACPP_STEPPREVN_H
