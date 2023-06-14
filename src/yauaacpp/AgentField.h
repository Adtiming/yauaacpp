/*
 * Yet Another UserAgent Analyzer cpp version
 * Copyright (C) 2023 Adtiming
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */



#ifndef BEARKNOCKS_AGENT_FIELD_H
#define BEARKNOCKS_AGENT_FIELD_H

#include "yauaacpp_def.h"
#include <iostream>
#include <sstream>

namespace ycpp{

    struct AgentField {
        virtual ~AgentField(){};

        /**
         * What is the value we have for this field?
         * If we do not know you'll get the default value that has been defined (which may be null).
         */
        virtual std::string getValue() const = 0;

        /**
         * @return How certain are we about this value?
         * &lt;0 : We are uncertain.
         * 0&gt;= : The higher the more confident.
         */
        virtual long getConfidence() const = 0;

        /**
         * @return Is the value you are getting the default (i.e. we do not know what this is)?
         */
        virtual bool isDefaultValue() const = 0;

        /**
         * @return The default value for this field in case we do not know what this is.
         */
        virtual std::string getDefaultValue() const = 0;

        bool afEquals(const AgentField & agentField) const;


        std::string afToString() const;

        size_t afHashCode() const;

    };

    struct MutableAgentField : public AgentField {
        std::string defaultValue;
        std::string value;
        long confidence;

        MutableAgentField(const std::string & defaultValue) {
            this->defaultValue = defaultValue;
            reset();
        }

        void reset() {
            value = "";
            confidence = -1;
        }

        std::string getValue() const override {
            if (value.empty()) {
                return defaultValue;
            }
            return value;
        }

        bool isDefaultValue() const override {
            return confidence < 0 || value.empty();
        }


        std::string getDefaultValue() const override;

        long getConfidence() const override {
            return confidence;
        }

        bool setValue(MutableAgentField field) {
            return setValue(field.value, field.confidence);
        }

        bool setValue(const std::string & newValue, long newConfidence) {
            if (newConfidence > this->confidence) {
                setValueForced(newValue, newConfidence);
                return true;
            }
            return false;
        }

        void setValueForced(const std::string & newValue, long newConfidence);

        bool equals(AgentField & o) const {
            return afEquals(o);
        }


        virtual std::string toString() const {
            return afToString();
        }
    };

    struct ImmutableAgentField : public AgentField {
        std::string value;
        long confidence;
        bool _isDefaultValue;
        std::string defaultValue;

        explicit ImmutableAgentField(){
            confidence = 0;
            _isDefaultValue = false;
        }
        explicit ImmutableAgentField(const std::string & value, long confidence, bool isDefaultValue, const std::string & defaultValue) {
            this->value = value;
            this->confidence = confidence;
            this->_isDefaultValue = isDefaultValue;
            this->defaultValue = defaultValue;
        }

        explicit ImmutableAgentField(const MutableAgentField & agentField) {
            value = agentField.getValue();
            confidence = agentField.getConfidence();
            _isDefaultValue = agentField.isDefaultValue();
            defaultValue = agentField.getDefaultValue();
        }


        std::string getValue() const override {
            return value;
        }


        long getConfidence() const override {
            return confidence;
        }


        bool isDefaultValue() const override {
            return _isDefaultValue;
        }


        std::string getDefaultValue() const override {
            return defaultValue;
        }

        std::string toString() const {
            return afToString();
        }

        bool save(FILE * fout);
        bool load(FILE * fin);
    };
} // namespace ycpp

#endif