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
