//
// Created by sunxg on 22-2-4.
//

#include <analyze/InvalidParserConfigurationException.h>
#include "YauaaVersion.h"
#include "tool/tool.h"

namespace ycpp {
#define URL             "https://github.com/Adtiming/yauaacpp"
#define COPYRIGHT       "copy right"
#define LICENSE         "license"

    struct Version :public YauaaVersion{
    };

    void YauaaVersion::logVersion(std::list<std::string> extraLines) {
        const char * lines[] = {
                "For more information: " URL,
                COPYRIGHT " - " LICENSE
        };
        std::string version = getVersion();
        size_t width = version.length();
        for (const std::string & line : lines) {
            width = std::max(width, line.length());
        }
        for (const std::string & line : extraLines) {
            width = std::max(width, line.length());
        }

        std::string padding = YauaaVersion::padding('-', width);

        LOG::error( "");
        LOG::error( "/-%s-\\", padding.c_str());
        logLine(version, width);
        LOG::error( "+-%s-+", padding.c_str());
        for (const std::string & line : lines) {
            logLine(line, width);
        }
        if (!extraLines.empty()) {
            LOG::error( "+-%s-+", padding.c_str());
            for (const std::string & line : extraLines) {
                logLine(line, width);
            }
        }

        LOG::error( "\\-%s-/", padding.c_str());
        LOG::error( "");
    }

    std::string YauaaVersion::getVersion() {
        //return getVersion(Version.getInstance());
        return "Yauaa : 6.6";
    }

    void YauaaVersion::assertSameVersion(YauaaVersion::AbstractVersion *libraryVersion,
                                         YauaaVersion::AbstractVersion *rulesVersion) {
        if (libraryVersion->equals(rulesVersion)) {
            return;
        }
        LOG::error("===============================================");
        LOG::error("==========        FATAL ERROR       ===========");
        LOG::error("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv");
        LOG::error("");
        LOG::error("Two different Yauaa versions have been loaded:");
        LOG::error("Runtime Library: %s", libraryVersion->toString().c_str());
        LOG::error("Rule sets      : %s", rulesVersion->toString().c_str());
        LOG::error("");
        LOG::error("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        LOG::error("===============================================");

        throw InvalidParserConfigurationException(std::string("Two different Yauaa versions have been loaded: \n") +
                                                      "Runtime Library: " + libraryVersion->toString() + "\n" +
                                                      "Rule sets      : " + rulesVersion->toString() + "\n");
    }

    void YauaaVersion::assertSameVersion(NodeTuple * versionNodeTuple, const std::string &filename) {
        //RulesVersion * rulesVersion = new RulesVersion(versionNodeTuple, filename);
        //assertSameVersion(Version.getInstance(), rulesVersion);
    }

    void YauaaVersion::logLine(const std::string &line, int width) {
        if (LOG::isInfoEnabled()) {
            LOG::error( "| %s%s |", line.c_str(), padding(' ', width - line.length()).c_str());
        }
    }

    bool YauaaVersion::AbstractVersion::equals(YauaaVersion::AbstractVersion *o) {
        if (this == o) {
            return true;
        }
        if (nullptr == dynamic_cast<AbstractVersion*>(o)) {
            return false;
        }
        AbstractVersion * version = (AbstractVersion*) o;
        return
                getGitCommitId()              == version->getGitCommitId() &&
                getGitCommitIdDescribeShort() == version->getGitCommitIdDescribeShort() &&
                getBuildTimeStamp()           == version->getBuildTimeStamp() &&
                getProjectVersion()           == version->getProjectVersion() &&
                getCopyright()                == version->getCopyright() &&
                getLicense()                  == version->getLicense() &&
                getUrl()                      == version->getUrl() &&
                getBuildJDKVersion()          == version->getBuildJDKVersion() &&
                getTargetJREVersion()         == version->getTargetJREVersion();
    }

    YauaaVersion::RulesVersion::RulesVersion(NodeTuple * versionNodeTuple, const std::string &filename) {
/*
        // Check the version information from the Yaml files
        SequenceNode versionNode = getValueAsSequenceNode(versionNodeTuple, filename);

        std::list<Node> versionList = versionNode.getValue();
        for (Node versionEntry : versionList) {
            requireNodeInstanceOf(YAML::NodeType::Map, versionEntry, filename, "The entry MUST be a mapping");
            NodeTuple entry = getExactlyOneNodeTuple((MappingNode) versionEntry, filename);
            std::string key = getKeyAsString(entry, filename);
            std::string value = getValueAsString(entry, filename);
            switch (key) {
                case "git_commit_id":
                    gitCommitId = value;
                    break;
                case "git_commit_id_describe_short":
                    gitCommitIdDescribeShort = value;
                    break;
                case "build_timestamp":
                    buildTimeStamp = value;
                    break;
                case "project_version":
                    projectVersion = value;
                    break;
                case "license":
                    license = value;
                    break;
                case "copyright":
                    copyright = value;
                    break;
                case "url":
                    url = value;
                    break;
                case "buildJDKVersion":
                    buildJDKVersion = value;
                    break;
                case "targetJREVersion":
                    targetJREVersion = value;
                    break;
                default:
                    throw InvalidParserConfigurationException(
                            "Yaml config.(" + filename + ":" + versionNode.getStartMark().getLine() + "): " +
                            "Found unexpected config entry: " + key + ", allowed are " +
                            "'git_commit_id_describe_short', 'build_timestamp' and 'project_version'");
            }
        }
*/
    }
}