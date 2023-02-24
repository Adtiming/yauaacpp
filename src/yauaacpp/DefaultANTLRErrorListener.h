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

#ifndef YAUAACPP_DEFAULT_ANTL_RTERROR_LISTENER_H
#define YAUAACPP_DEFAULT_ANTL_RTERROR_LISTENER_H


#include "yauaacpp_def.h"

#include <ANTLRErrorListener.h>

namespace ycpp {

    class DefaultANTLRErrorListener:virtual public antlr4::ANTLRErrorListener {
        void
        reportAmbiguity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
                        bool exact,
                        const antlrcpp::BitSet &ambigAlts, antlr4::atn::ATNConfigSet *configs) {
            // Ignore this always.
        }

        void reportAttemptingFullContext(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex,
                                         size_t stopIndex,
                                         const antlrcpp::BitSet &conflictingAlts, antlr4::atn::ATNConfigSet *configs) {
            // Ignore this always.
        }

        void reportContextSensitivity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex,
                                      size_t stopIndex,
                                      size_t prediction, antlr4::atn::ATNConfigSet *configs) {
            // Ignore this always.
        }
    };
}

#endif //YAUAACPP_DEFAULT_ANTL_RTERROR_LISTENER_H
