//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_DEBUGUSERAGENT_H
#define YAUAACPP_DEBUGUSERAGENT_H

#include <yauaacpp/analyze/Matcher.h>
#include "yauaacpp_def.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    class DebugUserAgent : public MutableUserAgent { // NOSONAR: No need to override equals and hashcode

    private:
        std::list<std::pair<std::shared_ptr<UserAgent>, std::shared_ptr<Matcher>>> appliedMatcherResults;

    public:
        DebugUserAgent(const std::set<std::string> & wantedFieldNames):MutableUserAgent(wantedFieldNames) {
        }

        void set(std::shared_ptr<MutableUserAgent> newValuesUserAgent, std::shared_ptr<Matcher> appliedMatcher);


        void reset();

        size_t getNumberOfAppliedMatches() {
            return appliedMatcherResults.size();
        }

        std::string toMatchTrace(std::list<std::string> highlightNames);

        bool analyzeMatchersResult();


    };

}
#endif //YAUAACPP_DEBUGUSERAGENT_H
