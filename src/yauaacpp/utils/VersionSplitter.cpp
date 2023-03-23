//
// Created by sunxg on 22-2-3.
//

#include "VersionSplitter.h"

namespace ycpp {

    VersionSplitter * VersionSplitter::instance = nullptr;

    bool VersionSplitter::isSeparator(unsigned short c) {
        switch (c) {
            case '|': // Next segment
            case '.':
            case '_':
            case '-':
            case ',':
                return true;
            default:
                return false;
        }
    }

    VersionSplitter *VersionSplitter::getInstance() {
        if (instance == nullptr) {
            instance = new VersionSplitter();
        }
        return instance;
    }

    std::string VersionSplitter::getSingleSplit(const std::string &value, int split) {
        if (looksLikeEmailOrWebaddress(value)) {
            return (split == 1) ? std::string(value) : "";
        }

        std::u16string characters;
        std::wstring_convert<
                deletable_facet<std::codecvt<char16_t, char, std::mbstate_t>>, char16_t> conv16;
        characters = conv16.from_bytes(value);
        int start = findSplitStart(characters, split);
        if (start == -1) {
            return "";
        }
        int end = findSplitEnd(characters, start);
        return value.substr(start, end-start);
    }

    std::string VersionSplitter::getFirstSplits(const std::string &value, int split) {
        if (looksLikeEmailOrWebaddress(value)) {
            return (split == 1) ? std::string(value) : "";
        }

        std::u16string characters;
        std::wstring_convert<
                deletable_facet<std::codecvt<char16_t, char, std::mbstate_t>>, char16_t> conv16;
        characters = conv16.from_bytes(value);
        int start = findSplitStart(characters, split);
        if (start == -1) {
            return "";
        }
        int end = findSplitEnd(characters, start);
        return value.substr(0, end);
    }

    bool VersionSplitter::looksLikeEmailOrWebaddress(const std::string &value) {
        // Simple quick and dirty way to avoid splitting email and web addresses
        return (starts_with(value,std::string("www.")) || starts_with(value,std::string("http")) || (std::string::npos != value.find("@") && std::string::npos != value.find(".")));
    }
}