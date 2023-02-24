//
// Created by sunxg on 22-2-23.
//

#include "YamlUtils.h"
#include <tool/tool.h>

namespace ycpp {

    std::string YamlUtils::createErrorString(YAML::Node &node, const std::string &filename, const std::string &error) {
        return  "Yaml config problem.("+filename+":"+itos(node.Mark().line)+"): " + error;
    }

    const char *YamlUtils::getNodeTypeName(YAML::Node &node) {
        switch (node.Type()){
            case YAML::NodeType::Undefined:
                return "Undefined";
            case YAML::NodeType::Null:
                return "Null";
            case YAML::NodeType::Scalar:
                return "Null";
            case YAML::NodeType::Sequence:
                return "Null";
            case YAML::NodeType::Map:
                return "Null";
            default:
                return "Unexpected";
        }
    }

    std::list<std::string> YamlUtils::getStringValues(YAML::Node &sequenceNode, const std::string &filename) {
        requireNodeInstanceOf(YAML::NodeType::Sequence, sequenceNode, filename,
                              std::string("The provided node must be a sequence but it is a ") + getNodeTypeName(sequenceNode));

        for(size_t i=0; i<sequenceNode.size(); i++) {
            YAML::Node node = sequenceNode[i];
            requireNodeInstanceOf(YAML::NodeType::Scalar, node, filename,
                                  std::string("The value should be a string but it is a ") +
                                  getNodeTypeName(node));
        }
        return sequenceNode.as<std::list<std::string>>();
    }
}