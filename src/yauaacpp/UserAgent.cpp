#define _USERAGENT_CPP_
#include "UserAgent.h"
#include "ImmutableUserAgent.h"
#include <set>
#include <antlr4-runtime.h>
#include <ANTLRErrorListener.h>
#include <analyser/cpp/UserAgentBaseListener.h>
#include "DefaultANTLRErrorListener.h"
#include "analyze/Matcher.h"
#include "tool/tool.h"

namespace ycpp {

    const char * STANDARD_FIELDS[] = {
            DEVICE_CLASS,
            DEVICE_BRAND,
            DEVICE_NAME,
            OPERATING_SYSTEM_CLASS,
            OPERATING_SYSTEM_NAME,
            OPERATING_SYSTEM_VERSION,
            OPERATING_SYSTEM_VERSION_MAJOR,
            OPERATING_SYSTEM_NAME_VERSION,
            OPERATING_SYSTEM_NAME_VERSION_MAJOR,
            LAYOUT_ENGINE_CLASS,
            LAYOUT_ENGINE_NAME,
            LAYOUT_ENGINE_VERSION,
            LAYOUT_ENGINE_VERSION_MAJOR,
            LAYOUT_ENGINE_NAME_VERSION,
            LAYOUT_ENGINE_NAME_VERSION_MAJOR,
            AGENT_CLASS,
            AGENT_NAME,
            AGENT_VERSION,
            AGENT_VERSION_MAJOR,
            AGENT_NAME_VERSION,
            AGENT_NAME_VERSION_MAJOR
    };

    const size_t STANDARD_FIELDS_SIZE = sizeof(STANDARD_FIELDS)/sizeof(const char *);

    const char * PRE_SORTED_FIELDS_LIST[] = {
            DEVICE_CLASS,
            DEVICE_NAME,
            DEVICE_BRAND,
            DEVICE_CPU,
            DEVICE_CPU_BITS,
            DEVICE_FIRMWARE_VERSION,
            DEVICE_VERSION,

            OPERATING_SYSTEM_CLASS,
            OPERATING_SYSTEM_NAME,
            OPERATING_SYSTEM_VERSION,
            OPERATING_SYSTEM_VERSION_MAJOR,
            OPERATING_SYSTEM_NAME_VERSION,
            OPERATING_SYSTEM_NAME_VERSION_MAJOR,
            OPERATING_SYSTEM_VERSION_BUILD,

            LAYOUT_ENGINE_CLASS,
            LAYOUT_ENGINE_NAME,
            LAYOUT_ENGINE_VERSION,
            LAYOUT_ENGINE_VERSION_MAJOR,
            LAYOUT_ENGINE_NAME_VERSION,
            LAYOUT_ENGINE_NAME_VERSION_MAJOR,
            LAYOUT_ENGINE_BUILD,

            AGENT_CLASS,
            AGENT_NAME,
            AGENT_VERSION,
            AGENT_VERSION_MAJOR,
            AGENT_NAME_VERSION,
            AGENT_NAME_VERSION_MAJOR,
            AGENT_BUILD,
            AGENT_LANGUAGE,
            AGENT_LANGUAGE_CODE,
            AGENT_INFORMATION_EMAIL,
            AGENT_INFORMATION_URL,
            AGENT_SECURITY,
            AGENT_UUID,

            WEBVIEW_APP_NAME,
            WEBVIEW_APP_VERSION,
            WEBVIEW_APP_VERSION_MAJOR,
            WEBVIEW_APP_NAME_VERSION,
            WEBVIEW_APP_NAME_VERSION_MAJOR,

            FACEBOOK_CARRIER,
            FACEBOOK_DEVICE_CLASS,
            FACEBOOK_DEVICE_NAME,
            FACEBOOK_DEVICE_VERSION,
            FACEBOOK_F_B_O_P,
            FACEBOOK_F_B_S_S,
            FACEBOOK_OPERATING_SYSTEM_NAME,
            FACEBOOK_OPERATING_SYSTEM_VERSION,

            ANONYMIZED,

            HACKER_ATTACK_VECTOR,
            HACKER_TOOLKIT,

            KOBO_AFFILIATE,
            KOBO_PLATFORM_ID,

            IE_COMPATIBILITY_VERSION,
            IE_COMPATIBILITY_VERSION_MAJOR,
            IE_COMPATIBILITY_NAME_VERSION,
            IE_COMPATIBILITY_NAME_VERSION_MAJOR,

            SYNTAX_ERROR
    };


