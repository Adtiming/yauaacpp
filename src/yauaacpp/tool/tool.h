//
// Created by sunxg on 22-1-28.
//

#ifndef YAUAACPP_TOOL_H
#define YAUAACPP_TOOL_H

#include "yauaacpp_def.h"
#include <string>
#include <list>
#include <vector>
#include <set>
#include <sstream>
#include <iosfwd>
#include <algorithm>

namespace ycpp {

    void string_replace(std::string &s1, const std::string &from, const std::string &to);

    template <typename T>
    bool starts_with(const std::basic_string<T>& value, const std::basic_string<T>& match){
        return ((match.size() <= value.size()) &&
                std::equal(match.begin(), match.end(), value.begin()));
    }

    template <typename T>
    bool ends_with(const std::basic_string<T>& value, const std::basic_string<T>& match){
        return ((match.size() <= value.size()) &&
                value.compare(value.size() - match.size(), match.size(), match) ==
                0);
    }

    bool ends_with_ignore_case(const std::string& value, const std::string& match);

    bool starts_with_ignore_case(const std::string& value, const std::string& match);

    bool icasecompare(const std::string& a, const std::string& b);

    bool contains(const std::string& value, const std::string& match);

    template <typename T>
    std::basic_string<T> tolowers(const std::basic_string<T>& s){
        std::basic_string<T> t = s;
        std::for_each(t.begin(), t.end(), [](T & c){
            c = ::tolower(c);
        });
        return t;
    }

    std::string escape_json(const std::string &s);

    std::string escape_xml10(const std::string &s);

    std::string uitos(size_t value);
    std::string itos(int value);
    size_t uitoa(char* result, size_t value);
    size_t uitoa(char* result, size_t value, int base);

    std::vector<std::string> string_split(const std::string& str, char delim, size_t limit=0);

    void add_all(std::list<std::string>& l, const char * str_array[], size_t size);

    std::string& trim(std::string& text);

    std::string wstring_to_string(const std::wstring & s);
    std::wstring string_to_wstring(const std::string & s);

    template <typename str_iterator>
    std::string to_string(const str_iterator & begin, const str_iterator & end){
        std::ostringstream o;
        o << '[';
        str_iterator it=begin;
        while(it!=end){
            o << (*it).c_str();
            it ++;
            if(it!=end)
                o << ',';
        }
        o << ']';
        return o.str();
    }
    template <typename str_iterator>
    std::string to_string_objs(const str_iterator & begin, const str_iterator & end){
        std::ostringstream o;
        o << '[';
        str_iterator it=begin;
        while(it!=end){
            o << (*it)->toString().c_str();
            it ++;
            if(it!=end)
                o << ',';
        }
        o << ']';
        return o.str();
    }
    template <typename pair_iterator>
    std::string to_pair_string(const pair_iterator & begin, const pair_iterator & end){
        std::ostringstream o;
        o << '[';
        pair_iterator it=begin;
        while(it!=end){
            o << it->first.c_str();
            o << "->";
            o << it->second.c_str();
            it ++;
            if(it!=end)
                o << ',';
        }
        o << ']';
        return o.str();
    }

    long get_cur_msec();

    std::string string_format(const char * format, ...);

    class LOG {
    public:
        static bool isInfoEnabled(){return true;}
        static bool isWarnEnabled(){return true;}
        static bool isErrorEnabled(){return true;}
        static void warn(const char * format, ...);
        static void info(const char * format, ...);
        static void error(const char * format, ...);
        static void debug(const char * format, ...);
    };
}

#endif //YAUAACPP_TOOL_H
