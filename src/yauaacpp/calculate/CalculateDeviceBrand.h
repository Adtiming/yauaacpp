//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_CALCULATEDEVICEBRAND_H
#define YAUAACPP_CALCULATEDEVICEBRAND_H

#include <utils/HostnameExtracter.h>
#include "yauaacpp_def.h"

namespace ycpp {

    class CalculateDeviceBrand : public FieldCalculator {

    private:
        std::string determineDeviceBrand(UserAgent * userAgent) {
            // If no brand is known but we do have a URL then we assume the hostname to be the brand.
            // We put this AFTER the creation of the DeviceName because we choose to not have
            // this brandname in the DeviceName.

            std::string deviceBrand;

            const AgentField & informationUrl = userAgent->get(AGENT_INFORMATION_URL);
            if (!informationUrl.isDefaultValue()) {
                deviceBrand = HostnameExtracter::extractBrandFromUrl(informationUrl.getValue());
            }

            if (!deviceBrand.empty()) {
                return deviceBrand;
            }

            const AgentField & informationEmail = userAgent->get(AGENT_INFORMATION_EMAIL);
            if (!informationEmail.isDefaultValue()) {
                deviceBrand = HostnameExtracter::extractBrandFromEmail(informationEmail.getValue());
            }

            return deviceBrand;
        }

        void calculate(std::shared_ptr<MutableUserAgent> userAgent) override {
            // The device brand field is a mess.
            const AgentField & deviceBrand = userAgent->get(DEVICE_BRAND);
            if (deviceBrand.isDefaultValue()) {
                // If no brand is known then try to extract something that looks like a Brand from things like URL and Email addresses.
                std::string newDeviceBrand = determineDeviceBrand(userAgent.get());
                if (!newDeviceBrand.empty()) {
                    userAgent->setForced(
                            DEVICE_BRAND,
                            newDeviceBrand,
                            0);
                } else {
                    userAgent->setForced(
                            DEVICE_BRAND,
                            NULL_VALUE,
                            0);
                }
            } else {
                userAgent->setForced(
                        DEVICE_BRAND,
                        Normalize::brand(deviceBrand.getValue()),
                        deviceBrand.getConfidence());
            }
        }




        std::string getCalculatedFieldName() {
            return DEVICE_BRAND;
        }


        std::set<std::string> getDependencies() {
            std::set<std::string> t;
            t.emplace(AGENT_INFORMATION_URL);
            t.emplace(AGENT_INFORMATION_EMAIL);
            return t;
        }
    };
}
#endif //YAUAACPP_CALCULATEDEVICEBRAND_H
