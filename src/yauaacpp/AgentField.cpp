#include "AgentField.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {
    bool save_string(FILE * fout, const std::string & s);
    bool load_string(FILE * fin, std::string & s);

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

    bool ImmutableAgentField::save(FILE * fout){
        save_string(fout,value);
        fwrite(&confidence,sizeof(confidence),1,fout);
        fwrite(&_isDefaultValue,sizeof(_isDefaultValue),1,fout);
        save_string(fout,defaultValue);
        return true;
    }

    bool ImmutableAgentField::load(FILE * fin){
        load_string(fin,value);
        if(1!=fread(&confidence,sizeof(confidence),1,fin)) return false;
        if(1!=fread(&_isDefaultValue,sizeof(_isDefaultValue),1,fin)) return false;
        if(!load_string(fin,defaultValue)) return false;
        return true;
    }
} // namespace ycpp