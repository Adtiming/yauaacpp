//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_STEP_H
#define YAUAACPP_STEP_H

#include "yauaacpp_def.h"
#include "WalkList.h"

namespace ycpp {
    class WalkResult;

    class Step {
    private:
        int stepNr;

        std::shared_ptr<Step> nextStep;

    public:
        typedef antlr4::tree::ParseTree* PParseTree;
        std::string logprefix = "";
        bool verbose = false;

        Step(){
        }
        virtual ~Step();
        virtual void setVerbose(bool newVerbose);

        virtual void destroy();

        virtual void setNextStep(int newStepNr, std::shared_ptr<Step> newNextStep);

        virtual std::shared_ptr<WalkResult> walkNextStep(antlr4::tree::ParseTree * tree, const std::string & value);

        virtual antlr4::tree::ParseTree * up(antlr4::tree::ParseTree * tree);

        static bool treeIsSeparator(antlr4::tree::ParseTree * tree);

        std::string getActualValue(antlr4::tree::ParseTree * tree, const std::string & value);

        /**
         * This will walk into the tree and recurse through all the remaining steps.
         * This must iterate of all possibilities and return the first matching result.
         *
         * @param tree  The tree to walk into.
         * @param value The string representation of the previous step (needed for compare and lookup operations).
         *              The null value means to use the implicit 'full' value (i.e. getSourceText(tree) )
         * @return Either null or the actual value that was found.
         */
        virtual std::shared_ptr<WalkResult> walk(antlr4::tree::ParseTree * tree, const std::string & value) = 0;

        /**
         * Some steps cannot fail.
         * For a require rule if the last step cannot fail then this can be removed from the require list
         * to improve performance at run time.
         * @return If this specific step can or cannot fail.
         */
        virtual bool canFail();

        /**
         * Some steps can even pass if there is no input provided.
         * @return If this specific step needs input to pass.
         */
        virtual bool mustHaveInput();

        virtual std::shared_ptr<Step> getNextStep() {
            return nextStep;
        }

        virtual std::string toString()const = 0;
    };
}

#endif //YAUAACPP_STEP_H
