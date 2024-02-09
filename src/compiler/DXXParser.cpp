
// Generated from templates/DXXParser.g4 by ANTLR 4.13.1


#include "DXXParserVisitor.h"

#include "DXXParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct DXXParserStaticData final {
  DXXParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  DXXParserStaticData(const DXXParserStaticData&) = delete;
  DXXParserStaticData(DXXParserStaticData&&) = delete;
  DXXParserStaticData& operator=(const DXXParserStaticData&) = delete;
  DXXParserStaticData& operator=(DXXParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag dxxparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
DXXParserStaticData *dxxparserParserStaticData = nullptr;

void dxxparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (dxxparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(dxxparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<DXXParserStaticData>(
    std::vector<std::string>{
      "stat", "expressions", "boolean", "negative", "importLib", "functionDefine", 
      "function", "return", "lambdaFunction", "functionHead", "functionCall", 
      "paramList", "callParamList", "varDefine", "varSet", "ifStatement", 
      "switchStatement", "caseStatement", "defaultStatement", "whileLoop", 
      "doWhileLoop", "foreachLoop", "goto", "gotoLabelDefine", "enum", "enumList", 
      "class", "classMethods", "operatorDefine", "block", "templateList", 
      "callTemplateList", "templateListSub", "callTemplateSub", "try", "trySub", 
      "catchSub", "finallySub", "throw", "theType", "theTypeSub", "idEx", 
      "info", "native", "assigns", "allOperators"
    },
    std::vector<std::string>{
      "", "'asm'", "'bool'", "'break'", "'case'", "'catch'", "'char'", "'class'", 
      "'continue'", "'default'", "'delete'", "'do'", "'else'", "'enum'", 
      "'extends'", "'false'", "'final'", "'finally'", "'float'", "'foreach'", 
      "'goto'", "'if'", "'import'", "'inline'", "'int'", "'implements'", 
      "'long'", "'native'", "'new'", "'null'", "'object'", "'operator'", 
      "'override'", "'private'", "'protected'", "'public'", "'return'", 
      "'short'", "'static'", "'string'", "'super'", "'switch'", "'template'", 
      "'this'", "'throw'", "'true'", "'try'", "'typedef'", "'virtual'", 
      "'void'", "'while'", "'('", "')'", "'['", "']'", "'{'", "'}'", "'=>'", 
      "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'&'", "'|'", "'~'", "", 
      "'='", "':='", "'<'", "'>'", "'+='", "'-='", "'*='", "'/='", "'%='", 
      "'^='", "'&='", "'|='", "'<<='", "'>>='", "'=='", "'!='", "'<='", 
      "'>='", "", "", "'++'", "'--'", "','", "'\\u003F'", "':'", "';'", 
      "'.'", "'...'", "'<<'", "'>>'", "", "'__constructor__'", "'__destructor__'"
    },
    std::vector<std::string>{
      "", "Asm", "Bool", "Break", "Case", "Catch", "Char", "Class", "Continue", 
      "Default", "Delete", "Do", "Else", "Enum", "Extends", "False", "Final", 
      "Finally", "Float", "Foreach", "Goto", "If", "Import", "Inline", "Int", 
      "Implements", "Long", "Native", "New", "Null", "Object", "Operator", 
      "Override", "Private", "Protected", "Public", "Return", "Short", "Static", 
      "String", "Super", "Switch", "Template", "This", "Throw", "True", 
      "Try", "Typedef", "Virtual", "Void", "While", "LeftParen", "RightParen", 
      "LeftBracket", "RightBracket", "LeftBrace", "RightBrace", "Arrow", 
      "Plus", "Minus", "Star", "Div", "Mod", "Caret", "And", "Or", "Tilde", 
      "Not", "Assign", "ColonAssign", "Less", "Greater", "PlusAssign", "MinusAssign", 
      "StarAssign", "DivAssign", "ModAssign", "XorAssign", "AndAssign", 
      "OrAssign", "LeftShiftAssign", "RightShiftAssign", "Equal", "NotEqual", 
      "LessEqual", "GreaterEqual", "AndAnd", "OrOr", "PlusPlus", "MinusMinus", 
      "Comma", "Question", "Colon", "Semi", "Dot", "Ellipsis", "LeftShift", 
      "RightShift", "ID", "Constructor", "Destructor", "Whitespace", "Newline", 
      "BlockComment", "LineComment", "IntegerData", "FloatingNumberData", 
      "StringData"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,107,545,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,1,0,5,0,94,8,0,10,0,12,0,97,9,0,1,0,
  	1,0,1,1,1,1,1,1,1,1,1,1,3,1,106,8,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,146,8,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,184,
  	8,1,10,1,12,1,187,9,1,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,4,1,5,1,5,1,6,1,6,
  	1,6,1,7,1,7,1,7,1,8,1,8,1,8,1,8,1,9,3,9,210,8,9,1,9,5,9,213,8,9,10,9,
  	12,9,216,9,9,1,9,1,9,1,9,3,9,221,8,9,1,9,1,9,1,9,1,9,1,10,1,10,3,10,229,
  	8,10,1,10,1,10,3,10,233,8,10,1,10,1,10,1,11,1,11,1,11,5,11,240,8,11,10,
  	11,12,11,243,9,11,1,11,1,11,3,11,247,8,11,1,12,1,12,1,12,5,12,252,8,12,
  	10,12,12,12,255,9,12,1,13,1,13,5,13,259,8,13,10,13,12,13,262,9,13,1,13,
  	1,13,3,13,266,8,13,1,14,1,14,1,14,1,14,1,15,1,15,1,15,3,15,275,8,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,3,15,283,8,15,1,15,1,15,5,15,287,8,15,10,
  	15,12,15,290,9,15,1,15,1,15,1,15,5,15,295,8,15,10,15,12,15,298,9,15,1,
  	15,3,15,301,8,15,1,16,1,16,1,16,1,16,1,16,1,16,5,16,309,8,16,10,16,12,
  	16,312,9,16,1,16,3,16,315,8,16,1,16,1,16,1,17,1,17,1,17,1,17,1,18,1,18,
  	1,18,5,18,326,8,18,10,18,12,18,329,9,18,1,18,1,18,1,19,1,19,1,19,1,19,
  	1,19,3,19,338,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,21,1,21,1,21,1,21,
  	3,21,350,8,21,1,21,1,21,1,21,1,21,3,21,356,8,21,1,22,1,22,1,22,1,23,1,
  	23,1,23,1,23,1,24,1,24,1,24,1,24,3,24,369,8,24,1,24,1,24,1,25,1,25,1,
  	25,5,25,376,8,25,10,25,12,25,379,9,25,1,26,1,26,1,26,1,26,1,26,5,26,386,
  	8,26,10,26,12,26,389,9,26,3,26,391,8,26,1,26,1,26,5,26,395,8,26,10,26,
  	12,26,398,9,26,3,26,400,8,26,1,26,1,26,5,26,404,8,26,10,26,12,26,407,
  	9,26,1,26,1,26,1,27,1,27,1,28,1,28,1,28,1,28,3,28,417,8,28,1,28,1,28,
  	1,28,1,28,3,28,423,8,28,1,29,1,29,5,29,427,8,29,10,29,12,29,430,9,29,
  	1,29,1,29,1,30,1,30,1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,32,1,32,3,32,
  	445,8,32,1,32,1,32,1,32,3,32,450,8,32,1,32,1,32,1,32,3,32,455,8,32,1,
  	32,1,32,1,32,3,32,460,8,32,5,32,462,8,32,10,32,12,32,465,9,32,1,33,1,
  	33,1,33,5,33,470,8,33,10,33,12,33,473,9,33,1,34,1,34,5,34,477,8,34,10,
  	34,12,34,480,9,34,1,34,3,34,483,8,34,1,35,1,35,1,35,1,36,1,36,1,36,1,
  	36,3,36,492,8,36,1,36,1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,1,39,5,
  	39,504,8,39,10,39,12,39,507,9,39,1,39,1,39,1,40,1,40,1,41,1,41,5,41,515,
  	8,41,10,41,12,41,518,9,41,1,41,1,41,1,42,1,42,1,42,1,42,1,42,1,42,1,42,
  	1,42,1,42,1,42,3,42,532,8,42,1,43,1,43,1,43,1,43,1,43,1,43,1,43,1,44,
  	1,44,1,45,1,45,1,45,0,1,2,46,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,
  	30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,
  	76,78,80,82,84,86,88,90,0,10,2,0,66,67,88,89,1,0,60,62,1,0,58,59,1,0,
  	96,97,2,0,70,71,84,85,1,0,82,83,2,0,15,15,45,45,7,0,2,2,18,18,24,24,30,
  	30,39,39,49,49,98,98,2,0,68,69,72,81,4,0,57,89,92,92,94,94,96,97,596,
  	0,95,1,0,0,0,2,145,1,0,0,0,4,188,1,0,0,0,6,190,1,0,0,0,8,193,1,0,0,0,
  	10,196,1,0,0,0,12,198,1,0,0,0,14,201,1,0,0,0,16,204,1,0,0,0,18,209,1,
  	0,0,0,20,226,1,0,0,0,22,236,1,0,0,0,24,248,1,0,0,0,26,256,1,0,0,0,28,
  	267,1,0,0,0,30,271,1,0,0,0,32,302,1,0,0,0,34,318,1,0,0,0,36,322,1,0,0,
  	0,38,332,1,0,0,0,40,339,1,0,0,0,42,345,1,0,0,0,44,357,1,0,0,0,46,360,
  	1,0,0,0,48,364,1,0,0,0,50,372,1,0,0,0,52,380,1,0,0,0,54,410,1,0,0,0,56,
  	412,1,0,0,0,58,424,1,0,0,0,60,433,1,0,0,0,62,438,1,0,0,0,64,444,1,0,0,
  	0,66,466,1,0,0,0,68,474,1,0,0,0,70,484,1,0,0,0,72,487,1,0,0,0,74,496,
  	1,0,0,0,76,499,1,0,0,0,78,505,1,0,0,0,80,510,1,0,0,0,82,516,1,0,0,0,84,
  	531,1,0,0,0,86,533,1,0,0,0,88,540,1,0,0,0,90,542,1,0,0,0,92,94,3,2,1,
  	0,93,92,1,0,0,0,94,97,1,0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,98,1,0,0,
  	0,97,95,1,0,0,0,98,99,5,0,0,1,99,1,1,0,0,0,100,101,6,1,-1,0,101,146,3,
  	8,4,0,102,146,3,56,28,0,103,105,5,51,0,0,104,106,3,2,1,0,105,104,1,0,
  	0,0,105,106,1,0,0,0,106,107,1,0,0,0,107,146,5,52,0,0,108,109,7,0,0,0,
  	109,146,3,2,1,43,110,111,5,51,0,0,111,112,3,78,39,0,112,113,5,52,0,0,
  	113,114,3,2,1,42,114,146,1,0,0,0,115,146,3,6,3,0,116,146,3,28,14,0,117,
  	146,3,12,6,0,118,146,3,10,5,0,119,146,3,20,10,0,120,146,3,14,7,0,121,
  	146,3,26,13,0,122,146,3,30,15,0,123,146,3,32,16,0,124,146,3,38,19,0,125,
  	146,3,40,20,0,126,146,3,42,21,0,127,146,3,44,22,0,128,146,3,46,23,0,129,
  	146,3,48,24,0,130,146,3,52,26,0,131,146,3,68,34,0,132,146,3,76,38,0,133,
  	146,3,82,41,0,134,146,5,3,0,0,135,146,5,8,0,0,136,146,5,105,0,0,137,146,
  	5,106,0,0,138,146,5,107,0,0,139,146,3,4,2,0,140,146,5,29,0,0,141,146,
  	5,49,0,0,142,146,5,93,0,0,143,146,3,78,39,0,144,146,3,16,8,0,145,100,
  	1,0,0,0,145,102,1,0,0,0,145,103,1,0,0,0,145,108,1,0,0,0,145,110,1,0,0,
  	0,145,115,1,0,0,0,145,116,1,0,0,0,145,117,1,0,0,0,145,118,1,0,0,0,145,
  	119,1,0,0,0,145,120,1,0,0,0,145,121,1,0,0,0,145,122,1,0,0,0,145,123,1,
  	0,0,0,145,124,1,0,0,0,145,125,1,0,0,0,145,126,1,0,0,0,145,127,1,0,0,0,
  	145,128,1,0,0,0,145,129,1,0,0,0,145,130,1,0,0,0,145,131,1,0,0,0,145,132,
  	1,0,0,0,145,133,1,0,0,0,145,134,1,0,0,0,145,135,1,0,0,0,145,136,1,0,0,
  	0,145,137,1,0,0,0,145,138,1,0,0,0,145,139,1,0,0,0,145,140,1,0,0,0,145,
  	141,1,0,0,0,145,142,1,0,0,0,145,143,1,0,0,0,145,144,1,0,0,0,146,185,1,
  	0,0,0,147,148,10,41,0,0,148,149,7,1,0,0,149,184,3,2,1,42,150,151,10,40,
  	0,0,151,152,7,2,0,0,152,184,3,2,1,41,153,154,10,39,0,0,154,155,7,3,0,
  	0,155,184,3,2,1,40,156,157,10,38,0,0,157,158,7,4,0,0,158,184,3,2,1,39,
  	159,160,10,37,0,0,160,161,7,5,0,0,161,184,3,2,1,38,162,163,10,36,0,0,
  	163,164,5,64,0,0,164,184,3,2,1,37,165,166,10,35,0,0,166,167,5,63,0,0,
  	167,184,3,2,1,36,168,169,10,34,0,0,169,170,5,65,0,0,170,184,3,2,1,35,
  	171,172,10,33,0,0,172,173,5,87,0,0,173,184,3,2,1,34,174,175,10,32,0,0,
  	175,176,5,86,0,0,176,184,3,2,1,33,177,178,10,31,0,0,178,179,5,91,0,0,
  	179,180,3,2,1,0,180,181,5,92,0,0,181,182,3,2,1,32,182,184,1,0,0,0,183,
  	147,1,0,0,0,183,150,1,0,0,0,183,153,1,0,0,0,183,156,1,0,0,0,183,159,1,
  	0,0,0,183,162,1,0,0,0,183,165,1,0,0,0,183,168,1,0,0,0,183,171,1,0,0,0,
  	183,174,1,0,0,0,183,177,1,0,0,0,184,187,1,0,0,0,185,183,1,0,0,0,185,186,
  	1,0,0,0,186,3,1,0,0,0,187,185,1,0,0,0,188,189,7,6,0,0,189,5,1,0,0,0,190,
  	191,5,59,0,0,191,192,3,2,1,0,192,7,1,0,0,0,193,194,5,22,0,0,194,195,3,
  	82,41,0,195,9,1,0,0,0,196,197,3,18,9,0,197,11,1,0,0,0,198,199,3,18,9,
  	0,199,200,3,58,29,0,200,13,1,0,0,0,201,202,5,36,0,0,202,203,3,2,1,0,203,
  	15,1,0,0,0,204,205,5,53,0,0,205,206,5,54,0,0,206,207,3,58,29,0,207,17,
  	1,0,0,0,208,210,3,60,30,0,209,208,1,0,0,0,209,210,1,0,0,0,210,214,1,0,
  	0,0,211,213,3,84,42,0,212,211,1,0,0,0,213,216,1,0,0,0,214,212,1,0,0,0,
  	214,215,1,0,0,0,215,217,1,0,0,0,216,214,1,0,0,0,217,218,5,98,0,0,218,
  	220,5,51,0,0,219,221,3,22,11,0,220,219,1,0,0,0,220,221,1,0,0,0,221,222,
  	1,0,0,0,222,223,5,52,0,0,223,224,5,57,0,0,224,225,3,78,39,0,225,19,1,
  	0,0,0,226,228,3,82,41,0,227,229,3,62,31,0,228,227,1,0,0,0,228,229,1,0,
  	0,0,229,230,1,0,0,0,230,232,5,51,0,0,231,233,3,24,12,0,232,231,1,0,0,
  	0,232,233,1,0,0,0,233,234,1,0,0,0,234,235,5,52,0,0,235,21,1,0,0,0,236,
  	241,3,26,13,0,237,238,5,90,0,0,238,240,3,26,13,0,239,237,1,0,0,0,240,
  	243,1,0,0,0,241,239,1,0,0,0,241,242,1,0,0,0,242,246,1,0,0,0,243,241,1,
  	0,0,0,244,245,5,90,0,0,245,247,5,95,0,0,246,244,1,0,0,0,246,247,1,0,0,
  	0,247,23,1,0,0,0,248,253,3,2,1,0,249,250,5,90,0,0,250,252,3,2,1,0,251,
  	249,1,0,0,0,252,255,1,0,0,0,253,251,1,0,0,0,253,254,1,0,0,0,254,25,1,
  	0,0,0,255,253,1,0,0,0,256,260,3,78,39,0,257,259,3,84,42,0,258,257,1,0,
  	0,0,259,262,1,0,0,0,260,258,1,0,0,0,260,261,1,0,0,0,261,265,1,0,0,0,262,
  	260,1,0,0,0,263,266,3,28,14,0,264,266,5,98,0,0,265,263,1,0,0,0,265,264,
  	1,0,0,0,266,27,1,0,0,0,267,268,3,82,41,0,268,269,3,88,44,0,269,270,3,
  	2,1,0,270,29,1,0,0,0,271,272,5,21,0,0,272,274,5,51,0,0,273,275,3,2,1,
  	0,274,273,1,0,0,0,274,275,1,0,0,0,275,276,1,0,0,0,276,277,5,52,0,0,277,
  	288,3,58,29,0,278,279,5,12,0,0,279,280,5,21,0,0,280,282,5,51,0,0,281,
  	283,3,2,1,0,282,281,1,0,0,0,282,283,1,0,0,0,283,284,1,0,0,0,284,285,5,
  	52,0,0,285,287,3,58,29,0,286,278,1,0,0,0,287,290,1,0,0,0,288,286,1,0,
  	0,0,288,289,1,0,0,0,289,300,1,0,0,0,290,288,1,0,0,0,291,292,5,12,0,0,
  	292,296,5,55,0,0,293,295,3,2,1,0,294,293,1,0,0,0,295,298,1,0,0,0,296,
  	294,1,0,0,0,296,297,1,0,0,0,297,299,1,0,0,0,298,296,1,0,0,0,299,301,5,
  	56,0,0,300,291,1,0,0,0,300,301,1,0,0,0,301,31,1,0,0,0,302,303,5,41,0,
  	0,303,304,5,51,0,0,304,305,3,2,1,0,305,306,5,52,0,0,306,310,5,55,0,0,
  	307,309,3,34,17,0,308,307,1,0,0,0,309,312,1,0,0,0,310,308,1,0,0,0,310,
  	311,1,0,0,0,311,314,1,0,0,0,312,310,1,0,0,0,313,315,3,36,18,0,314,313,
  	1,0,0,0,314,315,1,0,0,0,315,316,1,0,0,0,316,317,5,56,0,0,317,33,1,0,0,
  	0,318,319,5,4,0,0,319,320,3,2,1,0,320,321,3,58,29,0,321,35,1,0,0,0,322,
  	323,5,9,0,0,323,327,5,55,0,0,324,326,3,2,1,0,325,324,1,0,0,0,326,329,
  	1,0,0,0,327,325,1,0,0,0,327,328,1,0,0,0,328,330,1,0,0,0,329,327,1,0,0,
  	0,330,331,5,56,0,0,331,37,1,0,0,0,332,333,5,50,0,0,333,334,5,51,0,0,334,
  	335,3,2,1,0,335,337,5,52,0,0,336,338,3,58,29,0,337,336,1,0,0,0,337,338,
  	1,0,0,0,338,39,1,0,0,0,339,340,3,38,19,0,340,341,5,11,0,0,341,342,5,51,
  	0,0,342,343,3,2,1,0,343,344,5,52,0,0,344,41,1,0,0,0,345,346,5,19,0,0,
  	346,349,5,51,0,0,347,350,3,26,13,0,348,350,3,82,41,0,349,347,1,0,0,0,
  	349,348,1,0,0,0,350,351,1,0,0,0,351,352,5,92,0,0,352,353,3,2,1,0,353,
  	355,5,52,0,0,354,356,3,58,29,0,355,354,1,0,0,0,355,356,1,0,0,0,356,43,
  	1,0,0,0,357,358,5,20,0,0,358,359,5,98,0,0,359,45,1,0,0,0,360,361,5,98,
  	0,0,361,362,5,92,0,0,362,363,3,58,29,0,363,47,1,0,0,0,364,365,5,13,0,
  	0,365,366,5,98,0,0,366,368,5,55,0,0,367,369,3,50,25,0,368,367,1,0,0,0,
  	368,369,1,0,0,0,369,370,1,0,0,0,370,371,5,56,0,0,371,49,1,0,0,0,372,377,
  	5,98,0,0,373,374,5,90,0,0,374,376,5,98,0,0,375,373,1,0,0,0,376,379,1,
  	0,0,0,377,375,1,0,0,0,377,378,1,0,0,0,378,51,1,0,0,0,379,377,1,0,0,0,
  	380,381,3,60,30,0,381,382,5,7,0,0,382,390,5,98,0,0,383,387,5,14,0,0,384,
  	386,3,82,41,0,385,384,1,0,0,0,386,389,1,0,0,0,387,385,1,0,0,0,387,388,
  	1,0,0,0,388,391,1,0,0,0,389,387,1,0,0,0,390,383,1,0,0,0,390,391,1,0,0,
  	0,391,399,1,0,0,0,392,396,5,25,0,0,393,395,3,82,41,0,394,393,1,0,0,0,
  	395,398,1,0,0,0,396,394,1,0,0,0,396,397,1,0,0,0,397,400,1,0,0,0,398,396,
  	1,0,0,0,399,392,1,0,0,0,399,400,1,0,0,0,400,401,1,0,0,0,401,405,5,55,
  	0,0,402,404,3,54,27,0,403,402,1,0,0,0,404,407,1,0,0,0,405,403,1,0,0,0,
  	405,406,1,0,0,0,406,408,1,0,0,0,407,405,1,0,0,0,408,409,5,56,0,0,409,
  	53,1,0,0,0,410,411,3,2,1,0,411,55,1,0,0,0,412,413,5,31,0,0,413,414,3,
  	90,45,0,414,416,5,51,0,0,415,417,3,22,11,0,416,415,1,0,0,0,416,417,1,
  	0,0,0,417,418,1,0,0,0,418,419,5,52,0,0,419,420,5,57,0,0,420,422,3,78,
  	39,0,421,423,3,58,29,0,422,421,1,0,0,0,422,423,1,0,0,0,423,57,1,0,0,0,
  	424,428,5,55,0,0,425,427,3,2,1,0,426,425,1,0,0,0,427,430,1,0,0,0,428,
  	426,1,0,0,0,428,429,1,0,0,0,429,431,1,0,0,0,430,428,1,0,0,0,431,432,5,
  	56,0,0,432,59,1,0,0,0,433,434,5,42,0,0,434,435,5,70,0,0,435,436,3,64,
  	32,0,436,437,5,71,0,0,437,61,1,0,0,0,438,439,5,70,0,0,439,440,3,66,33,
  	0,440,441,5,71,0,0,441,63,1,0,0,0,442,445,5,7,0,0,443,445,3,78,39,0,444,
  	442,1,0,0,0,444,443,1,0,0,0,445,446,1,0,0,0,446,449,5,98,0,0,447,448,
  	5,68,0,0,448,450,3,2,1,0,449,447,1,0,0,0,449,450,1,0,0,0,450,463,1,0,
  	0,0,451,454,5,90,0,0,452,455,5,7,0,0,453,455,3,78,39,0,454,452,1,0,0,
  	0,454,453,1,0,0,0,455,456,1,0,0,0,456,459,5,98,0,0,457,458,5,68,0,0,458,
  	460,3,2,1,0,459,457,1,0,0,0,459,460,1,0,0,0,460,462,1,0,0,0,461,451,1,
  	0,0,0,462,465,1,0,0,0,463,461,1,0,0,0,463,464,1,0,0,0,464,65,1,0,0,0,
  	465,463,1,0,0,0,466,471,3,2,1,0,467,468,5,90,0,0,468,470,3,2,1,0,469,
  	467,1,0,0,0,470,473,1,0,0,0,471,469,1,0,0,0,471,472,1,0,0,0,472,67,1,
  	0,0,0,473,471,1,0,0,0,474,478,3,70,35,0,475,477,3,72,36,0,476,475,1,0,
  	0,0,477,480,1,0,0,0,478,476,1,0,0,0,478,479,1,0,0,0,479,482,1,0,0,0,480,
  	478,1,0,0,0,481,483,3,74,37,0,482,481,1,0,0,0,482,483,1,0,0,0,483,69,
  	1,0,0,0,484,485,5,46,0,0,485,486,3,58,29,0,486,71,1,0,0,0,487,488,5,5,
  	0,0,488,491,5,51,0,0,489,492,3,26,13,0,490,492,5,95,0,0,491,489,1,0,0,
  	0,491,490,1,0,0,0,492,493,1,0,0,0,493,494,5,52,0,0,494,495,3,58,29,0,
  	495,73,1,0,0,0,496,497,5,17,0,0,497,498,3,58,29,0,498,75,1,0,0,0,499,
  	500,5,44,0,0,500,501,3,2,1,0,501,77,1,0,0,0,502,504,3,84,42,0,503,502,
  	1,0,0,0,504,507,1,0,0,0,505,503,1,0,0,0,505,506,1,0,0,0,506,508,1,0,0,
  	0,507,505,1,0,0,0,508,509,3,80,40,0,509,79,1,0,0,0,510,511,7,7,0,0,511,
  	81,1,0,0,0,512,513,5,98,0,0,513,515,5,94,0,0,514,512,1,0,0,0,515,518,
  	1,0,0,0,516,514,1,0,0,0,516,517,1,0,0,0,517,519,1,0,0,0,518,516,1,0,0,
  	0,519,520,5,98,0,0,520,83,1,0,0,0,521,532,5,16,0,0,522,532,5,32,0,0,523,
  	532,5,23,0,0,524,532,5,38,0,0,525,532,5,35,0,0,526,532,5,34,0,0,527,532,
  	5,33,0,0,528,532,5,99,0,0,529,532,5,100,0,0,530,532,3,86,43,0,531,521,
  	1,0,0,0,531,522,1,0,0,0,531,523,1,0,0,0,531,524,1,0,0,0,531,525,1,0,0,
  	0,531,526,1,0,0,0,531,527,1,0,0,0,531,528,1,0,0,0,531,529,1,0,0,0,531,
  	530,1,0,0,0,532,85,1,0,0,0,533,534,5,27,0,0,534,535,5,51,0,0,535,536,
  	5,107,0,0,536,537,5,90,0,0,537,538,5,107,0,0,538,539,5,52,0,0,539,87,
  	1,0,0,0,540,541,7,8,0,0,541,89,1,0,0,0,542,543,7,9,0,0,543,91,1,0,0,0,
  	48,95,105,145,183,185,209,214,220,228,232,241,246,253,260,265,274,282,
  	288,296,300,310,314,327,337,349,355,368,377,387,390,396,399,405,416,422,
  	428,444,449,454,459,463,471,478,482,491,505,516,531
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  dxxparserParserStaticData = staticData.release();
}

}

DXXParser::DXXParser(TokenStream *input) : DXXParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

DXXParser::DXXParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  DXXParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *dxxparserParserStaticData->atn, dxxparserParserStaticData->decisionToDFA, dxxparserParserStaticData->sharedContextCache, options);
}

DXXParser::~DXXParser() {
  delete _interpreter;
}

const atn::ATN& DXXParser::getATN() const {
  return *dxxparserParserStaticData->atn;
}

std::string DXXParser::getGrammarFileName() const {
  return "DXXParser.g4";
}

const std::vector<std::string>& DXXParser::getRuleNames() const {
  return dxxparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& DXXParser::getVocabulary() const {
  return dxxparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView DXXParser::getSerializedATN() const {
  return dxxparserParserStaticData->serializedATN;
}


//----------------- StatContext ------------------------------------------------------------------

DXXParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::StatContext::EOF() {
  return getToken(DXXParser::EOF, 0);
}

std::vector<DXXParser::ExpressionsContext *> DXXParser::StatContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::StatContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}


size_t DXXParser::StatContext::getRuleIndex() const {
  return DXXParser::RuleStat;
}


std::any DXXParser::StatContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitStat(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::StatContext* DXXParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 0, DXXParser::RuleStat);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 589539305307611404) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & 3878502268931) != 0)) {
      setState(92);
      expressions(0);
      setState(97);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(98);
    match(DXXParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionsContext ------------------------------------------------------------------

DXXParser::ExpressionsContext::ExpressionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DXXParser::ExpressionsContext::getRuleIndex() const {
  return DXXParser::RuleExpressions;
}

void DXXParser::ExpressionsContext::copyFrom(ExpressionsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- VarSetExprContext ------------------------------------------------------------------

DXXParser::VarSetContext* DXXParser::VarSetExprContext::varSet() {
  return getRuleContext<DXXParser::VarSetContext>(0);
}

DXXParser::VarSetExprContext::VarSetExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::VarSetExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVarSetExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParensContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::ParensContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

tree::TerminalNode* DXXParser::ParensContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

DXXParser::ExpressionsContext* DXXParser::ParensContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}

DXXParser::ParensContext::ParensContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::ParensContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitParens(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DoWhileLoopExprContext ------------------------------------------------------------------

DXXParser::DoWhileLoopContext* DXXParser::DoWhileLoopExprContext::doWhileLoop() {
  return getRuleContext<DXXParser::DoWhileLoopContext>(0);
}

DXXParser::DoWhileLoopExprContext::DoWhileLoopExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::DoWhileLoopExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitDoWhileLoopExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntegerExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::IntegerExprContext::IntegerData() {
  return getToken(DXXParser::IntegerData, 0);
}

DXXParser::IntegerExprContext::IntegerExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::IntegerExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitIntegerExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NullExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::NullExprContext::Null() {
  return getToken(DXXParser::Null, 0);
}

DXXParser::NullExprContext::NullExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::NullExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNullExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VoidExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::VoidExprContext::Void() {
  return getToken(DXXParser::Void, 0);
}

DXXParser::VoidExprContext::VoidExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::VoidExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVoidExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExExprContext ------------------------------------------------------------------

DXXParser::IdExContext* DXXParser::IdExExprContext::idEx() {
  return getRuleContext<DXXParser::IdExContext>(0);
}

DXXParser::IdExExprContext::IdExExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::IdExExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitIdExExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegativeExprContext ------------------------------------------------------------------

DXXParser::NegativeContext* DXXParser::NegativeExprContext::negative() {
  return getRuleContext<DXXParser::NegativeContext>(0);
}

DXXParser::NegativeExprContext::NegativeExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::NegativeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNegativeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::BreakExprContext::Break() {
  return getToken(DXXParser::Break, 0);
}

DXXParser::BreakExprContext::BreakExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::BreakExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitBreakExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusClassExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::PlusClassExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::PlusClassExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::PlusClassExprContext::Plus() {
  return getToken(DXXParser::Plus, 0);
}

tree::TerminalNode* DXXParser::PlusClassExprContext::Minus() {
  return getToken(DXXParser::Minus, 0);
}

DXXParser::PlusClassExprContext::PlusClassExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::PlusClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitPlusClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- QuestionExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::QuestionExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::QuestionExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::QuestionExprContext::Question() {
  return getToken(DXXParser::Question, 0);
}

tree::TerminalNode* DXXParser::QuestionExprContext::Colon() {
  return getToken(DXXParser::Colon, 0);
}

DXXParser::QuestionExprContext::QuestionExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::QuestionExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitQuestionExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDefineExprContext ------------------------------------------------------------------

DXXParser::VarDefineContext* DXXParser::VarDefineExprContext::varDefine() {
  return getRuleContext<DXXParser::VarDefineContext>(0);
}

DXXParser::VarDefineExprContext::VarDefineExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::VarDefineExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVarDefineExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionExprContext ------------------------------------------------------------------

DXXParser::FunctionContext* DXXParser::FunctionExprContext::function() {
  return getRuleContext<DXXParser::FunctionContext>(0);
}

DXXParser::FunctionExprContext::FunctionExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::FunctionExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::StringExprContext::StringData() {
  return getToken(DXXParser::StringData, 0);
}

DXXParser::StringExprContext::StringExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::StringExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitStringExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfStatementExprContext ------------------------------------------------------------------

DXXParser::IfStatementContext* DXXParser::IfStatementExprContext::ifStatement() {
  return getRuleContext<DXXParser::IfStatementContext>(0);
}

DXXParser::IfStatementExprContext::IfStatementExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::IfStatementExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitIfStatementExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualOrNotEqualExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::EqualOrNotEqualExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::EqualOrNotEqualExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::EqualOrNotEqualExprContext::Equal() {
  return getToken(DXXParser::Equal, 0);
}

tree::TerminalNode* DXXParser::EqualOrNotEqualExprContext::NotEqual() {
  return getToken(DXXParser::NotEqual, 0);
}

DXXParser::EqualOrNotEqualExprContext::EqualOrNotEqualExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::EqualOrNotEqualExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitEqualOrNotEqualExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConvertExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::ConvertExprContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

DXXParser::TheTypeContext* DXXParser::ConvertExprContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
}

tree::TerminalNode* DXXParser::ConvertExprContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

DXXParser::ExpressionsContext* DXXParser::ConvertExprContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}

DXXParser::ConvertExprContext::ConvertExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::ConvertExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitConvertExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StarClassExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::StarClassExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::StarClassExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::StarClassExprContext::Star() {
  return getToken(DXXParser::Star, 0);
}

tree::TerminalNode* DXXParser::StarClassExprContext::Div() {
  return getToken(DXXParser::Div, 0);
}

tree::TerminalNode* DXXParser::StarClassExprContext::Mod() {
  return getToken(DXXParser::Mod, 0);
}

DXXParser::StarClassExprContext::StarClassExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::StarClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitStarClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallExprContext ------------------------------------------------------------------

DXXParser::FunctionCallContext* DXXParser::FunctionCallExprContext::functionCall() {
  return getRuleContext<DXXParser::FunctionCallContext>(0);
}

DXXParser::FunctionCallExprContext::FunctionCallExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::FunctionCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SwitchStatementExprContext ------------------------------------------------------------------

DXXParser::SwitchStatementContext* DXXParser::SwitchStatementExprContext::switchStatement() {
  return getRuleContext<DXXParser::SwitchStatementContext>(0);
}

DXXParser::SwitchStatementExprContext::SwitchStatementExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::SwitchStatementExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitSwitchStatementExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EnumExprContext ------------------------------------------------------------------

DXXParser::EnumContext* DXXParser::EnumExprContext::enum_() {
  return getRuleContext<DXXParser::EnumContext>(0);
}

DXXParser::EnumExprContext::EnumExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::EnumExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitEnumExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatingExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::FloatingExprContext::FloatingNumberData() {
  return getToken(DXXParser::FloatingNumberData, 0);
}

DXXParser::FloatingExprContext::FloatingExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::FloatingExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFloatingExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LessClassExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::LessClassExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::LessClassExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::LessClassExprContext::Less() {
  return getToken(DXXParser::Less, 0);
}

tree::TerminalNode* DXXParser::LessClassExprContext::Greater() {
  return getToken(DXXParser::Greater, 0);
}

tree::TerminalNode* DXXParser::LessClassExprContext::LessEqual() {
  return getToken(DXXParser::LessEqual, 0);
}

tree::TerminalNode* DXXParser::LessClassExprContext::GreaterEqual() {
  return getToken(DXXParser::GreaterEqual, 0);
}

DXXParser::LessClassExprContext::LessClassExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::LessClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitLessClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ImportExprContext ------------------------------------------------------------------

DXXParser::ImportLibContext* DXXParser::ImportExprContext::importLib() {
  return getRuleContext<DXXParser::ImportLibContext>(0);
}

DXXParser::ImportExprContext::ImportExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::ImportExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitImportExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForeachLoopExprContext ------------------------------------------------------------------

DXXParser::ForeachLoopContext* DXXParser::ForeachLoopExprContext::foreachLoop() {
  return getRuleContext<DXXParser::ForeachLoopContext>(0);
}

DXXParser::ForeachLoopExprContext::ForeachLoopExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::ForeachLoopExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitForeachLoopExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ThrowExprContext ------------------------------------------------------------------

DXXParser::ThrowContext* DXXParser::ThrowExprContext::throw_() {
  return getRuleContext<DXXParser::ThrowContext>(0);
}

DXXParser::ThrowExprContext::ThrowExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::ThrowExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitThrowExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrorExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::OrorExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::OrorExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::OrorExprContext::OrOr() {
  return getToken(DXXParser::OrOr, 0);
}

DXXParser::OrorExprContext::OrorExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::OrorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitOrorExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GotoExprContext ------------------------------------------------------------------

DXXParser::GotoContext* DXXParser::GotoExprContext::goto_() {
  return getRuleContext<DXXParser::GotoContext>(0);
}

DXXParser::GotoExprContext::GotoExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::GotoExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitGotoExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SemiExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::SemiExprContext::Semi() {
  return getToken(DXXParser::Semi, 0);
}

DXXParser::SemiExprContext::SemiExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::SemiExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitSemiExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeExprContext ------------------------------------------------------------------

DXXParser::TheTypeContext* DXXParser::TypeExprContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
}

