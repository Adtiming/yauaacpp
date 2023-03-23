
// Generated from UserAgentTreeWalker.g4 by ANTLR 4.12.0


#include "UserAgentTreeWalkerListener.h"
#include "UserAgentTreeWalkerVisitor.h"

#include "UserAgentTreeWalkerParser.h"


using namespace antlrcpp;
using namespace ycpp;

using namespace antlr4;

namespace {

struct UserAgentTreeWalkerParserStaticData final {
  UserAgentTreeWalkerParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  UserAgentTreeWalkerParserStaticData(const UserAgentTreeWalkerParserStaticData&) = delete;
  UserAgentTreeWalkerParserStaticData(UserAgentTreeWalkerParserStaticData&&) = delete;
  UserAgentTreeWalkerParserStaticData& operator=(const UserAgentTreeWalkerParserStaticData&) = delete;
  UserAgentTreeWalkerParserStaticData& operator=(UserAgentTreeWalkerParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag useragenttreewalkerParserOnceFlag;
UserAgentTreeWalkerParserStaticData *useragenttreewalkerParserStaticData = nullptr;

void useragenttreewalkerParserInitialize() {
  assert(useragenttreewalkerParserStaticData == nullptr);
  auto staticData = std::make_unique<UserAgentTreeWalkerParserStaticData>(
    std::vector<std::string>{
      "matcherRequire", "matcherExtract", "matcherVariable", "matcher", 
      "basePath", "path", "numberRange", "wordRange"
    },
    std::vector<std::string>{
      "", "'__SyntaxError__'", "'IsNull'", "'Concat'", "'NormalizeBrand'", 
      "'ExtractBrandFromUrl'", "'CleanVersion'", "'ReplaceString'", "'LookUp'", 
      "'IsInLookUp'", "'LookUpContains'", "'IsInLookUpContains'", "'LookUpPrefix'", 
      "'IsInLookUpPrefix'", "'IsNotInLookUpPrefix'", "'DefaultIfNull'", 
      "'agent'", "", "", "", "'^'", "'>'", "'>>'", "'>>>'", "'>>>>'", "'<'", 
      "'<<'", "'<<<'", "'<<<<'", "'.'", "'-'", "'*'", "'\\u003F'", "'\\u003F!'", 
      "", "'['", "']'", "'('", "')'", "'\"'", "':'", "';'", "", "'!='", 
      "'='", "'~'", "'!~'", "'{'", "'}'", "'@'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
      "PATHTOKENNAME", "VALUENAME", "VALUE", "UP", "NEXT", "NEXT2", "NEXT3", 
      "NEXT4", "PREV", "PREV2", "PREV3", "PREV4", "DOT", "MINUS", "STAR", 
      "IN", "NOTIN", "NUMBER", "BLOCKOPEN", "BLOCKCLOSE", "BRACEOPEN", "BRACECLOSE", 
      "DOUBLEQUOTE", "COLON", "SEMICOLON", "SPACE", "NOTEQUALS", "EQUALS", 
      "CONTAINS", "NOTCONTAINS", "STARTSWITH", "ENDSWITH", "BACKTOFULL"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,49,312,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,3,0,29,8,0,1,1,
  	1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,93,8,3,1,3,1,3,1,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,111,8,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,3,129,8,3,1,3,1,3,1,3,
  	1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,
  	3,1,3,1,3,3,3,154,8,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,5,3,163,8,3,10,3,12,
  	3,166,9,3,1,4,1,4,1,4,1,4,3,4,172,8,4,1,4,1,4,3,4,176,8,4,3,4,178,8,4,
  	1,5,1,5,1,5,1,5,3,5,184,8,5,1,5,1,5,3,5,188,8,5,1,5,1,5,3,5,192,8,5,1,
  	5,1,5,3,5,196,8,5,1,5,1,5,3,5,200,8,5,1,5,1,5,3,5,204,8,5,1,5,1,5,3,5,
  	208,8,5,1,5,1,5,3,5,212,8,5,1,5,1,5,3,5,216,8,5,1,5,1,5,3,5,220,8,5,1,
  	5,1,5,1,5,3,5,225,8,5,1,5,1,5,1,5,3,5,230,8,5,1,5,1,5,1,5,3,5,235,8,5,
  	1,5,1,5,1,5,3,5,240,8,5,1,5,1,5,1,5,3,5,245,8,5,1,5,1,5,1,5,3,5,250,8,
  	5,1,5,1,5,1,5,3,5,255,8,5,1,5,1,5,1,5,3,5,260,8,5,1,5,1,5,3,5,264,8,5,
  	1,5,1,5,3,5,268,8,5,3,5,270,8,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,292,8,6,1,7,1,7,1,7,1,7,
  	1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,310,8,7,1,7,0,1,6,
  	8,0,2,4,6,8,10,12,14,0,0,376,0,28,1,0,0,0,2,30,1,0,0,0,4,33,1,0,0,0,6,
  	153,1,0,0,0,8,177,1,0,0,0,10,269,1,0,0,0,12,291,1,0,0,0,14,309,1,0,0,
  	0,16,17,3,6,3,0,17,18,5,0,0,1,18,29,1,0,0,0,19,20,5,1,0,0,20,21,5,44,
  	0,0,21,29,5,19,0,0,22,23,5,2,0,0,23,24,5,35,0,0,24,25,3,6,3,0,25,26,5,
  	36,0,0,26,27,5,0,0,1,27,29,1,0,0,0,28,16,1,0,0,0,28,19,1,0,0,0,28,22,
  	1,0,0,0,29,1,1,0,0,0,30,31,3,6,3,0,31,32,5,0,0,1,32,3,1,0,0,0,33,34,3,
  	6,3,0,34,35,5,0,0,1,35,5,1,0,0,0,36,37,6,3,-1,0,37,154,3,8,4,0,38,39,
  	5,3,0,0,39,40,5,35,0,0,40,41,5,19,0,0,41,42,5,41,0,0,42,43,3,6,3,0,43,
  	44,5,41,0,0,44,45,5,19,0,0,45,46,5,36,0,0,46,154,1,0,0,0,47,48,5,3,0,
  	0,48,49,5,35,0,0,49,50,5,19,0,0,50,51,5,41,0,0,51,52,3,6,3,0,52,53,5,
  	36,0,0,53,154,1,0,0,0,54,55,5,3,0,0,55,56,5,35,0,0,56,57,3,6,3,0,57,58,
  	5,41,0,0,58,59,5,19,0,0,59,60,5,36,0,0,60,154,1,0,0,0,61,62,5,4,0,0,62,
  	63,5,35,0,0,63,64,3,6,3,0,64,65,5,36,0,0,65,154,1,0,0,0,66,67,5,5,0,0,
  	67,68,5,35,0,0,68,69,3,6,3,0,69,70,5,36,0,0,70,154,1,0,0,0,71,72,5,6,
  	0,0,72,73,5,35,0,0,73,74,3,6,3,0,74,75,5,36,0,0,75,154,1,0,0,0,76,77,
  	5,7,0,0,77,78,5,35,0,0,78,79,3,6,3,0,79,80,5,41,0,0,80,81,5,19,0,0,81,
  	82,5,41,0,0,82,83,5,19,0,0,83,84,5,36,0,0,84,154,1,0,0,0,85,86,5,8,0,
  	0,86,87,5,35,0,0,87,88,5,18,0,0,88,89,5,41,0,0,89,92,3,6,3,0,90,91,5,
  	41,0,0,91,93,5,19,0,0,92,90,1,0,0,0,92,93,1,0,0,0,93,94,1,0,0,0,94,95,
  	5,36,0,0,95,154,1,0,0,0,96,97,5,9,0,0,97,98,5,35,0,0,98,99,5,18,0,0,99,
  	100,5,41,0,0,100,101,3,6,3,0,101,102,5,36,0,0,102,154,1,0,0,0,103,104,
  	5,10,0,0,104,105,5,35,0,0,105,106,5,18,0,0,106,107,5,41,0,0,107,110,3,
  	6,3,0,108,109,5,41,0,0,109,111,5,19,0,0,110,108,1,0,0,0,110,111,1,0,0,
  	0,111,112,1,0,0,0,112,113,5,36,0,0,113,154,1,0,0,0,114,115,5,11,0,0,115,
  	116,5,35,0,0,116,117,5,18,0,0,117,118,5,41,0,0,118,119,3,6,3,0,119,120,
  	5,36,0,0,120,154,1,0,0,0,121,122,5,12,0,0,122,123,5,35,0,0,123,124,5,
  	18,0,0,124,125,5,41,0,0,125,128,3,6,3,0,126,127,5,41,0,0,127,129,5,19,
  	0,0,128,126,1,0,0,0,128,129,1,0,0,0,129,130,1,0,0,0,130,131,5,36,0,0,
  	131,154,1,0,0,0,132,133,5,13,0,0,133,134,5,35,0,0,134,135,5,18,0,0,135,
  	136,5,41,0,0,136,137,3,6,3,0,137,138,5,36,0,0,138,154,1,0,0,0,139,140,
  	5,14,0,0,140,141,5,35,0,0,141,142,5,18,0,0,142,143,5,41,0,0,143,144,3,
  	6,3,0,144,145,5,36,0,0,145,154,1,0,0,0,146,147,5,15,0,0,147,148,5,35,
  	0,0,148,149,3,6,3,0,149,150,5,41,0,0,150,151,5,19,0,0,151,152,5,36,0,
  	0,152,154,1,0,0,0,153,36,1,0,0,0,153,38,1,0,0,0,153,47,1,0,0,0,153,54,
  	1,0,0,0,153,61,1,0,0,0,153,66,1,0,0,0,153,71,1,0,0,0,153,76,1,0,0,0,153,
  	85,1,0,0,0,153,96,1,0,0,0,153,103,1,0,0,0,153,114,1,0,0,0,153,121,1,0,
  	0,0,153,132,1,0,0,0,153,139,1,0,0,0,153,146,1,0,0,0,154,164,1,0,0,0,155,
  	156,10,2,0,0,156,163,3,14,7,0,157,158,10,1,0,0,158,159,5,35,0,0,159,160,
  	3,14,7,0,160,161,5,36,0,0,161,163,1,0,0,0,162,155,1,0,0,0,162,157,1,0,
  	0,0,163,166,1,0,0,0,164,162,1,0,0,0,164,165,1,0,0,0,165,7,1,0,0,0,166,
  	164,1,0,0,0,167,178,5,19,0,0,168,169,5,49,0,0,169,171,5,18,0,0,170,172,
  	3,10,5,0,171,170,1,0,0,0,171,172,1,0,0,0,172,178,1,0,0,0,173,175,5,16,
  	0,0,174,176,3,10,5,0,175,174,1,0,0,0,175,176,1,0,0,0,176,178,1,0,0,0,
  	177,167,1,0,0,0,177,168,1,0,0,0,177,173,1,0,0,0,178,9,1,0,0,0,179,180,
  	5,29,0,0,180,181,3,12,6,0,181,183,5,17,0,0,182,184,3,10,5,0,183,182,1,
  	0,0,0,183,184,1,0,0,0,184,270,1,0,0,0,185,187,5,20,0,0,186,188,3,10,5,
  	0,187,186,1,0,0,0,187,188,1,0,0,0,188,270,1,0,0,0,189,191,5,21,0,0,190,
  	192,3,10,5,0,191,190,1,0,0,0,191,192,1,0,0,0,192,270,1,0,0,0,193,195,
  	5,22,0,0,194,196,3,10,5,0,195,194,1,0,0,0,195,196,1,0,0,0,196,270,1,0,
  	0,0,197,199,5,23,0,0,198,200,3,10,5,0,199,198,1,0,0,0,199,200,1,0,0,0,
  	200,270,1,0,0,0,201,203,5,24,0,0,202,204,3,10,5,0,203,202,1,0,0,0,203,
  	204,1,0,0,0,204,270,1,0,0,0,205,207,5,25,0,0,206,208,3,10,5,0,207,206,
  	1,0,0,0,207,208,1,0,0,0,208,270,1,0,0,0,209,211,5,26,0,0,210,212,3,10,
  	5,0,211,210,1,0,0,0,211,212,1,0,0,0,212,270,1,0,0,0,213,215,5,27,0,0,
  	214,216,3,10,5,0,215,214,1,0,0,0,215,216,1,0,0,0,216,270,1,0,0,0,217,
  	219,5,28,0,0,218,220,3,10,5,0,219,218,1,0,0,0,219,220,1,0,0,0,220,270,
  	1,0,0,0,221,222,5,44,0,0,222,224,5,19,0,0,223,225,3,10,5,0,224,223,1,
  	0,0,0,224,225,1,0,0,0,225,270,1,0,0,0,226,227,5,43,0,0,227,229,5,19,0,
  	0,228,230,3,10,5,0,229,228,1,0,0,0,229,230,1,0,0,0,230,270,1,0,0,0,231,
  	232,5,47,0,0,232,234,5,19,0,0,233,235,3,10,5,0,234,233,1,0,0,0,234,235,
  	1,0,0,0,235,270,1,0,0,0,236,237,5,48,0,0,237,239,5,19,0,0,238,240,3,10,
  	5,0,239,238,1,0,0,0,239,240,1,0,0,0,240,270,1,0,0,0,241,242,5,45,0,0,
  	242,244,5,19,0,0,243,245,3,10,5,0,244,243,1,0,0,0,244,245,1,0,0,0,245,
  	270,1,0,0,0,246,247,5,46,0,0,247,249,5,19,0,0,248,250,3,10,5,0,249,248,
  	1,0,0,0,249,250,1,0,0,0,250,270,1,0,0,0,251,252,5,32,0,0,252,254,5,18,
  	0,0,253,255,3,10,5,0,254,253,1,0,0,0,254,255,1,0,0,0,255,270,1,0,0,0,
  	256,257,5,33,0,0,257,259,5,18,0,0,258,260,3,10,5,0,259,258,1,0,0,0,259,
  	260,1,0,0,0,260,270,1,0,0,0,261,263,3,14,7,0,262,264,3,10,5,0,263,262,
  	1,0,0,0,263,264,1,0,0,0,264,270,1,0,0,0,265,267,5,49,0,0,266,268,3,10,
  	5,0,267,266,1,0,0,0,267,268,1,0,0,0,268,270,1,0,0,0,269,179,1,0,0,0,269,
  	185,1,0,0,0,269,189,1,0,0,0,269,193,1,0,0,0,269,197,1,0,0,0,269,201,1,
  	0,0,0,269,205,1,0,0,0,269,209,1,0,0,0,269,213,1,0,0,0,269,217,1,0,0,0,
  	269,221,1,0,0,0,269,226,1,0,0,0,269,231,1,0,0,0,269,236,1,0,0,0,269,241,
  	1,0,0,0,269,246,1,0,0,0,269,251,1,0,0,0,269,256,1,0,0,0,269,261,1,0,0,
  	0,269,265,1,0,0,0,270,11,1,0,0,0,271,272,5,37,0,0,272,273,5,34,0,0,273,
  	274,5,30,0,0,274,275,5,34,0,0,275,292,5,38,0,0,276,277,5,37,0,0,277,278,
  	5,30,0,0,278,279,5,34,0,0,279,292,5,38,0,0,280,281,5,37,0,0,281,282,5,
  	34,0,0,282,283,5,30,0,0,283,292,5,38,0,0,284,285,5,37,0,0,285,286,5,34,
  	0,0,286,292,5,38,0,0,287,288,5,37,0,0,288,289,5,31,0,0,289,292,5,38,0,
  	0,290,292,1,0,0,0,291,271,1,0,0,0,291,276,1,0,0,0,291,280,1,0,0,0,291,
  	284,1,0,0,0,291,287,1,0,0,0,291,290,1,0,0,0,292,13,1,0,0,0,293,294,5,
  	35,0,0,294,295,5,34,0,0,295,296,5,30,0,0,296,297,5,34,0,0,297,310,5,36,
  	0,0,298,299,5,35,0,0,299,300,5,30,0,0,300,301,5,34,0,0,301,310,5,36,0,
  	0,302,303,5,35,0,0,303,304,5,34,0,0,304,305,5,30,0,0,305,310,5,36,0,0,
  	306,307,5,35,0,0,307,308,5,34,0,0,308,310,5,36,0,0,309,293,1,0,0,0,309,
  	298,1,0,0,0,309,302,1,0,0,0,309,306,1,0,0,0,310,15,1,0,0,0,33,28,92,110,
  	128,153,162,164,171,175,177,183,187,191,195,199,203,207,211,215,219,224,
  	229,234,239,244,249,254,259,263,267,269,291,309
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  useragenttreewalkerParserStaticData = staticData.release();
}

}

UserAgentTreeWalkerParser::UserAgentTreeWalkerParser(TokenStream *input) : UserAgentTreeWalkerParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

UserAgentTreeWalkerParser::UserAgentTreeWalkerParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  UserAgentTreeWalkerParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *useragenttreewalkerParserStaticData->atn, useragenttreewalkerParserStaticData->decisionToDFA, useragenttreewalkerParserStaticData->sharedContextCache, options);
}

UserAgentTreeWalkerParser::~UserAgentTreeWalkerParser() {
  delete _interpreter;
}

const atn::ATN& UserAgentTreeWalkerParser::getATN() const {
  return *useragenttreewalkerParserStaticData->atn;
}

std::string UserAgentTreeWalkerParser::getGrammarFileName() const {
  return "UserAgentTreeWalker.g4";
}

const std::vector<std::string>& UserAgentTreeWalkerParser::getRuleNames() const {
  return useragenttreewalkerParserStaticData->ruleNames;
}

const dfa::Vocabulary& UserAgentTreeWalkerParser::getVocabulary() const {
  return useragenttreewalkerParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView UserAgentTreeWalkerParser::getSerializedATN() const {
  return useragenttreewalkerParserStaticData->serializedATN;
}


//----------------- MatcherRequireContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherRequireContext::MatcherRequireContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::MatcherRequireContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleMatcherRequire;
}

void UserAgentTreeWalkerParser::MatcherRequireContext::copyFrom(MatcherRequireContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IsSyntaxErrorContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::IsSyntaxErrorContext::EQUALS() {
  return getToken(UserAgentTreeWalkerParser::EQUALS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::IsSyntaxErrorContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::IsSyntaxErrorContext::IsSyntaxErrorContext(MatcherRequireContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::IsSyntaxErrorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIsSyntaxError(this);
}
void UserAgentTreeWalkerParser::IsSyntaxErrorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIsSyntaxError(this);
}

std::any UserAgentTreeWalkerParser::IsSyntaxErrorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitIsSyntaxError(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherBaseContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherBaseContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherBaseContext::EOF() {
  return getToken(UserAgentTreeWalkerParser::EOF, 0);
}

UserAgentTreeWalkerParser::MatcherBaseContext::MatcherBaseContext(MatcherRequireContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherBaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherBase(this);
}
void UserAgentTreeWalkerParser::MatcherBaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherBase(this);
}

std::any UserAgentTreeWalkerParser::MatcherBaseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherBase(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsNullContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNullContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsNullContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNullContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNullContext::EOF() {
  return getToken(UserAgentTreeWalkerParser::EOF, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsNullContext::MatcherPathIsNullContext(MatcherRequireContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsNullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsNull(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsNullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsNull(this);
}

std::any UserAgentTreeWalkerParser::MatcherPathIsNullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsNull(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::MatcherRequireContext* UserAgentTreeWalkerParser::matcherRequire() {
  MatcherRequireContext *_localctx = _tracker.createInstance<MatcherRequireContext>(_ctx, getState());
  enterRule(_localctx, 0, UserAgentTreeWalkerParser::RuleMatcherRequire);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(28);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentTreeWalkerParser::T__2:
      case UserAgentTreeWalkerParser::T__3:
      case UserAgentTreeWalkerParser::T__4:
      case UserAgentTreeWalkerParser::T__5:
      case UserAgentTreeWalkerParser::T__6:
      case UserAgentTreeWalkerParser::T__7:
      case UserAgentTreeWalkerParser::T__8:
      case UserAgentTreeWalkerParser::T__9:
      case UserAgentTreeWalkerParser::T__10:
      case UserAgentTreeWalkerParser::T__11:
      case UserAgentTreeWalkerParser::T__12:
      case UserAgentTreeWalkerParser::T__13:
      case UserAgentTreeWalkerParser::T__14:
      case UserAgentTreeWalkerParser::T__15:
      case UserAgentTreeWalkerParser::VALUE:
      case UserAgentTreeWalkerParser::BACKTOFULL: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::MatcherBaseContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(16);
        matcher(0);
        setState(17);
        match(UserAgentTreeWalkerParser::EOF);
        break;
      }

      case UserAgentTreeWalkerParser::T__0: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::IsSyntaxErrorContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(19);
        match(UserAgentTreeWalkerParser::T__0);
        setState(20);
        match(UserAgentTreeWalkerParser::EQUALS);
        setState(21);
        antlrcpp::downCast<IsSyntaxErrorContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        break;
      }

      case UserAgentTreeWalkerParser::T__1: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::MatcherPathIsNullContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(22);
        match(UserAgentTreeWalkerParser::T__1);
        setState(23);
        match(UserAgentTreeWalkerParser::BLOCKOPEN);
        setState(24);
        matcher(0);
        setState(25);
        match(UserAgentTreeWalkerParser::BLOCKCLOSE);
        setState(26);
        match(UserAgentTreeWalkerParser::EOF);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatcherExtractContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherExtractContext::MatcherExtractContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherExtractContext::EOF() {
  return getToken(UserAgentTreeWalkerParser::EOF, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherExtractContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}


size_t UserAgentTreeWalkerParser::MatcherExtractContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleMatcherExtract;
}

void UserAgentTreeWalkerParser::MatcherExtractContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherExtract(this);
}

void UserAgentTreeWalkerParser::MatcherExtractContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherExtract(this);
}


std::any UserAgentTreeWalkerParser::MatcherExtractContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherExtract(this);
  else
    return visitor->visitChildren(this);
}

UserAgentTreeWalkerParser::MatcherExtractContext* UserAgentTreeWalkerParser::matcherExtract() {
  MatcherExtractContext *_localctx = _tracker.createInstance<MatcherExtractContext>(_ctx, getState());
  enterRule(_localctx, 2, UserAgentTreeWalkerParser::RuleMatcherExtract);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    antlrcpp::downCast<MatcherExtractContext *>(_localctx)->expression = matcher(0);
    setState(31);
    match(UserAgentTreeWalkerParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatcherVariableContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherVariableContext::MatcherVariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherVariableContext::EOF() {
  return getToken(UserAgentTreeWalkerParser::EOF, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherVariableContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}


size_t UserAgentTreeWalkerParser::MatcherVariableContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleMatcherVariable;
}

void UserAgentTreeWalkerParser::MatcherVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherVariable(this);
}

void UserAgentTreeWalkerParser::MatcherVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherVariable(this);
}


std::any UserAgentTreeWalkerParser::MatcherVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherVariable(this);
  else
    return visitor->visitChildren(this);
}

UserAgentTreeWalkerParser::MatcherVariableContext* UserAgentTreeWalkerParser::matcherVariable() {
  MatcherVariableContext *_localctx = _tracker.createInstance<MatcherVariableContext>(_ctx, getState());
  enterRule(_localctx, 4, UserAgentTreeWalkerParser::RuleMatcherVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    antlrcpp::downCast<MatcherVariableContext *>(_localctx)->expression = matcher(0);
    setState(34);
    match(UserAgentTreeWalkerParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MatcherContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherContext::MatcherContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::MatcherContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleMatcher;
}

void UserAgentTreeWalkerParser::MatcherContext::copyFrom(MatcherContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MatcherCleanVersionContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherCleanVersionContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherCleanVersionContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherCleanVersionContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

UserAgentTreeWalkerParser::MatcherCleanVersionContext::MatcherCleanVersionContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherCleanVersionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherCleanVersion(this);
}
void UserAgentTreeWalkerParser::MatcherCleanVersionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherCleanVersion(this);
}

std::any UserAgentTreeWalkerParser::MatcherCleanVersionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherCleanVersion(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathLookupPrefixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::MatcherPathLookupPrefixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathLookupPrefix(this);
}
void UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathLookupPrefix(this);
}

std::any UserAgentTreeWalkerParser::MatcherPathLookupPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathLookupPrefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathLookupContainsContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::MatcherPathLookupContainsContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathLookupContains(this);
}
void UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathLookupContains(this);
}

std::any UserAgentTreeWalkerParser::MatcherPathLookupContainsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathLookupContains(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherConcatPrefixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPrefixContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherConcatPrefixContext::MatcherConcatPrefixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherConcatPrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherConcatPrefix(this);
}
void UserAgentTreeWalkerParser::MatcherConcatPrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherConcatPrefix(this);
}

std::any UserAgentTreeWalkerParser::MatcherConcatPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherConcatPrefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsInLookupContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::MatcherPathIsInLookupContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsInLookup(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsInLookup(this);
}

std::any UserAgentTreeWalkerParser::MatcherPathIsInLookupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsInLookup(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherWordRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherWordRangeContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

UserAgentTreeWalkerParser::WordRangeContext* UserAgentTreeWalkerParser::MatcherWordRangeContext::wordRange() {
  return getRuleContext<UserAgentTreeWalkerParser::WordRangeContext>(0);
}

UserAgentTreeWalkerParser::MatcherWordRangeContext::MatcherWordRangeContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherWordRangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherWordRange(this);
}
void UserAgentTreeWalkerParser::MatcherWordRangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherWordRange(this);
}

