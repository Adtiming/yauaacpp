//
// Created by sunxg on 22-1-29.
//

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


        virtual std::shared_ptr<UserAgent> parsePtr(std::shared_ptr<MutableUserAgent> userAgent) override;

        std::string toString();

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
