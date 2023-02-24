//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_WORDSPLITTER_H
#define YAUAACPP_WORDSPLITTER_H

#include "yauaacpp_def.h"
#include "Splitter.h"

namespace ycpp {

    class WordSplitter : public Splitter {
    private:
        WordSplitter() {
        }

        static WordSplitter * instance;

    public:
        static WordSplitter * getInstance() {
            if (instance == nullptr) {
                instance = new WordSplitter();
            }
            return instance;
        }

        bool isSeparator(unsigned short c) override ;
        bool isEndOfStringSeparator(unsigned short c) override ;
    };

}
#endif //YAUAACPP_WORDSPLITTER_H
