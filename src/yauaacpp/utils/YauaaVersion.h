//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_YAUAAVERSION_H
#define YAUAACPP_YAUAAVERSION_H

#include "yauaacpp_def.h"

namespace ycpp {
    class NodeTuple;

    class YauaaVersion {

    private:
        YauaaVersion() {
        }
        static std::string padding(char letter, int count) {
            std::stringstream o;
            for (int i = 0; i < count; i++) {
                o<<letter;
            }
            return o.str();
        }

        static void logLine(const std::string & line, int width);

    public:
        class AbstractVersion {
        public:
            virtual std::string getGitCommitId() const = 0;
            virtual std::string getGitCommitIdDescribeShort() const = 0;
            virtual std::string getBuildTimeStamp() const = 0;
            virtual std::string getProjectVersion() const = 0;
            virtual std::string getCopyright() const = 0;
            virtual std::string getLicense() const = 0;
            virtual std::string getUrl() const = 0;
            virtual std::string getBuildJDKVersion() const = 0;
            virtual std::string getTargetJREVersion() const = 0;


            bool equals(AbstractVersion * o);


            std::string toString() const {
                std::ostringstream o;
                o << "Yauaa " << getProjectVersion() <<
                       " (" << getGitCommitIdDescribeShort() << " @ " << getBuildTimeStamp() <<
                       " [JDK:"<<getBuildJDKVersion()<<";JRE:"<<getTargetJREVersion()<<"])";
                return o.str();
            }
        };

//        static void logVersion(const std::string &... extraLines) {
//            logVersion(Arrays.asList(extraLines));
//        }

        static void logVersion(std::list<std::string> extraLines);


        static std::string getVersion();

        static std::string getVersion(const AbstractVersion * version) {
            return getVersion(version->getProjectVersion(), version->getGitCommitIdDescribeShort(), version->getBuildTimeStamp());
        }

        static std::string getVersion(const std::string & projectVersion, const std::string & gitCommitIdDescribeShort, const std::string & buildTimestamp) {
            return "Yauaa " + projectVersion + " (" + gitCommitIdDescribeShort + " @ " + buildTimestamp + ")";
        }

        static std::string getVersion(const std::string & projectVersion, const std::string & gitCommitIdDescribeShort, const std::string & buildTimestamp, const std::string & buildJDKVersion, const std::string & targetJREVersion) {
            return "Yauaa " + projectVersion + " (" + gitCommitIdDescribeShort + " @ " + buildTimestamp + " [JDK:"+buildJDKVersion+";JRE:"+targetJREVersion+"])";
        }

    private:
        class RulesVersion : public AbstractVersion {
        private:
            std::string gitCommitId              = "<undefined>";
            std::string gitCommitIdDescribeShort = "<undefined>";
            std::string buildTimeStamp           = "<undefined>";
            std::string projectVersion           = "<undefined>";
            std::string copyright                = "<undefined>";
            std::string license                  = "<undefined>";
            std::string url                      = "<undefined>";
            std::string buildJDKVersion          = "<undefined>";
            std::string targetJREVersion         = "<undefined>";

        public:
            std::string getGitCommitId() const {
                return gitCommitId;
            }


            std::string getGitCommitIdDescribeShort() const {
                return gitCommitIdDescribeShort;
            }


            std::string getBuildTimeStamp() const {
                return buildTimeStamp;
            }


            std::string getProjectVersion() const {
                return projectVersion;
            }


            std::string getCopyright() const {
                return copyright;
            }


            std::string getLicense() const {
                return license;
            }


            std::string getUrl() const {
                return url;
            }


            std::string getBuildJDKVersion() const {
                return buildJDKVersion;
            }


            std::string getTargetJREVersion() const {
                return targetJREVersion;
            }

            RulesVersion(NodeTuple * versionNodeTuple, const std::string & filename);
        };

        static void assertSameVersion(NodeTuple * versionNodeTuple, const std::string & filename);

        static void assertSameVersion(AbstractVersion * libraryVersion, AbstractVersion  * rulesVersion);

    };

}
#endif //YAUAACPP_YAUAAVERSION_H