std::any UserAgentTreeWalkerParser::MatcherWordRangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherWordRange(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherSegmentRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherSegmentRangeContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherSegmentRangeContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::WordRangeContext* UserAgentTreeWalkerParser::MatcherSegmentRangeContext::wordRange() {
  return getRuleContext<UserAgentTreeWalkerParser::WordRangeContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherSegmentRangeContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

UserAgentTreeWalkerParser::MatcherSegmentRangeContext::MatcherSegmentRangeContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherSegmentRangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherSegmentRange(this);
}
void UserAgentTreeWalkerParser::MatcherSegmentRangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherSegmentRange(this);
}

std::any UserAgentTreeWalkerParser::MatcherSegmentRangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherSegmentRange(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherNormalizeBrandContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::MatcherNormalizeBrandContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherNormalizeBrand(this);
}
void UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherNormalizeBrand(this);
}

std::any UserAgentTreeWalkerParser::MatcherNormalizeBrandContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherNormalizeBrand(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherConcatContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherConcatContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherConcatContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherConcatContext::VALUE() {
  return getTokens(UserAgentTreeWalkerParser::VALUE);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatContext::VALUE(size_t i) {
  return getToken(UserAgentTreeWalkerParser::VALUE, i);
}

UserAgentTreeWalkerParser::MatcherConcatContext::MatcherConcatContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherConcatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherConcat(this);
}
void UserAgentTreeWalkerParser::MatcherConcatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherConcat(this);
}

