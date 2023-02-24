## Description
The purpose of this program is to implement user agent analysis, which is the same as the result of using https://github.com/nielsbasjes/yauaa java library.

The implementation is based on https://github.com/nielsbasjes/yauaa version 6.6(java)

```
        <dependency>
            <groupId>nl.basjes.parse.useragent</groupId>
            <artifactId>yauaa</artifactId>
            <version>6.6</version>
        </dependency>
```

        String ua = req.getHeader("User-Agent");
        logger.info("ua = " + ua);
        UserAgentAnalyzer uaa = UserAgentAnalyzer.newBuilder().withCache(1234).withField("DeviceClass").withAllFields().build();
        UserAgent obj = uaa.parse(ua);
        //logger.info("os = "+obj.getValue(UserAgent.OPERATING_SYSTEM_NAME));
        logger.info("device class = "+obj.getValue(UserAgent.DEVICE_CLASS));
        logger.info("agent name = " + obj.getValue(UserAgent.AGENT_NAME));

## Dependency

### antlr4 https://github.com/antlr/antlr4.git version 4.9.3

##### get antlr 4.9.3

git clone https://github.com/antlr/antlr4.git 

git checkout 4.9.3


##### Install antlr 4.9.3 in CentOS 7.6 environment

In CentOS 7.6 gcc version 4.8.5, there is incomplete support for regex, which needs to be upgraded to gcc 7.3.1

1. Install gcc 7.3.1
```
  sudo yum install centos-release-scl

  sudo yum install devtoolset-7-gcc*
```
   
2. Install antlr4 dependency
```
 sudo yum install  libuuid-devel
``` 

3. compile alntr4

```
cd antlr4/runtime/Cpp

mkdir build

cd build

cmake ..

make     
```

In case of error CPPUtils.cpp:54:24: missing binary operator before token "("

​             if __has_cpp_attribute(clang::fallthrough)

__*has_cpp_attribute* is introduced in the c++20 standard, directly comment out the following code:

```c++
#ifndef _MSC_VER
#if __has_cpp_attribute(clang::fallthrough)
          [[clang::fallthrough]];
#endif
#endif
```

After successful compilation, install:
```
    sudo make install
```

##### Install antlr 4.9.3 in ubuntu 20.0.4 environment

1) Install antlr4 dependency

  `sudo apt install uuid-dev`

2) Compile alntr4

`cd antlr4/runtime/Cpp`

`mkdir build`

`cd build`

`cmake ../`

`make`

`make install`

### yaml-cpp

##### Install yaml-cpp in CentOS 7.6 environment

```
git clone https://github.com/jbeder/yaml-cpp
cd yaml-cpp
git checkout yaml-cpp-0.7.0
mkdir build
cd build
cmake .. -DBUILD_SHARED_LIBS=ON
make
sudo make install
```

##### Installyaml-cpp in ubuntu 20.0.4 environment

`sudo apt install libyaml-cpp-dev`


## Compile & Install
```
   cd {your_path}/yauaacpp
   mkdir build
   cd build
   cmake ..
   make
   sudo make install
```

## Examples

### C++ example
test/src/yauaacpp/test.cpp
```c++
   std::shared_ptr<ycpp::AbstractUserAgentAnalyzerDirect> uaa = UserAgentAnalyzer::newBuilder()
            ->withField(DEVICE_CLASS)
            .withField(AGENT_NAME)
            .withoutCache()
            .build();

    std::ifstream f("./ua.txt",std::ios_base::in);
    for(int i=0; i<5; i++){
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
    
void funcua(std::shared_ptr<ycpp::AbstractUserAgentAnalyzerDirect> uaa, const std::string &ua_txt){
    std::shared_ptr<UserAgent> obj = uaa->parse(std::string(ua_txt));
    std::cout << ua_txt << std::endl;
    std::cout << "device class = " << obj->getValue(DEVICE_CLASS) << std::endl;
    std::cout << "agent name = " << obj->getValue(AGENT_NAME) << std::endl;
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

    std::cout << "browser:" << browser << ", evironment:" <<  evironment << std::endl;
}


```
### C example
test/src/yauaacpp/test.c
```c++
int main(int argc, char * argv[])
{
         char * ua = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36";
         char * fields[] = { DEVICE_CLASS, AGENT_NAME, NULL };
         const char * results[3];
         const char * ps;
     
         USER_AGENT_ANALYSER uaa = user_agent_analyser_create(fields, 0);
     
         user_agent_analyser_parse(uaa, ua, results);
     
         int i=0;
         while( (ps = results[i++]) != NULL) printf("%d:%s\n",i,ps);
     
         user_agent_analyser_free(uaa);
}         
```

