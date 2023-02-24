//
// Created by sunxg on 22-1-29.
//

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
