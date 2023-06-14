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



#ifndef YAUAACPP_ABSTRACTUSERAGENTANALYZER_H
#define YAUAACPP_ABSTRACTUSERAGENTANALYZER_H


#include "yauaacpp_def.h"
#include "AbstractUserAgentAnalyzerDirect.h"

namespace ycpp {
    template<class K, class V> struct lrumap;

    class AbstractUserAgentAnalyzer : public AbstractUserAgentAnalyzerDirect {
    private:
        lrumap<std::string, std::shared_ptr<UserAgent>> * parseCache;
//        std::recursive_mutex lock;
        size_t cacheSize;

        void initializeCache();
    protected:
        AbstractUserAgentAnalyzer() {
            cacheSize = DEFAULT_PARSE_CACHE_SIZE;
            initializeCache();
        }
    public:
        enum{DEFAULT_PARSE_CACHE_SIZE = 10000};

        ~AbstractUserAgentAnalyzer();

        void destroy();

        void disableCaching();

        /**
         * Sets the new size of the parsing cache.
         * Note that this will also wipe the existing cache.
         *
         * @param newCacheSize The size of the new LRU cache. As size of 0 will disable caching.
         */
        void setCacheSize(size_t newCacheSize);

        void clearCache();



        size_t getCacheSize() {
            return cacheSize;
        }

        std::shared_ptr<CacheCopy> copyCache() override ;

        bool saveCache(const std::string & fileName,std::shared_ptr<CacheCopy> & cacheCopy) const override ;

        bool loadCache(const std::string & fileName) override ;

        std::shared_ptr<UserAgent> parsePtr(std::shared_ptr<MutableUserAgent> userAgent) override;

        std::string toString() override;

    };

    class AbstractUserAgentAnalyzerBuilder
        : public AbstractUserAgentAnalyzerDirectBuilder {
    public:
        AbstractUserAgentAnalyzerBuilder(std::shared_ptr<AbstractUserAgentAnalyzerDirect> newUaa): AbstractUserAgentAnalyzerDirectBuilder(newUaa) {
        }

        /**
         * Specify a new cache size (0 = disable caching).
         * @param newCacheSize The new cache size value
         * @return the current Builder instance.
         */
        B & withCache(int newCacheSize);

        /**
         * Disable caching.
         * @return the current Builder instance.
         */
        B & withoutCache();


        std::shared_ptr<AbstractUserAgentAnalyzerDirect> build();
    };

}
#endif //YAUAACPP_ABSTRACTUSERAGENTANALYZER_H
