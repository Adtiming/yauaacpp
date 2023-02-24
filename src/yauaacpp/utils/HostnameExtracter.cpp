//
// Created by sunxg on 22-2-4.
//

#include "HostnameExtracter.h"
#include "Normalize.h"
#include "tool/LUrlParser.h"
#include "tool/tool.h"

namespace ycpp {

    std::set<std::string> HostnameExtracter::UNWANTED_URL_BRANDS = initUrlBrands();
    std::set<std::string> HostnameExtracter::UNWANTED_EMAIL_BRANDS = initEmailBrands();
    std::list<HostnameExtracter::SitePathExtract> HostnameExtracter::SITE_PATH_EXTRACTS = initSitePathExtracts();

    std::set<std::string> HostnameExtracter::initUrlBrands() {
        std::set<std::string> t;
        // Localhost ...
        t.insert("localhost");
        // Software repositories
        t.insert("github.com");
        t.insert("gitlab.com");
        // Url shortners
        t.insert("bit.ly");
        // Hosting sites
        t.insert("wordpress.com");
        return t;
    }

    std::set<std::string> HostnameExtracter::initEmailBrands() {
        std::set<std::string> t;
        t.insert("localhost");
        t.insert("gmail.com");
        t.insert("outlook.com");
        return t;
    }

    std::list<HostnameExtracter::SitePathExtract> HostnameExtracter::initSitePathExtracts() {
        std::list<SitePathExtract> t;
        t.emplace_back("https://github.com/",                  0);
        t.emplace_back("https://gitlab.com/",                  0);
        t.emplace_back("https://sourceforge.net/projects/",    0);
        return t;
    }

    std::string HostnameExtracter::extractCompanyFromSoftwareRepositoryUrl(const std::string &url) {
        for (SitePathExtract sitePathExtract : SITE_PATH_EXTRACTS) {
            if (starts_with(url,sitePathExtract.prefix)) {
                std::string path = url.substr(sitePathExtract.prefixLength);
                auto splits = string_split(path,'/');
                if (splits.size() == 0 || splits.size() < (size_t)sitePathExtract.brandSegment){
                    return "";
                }
                std::string brand = splits[sitePathExtract.brandSegment];
                if (brand.empty()) {
                    return "";
                }
                return Normalize::brand(brand);
            }
        }
        return "";
    }

    std::string HostnameExtracter::extractCompanyFromHostName(const std::string &_hostname, std::set<std::string> blackList) {
        std::string hostname = _hostname;
        if (hostname.empty()) {
            return "";
        }
        hostname = tolowers(hostname);
        if (blackList.end() == blackList.find(hostname)) {
            return "";
        }
        auto v = string_split(hostname,'.');
        return Normalize::brand(v[0]);
        // todo 实现 getDomainRoot
//        std::string root = PublicSuffixMatcherLoader.getDefault().getDomainRoot(hostname, ICANN);
//
//        if (root.empty()) {
//            return root;
//        }
//        return Normalize::brand(root.split("\\.", 2)[0]);
    }

    std::string HostnameExtracter::extractHostname(const std::string &_uriString) {
        std::string uriString = _uriString;
        if (uriString.empty()) {
            return ""; // Nothing to do here
        }

        size_t firstQuestionMark = uriString.find('?');
        size_t firstAmpersand = uriString.find('&');
        size_t cutIndex = std::string::npos;
        if (firstAmpersand != std::string::npos) {
            if (firstQuestionMark != std::string::npos) {
                cutIndex = firstQuestionMark;
            } else {
                cutIndex = firstAmpersand;
            }
        } else {
            if (firstQuestionMark != std::string::npos) {
                cutIndex = firstQuestionMark;
            }
        }
        if (cutIndex != std::string::npos) {
            uriString = uriString.substr(0, cutIndex);
        }

        LUrlParser::ParseURL  uri = LUrlParser::ParseURL::parseURL(uriString);
        try {
            if (uriString[0] == '/') {
                if (uriString[1] == '/') {
                    //uri = LUrlParser::ParseURL::parseURL(uriString);
                } else {
                    // So no hostname
                    return "";
                }
            } else {
                if (contains(uriString,":")) {
                    //uri = LUrlParser::ParseURL::parseURL(uriString);
                } else {
                    if (contains(uriString,"/")) {
                        return string_split(uriString,'/')[0];
                    } else {
                        return uriString;
                    }
                }
            }
        } catch (std::exception & e) {
            return "";
        }

        return uri.host_;
    }

    std::string HostnameExtracter::extractBrandFromUrl(const std::string &url) {
        std::string hostname = extractHostname(url);
        std::string brand = extractCompanyFromHostName(hostname, UNWANTED_URL_BRANDS);

        if (brand.empty()) {
            // Perhaps this is software repository
            brand = extractCompanyFromSoftwareRepositoryUrl(url);
        }
        return brand;
    }

    std::string HostnameExtracter::extractBrandFromEmail(const std::string &email) {
        std::string hostname = email;
        size_t atOffset = hostname.find('@');
        if (atOffset != std::string::npos) {
            hostname = hostname.substr(atOffset + 1);
        }
        return extractCompanyFromHostName(hostname, UNWANTED_EMAIL_BRANDS);
    }
}