DXXParser::TypeExprContext::TypeExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::TypeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTypeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotClassExprContext ------------------------------------------------------------------

DXXParser::ExpressionsContext* DXXParser::NotClassExprContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}

tree::TerminalNode* DXXParser::NotClassExprContext::Not() {
  return getToken(DXXParser::Not, 0);
}

tree::TerminalNode* DXXParser::NotClassExprContext::Tilde() {
  return getToken(DXXParser::Tilde, 0);
}

tree::TerminalNode* DXXParser::NotClassExprContext::PlusPlus() {
  return getToken(DXXParser::PlusPlus, 0);
}

tree::TerminalNode* DXXParser::NotClassExprContext::MinusMinus() {
  return getToken(DXXParser::MinusMinus, 0);
}

DXXParser::NotClassExprContext::NotClassExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::NotClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNotClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BooleanExprContext ------------------------------------------------------------------

DXXParser::BooleanContext* DXXParser::BooleanExprContext::boolean() {
  return getRuleContext<DXXParser::BooleanContext>(0);
}

DXXParser::BooleanExprContext::BooleanExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::BooleanExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitBooleanExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionDefineExprContext ------------------------------------------------------------------

DXXParser::FunctionDefineContext* DXXParser::FunctionDefineExprContext::functionDefine() {
  return getRuleContext<DXXParser::FunctionDefineContext>(0);
}

