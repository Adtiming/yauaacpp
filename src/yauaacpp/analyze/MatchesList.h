//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MATCHESLIST_H
#define YAUAACPP_MATCHESLIST_H

#include <list>
#include <iostream>
#include <sstream>

#include "yauaacpp_def.h"
#include "tool/tool.h"


namespace ycpp {
    struct Match {
        std::string key;
        std::string value;
        antlr4::tree::ParseTree * result;

        Match() {
            result = nullptr;
        }

        Match(const std::string & key, const std::string & value, antlr4::tree::ParseTree * result) {
            fill(key, value, result);
        }

        void fill(const std::string & nKey, const std::string & nValue, antlr4::tree::ParseTree * nResult) {
            this->key = nKey;
            this->value = nValue;
            this->result = nResult;
        }

        std::string getKey() {
            return key;
        }

        std::string getValue() {
            return value;
        }

        antlr4::tree::ParseTree * getResult() {
            return result;
        }
    };


    class MatchesList : public std::list<Match> {
    public:
        MatchesList(){

        }

        explicit MatchesList(size_t size):std::list<Match>(size){

        }
        void add(const std::string & key, const std::string & value, antlr4::tree::ParseTree *result) {
            push_back(Match(key, value, result));
        }

        std::list<std::string> toStrings() {
            std::list<std::string> result ;
            for (Match & match: *this) {
                result.push_back("{ \"" + match.key + "\"=\"" + match.value + "\" }");
            }
            return result;
        }

        std::string toString() {
            std::ostringstream o;
            o << "MatchesList(" << size() << ") [";
            std::list<std::string> l = toStrings();
            size_t i=0;
            for(std::string & s : l){
                o << s;
                if(i<l.size()-1)
                    o << ",";
            }

            o << ") ";
            return o.str();
        }

    };
}
#endif //YAUAACPP_MATCHESLIST_H
