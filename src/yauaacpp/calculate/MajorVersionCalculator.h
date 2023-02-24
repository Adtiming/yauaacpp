//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_MAJORVERSIONCALCULATOR_H
#define YAUAACPP_MAJORVERSIONCALCULATOR_H

#include "yauaacpp_def.h"

namespace ycpp {

    class MajorVersionCalculator : public FieldCalculator {
    private:
        std::string versionName;
        std::string majorVersionName;
        MajorVersionCalculator() { }

    public:
        MajorVersionCalculator(const std::string & majorVersionName, const std::string & versionName) {
            this->majorVersionName = majorVersionName;
            this->versionName = versionName;
        }

        void calculate(std::shared_ptr<MutableUserAgent> userAgent) override {
            const AgentField & agentVersionMajor = userAgent->get(majorVersionName);
            if (agentVersionMajor.isDefaultValue()) {
                const AgentField & agentVersion = userAgent->get(versionName);
                std::string version = NULL_VALUE;
                if (!agentVersion.isDefaultValue()) {
                    version = VersionSplitter::getInstance()->getSingleSplit(agentVersion.getValue(), 1);
                }
                userAgent->setForced(
                        majorVersionName,
                        version,
                        agentVersion.getConfidence());
            }
        }


        std::string getCalculatedFieldName() {
            return majorVersionName;
        }


        std::set<std::string> getDependencies() {
            std::set<std::string> t;
            t.insert(versionName);
            return t;
        }


        std::string toString() {
            return "Calculate " + versionName + " --> " + majorVersionName;
        }
    };

}
#endif //YAUAACPP_MAJORVERSIONCALCULATOR_H