DXXParser::FunctionDefineExprContext::FunctionDefineExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::FunctionDefineExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDefineExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnExprContext ------------------------------------------------------------------

DXXParser::ReturnContext* DXXParser::ReturnExprContext::return_() {
  return getRuleContext<DXXParser::ReturnContext>(0);
}

DXXParser::ReturnExprContext::ReturnExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::ReturnExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitReturnExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassExprContext ------------------------------------------------------------------

DXXParser::ClassContext* DXXParser::ClassExprContext::class_() {
  return getRuleContext<DXXParser::ClassContext>(0);
}

DXXParser::ClassExprContext::ClassExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::ClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeftOrRightShiftExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::LeftOrRightShiftExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::LeftOrRightShiftExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::LeftOrRightShiftExprContext::LeftShift() {
  return getToken(DXXParser::LeftShift, 0);
}

tree::TerminalNode* DXXParser::LeftOrRightShiftExprContext::RightShift() {
  return getToken(DXXParser::RightShift, 0);
}

DXXParser::LeftOrRightShiftExprContext::LeftOrRightShiftExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::LeftOrRightShiftExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitLeftOrRightShiftExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::OrExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::OrExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::OrExprContext::Or() {
  return getToken(DXXParser::Or, 0);
}

