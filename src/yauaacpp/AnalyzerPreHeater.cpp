//
// Created by sunxg on 22-2-2.
//

#include <tool/tool.h>
#include "AnalyzerPreHeater.h"
#include "UserAgent.h"
#include "ImmutableUserAgent.h"

namespace ycpp {

    long AnalyzerPreHeater::preHeat(long preheatIterations, bool log) {
        if (PreHeatCases::USERAGENTS.empty()) {
            LOG::warn("NO PREHEAT WAS DONE. This should never occur.");
            return 0;
        }
        if (preheatIterations <= 0) {
            LOG::warn("NO PREHEAT WAS DONE. Simply because you asked for %ld to run.", preheatIterations);
            return 0;
        }
        if (preheatIterations > MAX_PRE_HEAT_ITERATIONS) {
            LOG::warn("NO PREHEAT WAS DONE. Simply because you asked for too many (%ld > %ld) to run.", preheatIterations, MAX_PRE_HEAT_ITERATIONS);
            return 0;
        }
        if (log) {
            LOG::info("Preheating JVM by running %ld testcases.", preheatIterations);
        }
        long remainingIterations = preheatIterations;
        long goodResults = 0;
        while (remainingIterations > 0) {
            for (const std::string & userAgentString : PreHeatCases::USERAGENTS) {
                remainingIterations--;
                // Calculate and use result to guarantee not optimized away.
                if(!parse(userAgentString)->hasSyntaxError()) {
                    goodResults++;
                }
                if (remainingIterations <= 0) {
                    break;
                }
            }
        }
        if (log) {
            LOG::info("Preheating JVM completed. (%ld of %ld were proper results)", goodResults, preheatIterations);
        }
        return preheatIterations;
    }
}