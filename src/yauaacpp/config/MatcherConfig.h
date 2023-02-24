//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MATCHERCONFIG_H
#define YAUAACPP_MATCHERCONFIG_H

#include "yauaacpp_def.h"

namespace ycpp {


    class ConfigLine {
    private:

        std::string attribute;
        long confidence;
        std::string expression;

    public:
        enum Type {
            VARIABLE,
            REQUIRE,
            FAIL_IF_FOUND,
            EXTRACT
        };

    private:
        Type type;

    public:
        // For Kryo ONLY
        ConfigLine() {
            this->type = Type::FAIL_IF_FOUND;
            this->attribute = "<<Should never appear after deserialization>>";
            this->confidence = -42L;
            this->expression = "<<Should never appear after deserialization>>";
        }



        ConfigLine(Type type, const std::string & attribute, long confidence, const std::string & expression) {
            this->type = type;
            this->attribute = attribute;
            this->confidence = confidence;
            this->expression = expression;
        }

        Type getType() {
            return type;
        }
        std::string getTypeStr();

        std::string getAttribute() {
            return attribute;
        }

        long getConfidence() {
            return confidence;
        }

        std::string getExpression() {
            return expression;
        }


        std::string toString() const {
            std::ostringstream o;
            o << "ConfigLine{";
            o << "type=" << type;
            o << ", attribute='" << attribute << '\'';
            o << ", confidence=" << confidence ;
            o << ", expression='" << expression << '\'';
            o << '}';
            return o.str();
        }
    };


    class MatcherConfig {
    private:
        std::list<std::string> options;

        std::string matcherSourceFilename;
        int matcherSourceLineNumber;

        std::list<ConfigLine> configLines;

        // For Kryo ONLY
        MatcherConfig(){
            matcherSourceFilename = "<<Should never appear after deserialization>>";
            matcherSourceLineNumber = -1;
        }

    public:
        MatcherConfig(const std::string & matcherSourceFilename, int matcherSourceLineNumber, const std::list<std::string> & options, std::list<ConfigLine> configLines);

    void add(const ConfigLine & configLine) {
        this->configLines.push_back(configLine);
    }

    std::list<std::string> getOptions() {
        return options;
    }

    std::string getMatcherSourceFilename() {
        return matcherSourceFilename;
    }

    int getMatcherSourceLineNumber() {
        return matcherSourceLineNumber;
    }

    std::list<ConfigLine> getConfigLines() {
        return configLines;
    }


    std::string toString() {
        std::ostringstream o;
        o << "MatcherConfig{";
        o << "options=";
        size_t i=0;
        for(std::string & s : options){
            o << s;
            if(i<options.size()-1)
                o << ",";
        }
        o << ", matcherSourceFilename='" << matcherSourceFilename << '\'';
        o << ", matcherSourceLineNumber=" << matcherSourceLineNumber;
        o << ", configLines=";
        i = 0;
        for(const ConfigLine & cl : configLines){
            o << cl.toString();
            if(i<options.size()-1)
                o << ",";
        }
        o << '}';
        return o.str();
    }
};


}
#endif //YAUAACPP_MATCHERCONFIG_H
