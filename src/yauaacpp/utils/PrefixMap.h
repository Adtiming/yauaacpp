//
// Created by sunxg on 22-2-5.
//

#ifndef YAUAACPP_PREFIXMAP_H
#define YAUAACPP_PREFIXMAP_H

#include <glob.h>
#include <string>
#include <map>
#include <tool/tool.h>

namespace ycpp {

    template <typename V>
    class PrefixMap{
    public:
        virtual ~PrefixMap(){}
        virtual size_t size() const = 0;
        virtual bool containsPrefix(const std::string & prefix) const = 0;
        virtual void put(const std::string & prefix, const V & value) = 0;
        virtual bool get(const std::string & prefix, V & v) const = 0;
        virtual void clear() = 0;
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
        virtual bool getShortestMatch(const std::string & input, V & v) const = 0;
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
        virtual bool getLongestMatch(const std::string & input, V & v) const = 0;
        bool isEmpty() {
            return size() == 0;
        }
        void putAll(STRMAP_SP prefixesAndValues) {
            for(auto it = prefixesAndValues->begin(); it!=prefixesAndValues->end(); it++)
                this->put(it->first,it->second);
        }
    };

}
#endif //YAUAACPP_PREFIXMAP_H