std::any UserAgentTreeWalkerParser::MatcherConcatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherConcat(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsInLookupContainsContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::MatcherPathIsInLookupContainsContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsInLookupContains(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsInLookupContains(this);
}

std::any UserAgentTreeWalkerParser::MatcherPathIsInLookupContainsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsInLookupContains(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherDefaultIfNullContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::MatcherDefaultIfNullContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherDefaultIfNull(this);
}
void UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherDefaultIfNull(this);
}

std::any UserAgentTreeWalkerParser::MatcherDefaultIfNullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherDefaultIfNull(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::BasePathContext* UserAgentTreeWalkerParser::MatcherPathContext::basePath() {
  return getRuleContext<UserAgentTreeWalkerParser::BasePathContext>(0);
}

UserAgentTreeWalkerParser::MatcherPathContext::MatcherPathContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPath(this);
}
void UserAgentTreeWalkerParser::MatcherPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPath(this);
}

std::any UserAgentTreeWalkerParser::MatcherPathContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPath(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsNotInLookupPrefixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::MatcherPathIsNotInLookupPrefixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsNotInLookupPrefix(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsNotInLookupPrefix(this);
}

std::any UserAgentTreeWalkerParser::MatcherPathIsNotInLookupPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsNotInLookupPrefix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherReplaceStringContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherReplaceStringContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherReplaceStringContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherReplaceStringContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherReplaceStringContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherReplaceStringContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherReplaceStringContext::VALUE() {
  return getTokens(UserAgentTreeWalkerParser::VALUE);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherReplaceStringContext::VALUE(size_t i) {
  return getToken(UserAgentTreeWalkerParser::VALUE, i);
}

UserAgentTreeWalkerParser::MatcherReplaceStringContext::MatcherReplaceStringContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherReplaceStringContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherReplaceString(this);
}
void UserAgentTreeWalkerParser::MatcherReplaceStringContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherReplaceString(this);
}

