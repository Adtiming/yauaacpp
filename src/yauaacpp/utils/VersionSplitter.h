//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_VERSIONSPLITTER_H
#define YAUAACPP_VERSIONSPLITTER_H

#include "yauaacpp_def.h"
#include "Splitter.h"

namespace ycpp {

    class VersionSplitter : public Splitter {
    private:
        VersionSplitter() = default;

        static VersionSplitter * instance;
        bool looksLikeEmailOrWebaddress(const std::string & value);
    public:
        static VersionSplitter * getInstance();

        bool isSeparator(unsigned short c) override;


        bool isEndOfStringSeparator(unsigned short c) override {
            return false;
        }

        std::string getSingleSplit(const std::string & value, int split);


        std::string getFirstSplits(const std::string & value, int split);

    };

}
#endif //YAUAACPP_VERSIONSPLITTER_H