    size_t PRE_SORTED_FIELDS_LIST_SIZE = sizeof(PRE_SORTED_FIELDS_LIST)/sizeof(const char *);


    AgentField & MutableUserAgent::get(const std::string &fieldName){
        if (fieldName == USERAGENT_FIELDNAME) {
            return *userAgentStringField;
        } else {
            auto it = allFields.find(fieldName);
            MutableAgentField * agentField = nullptr;
            if(it == allFields.end()){
                agentField = new MutableAgentField(getDefaultValueForField(fieldName));
                allFields[fieldName] = agentField;
            } else
                agentField = it->second;
            return *agentField;
        }
    }

    void MutableUserAgent::set(std::shared_ptr<MutableUserAgent>newValuesUserAgent, Matcher * appliedMatcher) { // NOSONAR: Unused parameter
        for (auto it = newValuesUserAgent->allFields.begin(); it != newValuesUserAgent->allFields.end(); it++) {
            const MutableAgentField * field = it->second;
            set(it->first, field->value, field->confidence);
        }
    }

    void MutableUserAgent::reset() {
        _hasSyntaxError = false;
        _hasAmbiguity = false;
        ambiguityCount = 0;

        for(auto it = allFields.begin(); it!= allFields.end(); it++) {
            it->second->reset();
        }
    }

    void MutableUserAgent::processSetAll() {
        auto it = allFields.find(SET_ALL_FIELDS);
        if (it == allFields.end()) {
            return;
        }

        const MutableAgentField * setAllField = it->second;
        std::string value;
        if (setAllField->isDefaultValue()) {
            value = NULL_VALUE;
        } else {
            value = setAllField->getValue();
        }

        long confidence = setAllField->confidence;
        for (auto allit = allFields.begin(); allit != allFields.end(); allit++ ) {
            if (!isSystemField(allit->first)) {
                allit->second->setValue(value, confidence);
            }
        }
    }

    void MutableUserAgent::set(const std::string &attribute, const std::string &value, long confidence) {
        MutableAgentField * field = nullptr;
        auto it = allFields.find(attribute);
        if (it == allFields.end())
            field = new MutableAgentField(getDefaultValueForField(attribute));
        else
            field = it->second;

        bool wasEmpty = confidence == -1;
        bool updated  = field->setValue(value, confidence);
        if (debug && !wasEmpty) {
            if (updated) {
                LOG::info("USE  %s (%ld) = %s", attribute.c_str(), confidence, value.c_str());
            } else {
                LOG::info("SKIP %s (%ld) = %s", attribute.c_str(), confidence, value.c_str());
            }
        }
        allFields[attribute] = field;
    }

    void MutableUserAgent::setForced(const std::string &attribute, const std::string &value, long confidence) {
        MutableAgentField * field = nullptr;
        auto it = allFields.find(attribute);
        if (it == allFields.end()) {
            field = new MutableAgentField(getDefaultValueForField(attribute));
        } else
            field = it->second;

        bool wasEmpty = confidence == -1;
        field->setValueForced(value, confidence);
        if (debug && !wasEmpty) {
            LOG::info("USE  %s (%ld) = %s}", attribute.c_str(), confidence, value.c_str());
        }
        allFields[attribute] = field;
    }

    std::string MutableUserAgent::getValue(const std::string &fieldName) const {
        if (fieldName == USERAGENT_FIELDNAME) {
            return userAgentString;
        }

        auto it = allFields.find(fieldName);
        if(it == allFields.end())
            return getDefaultValueForField(fieldName);
        return it->second->getValue();
    }

