#include "AgentField.h"
#include "yauaa_c.h"
#include "yauaacpp.h"

using namespace ycpp;

std::recursive_mutex g_ycpp_lock;


typedef struct {
    std::recursive_mutex lock;
    std::shared_ptr<ycpp::AbstractUserAgentAnalyzerDirect> uaa;
    std::vector<std::string> fields;
    std::vector<std::string> result[YAUAA_C_MAX_THREAD_NUM];
} USER_AGENT_ANALYSER_INNER;

// with_fileds, DEVICE_CLASS,AGENT_NAME etc, NULL is end flag.
// cache_size, 0- no cache, other value is cache size
USER_AGENT_ANALYSER user_agent_analyser_create(char * with_fileds [], int cache_size)
{
    g_ycpp_lock.lock();
    USER_AGENT_ANALYSER_INNER * inner = new USER_AGENT_ANALYSER_INNER;
    auto builder = UserAgentAnalyzer::newBuilder();

    char * field = nullptr;
    while( (field = *with_fileds++) != nullptr) {
        inner->fields.push_back(field);
        builder->withField(field);
    }

    inner->uaa = builder->build();

    g_ycpp_lock.unlock();

    return (USER_AGENT_ANALYSER * )inner;
}


void user_agent_analyser_free(USER_AGENT_ANALYSER uaa)
{
    g_ycpp_lock.lock();
    USER_AGENT_ANALYSER_INNER * inner = (USER_AGENT_ANALYSER_INNER *) uaa;
    delete inner;
    g_ycpp_lock.unlock();
}

void user_agent_analyser_parse(USER_AGENT_ANALYSER uaa, const char * ua, const char * result [])
{
    static int g_rtbcore_thread_cnt = 0;
    static __thread int threadidx = -1;

    if(threadidx == -1){
        g_ycpp_lock.lock();
        if(threadidx == -1){
            if(g_rtbcore_thread_cnt >= YAUAA_C_MAX_THREAD_NUM)
                perror("reach max thread for yauaa c module");
            threadidx = g_rtbcore_thread_cnt;
            g_rtbcore_thread_cnt ++;
        }
        g_ycpp_lock.unlock();
    }

    USER_AGENT_ANALYSER_INNER * inner = (USER_AGENT_ANALYSER_INNER *) uaa;

    inner->result[threadidx].resize(inner->fields.size());
    std::shared_ptr<UserAgent> obj = inner->uaa->parse(std::string(ua));


    int i = 0;
    for(const std::string & field : inner->fields){
        inner->result[threadidx][i] = obj->getValue(field);
        result[i] = inner->result[threadidx][i].c_str();
        i++;
    }
    result[i] = nullptr;
}