DXXParser::OrExprContext::OrExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LambdaFunctionExprContext ------------------------------------------------------------------

DXXParser::LambdaFunctionContext* DXXParser::LambdaFunctionExprContext::lambdaFunction() {
  return getRuleContext<DXXParser::LambdaFunctionContext>(0);
}

DXXParser::LambdaFunctionExprContext::LambdaFunctionExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::LambdaFunctionExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitLambdaFunctionExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::ContinueExprContext::Continue() {
  return getToken(DXXParser::Continue, 0);
}

DXXParser::ContinueExprContext::ContinueExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::ContinueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitContinueExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndandExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::AndandExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::AndandExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::AndandExprContext::AndAnd() {
  return getToken(DXXParser::AndAnd, 0);
}

DXXParser::AndandExprContext::AndandExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::AndandExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitAndandExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileLoopExprContext ------------------------------------------------------------------

DXXParser::WhileLoopContext* DXXParser::WhileLoopExprContext::whileLoop() {
  return getRuleContext<DXXParser::WhileLoopContext>(0);
}

DXXParser::WhileLoopExprContext::WhileLoopExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::WhileLoopExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWhileLoopExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CaretExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::CaretExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::CaretExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::CaretExprContext::Caret() {
  return getToken(DXXParser::Caret, 0);
}

DXXParser::CaretExprContext::CaretExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::CaretExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitCaretExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TryExprContext ------------------------------------------------------------------

DXXParser::TryContext* DXXParser::TryExprContext::try_() {
  return getRuleContext<DXXParser::TryContext>(0);
}

DXXParser::TryExprContext::TryExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::TryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GotoLabelDefineExprContext ------------------------------------------------------------------

DXXParser::GotoLabelDefineContext* DXXParser::GotoLabelDefineExprContext::gotoLabelDefine() {
  return getRuleContext<DXXParser::GotoLabelDefineContext>(0);
}

DXXParser::GotoLabelDefineExprContext::GotoLabelDefineExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::GotoLabelDefineExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitGotoLabelDefineExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OperatorDefineExprContext ------------------------------------------------------------------

DXXParser::OperatorDefineContext* DXXParser::OperatorDefineExprContext::operatorDefine() {
  return getRuleContext<DXXParser::OperatorDefineContext>(0);
}

DXXParser::OperatorDefineExprContext::OperatorDefineExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::OperatorDefineExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitOperatorDefineExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndExprContext ------------------------------------------------------------------

std::vector<DXXParser::ExpressionsContext *> DXXParser::AndExprContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::AndExprContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

tree::TerminalNode* DXXParser::AndExprContext::And() {
  return getToken(DXXParser::And, 0);
}

DXXParser::AndExprContext::AndExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ExpressionsContext* DXXParser::expressions() {
   return expressions(0);
}

