//
// Created by sunxg on 23-2-17.
//

#ifndef YAUAACPP_YAUAA_C_H
#define YAUAACPP_YAUAA_C_H

#define DEVICE_CLASS                         "DeviceClass"
#define DEVICE_NAME                          "DeviceName"
#define DEVICE_BRAND                         "DeviceBrand"
#define DEVICE_CPU                           "DeviceCpu"
#define DEVICE_CPU_BITS                      "DeviceCpuBits"
#define DEVICE_FIRMWARE_VERSION              "DeviceFirmwareVersion"
#define DEVICE_VERSION                       "DeviceVersion"

#define OPERATING_SYSTEM_CLASS               "OperatingSystemClass"
#define OPERATING_SYSTEM_NAME                "OperatingSystemName"
#define OPERATING_SYSTEM_VERSION             "OperatingSystemVersion"
#define OPERATING_SYSTEM_VERSION_MAJOR       "OperatingSystemVersionMajor"
#define OPERATING_SYSTEM_NAME_VERSION        "OperatingSystemNameVersion"
#define OPERATING_SYSTEM_NAME_VERSION_MAJOR  "OperatingSystemNameVersionMajor"
#define OPERATING_SYSTEM_VERSION_BUILD       "OperatingSystemVersionBuild"

#define LAYOUT_ENGINE_CLASS                  "LayoutEngineClass"
#define LAYOUT_ENGINE_NAME                   "LayoutEngineName"
#define LAYOUT_ENGINE_VERSION                "LayoutEngineVersion"
#define LAYOUT_ENGINE_VERSION_MAJOR          "LayoutEngineVersionMajor"
#define LAYOUT_ENGINE_NAME_VERSION           "LayoutEngineNameVersion"
#define LAYOUT_ENGINE_NAME_VERSION_MAJOR     "LayoutEngineNameVersionMajor"
#define LAYOUT_ENGINE_BUILD                  "LayoutEngineBuild"

#define AGENT_CLASS                          "AgentClass"
#define AGENT_NAME                           "AgentName"
#define AGENT_VERSION                        "AgentVersion"
#define AGENT_VERSION_MAJOR                  "AgentVersionMajor"
#define AGENT_NAME_VERSION                   "AgentNameVersion"
#define AGENT_NAME_VERSION_MAJOR             "AgentNameVersionMajor"
#define AGENT_BUILD                          "AgentBuild"
#define AGENT_LANGUAGE                       "AgentLanguage"
#define AGENT_LANGUAGE_CODE                  "AgentLanguageCode"
#define AGENT_INFORMATION_EMAIL              "AgentInformationEmail"
#define AGENT_INFORMATION_URL                "AgentInformationUrl"
#define AGENT_SECURITY                       "AgentSecurity"
#define AGENT_UUID                           "AgentUuid"

#define WEBVIEW_APP_NAME                     "WebviewAppName"
#define WEBVIEW_APP_VERSION                  "WebviewAppVersion"
#define WEBVIEW_APP_VERSION_MAJOR            "WebviewAppVersionMajor"
#define WEBVIEW_APP_NAME_VERSION             "WebviewAppNameVersion"
#define WEBVIEW_APP_NAME_VERSION_MAJOR       "WebviewAppNameVersionMajor"

#define FACEBOOK_CARRIER                     "FacebookCarrier"
#define FACEBOOK_DEVICE_CLASS                "FacebookDeviceClass"
#define FACEBOOK_DEVICE_NAME                 "FacebookDeviceName"
#define FACEBOOK_DEVICE_VERSION              "FacebookDeviceVersion"
#define FACEBOOK_F_B_O_P                     "FacebookFBOP"
#define FACEBOOK_F_B_S_S                     "FacebookFBSS"
#define FACEBOOK_OPERATING_SYSTEM_NAME       "FacebookOperatingSystemName"
#define FACEBOOK_OPERATING_SYSTEM_VERSION    "FacebookOperatingSystemVersion"

#define ANONYMIZED                           "Anonymized"

#define HACKER_ATTACK_VECTOR                 "HackerAttackVector"
#define HACKER_TOOLKIT                       "HackerToolkit"

#define KOBO_AFFILIATE                       "KoboAffiliate"
#define KOBO_PLATFORM_ID                     "KoboPlatformId"

#define IE_COMPATIBILITY_VERSION             "IECompatibilityVersion"
#define IE_COMPATIBILITY_VERSION_MAJOR       "IECompatibilityVersionMajor"
#define IE_COMPATIBILITY_NAME_VERSION        "IECompatibilityNameVersion"
#define IE_COMPATIBILITY_NAME_VERSION_MAJOR  "IECompatibilityNameVersionMajor"

#define SYNTAX_ERROR                         "__SyntaxError__"
#define USERAGENT_FIELDNAME                  "Useragent"

#define NETWORK_TYPE                         "NetworkType"

#define SET_ALL_FIELDS                       "__Set_ALL_Fields__"
#define NULL_VALUE                           "<<<null>>>"
#define UNKNOWN_VALUE                        "Unknown"
#define UNKNOWN_VERSION                      "??"
#define UNKNOWN_NAME_VERSION                 "Unknown ??"

#ifdef __cplusplus
extern "C" {
#endif

    typedef void * USER_AGENT_ANALYSER;

    // with_fileds, DEVICE_CLASS,AGENT_NAME etc, NULL is end flag
    // cache_size, 0- no cache, other value is cache size
    USER_AGENT_ANALYSER user_agent_analyser_create(char * with_fileds [], int cache_size);
    void user_agent_analyser_free(USER_AGENT_ANALYSER uaa);

    //result, value count is same to with_fileds, and NULL is end flag
    void user_agent_analyser_parse(USER_AGENT_ANALYSER uaa, const char * ua, const char * result []);

    /*
     * Example
     *    char * ua = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36";
     *    char * fields[] = { DEVICE_CLASS, AGENT_NAME, NULL };
     *    const char * results[3];
     *    const char * ps;
     *
     *    USER_AGENT_ANALYSER uaa = user_agent_analyser_create(fields, 0);
     *
     *    user_agent_analyser_parse(uaa, ua, results);
     *
     *    while( (ps = *results++) != NULL) printf("%s\n", ps);
     *
     *    user_agent_analyser_free(uaa);
     */

#ifdef __cplusplus
}
#endif

#endif //YAUAACPP_YAUAA_C_H
