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

#ifndef BEARKNOCKS_USER_AGENT_ANALYSER_H
#define BEARKNOCKS_USER_AGENT_ANALYSER_H

#include "yauaacpp_def.h"
#include "AbstractUserAgentAnalyzer.h"

namespace ycpp {
    class UserAgentAnalyzerBuilder;

    class UserAgentAnalyzer : public AbstractUserAgentAnalyzer {
    public:
        static std::shared_ptr<UserAgentAnalyzerBuilder> newBuilder();
    };

    class UserAgentAnalyzerBuilder : public AbstractUserAgentAnalyzerBuilder {

    public:
        UserAgentAnalyzerBuilder(std::shared_ptr<AbstractUserAgentAnalyzerDirect> newUaa):AbstractUserAgentAnalyzerBuilder(newUaa) {
        }
    };
}
#endif