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



#ifdef _MSC_VER

#include <unordered_map>
#include <vector>

#else

#include <unistd.h> // for getopt on non-Windows platform

#endif

#include <string>
#include <chrono>
#include <tuple>
#include <iostream>

#include "yauaacpp/yauaacpp.h"

using namespace ycpp;
std::shared_ptr<ycpp::AbstractUserAgentAnalyzerDirect> uaa;
std::recursive_mutex lock;

#define BROWSER_OTHER       "0"
#define BROWSER_CHROME      "1"
#define BROWSER_MOZILLA     "2"
#define BROWSER_SAFARI      "3"
#define BROWSER_IE          "4"
#define BROWSER_EDGE        "5"
#define BROWSER_SAMSUNG     "6"
#define BROWSER_MINUI       "7"
#define BROWSER_OPERA       "8"
#define BROWSER_YANDEX      "9"
#define BROWSER_UC          "10"
#define BROWSER_FIREFOX     "11"
//#define BROWSER_QQ          "12"
#define BROWSER_HUAWEI      "12"
#define BROWSER_WEBVIEW             "20"
#define BROWSER_WEBVIEW_FACEBOOK    "21"
#define BROWSER_WEBVIEW_INSTAGRAM   "22"
#define BROWSER_WEBVIEW_SNAPCHAT    "23"
#define BROWSER_WEBVIEW_GOOGLE      "24"
#define BROWSER_GOOGLEBOT           "30"



//const char * ua_txt = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.99 Safari/537.36";
const char * ua_txt ="Mozilla/5.0 (iPhone; CPU iPhone OS 15_3_1 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/15.3 Mobile/15E148 Safari/604.1";

bool skip(const std::string & browser_result, const std::string & browser){
    if(browser == BROWSER_HUAWEI)
        return true;
    if(browser==BROWSER_WEBVIEW && browser_result==BROWSER_OTHER)
        return true;
    if(browser==BROWSER_WEBVIEW_INSTAGRAM && browser_result == BROWSER_WEBVIEW)
        return true;
    if(browser==BROWSER_WEBVIEW && browser_result == BROWSER_WEBVIEW_FACEBOOK)
        return true;
    if(browser==BROWSER_EDGE && browser_result == BROWSER_CHROME)
        return true;
//    if(browser==BROWSER_CHROME && browser_result == BROWSER_QQ)
//        return true;
    if(browser==BROWSER_OTHER && browser_result == BROWSER_CHROME)
        return true;
    if(browser==BROWSER_GOOGLEBOT && browser_result == BROWSER_OTHER)
        return true;
    return false;
}

