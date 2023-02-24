//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_USERAGENTANALYZERTESTER_H
#define YAUAACPP_USERAGENTANALYZERTESTER_H

#include "yauaacpp_def.h"
#include "AbstractUserAgentAnalyzerTester.h"

namespace ycpp {
    class UserAgentAnalyzerTesterBuilder;

    class UserAgentAnalyzerTester : public AbstractUserAgentAnalyzerTester {
    public:
        static AbstractUserAgentAnalyzerDirectBuilder & newBuilder();

        /**
         * This is used to configure the provided Kryo instance if Kryo serialization is desired.
         * The expected type here is Object because otherwise the Kryo library becomes
         * a mandatory dependency on any project that uses Yauaa.
         * @param kryoInstance The instance of com.esotericsoftware.kryo.Kryo that needs to be configured.
         */
/*
        public static void configureKryo(Object kryoInstance) {
            Kryo kryo = (Kryo) kryoInstance;
            kryo.register(UserAgentAnalyzerTester.class);
            AbstractUserAgentAnalyzerTester.configureKryo(kryo);
        }
*/
    };

    class UserAgentAnalyzerTesterBuilder : public AbstractUserAgentAnalyzerTesterBuilder {
    public:
        UserAgentAnalyzerTesterBuilder(std::shared_ptr<AbstractUserAgentAnalyzerDirect> newUaa):AbstractUserAgentAnalyzerTesterBuilder(newUaa) {
        }
    };

}
#endif //YAUAACPP_USERAGENTANALYZERTESTER_H
