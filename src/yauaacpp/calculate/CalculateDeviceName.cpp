//
// Created by sunxg on 22-2-4.
//

#include "CalculateDeviceName.h"
#include "ImmutableUserAgent.h"

namespace ycpp {
    std::regex CalculateDeviceName::CLEAN_1_PATTERN("AppleWebKit", std::regex::icase);

    void CalculateDeviceName::calculate(std::shared_ptr<MutableUserAgent>userAgent) {
        // Make sure the DeviceName always starts with the DeviceBrand
        const AgentField & deviceName = userAgent->get(DEVICE_NAME);
        if (!deviceName.isDefaultValue()) {
            const AgentField & deviceBrand = userAgent->get(DEVICE_BRAND);
            std::string deviceNameValue = removeBadSubStrings(deviceName.getValue());
            std::string deviceBrandValue = deviceBrand.getValue();
            if (deviceName.getConfidence() >= 0 &&
                deviceBrand.getConfidence() >= 0 &&
                deviceBrandValue != UNKNOWN_VALUE) {
                // In some cases it does start with the brand but without a separator following the brand
                deviceNameValue = Normalize::cleanupDeviceBrandName(deviceBrandValue, deviceNameValue);
            } else {
                deviceNameValue = Normalize::brand(deviceNameValue);
            }

            userAgent->setForced(
                    DEVICE_NAME,
                    deviceNameValue,
                    deviceName.getConfidence());
        }
    }
}