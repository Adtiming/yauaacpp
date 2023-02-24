//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_LISTSPLITTER_H
#define YAUAACPP_LISTSPLITTER_H

#include "yauaacpp_def.h"
#include "Splitter.h"

namespace ycpp {

    class ListSplitter : public Splitter {
    private:
        ListSplitter() {
        }

        static ListSplitter * instance;
        static std::mutex lock;

    public:
        static ListSplitter * getInstance();

        bool isSeparator(unsigned short c) override {
            return c == '|';
        }
        bool isEndOfStringSeparator(unsigned short c) override {
            return false;
        }
};

}
#endif //YAUAACPP_LISTSPLITTER_H
