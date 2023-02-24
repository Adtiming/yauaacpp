//
// Created by sunxg on 22-2-5.
//

#ifndef YAUAACPP_STRINGPREFIXMAP_H
#define YAUAACPP_STRINGPREFIXMAP_H

#include "PrefixMap.h"
#include "StringPrefixTrie.h"
#include "tool/tool.h"

namespace ycpp {

    template <typename V>
    class StringPrefixMap : public PrefixMap<V> {
    private:
        bool caseSensitive;
        PrefixTrie<V> * prefixTrie;
        std::map<std::wstring, V> allPrefixes;

        std::wstring storedKey(const std::string & key) {
            std::wstring t = string_to_wstring(key);
            if (prefixTrie->caseSensitive()) {
                return t;
            } else {
                std::transform(t.begin(), t.end(), t.begin(), ::tolower);
                return t;
            }
        }

    public:
        virtual ~StringPrefixMap(){
            if(prefixTrie)
                delete prefixTrie;
        }

        PrefixTrie<V> * createTrie(bool newCaseSensitive) {
            return new StringPrefixTrie<V>(newCaseSensitive);
        }

        explicit StringPrefixMap(bool caseSensitive) {
            this->caseSensitive = caseSensitive; // Only needed for serialization.
            prefixTrie = createTrie(caseSensitive);
        }


        bool containsPrefix(const std::string & prefix) const override {
            std::wstring t = string_to_wstring(prefix);
            return prefixTrie->containsPrefix(t);
        }

        void put(const std::string & prefix, const V & value) override {
            std::wstring t = string_to_wstring(prefix);
            prefixTrie->add(t, value);
            allPrefixes[storedKey(prefix)] = value;
        }

        size_t size() const override {
            return allPrefixes.size();
        }


        void clear() {
            prefixTrie->clear();
            allPrefixes.clear();
        }

//
//        bool remove(const std::string & prefix) override {
//            if (prefix == null) {
//                throw NullPointerException("The prefix may not be null");
//            }
//            V oldValue = prefixTrie.remove(prefix);
//            if (oldValue != null) {
//                allPrefixes.remove(storedKey(prefix));
//            }
//            return oldValue;
//        }


        bool get(const std::string & prefix, V & v) const override {
            std::wstring t = string_to_wstring(prefix);
            return prefixTrie->get(t,v);
        }


        bool getShortestMatch(const std::string & input, V & v) const override {
            std::wstring t = string_to_wstring(input);
            return prefixTrie->getShortestMatch(t, v);
        }


        bool getLongestMatch(const std::string & input, V & v) const override {
            std::wstring t = string_to_wstring(input);
            return prefixTrie->getLongestMatch(t, v);
        }

    };

}

#endif //YAUAACPP_STRINGPREFIXMAP_H
