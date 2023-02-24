//
// Created by sunxg on 22-2-3.
//

#include "EvilManualUseragentStringHacks.h"
#include "tool/encode.hpp"
#include "tool/tool.h"

namespace ycpp {
    std::regex EvilManualUseragentStringHacks::MISSING_PRODUCT_AT_START("^\\(( |;|null|compatible|windows|android|linux).*",std::regex::icase);
    std::regex EvilManualUseragentStringHacks::MISSING_SPACE("(/[0-9]+\\.[0-9]+)([A-Z][a-z][a-z][a-z]+ )");
    std::regex EvilManualUseragentStringHacks::MULTIPLE_SPACES(" {2,}");
    std::regex EvilManualUseragentStringHacks::AVOID_BASE64_MATCH("(android/[0-9]+)(/)",std::regex::icase);
    std::regex EvilManualUseragentStringHacks::ANDROID_DASH_VERSION("(android)-([0-9]+)",std::regex::icase);
    std::regex EvilManualUseragentStringHacks::TENCENT_NETTYPE_FIX("(NetType)/([0-9a-z._-]+)",std::regex::icase);
    std::regex EvilManualUseragentStringHacks::TENCENT_LANGUAGE_FIX("(Language)/([a-z_-]+)",std::regex::icase);

    std::string EvilManualUseragentStringHacks::fixIt(const std::string &useragent) {
        if (useragent == "" || useragent.empty()) {
            return useragent;
        }
        std::string result = useragent;

        result = std::regex_replace(result,MULTIPLE_SPACES,std::string(" "));

        // The first one is a special kind of space: https://unicodemap.org/details/0x2002/index.html
        string_replace(result, "\u2002", " ");

        if (result[0] == ' ') {
            result = trim(result);
        }

        // The NetType and Language tags as used by Tencent re hard to parse.
        // Some example snippets from Tencent/Alibaba style agents:
        //    Core/UIWebView NetType/WIFI
        //    Core/UIWebView NetType/2G
        //    Process/tools NetType/portalmmm.nl Language/zh_CN
        //    Process/tools NetType/NON_NETWORK Language/zh_CN
        //
        // The 'fix' is to force an extra comment block in there.
        result = std::regex_replace(result,TENCENT_NETTYPE_FIX,std::string("() $1/$2()"));
        result = std::regex_replace(result,TENCENT_LANGUAGE_FIX,std::string("() $1/$2()"));

        string_replace(result, "SSL/TLS", "SSL TLS");

        if (result.npos != result.find("MSIE")) {
            string_replace(result, "MSIE7", "MSIE 7");
            string_replace(result, "MSIE8", "MSIE 8");
            string_replace(result, "MSIE9", "MSIE 9");
        }

        string_replace(result, "MSOffice", "MS-Office");

        string_replace(result, "Ant.com Toolbar", "Ant.com_Toolbar");

        // Something like Android-4.0.3 is seen as a text instead of a product.
        result = std::regex_replace(result,ANDROID_DASH_VERSION,std::string("$1 $2"));

        // We have seen problem cases like " Version/4.0Mobile Safari/530.17"
        result = std::regex_replace(result,MISSING_SPACE,std::string("$1 $2"));

        // Sometimes a case like  "Android/9/something/" matches the pattern of Base84 which breaks everything
        // So those cases we simply insert a space to avoid this match and without changing the resulting tree.
        result = std::regex_replace(result,AVOID_BASE64_MATCH,std::string("$1 $2"));

        // We have seen problem cases like "Java1.0.21.0"
        string_replace(result, "Java", "Java ");

        // We have seen problem cases like "Wazzup1.1.100"
        string_replace(result, "Wazzup", "Wazzup ");

        // This one is a single useragent that hold significant traffic
        string_replace(result, " (Macintosh); ", " (Macintosh; ");

        // This one is a single useragent that hold significant traffic
        string_replace(result, "Microsoft Windows NT 6.2.9200.0);", "Microsoft Windows NT 6.2.9200.0;");

        // The VM_Vertis 4010 You Build/VM is missing a ')'
        string_replace(result, "You Build/VM", "You Build/VM)");

        // Some agents are providing comment values that are ONLY a version
        string_replace(result, "(/", "(Unknown/");
        string_replace(result, "; /", "; Unknown/");

        string_replace(result, ", _TV_", " _TV_");

        // Repair certain cases of broken useragents (like we see for the Facebook app a lot)
        if (std::regex_search(result,MISSING_PRODUCT_AT_START) || result[0] == '[') {
            // We simply prefix a fake product name to continue parsing.
            result = "FakeYauaaProduct/3.14 " + result;
        } else {
            // This happens occasionally
            if (result[0] == '/') {
                // We simply prefix a fake product name to continue parsing.
                result = "FakeYauaaProduct" + result;
            }
        }

        // Kick some garbage that sometimes occurs.
        result = std::regex_replace(result, std::regex(",gzip(gfe)"), std::string(""));

        // The Weibo useragent This one is a single useragent that hold significant traffic
        string_replace(result, "__", " ");

        if (    (result.find('%') != result.npos) &&
                (result.find("%20") != result.npos ||
                 result.find("%3B") != result.npos ||
                 result.find("%25") != result.npos ||
                 result.find("%2F") != result.npos ||
                 result.find("%28") != result.npos))
        {

                result = lib::url_decode(result);
        }

        return result; // 99.99% of the cases nothing will have changed.
    }
}