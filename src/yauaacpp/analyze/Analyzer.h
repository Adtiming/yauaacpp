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



#ifndef BEARKNOCKS_ANALYSER_H
#define BEARKNOCKS_ANALYSER_H

#include<map>

#include "../yauaacpp_def.h"
#include "../linked_hash.h"
#include "../Range.h"

namespace ycpp {

    class UserAgent;
    class MatcherAction;
    class Matcher;
    class TestCase;

    class Analyzer {
    public:
        Analyzer() = default;

        virtual ~Analyzer(){}
        /**
         * Parses and analyzes the provided useragent string
         * @param userAgentString The User-Agent std::string that is to be parsed and analyzed
         * @return An ImmutableUserAgent record that holds all of the results.
         */
        virtual std::shared_ptr<UserAgent> parse(const std::string &userAgentString){
            return nullptr;
        };

        virtual void inform(const std::string & path, const std::string & value, antlr4::tree::ParseTree * ctx)= 0;

        virtual void informMeAbout(MatcherAction * matcherAction, const std::string & keyPattern) = 0;

        virtual void lookingForRange(const std::string & treeName, const Range & range) = 0;

        virtual const linked_hash_set<Range> & getRequiredInformRanges(const std::string & treeName) = 0;

        virtual void informMeAboutPrefix(MatcherAction * matcherAction, const std::string & treeName, const std::string & prefix) = 0;

        virtual linked_hash_set<size_t> * getRequiredPrefixLengths(const std::string & treeName) = 0;

        virtual void receivedInput(Matcher * matcher) {
            // Nothing to do
        }

        virtual std::shared_ptr<MAPMAPS> getLookups() = 0;

        virtual std::shared_ptr<MAPSETS> getLookupSets() = 0;

        virtual std::list<std::shared_ptr<TestCase> > getTestCases() = 0;
    };
}

#endif