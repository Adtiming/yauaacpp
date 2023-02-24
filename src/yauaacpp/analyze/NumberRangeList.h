//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_NUMBERRANGELIST_H
#define YAUAACPP_NUMBERRANGELIST_H

#include "yauaacpp_def.h"

namespace ycpp {
    template <class T>
    class RangeContainer
    {
    private:
        T mBegin;
        T mEnd;
        int mSize;
    public:
        class Iterator
        {
        private:
            int mCurrentStep;
            RangeContainer& mRange;
            T mCurrentValue;
        public:
            Iterator(int start, RangeContainer& range) : mCurrentStep(start), mRange(range)
            {
                mCurrentValue = mRange.mBegin + mCurrentStep;
            }

            T operator * ()
            {
                return mCurrentValue;
            }

            bool operator != (const Iterator &another)
            {
                return mCurrentStep != another.mCurrentStep;
            }

            const Iterator & operator++()
            {
                mCurrentValue += 1;
                mCurrentStep++;
                return *this;
            }

        };

    public:
        RangeContainer(){
            mBegin =0;
            mEnd = 0;
            mSize = 0;
        }
        RangeContainer(const RangeContainer & o){
            *this = o;
        }
        RangeContainer & operator = (const RangeContainer & o){
            this->mBegin = o.mBegin;
            this->mEnd = o.mEnd;
            this->mSize = o.mSize;
            return *this;
        }
        RangeContainer(T begin, T end) : mBegin(begin), mEnd(end)
        {
            if(mBegin > mEnd)
                throw std::logic_error("end must greater than begin.");

            mSize = (mEnd - mBegin) + 1 ;
        };

        int getStart() const {return mBegin;}
        int getEnd() const {return mEnd;}

        int size() const { return mSize;}

        Iterator begin()
        {
            return Iterator(0, *this);
        }

        Iterator end()
        {
            return Iterator(mSize, *this);
        }

    };

    template <typename T, typename U = int>
    auto range(T begin, T end)->RangeContainer<decltype(begin)>
    {
        return RangeContainer<decltype(begin)>(begin, end);
    };

    template <typename T>
    RangeContainer<T> range(T end)
    {
        return RangeContainer<T>(0, end);
    };

    typedef RangeContainer<int> NumberRangeList;

}
#endif //YAUAACPP_NUMBERRANGELIST_H