void funcua(std::shared_ptr<ycpp::AbstractUserAgentAnalyzerDirect> uaa, const std::string &ua_txt, const std::string & browser_result,int deep){
    if(deep >= 2)
        return ;
    lock.lock();
    std::shared_ptr<UserAgent> obj = uaa->parse(std::string(ua_txt));
    lock.unlock();
//    std::cout << ua_txt << std::endl;
//    std::cout << "device class = " << obj->getValue(DEVICE_CLASS) << std::endl;
//    std::cout << "agent name = " << obj->getValue(AGENT_NAME) << std::endl;
    std::string evironment,browser;
    std::string deviceClass = obj->getValue(DEVICE_CLASS);
    if(deviceClass == "Desktop")
        evironment = "1";
    else if(deviceClass == "Phone")
        evironment = "2";
    else if(deviceClass == "Tablet")
        evironment = "3";
    else
        evironment = "0";

    std::string agentName = obj->getValue(AGENT_NAME);
    std::string webviewApp = obj->getValue(WEBVIEW_APP_NAME);

    if(agentName == "Chrome")
        browser = BROWSER_CHROME;
    else if(agentName == "Mozilla")
        browser = BROWSER_MOZILLA;
    else if(agentName == "Safari")
        browser = BROWSER_SAFARI;
    else if(agentName == "Internet Explorer")
        browser = BROWSER_IE;
    else if(agentName == "Edge" || agentName == "Edge Webview")
        browser = BROWSER_EDGE;
    else if(agentName == "SamsungBrowser" || webviewApp == "SamsungBrowser")
        browser = BROWSER_SAMSUNG;
    else if(agentName == "Opera" || webviewApp == "Opera")
        browser = BROWSER_OPERA;
    else if(agentName == "Firefox")
        browser = BROWSER_FIREFOX;
    else if(agentName == "MiuiBrowser")
        browser = BROWSER_MINUI;
    else if(agentName == "YaBrowser")
        browser = BROWSER_YANDEX;
    else if(agentName == "HuaweiBrowser")
        browser = BROWSER_HUAWEI;
    else if(agentName == "Chrome Webview" || agentName == "UIWebView" || agentName == "AppleWebKit" ||
            agentName == "NewsBreak" ||
            agentName.find("WebViewApp") == 0) // start with "WebViewApp"
        browser = BROWSER_WEBVIEW;
    else if(deviceClass=="Robot" || agentName.find("Googlebot") == 0)
        browser = BROWSER_GOOGLEBOT;
    else
        browser = BROWSER_OTHER;

    if(browser == BROWSER_OTHER || browser == BROWSER_WEBVIEW) {
        if (webviewApp == "AgentWeb")
            browser = BROWSER_UC;
        else if (webviewApp == "Facebook App for Android" || webviewApp == "Facebook App for iOS" || webviewApp == "Facebook EMA")
            browser = BROWSER_WEBVIEW_FACEBOOK;
        else if (agentName == "Instagram" || webviewApp == "Instagram")
            browser = BROWSER_WEBVIEW_INSTAGRAM;
        else if (webviewApp == "Google Search App")
            browser = BROWSER_WEBVIEW_GOOGLE;
        else if (webviewApp == "Snapchat")
            browser = BROWSER_WEBVIEW_SNAPCHAT;
    }


    if(browser_result == browser)
        std::cout << "ok" << std::endl;
    else {
        if (!skip(browser_result,browser)) {
            std::cout << browser << " should be " << browser_result << "," << ua_txt << std::endl;
            funcua(uaa, ua_txt, browser_result, deep + 1);
        }
    }
}

void * proc(void * param){
    std::ifstream f("/work/base.txt",std::ios_base::in);
    for(int i=0; i<100000; i++){
        if(i<0)
            continue;
        std::string line;
        if(std::getline(f,line)) {
            const char * ps = line.c_str();
            int browser_result = atoi(ps);
            ps = strchr(ps,',');
            ps ++;
            ps = strchr(ps,',');
            ps ++;
            std::string ua = ps;
            char result_str[100];
            sprintf(result_str,"%d",browser_result);
            funcua(uaa, ua, result_str,0);
        }
        else {
            std::cerr << "ua.txt read failure, line " << i << std::endl;
            break;
        }
    }
    return nullptr;
}

int main(int argc, char **argv) {
    std::cout << "Testing User Agent parse..." << std::endl;
    time_t start = time(nullptr);
    uaa = UserAgentAnalyzer::newBuilder()
            ->withField(DEVICE_CLASS)
            .withField(AGENT_NAME)
            .withField(WEBVIEW_APP_NAME)
            .withCache(10000)
            .build();


    int THREAD_CNT = 1;

    std::vector<pthread_t> threads;

    for(int i=0; i<THREAD_CNT; i++){
        pthread_t t;
        pthread_attr_t tattr;
        pthread_attr_init(&tattr);
        pthread_create(&t, &tattr, proc, nullptr);
        threads.push_back(t);
    }

    for(pthread_t t:threads){
        pthread_join(t, nullptr);
    }
    time_t end = time(nullptr);
    std::cout << "total seconds = " << end-start << std::endl;
    return 0;
}