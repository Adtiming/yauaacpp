//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_SPLITTER_H
#define YAUAACPP_SPLITTER_H

#include "yauaacpp_def.h"
#include "analyze/WordRangeVisitor.h"
#include <codecvt>
#include <locale>

namespace ycpp {

    template<class Facet>
    struct deletable_facet : Facet
    {
        template<class ...Args>
        deletable_facet(Args&& ...args) : Facet(std::forward<Args>(args)...) {}
        ~deletable_facet() {}
    };

    class Splitter {
    protected:
        virtual bool isSeparator(unsigned short c) = 0;

        virtual bool isEndOfStringSeparator(unsigned short c) = 0;

    public:
        virtual ~Splitter() {};
        /**
         * Find the start offset of next split
         *
         * @param chars The input in which we are seeking
         * @param offset The start offset from where to seek
         * @return The offset of the next split
         */
        int findNextSplitStart(const std::u16string & chars, int offset) {
            for (size_t charNr = offset; charNr<chars.size(); charNr++) {
                unsigned short theChar = chars[charNr];
                if (isEndOfStringSeparator(theChar)) {
                    return -1;
                }
                if (!isSeparator(theChar)) {
                    return charNr;
                }
            }
            return -1;
        }

        /**
         * Find the end of the string
         *
         * @param chars The input in which we are seeking
         * @param offset The start offset from where to seek
         * @return The offset of the last character of the last split.
         */
        int findEndOfString(const std::u16string & chars, int offset) {
            for (size_t charNr = offset; charNr<chars.size(); charNr++) {
                char theChar = chars[charNr];
                if (isEndOfStringSeparator(theChar)) {
                    return charNr;
                }
            }
            return chars.size();
        }

        /**
         * Find the start offset of split
         *
         * @param chars The input in which we are seeking
         * @param split  The split number for which we are looking for the start
         * @return The offset or -1 if it does not exist
         */
        int findSplitStart(const std::u16string & chars, int split) {
            if (split <= 0) {
                return -1;
            }
            // We expect the chars to start with a split.
            int charNr = 0;
            bool inSplit = false;
            int currentSplit = 0;
            for (size_t i=0; i<chars.size(); i++) {
                wchar_t theChar = chars[i];
                if (isEndOfStringSeparator(theChar)) {
                    return -1;
                }

                if (isSeparator(theChar)) {
                    if (inSplit) {
                        inSplit = false;
                    }
                } else {
                    if (!inSplit) {
                        inSplit = true;
                        currentSplit++;
                        if (currentSplit == split) {
                            return charNr;
                        }
                    }
                }
                charNr++;
            }
            return -1;
        }

        int findSplitEnd(const std::u16string & chars, int startOffset) {
            size_t i = startOffset;
            while (i < chars.size()) {
                if (isSeparator(chars[i])) {
                    return i;
                }
                i++;
            }
            return chars.size(); // == The end of the string
        }

        std::string getSingleSplit(const std::string & value, int split) {
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

        std::string getFirstSplits(const std::string & value, int split) {
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

        std::string getSplitRange(const std::string & value, int firstSplit, int lastSplit) {
            if (value == "" || (lastSplit > 0 && lastSplit < firstSplit)) {
                return "";
            }
            std::u16string characters;
            std::wstring_convert<
                    deletable_facet<std::codecvt<char16_t, char, std::mbstate_t>>, char16_t> conv16;
            characters = conv16.from_bytes(value);
            int firstCharOfFirstSplit = findSplitStart(characters, firstSplit);
            if (firstCharOfFirstSplit == -1) {
                return "";
            }

            if (lastSplit == -1) {
                return value.substr(firstCharOfFirstSplit, findEndOfString(characters, firstCharOfFirstSplit)-firstCharOfFirstSplit);
            }
            int firstCharOfLastSplit = firstCharOfFirstSplit;
            if (lastSplit != firstSplit) {
                firstCharOfLastSplit = findSplitStart(characters, lastSplit);
                if (firstCharOfLastSplit == -1) {
                    return "";
                }
            }

            int lastCharOfLastSplit = findSplitEnd(characters, firstCharOfLastSplit);

            return value.substr(firstCharOfFirstSplit, lastCharOfLastSplit-firstCharOfFirstSplit);
        }

        std::string getSplitRange(const std::string & value, const Range & range) {
            return getSplitRange(value, range.getFirst(), range.getLast());
        }

        std::string getSplitRange(const std::string & value, std::vector<std::pair<int, int>> splitList, const Range & range) {
            return getSplitRange(value, splitList, range.getFirst(), range.getLast());
        }

        std::string getSplitRange(const std::string & value, std::vector<std::pair<int, int>> splitList, int first, int last) {
            int lastIndex = last - 1;
            int firstIndex = first - 1;
            int splits = splitList.size();

            if (last == -1) {
                lastIndex = splits - 1;
            }
            if (firstIndex < 0 || lastIndex < 0) {
                return "";
            }
            if (firstIndex >= splits || lastIndex >= splits) {
                return "";
            }

            return value.substr(splitList[firstIndex].first, splitList[lastIndex].second-splitList[firstIndex].first);
        }

        std::vector<std::pair<int, int>> createSplitList(const std::string & characters) {
            std::u16string cs;
            std::wstring_convert<
                    deletable_facet<std::codecvt<char16_t, char, std::mbstate_t>>, char16_t> conv16;
            cs = conv16.from_bytes(characters);
            return createSplitList(cs);
        }

        std::vector<std::pair<int, int>> createSplitList(const std::u16string & characters){
            std::vector<std::pair<int, int>> result;

            int offset = findSplitStart(characters, 1);
            if (offset == -1) {
                return result; // Nothing at all. So we are already done
            }
            while(offset != -1) {

                int start = offset;
                int end= findSplitEnd(characters, start);

                result.emplace_back(std::pair<int, int>(start, end));
                offset = findNextSplitStart(characters, end);
            }
            return result;
        }

    };
}
#endif //YAUAACPP_SPLITTER_H
