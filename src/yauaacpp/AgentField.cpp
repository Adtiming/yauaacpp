#include "AgentField.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    std::string MutableAgentField::getDefaultValue() const {
        return defaultValue;
    }

    void MutableAgentField::setValueForced(const std::string &newValue, long newConfidence) {
        this->confidence = newConfidence;

        if (newValue == NULL_VALUE) {
            this->value = "";
        } else {
            this->value = newValue;
        }
    }

    std::string AgentField::afToString() const {
        std::ostringstream stream;
        stream << "{ value:'" << getValue() << "', confidence:'" << getConfidence() << "', ";

        std::string defaultValue = getDefaultValue();
        if (defaultValue.empty()) {
            stream << "default:null, ";
        } else {
            stream <<"default:'" << getDefaultValue() << "', ";
        }
        stream << "isDefault:" << (isDefaultValue()?"true":"false") << " }";
        return stream.str();
    }

    size_t AgentField::afHashCode() const {
        static std::hash<std::string> hash_fn;
        size_t hashv = getConfidence();
        hashv = hashv*31 + hash_fn(getValue());
        hashv = hashv*31 + hash_fn(getDefaultValue());
        hashv = hashv*31 + isDefaultValue();
        return hashv;
    }

    bool AgentField::afEquals(const AgentField &agentField) const {
        if (this == &agentField) {
            return true;
        }
        return
                getConfidence() == agentField.getConfidence() &&
                getValue() == agentField.getValue() &&
                getDefaultValue() == agentField.getDefaultValue() &&
                isDefaultValue() == agentField.isDefaultValue();
    }
} // namespace ycpp