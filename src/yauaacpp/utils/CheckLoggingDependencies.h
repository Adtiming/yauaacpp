//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_CHECKLOGGINGDEPENDENCIES_H
#define YAUAACPP_CHECKLOGGINGDEPENDENCIES_H

#include "yauaacpp_def.h"

namespace ycpp {

    class CheckLoggingDependencies {
    public:
        class InvalidLoggingDependencyException : public antlr4::RuntimeException {
        public:
            InvalidLoggingDependencyException(const std::string & message):antlr4::RuntimeException(message) {
            }
        };

//        void verifyLog4j2Dependencies() {
//            try {
//                org.apache.logging.log4j.LogManager.getLogger("Verify Logging Dependencies (Log4J2)");
//            } catch (NoClassDefFoundError e) {
//                throw InvalidLoggingDependencyException("Failed loading Log4J2 (Not present)", e);
//            }
//        }
//
//        void verifySlf4jDependencies() {
//            try {
//                // Check slf4j (used by PublicSuffixMatcherLoader from httpclient)
//                org.slf4j.LoggerFactory.getLogger("Verify Logging Dependencies (Slf4j)");
//            } catch (NoClassDefFoundError e) {
//                throw InvalidLoggingDependencyException("Failed testing SLF4J (Not present)", e);
//            }
//        }
//
//        void verifyJCLDependencies() {
//            try {
//                // Check JCL (used by PathMatchingResourcePatternResolver from Springframework)
//                org.apache.commons.logging.LogFactory.getLog("Verify Logging Dependencies (JCL)");
//            } catch (NoClassDefFoundError e) {
//                throw InvalidLoggingDependencyException("Failed testing JCL (Not present)", e);
//            }
//        }

        /**
         * Checks if the logging dependencies needed for this library are available.
         * Throws an exception if something is wrong.
         */
        static void verifyLoggingDependencies() {
//            CheckLoggingDependencies ldt = new CheckLoggingDependencies();
//            ldt.verifyLog4j2Dependencies();
//            ldt.verifySlf4jDependencies();
//            ldt.verifyJCLDependencies();
        }
    };

}
#endif //YAUAACPP_CHECKLOGGINGDEPENDENCIES_H
