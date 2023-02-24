//
// Created by sunxg on 22-2-3.
//

#include <tool/tool.h>
#include "TestCase.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    bool TestCase::verify(Analyzer *analyzer) {
        UserAgent * result = analyzer->parse(userAgent).get();

        std::set<std::string> combinedKeys;
        for(auto pair : expected) combinedKeys.insert(pair.first);
        for(auto pair : result->toMap()) combinedKeys.insert(pair.first);
        combinedKeys.erase(USERAGENT_FIELDNAME); // Remove the input "field" from the result set.
        combinedKeys.erase(SYNTAX_ERROR);

        for (const std::string & key : combinedKeys) {

            auto it = expected.find(key);
            if (it == expected.end()) {
                // If we do not expect anything it is ok to get a Default value.
                if (!result->get(key).isDefaultValue()) {
                    return false;
                }
            } else {
                std::string expectedValue = it->second;
                std::string actualValue = result->getValue(key);
                if (expectedValue != actualValue) {
                    return false;
                }
            }
        }
        return true;
    }

    std::string TestCase::toString() {
        std::ostringstream o;

        o << "TestCase{" <<
               "userAgent='" << userAgent << '\'' <<
               ", testName='" << testName << '\'' <<
               ", options=" << to_string(options.begin(),options.end()) <<
               ", metadata=" << to_pair_string(metadata.begin(),metadata.end()) <<
               ", expected=" << to_pair_string(expected.begin(),expected.end()) <<
               '}';
        return o.str();
    }
}
