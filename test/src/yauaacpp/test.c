#include <stdio.h>
#include <stdlib.h>

#include <yauaacpp/yauaa_c.h>

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