DXXParser::ExpressionsContext* DXXParser::expressions(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  DXXParser::ExpressionsContext *_localctx = _tracker.createInstance<ExpressionsContext>(_ctx, parentState);
  DXXParser::ExpressionsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, DXXParser::RuleExpressions, precedence);

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
    setState(145);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ImportExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(101);
      importLib();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<OperatorDefineExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(102);
      operatorDefine();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(103);
      match(DXXParser::LeftParen);
      setState(105);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 589539305307611404) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & 3878502268931) != 0)) {
        setState(104);
        expressions(0);
      }
      setState(107);
      match(DXXParser::RightParen);
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<NotClassExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(108);
      _la = _input->LA(1);
      if (!(((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & 12582915) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(109);
      expressions(43);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ConvertExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(110);
      match(DXXParser::LeftParen);
      setState(111);
      theType();
      setState(112);
      match(DXXParser::RightParen);
      setState(113);
      expressions(42);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NegativeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(115);
      negative();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<VarSetExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(116);
      varSet();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<FunctionExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(117);
      function();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<FunctionDefineExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(118);
      functionDefine();
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<FunctionCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(119);
      functionCall();
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<ReturnExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(120);
      return_();
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<VarDefineExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(121);
      varDefine();
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<IfStatementExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(122);
      ifStatement();
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<SwitchStatementExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(123);
      switchStatement();
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<WhileLoopExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(124);
      whileLoop();
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<DoWhileLoopExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(125);
      doWhileLoop();
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<ForeachLoopExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(126);
      foreachLoop();
      break;
    }

    case 18: {
      _localctx = _tracker.createInstance<GotoExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(127);
      goto_();
      break;
    }

    case 19: {
      _localctx = _tracker.createInstance<GotoLabelDefineExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(128);
      gotoLabelDefine();
      break;
    }

    case 20: {
      _localctx = _tracker.createInstance<EnumExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(129);
      enum_();
      break;
    }

    case 21: {
      _localctx = _tracker.createInstance<ClassExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(130);
      class_();
      break;
    }

    case 22: {
      _localctx = _tracker.createInstance<TryExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(131);
      try_();
      break;
    }

    case 23: {
      _localctx = _tracker.createInstance<ThrowExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(132);
      throw_();
      break;
    }

    case 24: {
      _localctx = _tracker.createInstance<IdExExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(133);
      idEx();
      break;
    }

    case 25: {
      _localctx = _tracker.createInstance<BreakExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(134);
      match(DXXParser::Break);
      break;
    }

    case 26: {
      _localctx = _tracker.createInstance<ContinueExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(135);
      match(DXXParser::Continue);
      break;
    }

    case 27: {
      _localctx = _tracker.createInstance<IntegerExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(136);
      match(DXXParser::IntegerData);
      break;
    }

    case 28: {
      _localctx = _tracker.createInstance<FloatingExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(137);
      match(DXXParser::FloatingNumberData);
      break;
    }

    case 29: {
      _localctx = _tracker.createInstance<StringExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(138);
      match(DXXParser::StringData);
      break;
    }

    case 30: {
      _localctx = _tracker.createInstance<BooleanExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(139);
      boolean();
      break;
    }

    case 31: {
      _localctx = _tracker.createInstance<NullExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(140);
      match(DXXParser::Null);
      break;
    }

    case 32: {
      _localctx = _tracker.createInstance<VoidExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(141);
      match(DXXParser::Void);
      break;
    }

    case 33: {
      _localctx = _tracker.createInstance<SemiExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(142);
      match(DXXParser::Semi);
      break;
    }

    case 34: {
      _localctx = _tracker.createInstance<TypeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(143);
      theType();
      break;
    }

    case 35: {
      _localctx = _tracker.createInstance<LambdaFunctionExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(144);
      lambdaFunction();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(185);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(183);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<StarClassExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(147);

          if (!(precpred(_ctx, 41))) throw FailedPredicateException(this, "precpred(_ctx, 41)");
          setState(148);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 8070450532247928832) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(149);
          expressions(42);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusClassExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(150);

          if (!(precpred(_ctx, 40))) throw FailedPredicateException(this, "precpred(_ctx, 40)");
          setState(151);
          _la = _input->LA(1);
          if (!(_la == DXXParser::Plus

          || _la == DXXParser::Minus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(152);
          expressions(41);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<LeftOrRightShiftExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(153);

          if (!(precpred(_ctx, 39))) throw FailedPredicateException(this, "precpred(_ctx, 39)");
          setState(154);
          _la = _input->LA(1);
          if (!(_la == DXXParser::LeftShift

          || _la == DXXParser::RightShift)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(155);
          expressions(40);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<LessClassExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(156);

          if (!(precpred(_ctx, 38))) throw FailedPredicateException(this, "precpred(_ctx, 38)");
          setState(157);
          _la = _input->LA(1);
          if (!(((((_la - 70) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 70)) & 49155) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(158);
          expressions(39);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<EqualOrNotEqualExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(159);

          if (!(precpred(_ctx, 37))) throw FailedPredicateException(this, "precpred(_ctx, 37)");
          setState(160);
          _la = _input->LA(1);
          if (!(_la == DXXParser::Equal

          || _la == DXXParser::NotEqual)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(161);
          expressions(38);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(162);

          if (!(precpred(_ctx, 36))) throw FailedPredicateException(this, "precpred(_ctx, 36)");
          setState(163);
          match(DXXParser::And);
          setState(164);
          expressions(37);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<CaretExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(165);

          if (!(precpred(_ctx, 35))) throw FailedPredicateException(this, "precpred(_ctx, 35)");
          setState(166);
          match(DXXParser::Caret);
          setState(167);
          expressions(36);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(168);

          if (!(precpred(_ctx, 34))) throw FailedPredicateException(this, "precpred(_ctx, 34)");
          setState(169);
          match(DXXParser::Or);
          setState(170);
          expressions(35);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<OrorExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(171);

          if (!(precpred(_ctx, 33))) throw FailedPredicateException(this, "precpred(_ctx, 33)");
          setState(172);
          match(DXXParser::OrOr);
          setState(173);
          expressions(34);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<AndandExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(174);

          if (!(precpred(_ctx, 32))) throw FailedPredicateException(this, "precpred(_ctx, 32)");
          setState(175);
          match(DXXParser::AndAnd);
          setState(176);
          expressions(33);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<QuestionExprContext>(_tracker.createInstance<ExpressionsContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpressions);
          setState(177);

          if (!(precpred(_ctx, 31))) throw FailedPredicateException(this, "precpred(_ctx, 31)");
          setState(178);
          match(DXXParser::Question);
          setState(179);
          expressions(0);
          setState(180);
          match(DXXParser::Colon);
          setState(181);
          expressions(32);
          break;
        }

        default:
          break;
        } 
      }
      setState(187);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- BooleanContext ------------------------------------------------------------------

DXXParser::BooleanContext::BooleanContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::BooleanContext::True() {
  return getToken(DXXParser::True, 0);
}

tree::TerminalNode* DXXParser::BooleanContext::False() {
  return getToken(DXXParser::False, 0);
}


size_t DXXParser::BooleanContext::getRuleIndex() const {
  return DXXParser::RuleBoolean;
}


std::any DXXParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::BooleanContext* DXXParser::boolean() {
  BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, getState());
  enterRule(_localctx, 4, DXXParser::RuleBoolean);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    _la = _input->LA(1);
    if (!(_la == DXXParser::False

    || _la == DXXParser::True)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NegativeContext ------------------------------------------------------------------

DXXParser::NegativeContext::NegativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::NegativeContext::Minus() {
  return getToken(DXXParser::Minus, 0);
}

DXXParser::ExpressionsContext* DXXParser::NegativeContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}


size_t DXXParser::NegativeContext::getRuleIndex() const {
  return DXXParser::RuleNegative;
}


std::any DXXParser::NegativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNegative(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::NegativeContext* DXXParser::negative() {
  NegativeContext *_localctx = _tracker.createInstance<NegativeContext>(_ctx, getState());
  enterRule(_localctx, 6, DXXParser::RuleNegative);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(190);
    match(DXXParser::Minus);
    setState(191);
    expressions(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportLibContext ------------------------------------------------------------------

DXXParser::ImportLibContext::ImportLibContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::ImportLibContext::Import() {
  return getToken(DXXParser::Import, 0);
}

DXXParser::IdExContext* DXXParser::ImportLibContext::idEx() {
  return getRuleContext<DXXParser::IdExContext>(0);
}


size_t DXXParser::ImportLibContext::getRuleIndex() const {
  return DXXParser::RuleImportLib;
}


std::any DXXParser::ImportLibContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitImportLib(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ImportLibContext* DXXParser::importLib() {
  ImportLibContext *_localctx = _tracker.createInstance<ImportLibContext>(_ctx, getState());
  enterRule(_localctx, 8, DXXParser::RuleImportLib);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    match(DXXParser::Import);
    setState(194);
    idEx();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefineContext ------------------------------------------------------------------

DXXParser::FunctionDefineContext::FunctionDefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::FunctionHeadContext* DXXParser::FunctionDefineContext::functionHead() {
  return getRuleContext<DXXParser::FunctionHeadContext>(0);
}


size_t DXXParser::FunctionDefineContext::getRuleIndex() const {
  return DXXParser::RuleFunctionDefine;
}


std::any DXXParser::FunctionDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDefine(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::FunctionDefineContext* DXXParser::functionDefine() {
  FunctionDefineContext *_localctx = _tracker.createInstance<FunctionDefineContext>(_ctx, getState());
  enterRule(_localctx, 10, DXXParser::RuleFunctionDefine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    functionHead();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionContext ------------------------------------------------------------------

DXXParser::FunctionContext::FunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::FunctionHeadContext* DXXParser::FunctionContext::functionHead() {
  return getRuleContext<DXXParser::FunctionHeadContext>(0);
}

DXXParser::BlockContext* DXXParser::FunctionContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::FunctionContext::getRuleIndex() const {
  return DXXParser::RuleFunction;
}


std::any DXXParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::FunctionContext* DXXParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 12, DXXParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    functionHead();
    setState(199);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnContext ------------------------------------------------------------------

DXXParser::ReturnContext::ReturnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::ReturnContext::Return() {
  return getToken(DXXParser::Return, 0);
}

DXXParser::ExpressionsContext* DXXParser::ReturnContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}


size_t DXXParser::ReturnContext::getRuleIndex() const {
  return DXXParser::RuleReturn;
}


std::any DXXParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ReturnContext* DXXParser::return_() {
  ReturnContext *_localctx = _tracker.createInstance<ReturnContext>(_ctx, getState());
  enterRule(_localctx, 14, DXXParser::RuleReturn);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(201);
    match(DXXParser::Return);
    setState(202);
    expressions(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LambdaFunctionContext ------------------------------------------------------------------

DXXParser::LambdaFunctionContext::LambdaFunctionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::LambdaFunctionContext::LeftBracket() {
  return getToken(DXXParser::LeftBracket, 0);
}

tree::TerminalNode* DXXParser::LambdaFunctionContext::RightBracket() {
  return getToken(DXXParser::RightBracket, 0);
}

DXXParser::BlockContext* DXXParser::LambdaFunctionContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::LambdaFunctionContext::getRuleIndex() const {
  return DXXParser::RuleLambdaFunction;
}


std::any DXXParser::LambdaFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitLambdaFunction(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::LambdaFunctionContext* DXXParser::lambdaFunction() {
  LambdaFunctionContext *_localctx = _tracker.createInstance<LambdaFunctionContext>(_ctx, getState());
  enterRule(_localctx, 16, DXXParser::RuleLambdaFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    match(DXXParser::LeftBracket);
    setState(205);
    match(DXXParser::RightBracket);
    setState(206);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionHeadContext ------------------------------------------------------------------

DXXParser::FunctionHeadContext::FunctionHeadContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::FunctionHeadContext::ID() {
  return getToken(DXXParser::ID, 0);
}

tree::TerminalNode* DXXParser::FunctionHeadContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

tree::TerminalNode* DXXParser::FunctionHeadContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

tree::TerminalNode* DXXParser::FunctionHeadContext::Arrow() {
  return getToken(DXXParser::Arrow, 0);
}

DXXParser::TheTypeContext* DXXParser::FunctionHeadContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
}

DXXParser::TemplateListContext* DXXParser::FunctionHeadContext::templateList() {
  return getRuleContext<DXXParser::TemplateListContext>(0);
}

std::vector<DXXParser::InfoContext *> DXXParser::FunctionHeadContext::info() {
  return getRuleContexts<DXXParser::InfoContext>();
}

DXXParser::InfoContext* DXXParser::FunctionHeadContext::info(size_t i) {
  return getRuleContext<DXXParser::InfoContext>(i);
}

DXXParser::ParamListContext* DXXParser::FunctionHeadContext::paramList() {
  return getRuleContext<DXXParser::ParamListContext>(0);
}


size_t DXXParser::FunctionHeadContext::getRuleIndex() const {
  return DXXParser::RuleFunctionHead;
}


std::any DXXParser::FunctionHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionHead(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::FunctionHeadContext* DXXParser::functionHead() {
  FunctionHeadContext *_localctx = _tracker.createInstance<FunctionHeadContext>(_ctx, getState());
  enterRule(_localctx, 18, DXXParser::RuleFunctionHead);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Template) {
      setState(208);
      templateList();
    }
    setState(214);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 339445088256) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(211);
      info();
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(217);
    match(DXXParser::ID);
    setState(218);
    match(DXXParser::LeftParen);
    setState(220);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 563840245104644) != 0) || ((((_la - 98) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 98)) & 7) != 0)) {
      setState(219);
      paramList();
    }
    setState(222);
    match(DXXParser::RightParen);
    setState(223);
    match(DXXParser::Arrow);
    setState(224);
    theType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

DXXParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::IdExContext* DXXParser::FunctionCallContext::idEx() {
  return getRuleContext<DXXParser::IdExContext>(0);
}

tree::TerminalNode* DXXParser::FunctionCallContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

tree::TerminalNode* DXXParser::FunctionCallContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

DXXParser::CallTemplateListContext* DXXParser::FunctionCallContext::callTemplateList() {
  return getRuleContext<DXXParser::CallTemplateListContext>(0);
}

DXXParser::CallParamListContext* DXXParser::FunctionCallContext::callParamList() {
  return getRuleContext<DXXParser::CallParamListContext>(0);
}


size_t DXXParser::FunctionCallContext::getRuleIndex() const {
  return DXXParser::RuleFunctionCall;
}


std::any DXXParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::FunctionCallContext* DXXParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 20, DXXParser::RuleFunctionCall);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    idEx();
    setState(228);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Less) {
      setState(227);
      callTemplateList();
    }
    setState(230);
    match(DXXParser::LeftParen);
    setState(232);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 589539305307611404) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & 3878502268931) != 0)) {
      setState(231);
      callParamList();
    }
    setState(234);
    match(DXXParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

DXXParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DXXParser::VarDefineContext *> DXXParser::ParamListContext::varDefine() {
  return getRuleContexts<DXXParser::VarDefineContext>();
}

DXXParser::VarDefineContext* DXXParser::ParamListContext::varDefine(size_t i) {
  return getRuleContext<DXXParser::VarDefineContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::ParamListContext::Comma() {
  return getTokens(DXXParser::Comma);
}

tree::TerminalNode* DXXParser::ParamListContext::Comma(size_t i) {
  return getToken(DXXParser::Comma, i);
}

tree::TerminalNode* DXXParser::ParamListContext::Ellipsis() {
  return getToken(DXXParser::Ellipsis, 0);
}


size_t DXXParser::ParamListContext::getRuleIndex() const {
  return DXXParser::RuleParamList;
}


std::any DXXParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ParamListContext* DXXParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 22, DXXParser::RuleParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(236);
    varDefine();
    setState(241);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(237);
        match(DXXParser::Comma);
        setState(238);
        varDefine(); 
      }
      setState(243);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
    setState(246);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Comma) {
      setState(244);
      match(DXXParser::Comma);
      setState(245);
      match(DXXParser::Ellipsis);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallParamListContext ------------------------------------------------------------------

DXXParser::CallParamListContext::CallParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DXXParser::ExpressionsContext *> DXXParser::CallParamListContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::CallParamListContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::CallParamListContext::Comma() {
  return getTokens(DXXParser::Comma);
}

tree::TerminalNode* DXXParser::CallParamListContext::Comma(size_t i) {
  return getToken(DXXParser::Comma, i);
}


size_t DXXParser::CallParamListContext::getRuleIndex() const {
  return DXXParser::RuleCallParamList;
}


std::any DXXParser::CallParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitCallParamList(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::CallParamListContext* DXXParser::callParamList() {
  CallParamListContext *_localctx = _tracker.createInstance<CallParamListContext>(_ctx, getState());
  enterRule(_localctx, 24, DXXParser::RuleCallParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    expressions(0);
    setState(253);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DXXParser::Comma) {
      setState(249);
      match(DXXParser::Comma);
      setState(250);
      expressions(0);
      setState(255);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefineContext ------------------------------------------------------------------

DXXParser::VarDefineContext::VarDefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::TheTypeContext* DXXParser::VarDefineContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
}

DXXParser::VarSetContext* DXXParser::VarDefineContext::varSet() {
  return getRuleContext<DXXParser::VarSetContext>(0);
}

tree::TerminalNode* DXXParser::VarDefineContext::ID() {
  return getToken(DXXParser::ID, 0);
}

std::vector<DXXParser::InfoContext *> DXXParser::VarDefineContext::info() {
  return getRuleContexts<DXXParser::InfoContext>();
}

DXXParser::InfoContext* DXXParser::VarDefineContext::info(size_t i) {
  return getRuleContext<DXXParser::InfoContext>(i);
}


size_t DXXParser::VarDefineContext::getRuleIndex() const {
  return DXXParser::RuleVarDefine;
}


std::any DXXParser::VarDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVarDefine(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::VarDefineContext* DXXParser::varDefine() {
  VarDefineContext *_localctx = _tracker.createInstance<VarDefineContext>(_ctx, getState());
  enterRule(_localctx, 26, DXXParser::RuleVarDefine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(256);
    theType();
    setState(260);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 339445088256) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(257);
      info();
      setState(262);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(265);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(263);
      varSet();
      break;
    }

    case 2: {
      setState(264);
      match(DXXParser::ID);
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

//----------------- VarSetContext ------------------------------------------------------------------

DXXParser::VarSetContext::VarSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::IdExContext* DXXParser::VarSetContext::idEx() {
  return getRuleContext<DXXParser::IdExContext>(0);
}

DXXParser::AssignsContext* DXXParser::VarSetContext::assigns() {
  return getRuleContext<DXXParser::AssignsContext>(0);
}

DXXParser::ExpressionsContext* DXXParser::VarSetContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}


size_t DXXParser::VarSetContext::getRuleIndex() const {
  return DXXParser::RuleVarSet;
}


std::any DXXParser::VarSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVarSet(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::VarSetContext* DXXParser::varSet() {
  VarSetContext *_localctx = _tracker.createInstance<VarSetContext>(_ctx, getState());
  enterRule(_localctx, 28, DXXParser::RuleVarSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(267);
    idEx();
    setState(268);
    assigns();
    setState(269);
    expressions(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

DXXParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DXXParser::IfStatementContext::If() {
  return getTokens(DXXParser::If);
}

tree::TerminalNode* DXXParser::IfStatementContext::If(size_t i) {
  return getToken(DXXParser::If, i);
}

std::vector<tree::TerminalNode *> DXXParser::IfStatementContext::LeftParen() {
  return getTokens(DXXParser::LeftParen);
}

tree::TerminalNode* DXXParser::IfStatementContext::LeftParen(size_t i) {
  return getToken(DXXParser::LeftParen, i);
}

std::vector<tree::TerminalNode *> DXXParser::IfStatementContext::RightParen() {
  return getTokens(DXXParser::RightParen);
}

tree::TerminalNode* DXXParser::IfStatementContext::RightParen(size_t i) {
  return getToken(DXXParser::RightParen, i);
}

std::vector<DXXParser::BlockContext *> DXXParser::IfStatementContext::block() {
  return getRuleContexts<DXXParser::BlockContext>();
}

DXXParser::BlockContext* DXXParser::IfStatementContext::block(size_t i) {
  return getRuleContext<DXXParser::BlockContext>(i);
}

std::vector<DXXParser::ExpressionsContext *> DXXParser::IfStatementContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::IfStatementContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::IfStatementContext::Else() {
  return getTokens(DXXParser::Else);
}

tree::TerminalNode* DXXParser::IfStatementContext::Else(size_t i) {
  return getToken(DXXParser::Else, i);
}

tree::TerminalNode* DXXParser::IfStatementContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::IfStatementContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}


size_t DXXParser::IfStatementContext::getRuleIndex() const {
  return DXXParser::RuleIfStatement;
}


std::any DXXParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::IfStatementContext* DXXParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 30, DXXParser::RuleIfStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(271);
    match(DXXParser::If);
    setState(272);
    match(DXXParser::LeftParen);
    setState(274);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 589539305307611404) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & 3878502268931) != 0)) {
      setState(273);
      expressions(0);
    }
    setState(276);
    match(DXXParser::RightParen);
    setState(277);
    block();
    setState(288);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(278);
        match(DXXParser::Else);
        setState(279);
        match(DXXParser::If);
        setState(280);
        match(DXXParser::LeftParen);
        setState(282);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 589539305307611404) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 66)) & 3878502268931) != 0)) {
          setState(281);
          expressions(0);
        }
        setState(284);
        match(DXXParser::RightParen);
        setState(285);
        block(); 
      }
      setState(290);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    }
    setState(300);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(291);
      match(DXXParser::Else);
      setState(292);
      match(DXXParser::LeftBrace);
      setState(296);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 589539305307611404) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 66)) & 3878502268931) != 0)) {
        setState(293);
        expressions(0);
        setState(298);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(299);
      match(DXXParser::RightBrace);
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

//----------------- SwitchStatementContext ------------------------------------------------------------------

DXXParser::SwitchStatementContext::SwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::SwitchStatementContext::Switch() {
  return getToken(DXXParser::Switch, 0);
}

tree::TerminalNode* DXXParser::SwitchStatementContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

DXXParser::ExpressionsContext* DXXParser::SwitchStatementContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}

tree::TerminalNode* DXXParser::SwitchStatementContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

tree::TerminalNode* DXXParser::SwitchStatementContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::SwitchStatementContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}

std::vector<DXXParser::CaseStatementContext *> DXXParser::SwitchStatementContext::caseStatement() {
  return getRuleContexts<DXXParser::CaseStatementContext>();
}

DXXParser::CaseStatementContext* DXXParser::SwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<DXXParser::CaseStatementContext>(i);
}

DXXParser::DefaultStatementContext* DXXParser::SwitchStatementContext::defaultStatement() {
  return getRuleContext<DXXParser::DefaultStatementContext>(0);
}


size_t DXXParser::SwitchStatementContext::getRuleIndex() const {
  return DXXParser::RuleSwitchStatement;
}


std::any DXXParser::SwitchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitSwitchStatement(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::SwitchStatementContext* DXXParser::switchStatement() {
  SwitchStatementContext *_localctx = _tracker.createInstance<SwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 32, DXXParser::RuleSwitchStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    match(DXXParser::Switch);
    setState(303);
    match(DXXParser::LeftParen);
    setState(304);
    expressions(0);
    setState(305);
    match(DXXParser::RightParen);
    setState(306);
    match(DXXParser::LeftBrace);
    setState(310);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DXXParser::Case) {
      setState(307);
      caseStatement();
      setState(312);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(314);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Default) {
      setState(313);
      defaultStatement();
    }
    setState(316);
    match(DXXParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CaseStatementContext ------------------------------------------------------------------

DXXParser::CaseStatementContext::CaseStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::CaseStatementContext::Case() {
  return getToken(DXXParser::Case, 0);
}

DXXParser::ExpressionsContext* DXXParser::CaseStatementContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}

DXXParser::BlockContext* DXXParser::CaseStatementContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::CaseStatementContext::getRuleIndex() const {
  return DXXParser::RuleCaseStatement;
}


std::any DXXParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::CaseStatementContext* DXXParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 34, DXXParser::RuleCaseStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(318);
    match(DXXParser::Case);
    setState(319);
    expressions(0);
    setState(320);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DefaultStatementContext ------------------------------------------------------------------

DXXParser::DefaultStatementContext::DefaultStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::DefaultStatementContext::Default() {
  return getToken(DXXParser::Default, 0);
}

tree::TerminalNode* DXXParser::DefaultStatementContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::DefaultStatementContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}

