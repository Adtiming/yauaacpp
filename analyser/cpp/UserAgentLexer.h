
// Generated from UserAgent.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"


namespace ycpp {


class  UserAgentLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, QUOTE1 = 2, QUOTE2 = 3, QUOTE3 = 4, QUOTE4 = 5, BAD_ESC_TAB = 6, 
    MIME_TYPE_1 = 7, MIME_TYPE_2 = 8, SPACE = 9, USERAGENT1 = 10, USERAGENT2 = 11, 
    EMAIL = 12, CURLYBRACEOPEN = 13, CURLYBRACECLOSE = 14, BRACEOPEN = 15, 
    BRACECLOSE = 16, BLOCKOPEN = 17, BLOCKCLOSE = 18, SEMICOLON = 19, COLON = 20, 
    COMMA = 21, SLASH = 22, EQUALS = 23, MINUS = 24, PLUS = 25, UUID = 26, 
    URL = 27, SPECIALVERSIONWORDS = 28, UNASSIGNEDVARIABLE = 29, GIBBERISH = 30, 
    ATSIGN = 31, VERSION = 32, WORD = 33, BASE64 = 34
  };

  explicit UserAgentLexer(antlr4::CharStream *input);

  ~UserAgentLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace ycpp
