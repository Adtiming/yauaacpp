//
// Created by sunxg on 22-2-5.
//

#ifndef YAUAACPP_STRINGPREFIXTRIE_H
#define YAUAACPP_STRINGPREFIXTRIE_H

#include <string>
#include <antlr4-runtime.h>

namespace ycpp {
    template <typename V>
    class PrefixTrie{
    public:
        virtual ~PrefixTrie(){}
        /**
         * <p>Add a new prefix and related value to the PrefixTrie.</p>
         * @param prefix The prefix for which we want to store the provided value
         * @param value The value that we want to store. The may NOT be null.
         * @return The previously stored value, null if no previous value was present.
         */
        virtual void add(const std::wstring & prefix, const V & value) = 0;
        /**
         * <p>Determine if we have a value for the <code>exact</code> prefix. </p>
         * @param prefix The string for which we need to know if it is present
         * @return True if the exact prefix value is present, False otherwise
         */
        virtual bool containsPrefix(const std::wstring & prefix) const = 0;
        /**
         * <p>Return the value of the <code>exact</code> matching prefix. </p>
         * <p>The value returned is the stored prefix for which is true:
         * <code>input.equals(prefix)</code>.</p>
         * <p>Note that implementations may be constructed to match either
         * case sensitive or case insensitive.</p>
         *
         * @param input The string for which we need value of the stored prefix
         * @return The value, null if not found.
         */
        virtual bool get(const std::wstring & input, V & v) const = 0;
        /**
         * <p>Return the value of the <code>shortest</code> matching prefix. </p>
         * <p>The value returned is the shortest stored prefix for which is true:
         * <code>input.startsWith(prefix)</code>.</p>
         * <p>Note that implementations may be constructed to match either
         * case sensitive or case insensitive.</p>
         *
         * @param input The string for which we need value of the stored prefix
         * @return The value, null if not found.
         */
        virtual bool getShortestMatch(const std::wstring & input,V & v) const = 0;

        /**
         * <p>Return the value of the longest matching prefix.</p>
         * <p>The value returned is the longest stored prefix for which is true:
         * <code>input.startsWith(prefix)</code>.</p>
         * <p>Note that implementations may be constructed to match either
         * case sensitive or case insensitive.</p>
         *
         * @param input The string for which we need value of the stored prefix
         * @return The value, null if not found.
         */
        virtual bool getLongestMatch(const std::wstring & input, V & v) const = 0;

        virtual bool remove(const std::wstring & prefix) {
            throw antlr4::RuntimeException("The 'remove(const std::string & prefix)' "
                                           "method has not been implemented in PrefixTrie");
        }

        /**
         * Wipe all prefixes and values.
         */
        virtual void clear() = 0;

        /**
         * Is the matching being done in a case sensitive way?
         * @return True if the case 'a'/'A' makes a difference, False if they should be considered the same.
         */
        virtual bool caseSensitive() const = 0;
    };

    template <typename V>
    class StringPrefixTrie: public PrefixTrie<V> {
    private:
        bool                     _caseSensitive;
        size_t                   charIndex;
        std::map<wchar_t , std::shared_ptr<PrefixTrie<V>>> childNodes;
        V *                      theValue;
    public:
        explicit StringPrefixTrie(bool caseSensitive):_caseSensitive(caseSensitive),charIndex(0) {
            theValue = nullptr;
        }

        explicit StringPrefixTrie(bool caseSensitive, int charIndex):_caseSensitive(caseSensitive),charIndex(charIndex) {
            theValue = nullptr;
        }

        virtual ~StringPrefixTrie(){
            clear();
        }

        void add(const std::wstring & prefix, const V & value) override {
            if (charIndex == prefix.length()) {
                if(theValue)
                    *theValue = value;
                else
                    theValue = new V(value);
                return ;
            }

            wchar_t myChar = prefix[charIndex];

            if (_caseSensitive) {
                std::shared_ptr<PrefixTrie<V>> child;
                auto it = childNodes.find(myChar);
                if(it == childNodes.end()){
                    child = std::make_shared<StringPrefixTrie<V>>(true, charIndex + 1);
                    childNodes[myChar] = child;
                } else
                    child = it->second;
                child->add(prefix, value);
            } else {
                // If case INsensitive we build the tree
                // and we link the same child to both the
                // lower and uppercase entries in the child array.
                wchar_t lower = std::tolower(myChar);
                wchar_t upper = std::toupper(myChar);

                std::shared_ptr<PrefixTrie<V>> child;
                auto it = childNodes.find(lower);
                if(it == childNodes.end()){
                    child = std::make_shared<StringPrefixTrie<V>>(false, charIndex + 1);
                    childNodes[lower] = child;
                } else
                    child = it->second;

                child->add(prefix, value);
                childNodes[upper] = child;
            }
        }

        bool remove(const std::wstring & prefix) override {
            if (charIndex == prefix.length()) {
                delete theValue;
                theValue = nullptr;
                return true;
            }

            if (childNodes.empty()) {
                return false;
            }

            wchar_t myChar = prefix[charIndex]; // This will give us the ASCII value of the char

            if (!_caseSensitive) {
                // If case INsensitive we only follow the lower case one.
                myChar = std::tolower(myChar);
            }

            auto it = childNodes.find(myChar);
            if(it == childNodes.end())
                return false;

            std::shared_ptr<PrefixTrie<V>> child = it->second;

            return child->remove(prefix);
        }

        bool containsPrefix(const std::wstring & prefix) const override {
            V v;
            return get(prefix,v);
        }

        bool get(const std::wstring & prefix, V & v) const override {
            if (charIndex == prefix.length()) {
                v = *theValue;
                return true;
            }

            if (childNodes.empty()) {
                return false;
            }

            wchar_t myChar = prefix[charIndex];

            auto it = childNodes.find(myChar);
            if(it == childNodes.end())
                return false;
            std::shared_ptr<PrefixTrie<V>> child = it->second;

            return child->get(prefix,v);
        }

        bool getShortestMatch(const std::wstring & input, V & v) const override {
            if (theValue != nullptr ||
                charIndex == input.length() ||
                childNodes.empty()) {
                v = *theValue;
                return true;
            }

            wchar_t myChar = input[charIndex];

            auto it = childNodes.find(myChar);
            if(it == childNodes.end())
                return false;

            std::shared_ptr<PrefixTrie<V>> child = it->second;

            return child->getShortestMatch(input, v);
        }

        bool getLongestMatch(const std::wstring & input, V & v) const override {
            if (charIndex == input.length() || childNodes.empty()) {
                if(theValue == nullptr)
                    return false;
                v = *theValue;
                return true;
            }

            wchar_t myChar = input[charIndex];
            auto it = childNodes.find(myChar);
            if(it == childNodes.end()){
                if(theValue == nullptr)
                    return false;
                v = *theValue;
                return true;
            }
            std::shared_ptr<PrefixTrie<V>> child = it->second;


            if(child->getLongestMatch(input,v))
                return true;
            if(theValue == nullptr)
                return false;
            v = *theValue;
            return true;
        }

        void clear() override {
            childNodes.clear();
            if(theValue)
                delete theValue;
            theValue = nullptr;
        }
        bool caseSensitive() const override {
            return _caseSensitive;
        }
    };


}

#endif //YAUAACPP_STRINGPREFIXTRIE_H
