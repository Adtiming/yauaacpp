//
// Created by sunxg on 22-2-2.
//

#ifndef YAUAACPP_ANALYZERPREHEATER_H
#define YAUAACPP_ANALYZERPREHEATER_H

#include "antlr4-runtime.h"
#include "analyze/Analyzer.h"
#include "PreHeatCases.h"

namespace ycpp {
    class AnalyzerPreHeater : virtual public Analyzer {

    public:
        /**
         * Runs all testcases once to heat up the JVM.
         * @return Number of actually done testcases.
         */
        long preHeat() {
            return preHeat(PreHeatCases::USERAGENTS.size(), true);
        }
        /**
         * Runs the number of specified testcases to heat up the JVM.
         * @param preheatIterations Number of desired tests to run.
         * @return Number of actually done testcases.
         */
        long preHeat(long preheatIterations) {
            return preHeat(preheatIterations, true);
        }

        long MAX_PRE_HEAT_ITERATIONS = 1000000L;

        /**
         * Runs the number of specified testcases to heat up the JVM.
         * @param preheatIterations Number of desired tests to run.
         * @param log Enable logging?
         * @return Number of actually done testcases.
         */
        long preHeat(long preheatIterations, bool log);
    };
}

#endif //YAUAACPP_ANALYZERPREHEATER_H