    long MutableUserAgent::getConfidence(const std::string &fieldName) const {
        if (fieldName == USERAGENT_FIELDNAME) {
            return 0L;
        }
        auto it = allFields.find(fieldName);
        if(it == allFields.end())
            return -1L;
        return it->second->getConfidence();
    }

    std::list<std::string> MutableUserAgent::getAvailableFieldNamesSorted() const {
        std::list<std::string> fieldNames;
        if (wantedFieldNames.empty()) {
            add_all(fieldNames,STANDARD_FIELDS,sizeof(STANDARD_FIELDS)/sizeof(const char *));
            for(auto it=allFields.begin(); it!=allFields.end(); it++){
                const std::string & fieldName = it->first;
                MutableAgentField * field = it->second;
                if(fieldNames.end() == std::find(fieldNames.begin(),fieldNames.end(), fieldName)){
                    if (!field->isDefaultValue()) {
                        fieldNames.push_back(fieldName);
                    }
                }
            }
        } else {
            for(auto it=allFields.begin(); it!=allFields.end(); it++){
                const std::string & fieldName = it->first;
                MutableAgentField * field = it->second;
                if(fieldNames.end() == std::find(fieldNames.begin(),fieldNames.end(), fieldName)){
                    if (!field->isDefaultValue()) {
                        fieldNames.push_back(fieldName);
                    }
                }
            }
        }

        // This is not a field; this is a special operator.
        fieldNames.remove(SET_ALL_FIELDS);

        std::list<std::string> result;
        for(size_t i=0; i<PRE_SORTED_FIELDS_LIST_SIZE; i++){
            if(fieldNames.end() != std::find(fieldNames.begin(),fieldNames.end(),PRE_SORTED_FIELDS_LIST[i])){
                fieldNames.remove(PRE_SORTED_FIELDS_LIST[i]);
                result.push_back(PRE_SORTED_FIELDS_LIST[i]);
            }
        }

        fieldNames.sort();

        for(const std::string & fn: fieldNames)
            result.push_back(fn);
        return result;
    }

    void MutableUserAgent::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                                       size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
        if (debug) {
            LOG::error("Syntax error");
            LOG::error("Source : %s", userAgentString.c_str());
            LOG::error("Message: %s", msg.c_str());
        }
        _hasSyntaxError = true;
        MutableAgentField * syntaxError = new MutableAgentField("false");
        syntaxError->setValue("true", 1);

