//
// Created by sunxg on 22-1-30.
//

#ifndef YAUAACPP_CHILDITERABLE_H
#define YAUAACPP_CHILDITERABLE_H

#include "yauaacpp_def.h"
#include <functional>


namespace ycpp {
    class ChildIterator;

    class BaseIterator{
    public:
        virtual ~BaseIterator(){}
    };

    template<typename V>
    class Iterator:public BaseIterator{
    public:
        virtual ~Iterator(){};
        virtual bool hasNext() = 0;
        virtual V next() = 0;
    };

    template<typename V>
    class BlankIterator : public Iterator<V>{
    public:
        bool hasNext() override {return false;}
        V next() override {return V();}
    };

    template <typename C, typename V>
    class ContenerIterator : public Iterator<V>{
    private:
        const C * c;
        typename C::const_iterator it;
    public:
        ContenerIterator(const C * c){
            this->c = c;
            this->it = c->begin();
        }
        bool hasNext() override {
            return it != c->end();
        }
        V next() override {return *it++;}
    };

    typedef std::function< bool(antlr4::tree::ParseTree *t)> Predicate;

    class ChildIterable {
    private:
        bool privateNumberRange;
        int start;
        int end;

        Predicate isWantedClassPredicate;

        ChildIterator * ci;
        ChildIterable(){}
        ChildIterable(const ChildIterable & ci){
            this->privateNumberRange = ci.privateNumberRange;
            this->start = ci.start;
            this->end = ci.end;
            this->isWantedClassPredicate = ci.isWantedClassPredicate;
        }
    public:
        ChildIterable(bool privateNumberRange,
                      int start, int end,
                      Predicate isWantedClassPredicate);
        ~ChildIterable();

        Iterator<antlr4::tree::ParseTree*> * iterator(antlr4::ParserRuleContext * treeContext);

        friend class ChildIterator;
    };
}

#endif //YAUAACPP_CHILDITERABLE_H
