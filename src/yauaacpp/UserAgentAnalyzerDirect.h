//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_USERAGENTANALYZERDIRECT_H
#define YAUAACPP_USERAGENTANALYZERDIRECT_H

#include "yauaacpp_def.h"
#include "AbstractUserAgentAnalyzerDirect.h"

namespace ycpp {
    class UserAgentAnalyzerDirect;

    class UserAgentAnalyzerDirectBuilder : public AbstractUserAgentAnalyzerDirectBuilder {
    public:
        UserAgentAnalyzerDirectBuilder(std::shared_ptr<AbstractUserAgentAnalyzerDirect> newUaa):AbstractUserAgentAnalyzerDirectBuilder(newUaa) {
        }
    };

    class UserAgentAnalyzerDirect : public AbstractUserAgentAnalyzerDirect {
    private:
        std::shared_ptr<UserAgentAnalyzerDirectBuilder> builder;
    public:
        UserAgentAnalyzerDirectBuilder & newBuilder() {
            builder.reset(new UserAgentAnalyzerDirectBuilder(std::make_shared<UserAgentAnalyzerDirect>()));
            return *builder;
        }

//
//        /**
//         * This is used to configure the provided Kryo instance if Kryo serialization is desired.
//         * The expected type here is Object because otherwise the Kryo library becomes
//         * a mandatory dependency on any project that uses Yauaa.
//         * @param kryoInstance The instance of com.esotericsoftware.kryo.Kryo that needs to be configured.
//         */
//        static void configureKryo(Object kryoInstance) {
//            Kryo kryo = (Kryo) kryoInstance;
//            kryo.register(UserAgentAnalyzerDirect.class);
//            AbstractUserAgentAnalyzer.configureKryo(kryo);
//        }

    };

}
#endif //YAUAACPP_USERAGENTANALYZERDIRECT_H
