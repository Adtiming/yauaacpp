//
// Created by sunxg on 22-1-30.
//

#include <analyze/treewalker/steps/Step.h>
#include "ChildIterable.h"
#include "utils/NotInAntlr4.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    class ChildIterator : public Iterator<antlr4::tree::ParseTree*> {
    private:
        ChildIterable * parent;
        std::vector<antlr4::tree::ParseTree *>::iterator childIter;
        const std::vector<antlr4::tree::ParseTree *> *contener;
        bool                _hasNext;
        int                 index = 0;
        antlr4::tree::ParseTree * nextChild;


        /**
         * Find and set the nextChild
         * @return If there is a next
         */
        bool findNext() {
            while (childIter != contener->end()) {
                antlr4::tree::ParseTree * nextParseTree = *childIter++;
                if (Step::treeIsSeparator(nextParseTree)) {
                    continue;
                }
                if (!parent->privateNumberRange) {
                    index++;
                }
                if (!parent->isWantedClassPredicate(nextParseTree)) {
                    continue;
                }
                if (parent->privateNumberRange) {
                    index++;
                }
                if (index > parent->end) {
                    nextChild = nullptr;
                    return false;
                }
                if (parent->start <= index) {
                    nextChild = nextParseTree;
                    return true;
                }
            }

            // We found nothing
            nextChild = nullptr;
            return false;
        }

    public:

        ChildIterator(ChildIterable * parent, antlr4::ParserRuleContext * treeContext) {
            this->parent = parent;
            contener = &treeContext->children;
            childIter = treeContext->children.begin();
            if (treeContext->children.empty()) {
                nextChild = nullptr;
                _hasNext = false;
            } else {

                _hasNext = findNext(); // We always want the first one
            }
        }


        bool hasNext() {
            if(!_hasNext)
                _hasNext = findNext();
            return _hasNext;
        }


        antlr4::tree::ParseTree * next() {
            if (!hasNext()) {
                throw antlr4::NoSuchElementException();
            }
            _hasNext = false;
            return nextChild;
        }
    };

    ChildIterable::ChildIterable(bool privateNumberRange, int start, int end,
                                 Predicate isWantedClassPredicate) {
            this->privateNumberRange = privateNumberRange;
            this->start = start;
            this->end = end;
            this->isWantedClassPredicate = isWantedClassPredicate;
            this->ci = nullptr;
        }

        Iterator<antlr4::tree::ParseTree *> *ChildIterable::iterator(antlr4::ParserRuleContext *treeContext) {
            if(this->ci != nullptr)
                delete this->ci;
            this->ci = new ChildIterator(this,treeContext);
            return ci;
        }

    ChildIterable::~ChildIterable() {
        if(ci)
            delete ci;
    }

}