std::vector<DXXParser::ExpressionsContext *> DXXParser::DefaultStatementContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::DefaultStatementContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}


size_t DXXParser::DefaultStatementContext::getRuleIndex() const {
  return DXXParser::RuleDefaultStatement;
}


std::any DXXParser::DefaultStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitDefaultStatement(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::DefaultStatementContext* DXXParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 36, DXXParser::RuleDefaultStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    match(DXXParser::Default);
    setState(323);
    match(DXXParser::LeftBrace);
    setState(327);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 589539305307611404) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & 3878502268931) != 0)) {
      setState(324);
      expressions(0);
      setState(329);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(330);
    match(DXXParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileLoopContext ------------------------------------------------------------------

DXXParser::WhileLoopContext::WhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::WhileLoopContext::While() {
  return getToken(DXXParser::While, 0);
}

tree::TerminalNode* DXXParser::WhileLoopContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

DXXParser::ExpressionsContext* DXXParser::WhileLoopContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}

tree::TerminalNode* DXXParser::WhileLoopContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

DXXParser::BlockContext* DXXParser::WhileLoopContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::WhileLoopContext::getRuleIndex() const {
  return DXXParser::RuleWhileLoop;
}


std::any DXXParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::WhileLoopContext* DXXParser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 38, DXXParser::RuleWhileLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    match(DXXParser::While);
    setState(333);
    match(DXXParser::LeftParen);
    setState(334);
    expressions(0);
    setState(335);
    match(DXXParser::RightParen);
    setState(337);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      setState(336);
      block();
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

//----------------- DoWhileLoopContext ------------------------------------------------------------------

DXXParser::DoWhileLoopContext::DoWhileLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::WhileLoopContext* DXXParser::DoWhileLoopContext::whileLoop() {
  return getRuleContext<DXXParser::WhileLoopContext>(0);
}

tree::TerminalNode* DXXParser::DoWhileLoopContext::Do() {
  return getToken(DXXParser::Do, 0);
}

tree::TerminalNode* DXXParser::DoWhileLoopContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

DXXParser::ExpressionsContext* DXXParser::DoWhileLoopContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}

tree::TerminalNode* DXXParser::DoWhileLoopContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}


size_t DXXParser::DoWhileLoopContext::getRuleIndex() const {
  return DXXParser::RuleDoWhileLoop;
}


