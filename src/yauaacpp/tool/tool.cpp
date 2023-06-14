//
// Created by sunxg on 22-1-28.
//

#include "tool.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <assert.h>
#include <stdarg.h>
#include <algorithm>
#include <time.h>
#include <sys/time.h>
#include <codecvt>

namespace ycpp {
    void string_replace(std::string &s1, const std::string &from, const std::string &to) {
        std::string::size_type pos = 0;
        std::string::size_type a = from.size();
        std::string::size_type b = to.size();
        while ((pos = s1.find(from, pos)) != std::string::npos) {
            s1.replace(pos, a, to);
            pos += b;
        }
    }

    std::string escape_json(const std::string &s) {
        std::ostringstream o;
        for (auto c = s.cbegin(); c != s.cend(); c++) {
            switch (*c) {
                case '"':
                    o << "\\\"";
                    break;
                case '\\':
                    o << "\\\\";
                    break;
                case '\b':
                    o << "\\b";
                    break;
                case '\f':
                    o << "\\f";
                    break;
                case '\n':
                    o << "\\n";
                    break;
                case '\r':
                    o << "\\r";
                    break;
                case '\t':
                    o << "\\t";
                    break;
                default:
                    if ('\x00' <= *c && *c <= '\x1f') {
                        o << "\\u"
                          << std::hex << std::setw(4) << std::setfill('0') << (int) *c;
                    } else {
                        o << *c;
                    }
            }
        }
        return o.str();
    }

    std::string escape_xml10(const std::string &s) {
        return s;
    }

    std::string uitos(size_t value){
        char buf[100];
        uitoa(buf,value);
        return std::string(buf);
    }

    std::string itos(int value){
        char buf[100];
        if(value<0) {
            buf[0] = '-';
            uitoa(buf+1,(size_t)(-value));
        } else {
            uitoa(buf,(size_t)value);
        }
        return std::string(buf);
    }

    size_t uitoa(char* result, size_t value)
    {
        return uitoa(result, value, 10);
    }

    size_t uitoa(char* result, size_t value, int base) {
        // check that the base if valid
        assert (base >= 2 && base <= 36) ;

        char* ptr = result, *ptr1 = result, tmp_char;
        size_t tmp_value;

        do {
            tmp_value = value;
            value /= base;
            *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
        } while ( value );

        size_t len = ptr - result;
        *ptr-- = '\0';

        while(ptr1 < ptr) {
            tmp_char = *ptr;
            *ptr--= *ptr1;
            *ptr1++ = tmp_char;
        }
        return len;
    }

    void add_all(std::list<std::string>& l, const char * str_array[], size_t size){
        for(size_t i=0; i<size; i++)
            l.emplace_back(str_array[i]);
    }

    std::string& trim(std::string& text)
    {
        if(!text.empty())
        {
            text.erase(0, text.find_first_not_of(" \n\r\t"));
            text.erase(text.find_last_not_of(" \n\r\t") + 1);
        }
        return text;
    }

    bool ends_with_ignore_case(const std::string& value, const std::string& match){
        if(match.size() > value.size())
            return false;
        return icasecompare(value.substr(value.size() - match.size()),match);
    }

    bool starts_with_ignore_case(const std::string& value, const std::string& match){
        if(match.size() > value.size())
            return false;
        return icasecompare(value.substr(0,value.size()),match);
    }

    bool icasecompare(const std::string& a, const std::string& b) {
        if (a.length() == b.length()) {
            return std::equal(a.begin(), a.end(), b.begin(),
                              [](char a, char b) {
                                  return std::tolower(a) == std::tolower(b);
                              });
        }
        else {
            return false;
        }
    }

    bool contains(const std::string &value, const std::string &match) {
        return (std::string::npos != value.find(match));
    }

    std::vector<std::string> string_split(const std::string& str, char delim, size_t limit) {
        std::stringstream ss(str);
        std::string item;
        std::vector<std::string> elems;
        while ((limit==0 || elems.size()<limit-1) && std::getline(ss, item, delim)) {
            if (!item.empty()) {
                elems.push_back(item);
            }
        }
        if(std::getline(ss, item, (char)0))
            elems.push_back(item);
        return elems;
    }

    long get_cur_msec() {
        int secs, msecs;
        struct timeval tv;
        ::gettimeofday(&tv, NULL);
        secs = (int) tv.tv_sec;
        msecs = (int) (tv.tv_usec / 1000);
        return secs*1000+msecs;
    }

    std::string wstring_to_string(const std::wstring &s) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.to_bytes(s);;
    }

    std::wstring string_to_wstring(const std::string &s) {
        std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
        return converter.from_bytes(s);
    }

    std::string string_format(const char * format, ...){
        std::string s;
        va_list vap;
        va_start(vap, format);
        int nLength = vprintf(format, vap);
        nLength += 1;  //上面返回的长度是包含\0，这里加上
        char vectorChars[nLength];
        vsnprintf(vectorChars, nLength, format, vap);
        s.assign(vectorChars);
        va_end(vap);
        return s;
    }
    void LOG::warn(const char *format, ...) {
        std::string _format = format;
        _format += "\n";
        va_list vap;
        va_start(vap, format);
        vfprintf(stderr,_format.c_str(),vap);
        va_end(vap);
    }

    void LOG::info(const char *format, ...) {
        std::string _format = format;
        _format += "\n";
        va_list vap;
        va_start(vap, format);
        vfprintf(stderr,_format.c_str(),vap);
        va_end(vap);
    }

    void LOG::error(const char *format, ...) {
        std::string _format = format;
        _format += "\n";
        va_list vap;
        va_start(vap, format);
        vfprintf(stderr,_format.c_str(),vap);
        va_end(vap);
    }
    void LOG::debug(const char * format, ...) {
        std::string _format = format;
        _format += "\n";
        va_list vap;
        va_start(vap, format);
        vfprintf(stderr,_format.c_str(),vap);
        va_end(vap);
    }



} // namespace ycpp