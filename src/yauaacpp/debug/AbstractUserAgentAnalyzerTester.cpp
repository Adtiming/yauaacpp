//
// Created by sunxg on 22-3-5.
//
#include "AbstractUserAgentAnalyzerTester.h"
#include "parse/UserAgentTreeFlattener.h"
#include "config/TestCase.h"
#include <bits/stdc++.h>

namespace ycpp{

    ReusableMessageFactory AbstractUserAgentAnalyzerTester::MESSAGE_FACTORY;

    std::string ycpp::AbstractUserAgentAnalyzerTester::determineLogMessage(const std::string &format, ...) {
        va_list args;
        va_start(args, format);
        std::string s = MESSAGE_FACTORY.newMessage(format, args)->getFormattedMessage();
        va_end(args);
        return s;
    }

    void
    ycpp::AbstractUserAgentAnalyzerTester::logInfo(std::stringstream &errorMessageReceiver, const std::string &format,
                                                   ...) {
        if (LOG::isInfoEnabled()) {
            va_list args;
            va_start(args, format);
            std::string message = determineLogMessage(format, args);
            va_end(args);
            LOG::error( message.c_str() );
            if (nullptr != &errorMessageReceiver) {
                errorMessageReceiver << message.c_str() << '\n';
            }
        }
    }

    void
    ycpp::AbstractUserAgentAnalyzerTester::logWarn(std::stringstream &errorMessageReceiver, const std::string &format,
                                                   ...) {
        if (LOG::isWarnEnabled()) {
            va_list args;
            va_start(args, format);
            std::string message = determineLogMessage(format, args);
            va_end(args);
            LOG::warn(message.c_str());
            if (nullptr != &errorMessageReceiver) {
                errorMessageReceiver << message.c_str() << '\n';
            }
        }
    }

    void
    ycpp::AbstractUserAgentAnalyzerTester::logError(std::stringstream &errorMessageReceiver, const std::string &format,
                                                    ...) {
        if (LOG::isErrorEnabled()) {
            va_list args;
            va_start(args, format);
            std::string message = determineLogMessage(format, args);
            LOG::error(message.c_str());
            va_end(args);
            if (nullptr != &errorMessageReceiver) {
                errorMessageReceiver << message.c_str() << '\n';
            }
        }
    }

