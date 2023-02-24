//
// Created by sunxg on 22-2-3.
//

#include "WordSplitter.h"

namespace ycpp {
    WordSplitter * WordSplitter::instance = nullptr;

    bool WordSplitter::isSeparator(unsigned short c) {
        switch (c) {
            case '|': // Next segment
            case ' ':
            case '.':
            case ':':
            case ';':
            case '=':
            case '/':
            case '\\':
            case '+':
            case '-':
            case '_':
            case '<':
            case '>':
            case '~':
            case '(': // EndOfString marker
            case ')': // EndOfString marker
                return true;
            default:
                return false;
        }
    }

    bool WordSplitter::isEndOfStringSeparator(unsigned short c) {
        return c == '(' || c == ')';
    }
}