std::any DXXParser::DoWhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitDoWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::DoWhileLoopContext* DXXParser::doWhileLoop() {
  DoWhileLoopContext *_localctx = _tracker.createInstance<DoWhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 40, DXXParser::RuleDoWhileLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(339);
    whileLoop();
    setState(340);
    match(DXXParser::Do);
    setState(341);
    match(DXXParser::LeftParen);
    setState(342);
    expressions(0);
    setState(343);
    match(DXXParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForeachLoopContext ------------------------------------------------------------------

DXXParser::ForeachLoopContext::ForeachLoopContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::ForeachLoopContext::Foreach() {
  return getToken(DXXParser::Foreach, 0);
}

tree::TerminalNode* DXXParser::ForeachLoopContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

tree::TerminalNode* DXXParser::ForeachLoopContext::Colon() {
  return getToken(DXXParser::Colon, 0);
}

DXXParser::ExpressionsContext* DXXParser::ForeachLoopContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}

tree::TerminalNode* DXXParser::ForeachLoopContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

DXXParser::VarDefineContext* DXXParser::ForeachLoopContext::varDefine() {
  return getRuleContext<DXXParser::VarDefineContext>(0);
}

DXXParser::IdExContext* DXXParser::ForeachLoopContext::idEx() {
  return getRuleContext<DXXParser::IdExContext>(0);
}

DXXParser::BlockContext* DXXParser::ForeachLoopContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::ForeachLoopContext::getRuleIndex() const {
  return DXXParser::RuleForeachLoop;
}


std::any DXXParser::ForeachLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitForeachLoop(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ForeachLoopContext* DXXParser::foreachLoop() {
  ForeachLoopContext *_localctx = _tracker.createInstance<ForeachLoopContext>(_ctx, getState());
  enterRule(_localctx, 42, DXXParser::RuleForeachLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(345);
    match(DXXParser::Foreach);
    setState(346);
    match(DXXParser::LeftParen);
    setState(349);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(347);
      varDefine();
      break;
    }

    case 2: {
      setState(348);
      idEx();
      break;
    }

    default:
      break;
    }
    setState(351);
    match(DXXParser::Colon);
    setState(352);
    expressions(0);
    setState(353);
    match(DXXParser::RightParen);
    setState(355);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(354);
      block();
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

//----------------- GotoContext ------------------------------------------------------------------

DXXParser::GotoContext::GotoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::GotoContext::Goto() {
  return getToken(DXXParser::Goto, 0);
}

tree::TerminalNode* DXXParser::GotoContext::ID() {
  return getToken(DXXParser::ID, 0);
}


size_t DXXParser::GotoContext::getRuleIndex() const {
  return DXXParser::RuleGoto;
}


std::any DXXParser::GotoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitGoto(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::GotoContext* DXXParser::goto_() {
  GotoContext *_localctx = _tracker.createInstance<GotoContext>(_ctx, getState());
  enterRule(_localctx, 44, DXXParser::RuleGoto);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(DXXParser::Goto);
    setState(358);
    match(DXXParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GotoLabelDefineContext ------------------------------------------------------------------

DXXParser::GotoLabelDefineContext::GotoLabelDefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::GotoLabelDefineContext::ID() {
  return getToken(DXXParser::ID, 0);
}

tree::TerminalNode* DXXParser::GotoLabelDefineContext::Colon() {
  return getToken(DXXParser::Colon, 0);
}

DXXParser::BlockContext* DXXParser::GotoLabelDefineContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::GotoLabelDefineContext::getRuleIndex() const {
  return DXXParser::RuleGotoLabelDefine;
}


std::any DXXParser::GotoLabelDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitGotoLabelDefine(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::GotoLabelDefineContext* DXXParser::gotoLabelDefine() {
  GotoLabelDefineContext *_localctx = _tracker.createInstance<GotoLabelDefineContext>(_ctx, getState());
  enterRule(_localctx, 46, DXXParser::RuleGotoLabelDefine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    match(DXXParser::ID);
    setState(361);
    match(DXXParser::Colon);
    setState(362);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumContext ------------------------------------------------------------------

DXXParser::EnumContext::EnumContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::EnumContext::Enum() {
  return getToken(DXXParser::Enum, 0);
}

tree::TerminalNode* DXXParser::EnumContext::ID() {
  return getToken(DXXParser::ID, 0);
}

tree::TerminalNode* DXXParser::EnumContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::EnumContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}

DXXParser::EnumListContext* DXXParser::EnumContext::enumList() {
  return getRuleContext<DXXParser::EnumListContext>(0);
}


size_t DXXParser::EnumContext::getRuleIndex() const {
  return DXXParser::RuleEnum;
}


std::any DXXParser::EnumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitEnum(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::EnumContext* DXXParser::enum_() {
  EnumContext *_localctx = _tracker.createInstance<EnumContext>(_ctx, getState());
  enterRule(_localctx, 48, DXXParser::RuleEnum);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(364);
    match(DXXParser::Enum);
    setState(365);
    match(DXXParser::ID);
    setState(366);
    match(DXXParser::LeftBrace);
    setState(368);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::ID) {
      setState(367);
      enumList();
    }
    setState(370);
    match(DXXParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumListContext ------------------------------------------------------------------

DXXParser::EnumListContext::EnumListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DXXParser::EnumListContext::ID() {
  return getTokens(DXXParser::ID);
}

tree::TerminalNode* DXXParser::EnumListContext::ID(size_t i) {
  return getToken(DXXParser::ID, i);
}

std::vector<tree::TerminalNode *> DXXParser::EnumListContext::Comma() {
  return getTokens(DXXParser::Comma);
}

tree::TerminalNode* DXXParser::EnumListContext::Comma(size_t i) {
  return getToken(DXXParser::Comma, i);
}


size_t DXXParser::EnumListContext::getRuleIndex() const {
  return DXXParser::RuleEnumList;
}


std::any DXXParser::EnumListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitEnumList(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::EnumListContext* DXXParser::enumList() {
  EnumListContext *_localctx = _tracker.createInstance<EnumListContext>(_ctx, getState());
  enterRule(_localctx, 50, DXXParser::RuleEnumList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(372);
    match(DXXParser::ID);
    setState(377);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DXXParser::Comma) {
      setState(373);
      match(DXXParser::Comma);
      setState(374);
      match(DXXParser::ID);
      setState(379);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassContext ------------------------------------------------------------------

DXXParser::ClassContext::ClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::TemplateListContext* DXXParser::ClassContext::templateList() {
  return getRuleContext<DXXParser::TemplateListContext>(0);
}

tree::TerminalNode* DXXParser::ClassContext::Class() {
  return getToken(DXXParser::Class, 0);
}

tree::TerminalNode* DXXParser::ClassContext::ID() {
  return getToken(DXXParser::ID, 0);
}

tree::TerminalNode* DXXParser::ClassContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::ClassContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}

tree::TerminalNode* DXXParser::ClassContext::Extends() {
  return getToken(DXXParser::Extends, 0);
}

tree::TerminalNode* DXXParser::ClassContext::Implements() {
  return getToken(DXXParser::Implements, 0);
}

std::vector<DXXParser::ClassMethodsContext *> DXXParser::ClassContext::classMethods() {
  return getRuleContexts<DXXParser::ClassMethodsContext>();
}

DXXParser::ClassMethodsContext* DXXParser::ClassContext::classMethods(size_t i) {
  return getRuleContext<DXXParser::ClassMethodsContext>(i);
}

std::vector<DXXParser::IdExContext *> DXXParser::ClassContext::idEx() {
  return getRuleContexts<DXXParser::IdExContext>();
}

DXXParser::IdExContext* DXXParser::ClassContext::idEx(size_t i) {
  return getRuleContext<DXXParser::IdExContext>(i);
}


size_t DXXParser::ClassContext::getRuleIndex() const {
  return DXXParser::RuleClass;
}


std::any DXXParser::ClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitClass(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ClassContext* DXXParser::class_() {
  ClassContext *_localctx = _tracker.createInstance<ClassContext>(_ctx, getState());
  enterRule(_localctx, 52, DXXParser::RuleClass);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    templateList();
    setState(381);
    match(DXXParser::Class);
    setState(382);
    match(DXXParser::ID);
    setState(390);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Extends) {
      setState(383);
      match(DXXParser::Extends);
      setState(387);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DXXParser::ID) {
        setState(384);
        idEx();
        setState(389);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(399);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Implements) {
      setState(392);
      match(DXXParser::Implements);
      setState(396);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DXXParser::ID) {
        setState(393);
        idEx();
        setState(398);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(401);
    match(DXXParser::LeftBrace);
    setState(405);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 589539305307611404) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & 3878502268931) != 0)) {
      setState(402);
      classMethods();
      setState(407);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(408);
    match(DXXParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassMethodsContext ------------------------------------------------------------------

DXXParser::ClassMethodsContext::ClassMethodsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::ExpressionsContext* DXXParser::ClassMethodsContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}


size_t DXXParser::ClassMethodsContext::getRuleIndex() const {
  return DXXParser::RuleClassMethods;
}


std::any DXXParser::ClassMethodsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitClassMethods(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ClassMethodsContext* DXXParser::classMethods() {
  ClassMethodsContext *_localctx = _tracker.createInstance<ClassMethodsContext>(_ctx, getState());
  enterRule(_localctx, 54, DXXParser::RuleClassMethods);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(410);
    expressions(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperatorDefineContext ------------------------------------------------------------------

DXXParser::OperatorDefineContext::OperatorDefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::OperatorDefineContext::Operator() {
  return getToken(DXXParser::Operator, 0);
}

DXXParser::AllOperatorsContext* DXXParser::OperatorDefineContext::allOperators() {
  return getRuleContext<DXXParser::AllOperatorsContext>(0);
}

tree::TerminalNode* DXXParser::OperatorDefineContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

tree::TerminalNode* DXXParser::OperatorDefineContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

tree::TerminalNode* DXXParser::OperatorDefineContext::Arrow() {
  return getToken(DXXParser::Arrow, 0);
}

DXXParser::TheTypeContext* DXXParser::OperatorDefineContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
}

DXXParser::ParamListContext* DXXParser::OperatorDefineContext::paramList() {
  return getRuleContext<DXXParser::ParamListContext>(0);
}

DXXParser::BlockContext* DXXParser::OperatorDefineContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::OperatorDefineContext::getRuleIndex() const {
  return DXXParser::RuleOperatorDefine;
}


std::any DXXParser::OperatorDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitOperatorDefine(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::OperatorDefineContext* DXXParser::operatorDefine() {
  OperatorDefineContext *_localctx = _tracker.createInstance<OperatorDefineContext>(_ctx, getState());
  enterRule(_localctx, 56, DXXParser::RuleOperatorDefine);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(412);
    match(DXXParser::Operator);
    setState(413);
    allOperators();
    setState(414);
    match(DXXParser::LeftParen);
    setState(416);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 563840245104644) != 0) || ((((_la - 98) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 98)) & 7) != 0)) {
      setState(415);
      paramList();
    }
    setState(418);
    match(DXXParser::RightParen);
    setState(419);
    match(DXXParser::Arrow);
    setState(420);
    theType();
    setState(422);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(421);
      block();
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

//----------------- BlockContext ------------------------------------------------------------------

DXXParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::BlockContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::BlockContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}

std::vector<DXXParser::ExpressionsContext *> DXXParser::BlockContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::BlockContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}


size_t DXXParser::BlockContext::getRuleIndex() const {
  return DXXParser::RuleBlock;
}


std::any DXXParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::BlockContext* DXXParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 58, DXXParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(424);
    match(DXXParser::LeftBrace);
    setState(428);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 589539305307611404) != 0) || ((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & 3878502268931) != 0)) {
      setState(425);
      expressions(0);
      setState(430);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(431);
    match(DXXParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TemplateListContext ------------------------------------------------------------------

DXXParser::TemplateListContext::TemplateListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::TemplateListContext::Template() {
  return getToken(DXXParser::Template, 0);
}

tree::TerminalNode* DXXParser::TemplateListContext::Less() {
  return getToken(DXXParser::Less, 0);
}

DXXParser::TemplateListSubContext* DXXParser::TemplateListContext::templateListSub() {
  return getRuleContext<DXXParser::TemplateListSubContext>(0);
}

tree::TerminalNode* DXXParser::TemplateListContext::Greater() {
  return getToken(DXXParser::Greater, 0);
}


size_t DXXParser::TemplateListContext::getRuleIndex() const {
  return DXXParser::RuleTemplateList;
}


std::any DXXParser::TemplateListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTemplateList(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TemplateListContext* DXXParser::templateList() {
  TemplateListContext *_localctx = _tracker.createInstance<TemplateListContext>(_ctx, getState());
  enterRule(_localctx, 60, DXXParser::RuleTemplateList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(433);
    match(DXXParser::Template);
    setState(434);
    match(DXXParser::Less);
    setState(435);
    templateListSub();
    setState(436);
    match(DXXParser::Greater);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallTemplateListContext ------------------------------------------------------------------

DXXParser::CallTemplateListContext::CallTemplateListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::CallTemplateListContext::Less() {
  return getToken(DXXParser::Less, 0);
}

DXXParser::CallTemplateSubContext* DXXParser::CallTemplateListContext::callTemplateSub() {
  return getRuleContext<DXXParser::CallTemplateSubContext>(0);
}

tree::TerminalNode* DXXParser::CallTemplateListContext::Greater() {
  return getToken(DXXParser::Greater, 0);
}


size_t DXXParser::CallTemplateListContext::getRuleIndex() const {
  return DXXParser::RuleCallTemplateList;
}


std::any DXXParser::CallTemplateListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitCallTemplateList(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::CallTemplateListContext* DXXParser::callTemplateList() {
  CallTemplateListContext *_localctx = _tracker.createInstance<CallTemplateListContext>(_ctx, getState());
  enterRule(_localctx, 62, DXXParser::RuleCallTemplateList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(438);
    match(DXXParser::Less);
    setState(439);
    callTemplateSub();
    setState(440);
    match(DXXParser::Greater);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TemplateListSubContext ------------------------------------------------------------------

DXXParser::TemplateListSubContext::TemplateListSubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DXXParser::TemplateListSubContext::ID() {
  return getTokens(DXXParser::ID);
}

tree::TerminalNode* DXXParser::TemplateListSubContext::ID(size_t i) {
  return getToken(DXXParser::ID, i);
}

std::vector<tree::TerminalNode *> DXXParser::TemplateListSubContext::Class() {
  return getTokens(DXXParser::Class);
}

tree::TerminalNode* DXXParser::TemplateListSubContext::Class(size_t i) {
  return getToken(DXXParser::Class, i);
}

std::vector<DXXParser::TheTypeContext *> DXXParser::TemplateListSubContext::theType() {
  return getRuleContexts<DXXParser::TheTypeContext>();
}

DXXParser::TheTypeContext* DXXParser::TemplateListSubContext::theType(size_t i) {
  return getRuleContext<DXXParser::TheTypeContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::TemplateListSubContext::Assign() {
  return getTokens(DXXParser::Assign);
}

tree::TerminalNode* DXXParser::TemplateListSubContext::Assign(size_t i) {
  return getToken(DXXParser::Assign, i);
}

std::vector<DXXParser::ExpressionsContext *> DXXParser::TemplateListSubContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::TemplateListSubContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::TemplateListSubContext::Comma() {
  return getTokens(DXXParser::Comma);
}

tree::TerminalNode* DXXParser::TemplateListSubContext::Comma(size_t i) {
  return getToken(DXXParser::Comma, i);
}


size_t DXXParser::TemplateListSubContext::getRuleIndex() const {
  return DXXParser::RuleTemplateListSub;
}


std::any DXXParser::TemplateListSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTemplateListSub(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TemplateListSubContext* DXXParser::templateListSub() {
  TemplateListSubContext *_localctx = _tracker.createInstance<TemplateListSubContext>(_ctx, getState());
  enterRule(_localctx, 64, DXXParser::RuleTemplateListSub);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DXXParser::Class: {
        setState(442);
        match(DXXParser::Class);
        break;
      }

      case DXXParser::Bool:
      case DXXParser::Final:
      case DXXParser::Float:
      case DXXParser::Inline:
      case DXXParser::Int:
      case DXXParser::Native:
      case DXXParser::Object:
      case DXXParser::Override:
      case DXXParser::Private:
      case DXXParser::Protected:
      case DXXParser::Public:
      case DXXParser::Static:
      case DXXParser::String:
      case DXXParser::Void:
      case DXXParser::ID:
      case DXXParser::Constructor:
      case DXXParser::Destructor: {
        setState(443);
        theType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(446);
    match(DXXParser::ID);
    setState(449);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Assign) {
      setState(447);
      match(DXXParser::Assign);
      setState(448);
      expressions(0);
    }
    setState(463);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DXXParser::Comma) {
      setState(451);
      match(DXXParser::Comma);
      setState(454);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DXXParser::Class: {
          setState(452);
          match(DXXParser::Class);
          break;
        }

        case DXXParser::Bool:
        case DXXParser::Final:
        case DXXParser::Float:
        case DXXParser::Inline:
        case DXXParser::Int:
        case DXXParser::Native:
        case DXXParser::Object:
        case DXXParser::Override:
        case DXXParser::Private:
        case DXXParser::Protected:
        case DXXParser::Public:
        case DXXParser::Static:
        case DXXParser::String:
        case DXXParser::Void:
        case DXXParser::ID:
        case DXXParser::Constructor:
        case DXXParser::Destructor: {
          setState(453);
          theType();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(456);
      match(DXXParser::ID);
      setState(459);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DXXParser::Assign) {
        setState(457);
        match(DXXParser::Assign);
        setState(458);
        expressions(0);
      }
      setState(465);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CallTemplateSubContext ------------------------------------------------------------------

DXXParser::CallTemplateSubContext::CallTemplateSubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DXXParser::ExpressionsContext *> DXXParser::CallTemplateSubContext::expressions() {
  return getRuleContexts<DXXParser::ExpressionsContext>();
}

DXXParser::ExpressionsContext* DXXParser::CallTemplateSubContext::expressions(size_t i) {
  return getRuleContext<DXXParser::ExpressionsContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::CallTemplateSubContext::Comma() {
  return getTokens(DXXParser::Comma);
}

tree::TerminalNode* DXXParser::CallTemplateSubContext::Comma(size_t i) {
  return getToken(DXXParser::Comma, i);
}


size_t DXXParser::CallTemplateSubContext::getRuleIndex() const {
  return DXXParser::RuleCallTemplateSub;
}


std::any DXXParser::CallTemplateSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitCallTemplateSub(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::CallTemplateSubContext* DXXParser::callTemplateSub() {
  CallTemplateSubContext *_localctx = _tracker.createInstance<CallTemplateSubContext>(_ctx, getState());
  enterRule(_localctx, 66, DXXParser::RuleCallTemplateSub);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(466);
    expressions(0);
    setState(471);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DXXParser::Comma) {
      setState(467);
      match(DXXParser::Comma);
      setState(468);
      expressions(0);
      setState(473);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TryContext ------------------------------------------------------------------

DXXParser::TryContext::TryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::TrySubContext* DXXParser::TryContext::trySub() {
  return getRuleContext<DXXParser::TrySubContext>(0);
}

std::vector<DXXParser::CatchSubContext *> DXXParser::TryContext::catchSub() {
  return getRuleContexts<DXXParser::CatchSubContext>();
}

DXXParser::CatchSubContext* DXXParser::TryContext::catchSub(size_t i) {
  return getRuleContext<DXXParser::CatchSubContext>(i);
}

DXXParser::FinallySubContext* DXXParser::TryContext::finallySub() {
  return getRuleContext<DXXParser::FinallySubContext>(0);
}


size_t DXXParser::TryContext::getRuleIndex() const {
  return DXXParser::RuleTry;
}


std::any DXXParser::TryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTry(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TryContext* DXXParser::try_() {
  TryContext *_localctx = _tracker.createInstance<TryContext>(_ctx, getState());
  enterRule(_localctx, 68, DXXParser::RuleTry);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(474);
    trySub();
    setState(478);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(475);
        catchSub(); 
      }
      setState(480);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx);
    }
    setState(482);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(481);
      finallySub();
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

//----------------- TrySubContext ------------------------------------------------------------------

DXXParser::TrySubContext::TrySubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::TrySubContext::Try() {
  return getToken(DXXParser::Try, 0);
}

DXXParser::BlockContext* DXXParser::TrySubContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::TrySubContext::getRuleIndex() const {
  return DXXParser::RuleTrySub;
}


std::any DXXParser::TrySubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTrySub(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TrySubContext* DXXParser::trySub() {
  TrySubContext *_localctx = _tracker.createInstance<TrySubContext>(_ctx, getState());
  enterRule(_localctx, 70, DXXParser::RuleTrySub);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(DXXParser::Try);
    setState(485);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchSubContext ------------------------------------------------------------------

DXXParser::CatchSubContext::CatchSubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::CatchSubContext::Catch() {
  return getToken(DXXParser::Catch, 0);
}

tree::TerminalNode* DXXParser::CatchSubContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

tree::TerminalNode* DXXParser::CatchSubContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

DXXParser::BlockContext* DXXParser::CatchSubContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}

DXXParser::VarDefineContext* DXXParser::CatchSubContext::varDefine() {
  return getRuleContext<DXXParser::VarDefineContext>(0);
}

tree::TerminalNode* DXXParser::CatchSubContext::Ellipsis() {
  return getToken(DXXParser::Ellipsis, 0);
}


size_t DXXParser::CatchSubContext::getRuleIndex() const {
  return DXXParser::RuleCatchSub;
}


std::any DXXParser::CatchSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitCatchSub(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::CatchSubContext* DXXParser::catchSub() {
  CatchSubContext *_localctx = _tracker.createInstance<CatchSubContext>(_ctx, getState());
  enterRule(_localctx, 72, DXXParser::RuleCatchSub);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(487);
    match(DXXParser::Catch);
    setState(488);
    match(DXXParser::LeftParen);
    setState(491);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DXXParser::Bool:
      case DXXParser::Final:
      case DXXParser::Float:
      case DXXParser::Inline:
      case DXXParser::Int:
      case DXXParser::Native:
      case DXXParser::Object:
      case DXXParser::Override:
      case DXXParser::Private:
      case DXXParser::Protected:
      case DXXParser::Public:
      case DXXParser::Static:
      case DXXParser::String:
      case DXXParser::Void:
      case DXXParser::ID:
      case DXXParser::Constructor:
      case DXXParser::Destructor: {
        setState(489);
        varDefine();
        break;
      }

      case DXXParser::Ellipsis: {
        setState(490);
        match(DXXParser::Ellipsis);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(493);
    match(DXXParser::RightParen);
    setState(494);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FinallySubContext ------------------------------------------------------------------

DXXParser::FinallySubContext::FinallySubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::FinallySubContext::Finally() {
  return getToken(DXXParser::Finally, 0);
}

DXXParser::BlockContext* DXXParser::FinallySubContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::FinallySubContext::getRuleIndex() const {
  return DXXParser::RuleFinallySub;
}


std::any DXXParser::FinallySubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFinallySub(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::FinallySubContext* DXXParser::finallySub() {
  FinallySubContext *_localctx = _tracker.createInstance<FinallySubContext>(_ctx, getState());
  enterRule(_localctx, 74, DXXParser::RuleFinallySub);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    match(DXXParser::Finally);
    setState(497);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThrowContext ------------------------------------------------------------------

DXXParser::ThrowContext::ThrowContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::ThrowContext::Throw() {
  return getToken(DXXParser::Throw, 0);
}

DXXParser::ExpressionsContext* DXXParser::ThrowContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}


size_t DXXParser::ThrowContext::getRuleIndex() const {
  return DXXParser::RuleThrow;
}


std::any DXXParser::ThrowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitThrow(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ThrowContext* DXXParser::throw_() {
  ThrowContext *_localctx = _tracker.createInstance<ThrowContext>(_ctx, getState());
  enterRule(_localctx, 76, DXXParser::RuleThrow);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
    match(DXXParser::Throw);
    setState(500);
    expressions(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TheTypeContext ------------------------------------------------------------------

DXXParser::TheTypeContext::TheTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::TheTypeSubContext* DXXParser::TheTypeContext::theTypeSub() {
  return getRuleContext<DXXParser::TheTypeSubContext>(0);
}

std::vector<DXXParser::InfoContext *> DXXParser::TheTypeContext::info() {
  return getRuleContexts<DXXParser::InfoContext>();
}

DXXParser::InfoContext* DXXParser::TheTypeContext::info(size_t i) {
  return getRuleContext<DXXParser::InfoContext>(i);
}


size_t DXXParser::TheTypeContext::getRuleIndex() const {
  return DXXParser::RuleTheType;
}


std::any DXXParser::TheTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTheType(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TheTypeContext* DXXParser::theType() {
  TheTypeContext *_localctx = _tracker.createInstance<TheTypeContext>(_ctx, getState());
  enterRule(_localctx, 78, DXXParser::RuleTheType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(505);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 339445088256) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(502);
      info();
      setState(507);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(508);
    theTypeSub();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TheTypeSubContext ------------------------------------------------------------------

DXXParser::TheTypeSubContext::TheTypeSubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::TheTypeSubContext::Int() {
  return getToken(DXXParser::Int, 0);
}

tree::TerminalNode* DXXParser::TheTypeSubContext::Float() {
  return getToken(DXXParser::Float, 0);
}

tree::TerminalNode* DXXParser::TheTypeSubContext::String() {
  return getToken(DXXParser::String, 0);
}

tree::TerminalNode* DXXParser::TheTypeSubContext::Bool() {
  return getToken(DXXParser::Bool, 0);
}

tree::TerminalNode* DXXParser::TheTypeSubContext::Object() {
  return getToken(DXXParser::Object, 0);
}

tree::TerminalNode* DXXParser::TheTypeSubContext::Void() {
  return getToken(DXXParser::Void, 0);
}

tree::TerminalNode* DXXParser::TheTypeSubContext::ID() {
  return getToken(DXXParser::ID, 0);
}


size_t DXXParser::TheTypeSubContext::getRuleIndex() const {
  return DXXParser::RuleTheTypeSub;
}


std::any DXXParser::TheTypeSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTheTypeSub(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TheTypeSubContext* DXXParser::theTypeSub() {
  TheTypeSubContext *_localctx = _tracker.createInstance<TheTypeSubContext>(_ctx, getState());
  enterRule(_localctx, 80, DXXParser::RuleTheTypeSub);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(510);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 563500800016388) != 0) || _la == DXXParser::ID)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdExContext ------------------------------------------------------------------

DXXParser::IdExContext::IdExContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DXXParser::IdExContext::ID() {
  return getTokens(DXXParser::ID);
}

tree::TerminalNode* DXXParser::IdExContext::ID(size_t i) {
  return getToken(DXXParser::ID, i);
}

std::vector<tree::TerminalNode *> DXXParser::IdExContext::Dot() {
  return getTokens(DXXParser::Dot);
}

tree::TerminalNode* DXXParser::IdExContext::Dot(size_t i) {
  return getToken(DXXParser::Dot, i);
}


size_t DXXParser::IdExContext::getRuleIndex() const {
  return DXXParser::RuleIdEx;
}


std::any DXXParser::IdExContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitIdEx(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::IdExContext* DXXParser::idEx() {
  IdExContext *_localctx = _tracker.createInstance<IdExContext>(_ctx, getState());
  enterRule(_localctx, 82, DXXParser::RuleIdEx);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(516);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(512);
        match(DXXParser::ID);
        setState(513);
        match(DXXParser::Dot); 
      }
      setState(518);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx);
    }
    setState(519);
    match(DXXParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InfoContext ------------------------------------------------------------------

DXXParser::InfoContext::InfoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::InfoContext::Final() {
  return getToken(DXXParser::Final, 0);
}

tree::TerminalNode* DXXParser::InfoContext::Override() {
  return getToken(DXXParser::Override, 0);
}

tree::TerminalNode* DXXParser::InfoContext::Inline() {
  return getToken(DXXParser::Inline, 0);
}

tree::TerminalNode* DXXParser::InfoContext::Static() {
  return getToken(DXXParser::Static, 0);
}

tree::TerminalNode* DXXParser::InfoContext::Public() {
  return getToken(DXXParser::Public, 0);
}

tree::TerminalNode* DXXParser::InfoContext::Protected() {
  return getToken(DXXParser::Protected, 0);
}

tree::TerminalNode* DXXParser::InfoContext::Private() {
  return getToken(DXXParser::Private, 0);
}

tree::TerminalNode* DXXParser::InfoContext::Constructor() {
  return getToken(DXXParser::Constructor, 0);
}

tree::TerminalNode* DXXParser::InfoContext::Destructor() {
  return getToken(DXXParser::Destructor, 0);
}

DXXParser::NativeContext* DXXParser::InfoContext::native() {
  return getRuleContext<DXXParser::NativeContext>(0);
}


size_t DXXParser::InfoContext::getRuleIndex() const {
  return DXXParser::RuleInfo;
}


std::any DXXParser::InfoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitInfo(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::InfoContext* DXXParser::info() {
  InfoContext *_localctx = _tracker.createInstance<InfoContext>(_ctx, getState());
  enterRule(_localctx, 84, DXXParser::RuleInfo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(531);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DXXParser::Final: {
        enterOuterAlt(_localctx, 1);
        setState(521);
        match(DXXParser::Final);
        break;
      }

      case DXXParser::Override: {
        enterOuterAlt(_localctx, 2);
        setState(522);
        match(DXXParser::Override);
        break;
      }

      case DXXParser::Inline: {
        enterOuterAlt(_localctx, 3);
        setState(523);
        match(DXXParser::Inline);
        break;
      }

      case DXXParser::Static: {
        enterOuterAlt(_localctx, 4);
        setState(524);
        match(DXXParser::Static);
        break;
      }

      case DXXParser::Public: {
        enterOuterAlt(_localctx, 5);
        setState(525);
        match(DXXParser::Public);
        break;
      }

      case DXXParser::Protected: {
        enterOuterAlt(_localctx, 6);
        setState(526);
        match(DXXParser::Protected);
        break;
      }

      case DXXParser::Private: {
        enterOuterAlt(_localctx, 7);
        setState(527);
        match(DXXParser::Private);
        break;
      }

      case DXXParser::Constructor: {
        enterOuterAlt(_localctx, 8);
        setState(528);
        match(DXXParser::Constructor);
        break;
      }

      case DXXParser::Destructor: {
        enterOuterAlt(_localctx, 9);
        setState(529);
        match(DXXParser::Destructor);
        break;
      }

      case DXXParser::Native: {
        enterOuterAlt(_localctx, 10);
        setState(530);
        native();
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

//----------------- NativeContext ------------------------------------------------------------------

DXXParser::NativeContext::NativeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::NativeContext::Native() {
  return getToken(DXXParser::Native, 0);
}

tree::TerminalNode* DXXParser::NativeContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

std::vector<tree::TerminalNode *> DXXParser::NativeContext::StringData() {
  return getTokens(DXXParser::StringData);
}

tree::TerminalNode* DXXParser::NativeContext::StringData(size_t i) {
  return getToken(DXXParser::StringData, i);
}

tree::TerminalNode* DXXParser::NativeContext::Comma() {
  return getToken(DXXParser::Comma, 0);
}

tree::TerminalNode* DXXParser::NativeContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}


size_t DXXParser::NativeContext::getRuleIndex() const {
  return DXXParser::RuleNative;
}


std::any DXXParser::NativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNative(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::NativeContext* DXXParser::native() {
  NativeContext *_localctx = _tracker.createInstance<NativeContext>(_ctx, getState());
  enterRule(_localctx, 86, DXXParser::RuleNative);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(533);
    match(DXXParser::Native);
    setState(534);
    match(DXXParser::LeftParen);
    setState(535);
    match(DXXParser::StringData);
    setState(536);
    match(DXXParser::Comma);
    setState(537);
    match(DXXParser::StringData);
    setState(538);
    match(DXXParser::RightParen);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignsContext ------------------------------------------------------------------

DXXParser::AssignsContext::AssignsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::AssignsContext::Assign() {
  return getToken(DXXParser::Assign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::ColonAssign() {
  return getToken(DXXParser::ColonAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::DivAssign() {
  return getToken(DXXParser::DivAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::ModAssign() {
  return getToken(DXXParser::ModAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::PlusAssign() {
  return getToken(DXXParser::PlusAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::MinusAssign() {
  return getToken(DXXParser::MinusAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::StarAssign() {
  return getToken(DXXParser::StarAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::XorAssign() {
  return getToken(DXXParser::XorAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::AndAssign() {
  return getToken(DXXParser::AndAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::OrAssign() {
  return getToken(DXXParser::OrAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::LeftShiftAssign() {
  return getToken(DXXParser::LeftShiftAssign, 0);
}

tree::TerminalNode* DXXParser::AssignsContext::RightShiftAssign() {
  return getToken(DXXParser::RightShiftAssign, 0);
}


size_t DXXParser::AssignsContext::getRuleIndex() const {
  return DXXParser::RuleAssigns;
}


std::any DXXParser::AssignsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitAssigns(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::AssignsContext* DXXParser::assigns() {
  AssignsContext *_localctx = _tracker.createInstance<AssignsContext>(_ctx, getState());
  enterRule(_localctx, 88, DXXParser::RuleAssigns);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(540);
    _la = _input->LA(1);
    if (!(((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & 16371) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AllOperatorsContext ------------------------------------------------------------------

DXXParser::AllOperatorsContext::AllOperatorsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Arrow() {
  return getToken(DXXParser::Arrow, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Plus() {
  return getToken(DXXParser::Plus, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Minus() {
  return getToken(DXXParser::Minus, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Star() {
  return getToken(DXXParser::Star, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Div() {
  return getToken(DXXParser::Div, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Mod() {
  return getToken(DXXParser::Mod, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Caret() {
  return getToken(DXXParser::Caret, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::And() {
  return getToken(DXXParser::And, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Or() {
  return getToken(DXXParser::Or, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Tilde() {
  return getToken(DXXParser::Tilde, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Not() {
  return getToken(DXXParser::Not, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Assign() {
  return getToken(DXXParser::Assign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::ColonAssign() {
  return getToken(DXXParser::ColonAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Less() {
  return getToken(DXXParser::Less, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Greater() {
  return getToken(DXXParser::Greater, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::PlusAssign() {
  return getToken(DXXParser::PlusAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::MinusAssign() {
  return getToken(DXXParser::MinusAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::StarAssign() {
  return getToken(DXXParser::StarAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::DivAssign() {
  return getToken(DXXParser::DivAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::ModAssign() {
  return getToken(DXXParser::ModAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::XorAssign() {
  return getToken(DXXParser::XorAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::AndAssign() {
  return getToken(DXXParser::AndAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::OrAssign() {
  return getToken(DXXParser::OrAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::LeftShiftAssign() {
  return getToken(DXXParser::LeftShiftAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::RightShiftAssign() {
  return getToken(DXXParser::RightShiftAssign, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Equal() {
  return getToken(DXXParser::Equal, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::NotEqual() {
  return getToken(DXXParser::NotEqual, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::LessEqual() {
  return getToken(DXXParser::LessEqual, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::GreaterEqual() {
  return getToken(DXXParser::GreaterEqual, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::AndAnd() {
  return getToken(DXXParser::AndAnd, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::OrOr() {
  return getToken(DXXParser::OrOr, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::PlusPlus() {
  return getToken(DXXParser::PlusPlus, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::MinusMinus() {
  return getToken(DXXParser::MinusMinus, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Colon() {
  return getToken(DXXParser::Colon, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::Dot() {
  return getToken(DXXParser::Dot, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::LeftShift() {
  return getToken(DXXParser::LeftShift, 0);
}

tree::TerminalNode* DXXParser::AllOperatorsContext::RightShift() {
  return getToken(DXXParser::RightShift, 0);
}


size_t DXXParser::AllOperatorsContext::getRuleIndex() const {
  return DXXParser::RuleAllOperators;
}


std::any DXXParser::AllOperatorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitAllOperators(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::AllOperatorsContext* DXXParser::allOperators() {
  AllOperatorsContext *_localctx = _tracker.createInstance<AllOperatorsContext>(_ctx, getState());
  enterRule(_localctx, 90, DXXParser::RuleAllOperators);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(542);
    _la = _input->LA(1);
    if (!(((((_la - 57) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 57)) & 1829656068095) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool DXXParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionsSempred(antlrcpp::downCast<ExpressionsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool DXXParser::expressionsSempred(ExpressionsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 41);
    case 1: return precpred(_ctx, 40);
    case 2: return precpred(_ctx, 39);
    case 3: return precpred(_ctx, 38);
    case 4: return precpred(_ctx, 37);
    case 5: return precpred(_ctx, 36);
    case 6: return precpred(_ctx, 35);
    case 7: return precpred(_ctx, 34);
    case 8: return precpred(_ctx, 33);
    case 9: return precpred(_ctx, 32);
    case 10: return precpred(_ctx, 31);

  default:
    break;
  }
  return true;
}

void DXXParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  dxxparserParserInitialize();
#else
  ::antlr4::internal::call_once(dxxparserParserOnceFlag, dxxparserParserInitialize);
#endif
}