    bool AbstractUserAgentAnalyzerTester::runTests(AbstractUserAgentAnalyzerDirect & analyzer, bool showAll,
                                                   bool failOnUnexpected, std::list<std::string> & _onlyValidateFieldNames,
                                                   bool measureSpeed, bool showPassedTests,
                                                   std::stringstream &errorMessageReceiver) {
        std::list<std::string> onlyValidateFieldNames = _onlyValidateFieldNames;
        analyzer.initializeMatchers();
        if (analyzer.getTestCases().empty()) {
            return true;
        }
        std::shared_ptr<MutableUserAgent> agent(new DebugUserAgent(analyzer.getWantedFieldNames()));

        std::list<TestResult> results;

        std::string filenameHeader = "Test number and source";
        size_t filenameHeaderLength = filenameHeader.length();
        size_t maxFilenameLength = filenameHeaderLength;
        for (std::shared_ptr<TestCase> test : analyzer.getTestCases()) {
            std::map<std::string, std::string> metaData = test->getMetadata();
            std::string filename = metaData["filename"];
            maxFilenameLength = std::max(maxFilenameLength, filename.length());
        }

        maxFilenameLength+=11;

        std::stringstream o;

        o << "| " << filenameHeader;
        for (int i = filenameHeaderLength; i < maxFilenameLength; i++) {
            o << ' ';
        }

        o << " |S|AA|MF|";
        if (measureSpeed) {
            o << "  PPS| msPP|";
        }
        o << "--> S=Syntax Error, AA=Number of ambiguities during parse, MF=Matches Found";
        if (measureSpeed) {
            o << ", PPS=parses/sec, msPP=milliseconds per parse";
        }

        long fullStart = get_cur_msec();

        if (showPassedTests) {
            LOG::error( "+===========================================================================================");
            LOG::error( "%s", o.str());
            LOG::error( "+-------------------------------------------------------------------------------------------");
        }

        bool allPass = true;
        int testcount = 0;
        for (std::shared_ptr<TestCase> test : analyzer.getTestCases()) {
            testcount++;
            std::string testName = test->getTestName();
            std::string userAgentString = test->getUserAgent();
            std::map<std::string, std::string> expected = test->getExpected();

            std::list<std::string> options = test->getOptions();
            std::map<std::string, std::string> metaData = test->getMetadata();
            std::string filename = metaData["filename"];
            std::string linenumber = metaData["fileline"];

            bool init = false;

            if (options.empty()) {
                analyzer.setVerbose(false);
                agent->setDebug(false);
            } else {
                bool newVerbose = options.end() != std::find(options.begin(),options.end(),"verbose");
                analyzer.setVerbose(newVerbose);
                agent->setDebug(newVerbose);
                init = options.end() != std::find(options.begin(),options.end(),"init");
            }
            if (expected.size() == 0) {
                init = true;
            }

            if (testName.empty()) {
                if (userAgentString.length() > 200) {
                    testName = userAgentString.substr(0, 190) + " ... ( " + uitos(userAgentString.length()) + " chars)";
                } else {
                    testName = userAgentString;
                }
            }

            o.clear();

            o << "|" << string_format("%5d", testcount)
                << ".(" << filename << ':' << linenumber << ')';
            for (size_t i = filename.length()+linenumber.length()+7; i < maxFilenameLength; i++) {
                o << ' ';
            }

            agent->setUserAgentString(userAgentString);


            std::shared_ptr<UserAgent> parseResult;
            long      measuredSpeed=-1;
            if (measureSpeed) {
                // Preheat
                for (int i = 0; i < 100; i++) {
                    analyzer.parsePtr(agent);
                }
                long startTime = get_cur_msec();
                for (int i = 0; i < 1000; i++) {
                    parseResult = analyzer.parsePtr(agent);
                }
                long stopTime = get_cur_msec();
                measuredSpeed = (1000L * (1000)) / (stopTime - startTime);
            } else {
                parseResult = analyzer.parsePtr(agent);
            }

            o << '|';
            if (parseResult->hasSyntaxError()) {
                o << 'S';
            } else {
                o << ' ';
            }
            if (parseResult->hasAmbiguity()) {
                o << string_format("|%2d", parseResult->getAmbiguityCount()).c_str();
            } else {
                o << "|  ";
            }

            o << string_format("|%2d", ((DebugUserAgent*)agent.get())->getNumberOfAppliedMatches()).c_str();

            if (measureSpeed) {
                o << '|' << string_format("%5d", measuredSpeed).c_str();
                o << '|' << string_format("%5.2f", 1000.0/measuredSpeed).c_str();
            }

            o << "| " << testName;

            // We create the log line but we keep it until we know it actually must be output to the screen
            std::string testLogLine = o.str();

            o.clear();

            bool pass = true;
            results.clear();

            if (init) {
                LOG::error( testLogLine.c_str());
                o << agent->toYamlTestCase().c_str();
                LOG::error( "%s", o.str().c_str());
            }

            size_t maxNameLength     = 6; // "Field".length()+1;            NOSONAR: This is not commented code.
            size_t maxActualLength   = 7; // "Actual".length()+1;           NOSONAR: This is not commented code.
            size_t maxExpectedLength = 9; // "Expected".length()+1;         NOSONAR: This is not commented code.

            if (!expected.empty()) {
                std::list<std::string> fieldNames(parseResult->getAvailableFieldNamesSorted());

                if (!onlyValidateFieldNames.empty() && onlyValidateFieldNames.empty()) {
                    onlyValidateFieldNames.clear();
                } else if (!onlyValidateFieldNames.empty()) {
                    fieldNames.clear();
                    for(const std::string & s:onlyValidateFieldNames)
                        fieldNames.push_back(s);
                }

                for (auto pair : expected) {
                    const std::string & newFieldName = pair.first;
                    if (fieldNames.end() == std::find(fieldNames.begin(),fieldNames.end(),newFieldName)) {
                        fieldNames.push_back(newFieldName);
                    }
                }

                for (const std::string & fieldName : fieldNames) {
                    // Only check the desired fieldnames
                    if (onlyValidateFieldNames.end() == std::find(onlyValidateFieldNames.begin(),onlyValidateFieldNames.end(),fieldName))
                        continue;

                    TestResult result;
                    result.field = fieldName;
                    bool expectedSomething;

                    // Actual value
                    result.actual = parseResult->getValue(result.field);
                    result.isDefault = parseResult->get(result.field).isDefaultValue();

                    result.confidence = parseResult->getConfidence(result.field);
                    if (result.actual.empty()) {
                        result.actual = NULL_VALUE;
                    }

                    // Expected value
                    std::string expectedValue = expected[fieldName];
                    if (expectedValue.empty()) {
                        expectedSomething = false;
                        if (result.isDefault) {
                            continue;
                        }
                        result.expected = "<<absent>>";
                    } else {
                        expectedSomething = true;
                        result.expected = expectedValue;
                    }

                    result.pass = (result.actual == result.expected);
                    if (!result.pass) {
                        result.warn=true;
                        if (expectedSomething) {
                            result.warn=false;
                            pass = false;
                            allPass = false;
                        } else {
                            if (failOnUnexpected) {
                                // We ignore this special field
                                if (result.field != SYNTAX_ERROR) {
                                    result.warn = false;
                                    pass = false;
                                    allPass = false;
                                }
                            }
                        }
                    }

                    results.push_back(result);

                    maxNameLength = std::max(maxNameLength, result.field.length());
                    maxActualLength = std::max(maxActualLength, result.actual.length());
                    maxExpectedLength = std::max(maxExpectedLength, result.expected.length());
                }

                if (!((DebugUserAgent *)agent.get())->analyzeMatchersResult()) {
                    pass = false;
                    allPass = false;
                }
            }

            if (!init && pass && !showAll) {
                if (showPassedTests) {
                    logInfo(errorMessageReceiver, testLogLine);
                }
                continue;
            }

            if (!pass) {
                logInfo(errorMessageReceiver, testLogLine);
                logError(errorMessageReceiver, "| TEST FAILED !");
            }

            if (parseResult->hasAmbiguity()) {
                logInfo(errorMessageReceiver, "| Parsing problem: Ambiguity %d times. ", parseResult->getAmbiguityCount());
            }
            if (parseResult->hasSyntaxError()) {
                logInfo(errorMessageReceiver, "| Parsing problem: Syntax Error");
            }

            if (init || !pass) {
                o.clear();
                o << '\n';
                o << '\n';
                o << "- matcher:\n";
                o << "#    options:\n";
                o << "#    - 'verbose'\n";
                o << "    require:\n";
                for (const std::string & path : getAllPaths(userAgentString)) {
                    if (contains(path,"=\"")) {
                        o << "#    - '" << path << "'\n";
                    }
                }
                o << "    extract:\n";
                o << "#    - 'DeviceClass                         :      1 :' \n";
                o << "#    - 'DeviceBrand                         :      1 :' \n";
                o << "#    - 'DeviceName                          :      1 :' \n";
                o << "#    - 'OperatingSystemClass                :      1 :' \n";
                o << "#    - 'OperatingSystemName                 :      1 :' \n";
                o << "#    - 'OperatingSystemVersion              :      1 :' \n";
                o << "#    - 'LayoutEngineClass                   :      1 :' \n";
                o << "#    - 'LayoutEngineName                    :      1 :' \n";
                o << "#    - 'LayoutEngineVersion                 :      1 :' \n";
                o << "#    - 'AgentClass                          :      1 :' \n";
                o << "#    - 'AgentName                           :      1 :' \n";
                o << "#    - 'AgentVersion                        :      1 :' \n";
                o << '\n';
                o << '\n';
                LOG::error( "%s", o.str().c_str());
            }

            o.clear();
            o << "+--------+-";
            for (int i = 0; i < maxNameLength; i++) {
                o << '-';
            }
            o << "-+-";
            for (int i = 0; i < maxActualLength; i++) {
                o << '-';
            }
            o << "-+---------+------------+-";
            for (int i = 0; i < maxExpectedLength; i++) {
                o << '-';
            }
            o << "-+";

            std::string separator = o.str();
            logInfo(errorMessageReceiver, separator);

            o.clear();
            o << "| Result | Field ";
            for (int i = 6; i < maxNameLength; i++) {
                o << ' ';
            }
            o << " | Actual ";
            for (int i = 7; i < maxActualLength; i++) {
                o << ' ';
            }
            o << " | Default | Confidence | Expected ";
            for (int i = 9; i < maxExpectedLength; i++) {
                o << ' ';
            }
            o << " |";

            logInfo(errorMessageReceiver, o.str());

            logInfo(errorMessageReceiver, separator);

            std::map<std::string, std::string> failComments;

            std::list<std::string> failedFieldNames ;
            for (TestResult result : results) {
                o.clear();
                if (result.pass) {
                    o << "|        | ";
                } else {
                    if (result.warn) {
                        o << "| ~warn~ | ";
                        failComments[result.field] = "~~ Unexpected result ~~";
                    } else {
                        o << "| -FAIL- | ";
                        failComments[result.field] = std::string("FAILED; Should be '") + result.expected + "'";
                        failedFieldNames.push_back(result.field);
                    }
                }
                o << result.field.c_str();
                for (int i = result.field.length(); i < maxNameLength; i++) {
                    o << ' ';
                }
                o << " | ";
                o << result.actual.c_str();

                for (int i = result.actual.length(); i < maxActualLength; i++) {
                    o << ' ';
                }

                if (result.isDefault) {
                    o << " | Default | ";
                } else {
                    o << " |         | ";
                }
                o << string_format("%10d", result.confidence).c_str();
                o << " | ";

                if (result.pass) {
                    for (int i = 0; i < maxExpectedLength; i++) {
                        o << ' ';
                    }
                    o << " |";
                    logInfo(errorMessageReceiver, o.str());
                } else {
                    o << result.expected.c_str();
                    for (int i = result.expected.length(); i < maxExpectedLength; i++) {
                        o << ' ';
                    }
                    o << " |";
                    if (result.warn) {
                        logWarn(errorMessageReceiver, o.str());
                    } else {
                        logError(errorMessageReceiver, o.str());
                    }
                }
            }

            logInfo(errorMessageReceiver, separator);
            logInfo(errorMessageReceiver, "");

            logInfo(errorMessageReceiver, ((DebugUserAgent*)agent.get())->toMatchTrace(failedFieldNames));

            logInfo(errorMessageReceiver, "\n\nconfig:\n%s", parseResult->toYamlTestCase(!init, failComments));
            logInfo(errorMessageReceiver, "Location of failed test.(%s:%s)", filename, linenumber);
            if (!pass && !showAll) {
                return false;
            }
            if (init) {
                return allPass;
            }
        }

        if (showPassedTests) {
            LOG::error( "+===========================================================================================");
        } else {
            LOG::error( "All %d tests passed", testcount);
        }

        long fullStop = get_cur_msec();

        LOG::error( "This took %8.3f ms for %5d tests : averaging to %6.3f msec/test (This includes test validation and logging!!)",
                    (fullStop - fullStart),
                    testcount,
                    ((double)(fullStop - fullStart)) / testcount);

        if (testcount == 0) {
            LOG::error("NO tests were run at all!!!");
            allPass = false;
        }

        return allPass;
    }

