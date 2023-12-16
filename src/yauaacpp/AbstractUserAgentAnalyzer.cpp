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
        if(parseCache)
            delete parseCache;
        if (cacheSize >= 1) {
            parseCache = new lrumap<std::string, std::shared_ptr<UserAgent>>(cacheSize);
        } else {
            parseCache = nullptr;
        }
    }

    void AbstractUserAgentAnalyzer::destroy() {
        AbstractUserAgentAnalyzerDirect::destroy();
        parseCache->clear();
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

    bool save_string(FILE * fout, const std::string & s){
        size_t len = s.size();
        fwrite(&len,sizeof(size_t),1,fout);
        fwrite(s.c_str(),len,1,fout);
        return true;
    }

    bool load_string(FILE * fin, std::string & s){
        size_t len = 0;
        if(1!=fread(&len,sizeof(size_t),1,fin))
            return false;
        char * p = new char[len+1];
        if(1!=fread(p,len,1,fin)){
            delete []p;
            return false;
        }
        p[len] = 0;
        s = p;
        delete []p;
        return true;
    }

    struct M : public CacheCopy {
        std::map<std::string, std::shared_ptr<UserAgent>> m;
        size_t size() override {return m.size();}
    };

    std::shared_ptr<CacheCopy> AbstractUserAgentAnalyzer::copyCache() {

        if(parseCache){
            auto * result = new M();

            result->m.insert(parseCache->begin(),parseCache->end());

            return std::shared_ptr<CacheCopy>(result);
        } else
            return nullptr;
    }

    bool AbstractUserAgentAnalyzer::saveCache(const std::string & fileName,std::shared_ptr<CacheCopy> & cacheCopy) const {
        if(parseCache == nullptr)
            return false;
        if(!cacheCopy)
            return false;

        M * pCache = dynamic_cast<M*>(cacheCopy.get());

        FILE * fout = fopen(fileName.c_str(), "wb");
        if(fout == nullptr)
            return false;

        // write total
        size_t total = pCache->m.size();
        fwrite(&total,sizeof(size_t),1,fout);

        auto it = pCache->m.begin();
        while(it != pCache->m.end()){
            std::shared_ptr<UserAgent> v = it->second;
            auto * obj = dynamic_cast<ImmutableUserAgent*>(v.get());
            if(obj == nullptr){
                printf("is not ImmutableUserAgent");
            }else{
                obj->save(fout);
            }
            it ++;
        }

        fclose(fout);
        return true;
    }

    bool AbstractUserAgentAnalyzer::loadCache(const std::string & fileName) {
        if(parseCache == nullptr)
            return false;
        FILE * fin = fopen(fileName.c_str(),"rb");
        if(fin == nullptr)
            return false;
        size_t total;
        if(1!=fread(&total,sizeof(total),1,fin)) {
            fclose(fin);
            return false;
        }

        for(size_t i=0; i<total; i++) {
            auto obj = new ImmutableUserAgent();
            if(!obj->load(fin)){
                delete obj;
                fclose(fin);
                return false;
            }
            (*parseCache)[obj->getUserAgentString()] = std::shared_ptr<UserAgent>(obj);
        }

        fclose(fin);
        return true;
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