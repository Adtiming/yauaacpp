//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_ABSTRACTUSERAGENTANALYZERTESTER_H
#define YAUAACPP_ABSTRACTUSERAGENTANALYZERTESTER_H

#include <yauaacpp/ImmutableUserAgent.h>
#include "yauaacpp_def.h"
#include "AbstractUserAgentAnalyzer.h"
#include "tool/tool.h"
#include "analyze/MatcherList.h"
#include "DebugUserAgent.h"

namespace ycpp {

    struct TestResult {
        std::string field;
        std::string expected;
        std::string actual;
        bool isDefault;
        bool pass;
        bool warn;
        long confidence;
    };

    class ReusableMessageFactory;
    struct Message{
        std::string getFormattedMessage(){
            return formatedMessage;
        }
        std::string formatedMessage;
    };
    class MessageFactory{
    public:
        std::shared_ptr<Message> newMessage(const std::string & format, va_list & args){
            std::shared_ptr<Message> msg = std::make_shared<Message>();
            int nLength = vprintf(format.c_str(), args);
            nLength += 1;  //上面返回的长度是包含\0，这里加上
            std::vector<char> vectorChars(nLength);
            vsnprintf(vectorChars.data(), nLength, format.c_str(), args);
            msg->formatedMessage.assign(vectorChars.data());
            return msg;
        }
    };

    class ReusableMessageFactory:public MessageFactory{

    };


    struct MatcherImpact {
        std::string name;
        long neededInputs;
        long tests;
        long touched;
        long enoughInputs;
        long used;


        std::string toString() const;
    };

    class AbstractUserAgentAnalyzerTester : public AbstractUserAgentAnalyzer {

    /**
     * This is used to configure the provided Kryo instance if Kryo serialization is desired.
     * The expected type here is Object because otherwise the Kryo library becomes
     * a mandatory dependency on any project that uses Yauaa.
     * @param kryoInstance The instance of com.esotericsoftware.kryo.Kryo that needs to be configured.
     */
    /*
        public static void configureKryo(Object kryoInstance) {
            Kryo kryo = (Kryo) kryoInstance;
            kryo.register(AbstractUserAgentAnalyzerTester.class);
            AbstractUserAgentAnalyzer.configureKryo(kryo);
        }

        public static class KryoSerializer : public AbstractUserAgentAnalyzerDirect::KryoSerializer {
            public KryoSerializer(Kryo kryo, Class<?> type) {
                super(kryo, type);
            }
        };
    */

    private:
//        std::recursive_mutex lock;

        static ReusableMessageFactory MESSAGE_FACTORY;

        static std::string determineLogMessage(const std::string & format, ...);

        static void logInfo(std::stringstream & errorMessageReceiver, const std::string & format, ...);

        static void logWarn(std::stringstream & errorMessageReceiver, const std::string & format, ...);

        static void logError(std::stringstream & errorMessageReceiver, const std::string & format, ...);

    public:
        /**
         * Run all the test_cases available.
         *
         * @return true if all tests were successful.
         */
        bool runTests() {
            return runTests(false, true);
        }

        bool runTests(bool showAll, bool failOnUnexpected);

        bool runTests(bool showAll,
                                bool failOnUnexpected,
                                std::list<std::string> & onlyValidateFieldNames,
                                bool measureSpeed,
                                bool showPassedTests);

        static bool runTests(
                AbstractUserAgentAnalyzerDirect & analyzer,
                bool showAll,
                bool failOnUnexpected,
                std::list<std::string> & onlyValidateFieldNames,
                bool measureSpeed,
                bool showPassedTests,
                std::stringstream & errorMessageReceiver);

        // ===============================================================================================================

        /**
         * This function is used only for analyzing which patterns that could possibly be relevant
         * were actually relevant for the matcher actions.
         * @return The list of Matches that were possibly relevant.
         */
        std::list<Match> getMatches();

        std::list<Match> getUsedMatches(std::shared_ptr<MutableUserAgent> userAgent);



        void analyzeMatcherImpactAllTests();

        std::string toString() {
            return "UserAgentAnalyzerTester{" + AbstractUserAgentAnalyzer::toString() + "} ";
        }
    };

    class AbstractUserAgentAnalyzerTesterBuilder : public AbstractUserAgentAnalyzerBuilder {
    public:
        AbstractUserAgentAnalyzerTesterBuilder(std::shared_ptr<AbstractUserAgentAnalyzerDirect> newUaa):AbstractUserAgentAnalyzerBuilder(newUaa) {

        }


        std::shared_ptr<AbstractUserAgentAnalyzerDirect> build();
    };

}
#endif //YAUAACPP_ABSTRACTUSERAGENTANALYZERTESTER_H
