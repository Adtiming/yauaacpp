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

#include "yauaacpp.h"

using namespace ycpp;
std::shared_ptr<ycpp::AbstractUserAgentAnalyzerDirect> uaa;
std::recursive_mutex lock;

//const char * ua_txt = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.99 Safari/537.36";
const char * ua_txt ="Mozilla/5.0 (iPhone; CPU iPhone OS 15_3_1 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/15.3 Mobile/15E148 Safari/604.1";

void funcua(std::shared_ptr<ycpp::AbstractUserAgentAnalyzerDirect> uaa, const std::string &ua_txt){
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
    if(agentName == "Chrome")
        browser = "1";
    else if(agentName == "Mozilla")
        browser = "2";
    else if(agentName == "Safari")
        browser = "3";
    else if(agentName == "Internet Explorer")
        browser = "4";
    else if(agentName == "Edge")
        browser = "5";
    else
        browser = "0";

   // std::cout << "browser:" << browser << ", evironment:" <<  evironment << std::endl;
}

void * proc(void * param){
    std::ifstream f(".",std::ios_base::in);
    for(int i=0; i<100000; i++){
        if(i<0)
            continue;
        std::string ua;
        if(std::getline(f,ua))
            funcua(uaa,ua);
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
            .withCache(10000)
            .build();


    int THREAD_CNT = 3;

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