    bool AbstractUserAgentAnalyzerTester::runTests(bool showAll, bool failOnUnexpected) {
        std::list<std::string> fieldNames;
        return runTests(showAll, failOnUnexpected, fieldNames, false, false);
    }

    bool AbstractUserAgentAnalyzerTester::runTests(bool showAll, bool failOnUnexpected,
                                                   std::list<std::string> &onlyValidateFieldNames, bool measureSpeed,
                                                   bool showPassedTests) {
        std::stringstream null;
        return runTests(*this, showAll, failOnUnexpected, onlyValidateFieldNames, measureSpeed, showPassedTests, null);
    }

    std::list<Match> AbstractUserAgentAnalyzerTester::getMatches() {
        std::list<Match> allMatches;
        for (Matcher * matcher: getAllMatchers()) {
            for(auto & match:matcher->getMatches())
                allMatches.push_back(match);
        }
        return allMatches;
    }

    std::list<Match> AbstractUserAgentAnalyzerTester::getUsedMatches(std::shared_ptr<MutableUserAgent> userAgent) {
        lock.lock();
        // Reset all Matchers
        for (Matcher * matcher : getAllMatchers()) {
            matcher->reset();
            matcher->setVerboseTemporarily(false);
        }

        flattener->parse(userAgent);

        std::list<Match> allMatches(128);
        for (Matcher * matcher: getAllMatchers()) {
            for(auto & match : matcher->getUsedMatches())
                allMatches.push_back(match);
        }
        lock.unlock();
        return allMatches;
    }

