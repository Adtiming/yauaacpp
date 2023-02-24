//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_HOSTNAMEEXTRACTER_H
#define YAUAACPP_HOSTNAMEEXTRACTER_H

#include "yauaacpp_def.h"

namespace ycpp {

    class HostnameExtracter {
    private:
        static std::set<std::string> UNWANTED_URL_BRANDS;
        static std::set<std::string> UNWANTED_EMAIL_BRANDS;

        static std::set<std::string> initUrlBrands();
        static std::set<std::string> initEmailBrands();

        struct SitePathExtract {
            std::string prefix;
            int    prefixLength;
            int    brandSegment;

            SitePathExtract(const std::string & prefix, int brandSegment) {
                this->prefix = prefix;
                this->prefixLength = prefix.length();
                this->brandSegment = brandSegment;
            }
        };
        static std::list<SitePathExtract> SITE_PATH_EXTRACTS;
        static std::list<SitePathExtract> initSitePathExtracts();

    public:
        static std::string extractCompanyFromSoftwareRepositoryUrl(const std::string & url);

        static std::string extractCompanyFromHostName(const std::string & hostname, std::set<std::string> blackList);

        static std::string extractHostname(const std::string & uriString);


        static std::string extractBrandFromUrl(const std::string & url);

        static std::string extractBrandFromEmail(const std::string & email);

    };

}
#endif //YAUAACPP_HOSTNAMEEXTRACTER_H
