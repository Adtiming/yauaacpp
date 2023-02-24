//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_TESTCASE_H
#define YAUAACPP_TESTCASE_H

#include <analyze/Analyzer.h>
#include "yauaacpp_def.h"
#include "analyze/Analyzer.h"

namespace ycpp {
    class Analyzer;

    class TestCase {
    private:
        std::string userAgent;
        std::string testName;
        std::list<std::string> options;
        std::map<std::string, std::string> metadata;
        std::map<std::string, std::string> expected;


    public:
        // For Kryo ONLY
        TestCase() {
            this->userAgent = "<<Should never appear after deserialization>>";
            this->testName = "<<Should never appear after deserialization>>";
        }
        TestCase(const std::string & userAgent, const std::string & testName) {
            this->userAgent = userAgent;
            this->testName = testName;
        }

        std::string getUserAgent() {
            return userAgent;
        }

        std::string getTestName() {
            return testName;
        }

        std::list<std::string> getOptions() {
            return options;
        }

        void addOption(const std::string & option) {
            this->options.push_back(option);
        }

        std::map<std::string, std::string> getMetadata() {
            return metadata;
        }

        void addMetadata(const std::string & key, const std::string & value) {
            this->metadata[key] = value;
        }

        std::map<std::string, std::string> getExpected() {
            return expected;
        }

        void expect(const std::string & key, const std::string & value) {
            this->expected[key] = value;
        }

        bool verify(Analyzer * analyzer);


        std::string toString();
    };
}
#endif //YAUAACPP_TESTCASE_H
