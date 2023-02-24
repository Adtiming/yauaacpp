//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_CALCULATEAGENTNAME_H
#define YAUAACPP_CALCULATEAGENTNAME_H

#include "yauaacpp_def.h"
#include "utils/Normalize.h"

namespace ycpp {

    class CalculateAgentName : public FieldCalculator {
    public:
        void calculate(std::shared_ptr<MutableUserAgent> userAgent) override {
            // Cleanup the name of the useragent
            const AgentField * name = & userAgent->get(AGENT_NAME);
            if (name->isDefaultValue()) {
                name = & userAgent->get(DEVICE_BRAND);
                if (name->isDefaultValue()) {
                    userAgent->setForced(
                            AGENT_NAME,
                            NULL_VALUE,
                            name->getConfidence());
                } else {
                    userAgent->setForced(
                            AGENT_NAME,
                            name->getValue(),
                            name->getConfidence());
                }
                return;
            }

            std::string value = name->getValue();
            if (Normalize::isLowerCase(value)) {
                long confidence = name->getConfidence();
                if (confidence < 0) {
                    confidence = 0;
                }
                userAgent->setForced(
                        AGENT_NAME,
                        Normalize::brand(value),
                        confidence);
            }
        }


        std::string getCalculatedFieldName() {
            return AGENT_NAME;
        }


        std::set<std::string> getDependencies() {
            std::set<std::string> t;
            t.emplace(DEVICE_BRAND);
            return t;
        }
    };
}
#endif //YAUAACPP_CALCULATEAGENTNAME_H
