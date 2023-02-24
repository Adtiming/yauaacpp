//
// Created by sunxg on 22-2-14.
//


#include "UserAgentAnalyzer.h"
#include "tool/dir.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp{

    std::shared_ptr<UserAgentAnalyzerBuilder> UserAgentAnalyzer::newBuilder() {
        return std::shared_ptr<UserAgentAnalyzerBuilder>(new UserAgentAnalyzerBuilder(std::make_shared<UserAgentAnalyzer>()));
    }
}