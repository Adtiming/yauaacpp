//
// Created by sunxg on 22-1-29.
//

#ifndef YAUAACPP_ANTLRUTILS_H
#define YAUAACPP_ANTLRUTILS_H

#include "yauaacpp_def.h"

namespace ycpp {
    class AntlrUtils {
    private:
        AntlrUtils() {}

        class InnerParserRuleContext : public antlr4::ParserRuleContext{
            std::string getText() {
                return "";
            }
        };

        static antlr4::tree::ParseTree * init() {
            return new InnerParserRuleContext();
        }

    public:
        static antlr4::tree::ParseTree * NULL_PARSE_TREE ;

        static std::string getSourceText(antlr4::ParserRuleContext * ctx);

    };

}
#endif //YAUAACPP_ANTLRUTILS_H
