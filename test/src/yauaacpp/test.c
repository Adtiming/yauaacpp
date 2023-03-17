#include <stdio.h>
#include <stdlib.h>

#include <yauaacpp/yauaa_c.h>

int main(int argc, char * argv[])
{
    char * ua = "Mozilla/5.0 (Linux; Android 13; SM-G981U Build/TP1A.220624.014; wv) AppleWebKit/537.36 (KHTML, like Gecko) Version/4.0 Chrome/110.0.5481.153 Mobile Safari/537.36 [FB_IAB/FB4A;FBAV/405.1.0.28.72;]";
    char * fields[] = { DEVICE_CLASS, AGENT_NAME, WEBVIEW_APP_NAME, NULL };
    const char * results[3];
    const char * ps;

    USER_AGENT_ANALYSER uaa = user_agent_analyser_create(fields, 0);

    user_agent_analyser_parse(uaa, ua, results);
    int i=0;
    while( (ps = results[i++]) != NULL) printf("%d:%s\n",i,ps);
    user_agent_analyser_free(uaa);
}