### go example
src/go/yauaacpp/yauaa.go
```go
    package yauaacpp
    
    /*
    #cgo LDFLAGS: -L/usr/local/lib
    #cgo LDFLAGS: -lyauaacpp
    #include "string.h"
    #include "yauaacpp/yauaa_c.h"
    
    typedef struct {
        void * uaa;
        char * ua;
        int evironment;
        int browser;
    }uainfo;
    
    USER_AGENT_ANALYSER create_envirenment_browser_uaa(int cache_size) {
        char * fields[] = { DEVICE_CLASS, AGENT_NAME, NULL };
        return user_agent_analyser_create(fields, cache_size);
    }
    
    int get_envirenment_browser(uainfo * info){
        const char * results[3];
        user_agent_analyser_parse(info->uaa, info->ua, results);
        const char * deviceClass = results[0];
        if(0 == strcmp(deviceClass, "Desktop"))
            info->evironment = 1;
        else if(0 == strcmp(deviceClass, "Phone"))
            info->evironment = 2;
        else if(0 == strcmp(deviceClass, "Tablet"))
            info->evironment = 3;
        else
            info->evironment = 0;
    
        const char * agentName = results[1];
        if(0 == strcmp(agentName, "Chrome"))
            info->browser = 1;
        else if(0 == strcmp(agentName, "Mozilla"))
            info->browser = 2;
        else if(0 == strcmp(agentName, "Safari"))
            info->browser = 3;
        else if(0 == strcmp(agentName, "Internet Explorer"))
            info->browser = 4;
        else if(0 == strcmp(agentName, "Edge"))
            info->browser = 5;
        else
            info->browser = 0;
        return 1;
    }
    */
    import "C"
    
    import (
        "sync"
        "unsafe"
    )
    
    type Yauaa struct {
        mu     sync.Mutex
        uainfo *C.uainfo
    }
    
    func (y *Yauaa) WithCache(cacheSize int) {
        if y.uainfo == nil {
            y.mu.Lock()
            if y.uainfo == nil {
                y.uainfo = new(C.uainfo)
                y.uainfo.uaa = unsafe.Pointer(C.create_envirenment_browser_uaa(C.int(cacheSize)))
                y.uainfo.ua = nil
            }
            y.mu.Unlock()
        }
    }
    
    func (y *Yauaa) GetEnvirenmentBrowser(ua string) (evironment, browser int) {
        if y.uainfo == nil {
            y.mu.Lock()
            if y.uainfo == nil {
                y.uainfo = new(C.uainfo)
                y.uainfo.uaa = unsafe.Pointer(C.create_envirenment_browser_uaa(0))
                y.uainfo.ua = nil
            }
            y.mu.Unlock()
        }
    
        y.uainfo.ua = C.CString(ua)
        C.get_envirenment_browser(y.uainfo)
        return int(y.uainfo.evironment), int(y.uainfo.browser)
    }

```
src/go/yauaacpp/example/main.go
``` go
package main

import (
	"fmt"
	yauaacpp "yauaacpp"
)

func main() {
	yauaa := new(yauaacpp.Yauaa)

	fmt.Printf("init with cache\n")
	yauaa.WithCache(100)
	fmt.Printf("init with cache is over\n")

	var ua = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36"
	evironment, browser := yauaa.GetEnvirenmentBrowser(ua)
	fmt.Printf("evironment=%d,browser=%d\n", evironment, browser)
}

```
