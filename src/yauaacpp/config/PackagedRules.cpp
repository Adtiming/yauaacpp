//
// Created by sunxg on 22-2-16.
//

#include "PackagedRules.h"
#include <memory>
#include <mutex>
#include <tool/tool.h>


namespace ycpp {
    const char * RULE_FILES[] = {
            "UserAgents/Additional-Tests.yaml",
            "UserAgents/Alcatel-Tests.yaml",
            "UserAgents/Amazon.yaml",
            "UserAgents/AmazonDevices.yaml",
            "UserAgents/Android.yaml",
            "UserAgents/AndroidDeviceOverrides.yaml",
            "UserAgents/Anonymized.yaml",
            "UserAgents/Apple.yaml",
            "UserAgents/AppleTypes.yaml",
            "UserAgents/AppleTypesBasic.yaml",
            "UserAgents/AppleWebview.yaml",
            "UserAgents/Apps.yaml",
            "UserAgents/Asus-Tests.yaml",
            "UserAgents/Audio.yaml",
            "UserAgents/Bada.yaml",
            "UserAgents/BitWalker-tests.yaml",
            "UserAgents/BlackBerry.yaml",
            "UserAgents/BrokenUseragents-Tests.yaml",
            "UserAgents/BrokenUseragents.yaml",
            "UserAgents/CPUTypes.yaml",
            "UserAgents/Car.yaml",
            "UserAgents/Cubot-Tests.yaml",
            "UserAgents/EMailClients.yaml",
            "UserAgents/Electron.yaml",
            "UserAgents/Facebook-OsMeta.yaml",
            "UserAgents/Facebook.yaml",
            "UserAgents/GameConsoles.yaml",
            "UserAgents/GeckoFirefox.yaml",
            "UserAgents/GoannaPaleMoon.yaml",
            "UserAgents/GoogleChrome.yaml",
            "UserAgents/GoogleChrome70-Tests.yaml",
            "UserAgents/GoogleChromeFrozen.yaml",
            "UserAgents/GoogleFavicon-Tests.yaml",
            "UserAgents/GooglePixel.yaml",
            "UserAgents/Hackers-CodeInjection-Tests.yaml",
            "UserAgents/Hackers-Log4Shell-Tests.yaml",
            "UserAgents/Hackers-PathTraversal-Tests.yaml",
            "UserAgents/Hackers-Tests.yaml",
            "UserAgents/Hackers.yaml",
            "UserAgents/Huawei-Tests.yaml",
            "UserAgents/ISOLanguageCode-Tests.yaml",
            "UserAgents/ISOLanguageCode.yaml",
            "UserAgents/KaiOS.yaml",
            "UserAgents/Konqueror.yaml",
            "UserAgents/LG-Tests.yaml",
            "UserAgents/Lenovo-Tests.yaml",
            "UserAgents/Linux.yaml",
            "UserAgents/MSEdge.yaml",
            "UserAgents/MSInternetExplorer.yaml",
            "UserAgents/Maxthon.yaml",
            "UserAgents/Meizu-Tests.yaml",
            "UserAgents/Mobile.yaml",
            "UserAgents/MobileBrand-Tests.yaml",
            "UserAgents/MobileBrand-rules.yaml",
            "UserAgents/MobileBrands.yaml",
            "UserAgents/MobileBrowser-Tests.yaml",
            "UserAgents/Mozilla.yaml",
            "UserAgents/Nokia.yaml",
            "UserAgents/Openspc2-tests.yaml",
            "UserAgents/Opera.yaml",
            "UserAgents/OperatingSystem-Tests.yaml",
            "UserAgents/OperatingSystemDeviceNames.yaml",
            "UserAgents/Oppo-Tests.yaml",
            "UserAgents/OtherOS.yaml",
            "UserAgents/Otter-Tests.yaml",
            "UserAgents/Robot-Imitators.yaml",
            "UserAgents/RobotBaseRules.yaml",
            "UserAgents/Robots-Bing.yaml",
            "UserAgents/Robots-Google.yaml",
            "UserAgents/Robots-PriceSpiders.yaml",
            "UserAgents/Robots.yaml",
            "UserAgents/Safari.yaml",
            "UserAgents/Samsung.yaml",
            "UserAgents/SecurityFlag.yaml",
            "UserAgents/SettopBox.yaml",
            "UserAgents/Sony.yaml",
            "UserAgents/SpecialBrowsers.yaml",
            "UserAgents/TV.yaml",
            "UserAgents/Tencent.yaml",
            "UserAgents/URL.yaml",
            "UserAgents/UUID.yaml",
            "UserAgents/Ubuntu-18.10-Tests.yaml",
            "UserAgents/Ubuntu-Tests.yaml",
            "UserAgents/Ubuntu.yaml",
            "UserAgents/UbuntuVersionLookups.yaml",
            "UserAgents/Vodafone-Tests.yaml",
            "UserAgents/Watches.yaml",
            "UserAgents/Wiko-Tests.yaml",
            "UserAgents/Windows.yaml",
            "UserAgents/WindowsCE.yaml",
            "UserAgents/WindowsDesktopLookups.yaml",
            "UserAgents/WindowsOEM-Tests.yaml",
            "UserAgents/WindowsOEMCodes.yaml",
            "UserAgents/WindowsPhone.yaml",
            "UserAgents/WindowsPhoneLookups.yaml",
            "UserAgents/Xiaomi.yaml",
            "UserAgents/eBook.yaml"
    };

    std::recursive_mutex package_rule_lock;

    std::list<std::shared_ptr<Resource>> PackagedRules::RULE_FILES_LIST;

    const std::list<std::shared_ptr<Resource>> &PackagedRules::getRuleFileNames() {

        if(RULE_FILES_LIST.empty()){
            package_rule_lock.lock();
            if(RULE_FILES_LIST.empty()){
                for (const char * s : RULE_FILES) {
                    std::vector<std::string> v = string_split(s, '/');
                    RULE_FILES_LIST.emplace_back(std::make_shared<Resource>(v[0], v[1]));
                }
            }
            package_rule_lock.unlock();
        }

        return RULE_FILES_LIST;
    }
}