    void AbstractUserAgentAnalyzerTester::analyzeMatcherImpactAllTests() {
        if (getTestCases().empty()) {
            return;
        }
        initializeMatchers();
        std::shared_ptr<MutableUserAgent> agent(new DebugUserAgent(getWantedFieldNames()));
        setVerbose(false);
        agent->setDebug(false);

        std::map<std::string, MatcherImpact> impactOverview;
        std::list<MatcherImpact> impactList;

        std::vector<Matcher *> matchers = getAllMatchers();
        std::sort(matchers.begin(), matchers.end(), [](Matcher *m1, Matcher *m2) -> bool {
            if (m1->getSourceFileName() > m2->getSourceFileName())
                return true;
            else if (m1->getSourceFileName() < m2->getSourceFileName())
                return false;
            return m1->getSourceFileLineNumber() > m2->getSourceFileLineNumber();
        });

        for (Matcher *matcher:matchers) {
            MatcherImpact matcherImpact;
            matcherImpact.neededInputs = matcher->getActionsThatRequireInput();
            matcherImpact.name = matcher->getMatcherSourceLocation();
            impactOverview[matcher->getMatcherSourceLocation()] = matcherImpact;
            impactList.push_back(matcherImpact);
        }

        for (std::shared_ptr<TestCase> test : getTestCases()) {
            std::string userAgentString = test->getUserAgent();

            agent->setUserAgentString(userAgentString);

            parsePtr(agent);

            for (auto pair:impactOverview) {
                pair.second.tests++;
            }

            MatcherList *touchedMatcherList = getTouchedMatchers();
            for (Matcher *m: *touchedMatcherList) {
                MatcherImpact &impact = impactOverview[m->getMatcherSourceLocation()];
                impact.touched++;
                if (m->getActionsThatRequireInput() == m->getActionsThatRequireInputAndReceivedInput()) {
                    impact.enoughInputs++;
                    if (!m->getUsedMatches().empty()) {
                        impact.used++;
                    }
                }
            }
        }

        for (auto i : impactList) LOG::error("%s", i);
    }

    std::string MatcherImpact::toString() const {
        std::ostringstream o;
        return string_format(
                "%-45s --> touched= %5d (%3.0f%%), neededInputs = %2d, enoughInputs = %5d (%3.0f%%), used = %5d (%3.0f%%) %s%s%s",
                "Rule.(" + name + ")",
                touched,      100.0 * ((double)touched/tests),
                neededInputs,
                enoughInputs, touched      == 0 ? 0.0 : 100.0 * ((double)enoughInputs/touched),
                used,         enoughInputs == 0 ? 0.0 : 100.0 * ((double) used /enoughInputs),
                touched      ==  0              ? "~~~"               : "",
                enoughInputs >   0 && used == 0 ? "<-- NEVER USED "   : "",
                enoughInputs > 100 && used == 0 ? ">> SEVERE CASE <<" : "");
    }

    std::shared_ptr<AbstractUserAgentAnalyzerDirect> AbstractUserAgentAnalyzerTesterBuilder::build() {
        std::shared_ptr<AbstractUserAgentAnalyzerDirect> analyzer = AbstractUserAgentAnalyzerBuilder::build();
        verifyCalculatorDependencyOrdering();
        return analyzer;
    }
}