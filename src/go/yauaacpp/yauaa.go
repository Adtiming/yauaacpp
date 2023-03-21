package yauaacpp

/*
#cgo LDFLAGS: -L/usr/local/lib
#cgo LDFLAGS: -lyauaacpp
#include "string.h"

#define DEVICE_CLASS                         "DeviceClass"
#define AGENT_NAME                           "AgentName"
#define WEBVIEW_APP_NAME                     "WebviewAppName"

    typedef void * USER_AGENT_ANALYSER;

    // with_fileds, DEVICE_CLASS,AGENT_NAME etc, NULL is end flag
    // cache_size, 0- no cache, other value is cache size
    USER_AGENT_ANALYSER user_agent_analyser_create(char * with_fileds [], int cache_size);
    void user_agent_analyser_free(USER_AGENT_ANALYSER uaa);

    //result, value count is same to with_fileds, and NULL is end flag
    void user_agent_analyser_parse(USER_AGENT_ANALYSER uaa, const char * ua, const char * result []);


#define BROWSER_OTHER       0
#define BROWSER_CHROME      1
#define BROWSER_MOZILLA     2
#define BROWSER_SAFARI      3
#define BROWSER_IE          4
#define BROWSER_EDGE        5
#define BROWSER_SAMSUNG     6
#define BROWSER_MINUI       7
#define BROWSER_OPERA       8
#define BROWSER_YANDEX      9
#define BROWSER_UC          10
#define BROWSER_FIREFOX     11
#define BROWSER_HUAWEI      12
#define BROWSER_WEBVIEW             20
#define BROWSER_WEBVIEW_FACEBOOK    21
#define BROWSER_WEBVIEW_INSTAGRAM   22
#define BROWSER_WEBVIEW_SNAPCHAT    23
#define BROWSER_WEBVIEW_GOOGLE      24
#define BROWSER_GOOGLEBOT           30

typedef struct {
	void * uaa;
	char * ua;
	int evironment;
	int browser;
}uainfo;

USER_AGENT_ANALYSER create_envirenment_browser_uaa(int cache_size) {
	char * fields[] = { DEVICE_CLASS, AGENT_NAME, WEBVIEW_APP_NAME, NULL };
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
    const char * webviewApp = results[2];
    if(0 == strcmp(agentName,"Chrome"))
        info->browser = BROWSER_CHROME;
    else if(0 == strcmp(agentName,"Mozilla"))
        info->browser = BROWSER_MOZILLA;
    else if(0 == strcmp(agentName,"Safari"))
        info->browser = BROWSER_SAFARI;
    else if(0 == strcmp(agentName,"Internet Explorer"))
        info->browser = BROWSER_IE;
    else if(0 == strcmp(agentName,"Edge") || 0 == strcmp(agentName,"Edge Webview"))
        info->browser = BROWSER_EDGE;
    else if(0 == strcmp(agentName,"SamsungBrowser") || 0 == strcmp(webviewApp,"SamsungBrowser"))
        info->browser = BROWSER_SAMSUNG;
    else if(0 == strcmp(agentName,"Opera") || 0 == strcmp(webviewApp,"Opera"))
        info->browser = BROWSER_OPERA;
    else if(0 == strcmp(agentName,"Firefox"))
        info->browser = BROWSER_FIREFOX;
    else if(0 == strcmp(agentName,"MiuiBrowser"))
        info->browser = BROWSER_MINUI;
    else if(0 == strcmp(agentName,"YaBrowser"))
        info->browser = BROWSER_YANDEX;
    else if(0 == strcmp(agentName,"HuaweiBrowser"))
        info->browser = BROWSER_HUAWEI;
    else if(0 == strcmp(agentName,"Chrome Webview") || 0 == strcmp(agentName,"UIWebView") || 0 == strcmp(agentName,"AppleWebKit") ||
            0 == strcmp(agentName,"NewsBreak") ||
            strstr(agentName,"WebViewApp") == agentName) // start with "WebViewApp"
        info->browser = BROWSER_WEBVIEW;
    else if(0 == strcmp(deviceClass,"Robot") || strstr(agentName,"Googlebot") == agentName)
        info->browser = BROWSER_GOOGLEBOT;
    else
        info->browser = BROWSER_OTHER;

    if(info->browser == BROWSER_OTHER || info->browser == BROWSER_WEBVIEW) {
        if (0 == strcmp(webviewApp,"AgentWeb"))
            info->browser = BROWSER_UC;
        else if (0 == strcmp(webviewApp,"Facebook App for Android") || 0 == strcmp(webviewApp,"Facebook App for iOS") || 0 == strcmp(webviewApp,"Facebook EMA"))
            info->browser = BROWSER_WEBVIEW_FACEBOOK;
        else if (0 == strcmp(agentName,"Instagram") || 0 == strcmp(webviewApp,"Instagram"))
            info->browser = BROWSER_WEBVIEW_INSTAGRAM;
        else if (0 == strcmp(webviewApp,"Google Search App"))
            info->browser = BROWSER_WEBVIEW_GOOGLE;
        else if (0 == strcmp(webviewApp,"Snapchat"))
            info->browser = BROWSER_WEBVIEW_SNAPCHAT;
    }
	return 1;
}
*/
import "C"

import (
	"sync"
	"unsafe"
)

var uaa unsafe.Pointer
var lock sync.Mutex

func init() {
	cacheSize := 0
	uaa = unsafe.Pointer(C.create_envirenment_browser_uaa(C.int(cacheSize)))
}

// set cache size
func CacheSize(cacheSize int) {
	lock.Lock()
	C.user_agent_analyser_free(C.USER_AGENT_ANALYSER(uaa))
	uaa = unsafe.Pointer(C.create_envirenment_browser_uaa(C.int(cacheSize)))
	lock.Unlock()
}

// get envrenment and browser from ua
func GetEnvirenmentBrowser(ua string) (evironment, browser int) {
	uainfo := new(C.uainfo)
	uainfo.uaa = uaa
	uainfo.ua = C.CString(ua)
	C.get_envirenment_browser(uainfo)
	return int(uainfo.evironment), int(uainfo.browser)
}
