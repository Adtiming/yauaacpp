//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_CALCULATENETWORKTYPE_H
#define YAUAACPP_CALCULATENETWORKTYPE_H

#include "yauaacpp_def.h"

namespace ycpp {
    class CalculateNetworkType : public FieldCalculator {
    public:

    void calculate(std::shared_ptr<MutableUserAgent> userAgent) override {
        // Make sure the DeviceName always starts with the DeviceBrand
        const AgentField & networkType = userAgent->get(NETWORK_TYPE);
        if (!networkType.isDefaultValue()) {
            userAgent->setForced(
                    NETWORK_TYPE,
                    Normalize::brand(networkType.getValue()),
                    networkType.getConfidence());
        }
    }


    std::string getCalculatedFieldName() {
        return NETWORK_TYPE;
    }


    std::string toString() {
        return std::string("Calculate ") + NETWORK_TYPE;
    }

};

}
#endif //YAUAACPP_CALCULATENETWORKTYPE_H
