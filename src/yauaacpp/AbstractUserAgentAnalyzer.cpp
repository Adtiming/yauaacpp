//
// Created by sunxg on 22-2-23.
//

#include <tool/lrumap.h>
#include "AbstractUserAgentAnalyzer.h"
#include "tool/dir.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp{

    void AbstractUserAgentAnalyzer::initializeCache() {
        lock.lock();
        if(parseCache)
            delete parseCache;
        if (cacheSize >= 1) {
            parseCache = new lrumap<std::string, std::shared_ptr<UserAgent>>(cacheSize);
        } else {
            parseCache = nullptr;
        }
        lock.unlock();
    }

    void AbstractUserAgentAnalyzer::destroy() {
        lock.lock();
        AbstractUserAgentAnalyzerDirect::destroy();
        parseCache->clear();
        lock.unlock();
    }

    void AbstractUserAgentAnalyzer::disableCaching() {
        setCacheSize(0);
    }

    std::shared_ptr<UserAgent> AbstractUserAgentAnalyzer::parsePtr(std::shared_ptr<MutableUserAgent> userAgent) {
        if (userAgent == nullptr) {
            return nullptr;
        }
        if (parseCache == nullptr) {
            userAgent->reset();
            return AbstractUserAgentAnalyzerDirect::parsePtr(userAgent);
        }

        std::string             userAgentString = userAgent->getUserAgentString();
        std::shared_ptr<UserAgent> cachedValue     = (*parseCache)[userAgentString];
        if (cachedValue != nullptr) {
            return cachedValue; // As it is immutable it can safely be returned as is
        } else {
            cachedValue = AbstractUserAgentAnalyzerDirect::parsePtr(userAgent);
            (*parseCache)[userAgentString] = cachedValue;
        }
        // We have our answer.
        return cachedValue;
    }

    std::string AbstractUserAgentAnalyzer::toString() {
        std::ostringstream o;
        o << "UserAgentAnalyzer{" <<
          "cacheSize=" << cacheSize <<
          ", "  << AbstractUserAgentAnalyzerDirect::toString().c_str()  << "} ";
        return o.str();
    }

    void AbstractUserAgentAnalyzer::clearCache() {
        if (parseCache != nullptr) {
            parseCache->clear();
        }
    }

    void AbstractUserAgentAnalyzer::setCacheSize(size_t newCacheSize) {
        cacheSize = std::max(newCacheSize, (size_t)0);
        initializeCache();
    }

    AbstractUserAgentAnalyzer::~AbstractUserAgentAnalyzer() {
        if(parseCache)
            delete parseCache;
    }

    AbstractUserAgentAnalyzerBuilder::B &AbstractUserAgentAnalyzerBuilder::withCache(int newCacheSize) {
        AbstractUserAgentAnalyzerDirectBuilder::failIfAlreadyBuilt();
        ((AbstractUserAgentAnalyzer*)uaa.get())->setCacheSize(newCacheSize);
        return *this;
    }

    AbstractUserAgentAnalyzerBuilder::B &AbstractUserAgentAnalyzerBuilder::withoutCache() {
        AbstractUserAgentAnalyzerDirectBuilder::failIfAlreadyBuilt();
        ((AbstractUserAgentAnalyzer*)uaa.get())->setCacheSize(0);
        return *this;
    }

    std::shared_ptr<AbstractUserAgentAnalyzerDirect> AbstractUserAgentAnalyzerBuilder::build() {
        return AbstractUserAgentAnalyzerDirectBuilder::build();
    }
}