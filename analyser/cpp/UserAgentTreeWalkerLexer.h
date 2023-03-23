
// Generated from UserAgentTreeWalker.g4 by ANTLR 4.12.0

#pragma once


#include "antlr4-runtime.h"


namespace ycpp {


class  UserAgentTreeWalkerLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, PATHTOKENNAME = 17, VALUENAME = 18, VALUE = 19, 
    UP = 20, NEXT = 21, NEXT2 = 22, NEXT3 = 23, NEXT4 = 24, PREV = 25, PREV2 = 26, 
    PREV3 = 27, PREV4 = 28, DOT = 29, MINUS = 30, STAR = 31, IN = 32, NOTIN = 33, 
    NUMBER = 34, BLOCKOPEN = 35, BLOCKCLOSE = 36, BRACEOPEN = 37, BRACECLOSE = 38, 
    DOUBLEQUOTE = 39, COLON = 40, SEMICOLON = 41, SPACE = 42, NOTEQUALS = 43, 
    EQUALS = 44, CONTAINS = 45, NOTCONTAINS = 46, STARTSWITH = 47, ENDSWITH = 48, 
    BACKTOFULL = 49
  };

  explicit UserAgentTreeWalkerLexer(antlr4::CharStream *input);

  ~UserAgentTreeWalkerLexer() override;


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
