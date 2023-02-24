/**************************************************************************
   Copyright (c) 2022 bearknocks

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
 *************************************************************************/

#ifndef BEARKNOCKS_USER_AGENT_H
#define BEARKNOCKS_USER_AGENT_H

#include <map>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

#include "yauaacpp_def.h"
#include "AgentField.h"
#include "yauaa_c.h"


namespace ycpp{
    class Matcher;

#ifndef _USERAGENT_CPP_
    // We manually sort the list of fields to ensure the output is consistent.
    // Any unspecified fieldnames will be appended to the end.
    extern const char * STANDARD_FIELDS[];
    extern const size_t STANDARD_FIELDS_SIZE;

    extern const char * PRE_SORTED_FIELDS_LIST[];
    extern size_t PRE_SORTED_FIELDS_LIST_SIZE;
#endif
        
    class UserAgent{
    public:
        virtual ~UserAgent(){}
        virtual std::string getUserAgentString() const = 0;
        virtual AgentField & get(const std::string & fieldName) = 0;
        virtual std::string getValue(const std::string & fieldName) const = 0;
        virtual long getConfidence(const std::string & fieldName) const = 0;
        virtual bool hasSyntaxError() const = 0;
        virtual bool hasAmbiguity() const = 0;
        virtual int getAmbiguityCount() const = 0;

        virtual std::list<std::string> getAvailableFieldNamesSorted() const = 0;


        std::string escapeYaml(const std::string & input) const;

        std::string toYamlTestCase() {
            return toYamlTestCase(false, std::map<std::string, std::string>());
        }

        std::string toYamlTestCase(bool showConfidence) {
            return toYamlTestCase(showConfidence, std::map<std::string, std::string>());
        }

        std::string toYamlTestCase(bool showConfidence, const std::map<std::string, std::string>& comments);

        std::map<std::string, std::string> toMap() {
            std::list<std::string> fields;
            fields.emplace_back(USERAGENT_FIELDNAME);
            fields.merge(getAvailableFieldNamesSorted());
            return toMap(fields);
        }

//        std::map<std::string, std::string> toMap(const std::string &... fieldNames) {
//            return toMap(Arrays.asList(fieldNames));
//        }

        std::map<std::string, std::string> toMap(const std::list<std::string> & fieldNames) {
            std::map<std::string, std::string> result;

            for (const std::string & fieldName : fieldNames) {
                if (fieldName == USERAGENT_FIELDNAME) {
                    result[USERAGENT_FIELDNAME] = getUserAgentString();
                } else {
                    const AgentField & field = get(fieldName);
                    result[fieldName] = field.getValue();
                }
            }
            return result;
        }

        std::string toJson() {
            std::list<std::string> fields;
            fields.emplace_back(USERAGENT_FIELDNAME);
            fields.merge(getAvailableFieldNamesSorted());
            return toJson(fields);
        }

//        std::string toJson(const std::string &... fieldNames) {
//            return toJson(Arrays.asList(fieldNames));
//        }

        std::string toJson(const std::list<std::string> & fieldNames);

        std::string toXML() {
            std::list<std::string> fields;
            fields.emplace_back(USERAGENT_FIELDNAME);
            fields.merge(getAvailableFieldNamesSorted());
            return toXML(fields);
        }

//        std::string toXML(const std::string &... fieldNames) {
//            return toXML(Arrays.asList(fieldNames));
//        }

        std::string toXML(const std::list<std::string> & fieldNames);

//        std::string toString(const std::string &... fieldNames) {
//            return toString(Arrays.asList(fieldNames));
//        }

        std::string toString(const std::list<std::string> & fieldNames);

        bool uaEquals(UserAgent * agent);

        size_t uaHashCode();

    };

} // namespace ycpp
#endif