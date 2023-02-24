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
