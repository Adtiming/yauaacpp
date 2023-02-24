//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_CALCULATEAGENTEMAIL_H
#define YAUAACPP_CALCULATEAGENTEMAIL_H

#include "yauaacpp_def.h"

namespace ycpp {
    class CalculateAgentEmail : public FieldCalculator {
    public:
    void calculate(std::shared_ptr<MutableUserAgent> userAgent) override {
        // The email address is a mess
        const AgentField & email = userAgent->get(AGENT_INFORMATION_EMAIL);
        if (!email.isDefaultValue()) {
            userAgent->setForced(
                    AGENT_INFORMATION_EMAIL,
                    Normalize::email(email.getValue()),
                    email.getConfidence());
        }
    }


    std::string getCalculatedFieldName() {
        return AGENT_INFORMATION_EMAIL;
    }
};
}
#endif //YAUAACPP_CALCULATEAGENTEMAIL_H
