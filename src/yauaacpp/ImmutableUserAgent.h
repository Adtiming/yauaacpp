/*
 * Yet Another UserAgent Analyzer cpp version
 * Copyright (C) 2023 Adtiming
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef YAUAACPP_IMMUTABLEUSERAGENT_H
#define YAUAACPP_IMMUTABLEUSERAGENT_H

#include "UserAgent.h"
#include "ImmutableUserAgent.h"
#include <UserAgentBaseListener.h>
#include <DefaultANTLRErrorListener.h>

namespace ycpp{

    class MutableUserAgent : public UserAgent, public UserAgentBaseListener,public DefaultANTLRErrorListener {
    private:


        std::set<std::string> wantedFieldNames;
        bool     _hasSyntaxError;
        bool     _hasAmbiguity;
        int         ambiguityCount;

        std::shared_ptr<MutableAgentField> userAgentStringField;

        bool debug = false;

        std::map<std::string, MutableAgentField *> allFields;

        void setWantedFieldNames(const std::set<std::string> & newWantedFieldNames) {
            if (!newWantedFieldNames.empty()) {
                wantedFieldNames.insert(newWantedFieldNames.begin(),newWantedFieldNames.end());
            }
        }

    protected:
        // The original input value
        std::string userAgentString;

    public:
        ~MutableUserAgent() override;

        static std::string getDefaultValueForField(const std::string & fieldName);

        void destroy() {
        }

        bool hasSyntaxError() const override {
            return _hasSyntaxError;
        }

        bool hasAmbiguity() const override {
            return _hasAmbiguity;
        }

        int getAmbiguityCount() const override {
            return ambiguityCount;
        }

        size_t getAllFieldsSize() const{
            return allFields.size();
        }


        void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                         size_t charPositionInLine, const std::string &msg, std::exception_ptr e) override;


        void reportAmbiguity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
                             bool exact,
                             const antlrcpp::BitSet &ambigAlts, antlr4::atn::ATNConfigSet *configs) override;

        bool isDebug() const {
            return debug;
        }

        void setDebug(bool newDebug) {
            this->debug = newDebug;
        }


        bool equals(MutableUserAgent * agent) {
            return uaEquals(agent);
        }


        size_t hashCode() {
            return uaHashCode();
        }


        MutableUserAgent() {
            userAgentStringField = nullptr;
            reset();
        }

        MutableUserAgent(const std::set<std::string> & wantedFieldNames) {
            setWantedFieldNames(wantedFieldNames);
        }

        MutableUserAgent(const std::string & userAgentString) {
            // wantedFieldNames == null; --> Assume we want all fields.
            setUserAgentString(userAgentString);
        }

        MutableUserAgent(const std::string & userAgentString, const std::set<std::string> & wantedFieldNames) {
            setWantedFieldNames(wantedFieldNames);
            setUserAgentString(userAgentString);
        }

        void setUserAgentString(const std::string & newUserAgentString);

        std::string getUserAgentString() const {
            return userAgentString;
        }

        void reset();

        static bool isSystemField(const std::string & fieldname) {
            return fieldname == SET_ALL_FIELDS ||
                   fieldname == SYNTAX_ERROR ||
                   fieldname == USERAGENT_FIELDNAME;
        }

        void processSetAll();

        void set(const std::string & attribute, const std::string & value, long confidence);

        void setForced(const std::string & attribute,const std::string & value, long confidence);

        // The appliedMatcher parameter is needed for development and debugging.
        void set(std::shared_ptr<MutableUserAgent> newValuesUserAgent, Matcher * appliedMatcher);

        void setImmediateForTesting(const std::string & fieldName, const MutableAgentField & agentField);

        AgentField & get(const std::string & fieldName) override ;

        std::string getValue(const std::string & fieldName) const override;

        long getConfidence(const std::string & fieldName) const override;


        std::list<std::string> getAvailableFieldNamesSorted() const;


        std::string toString() {
            return UserAgent::toString(getAvailableFieldNamesSorted());
        }

        std::string toString(int num, ...) {
            va_list vap;
            va_start(vap,num);
            std::list<std::string> fields;
            char * para;
            for(int i=0; i<num; i++){
                para = va_arg( vap, char *);
                fields.push_back(para);
            }
            std::string r = UserAgent::toString(fields);
            va_end(vap);
            return r;
        }
    };


    class ImmutableUserAgent :public UserAgent {
    private:
        std::string                            userAgentString;
        std::shared_ptr<ImmutableAgentField>   userAgentStringField;
        std::map<std::string, ImmutableAgentField *>  allFields;
        std::map<std::string, ImmutableAgentField *>  defaultValueFields;
        std::list<std::string>                      availableFieldNamesSorted;
        bool                           _hasSyntaxError;
        bool                           _hasAmbiguity;
        int                               ambiguityCount;

        ImmutableUserAgent(){
            _hasSyntaxError = false;
            _hasAmbiguity = false;
            ambiguityCount = 0;
            userAgentStringField = nullptr;
        }
    public:
        explicit ImmutableUserAgent(MutableUserAgent & userAgent);

        ~ImmutableUserAgent() override;


        std::string getUserAgentString() const override {
            return userAgentString;
        }

        AgentField & get(const std::string & fieldName) override ;

        std::string getValue(const std::string & fieldName) const override ;

        long getConfidence(const std::string & fieldName) const override ;

        bool hasSyntaxError() const override {
            return _hasSyntaxError;
        }

        bool hasAmbiguity() const override {
            return _hasAmbiguity;
        }

        int getAmbiguityCount() const override {
            return ambiguityCount;
        }


        std::list<std::string> getAvailableFieldNamesSorted() const override {
            return availableFieldNamesSorted;
        }


        bool equals(UserAgent * o){
            return uaEquals(o);
        }


        size_t hashCode() {
            return uaHashCode();
        }


        std::string toString() {
            return UserAgent::toString(getAvailableFieldNamesSorted());
        }

    };
}

#endif //YAUAACPP_IMMUTABLEUSERAGENT_H