std::any UserAgentTreeWalkerParser::MatcherReplaceStringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherReplaceString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathLookupContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::MatcherPathLookupContext::SEMICOLON() {
  return getTokens(UserAgentTreeWalkerParser::SEMICOLON);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::SEMICOLON(size_t i) {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, i);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathLookupContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathLookupContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherPathLookupContext::MatcherPathLookupContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathLookupContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathLookup(this);
}
void UserAgentTreeWalkerParser::MatcherPathLookupContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathLookup(this);
}

std::any UserAgentTreeWalkerParser::MatcherPathLookupContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathLookup(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherExtractBrandFromUrlContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::MatcherExtractBrandFromUrlContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherExtractBrandFromUrl(this);
}
void UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherExtractBrandFromUrl(this);
}

std::any UserAgentTreeWalkerParser::MatcherExtractBrandFromUrlContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherExtractBrandFromUrl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherConcatPostfixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherConcatPostfixContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::MatcherConcatPostfixContext::MatcherConcatPostfixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherConcatPostfixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherConcatPostfix(this);
}
void UserAgentTreeWalkerParser::MatcherConcatPostfixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherConcatPostfix(this);
}

std::any UserAgentTreeWalkerParser::MatcherConcatPostfixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherConcatPostfix(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MatcherPathIsInLookupPrefixContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::SEMICOLON() {
  return getToken(UserAgentTreeWalkerParser::SEMICOLON, 0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::matcher() {
  return getRuleContext<UserAgentTreeWalkerParser::MatcherContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::MatcherPathIsInLookupPrefixContext(MatcherContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMatcherPathIsInLookupPrefix(this);
}
void UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMatcherPathIsInLookupPrefix(this);
}

std::any UserAgentTreeWalkerParser::MatcherPathIsInLookupPrefixContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitMatcherPathIsInLookupPrefix(this);
  else
    return visitor->visitChildren(this);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::matcher() {
   return matcher(0);
}

UserAgentTreeWalkerParser::MatcherContext* UserAgentTreeWalkerParser::matcher(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  UserAgentTreeWalkerParser::MatcherContext *_localctx = _tracker.createInstance<MatcherContext>(_ctx, parentState);
  UserAgentTreeWalkerParser::MatcherContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 6;
  enterRecursionRule(_localctx, 6, UserAgentTreeWalkerParser::RuleMatcher, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(153);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MatcherPathContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(37);
      basePath();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MatcherConcatContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(38);
      match(UserAgentTreeWalkerParser::T__2);
      setState(39);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(40);
      antlrcpp::downCast<MatcherConcatContext *>(_localctx)->prefix = match(UserAgentTreeWalkerParser::VALUE);
      setState(41);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(42);
      matcher(0);
      setState(43);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(44);
      antlrcpp::downCast<MatcherConcatContext *>(_localctx)->postfix = match(UserAgentTreeWalkerParser::VALUE);
      setState(45);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MatcherConcatPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(47);
      match(UserAgentTreeWalkerParser::T__2);
      setState(48);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(49);
      antlrcpp::downCast<MatcherConcatPrefixContext *>(_localctx)->prefix = match(UserAgentTreeWalkerParser::VALUE);
      setState(50);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(51);
      matcher(0);
      setState(52);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<MatcherConcatPostfixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(54);
      match(UserAgentTreeWalkerParser::T__2);
      setState(55);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(56);
      matcher(0);
      setState(57);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(58);
      antlrcpp::downCast<MatcherConcatPostfixContext *>(_localctx)->postfix = match(UserAgentTreeWalkerParser::VALUE);
      setState(59);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<MatcherNormalizeBrandContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(61);
      match(UserAgentTreeWalkerParser::T__3);
      setState(62);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(63);
      matcher(0);
      setState(64);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<MatcherExtractBrandFromUrlContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(66);
      match(UserAgentTreeWalkerParser::T__4);
      setState(67);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(68);
      matcher(0);
      setState(69);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<MatcherCleanVersionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(71);
      match(UserAgentTreeWalkerParser::T__5);
      setState(72);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(73);
      matcher(0);
      setState(74);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<MatcherReplaceStringContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(76);
      match(UserAgentTreeWalkerParser::T__6);
      setState(77);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(78);
      matcher(0);
      setState(79);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(80);
      antlrcpp::downCast<MatcherReplaceStringContext *>(_localctx)->search = match(UserAgentTreeWalkerParser::VALUE);
      setState(81);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(82);
      antlrcpp::downCast<MatcherReplaceStringContext *>(_localctx)->replace = match(UserAgentTreeWalkerParser::VALUE);
      setState(83);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<MatcherPathLookupContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(85);
      match(UserAgentTreeWalkerParser::T__7);
      setState(86);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(87);
      antlrcpp::downCast<MatcherPathLookupContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(88);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(89);
      matcher(0);
      setState(92);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentTreeWalkerParser::SEMICOLON) {
        setState(90);
        match(UserAgentTreeWalkerParser::SEMICOLON);
        setState(91);
        antlrcpp::downCast<MatcherPathLookupContext *>(_localctx)->defaultValue = match(UserAgentTreeWalkerParser::VALUE);
      }
      setState(94);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<MatcherPathIsInLookupContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(96);
      match(UserAgentTreeWalkerParser::T__8);
      setState(97);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(98);
      antlrcpp::downCast<MatcherPathIsInLookupContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(99);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(100);
      matcher(0);
      setState(101);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<MatcherPathLookupContainsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(103);
      match(UserAgentTreeWalkerParser::T__9);
      setState(104);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(105);
      antlrcpp::downCast<MatcherPathLookupContainsContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(106);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(107);
      matcher(0);
      setState(110);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentTreeWalkerParser::SEMICOLON) {
        setState(108);
        match(UserAgentTreeWalkerParser::SEMICOLON);
        setState(109);
        antlrcpp::downCast<MatcherPathLookupContainsContext *>(_localctx)->defaultValue = match(UserAgentTreeWalkerParser::VALUE);
      }
      setState(112);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<MatcherPathIsInLookupContainsContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(114);
      match(UserAgentTreeWalkerParser::T__10);
      setState(115);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(116);
      antlrcpp::downCast<MatcherPathIsInLookupContainsContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(117);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(118);
      matcher(0);
      setState(119);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<MatcherPathLookupPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(121);
      match(UserAgentTreeWalkerParser::T__11);
      setState(122);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(123);
      antlrcpp::downCast<MatcherPathLookupPrefixContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(124);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(125);
      matcher(0);
      setState(128);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == UserAgentTreeWalkerParser::SEMICOLON) {
        setState(126);
        match(UserAgentTreeWalkerParser::SEMICOLON);
        setState(127);
        antlrcpp::downCast<MatcherPathLookupPrefixContext *>(_localctx)->defaultValue = match(UserAgentTreeWalkerParser::VALUE);
      }
      setState(130);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<MatcherPathIsInLookupPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(132);
      match(UserAgentTreeWalkerParser::T__12);
      setState(133);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(134);
      antlrcpp::downCast<MatcherPathIsInLookupPrefixContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(135);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(136);
      matcher(0);
      setState(137);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<MatcherPathIsNotInLookupPrefixContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(139);
      match(UserAgentTreeWalkerParser::T__13);
      setState(140);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(141);
      antlrcpp::downCast<MatcherPathIsNotInLookupPrefixContext *>(_localctx)->lookup = match(UserAgentTreeWalkerParser::VALUENAME);
      setState(142);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(143);
      matcher(0);
      setState(144);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<MatcherDefaultIfNullContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(146);
      match(UserAgentTreeWalkerParser::T__14);
      setState(147);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(148);
      matcher(0);
      setState(149);
      match(UserAgentTreeWalkerParser::SEMICOLON);
      setState(150);
      antlrcpp::downCast<MatcherDefaultIfNullContext *>(_localctx)->defaultValue = match(UserAgentTreeWalkerParser::VALUE);
      setState(151);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(164);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(162);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MatcherWordRangeContext>(_tracker.createInstance<MatcherContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleMatcher);
          setState(155);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(156);
          wordRange();
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<MatcherSegmentRangeContext>(_tracker.createInstance<MatcherContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleMatcher);
          setState(157);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(158);
          match(UserAgentTreeWalkerParser::BLOCKOPEN);
          setState(159);
          wordRange();
          setState(160);
          match(UserAgentTreeWalkerParser::BLOCKCLOSE);
          break;
        }

        default:
          break;
        } 
      }
      setState(166);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BasePathContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::BasePathContext::BasePathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::BasePathContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleBasePath;
}