        allFields[SYNTAX_ERROR] = syntaxError;
    }

    void MutableUserAgent::reportAmbiguity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex,
                                           size_t stopIndex, bool exact, const antlrcpp::BitSet &ambigAlts,
                                           antlr4::atn::ATNConfigSet *configs) {
        _hasAmbiguity = true;
        ambiguityCount++;
    }

    std::string MutableUserAgent::getDefaultValueForField(const std::string &fieldName) {
        if (fieldName.npos != fieldName.find("NameVersion")) {
            return UNKNOWN_NAME_VERSION;
        }
        if (fieldName.npos != fieldName.find("Version")) {
            return UNKNOWN_VERSION;
        }
        return UNKNOWN_VALUE;
    }

    MutableUserAgent::~MutableUserAgent() {
        for(auto pair : allFields){
            delete pair.second;
        }
        allFields.clear();
    }

    void MutableUserAgent::setUserAgentString(const std::string &newUserAgentString) {
        this->userAgentString = newUserAgentString;
        userAgentStringField = std::make_shared<MutableAgentField>(userAgentString);
        userAgentStringField->setValue(userAgentString, 0L);
        reset();
    }

    void MutableUserAgent::setImmediateForTesting(const std::string &fieldName, const MutableAgentField & agentField) {
        MutableAgentField * field = new MutableAgentField(agentField);
        allFields[fieldName] = field;
    }

    AgentField & ImmutableUserAgent::get(const std::string &fieldName) {
        if (fieldName == USERAGENT_FIELDNAME) {
            return *userAgentStringField;
        }

        auto it = allFields.find(fieldName);
        if(it == allFields.end()){
            auto itdef = defaultValueFields.find(fieldName);
            if(itdef == defaultValueFields.end()) {
                ImmutableAgentField * agentField = new ImmutableAgentField(MutableUserAgent::getDefaultValueForField(fieldName),
                                                     -1,
                                                     true,
                                                     MutableUserAgent::getDefaultValueForField(fieldName));
                defaultValueFields[fieldName] = agentField;
                return *agentField;
            } else
                return *itdef->second;
        }
        return *it->second;
    }

    ImmutableUserAgent::ImmutableUserAgent(MutableUserAgent &userAgent) {
        userAgentString = userAgent.getUserAgentString();
        _hasSyntaxError = userAgent.hasSyntaxError();
        _hasAmbiguity = userAgent.hasAmbiguity();
        ambiguityCount = userAgent.getAmbiguityCount();

        userAgentStringField = std::make_shared<ImmutableAgentField>(userAgentString, 0L, false, userAgentString);

        for (const std::string & fieldName: userAgent.getAvailableFieldNamesSorted()) {
            const AgentField & agentField = userAgent.get(fieldName);
            allFields[fieldName] = new ImmutableAgentField((const MutableAgentField&)agentField);
        }

        availableFieldNamesSorted = userAgent.getAvailableFieldNamesSorted();
    }

    ImmutableUserAgent::~ImmutableUserAgent() {
        for(auto it=allFields.begin(); it!= allFields.end(); it++)
            delete it->second;
        for(auto it=defaultValueFields.begin(); it!= defaultValueFields.end(); it++)
            delete it->second;
    }

    std::string ImmutableUserAgent::getValue(const std::string &fieldName) const {
        if (fieldName == USERAGENT_FIELDNAME) {
            return userAgentString;
        }
        auto it = allFields.find(fieldName);
        if(it == allFields.end()){
            return MutableUserAgent::getDefaultValueForField(fieldName);
        }
        return it->second->getValue();
    }

    long ImmutableUserAgent::getConfidence(const std::string &fieldName) const {
        if (fieldName == USERAGENT_FIELDNAME) {
            return 0L;
        }
        auto it = allFields.find(fieldName);
        if(it == allFields.end())
            return -1L;
        return it->second->getConfidence();
    }

    std::string UserAgent::escapeYaml(const std::string &input) const {
        if (input.empty()) {
            return NULL_VALUE;
        }
        std::string s = input;
        string_replace(s,"'", "''");
        return s;
    }

    std::string UserAgent::toYamlTestCase(bool showConfidence, const std::map<std::string, std::string> &comments) {
        std::ostringstream stream;
        stream << "\n";
        stream << "- test:\n";
        stream << "    input:\n";
        stream << "      user_agent_string: '" << escapeYaml(getUserAgentString()) << "'\n";
        stream << "    expected:\n";

        std::list<std::string> fieldNames = getAvailableFieldNamesSorted();

        size_t maxNameLength  = 30;
        size_t maxValueLength = 0;
        for (const std::string & fieldName : fieldNames) {
            maxNameLength = std::max(maxNameLength, fieldName.size());
        }
        for (const std::string & fieldName : fieldNames) {
            std::string value = escapeYaml(getValue(fieldName));
            if (!value.empty()) {
                maxValueLength = std::max(maxValueLength, value.size());
            }
        }

        for (const std::string & fieldName : fieldNames) {
            const AgentField & field = get(fieldName);
            stream << "      " << fieldName;
            for (size_t l = fieldName.size(); l < maxNameLength + 6; l++) {
                stream << ' ';
            }
            std::string value = escapeYaml(field.getValue());
            stream << ": '" << value << '\'';

            if (showConfidence || !comments.empty()) {
                size_t l = value.size();
                for (; l < maxValueLength + 5; l++) {
                    stream << ' ';
                }
                stream << "# ";
                if (showConfidence) {
                    char buf[100];
                    snprintf(buf,100,"%8ld", getConfidence(fieldName));
                    stream << buf;
                    if (field.isDefaultValue()) {
                        stream << " [Default]";
                    }
                }
                if (!comments.empty()) {
                    auto it = comments.find(fieldName);
                    if(comments.end() != it){
                        if (!field.isDefaultValue()) {
                            stream << "          ";
                        }
                        stream << " | " << it->second;
                    }
                }
            }

            stream << '\n';
        }
        stream << "\n\n";

        return stream.str();
    }

    std::string UserAgent::toJson(const std::list<std::string> &fieldNames) {
        std::ostringstream stream;
        stream << "{";

        bool addSeparator = false;
        for (const std::string & fieldName : fieldNames) {
            if (addSeparator) {
                stream << ',';
            } else {
                addSeparator = true;
            }
            if (fieldName == USERAGENT_FIELDNAME) {
                stream << "\"Useragent\"" << ':' << '"' << escape_json(getUserAgentString()) << '"';
            } else {
                const AgentField & field = get(fieldName);
                stream << '"' << escape_json(fieldName) << '"'
                       << ':' << '"' << escape_json(field.getValue()) << '"';
            }
        }

        stream << "}";
        return stream.str();
    }

    std::string UserAgent::toXML(const std::list<std::string> &fieldNames) {
        std::ostringstream stream;
        stream << "<Yauaa>";

        for (const std::string & fieldName : fieldNames) {
            if (fieldName == USERAGENT_FIELDNAME) {
                stream << "<Useragent>" << escape_xml10(getUserAgentString()) << "</Useragent>";
            } else {
                const AgentField & field = get(fieldName);
                stream << '<' << escape_xml10(fieldName) << '>'
                       << escape_xml10(field.getValue())
                       << "</" << escape_xml10(fieldName) << '>';
            }
        }

        stream << "</Yauaa>";

        return stream.str();
    }

    std::string UserAgent::toString(const std::list<std::string> &fieldNames) {
        std::string uaFieldName = "user_agent_string";
        size_t maxLength = uaFieldName.size();
        for (const std::string & fieldName : fieldNames) {
            maxLength = std::max(maxLength, fieldName.size());
        }
        std::ostringstream stream;
        stream << "  - " << uaFieldName;
        for (size_t l = uaFieldName.size(); l < maxLength + 2; l++) {
            stream << ' ';
        }
        stream << ": '" << escapeYaml(getUserAgentString()) << "'\n";

        for (const std::string & fieldName : fieldNames) {
            if (fieldName != USERAGENT_FIELDNAME) {
                const AgentField & field = get(fieldName);
                stream << "    " << fieldName;
                for (size_t l = fieldName.size(); l < maxLength + 2; l++) {
                    stream << ' ';
                }
                stream << ": '" << escapeYaml(field.getValue()) << '\'';
                stream << '\n';

            }
        }
        return stream.str();
    }

    bool UserAgent::uaEquals(UserAgent *agent) {
        if (this == agent) {
            return true;
        }
        if (getUserAgentString() != agent->getUserAgentString()) {
            return false;
        }
        std::list<std::string> fnSorted1 = getAvailableFieldNamesSorted();
        std::list<std::string> fnSorted2 = agent->getAvailableFieldNamesSorted();
        if (!std::equal(fnSorted1.begin(),fnSorted1.end(),fnSorted2.begin())) {
            return false;
        }
        for (const std::string & fieldName: fnSorted1) {
            if(!get(fieldName).afEquals(agent->get(fieldName))){
                return false;
            }
        }
        return true;
    }

    size_t UserAgent::uaHashCode() {
        static std::hash<std::string> hash_fn;
        size_t result = hash_fn(getUserAgentString());
        for (const std::string & fieldName: getAvailableFieldNamesSorted()) {
            result = 31 * result + get(fieldName).afHashCode();
        }
        return result;
    }
}