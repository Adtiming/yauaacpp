
// Generated from UserAgent.g4 by ANTLR 4.7.2

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

  UserAgentLexer(antlr4::CharStream *input);
  ~UserAgentLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace ycpp
