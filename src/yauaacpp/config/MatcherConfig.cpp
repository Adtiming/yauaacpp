//
// Created by sunxg on 22-1-30.
//

#include "MatcherConfig.h"

namespace ycpp {
    MatcherConfig::MatcherConfig(const std::string &matcherSourceFilename, int matcherSourceLineNumber,
                                 const std::list<std::string> &options, std::list<ConfigLine> configLines) {
        this->matcherSourceFilename = matcherSourceFilename;
        this->matcherSourceLineNumber = matcherSourceLineNumber;
        //        this->matcherSourceLocation = matcherSourceLocation;
        this->options = options;
        this->configLines.insert(this->configLines.end(),configLines.begin(),configLines.end());
    }

    std::string ConfigLine::getTypeStr() {
        switch(type){
            case VARIABLE:
                return "VARIABLE";
            case REQUIRE:
                return "REQUIRE";
            case FAIL_IF_FOUND:
                return "FAIL_IF_FOUND";
            case EXTRACT:
                return "EXTRACT";
        }
        return "";
    }
}