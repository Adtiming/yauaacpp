//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_YAMLUTILS_H
#define YAUAACPP_YAMLUTILS_H

#include "yauaacpp_def.h"
#include <yaml-cpp/yaml.h>
#include <analyze/InvalidParserConfigurationException.h>

namespace ycpp {

    class YamlUtils {
    private:
        YamlUtils() {}
        static std::string createErrorString(YAML::Node & node, const std::string & filename, const std::string & error);
    public:
        static void requireNodeInstanceOf(YAML::NodeType::value node_type,YAML::Node & node, const std::string & filename, const std::string & error) {
            if (node_type != node.Type()) {
                throw InvalidParserConfigurationException(
                        createErrorString(node, filename, error));
            }
        }

        static void require(bool condition, YAML::Node & node, const std::string & filename, const std::string & error) {
            if (!condition) {
                throw InvalidParserConfigurationException(
                        createErrorString(node, filename, error));
            }
        }



        static YAML::Node::iterator getExactlyOneNodeTuple(YAML::Node & mappingNode, const std::string & filename) {
            assert(mappingNode.IsMap());

            require(mappingNode.size() == 1, mappingNode, filename,
                    "There must be exactly 1 value in the list");
            return mappingNode.begin();
        }

        static std::string getKeyAsString(YAML::Node::iterator & tuple, const std::string & filename) {
            YAML::Node & keyNode = tuple->first;
            requireNodeInstanceOf(YAML::NodeType::Scalar, keyNode, filename,
                    std::string("The key should be a string but it is a ") + getNodeTypeName(keyNode));
            return keyNode.as<std::string>();
        }

        static std::string getValueAsString(YAML::Node::iterator & tuple, const std::string & filename) {
            YAML::Node & valueNode = tuple->second;
            char buf[100];
            sprintf(buf,"The value should be a string but it is a %d", valueNode.Type());
            requireNodeInstanceOf(YAML::NodeType::Scalar, valueNode, filename,buf);
            return valueNode.as<std::string>();
        }

        static YAML::Node getValueAsMappingNode(YAML::Node::iterator & tuple, const std::string & filename) {
            YAML::Node valueNode = tuple->second;
            requireNodeInstanceOf(YAML::NodeType::Map, valueNode, filename,
                                  std::string("The value should be a map but it is a ") + getNodeTypeName(valueNode));
            return valueNode;
        }

        static YAML::Node getValueAsSequenceNode(YAML::Node::iterator & tuple, const std::string & filename) {
            YAML::Node valueNode = tuple->second;
            requireNodeInstanceOf(YAML::NodeType::Sequence, valueNode, filename,
                                  std::string("The value should be a sequence but it is a ") + getNodeTypeName(valueNode));
            return valueNode;
        }

        static std::list<std::string> getStringValues(YAML::Node & sequenceNode, const std::string & filename);

        static const char * getNodeTypeName(YAML::Node & node);

    };


}
#endif //YAUAACPP_YAMLUTILS_H
