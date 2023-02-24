//
// Created by sunxg on 22-3-5.
//

#include "UserAgentAnalyzerTester.h"

namespace ycpp{

    AbstractUserAgentAnalyzerDirectBuilder &UserAgentAnalyzerTester::newBuilder() {
        std::shared_ptr<AbstractUserAgentAnalyzerDirect> newUaa = std::shared_ptr<AbstractUserAgentAnalyzerDirect>(new UserAgentAnalyzerTester());
        UserAgentAnalyzerTesterBuilder * p = new UserAgentAnalyzerTesterBuilder(newUaa);
        return p->keepTests();
    }
}