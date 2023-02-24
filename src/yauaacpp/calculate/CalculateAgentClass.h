//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_CALCULATEAGENTCLASS_H
#define YAUAACPP_CALCULATEAGENTCLASS_H

#include "yauaacpp_def.h"

namespace ycpp {
    class CalculateAgentClass : public FieldCalculator {

    public:
        void calculate(std::shared_ptr<MutableUserAgent> userAgent) override {
            // Cleanup the class of the useragent
            const AgentField & agentClass = userAgent->get(AGENT_CLASS);
            if (agentClass.isDefaultValue()) {
                const AgentField & agentName = userAgent->get(AGENT_NAME);
                if (!agentName.isDefaultValue()) {
                    userAgent->setForced(
                            AGENT_CLASS,
                            "Special",
                            1);
                }
            }
        }


        std::string getCalculatedFieldName() {
            return AGENT_CLASS;
        }


        std::set<std::string> getDependencies() {
            std::set<std::string> t;
            t.emplace(AGENT_NAME);
            return t;
        }
    };
}
#endif //YAUAACPP_CALCULATEAGENTCLASS_H
