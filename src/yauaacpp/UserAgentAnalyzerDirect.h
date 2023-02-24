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