void UserAgentTreeWalkerParser::BasePathContext::copyFrom(BasePathContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PathVariableContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::PathVariableContext::BACKTOFULL() {
  return getToken(UserAgentTreeWalkerParser::BACKTOFULL, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::PathVariableContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::PathVariableContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::PathVariableContext::PathVariableContext(BasePathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::PathVariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathVariable(this);
}
void UserAgentTreeWalkerParser::PathVariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathVariable(this);
}

std::any UserAgentTreeWalkerParser::PathVariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitPathVariable(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PathWalkContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::PathWalkContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::PathWalkContext::PathWalkContext(BasePathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::PathWalkContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathWalk(this);
}
void UserAgentTreeWalkerParser::PathWalkContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathWalk(this);
}

std::any UserAgentTreeWalkerParser::PathWalkContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitPathWalk(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PathFixedValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::PathFixedValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathFixedValueContext::PathFixedValueContext(BasePathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::PathFixedValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPathFixedValue(this);
}
void UserAgentTreeWalkerParser::PathFixedValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPathFixedValue(this);
}

std::any UserAgentTreeWalkerParser::PathFixedValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitPathFixedValue(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::BasePathContext* UserAgentTreeWalkerParser::basePath() {
  BasePathContext *_localctx = _tracker.createInstance<BasePathContext>(_ctx, getState());
  enterRule(_localctx, 8, UserAgentTreeWalkerParser::RuleBasePath);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentTreeWalkerParser::VALUE: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::PathFixedValueContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(167);
        antlrcpp::downCast<PathFixedValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        break;
      }

      case UserAgentTreeWalkerParser::BACKTOFULL: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::PathVariableContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(168);
        match(UserAgentTreeWalkerParser::BACKTOFULL);
        setState(169);
        antlrcpp::downCast<PathVariableContext *>(_localctx)->variable = match(UserAgentTreeWalkerParser::VALUENAME);
        setState(171);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          setState(170);
          antlrcpp::downCast<PathVariableContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::T__15: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::PathWalkContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(173);
        match(UserAgentTreeWalkerParser::T__15);
        setState(175);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
        case 1: {
          setState(174);
          antlrcpp::downCast<PathWalkContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PathContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::PathContext::PathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::PathContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RulePath;
}

void UserAgentTreeWalkerParser::PathContext::copyFrom(PathContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StepNext4Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNext4Context::NEXT4() {
  return getToken(UserAgentTreeWalkerParser::NEXT4, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNext4Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNext4Context::StepNext4Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNext4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNext4(this);
}
void UserAgentTreeWalkerParser::StepNext4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNext4(this);
}

std::any UserAgentTreeWalkerParser::StepNext4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNext4(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepStartsWithValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepStartsWithValueContext::STARTSWITH() {
  return getToken(UserAgentTreeWalkerParser::STARTSWITH, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepStartsWithValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepStartsWithValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepStartsWithValueContext::StepStartsWithValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepStartsWithValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepStartsWithValue(this);
}
void UserAgentTreeWalkerParser::StepStartsWithValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepStartsWithValue(this);
}

std::any UserAgentTreeWalkerParser::StepStartsWithValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepStartsWithValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNext3Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNext3Context::NEXT3() {
  return getToken(UserAgentTreeWalkerParser::NEXT3, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNext3Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNext3Context::StepNext3Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNext3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNext3(this);
}
void UserAgentTreeWalkerParser::StepNext3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNext3(this);
}

std::any UserAgentTreeWalkerParser::StepNext3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNext3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepPrev4Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepPrev4Context::PREV4() {
  return getToken(UserAgentTreeWalkerParser::PREV4, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepPrev4Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepPrev4Context::StepPrev4Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepPrev4Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepPrev4(this);
}
void UserAgentTreeWalkerParser::StepPrev4Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepPrev4(this);
}

std::any UserAgentTreeWalkerParser::StepPrev4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepPrev4(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepPrev3Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepPrev3Context::PREV3() {
  return getToken(UserAgentTreeWalkerParser::PREV3, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepPrev3Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepPrev3Context::StepPrev3Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepPrev3Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepPrev3(this);
}
void UserAgentTreeWalkerParser::StepPrev3Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepPrev3(this);
}

std::any UserAgentTreeWalkerParser::StepPrev3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepPrev3(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepPrev2Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepPrev2Context::PREV2() {
  return getToken(UserAgentTreeWalkerParser::PREV2, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepPrev2Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepPrev2Context::StepPrev2Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepPrev2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepPrev2(this);
}
void UserAgentTreeWalkerParser::StepPrev2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepPrev2(this);
}

std::any UserAgentTreeWalkerParser::StepPrev2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepPrev2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepIsInSetContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepIsInSetContext::IN() {
  return getToken(UserAgentTreeWalkerParser::IN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepIsInSetContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepIsInSetContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepIsInSetContext::StepIsInSetContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepIsInSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepIsInSet(this);
}
void UserAgentTreeWalkerParser::StepIsInSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepIsInSet(this);
}

std::any UserAgentTreeWalkerParser::StepIsInSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepIsInSet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNext2Context ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNext2Context::NEXT2() {
  return getToken(UserAgentTreeWalkerParser::NEXT2, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNext2Context::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNext2Context::StepNext2Context(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNext2Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNext2(this);
}
void UserAgentTreeWalkerParser::StepNext2Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNext2(this);
}

std::any UserAgentTreeWalkerParser::StepNext2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNext2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepUpContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepUpContext::UP() {
  return getToken(UserAgentTreeWalkerParser::UP, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepUpContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepUpContext::StepUpContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepUpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepUp(this);
}
void UserAgentTreeWalkerParser::StepUpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepUp(this);
}

std::any UserAgentTreeWalkerParser::StepUpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepUp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepEndsWithValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepEndsWithValueContext::ENDSWITH() {
  return getToken(UserAgentTreeWalkerParser::ENDSWITH, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepEndsWithValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepEndsWithValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepEndsWithValueContext::StepEndsWithValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepEndsWithValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepEndsWithValue(this);
}
void UserAgentTreeWalkerParser::StepEndsWithValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepEndsWithValue(this);
}

std::any UserAgentTreeWalkerParser::StepEndsWithValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepEndsWithValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepIsNotInSetContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepIsNotInSetContext::NOTIN() {
  return getToken(UserAgentTreeWalkerParser::NOTIN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepIsNotInSetContext::VALUENAME() {
  return getToken(UserAgentTreeWalkerParser::VALUENAME, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepIsNotInSetContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepIsNotInSetContext::StepIsNotInSetContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepIsNotInSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepIsNotInSet(this);
}
void UserAgentTreeWalkerParser::StepIsNotInSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepIsNotInSet(this);
}

std::any UserAgentTreeWalkerParser::StepIsNotInSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepIsNotInSet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepEqualsValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepEqualsValueContext::EQUALS() {
  return getToken(UserAgentTreeWalkerParser::EQUALS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepEqualsValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepEqualsValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepEqualsValueContext::StepEqualsValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepEqualsValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepEqualsValue(this);
}
void UserAgentTreeWalkerParser::StepEqualsValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepEqualsValue(this);
}

std::any UserAgentTreeWalkerParser::StepEqualsValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepEqualsValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepDownContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepDownContext::DOT() {
  return getToken(UserAgentTreeWalkerParser::DOT, 0);
}

UserAgentTreeWalkerParser::NumberRangeContext* UserAgentTreeWalkerParser::StepDownContext::numberRange() {
  return getRuleContext<UserAgentTreeWalkerParser::NumberRangeContext>(0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepDownContext::PATHTOKENNAME() {
  return getToken(UserAgentTreeWalkerParser::PATHTOKENNAME, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepDownContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepDownContext::StepDownContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepDownContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepDown(this);
}
void UserAgentTreeWalkerParser::StepDownContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepDown(this);
}

std::any UserAgentTreeWalkerParser::StepDownContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepDown(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepWordRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::WordRangeContext* UserAgentTreeWalkerParser::StepWordRangeContext::wordRange() {
  return getRuleContext<UserAgentTreeWalkerParser::WordRangeContext>(0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepWordRangeContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepWordRangeContext::StepWordRangeContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepWordRangeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepWordRange(this);
}
void UserAgentTreeWalkerParser::StepWordRangeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepWordRange(this);
}

std::any UserAgentTreeWalkerParser::StepWordRangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepWordRange(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNotEqualsValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNotEqualsValueContext::NOTEQUALS() {
  return getToken(UserAgentTreeWalkerParser::NOTEQUALS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepNotEqualsValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNotEqualsValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNotEqualsValueContext::StepNotEqualsValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNotEqualsValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNotEqualsValue(this);
}
void UserAgentTreeWalkerParser::StepNotEqualsValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNotEqualsValue(this);
}

std::any UserAgentTreeWalkerParser::StepNotEqualsValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNotEqualsValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepBackToFullContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepBackToFullContext::BACKTOFULL() {
  return getToken(UserAgentTreeWalkerParser::BACKTOFULL, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepBackToFullContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepBackToFullContext::StepBackToFullContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepBackToFullContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepBackToFull(this);
}
void UserAgentTreeWalkerParser::StepBackToFullContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepBackToFull(this);
}

std::any UserAgentTreeWalkerParser::StepBackToFullContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepBackToFull(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepPrevContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepPrevContext::PREV() {
  return getToken(UserAgentTreeWalkerParser::PREV, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepPrevContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepPrevContext::StepPrevContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepPrevContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepPrev(this);
}
void UserAgentTreeWalkerParser::StepPrevContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepPrev(this);
}

std::any UserAgentTreeWalkerParser::StepPrevContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepPrev(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNextContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNextContext::NEXT() {
  return getToken(UserAgentTreeWalkerParser::NEXT, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNextContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNextContext::StepNextContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNextContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNext(this);
}
void UserAgentTreeWalkerParser::StepNextContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNext(this);
}

std::any UserAgentTreeWalkerParser::StepNextContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNext(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepContainsValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepContainsValueContext::CONTAINS() {
  return getToken(UserAgentTreeWalkerParser::CONTAINS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepContainsValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepContainsValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepContainsValueContext::StepContainsValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepContainsValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepContainsValue(this);
}
void UserAgentTreeWalkerParser::StepContainsValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepContainsValue(this);
}

std::any UserAgentTreeWalkerParser::StepContainsValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepContainsValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StepNotContainsValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::StepNotContainsValueContext::NOTCONTAINS() {
  return getToken(UserAgentTreeWalkerParser::NOTCONTAINS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::StepNotContainsValueContext::VALUE() {
  return getToken(UserAgentTreeWalkerParser::VALUE, 0);
}

UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::StepNotContainsValueContext::path() {
  return getRuleContext<UserAgentTreeWalkerParser::PathContext>(0);
}

UserAgentTreeWalkerParser::StepNotContainsValueContext::StepNotContainsValueContext(PathContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::StepNotContainsValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStepNotContainsValue(this);
}
void UserAgentTreeWalkerParser::StepNotContainsValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStepNotContainsValue(this);
}

std::any UserAgentTreeWalkerParser::StepNotContainsValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitStepNotContainsValue(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::PathContext* UserAgentTreeWalkerParser::path() {
  PathContext *_localctx = _tracker.createInstance<PathContext>(_ctx, getState());
  enterRule(_localctx, 10, UserAgentTreeWalkerParser::RulePath);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(269);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case UserAgentTreeWalkerParser::DOT: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepDownContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(179);
        match(UserAgentTreeWalkerParser::DOT);
        setState(180);
        numberRange();
        setState(181);
        antlrcpp::downCast<StepDownContext *>(_localctx)->name = match(UserAgentTreeWalkerParser::PATHTOKENNAME);
        setState(183);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          setState(182);
          antlrcpp::downCast<StepDownContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::UP: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepUpContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(185);
        match(UserAgentTreeWalkerParser::UP);
        setState(187);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          setState(186);
          antlrcpp::downCast<StepUpContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::NEXT: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepNextContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(189);
        match(UserAgentTreeWalkerParser::NEXT);
        setState(191);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
        case 1: {
          setState(190);
          antlrcpp::downCast<StepNextContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::NEXT2: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepNext2Context>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(193);
        match(UserAgentTreeWalkerParser::NEXT2);
        setState(195);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
        case 1: {
          setState(194);
          antlrcpp::downCast<StepNext2Context *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::NEXT3: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepNext3Context>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(197);
        match(UserAgentTreeWalkerParser::NEXT3);
        setState(199);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          setState(198);
          antlrcpp::downCast<StepNext3Context *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::NEXT4: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepNext4Context>(_localctx);
        enterOuterAlt(_localctx, 6);
        setState(201);
        match(UserAgentTreeWalkerParser::NEXT4);
        setState(203);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          setState(202);
          antlrcpp::downCast<StepNext4Context *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::PREV: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepPrevContext>(_localctx);
        enterOuterAlt(_localctx, 7);
        setState(205);
        match(UserAgentTreeWalkerParser::PREV);
        setState(207);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          setState(206);
          antlrcpp::downCast<StepPrevContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::PREV2: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepPrev2Context>(_localctx);
        enterOuterAlt(_localctx, 8);
        setState(209);
        match(UserAgentTreeWalkerParser::PREV2);
        setState(211);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          setState(210);
          antlrcpp::downCast<StepPrev2Context *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::PREV3: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepPrev3Context>(_localctx);
        enterOuterAlt(_localctx, 9);
        setState(213);
        match(UserAgentTreeWalkerParser::PREV3);
        setState(215);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          setState(214);
          antlrcpp::downCast<StepPrev3Context *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::PREV4: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepPrev4Context>(_localctx);
        enterOuterAlt(_localctx, 10);
        setState(217);
        match(UserAgentTreeWalkerParser::PREV4);
        setState(219);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
        case 1: {
          setState(218);
          antlrcpp::downCast<StepPrev4Context *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::EQUALS: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepEqualsValueContext>(_localctx);
        enterOuterAlt(_localctx, 11);
        setState(221);
        match(UserAgentTreeWalkerParser::EQUALS);
        setState(222);
        antlrcpp::downCast<StepEqualsValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(224);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          setState(223);
          antlrcpp::downCast<StepEqualsValueContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::NOTEQUALS: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepNotEqualsValueContext>(_localctx);
        enterOuterAlt(_localctx, 12);
        setState(226);
        match(UserAgentTreeWalkerParser::NOTEQUALS);
        setState(227);
        antlrcpp::downCast<StepNotEqualsValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(229);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(228);
          antlrcpp::downCast<StepNotEqualsValueContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::STARTSWITH: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepStartsWithValueContext>(_localctx);
        enterOuterAlt(_localctx, 13);
        setState(231);
        match(UserAgentTreeWalkerParser::STARTSWITH);
        setState(232);
        antlrcpp::downCast<StepStartsWithValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(234);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          setState(233);
          antlrcpp::downCast<StepStartsWithValueContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::ENDSWITH: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepEndsWithValueContext>(_localctx);
        enterOuterAlt(_localctx, 14);
        setState(236);
        match(UserAgentTreeWalkerParser::ENDSWITH);
        setState(237);
        antlrcpp::downCast<StepEndsWithValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(239);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
        case 1: {
          setState(238);
          antlrcpp::downCast<StepEndsWithValueContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::CONTAINS: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepContainsValueContext>(_localctx);
        enterOuterAlt(_localctx, 15);
        setState(241);
        match(UserAgentTreeWalkerParser::CONTAINS);
        setState(242);
        antlrcpp::downCast<StepContainsValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(244);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
        case 1: {
          setState(243);
          antlrcpp::downCast<StepContainsValueContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::NOTCONTAINS: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepNotContainsValueContext>(_localctx);
        enterOuterAlt(_localctx, 16);
        setState(246);
        match(UserAgentTreeWalkerParser::NOTCONTAINS);
        setState(247);
        antlrcpp::downCast<StepNotContainsValueContext *>(_localctx)->value = match(UserAgentTreeWalkerParser::VALUE);
        setState(249);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          setState(248);
          antlrcpp::downCast<StepNotContainsValueContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::IN: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepIsInSetContext>(_localctx);
        enterOuterAlt(_localctx, 17);
        setState(251);
        match(UserAgentTreeWalkerParser::IN);
        setState(252);
        antlrcpp::downCast<StepIsInSetContext *>(_localctx)->set = match(UserAgentTreeWalkerParser::VALUENAME);
        setState(254);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          setState(253);
          antlrcpp::downCast<StepIsInSetContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::NOTIN: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepIsNotInSetContext>(_localctx);
        enterOuterAlt(_localctx, 18);
        setState(256);
        match(UserAgentTreeWalkerParser::NOTIN);
        setState(257);
        antlrcpp::downCast<StepIsNotInSetContext *>(_localctx)->set = match(UserAgentTreeWalkerParser::VALUENAME);
        setState(259);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
        case 1: {
          setState(258);
          antlrcpp::downCast<StepIsNotInSetContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::BLOCKOPEN: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepWordRangeContext>(_localctx);
        enterOuterAlt(_localctx, 19);
        setState(261);
        wordRange();
        setState(263);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
        case 1: {
          setState(262);
          antlrcpp::downCast<StepWordRangeContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

      case UserAgentTreeWalkerParser::BACKTOFULL: {
        _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::StepBackToFullContext>(_localctx);
        enterOuterAlt(_localctx, 20);
        setState(265);
        match(UserAgentTreeWalkerParser::BACKTOFULL);
        setState(267);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
        case 1: {
          setState(266);
          antlrcpp::downCast<StepBackToFullContext *>(_localctx)->nextStep = path();
          break;
        }

        default:
          break;
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::NumberRangeContext::NumberRangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::NumberRangeContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleNumberRange;
}

void UserAgentTreeWalkerParser::NumberRangeContext::copyFrom(NumberRangeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumberRangeAllContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeAllContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeAllContext::STAR() {
  return getToken(UserAgentTreeWalkerParser::STAR, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeAllContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

UserAgentTreeWalkerParser::NumberRangeAllContext::NumberRangeAllContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeAllContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeAll(this);
}
void UserAgentTreeWalkerParser::NumberRangeAllContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeAll(this);
}

std::any UserAgentTreeWalkerParser::NumberRangeAllContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeAll(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeSingleValueContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeSingleValueContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeSingleValueContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeSingleValueContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::NumberRangeSingleValueContext::NumberRangeSingleValueContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeSingleValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeSingleValue(this);
}
void UserAgentTreeWalkerParser::NumberRangeSingleValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeSingleValue(this);
}

std::any UserAgentTreeWalkerParser::NumberRangeSingleValueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeSingleValue(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeStartToEndContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToEndContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToEndContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToEndContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::NumberRangeStartToEndContext::NUMBER() {
  return getTokens(UserAgentTreeWalkerParser::NUMBER);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToEndContext::NUMBER(size_t i) {
  return getToken(UserAgentTreeWalkerParser::NUMBER, i);
}

UserAgentTreeWalkerParser::NumberRangeStartToEndContext::NumberRangeStartToEndContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeStartToEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeStartToEnd(this);
}
void UserAgentTreeWalkerParser::NumberRangeStartToEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeStartToEnd(this);
}

std::any UserAgentTreeWalkerParser::NumberRangeStartToEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeStartToEnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeEmptyContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::NumberRangeEmptyContext::NumberRangeEmptyContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeEmptyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeEmpty(this);
}
void UserAgentTreeWalkerParser::NumberRangeEmptyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeEmpty(this);
}

std::any UserAgentTreeWalkerParser::NumberRangeEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeEmpty(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeOpenStartToEndContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::NumberRangeOpenStartToEndContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeOpenStartToEnd(this);
}
void UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeOpenStartToEnd(this);
}

std::any UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeOpenStartToEnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberRangeStartToOpenEndContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::BRACEOPEN() {
  return getToken(UserAgentTreeWalkerParser::BRACEOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::BRACECLOSE() {
  return getToken(UserAgentTreeWalkerParser::BRACECLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::NumberRangeStartToOpenEndContext(NumberRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberRangeStartToOpenEnd(this);
}
void UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberRangeStartToOpenEnd(this);
}

std::any UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitNumberRangeStartToOpenEnd(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::NumberRangeContext* UserAgentTreeWalkerParser::numberRange() {
  NumberRangeContext *_localctx = _tracker.createInstance<NumberRangeContext>(_ctx, getState());
  enterRule(_localctx, 12, UserAgentTreeWalkerParser::RuleNumberRange);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(291);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeStartToEndContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(271);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(272);
      antlrcpp::downCast<NumberRangeStartToEndContext *>(_localctx)->rangeStart = match(UserAgentTreeWalkerParser::NUMBER);
      setState(273);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(274);
      antlrcpp::downCast<NumberRangeStartToEndContext *>(_localctx)->rangeEnd = match(UserAgentTreeWalkerParser::NUMBER);
      setState(275);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeOpenStartToEndContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(276);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(277);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(278);
      antlrcpp::downCast<NumberRangeOpenStartToEndContext *>(_localctx)->rangeEnd = match(UserAgentTreeWalkerParser::NUMBER);
      setState(279);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeStartToOpenEndContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(280);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(281);
      antlrcpp::downCast<NumberRangeStartToOpenEndContext *>(_localctx)->rangeStart = match(UserAgentTreeWalkerParser::NUMBER);
      setState(282);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(283);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeSingleValueContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(284);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(285);
      antlrcpp::downCast<NumberRangeSingleValueContext *>(_localctx)->count = match(UserAgentTreeWalkerParser::NUMBER);
      setState(286);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeAllContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(287);
      match(UserAgentTreeWalkerParser::BRACEOPEN);
      setState(288);
      match(UserAgentTreeWalkerParser::STAR);
      setState(289);
      match(UserAgentTreeWalkerParser::BRACECLOSE);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::NumberRangeEmptyContext>(_localctx);
      enterOuterAlt(_localctx, 6);

      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WordRangeContext ------------------------------------------------------------------

UserAgentTreeWalkerParser::WordRangeContext::WordRangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t UserAgentTreeWalkerParser::WordRangeContext::getRuleIndex() const {
  return UserAgentTreeWalkerParser::RuleWordRange;
}

void UserAgentTreeWalkerParser::WordRangeContext::copyFrom(WordRangeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- WordRangeFirstWordsContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeFirstWordsContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeFirstWordsContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeFirstWordsContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeFirstWordsContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::WordRangeFirstWordsContext::WordRangeFirstWordsContext(WordRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::WordRangeFirstWordsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWordRangeFirstWords(this);
}
void UserAgentTreeWalkerParser::WordRangeFirstWordsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWordRangeFirstWords(this);
}

std::any UserAgentTreeWalkerParser::WordRangeFirstWordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitWordRangeFirstWords(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WordRangeLastWordsContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeLastWordsContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeLastWordsContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeLastWordsContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeLastWordsContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::WordRangeLastWordsContext::WordRangeLastWordsContext(WordRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::WordRangeLastWordsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWordRangeLastWords(this);
}
void UserAgentTreeWalkerParser::WordRangeLastWordsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWordRangeLastWords(this);
}

std::any UserAgentTreeWalkerParser::WordRangeLastWordsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitWordRangeLastWords(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WordRangeStartToEndContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeStartToEndContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeStartToEndContext::MINUS() {
  return getToken(UserAgentTreeWalkerParser::MINUS, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeStartToEndContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

std::vector<tree::TerminalNode *> UserAgentTreeWalkerParser::WordRangeStartToEndContext::NUMBER() {
  return getTokens(UserAgentTreeWalkerParser::NUMBER);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeStartToEndContext::NUMBER(size_t i) {
  return getToken(UserAgentTreeWalkerParser::NUMBER, i);
}

UserAgentTreeWalkerParser::WordRangeStartToEndContext::WordRangeStartToEndContext(WordRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::WordRangeStartToEndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWordRangeStartToEnd(this);
}
void UserAgentTreeWalkerParser::WordRangeStartToEndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWordRangeStartToEnd(this);
}

std::any UserAgentTreeWalkerParser::WordRangeStartToEndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitWordRangeStartToEnd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WordRangeSingleWordContext ------------------------------------------------------------------

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeSingleWordContext::BLOCKOPEN() {
  return getToken(UserAgentTreeWalkerParser::BLOCKOPEN, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeSingleWordContext::BLOCKCLOSE() {
  return getToken(UserAgentTreeWalkerParser::BLOCKCLOSE, 0);
}

tree::TerminalNode* UserAgentTreeWalkerParser::WordRangeSingleWordContext::NUMBER() {
  return getToken(UserAgentTreeWalkerParser::NUMBER, 0);
}

UserAgentTreeWalkerParser::WordRangeSingleWordContext::WordRangeSingleWordContext(WordRangeContext *ctx) { copyFrom(ctx); }

void UserAgentTreeWalkerParser::WordRangeSingleWordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWordRangeSingleWord(this);
}
void UserAgentTreeWalkerParser::WordRangeSingleWordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<UserAgentTreeWalkerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWordRangeSingleWord(this);
}

std::any UserAgentTreeWalkerParser::WordRangeSingleWordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<UserAgentTreeWalkerVisitor*>(visitor))
    return parserVisitor->visitWordRangeSingleWord(this);
  else
    return visitor->visitChildren(this);
}
UserAgentTreeWalkerParser::WordRangeContext* UserAgentTreeWalkerParser::wordRange() {
  WordRangeContext *_localctx = _tracker.createInstance<WordRangeContext>(_ctx, getState());
  enterRule(_localctx, 14, UserAgentTreeWalkerParser::RuleWordRange);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(309);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::WordRangeStartToEndContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(293);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(294);
      antlrcpp::downCast<WordRangeStartToEndContext *>(_localctx)->firstWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(295);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(296);
      antlrcpp::downCast<WordRangeStartToEndContext *>(_localctx)->lastWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(297);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::WordRangeFirstWordsContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(298);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(299);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(300);
      antlrcpp::downCast<WordRangeFirstWordsContext *>(_localctx)->lastWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(301);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::WordRangeLastWordsContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(302);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(303);
      antlrcpp::downCast<WordRangeLastWordsContext *>(_localctx)->firstWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(304);
      match(UserAgentTreeWalkerParser::MINUS);
      setState(305);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<UserAgentTreeWalkerParser::WordRangeSingleWordContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(306);
      match(UserAgentTreeWalkerParser::BLOCKOPEN);
      setState(307);
      antlrcpp::downCast<WordRangeSingleWordContext *>(_localctx)->singleWord = match(UserAgentTreeWalkerParser::NUMBER);
      setState(308);
      match(UserAgentTreeWalkerParser::BLOCKCLOSE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool UserAgentTreeWalkerParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 3: return matcherSempred(antlrcpp::downCast<MatcherContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool UserAgentTreeWalkerParser::matcherSempred(MatcherContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void UserAgentTreeWalkerParser::initialize() {
  ::antlr4::internal::call_once(useragenttreewalkerParserOnceFlag, useragenttreewalkerParserInitialize);
}
