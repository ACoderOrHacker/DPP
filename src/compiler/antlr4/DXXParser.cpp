
// Generated from templates/DXXParser.g4 by ANTLR 4.13.1


#include "DXXParserListener.h"
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
      "stat", "gExpressions", "expressions", "constant", "data", "boolean", 
      "negative", "semi", "importLib", "new", "delete", "typedef", "functionDefine", 
      "function", "return", "lambdaFunction", "functionHead", "functionCall", 
      "paramList", "callParamList", "throwtable", "varDefine", "varDefineNoSet", 
      "varSet", "withStatement", "withIf", "withIfExtends", "withIfExtendsSub", 
      "withSwitchStatement", "caseStatement", "defaultStatement", "whileLoop", 
      "doWhileLoop", "foreachLoop", "goto", "gotoLabelDefine", "enum", "enumSub", 
      "class", "interface", "classMethods", "interfaceMethods", "operatorDefine", 
      "block", "try", "throw", "theType", "theTypeSub", "idEx", "info", 
      "native", "assigns", "allOperators"
    },
    std::vector<std::string>{
      "", "'asm'", "'bool'", "'break'", "'case'", "'catch'", "'char'", "'class'", 
      "'compiletime'", "'continue'", "'default'", "'delete'", "'do'", "'enum'", 
      "'extends'", "'false'", "'final'", "'finally'", "'float'", "'foreach'", 
      "'goto'", "'if'", "'import'", "'inline'", "'int'", "'implements'", 
      "'interface'", "'long'", "'native'", "'new'", "'null'", "'object'", 
      "'operator'", "'override'", "'private'", "'protected'", "'public'", 
      "'return'", "'short'", "'static'", "'string'", "'super'", "'switch'", 
      "'template'", "'this'", "'throw'", "'true'", "'try'", "'type'", "'using'", 
      "'virtual'", "'void'", "'while'", "'with'", "'('", "')'", "'['", "']'", 
      "'{'", "'}'", "'=>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "'&'", 
      "'|'", "'~'", "", "'='", "':='", "'<'", "'>'", "'+='", "'-='", "'*='", 
      "'/='", "'%='", "'^='", "'&='", "'|='", "'<<='", "'>>='", "'=='", 
      "'!='", "'<='", "'>='", "", "", "'++'", "'--'", "','", "':'", "';'", 
      "'.'", "'...'", "'<<'", "'>>'", "", "'__constructor__'", "'__destructor__'"
    },
    std::vector<std::string>{
      "", "Asm", "Bool", "Break", "Case", "Catch", "Char", "Class", "Compiletime", 
      "Continue", "Default", "Delete", "Do", "Enum", "Extends", "False", 
      "Final", "Finally", "Float", "Foreach", "Goto", "If", "Import", "Inline", 
      "Int", "Implements", "Interface", "Long", "Native", "New", "Null", 
      "Object", "Operator", "Override", "Private", "Protected", "Public", 
      "Return", "Short", "Static", "String", "Super", "Switch", "Template", 
      "This", "Throw", "True", "Try", "Type", "Using", "Virtual", "Void", 
      "While", "With", "LeftParen", "RightParen", "LeftBracket", "RightBracket", 
      "LeftBrace", "RightBrace", "Arrow", "Plus", "Minus", "Star", "Div", 
      "Mod", "Caret", "And", "Or", "Tilde", "Not", "Assign", "ColonAssign", 
      "Less", "Greater", "PlusAssign", "MinusAssign", "StarAssign", "DivAssign", 
      "ModAssign", "XorAssign", "AndAssign", "OrAssign", "LeftShiftAssign", 
      "RightShiftAssign", "Equal", "NotEqual", "LessEqual", "GreaterEqual", 
      "AndAnd", "OrOr", "PlusPlus", "MinusMinus", "Comma", "Colon", "Semi", 
      "Dot", "Ellipsis", "LeftShift", "RightShift", "ID", "Constructor", 
      "Destructor", "Whitespace", "Newline", "BlockComment", "LineComment", 
      "IntegerData", "FloatingNumberData", "StringData"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,109,581,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,1,0,5,0,108,8,0,10,0,12,0,111,9,0,1,
  	0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,122,8,1,1,2,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,141,8,2,1,3,1,3,1,3,1,
  	3,1,3,3,3,148,8,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,156,8,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,3,4,164,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	5,4,196,8,4,10,4,12,4,199,9,4,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,8,1,8,1,8,
  	1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,13,1,
  	13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,15,3,15,234,8,15,1,15,1,15,1,
  	15,1,16,5,16,240,8,16,10,16,12,16,243,9,16,1,16,1,16,1,16,3,16,248,8,
  	16,1,16,1,16,1,16,1,16,3,16,254,8,16,1,17,1,17,1,17,3,17,259,8,17,1,17,
  	1,17,1,18,1,18,1,18,5,18,266,8,18,10,18,12,18,269,9,18,1,18,1,18,3,18,
  	273,8,18,1,19,1,19,1,19,5,19,278,8,19,10,19,12,19,281,9,19,1,20,1,20,
  	1,20,1,20,5,20,287,8,20,10,20,12,20,290,9,20,1,20,3,20,293,8,20,1,21,
  	1,21,5,21,297,8,21,10,21,12,21,300,9,21,1,21,1,21,1,21,1,21,3,21,306,
  	8,21,1,22,1,22,5,22,310,8,22,10,22,12,22,313,9,22,1,22,1,22,1,23,1,23,
  	1,23,1,23,1,24,1,24,1,24,3,24,324,8,24,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,26,1,26,1,26,1,26,5,26,337,8,26,10,26,12,26,340,9,26,1,26,1,26,
  	1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,5,28,354,8,28,10,28,
  	12,28,357,9,28,1,28,3,28,360,8,28,1,28,1,28,1,29,1,29,1,29,1,29,1,30,
  	1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,3,31,377,8,31,1,32,1,32,1,32,
  	1,32,1,32,1,32,1,33,1,33,1,33,1,33,3,33,389,8,33,1,33,1,33,1,33,1,33,
  	3,33,395,8,33,1,34,1,34,1,34,1,35,1,35,1,35,1,35,1,36,1,36,1,36,1,36,
  	1,36,1,36,5,36,410,8,36,10,36,12,36,413,9,36,3,36,415,8,36,1,36,1,36,
  	1,37,1,37,1,37,1,37,3,37,423,8,37,1,38,1,38,1,38,1,38,1,38,1,38,1,38,
  	3,38,432,8,38,3,38,434,8,38,1,38,1,38,1,38,1,38,1,38,3,38,441,8,38,3,
  	38,443,8,38,1,38,1,38,5,38,447,8,38,10,38,12,38,450,9,38,1,38,1,38,1,
  	39,1,39,1,39,1,39,1,39,1,39,5,39,460,8,39,10,39,12,39,463,9,39,1,39,3,
  	39,466,8,39,3,39,468,8,39,1,39,1,39,5,39,472,8,39,10,39,12,39,475,9,39,
  	1,39,1,39,1,40,1,40,1,40,1,40,1,40,1,40,3,40,485,8,40,1,41,1,41,1,41,
  	1,41,3,41,491,8,41,1,42,1,42,1,42,1,42,3,42,497,8,42,1,42,1,42,1,42,1,
  	42,3,42,503,8,42,1,43,1,43,5,43,507,8,43,10,43,12,43,510,9,43,1,43,1,
  	43,1,44,1,44,1,44,1,44,1,44,1,44,3,44,520,8,44,1,44,1,44,5,44,524,8,44,
  	10,44,12,44,527,9,44,1,44,1,44,3,44,531,8,44,1,45,1,45,1,45,3,45,536,
  	8,45,1,46,5,46,539,8,46,10,46,12,46,542,9,46,1,46,1,46,1,47,1,47,1,48,
  	1,48,5,48,550,8,48,10,48,12,48,553,9,48,1,48,1,48,1,49,1,49,1,49,1,49,
  	1,49,1,49,1,49,1,49,1,49,1,49,1,49,3,49,568,8,49,1,50,1,50,1,50,1,50,
  	1,50,1,50,1,50,1,51,1,51,1,52,1,52,1,52,0,1,8,53,0,2,4,6,8,10,12,14,16,
  	18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,
  	64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,0,10,
  	2,0,69,70,91,92,1,0,85,86,1,0,63,65,1,0,61,62,1,0,98,99,2,0,73,74,87,
  	88,2,0,15,15,46,46,8,0,2,2,18,18,24,24,31,31,40,40,48,48,51,51,100,100,
  	2,0,71,72,75,84,4,0,60,92,94,94,96,96,98,99,632,0,109,1,0,0,0,2,121,1,
  	0,0,0,4,140,1,0,0,0,6,147,1,0,0,0,8,163,1,0,0,0,10,200,1,0,0,0,12,202,
  	1,0,0,0,14,205,1,0,0,0,16,207,1,0,0,0,18,210,1,0,0,0,20,213,1,0,0,0,22,
  	216,1,0,0,0,24,221,1,0,0,0,26,223,1,0,0,0,28,226,1,0,0,0,30,229,1,0,0,
  	0,32,241,1,0,0,0,34,255,1,0,0,0,36,262,1,0,0,0,38,274,1,0,0,0,40,282,
  	1,0,0,0,42,294,1,0,0,0,44,307,1,0,0,0,46,316,1,0,0,0,48,323,1,0,0,0,50,
  	325,1,0,0,0,52,332,1,0,0,0,54,343,1,0,0,0,56,347,1,0,0,0,58,363,1,0,0,
  	0,60,367,1,0,0,0,62,371,1,0,0,0,64,378,1,0,0,0,66,384,1,0,0,0,68,396,
  	1,0,0,0,70,399,1,0,0,0,72,403,1,0,0,0,74,418,1,0,0,0,76,424,1,0,0,0,78,
  	453,1,0,0,0,80,484,1,0,0,0,82,490,1,0,0,0,84,492,1,0,0,0,86,504,1,0,0,
  	0,88,513,1,0,0,0,90,532,1,0,0,0,92,540,1,0,0,0,94,545,1,0,0,0,96,551,
  	1,0,0,0,98,567,1,0,0,0,100,569,1,0,0,0,102,576,1,0,0,0,104,578,1,0,0,
  	0,106,108,3,2,1,0,107,106,1,0,0,0,108,111,1,0,0,0,109,107,1,0,0,0,109,
  	110,1,0,0,0,110,112,1,0,0,0,111,109,1,0,0,0,112,113,5,0,0,1,113,1,1,0,
  	0,0,114,122,3,16,8,0,115,122,3,26,13,0,116,122,3,24,12,0,117,122,3,42,
  	21,0,118,122,3,76,38,0,119,122,3,78,39,0,120,122,3,14,7,0,121,114,1,0,
  	0,0,121,115,1,0,0,0,121,116,1,0,0,0,121,117,1,0,0,0,121,118,1,0,0,0,121,
  	119,1,0,0,0,121,120,1,0,0,0,122,3,1,0,0,0,123,141,3,18,9,0,124,141,3,
  	20,10,0,125,141,3,42,21,0,126,141,3,46,23,0,127,141,3,48,24,0,128,141,
  	3,62,31,0,129,141,3,64,32,0,130,141,3,66,33,0,131,141,3,68,34,0,132,141,
  	3,70,35,0,133,141,3,88,44,0,134,141,3,90,45,0,135,141,3,22,11,0,136,141,
  	3,28,14,0,137,141,5,3,0,0,138,141,5,9,0,0,139,141,3,14,7,0,140,123,1,
  	0,0,0,140,124,1,0,0,0,140,125,1,0,0,0,140,126,1,0,0,0,140,127,1,0,0,0,
  	140,128,1,0,0,0,140,129,1,0,0,0,140,130,1,0,0,0,140,131,1,0,0,0,140,132,
  	1,0,0,0,140,133,1,0,0,0,140,134,1,0,0,0,140,135,1,0,0,0,140,136,1,0,0,
  	0,140,137,1,0,0,0,140,138,1,0,0,0,140,139,1,0,0,0,141,5,1,0,0,0,142,148,
  	5,107,0,0,143,148,5,108,0,0,144,148,5,109,0,0,145,148,3,10,5,0,146,148,
  	5,30,0,0,147,142,1,0,0,0,147,143,1,0,0,0,147,144,1,0,0,0,147,145,1,0,
  	0,0,147,146,1,0,0,0,148,7,1,0,0,0,149,150,6,4,-1,0,150,164,3,6,3,0,151,
  	164,3,96,48,0,152,164,3,34,17,0,153,155,5,54,0,0,154,156,3,8,4,0,155,
  	154,1,0,0,0,155,156,1,0,0,0,156,157,1,0,0,0,157,164,5,55,0,0,158,159,
  	7,0,0,0,159,164,3,8,4,14,160,164,3,12,6,0,161,164,3,30,15,0,162,164,3,
  	92,46,0,163,149,1,0,0,0,163,151,1,0,0,0,163,152,1,0,0,0,163,153,1,0,0,
  	0,163,158,1,0,0,0,163,160,1,0,0,0,163,161,1,0,0,0,163,162,1,0,0,0,164,
  	197,1,0,0,0,165,166,10,13,0,0,166,167,5,89,0,0,167,196,3,8,4,14,168,169,
  	10,12,0,0,169,170,5,90,0,0,170,196,3,8,4,13,171,172,10,11,0,0,172,173,
  	7,1,0,0,173,196,3,8,4,12,174,175,10,10,0,0,175,176,7,2,0,0,176,196,3,
  	8,4,11,177,178,10,9,0,0,178,179,7,3,0,0,179,196,3,8,4,10,180,181,10,8,
  	0,0,181,182,7,4,0,0,182,196,3,8,4,9,183,184,10,7,0,0,184,185,7,5,0,0,
  	185,196,3,8,4,8,186,187,10,6,0,0,187,188,5,67,0,0,188,196,3,8,4,7,189,
  	190,10,5,0,0,190,191,5,66,0,0,191,196,3,8,4,6,192,193,10,4,0,0,193,194,
  	5,68,0,0,194,196,3,8,4,5,195,165,1,0,0,0,195,168,1,0,0,0,195,171,1,0,
  	0,0,195,174,1,0,0,0,195,177,1,0,0,0,195,180,1,0,0,0,195,183,1,0,0,0,195,
  	186,1,0,0,0,195,189,1,0,0,0,195,192,1,0,0,0,196,199,1,0,0,0,197,195,1,
  	0,0,0,197,198,1,0,0,0,198,9,1,0,0,0,199,197,1,0,0,0,200,201,7,6,0,0,201,
  	11,1,0,0,0,202,203,5,62,0,0,203,204,3,8,4,0,204,13,1,0,0,0,205,206,5,
  	95,0,0,206,15,1,0,0,0,207,208,5,22,0,0,208,209,3,96,48,0,209,17,1,0,0,
  	0,210,211,5,29,0,0,211,212,3,92,46,0,212,19,1,0,0,0,213,214,5,11,0,0,
  	214,215,3,8,4,0,215,21,1,0,0,0,216,217,5,49,0,0,217,218,5,100,0,0,218,
  	219,5,71,0,0,219,220,3,92,46,0,220,23,1,0,0,0,221,222,3,32,16,0,222,25,
  	1,0,0,0,223,224,3,32,16,0,224,225,3,86,43,0,225,27,1,0,0,0,226,227,5,
  	37,0,0,227,228,3,8,4,0,228,29,1,0,0,0,229,230,5,56,0,0,230,231,5,57,0,
  	0,231,233,5,54,0,0,232,234,3,36,18,0,233,232,1,0,0,0,233,234,1,0,0,0,
  	234,235,1,0,0,0,235,236,5,55,0,0,236,237,3,86,43,0,237,31,1,0,0,0,238,
  	240,3,98,49,0,239,238,1,0,0,0,240,243,1,0,0,0,241,239,1,0,0,0,241,242,
  	1,0,0,0,242,244,1,0,0,0,243,241,1,0,0,0,244,245,5,100,0,0,245,247,5,54,
  	0,0,246,248,3,36,18,0,247,246,1,0,0,0,247,248,1,0,0,0,248,249,1,0,0,0,
  	249,250,5,55,0,0,250,251,5,60,0,0,251,253,3,92,46,0,252,254,3,40,20,0,
  	253,252,1,0,0,0,253,254,1,0,0,0,254,33,1,0,0,0,255,256,3,96,48,0,256,
  	258,5,54,0,0,257,259,3,38,19,0,258,257,1,0,0,0,258,259,1,0,0,0,259,260,
  	1,0,0,0,260,261,5,55,0,0,261,35,1,0,0,0,262,267,3,42,21,0,263,264,5,93,
  	0,0,264,266,3,42,21,0,265,263,1,0,0,0,266,269,1,0,0,0,267,265,1,0,0,0,
  	267,268,1,0,0,0,268,272,1,0,0,0,269,267,1,0,0,0,270,271,5,93,0,0,271,
  	273,5,97,0,0,272,270,1,0,0,0,272,273,1,0,0,0,273,37,1,0,0,0,274,279,3,
  	8,4,0,275,276,5,93,0,0,276,278,3,8,4,0,277,275,1,0,0,0,278,281,1,0,0,
  	0,279,277,1,0,0,0,279,280,1,0,0,0,280,39,1,0,0,0,281,279,1,0,0,0,282,
  	288,5,45,0,0,283,284,3,96,48,0,284,285,5,93,0,0,285,287,1,0,0,0,286,283,
  	1,0,0,0,287,290,1,0,0,0,288,286,1,0,0,0,288,289,1,0,0,0,289,292,1,0,0,
  	0,290,288,1,0,0,0,291,293,3,96,48,0,292,291,1,0,0,0,292,293,1,0,0,0,293,
  	41,1,0,0,0,294,298,3,92,46,0,295,297,3,98,49,0,296,295,1,0,0,0,297,300,
  	1,0,0,0,298,296,1,0,0,0,298,299,1,0,0,0,299,301,1,0,0,0,300,298,1,0,0,
  	0,301,305,5,100,0,0,302,303,3,102,51,0,303,304,3,8,4,0,304,306,1,0,0,
  	0,305,302,1,0,0,0,305,306,1,0,0,0,306,43,1,0,0,0,307,311,3,92,46,0,308,
  	310,3,98,49,0,309,308,1,0,0,0,310,313,1,0,0,0,311,309,1,0,0,0,311,312,
  	1,0,0,0,312,314,1,0,0,0,313,311,1,0,0,0,314,315,5,100,0,0,315,45,1,0,
  	0,0,316,317,3,96,48,0,317,318,3,102,51,0,318,319,3,8,4,0,319,47,1,0,0,
  	0,320,324,3,50,25,0,321,324,3,52,26,0,322,324,3,56,28,0,323,320,1,0,0,
  	0,323,321,1,0,0,0,323,322,1,0,0,0,324,49,1,0,0,0,325,326,5,53,0,0,326,
  	327,5,21,0,0,327,328,5,54,0,0,328,329,3,8,4,0,329,330,5,55,0,0,330,331,
  	3,86,43,0,331,51,1,0,0,0,332,333,5,53,0,0,333,334,5,21,0,0,334,338,5,
  	58,0,0,335,337,3,54,27,0,336,335,1,0,0,0,337,340,1,0,0,0,338,336,1,0,
  	0,0,338,339,1,0,0,0,339,341,1,0,0,0,340,338,1,0,0,0,341,342,5,59,0,0,
  	342,53,1,0,0,0,343,344,3,8,4,0,344,345,5,60,0,0,345,346,3,86,43,0,346,
  	55,1,0,0,0,347,348,5,53,0,0,348,349,5,54,0,0,349,350,3,8,4,0,350,351,
  	5,55,0,0,351,355,5,58,0,0,352,354,3,58,29,0,353,352,1,0,0,0,354,357,1,
  	0,0,0,355,353,1,0,0,0,355,356,1,0,0,0,356,359,1,0,0,0,357,355,1,0,0,0,
  	358,360,3,60,30,0,359,358,1,0,0,0,359,360,1,0,0,0,360,361,1,0,0,0,361,
  	362,5,59,0,0,362,57,1,0,0,0,363,364,3,6,3,0,364,365,5,60,0,0,365,366,
  	3,86,43,0,366,59,1,0,0,0,367,368,5,10,0,0,368,369,5,60,0,0,369,370,3,
  	86,43,0,370,61,1,0,0,0,371,372,5,52,0,0,372,373,5,54,0,0,373,374,3,4,
  	2,0,374,376,5,55,0,0,375,377,3,86,43,0,376,375,1,0,0,0,376,377,1,0,0,
  	0,377,63,1,0,0,0,378,379,3,62,31,0,379,380,5,12,0,0,380,381,5,54,0,0,
  	381,382,3,4,2,0,382,383,5,55,0,0,383,65,1,0,0,0,384,385,5,19,0,0,385,
  	388,5,54,0,0,386,389,3,42,21,0,387,389,3,96,48,0,388,386,1,0,0,0,388,
  	387,1,0,0,0,389,390,1,0,0,0,390,391,5,94,0,0,391,392,3,4,2,0,392,394,
  	5,55,0,0,393,395,3,86,43,0,394,393,1,0,0,0,394,395,1,0,0,0,395,67,1,0,
  	0,0,396,397,5,20,0,0,397,398,5,100,0,0,398,69,1,0,0,0,399,400,5,100,0,
  	0,400,401,5,94,0,0,401,402,3,86,43,0,402,71,1,0,0,0,403,404,5,13,0,0,
  	404,405,3,74,37,0,405,414,5,58,0,0,406,411,3,74,37,0,407,408,5,93,0,0,
  	408,410,3,74,37,0,409,407,1,0,0,0,410,413,1,0,0,0,411,409,1,0,0,0,411,
  	412,1,0,0,0,412,415,1,0,0,0,413,411,1,0,0,0,414,406,1,0,0,0,414,415,1,
  	0,0,0,415,416,1,0,0,0,416,417,5,59,0,0,417,73,1,0,0,0,418,419,5,100,0,
  	0,419,422,5,71,0,0,420,423,3,8,4,0,421,423,3,4,2,0,422,420,1,0,0,0,422,
  	421,1,0,0,0,423,75,1,0,0,0,424,425,5,7,0,0,425,433,5,100,0,0,426,431,
  	5,14,0,0,427,428,3,96,48,0,428,429,5,93,0,0,429,430,3,96,48,0,430,432,
  	1,0,0,0,431,427,1,0,0,0,431,432,1,0,0,0,432,434,1,0,0,0,433,426,1,0,0,
  	0,433,434,1,0,0,0,434,442,1,0,0,0,435,440,5,25,0,0,436,437,3,96,48,0,
  	437,438,5,93,0,0,438,439,3,96,48,0,439,441,1,0,0,0,440,436,1,0,0,0,440,
  	441,1,0,0,0,441,443,1,0,0,0,442,435,1,0,0,0,442,443,1,0,0,0,443,444,1,
  	0,0,0,444,448,5,58,0,0,445,447,3,80,40,0,446,445,1,0,0,0,447,450,1,0,
  	0,0,448,446,1,0,0,0,448,449,1,0,0,0,449,451,1,0,0,0,450,448,1,0,0,0,451,
  	452,5,59,0,0,452,77,1,0,0,0,453,454,5,26,0,0,454,467,5,100,0,0,455,461,
  	5,25,0,0,456,457,3,96,48,0,457,458,5,93,0,0,458,460,1,0,0,0,459,456,1,
  	0,0,0,460,463,1,0,0,0,461,459,1,0,0,0,461,462,1,0,0,0,462,465,1,0,0,0,
  	463,461,1,0,0,0,464,466,3,96,48,0,465,464,1,0,0,0,465,466,1,0,0,0,466,
  	468,1,0,0,0,467,455,1,0,0,0,467,468,1,0,0,0,468,469,1,0,0,0,469,473,5,
  	58,0,0,470,472,3,82,41,0,471,470,1,0,0,0,472,475,1,0,0,0,473,471,1,0,
  	0,0,473,474,1,0,0,0,474,476,1,0,0,0,475,473,1,0,0,0,476,477,5,59,0,0,
  	477,79,1,0,0,0,478,485,3,76,38,0,479,485,3,78,39,0,480,485,3,26,13,0,
  	481,485,3,24,12,0,482,485,3,42,21,0,483,485,3,14,7,0,484,478,1,0,0,0,
  	484,479,1,0,0,0,484,480,1,0,0,0,484,481,1,0,0,0,484,482,1,0,0,0,484,483,
  	1,0,0,0,485,81,1,0,0,0,486,491,3,24,12,0,487,491,3,44,22,0,488,491,3,
  	78,39,0,489,491,3,14,7,0,490,486,1,0,0,0,490,487,1,0,0,0,490,488,1,0,
  	0,0,490,489,1,0,0,0,491,83,1,0,0,0,492,493,5,32,0,0,493,494,3,104,52,
  	0,494,496,5,54,0,0,495,497,3,36,18,0,496,495,1,0,0,0,496,497,1,0,0,0,
  	497,498,1,0,0,0,498,499,5,55,0,0,499,500,5,60,0,0,500,502,3,92,46,0,501,
  	503,3,86,43,0,502,501,1,0,0,0,502,503,1,0,0,0,503,85,1,0,0,0,504,508,
  	5,58,0,0,505,507,3,4,2,0,506,505,1,0,0,0,507,510,1,0,0,0,508,506,1,0,
  	0,0,508,509,1,0,0,0,509,511,1,0,0,0,510,508,1,0,0,0,511,512,5,59,0,0,
  	512,87,1,0,0,0,513,514,5,47,0,0,514,525,3,86,43,0,515,516,5,5,0,0,516,
  	519,5,54,0,0,517,520,3,42,21,0,518,520,5,97,0,0,519,517,1,0,0,0,519,518,
  	1,0,0,0,520,521,1,0,0,0,521,522,5,55,0,0,522,524,3,86,43,0,523,515,1,
  	0,0,0,524,527,1,0,0,0,525,523,1,0,0,0,525,526,1,0,0,0,526,530,1,0,0,0,
  	527,525,1,0,0,0,528,529,5,17,0,0,529,531,3,86,43,0,530,528,1,0,0,0,530,
  	531,1,0,0,0,531,89,1,0,0,0,532,535,5,45,0,0,533,536,3,96,48,0,534,536,
  	3,34,17,0,535,533,1,0,0,0,535,534,1,0,0,0,536,91,1,0,0,0,537,539,3,98,
  	49,0,538,537,1,0,0,0,539,542,1,0,0,0,540,538,1,0,0,0,540,541,1,0,0,0,
  	541,543,1,0,0,0,542,540,1,0,0,0,543,544,3,94,47,0,544,93,1,0,0,0,545,
  	546,7,7,0,0,546,95,1,0,0,0,547,548,5,100,0,0,548,550,5,96,0,0,549,547,
  	1,0,0,0,550,553,1,0,0,0,551,549,1,0,0,0,551,552,1,0,0,0,552,554,1,0,0,
  	0,553,551,1,0,0,0,554,555,5,100,0,0,555,97,1,0,0,0,556,568,5,8,0,0,557,
  	568,5,16,0,0,558,568,5,33,0,0,559,568,5,23,0,0,560,568,5,39,0,0,561,568,
  	5,36,0,0,562,568,5,35,0,0,563,568,5,34,0,0,564,568,5,101,0,0,565,568,
  	5,102,0,0,566,568,3,100,50,0,567,556,1,0,0,0,567,557,1,0,0,0,567,558,
  	1,0,0,0,567,559,1,0,0,0,567,560,1,0,0,0,567,561,1,0,0,0,567,562,1,0,0,
  	0,567,563,1,0,0,0,567,564,1,0,0,0,567,565,1,0,0,0,567,566,1,0,0,0,568,
  	99,1,0,0,0,569,570,5,28,0,0,570,571,5,54,0,0,571,572,5,109,0,0,572,573,
  	5,93,0,0,573,574,5,109,0,0,574,575,5,55,0,0,575,101,1,0,0,0,576,577,7,
  	8,0,0,577,103,1,0,0,0,578,579,7,9,0,0,579,105,1,0,0,0,52,109,121,140,
  	147,155,163,195,197,233,241,247,253,258,267,272,279,288,292,298,305,311,
  	323,338,355,359,376,388,394,411,414,422,431,433,440,442,448,461,465,467,
  	473,484,490,496,502,508,519,525,530,535,540,551,567
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

std::vector<DXXParser::GExpressionsContext *> DXXParser::StatContext::gExpressions() {
  return getRuleContexts<DXXParser::GExpressionsContext>();
}

DXXParser::GExpressionsContext* DXXParser::StatContext::gExpressions(size_t i) {
  return getRuleContext<DXXParser::GExpressionsContext>(i);
}


size_t DXXParser::StatContext::getRuleIndex() const {
  return DXXParser::RuleStat;
}

void DXXParser::StatContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStat(this);
}

void DXXParser::StatContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStat(this);
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
    setState(109);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055419572612) != 0) || ((((_la - 95) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 95)) & 225) != 0)) {
      setState(106);
      gExpressions();
      setState(111);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(112);
    match(DXXParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GExpressionsContext ------------------------------------------------------------------

DXXParser::GExpressionsContext::GExpressionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DXXParser::GExpressionsContext::getRuleIndex() const {
  return DXXParser::RuleGExpressions;
}

void DXXParser::GExpressionsContext::copyFrom(GExpressionsContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- GSemiExprContext ------------------------------------------------------------------

DXXParser::SemiContext* DXXParser::GSemiExprContext::semi() {
  return getRuleContext<DXXParser::SemiContext>(0);
}

DXXParser::GSemiExprContext::GSemiExprContext(GExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::GSemiExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGSemiExpr(this);
}
void DXXParser::GSemiExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGSemiExpr(this);
}

std::any DXXParser::GSemiExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitGSemiExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- InterfaceExprContext ------------------------------------------------------------------

DXXParser::InterfaceContext* DXXParser::InterfaceExprContext::interface() {
  return getRuleContext<DXXParser::InterfaceContext>(0);
}

DXXParser::InterfaceExprContext::InterfaceExprContext(GExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::InterfaceExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceExpr(this);
}
void DXXParser::InterfaceExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceExpr(this);
}

std::any DXXParser::InterfaceExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitInterfaceExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionDefineExprContext ------------------------------------------------------------------

DXXParser::FunctionDefineContext* DXXParser::FunctionDefineExprContext::functionDefine() {
  return getRuleContext<DXXParser::FunctionDefineContext>(0);
}

DXXParser::FunctionDefineExprContext::FunctionDefineExprContext(GExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::FunctionDefineExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefineExpr(this);
}
void DXXParser::FunctionDefineExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefineExpr(this);
}

std::any DXXParser::FunctionDefineExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDefineExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassExprContext ------------------------------------------------------------------

DXXParser::ClassContext* DXXParser::ClassExprContext::class_() {
  return getRuleContext<DXXParser::ClassContext>(0);
}

DXXParser::ClassExprContext::ClassExprContext(GExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::ClassExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassExpr(this);
}
void DXXParser::ClassExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassExpr(this);
}

std::any DXXParser::ClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ImportExprContext ------------------------------------------------------------------

DXXParser::ImportLibContext* DXXParser::ImportExprContext::importLib() {
  return getRuleContext<DXXParser::ImportLibContext>(0);
}

DXXParser::ImportExprContext::ImportExprContext(GExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::ImportExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportExpr(this);
}
void DXXParser::ImportExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportExpr(this);
}

std::any DXXParser::ImportExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitImportExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDefineExprContext ------------------------------------------------------------------

DXXParser::VarDefineContext* DXXParser::VarDefineExprContext::varDefine() {
  return getRuleContext<DXXParser::VarDefineContext>(0);
}

DXXParser::VarDefineExprContext::VarDefineExprContext(GExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::VarDefineExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefineExpr(this);
}
void DXXParser::VarDefineExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefineExpr(this);
}

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

DXXParser::FunctionExprContext::FunctionExprContext(GExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::FunctionExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionExpr(this);
}
void DXXParser::FunctionExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionExpr(this);
}

std::any DXXParser::FunctionExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionExpr(this);
  else
    return visitor->visitChildren(this);
}
DXXParser::GExpressionsContext* DXXParser::gExpressions() {
  GExpressionsContext *_localctx = _tracker.createInstance<GExpressionsContext>(_ctx, getState());
  enterRule(_localctx, 2, DXXParser::RuleGExpressions);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(121);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<DXXParser::ImportExprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(114);
      importLib();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<DXXParser::FunctionExprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(115);
      function();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<DXXParser::FunctionDefineExprContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(116);
      functionDefine();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<DXXParser::VarDefineExprContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(117);
      varDefine();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<DXXParser::ClassExprContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(118);
      class_();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<DXXParser::InterfaceExprContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(119);
      interface();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<DXXParser::GSemiExprContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(120);
      semi();
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

//----------------- NewExprContext ------------------------------------------------------------------

DXXParser::NewContext* DXXParser::NewExprContext::new_() {
  return getRuleContext<DXXParser::NewContext>(0);
}

DXXParser::NewExprContext::NewExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::NewExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNewExpr(this);
}
void DXXParser::NewExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNewExpr(this);
}

std::any DXXParser::NewExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNewExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarSetExprContext ------------------------------------------------------------------

DXXParser::VarSetContext* DXXParser::VarSetExprContext::varSet() {
  return getRuleContext<DXXParser::VarSetContext>(0);
}

DXXParser::VarSetExprContext::VarSetExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::VarSetExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarSetExpr(this);
}
void DXXParser::VarSetExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarSetExpr(this);
}

std::any DXXParser::VarSetExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVarSetExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ForeachLoopExprContext ------------------------------------------------------------------

DXXParser::ForeachLoopContext* DXXParser::ForeachLoopExprContext::foreachLoop() {
  return getRuleContext<DXXParser::ForeachLoopContext>(0);
}

DXXParser::ForeachLoopExprContext::ForeachLoopExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::ForeachLoopExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeachLoopExpr(this);
}
void DXXParser::ForeachLoopExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeachLoopExpr(this);
}

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

void DXXParser::ThrowExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThrowExpr(this);
}
void DXXParser::ThrowExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThrowExpr(this);
}

std::any DXXParser::ThrowExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitThrowExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypedefExprTagContext ------------------------------------------------------------------

DXXParser::TypedefContext* DXXParser::TypedefExprTagContext::typedef_() {
  return getRuleContext<DXXParser::TypedefContext>(0);
}

DXXParser::TypedefExprTagContext::TypedefExprTagContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::TypedefExprTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypedefExprTag(this);
}
void DXXParser::TypedefExprTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypedefExprTag(this);
}

std::any DXXParser::TypedefExprTagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTypedefExprTag(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DoWhileLoopExprContext ------------------------------------------------------------------

DXXParser::DoWhileLoopContext* DXXParser::DoWhileLoopExprContext::doWhileLoop() {
  return getRuleContext<DXXParser::DoWhileLoopContext>(0);
}

DXXParser::DoWhileLoopExprContext::DoWhileLoopExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::DoWhileLoopExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoWhileLoopExpr(this);
}
void DXXParser::DoWhileLoopExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoWhileLoopExpr(this);
}

std::any DXXParser::DoWhileLoopExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitDoWhileLoopExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GotoExprContext ------------------------------------------------------------------

DXXParser::GotoContext* DXXParser::GotoExprContext::goto_() {
  return getRuleContext<DXXParser::GotoContext>(0);
}

DXXParser::GotoExprContext::GotoExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::GotoExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGotoExpr(this);
}
void DXXParser::GotoExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGotoExpr(this);
}

std::any DXXParser::GotoExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitGotoExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DeleteExprContext ------------------------------------------------------------------

DXXParser::DeleteContext* DXXParser::DeleteExprContext::delete_() {
  return getRuleContext<DXXParser::DeleteContext>(0);
}

DXXParser::DeleteExprContext::DeleteExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::DeleteExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeleteExpr(this);
}
void DXXParser::DeleteExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeleteExpr(this);
}

std::any DXXParser::DeleteExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitDeleteExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SemiExprContext ------------------------------------------------------------------

DXXParser::SemiContext* DXXParser::SemiExprContext::semi() {
  return getRuleContext<DXXParser::SemiContext>(0);
}

DXXParser::SemiExprContext::SemiExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::SemiExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSemiExpr(this);
}
void DXXParser::SemiExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSemiExpr(this);
}

std::any DXXParser::SemiExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitSemiExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ReturnExprContext ------------------------------------------------------------------

DXXParser::ReturnContext* DXXParser::ReturnExprContext::return_() {
  return getRuleContext<DXXParser::ReturnContext>(0);
}

DXXParser::ReturnExprContext::ReturnExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::ReturnExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnExpr(this);
}
void DXXParser::ReturnExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnExpr(this);
}

std::any DXXParser::ReturnExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitReturnExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BreakExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::BreakExprContext::Break() {
  return getToken(DXXParser::Break, 0);
}

DXXParser::BreakExprContext::BreakExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::BreakExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakExpr(this);
}
void DXXParser::BreakExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakExpr(this);
}

std::any DXXParser::BreakExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitBreakExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ContinueExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::ContinueExprContext::Continue() {
  return getToken(DXXParser::Continue, 0);
}

DXXParser::ContinueExprContext::ContinueExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::ContinueExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueExpr(this);
}
void DXXParser::ContinueExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueExpr(this);
}

std::any DXXParser::ContinueExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitContinueExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDefineExprTagContext ------------------------------------------------------------------

DXXParser::VarDefineContext* DXXParser::VarDefineExprTagContext::varDefine() {
  return getRuleContext<DXXParser::VarDefineContext>(0);
}

DXXParser::VarDefineExprTagContext::VarDefineExprTagContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::VarDefineExprTagContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefineExprTag(this);
}
void DXXParser::VarDefineExprTagContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefineExprTag(this);
}

std::any DXXParser::VarDefineExprTagContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVarDefineExprTag(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileLoopExprContext ------------------------------------------------------------------

DXXParser::WhileLoopContext* DXXParser::WhileLoopExprContext::whileLoop() {
  return getRuleContext<DXXParser::WhileLoopContext>(0);
}

DXXParser::WhileLoopExprContext::WhileLoopExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::WhileLoopExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileLoopExpr(this);
}
void DXXParser::WhileLoopExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileLoopExpr(this);
}

std::any DXXParser::WhileLoopExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWhileLoopExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TryExprContext ------------------------------------------------------------------

DXXParser::TryContext* DXXParser::TryExprContext::try_() {
  return getRuleContext<DXXParser::TryContext>(0);
}

DXXParser::TryExprContext::TryExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::TryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTryExpr(this);
}
void DXXParser::TryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTryExpr(this);
}

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

void DXXParser::GotoLabelDefineExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGotoLabelDefineExpr(this);
}
void DXXParser::GotoLabelDefineExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGotoLabelDefineExpr(this);
}

std::any DXXParser::GotoLabelDefineExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitGotoLabelDefineExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WithExprContext ------------------------------------------------------------------

DXXParser::WithStatementContext* DXXParser::WithExprContext::withStatement() {
  return getRuleContext<DXXParser::WithStatementContext>(0);
}

DXXParser::WithExprContext::WithExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }

void DXXParser::WithExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithExpr(this);
}
void DXXParser::WithExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithExpr(this);
}

std::any DXXParser::WithExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWithExpr(this);
  else
    return visitor->visitChildren(this);
}
DXXParser::ExpressionsContext* DXXParser::expressions() {
  ExpressionsContext *_localctx = _tracker.createInstance<ExpressionsContext>(_ctx, getState());
  enterRule(_localctx, 4, DXXParser::RuleExpressions);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(140);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<DXXParser::NewExprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(123);
      new_();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<DXXParser::DeleteExprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(124);
      delete_();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<DXXParser::VarDefineExprTagContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(125);
      varDefine();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<DXXParser::VarSetExprContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(126);
      varSet();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<DXXParser::WithExprContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(127);
      withStatement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<DXXParser::WhileLoopExprContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(128);
      whileLoop();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<DXXParser::DoWhileLoopExprContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(129);
      doWhileLoop();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<DXXParser::ForeachLoopExprContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(130);
      foreachLoop();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<DXXParser::GotoExprContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(131);
      goto_();
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<DXXParser::GotoLabelDefineExprContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(132);
      gotoLabelDefine();
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<DXXParser::TryExprContext>(_localctx);
      enterOuterAlt(_localctx, 11);
      setState(133);
      try_();
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<DXXParser::ThrowExprContext>(_localctx);
      enterOuterAlt(_localctx, 12);
      setState(134);
      throw_();
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<DXXParser::TypedefExprTagContext>(_localctx);
      enterOuterAlt(_localctx, 13);
      setState(135);
      typedef_();
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<DXXParser::ReturnExprContext>(_localctx);
      enterOuterAlt(_localctx, 14);
      setState(136);
      return_();
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<DXXParser::BreakExprContext>(_localctx);
      enterOuterAlt(_localctx, 15);
      setState(137);
      match(DXXParser::Break);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<DXXParser::ContinueExprContext>(_localctx);
      enterOuterAlt(_localctx, 16);
      setState(138);
      match(DXXParser::Continue);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<DXXParser::SemiExprContext>(_localctx);
      enterOuterAlt(_localctx, 17);
      setState(139);
      semi();
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

//----------------- ConstantContext ------------------------------------------------------------------

DXXParser::ConstantContext::ConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DXXParser::ConstantContext::getRuleIndex() const {
  return DXXParser::RuleConstant;
}

void DXXParser::ConstantContext::copyFrom(ConstantContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- StringExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::StringExprContext::StringData() {
  return getToken(DXXParser::StringData, 0);
}

DXXParser::StringExprContext::StringExprContext(ConstantContext *ctx) { copyFrom(ctx); }

void DXXParser::StringExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringExpr(this);
}
void DXXParser::StringExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringExpr(this);
}

std::any DXXParser::StringExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitStringExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntegerExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::IntegerExprContext::IntegerData() {
  return getToken(DXXParser::IntegerData, 0);
}

DXXParser::IntegerExprContext::IntegerExprContext(ConstantContext *ctx) { copyFrom(ctx); }

void DXXParser::IntegerExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntegerExpr(this);
}
void DXXParser::IntegerExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntegerExpr(this);
}

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

DXXParser::NullExprContext::NullExprContext(ConstantContext *ctx) { copyFrom(ctx); }

void DXXParser::NullExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNullExpr(this);
}
void DXXParser::NullExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNullExpr(this);
}

std::any DXXParser::NullExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNullExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BooleanExprContext ------------------------------------------------------------------

DXXParser::BooleanContext* DXXParser::BooleanExprContext::boolean() {
  return getRuleContext<DXXParser::BooleanContext>(0);
}

DXXParser::BooleanExprContext::BooleanExprContext(ConstantContext *ctx) { copyFrom(ctx); }

void DXXParser::BooleanExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanExpr(this);
}
void DXXParser::BooleanExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanExpr(this);
}

std::any DXXParser::BooleanExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitBooleanExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatingExprContext ------------------------------------------------------------------

tree::TerminalNode* DXXParser::FloatingExprContext::FloatingNumberData() {
  return getToken(DXXParser::FloatingNumberData, 0);
}

DXXParser::FloatingExprContext::FloatingExprContext(ConstantContext *ctx) { copyFrom(ctx); }

void DXXParser::FloatingExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatingExpr(this);
}
void DXXParser::FloatingExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatingExpr(this);
}

std::any DXXParser::FloatingExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFloatingExpr(this);
  else
    return visitor->visitChildren(this);
}
DXXParser::ConstantContext* DXXParser::constant() {
  ConstantContext *_localctx = _tracker.createInstance<ConstantContext>(_ctx, getState());
  enterRule(_localctx, 6, DXXParser::RuleConstant);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(147);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DXXParser::IntegerData: {
        _localctx = _tracker.createInstance<DXXParser::IntegerExprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(142);
        match(DXXParser::IntegerData);
        break;
      }

      case DXXParser::FloatingNumberData: {
        _localctx = _tracker.createInstance<DXXParser::FloatingExprContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(143);
        match(DXXParser::FloatingNumberData);
        break;
      }

      case DXXParser::StringData: {
        _localctx = _tracker.createInstance<DXXParser::StringExprContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(144);
        match(DXXParser::StringData);
        break;
      }

      case DXXParser::False:
      case DXXParser::True: {
        _localctx = _tracker.createInstance<DXXParser::BooleanExprContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(145);
        boolean();
        break;
      }

      case DXXParser::Null: {
        _localctx = _tracker.createInstance<DXXParser::NullExprContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(146);
        match(DXXParser::Null);
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

//----------------- DataContext ------------------------------------------------------------------

DXXParser::DataContext::DataContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DXXParser::DataContext::getRuleIndex() const {
  return DXXParser::RuleData;
}

void DXXParser::DataContext::copyFrom(DataContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OrorExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::OrorExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::OrorExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
}

tree::TerminalNode* DXXParser::OrorExprContext::OrOr() {
  return getToken(DXXParser::OrOr, 0);
}

DXXParser::OrorExprContext::OrorExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::OrorExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrorExpr(this);
}
void DXXParser::OrorExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrorExpr(this);
}

std::any DXXParser::OrorExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitOrorExpr(this);
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

DXXParser::DataContext* DXXParser::ParensContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}

DXXParser::ParensContext::ParensContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::ParensContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParens(this);
}
void DXXParser::ParensContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParens(this);
}

std::any DXXParser::ParensContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitParens(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IdExExprContext ------------------------------------------------------------------

DXXParser::IdExContext* DXXParser::IdExExprContext::idEx() {
  return getRuleContext<DXXParser::IdExContext>(0);
}

DXXParser::IdExExprContext::IdExExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::IdExExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdExExpr(this);
}
void DXXParser::IdExExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdExExpr(this);
}

std::any DXXParser::IdExExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitIdExExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeExprContext ------------------------------------------------------------------

DXXParser::TheTypeContext* DXXParser::TypeExprContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
}

DXXParser::TypeExprContext::TypeExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::TypeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeExpr(this);
}
void DXXParser::TypeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeExpr(this);
}

std::any DXXParser::TypeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTypeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotClassExprContext ------------------------------------------------------------------

DXXParser::DataContext* DXXParser::NotClassExprContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
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

DXXParser::NotClassExprContext::NotClassExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::NotClassExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNotClassExpr(this);
}
void DXXParser::NotClassExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNotClassExpr(this);
}

std::any DXXParser::NotClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNotClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegativeExprContext ------------------------------------------------------------------

DXXParser::NegativeContext* DXXParser::NegativeExprContext::negative() {
  return getRuleContext<DXXParser::NegativeContext>(0);
}

DXXParser::NegativeExprContext::NegativeExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::NegativeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegativeExpr(this);
}
void DXXParser::NegativeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegativeExpr(this);
}

std::any DXXParser::NegativeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNegativeExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeftOrRightShiftExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::LeftOrRightShiftExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::LeftOrRightShiftExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
}

tree::TerminalNode* DXXParser::LeftOrRightShiftExprContext::LeftShift() {
  return getToken(DXXParser::LeftShift, 0);
}

tree::TerminalNode* DXXParser::LeftOrRightShiftExprContext::RightShift() {
  return getToken(DXXParser::RightShift, 0);
}

DXXParser::LeftOrRightShiftExprContext::LeftOrRightShiftExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::LeftOrRightShiftExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLeftOrRightShiftExpr(this);
}
void DXXParser::LeftOrRightShiftExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLeftOrRightShiftExpr(this);
}

std::any DXXParser::LeftOrRightShiftExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitLeftOrRightShiftExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- OrExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::OrExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::OrExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
}

tree::TerminalNode* DXXParser::OrExprContext::Or() {
  return getToken(DXXParser::Or, 0);
}

DXXParser::OrExprContext::OrExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::OrExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOrExpr(this);
}
void DXXParser::OrExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOrExpr(this);
}

std::any DXXParser::OrExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitOrExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PlusClassExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::PlusClassExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::PlusClassExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
}

tree::TerminalNode* DXXParser::PlusClassExprContext::Plus() {
  return getToken(DXXParser::Plus, 0);
}

tree::TerminalNode* DXXParser::PlusClassExprContext::Minus() {
  return getToken(DXXParser::Minus, 0);
}

DXXParser::PlusClassExprContext::PlusClassExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::PlusClassExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlusClassExpr(this);
}
void DXXParser::PlusClassExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlusClassExpr(this);
}

std::any DXXParser::PlusClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitPlusClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LambdaFunctionExprContext ------------------------------------------------------------------

DXXParser::LambdaFunctionContext* DXXParser::LambdaFunctionExprContext::lambdaFunction() {
  return getRuleContext<DXXParser::LambdaFunctionContext>(0);
}

DXXParser::LambdaFunctionExprContext::LambdaFunctionExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::LambdaFunctionExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaFunctionExpr(this);
}
void DXXParser::LambdaFunctionExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaFunctionExpr(this);
}

std::any DXXParser::LambdaFunctionExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitLambdaFunctionExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndandExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::AndandExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::AndandExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
}

tree::TerminalNode* DXXParser::AndandExprContext::AndAnd() {
  return getToken(DXXParser::AndAnd, 0);
}

DXXParser::AndandExprContext::AndandExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::AndandExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndandExpr(this);
}
void DXXParser::AndandExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndandExpr(this);
}

std::any DXXParser::AndandExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitAndandExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EqualOrNotEqualExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::EqualOrNotEqualExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::EqualOrNotEqualExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
}

tree::TerminalNode* DXXParser::EqualOrNotEqualExprContext::Equal() {
  return getToken(DXXParser::Equal, 0);
}

tree::TerminalNode* DXXParser::EqualOrNotEqualExprContext::NotEqual() {
  return getToken(DXXParser::NotEqual, 0);
}

DXXParser::EqualOrNotEqualExprContext::EqualOrNotEqualExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::EqualOrNotEqualExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualOrNotEqualExpr(this);
}
void DXXParser::EqualOrNotEqualExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualOrNotEqualExpr(this);
}

std::any DXXParser::EqualOrNotEqualExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitEqualOrNotEqualExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CaretExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::CaretExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::CaretExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
}

tree::TerminalNode* DXXParser::CaretExprContext::Caret() {
  return getToken(DXXParser::Caret, 0);
}

DXXParser::CaretExprContext::CaretExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::CaretExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaretExpr(this);
}
void DXXParser::CaretExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaretExpr(this);
}

std::any DXXParser::CaretExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitCaretExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StarClassExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::StarClassExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::StarClassExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
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

DXXParser::StarClassExprContext::StarClassExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::StarClassExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStarClassExpr(this);
}
void DXXParser::StarClassExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStarClassExpr(this);
}

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

DXXParser::FunctionCallExprContext::FunctionCallExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::FunctionCallExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCallExpr(this);
}
void DXXParser::FunctionCallExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCallExpr(this);
}

std::any DXXParser::FunctionCallExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionCallExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LessClassExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::LessClassExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::LessClassExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
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

DXXParser::LessClassExprContext::LessClassExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::LessClassExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLessClassExpr(this);
}
void DXXParser::LessClassExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLessClassExpr(this);
}

std::any DXXParser::LessClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitLessClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstantExprContext ------------------------------------------------------------------

DXXParser::ConstantContext* DXXParser::ConstantExprContext::constant() {
  return getRuleContext<DXXParser::ConstantContext>(0);
}

DXXParser::ConstantExprContext::ConstantExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::ConstantExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstantExpr(this);
}
void DXXParser::ConstantExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstantExpr(this);
}

std::any DXXParser::ConstantExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitConstantExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AndExprContext ------------------------------------------------------------------

std::vector<DXXParser::DataContext *> DXXParser::AndExprContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::AndExprContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
}

tree::TerminalNode* DXXParser::AndExprContext::And() {
  return getToken(DXXParser::And, 0);
}

DXXParser::AndExprContext::AndExprContext(DataContext *ctx) { copyFrom(ctx); }

void DXXParser::AndExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAndExpr(this);
}
void DXXParser::AndExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAndExpr(this);
}

std::any DXXParser::AndExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitAndExpr(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::DataContext* DXXParser::data() {
   return data(0);
}

DXXParser::DataContext* DXXParser::data(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  DXXParser::DataContext *_localctx = _tracker.createInstance<DataContext>(_ctx, parentState);
  DXXParser::DataContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 8;
  enterRecursionRule(_localctx, 8, DXXParser::RuleData, precedence);

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
    setState(163);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ConstantExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(150);
      constant();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IdExExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(151);
      idEx();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(152);
      functionCall();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(153);
      match(DXXParser::LeftParen);
      setState(155);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4704363436141019396) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 69)) & 1939190317059) != 0)) {
        setState(154);
        data(0);
      }
      setState(157);
      match(DXXParser::RightParen);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NotClassExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(158);
      _la = _input->LA(1);
      if (!(((((_la - 69) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 69)) & 12582915) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(159);
      data(14);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NegativeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(160);
      negative();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<LambdaFunctionExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(161);
      lambdaFunction();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<TypeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(162);
      theType();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(197);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(195);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<AndandExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(165);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(166);
          match(DXXParser::AndAnd);
          setState(167);
          data(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<OrorExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(168);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(169);
          match(DXXParser::OrOr);
          setState(170);
          data(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<EqualOrNotEqualExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(171);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(172);
          _la = _input->LA(1);
          if (!(_la == DXXParser::Equal

          || _la == DXXParser::NotEqual)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(173);
          data(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<StarClassExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(174);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(175);
          _la = _input->LA(1);
          if (!(((((_la - 63) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 63)) & 7) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(176);
          data(11);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<PlusClassExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(177);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(178);
          _la = _input->LA(1);
          if (!(_la == DXXParser::Plus

          || _la == DXXParser::Minus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(179);
          data(10);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LeftOrRightShiftExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(180);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(181);
          _la = _input->LA(1);
          if (!(_la == DXXParser::LeftShift

          || _la == DXXParser::RightShift)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(182);
          data(9);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<LessClassExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(183);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(184);
          _la = _input->LA(1);
          if (!(((((_la - 73) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 73)) & 49155) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(185);
          data(8);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(186);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(187);
          match(DXXParser::And);
          setState(188);
          data(7);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<CaretExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(189);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(190);
          match(DXXParser::Caret);
          setState(191);
          data(6);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(192);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(193);
          match(DXXParser::Or);
          setState(194);
          data(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(199);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
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

void DXXParser::BooleanContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBoolean(this);
}

void DXXParser::BooleanContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBoolean(this);
}


std::any DXXParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::BooleanContext* DXXParser::boolean() {
  BooleanContext *_localctx = _tracker.createInstance<BooleanContext>(_ctx, getState());
  enterRule(_localctx, 10, DXXParser::RuleBoolean);
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
    setState(200);
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

DXXParser::DataContext* DXXParser::NegativeContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}


size_t DXXParser::NegativeContext::getRuleIndex() const {
  return DXXParser::RuleNegative;
}

void DXXParser::NegativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNegative(this);
}

void DXXParser::NegativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNegative(this);
}


std::any DXXParser::NegativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNegative(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::NegativeContext* DXXParser::negative() {
  NegativeContext *_localctx = _tracker.createInstance<NegativeContext>(_ctx, getState());
  enterRule(_localctx, 12, DXXParser::RuleNegative);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    match(DXXParser::Minus);
    setState(203);
    data(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SemiContext ------------------------------------------------------------------

DXXParser::SemiContext::SemiContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::SemiContext::Semi() {
  return getToken(DXXParser::Semi, 0);
}


size_t DXXParser::SemiContext::getRuleIndex() const {
  return DXXParser::RuleSemi;
}

void DXXParser::SemiContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSemi(this);
}

void DXXParser::SemiContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSemi(this);
}


std::any DXXParser::SemiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitSemi(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::SemiContext* DXXParser::semi() {
  SemiContext *_localctx = _tracker.createInstance<SemiContext>(_ctx, getState());
  enterRule(_localctx, 14, DXXParser::RuleSemi);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(DXXParser::Semi);
   
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

void DXXParser::ImportLibContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportLib(this);
}

void DXXParser::ImportLibContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportLib(this);
}


std::any DXXParser::ImportLibContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitImportLib(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ImportLibContext* DXXParser::importLib() {
  ImportLibContext *_localctx = _tracker.createInstance<ImportLibContext>(_ctx, getState());
  enterRule(_localctx, 16, DXXParser::RuleImportLib);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    match(DXXParser::Import);
    setState(208);
    idEx();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewContext ------------------------------------------------------------------

DXXParser::NewContext::NewContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::NewContext::New() {
  return getToken(DXXParser::New, 0);
}

DXXParser::TheTypeContext* DXXParser::NewContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
}


size_t DXXParser::NewContext::getRuleIndex() const {
  return DXXParser::RuleNew;
}

void DXXParser::NewContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNew(this);
}

void DXXParser::NewContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNew(this);
}


std::any DXXParser::NewContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNew(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::NewContext* DXXParser::new_() {
  NewContext *_localctx = _tracker.createInstance<NewContext>(_ctx, getState());
  enterRule(_localctx, 18, DXXParser::RuleNew);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(DXXParser::New);
    setState(211);
    theType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeleteContext ------------------------------------------------------------------

DXXParser::DeleteContext::DeleteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::DeleteContext::Delete() {
  return getToken(DXXParser::Delete, 0);
}

DXXParser::DataContext* DXXParser::DeleteContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}


size_t DXXParser::DeleteContext::getRuleIndex() const {
  return DXXParser::RuleDelete;
}

void DXXParser::DeleteContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDelete(this);
}

void DXXParser::DeleteContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDelete(this);
}


std::any DXXParser::DeleteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitDelete(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::DeleteContext* DXXParser::delete_() {
  DeleteContext *_localctx = _tracker.createInstance<DeleteContext>(_ctx, getState());
  enterRule(_localctx, 20, DXXParser::RuleDelete);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    match(DXXParser::Delete);
    setState(214);
    data(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypedefContext ------------------------------------------------------------------

DXXParser::TypedefContext::TypedefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::TypedefContext::Using() {
  return getToken(DXXParser::Using, 0);
}

tree::TerminalNode* DXXParser::TypedefContext::ID() {
  return getToken(DXXParser::ID, 0);
}

tree::TerminalNode* DXXParser::TypedefContext::Assign() {
  return getToken(DXXParser::Assign, 0);
}

DXXParser::TheTypeContext* DXXParser::TypedefContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
}


size_t DXXParser::TypedefContext::getRuleIndex() const {
  return DXXParser::RuleTypedef;
}

void DXXParser::TypedefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypedef(this);
}

void DXXParser::TypedefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypedef(this);
}


std::any DXXParser::TypedefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTypedef(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TypedefContext* DXXParser::typedef_() {
  TypedefContext *_localctx = _tracker.createInstance<TypedefContext>(_ctx, getState());
  enterRule(_localctx, 22, DXXParser::RuleTypedef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(216);
    match(DXXParser::Using);
    setState(217);
    match(DXXParser::ID);
    setState(218);
    match(DXXParser::Assign);
    setState(219);
    theType();
   
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

void DXXParser::FunctionDefineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefine(this);
}

void DXXParser::FunctionDefineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefine(this);
}


std::any DXXParser::FunctionDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDefine(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::FunctionDefineContext* DXXParser::functionDefine() {
  FunctionDefineContext *_localctx = _tracker.createInstance<FunctionDefineContext>(_ctx, getState());
  enterRule(_localctx, 24, DXXParser::RuleFunctionDefine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
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

void DXXParser::FunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction(this);
}

void DXXParser::FunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction(this);
}


std::any DXXParser::FunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunction(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::FunctionContext* DXXParser::function() {
  FunctionContext *_localctx = _tracker.createInstance<FunctionContext>(_ctx, getState());
  enterRule(_localctx, 26, DXXParser::RuleFunction);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(223);
    functionHead();
    setState(224);
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

DXXParser::DataContext* DXXParser::ReturnContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}


size_t DXXParser::ReturnContext::getRuleIndex() const {
  return DXXParser::RuleReturn;
}

void DXXParser::ReturnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturn(this);
}

void DXXParser::ReturnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturn(this);
}


std::any DXXParser::ReturnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitReturn(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ReturnContext* DXXParser::return_() {
  ReturnContext *_localctx = _tracker.createInstance<ReturnContext>(_ctx, getState());
  enterRule(_localctx, 28, DXXParser::RuleReturn);

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
    match(DXXParser::Return);
    setState(227);
    data(0);
   
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

tree::TerminalNode* DXXParser::LambdaFunctionContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

tree::TerminalNode* DXXParser::LambdaFunctionContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

DXXParser::BlockContext* DXXParser::LambdaFunctionContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}

DXXParser::ParamListContext* DXXParser::LambdaFunctionContext::paramList() {
  return getRuleContext<DXXParser::ParamListContext>(0);
}


size_t DXXParser::LambdaFunctionContext::getRuleIndex() const {
  return DXXParser::RuleLambdaFunction;
}

void DXXParser::LambdaFunctionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLambdaFunction(this);
}

void DXXParser::LambdaFunctionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLambdaFunction(this);
}


std::any DXXParser::LambdaFunctionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitLambdaFunction(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::LambdaFunctionContext* DXXParser::lambdaFunction() {
  LambdaFunctionContext *_localctx = _tracker.createInstance<LambdaFunctionContext>(_ctx, getState());
  enterRule(_localctx, 30, DXXParser::RuleLambdaFunction);
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
    setState(229);
    match(DXXParser::LeftBracket);
    setState(230);
    match(DXXParser::RightBracket);
    setState(231);
    match(DXXParser::LeftParen);
    setState(233);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055348269316) != 0) || ((((_la - 100) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 100)) & 7) != 0)) {
      setState(232);
      paramList();
    }
    setState(235);
    match(DXXParser::RightParen);
    setState(236);
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

std::vector<DXXParser::InfoContext *> DXXParser::FunctionHeadContext::info() {
  return getRuleContexts<DXXParser::InfoContext>();
}

DXXParser::InfoContext* DXXParser::FunctionHeadContext::info(size_t i) {
  return getRuleContext<DXXParser::InfoContext>(i);
}

DXXParser::ParamListContext* DXXParser::FunctionHeadContext::paramList() {
  return getRuleContext<DXXParser::ParamListContext>(0);
}

DXXParser::ThrowtableContext* DXXParser::FunctionHeadContext::throwtable() {
  return getRuleContext<DXXParser::ThrowtableContext>(0);
}


size_t DXXParser::FunctionHeadContext::getRuleIndex() const {
  return DXXParser::RuleFunctionHead;
}

void DXXParser::FunctionHeadContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionHead(this);
}

void DXXParser::FunctionHeadContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionHead(this);
}


std::any DXXParser::FunctionHeadContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionHead(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::FunctionHeadContext* DXXParser::functionHead() {
  FunctionHeadContext *_localctx = _tracker.createInstance<FunctionHeadContext>(_ctx, getState());
  enterRule(_localctx, 32, DXXParser::RuleFunctionHead);
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
    setState(241);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 678881722624) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(238);
      info();
      setState(243);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(244);
    match(DXXParser::ID);
    setState(245);
    match(DXXParser::LeftParen);
    setState(247);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055348269316) != 0) || ((((_la - 100) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 100)) & 7) != 0)) {
      setState(246);
      paramList();
    }
    setState(249);
    match(DXXParser::RightParen);
    setState(250);
    match(DXXParser::Arrow);
    setState(251);
    theType();
    setState(253);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Throw) {
      setState(252);
      throwtable();
    }
   
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

DXXParser::CallParamListContext* DXXParser::FunctionCallContext::callParamList() {
  return getRuleContext<DXXParser::CallParamListContext>(0);
}


size_t DXXParser::FunctionCallContext::getRuleIndex() const {
  return DXXParser::RuleFunctionCall;
}

void DXXParser::FunctionCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionCall(this);
}

void DXXParser::FunctionCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionCall(this);
}


std::any DXXParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::FunctionCallContext* DXXParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 34, DXXParser::RuleFunctionCall);
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
    setState(255);
    idEx();
    setState(256);
    match(DXXParser::LeftParen);
    setState(258);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4704363436141019396) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & 1939190317059) != 0)) {
      setState(257);
      callParamList();
    }
    setState(260);
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

void DXXParser::ParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamList(this);
}

void DXXParser::ParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamList(this);
}


std::any DXXParser::ParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitParamList(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ParamListContext* DXXParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 36, DXXParser::RuleParamList);
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
    setState(262);
    varDefine();
    setState(267);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(263);
        match(DXXParser::Comma);
        setState(264);
        varDefine(); 
      }
      setState(269);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
    setState(272);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Comma) {
      setState(270);
      match(DXXParser::Comma);
      setState(271);
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

std::vector<DXXParser::DataContext *> DXXParser::CallParamListContext::data() {
  return getRuleContexts<DXXParser::DataContext>();
}

DXXParser::DataContext* DXXParser::CallParamListContext::data(size_t i) {
  return getRuleContext<DXXParser::DataContext>(i);
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

void DXXParser::CallParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCallParamList(this);
}

void DXXParser::CallParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCallParamList(this);
}


std::any DXXParser::CallParamListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitCallParamList(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::CallParamListContext* DXXParser::callParamList() {
  CallParamListContext *_localctx = _tracker.createInstance<CallParamListContext>(_ctx, getState());
  enterRule(_localctx, 38, DXXParser::RuleCallParamList);
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
    setState(274);
    data(0);
    setState(279);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DXXParser::Comma) {
      setState(275);
      match(DXXParser::Comma);
      setState(276);
      data(0);
      setState(281);
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

//----------------- ThrowtableContext ------------------------------------------------------------------

DXXParser::ThrowtableContext::ThrowtableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::ThrowtableContext::Throw() {
  return getToken(DXXParser::Throw, 0);
}

std::vector<DXXParser::IdExContext *> DXXParser::ThrowtableContext::idEx() {
  return getRuleContexts<DXXParser::IdExContext>();
}

DXXParser::IdExContext* DXXParser::ThrowtableContext::idEx(size_t i) {
  return getRuleContext<DXXParser::IdExContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::ThrowtableContext::Comma() {
  return getTokens(DXXParser::Comma);
}

tree::TerminalNode* DXXParser::ThrowtableContext::Comma(size_t i) {
  return getToken(DXXParser::Comma, i);
}


size_t DXXParser::ThrowtableContext::getRuleIndex() const {
  return DXXParser::RuleThrowtable;
}

void DXXParser::ThrowtableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThrowtable(this);
}

void DXXParser::ThrowtableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThrowtable(this);
}


std::any DXXParser::ThrowtableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitThrowtable(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ThrowtableContext* DXXParser::throwtable() {
  ThrowtableContext *_localctx = _tracker.createInstance<ThrowtableContext>(_ctx, getState());
  enterRule(_localctx, 40, DXXParser::RuleThrowtable);

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
    setState(282);
    match(DXXParser::Throw);
    setState(288);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(283);
        idEx();
        setState(284);
        match(DXXParser::Comma); 
      }
      setState(290);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(292);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(291);
      idEx();
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

//----------------- VarDefineContext ------------------------------------------------------------------

DXXParser::VarDefineContext::VarDefineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::TheTypeContext* DXXParser::VarDefineContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
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

DXXParser::AssignsContext* DXXParser::VarDefineContext::assigns() {
  return getRuleContext<DXXParser::AssignsContext>(0);
}

DXXParser::DataContext* DXXParser::VarDefineContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}


size_t DXXParser::VarDefineContext::getRuleIndex() const {
  return DXXParser::RuleVarDefine;
}

void DXXParser::VarDefineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefine(this);
}

void DXXParser::VarDefineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefine(this);
}


std::any DXXParser::VarDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVarDefine(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::VarDefineContext* DXXParser::varDefine() {
  VarDefineContext *_localctx = _tracker.createInstance<VarDefineContext>(_ctx, getState());
  enterRule(_localctx, 42, DXXParser::RuleVarDefine);
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
    setState(294);
    theType();
    setState(298);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 678881722624) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(295);
      info();
      setState(300);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(301);
    match(DXXParser::ID);
    setState(305);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 16371) != 0)) {
      setState(302);
      assigns();
      setState(303);
      data(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefineNoSetContext ------------------------------------------------------------------

DXXParser::VarDefineNoSetContext::VarDefineNoSetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::TheTypeContext* DXXParser::VarDefineNoSetContext::theType() {
  return getRuleContext<DXXParser::TheTypeContext>(0);
}

tree::TerminalNode* DXXParser::VarDefineNoSetContext::ID() {
  return getToken(DXXParser::ID, 0);
}

std::vector<DXXParser::InfoContext *> DXXParser::VarDefineNoSetContext::info() {
  return getRuleContexts<DXXParser::InfoContext>();
}

DXXParser::InfoContext* DXXParser::VarDefineNoSetContext::info(size_t i) {
  return getRuleContext<DXXParser::InfoContext>(i);
}


size_t DXXParser::VarDefineNoSetContext::getRuleIndex() const {
  return DXXParser::RuleVarDefineNoSet;
}

void DXXParser::VarDefineNoSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDefineNoSet(this);
}

void DXXParser::VarDefineNoSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDefineNoSet(this);
}


std::any DXXParser::VarDefineNoSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVarDefineNoSet(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::VarDefineNoSetContext* DXXParser::varDefineNoSet() {
  VarDefineNoSetContext *_localctx = _tracker.createInstance<VarDefineNoSetContext>(_ctx, getState());
  enterRule(_localctx, 44, DXXParser::RuleVarDefineNoSet);
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
    setState(307);
    theType();
    setState(311);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 678881722624) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(308);
      info();
      setState(313);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(314);
    match(DXXParser::ID);
   
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

DXXParser::DataContext* DXXParser::VarSetContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}


size_t DXXParser::VarSetContext::getRuleIndex() const {
  return DXXParser::RuleVarSet;
}

void DXXParser::VarSetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarSet(this);
}

void DXXParser::VarSetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarSet(this);
}


std::any DXXParser::VarSetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitVarSet(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::VarSetContext* DXXParser::varSet() {
  VarSetContext *_localctx = _tracker.createInstance<VarSetContext>(_ctx, getState());
  enterRule(_localctx, 46, DXXParser::RuleVarSet);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    idEx();
    setState(317);
    assigns();
    setState(318);
    data(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithStatementContext ------------------------------------------------------------------

DXXParser::WithStatementContext::WithStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::WithIfContext* DXXParser::WithStatementContext::withIf() {
  return getRuleContext<DXXParser::WithIfContext>(0);
}

DXXParser::WithIfExtendsContext* DXXParser::WithStatementContext::withIfExtends() {
  return getRuleContext<DXXParser::WithIfExtendsContext>(0);
}

DXXParser::WithSwitchStatementContext* DXXParser::WithStatementContext::withSwitchStatement() {
  return getRuleContext<DXXParser::WithSwitchStatementContext>(0);
}


size_t DXXParser::WithStatementContext::getRuleIndex() const {
  return DXXParser::RuleWithStatement;
}

void DXXParser::WithStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithStatement(this);
}

void DXXParser::WithStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithStatement(this);
}


std::any DXXParser::WithStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWithStatement(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::WithStatementContext* DXXParser::withStatement() {
  WithStatementContext *_localctx = _tracker.createInstance<WithStatementContext>(_ctx, getState());
  enterRule(_localctx, 48, DXXParser::RuleWithStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(323);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(320);
      withIf();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(321);
      withIfExtends();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(322);
      withSwitchStatement();
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

//----------------- WithIfContext ------------------------------------------------------------------

DXXParser::WithIfContext::WithIfContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::WithIfContext::With() {
  return getToken(DXXParser::With, 0);
}

tree::TerminalNode* DXXParser::WithIfContext::If() {
  return getToken(DXXParser::If, 0);
}

tree::TerminalNode* DXXParser::WithIfContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

DXXParser::DataContext* DXXParser::WithIfContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}

tree::TerminalNode* DXXParser::WithIfContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

DXXParser::BlockContext* DXXParser::WithIfContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::WithIfContext::getRuleIndex() const {
  return DXXParser::RuleWithIf;
}

void DXXParser::WithIfContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithIf(this);
}

void DXXParser::WithIfContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithIf(this);
}


std::any DXXParser::WithIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWithIf(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::WithIfContext* DXXParser::withIf() {
  WithIfContext *_localctx = _tracker.createInstance<WithIfContext>(_ctx, getState());
  enterRule(_localctx, 50, DXXParser::RuleWithIf);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(325);
    match(DXXParser::With);
    setState(326);
    match(DXXParser::If);
    setState(327);
    match(DXXParser::LeftParen);
    setState(328);
    data(0);
    setState(329);
    match(DXXParser::RightParen);
    setState(330);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithIfExtendsContext ------------------------------------------------------------------

DXXParser::WithIfExtendsContext::WithIfExtendsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::WithIfExtendsContext::With() {
  return getToken(DXXParser::With, 0);
}

tree::TerminalNode* DXXParser::WithIfExtendsContext::If() {
  return getToken(DXXParser::If, 0);
}

tree::TerminalNode* DXXParser::WithIfExtendsContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::WithIfExtendsContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}

std::vector<DXXParser::WithIfExtendsSubContext *> DXXParser::WithIfExtendsContext::withIfExtendsSub() {
  return getRuleContexts<DXXParser::WithIfExtendsSubContext>();
}

DXXParser::WithIfExtendsSubContext* DXXParser::WithIfExtendsContext::withIfExtendsSub(size_t i) {
  return getRuleContext<DXXParser::WithIfExtendsSubContext>(i);
}


size_t DXXParser::WithIfExtendsContext::getRuleIndex() const {
  return DXXParser::RuleWithIfExtends;
}

void DXXParser::WithIfExtendsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithIfExtends(this);
}

void DXXParser::WithIfExtendsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithIfExtends(this);
}


std::any DXXParser::WithIfExtendsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWithIfExtends(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::WithIfExtendsContext* DXXParser::withIfExtends() {
  WithIfExtendsContext *_localctx = _tracker.createInstance<WithIfExtendsContext>(_ctx, getState());
  enterRule(_localctx, 52, DXXParser::RuleWithIfExtends);
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
    setState(332);
    match(DXXParser::With);
    setState(333);
    match(DXXParser::If);
    setState(334);
    match(DXXParser::LeftBrace);
    setState(338);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4704363436141019396) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & 1939190317059) != 0)) {
      setState(335);
      withIfExtendsSub();
      setState(340);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(341);
    match(DXXParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithIfExtendsSubContext ------------------------------------------------------------------

DXXParser::WithIfExtendsSubContext::WithIfExtendsSubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::DataContext* DXXParser::WithIfExtendsSubContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}

tree::TerminalNode* DXXParser::WithIfExtendsSubContext::Arrow() {
  return getToken(DXXParser::Arrow, 0);
}

DXXParser::BlockContext* DXXParser::WithIfExtendsSubContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::WithIfExtendsSubContext::getRuleIndex() const {
  return DXXParser::RuleWithIfExtendsSub;
}

void DXXParser::WithIfExtendsSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithIfExtendsSub(this);
}

void DXXParser::WithIfExtendsSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithIfExtendsSub(this);
}


std::any DXXParser::WithIfExtendsSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWithIfExtendsSub(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::WithIfExtendsSubContext* DXXParser::withIfExtendsSub() {
  WithIfExtendsSubContext *_localctx = _tracker.createInstance<WithIfExtendsSubContext>(_ctx, getState());
  enterRule(_localctx, 54, DXXParser::RuleWithIfExtendsSub);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(343);
    data(0);
    setState(344);
    match(DXXParser::Arrow);
    setState(345);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithSwitchStatementContext ------------------------------------------------------------------

DXXParser::WithSwitchStatementContext::WithSwitchStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::WithSwitchStatementContext::With() {
  return getToken(DXXParser::With, 0);
}

tree::TerminalNode* DXXParser::WithSwitchStatementContext::LeftParen() {
  return getToken(DXXParser::LeftParen, 0);
}

DXXParser::DataContext* DXXParser::WithSwitchStatementContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}

tree::TerminalNode* DXXParser::WithSwitchStatementContext::RightParen() {
  return getToken(DXXParser::RightParen, 0);
}

tree::TerminalNode* DXXParser::WithSwitchStatementContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::WithSwitchStatementContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}

std::vector<DXXParser::CaseStatementContext *> DXXParser::WithSwitchStatementContext::caseStatement() {
  return getRuleContexts<DXXParser::CaseStatementContext>();
}

DXXParser::CaseStatementContext* DXXParser::WithSwitchStatementContext::caseStatement(size_t i) {
  return getRuleContext<DXXParser::CaseStatementContext>(i);
}

DXXParser::DefaultStatementContext* DXXParser::WithSwitchStatementContext::defaultStatement() {
  return getRuleContext<DXXParser::DefaultStatementContext>(0);
}


size_t DXXParser::WithSwitchStatementContext::getRuleIndex() const {
  return DXXParser::RuleWithSwitchStatement;
}

void DXXParser::WithSwitchStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithSwitchStatement(this);
}

void DXXParser::WithSwitchStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithSwitchStatement(this);
}


std::any DXXParser::WithSwitchStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWithSwitchStatement(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::WithSwitchStatementContext* DXXParser::withSwitchStatement() {
  WithSwitchStatementContext *_localctx = _tracker.createInstance<WithSwitchStatementContext>(_ctx, getState());
  enterRule(_localctx, 56, DXXParser::RuleWithSwitchStatement);
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
    setState(347);
    match(DXXParser::With);
    setState(348);
    match(DXXParser::LeftParen);
    setState(349);
    data(0);
    setState(350);
    match(DXXParser::RightParen);
    setState(351);
    match(DXXParser::LeftBrace);
    setState(355);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 70369817952256) != 0) || ((((_la - 107) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 107)) & 7) != 0)) {
      setState(352);
      caseStatement();
      setState(357);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(359);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Default) {
      setState(358);
      defaultStatement();
    }
    setState(361);
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

DXXParser::ConstantContext* DXXParser::CaseStatementContext::constant() {
  return getRuleContext<DXXParser::ConstantContext>(0);
}

tree::TerminalNode* DXXParser::CaseStatementContext::Arrow() {
  return getToken(DXXParser::Arrow, 0);
}

DXXParser::BlockContext* DXXParser::CaseStatementContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::CaseStatementContext::getRuleIndex() const {
  return DXXParser::RuleCaseStatement;
}

void DXXParser::CaseStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCaseStatement(this);
}

void DXXParser::CaseStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCaseStatement(this);
}


std::any DXXParser::CaseStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitCaseStatement(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::CaseStatementContext* DXXParser::caseStatement() {
  CaseStatementContext *_localctx = _tracker.createInstance<CaseStatementContext>(_ctx, getState());
  enterRule(_localctx, 58, DXXParser::RuleCaseStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    constant();
    setState(364);
    match(DXXParser::Arrow);
    setState(365);
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

tree::TerminalNode* DXXParser::DefaultStatementContext::Arrow() {
  return getToken(DXXParser::Arrow, 0);
}

DXXParser::BlockContext* DXXParser::DefaultStatementContext::block() {
  return getRuleContext<DXXParser::BlockContext>(0);
}


size_t DXXParser::DefaultStatementContext::getRuleIndex() const {
  return DXXParser::RuleDefaultStatement;
}

void DXXParser::DefaultStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefaultStatement(this);
}

void DXXParser::DefaultStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefaultStatement(this);
}


std::any DXXParser::DefaultStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitDefaultStatement(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::DefaultStatementContext* DXXParser::defaultStatement() {
  DefaultStatementContext *_localctx = _tracker.createInstance<DefaultStatementContext>(_ctx, getState());
  enterRule(_localctx, 60, DXXParser::RuleDefaultStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    match(DXXParser::Default);
    setState(368);
    match(DXXParser::Arrow);
    setState(369);
    block();
   
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

void DXXParser::WhileLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhileLoop(this);
}

void DXXParser::WhileLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhileLoop(this);
}


std::any DXXParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::WhileLoopContext* DXXParser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 62, DXXParser::RuleWhileLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    match(DXXParser::While);
    setState(372);
    match(DXXParser::LeftParen);
    setState(373);
    expressions();
    setState(374);
    match(DXXParser::RightParen);
    setState(376);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      setState(375);
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

void DXXParser::DoWhileLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDoWhileLoop(this);
}

void DXXParser::DoWhileLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDoWhileLoop(this);
}


std::any DXXParser::DoWhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitDoWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::DoWhileLoopContext* DXXParser::doWhileLoop() {
  DoWhileLoopContext *_localctx = _tracker.createInstance<DoWhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 64, DXXParser::RuleDoWhileLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    whileLoop();
    setState(379);
    match(DXXParser::Do);
    setState(380);
    match(DXXParser::LeftParen);
    setState(381);
    expressions();
    setState(382);
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

void DXXParser::ForeachLoopContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeachLoop(this);
}

void DXXParser::ForeachLoopContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeachLoop(this);
}


std::any DXXParser::ForeachLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitForeachLoop(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ForeachLoopContext* DXXParser::foreachLoop() {
  ForeachLoopContext *_localctx = _tracker.createInstance<ForeachLoopContext>(_ctx, getState());
  enterRule(_localctx, 66, DXXParser::RuleForeachLoop);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    match(DXXParser::Foreach);
    setState(385);
    match(DXXParser::LeftParen);
    setState(388);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(386);
      varDefine();
      break;
    }

    case 2: {
      setState(387);
      idEx();
      break;
    }

    default:
      break;
    }
    setState(390);
    match(DXXParser::Colon);
    setState(391);
    expressions();
    setState(392);
    match(DXXParser::RightParen);
    setState(394);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      setState(393);
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

void DXXParser::GotoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoto(this);
}

void DXXParser::GotoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoto(this);
}


std::any DXXParser::GotoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitGoto(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::GotoContext* DXXParser::goto_() {
  GotoContext *_localctx = _tracker.createInstance<GotoContext>(_ctx, getState());
  enterRule(_localctx, 68, DXXParser::RuleGoto);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(396);
    match(DXXParser::Goto);
    setState(397);
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

void DXXParser::GotoLabelDefineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGotoLabelDefine(this);
}

void DXXParser::GotoLabelDefineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGotoLabelDefine(this);
}


std::any DXXParser::GotoLabelDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitGotoLabelDefine(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::GotoLabelDefineContext* DXXParser::gotoLabelDefine() {
  GotoLabelDefineContext *_localctx = _tracker.createInstance<GotoLabelDefineContext>(_ctx, getState());
  enterRule(_localctx, 70, DXXParser::RuleGotoLabelDefine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    match(DXXParser::ID);
    setState(400);
    match(DXXParser::Colon);
    setState(401);
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

std::vector<DXXParser::EnumSubContext *> DXXParser::EnumContext::enumSub() {
  return getRuleContexts<DXXParser::EnumSubContext>();
}

DXXParser::EnumSubContext* DXXParser::EnumContext::enumSub(size_t i) {
  return getRuleContext<DXXParser::EnumSubContext>(i);
}

tree::TerminalNode* DXXParser::EnumContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::EnumContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}

std::vector<tree::TerminalNode *> DXXParser::EnumContext::Comma() {
  return getTokens(DXXParser::Comma);
}

tree::TerminalNode* DXXParser::EnumContext::Comma(size_t i) {
  return getToken(DXXParser::Comma, i);
}


size_t DXXParser::EnumContext::getRuleIndex() const {
  return DXXParser::RuleEnum;
}

void DXXParser::EnumContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnum(this);
}

void DXXParser::EnumContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnum(this);
}


std::any DXXParser::EnumContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitEnum(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::EnumContext* DXXParser::enum_() {
  EnumContext *_localctx = _tracker.createInstance<EnumContext>(_ctx, getState());
  enterRule(_localctx, 72, DXXParser::RuleEnum);
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
    setState(403);
    match(DXXParser::Enum);
    setState(404);
    enumSub();
    setState(405);
    match(DXXParser::LeftBrace);
    setState(414);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::ID) {
      setState(406);
      enumSub();
      setState(411);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DXXParser::Comma) {
        setState(407);
        match(DXXParser::Comma);
        setState(408);
        enumSub();
        setState(413);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(416);
    match(DXXParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EnumSubContext ------------------------------------------------------------------

DXXParser::EnumSubContext::EnumSubContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::EnumSubContext::ID() {
  return getToken(DXXParser::ID, 0);
}

tree::TerminalNode* DXXParser::EnumSubContext::Assign() {
  return getToken(DXXParser::Assign, 0);
}

DXXParser::DataContext* DXXParser::EnumSubContext::data() {
  return getRuleContext<DXXParser::DataContext>(0);
}

DXXParser::ExpressionsContext* DXXParser::EnumSubContext::expressions() {
  return getRuleContext<DXXParser::ExpressionsContext>(0);
}


size_t DXXParser::EnumSubContext::getRuleIndex() const {
  return DXXParser::RuleEnumSub;
}

void DXXParser::EnumSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEnumSub(this);
}

void DXXParser::EnumSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEnumSub(this);
}


std::any DXXParser::EnumSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitEnumSub(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::EnumSubContext* DXXParser::enumSub() {
  EnumSubContext *_localctx = _tracker.createInstance<EnumSubContext>(_ctx, getState());
  enterRule(_localctx, 74, DXXParser::RuleEnumSub);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(418);
    match(DXXParser::ID);
    setState(419);
    match(DXXParser::Assign);
    setState(422);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      setState(420);
      data(0);
      break;
    }

    case 2: {
      setState(421);
      expressions();
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

//----------------- ClassContext ------------------------------------------------------------------

DXXParser::ClassContext::ClassContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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

std::vector<tree::TerminalNode *> DXXParser::ClassContext::Comma() {
  return getTokens(DXXParser::Comma);
}

tree::TerminalNode* DXXParser::ClassContext::Comma(size_t i) {
  return getToken(DXXParser::Comma, i);
}


size_t DXXParser::ClassContext::getRuleIndex() const {
  return DXXParser::RuleClass;
}

void DXXParser::ClassContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClass(this);
}

void DXXParser::ClassContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClass(this);
}


std::any DXXParser::ClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitClass(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ClassContext* DXXParser::class_() {
  ClassContext *_localctx = _tracker.createInstance<ClassContext>(_ctx, getState());
  enterRule(_localctx, 76, DXXParser::RuleClass);
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
    match(DXXParser::Class);
    setState(425);
    match(DXXParser::ID);
    setState(433);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Extends) {
      setState(426);
      match(DXXParser::Extends);
      setState(431);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DXXParser::ID) {
        setState(427);
        idEx();

        setState(428);
        match(DXXParser::Comma);
        setState(429);
        idEx();
      }
    }
    setState(442);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Implements) {
      setState(435);
      match(DXXParser::Implements);
      setState(440);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DXXParser::ID) {
        setState(436);
        idEx();

        setState(437);
        match(DXXParser::Comma);
        setState(438);
        idEx();
      }
    }
    setState(444);
    match(DXXParser::LeftBrace);
    setState(448);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055415378308) != 0) || ((((_la - 95) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 95)) & 225) != 0)) {
      setState(445);
      classMethods();
      setState(450);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(451);
    match(DXXParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceContext ------------------------------------------------------------------

DXXParser::InterfaceContext::InterfaceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::InterfaceContext::Interface() {
  return getToken(DXXParser::Interface, 0);
}

tree::TerminalNode* DXXParser::InterfaceContext::ID() {
  return getToken(DXXParser::ID, 0);
}

tree::TerminalNode* DXXParser::InterfaceContext::LeftBrace() {
  return getToken(DXXParser::LeftBrace, 0);
}

tree::TerminalNode* DXXParser::InterfaceContext::RightBrace() {
  return getToken(DXXParser::RightBrace, 0);
}

tree::TerminalNode* DXXParser::InterfaceContext::Implements() {
  return getToken(DXXParser::Implements, 0);
}

std::vector<DXXParser::InterfaceMethodsContext *> DXXParser::InterfaceContext::interfaceMethods() {
  return getRuleContexts<DXXParser::InterfaceMethodsContext>();
}

DXXParser::InterfaceMethodsContext* DXXParser::InterfaceContext::interfaceMethods(size_t i) {
  return getRuleContext<DXXParser::InterfaceMethodsContext>(i);
}

std::vector<DXXParser::IdExContext *> DXXParser::InterfaceContext::idEx() {
  return getRuleContexts<DXXParser::IdExContext>();
}

DXXParser::IdExContext* DXXParser::InterfaceContext::idEx(size_t i) {
  return getRuleContext<DXXParser::IdExContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::InterfaceContext::Comma() {
  return getTokens(DXXParser::Comma);
}

tree::TerminalNode* DXXParser::InterfaceContext::Comma(size_t i) {
  return getToken(DXXParser::Comma, i);
}


size_t DXXParser::InterfaceContext::getRuleIndex() const {
  return DXXParser::RuleInterface;
}

void DXXParser::InterfaceContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterface(this);
}

void DXXParser::InterfaceContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterface(this);
}


std::any DXXParser::InterfaceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitInterface(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::InterfaceContext* DXXParser::interface() {
  InterfaceContext *_localctx = _tracker.createInstance<InterfaceContext>(_ctx, getState());
  enterRule(_localctx, 78, DXXParser::RuleInterface);
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
    setState(453);
    match(DXXParser::Interface);
    setState(454);
    match(DXXParser::ID);
    setState(467);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Implements) {
      setState(455);
      match(DXXParser::Implements);
      setState(461);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(456);
          idEx();
          setState(457);
          match(DXXParser::Comma); 
        }
        setState(463);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
      }
      setState(465);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DXXParser::ID) {
        setState(464);
        idEx();
      }
    }
    setState(469);
    match(DXXParser::LeftBrace);
    setState(473);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055415378180) != 0) || ((((_la - 95) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 95)) & 225) != 0)) {
      setState(470);
      interfaceMethods();
      setState(475);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(476);
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

DXXParser::ClassContext* DXXParser::ClassMethodsContext::class_() {
  return getRuleContext<DXXParser::ClassContext>(0);
}

DXXParser::InterfaceContext* DXXParser::ClassMethodsContext::interface() {
  return getRuleContext<DXXParser::InterfaceContext>(0);
}

DXXParser::FunctionContext* DXXParser::ClassMethodsContext::function() {
  return getRuleContext<DXXParser::FunctionContext>(0);
}

DXXParser::FunctionDefineContext* DXXParser::ClassMethodsContext::functionDefine() {
  return getRuleContext<DXXParser::FunctionDefineContext>(0);
}

DXXParser::VarDefineContext* DXXParser::ClassMethodsContext::varDefine() {
  return getRuleContext<DXXParser::VarDefineContext>(0);
}

DXXParser::SemiContext* DXXParser::ClassMethodsContext::semi() {
  return getRuleContext<DXXParser::SemiContext>(0);
}


size_t DXXParser::ClassMethodsContext::getRuleIndex() const {
  return DXXParser::RuleClassMethods;
}

void DXXParser::ClassMethodsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterClassMethods(this);
}

void DXXParser::ClassMethodsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitClassMethods(this);
}


std::any DXXParser::ClassMethodsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitClassMethods(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ClassMethodsContext* DXXParser::classMethods() {
  ClassMethodsContext *_localctx = _tracker.createInstance<ClassMethodsContext>(_ctx, getState());
  enterRule(_localctx, 80, DXXParser::RuleClassMethods);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(484);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(478);
      class_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(479);
      interface();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(480);
      function();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(481);
      functionDefine();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(482);
      varDefine();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(483);
      semi();
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

//----------------- InterfaceMethodsContext ------------------------------------------------------------------

DXXParser::InterfaceMethodsContext::InterfaceMethodsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DXXParser::FunctionDefineContext* DXXParser::InterfaceMethodsContext::functionDefine() {
  return getRuleContext<DXXParser::FunctionDefineContext>(0);
}

DXXParser::VarDefineNoSetContext* DXXParser::InterfaceMethodsContext::varDefineNoSet() {
  return getRuleContext<DXXParser::VarDefineNoSetContext>(0);
}

DXXParser::InterfaceContext* DXXParser::InterfaceMethodsContext::interface() {
  return getRuleContext<DXXParser::InterfaceContext>(0);
}

DXXParser::SemiContext* DXXParser::InterfaceMethodsContext::semi() {
  return getRuleContext<DXXParser::SemiContext>(0);
}


size_t DXXParser::InterfaceMethodsContext::getRuleIndex() const {
  return DXXParser::RuleInterfaceMethods;
}

void DXXParser::InterfaceMethodsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceMethods(this);
}

void DXXParser::InterfaceMethodsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceMethods(this);
}


std::any DXXParser::InterfaceMethodsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitInterfaceMethods(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::InterfaceMethodsContext* DXXParser::interfaceMethods() {
  InterfaceMethodsContext *_localctx = _tracker.createInstance<InterfaceMethodsContext>(_ctx, getState());
  enterRule(_localctx, 82, DXXParser::RuleInterfaceMethods);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(490);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(486);
      functionDefine();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(487);
      varDefineNoSet();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(488);
      interface();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(489);
      semi();
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

void DXXParser::OperatorDefineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperatorDefine(this);
}

void DXXParser::OperatorDefineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperatorDefine(this);
}


std::any DXXParser::OperatorDefineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitOperatorDefine(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::OperatorDefineContext* DXXParser::operatorDefine() {
  OperatorDefineContext *_localctx = _tracker.createInstance<OperatorDefineContext>(_ctx, getState());
  enterRule(_localctx, 84, DXXParser::RuleOperatorDefine);
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
    setState(492);
    match(DXXParser::Operator);
    setState(493);
    allOperators();
    setState(494);
    match(DXXParser::LeftParen);
    setState(496);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055348269316) != 0) || ((((_la - 100) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 100)) & 7) != 0)) {
      setState(495);
      paramList();
    }
    setState(498);
    match(DXXParser::RightParen);
    setState(499);
    match(DXXParser::Arrow);
    setState(500);
    theType();
    setState(502);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::LeftBrace) {
      setState(501);
      block();
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

void DXXParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void DXXParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


std::any DXXParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::BlockContext* DXXParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 86, DXXParser::RuleBlock);
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
    setState(504);
    match(DXXParser::LeftBrace);
    setState(508);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16784864021646092) != 0) || ((((_la - 95) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 95)) & 225) != 0)) {
      setState(505);
      expressions();
      setState(510);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(511);
    match(DXXParser::RightBrace);
   
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

tree::TerminalNode* DXXParser::TryContext::Try() {
  return getToken(DXXParser::Try, 0);
}

std::vector<DXXParser::BlockContext *> DXXParser::TryContext::block() {
  return getRuleContexts<DXXParser::BlockContext>();
}

DXXParser::BlockContext* DXXParser::TryContext::block(size_t i) {
  return getRuleContext<DXXParser::BlockContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::TryContext::Catch() {
  return getTokens(DXXParser::Catch);
}

tree::TerminalNode* DXXParser::TryContext::Catch(size_t i) {
  return getToken(DXXParser::Catch, i);
}

std::vector<tree::TerminalNode *> DXXParser::TryContext::LeftParen() {
  return getTokens(DXXParser::LeftParen);
}

tree::TerminalNode* DXXParser::TryContext::LeftParen(size_t i) {
  return getToken(DXXParser::LeftParen, i);
}

std::vector<tree::TerminalNode *> DXXParser::TryContext::RightParen() {
  return getTokens(DXXParser::RightParen);
}

tree::TerminalNode* DXXParser::TryContext::RightParen(size_t i) {
  return getToken(DXXParser::RightParen, i);
}

tree::TerminalNode* DXXParser::TryContext::Finally() {
  return getToken(DXXParser::Finally, 0);
}

std::vector<DXXParser::VarDefineContext *> DXXParser::TryContext::varDefine() {
  return getRuleContexts<DXXParser::VarDefineContext>();
}

DXXParser::VarDefineContext* DXXParser::TryContext::varDefine(size_t i) {
  return getRuleContext<DXXParser::VarDefineContext>(i);
}

std::vector<tree::TerminalNode *> DXXParser::TryContext::Ellipsis() {
  return getTokens(DXXParser::Ellipsis);
}

tree::TerminalNode* DXXParser::TryContext::Ellipsis(size_t i) {
  return getToken(DXXParser::Ellipsis, i);
}


size_t DXXParser::TryContext::getRuleIndex() const {
  return DXXParser::RuleTry;
}

void DXXParser::TryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTry(this);
}

void DXXParser::TryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTry(this);
}


std::any DXXParser::TryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTry(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TryContext* DXXParser::try_() {
  TryContext *_localctx = _tracker.createInstance<TryContext>(_ctx, getState());
  enterRule(_localctx, 88, DXXParser::RuleTry);
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
    setState(513);
    match(DXXParser::Try);
    setState(514);
    block();
    setState(525);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DXXParser::Catch) {
      setState(515);
      match(DXXParser::Catch);
      setState(516);
      match(DXXParser::LeftParen);
      setState(519);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DXXParser::Bool:
        case DXXParser::Compiletime:
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
        case DXXParser::Type:
        case DXXParser::Void:
        case DXXParser::ID:
        case DXXParser::Constructor:
        case DXXParser::Destructor: {
          setState(517);
          varDefine();
          break;
        }

        case DXXParser::Ellipsis: {
          setState(518);
          match(DXXParser::Ellipsis);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(521);
      match(DXXParser::RightParen);
      setState(522);
      block();
      setState(527);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(530);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Finally) {
      setState(528);
      match(DXXParser::Finally);
      setState(529);
      block();
    }
   
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

DXXParser::IdExContext* DXXParser::ThrowContext::idEx() {
  return getRuleContext<DXXParser::IdExContext>(0);
}

DXXParser::FunctionCallContext* DXXParser::ThrowContext::functionCall() {
  return getRuleContext<DXXParser::FunctionCallContext>(0);
}


size_t DXXParser::ThrowContext::getRuleIndex() const {
  return DXXParser::RuleThrow;
}

void DXXParser::ThrowContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThrow(this);
}

void DXXParser::ThrowContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThrow(this);
}


std::any DXXParser::ThrowContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitThrow(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::ThrowContext* DXXParser::throw_() {
  ThrowContext *_localctx = _tracker.createInstance<ThrowContext>(_ctx, getState());
  enterRule(_localctx, 90, DXXParser::RuleThrow);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(532);
    match(DXXParser::Throw);
    setState(535);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      setState(533);
      idEx();
      break;
    }

    case 2: {
      setState(534);
      functionCall();
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

void DXXParser::TheTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTheType(this);
}

void DXXParser::TheTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTheType(this);
}


std::any DXXParser::TheTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTheType(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TheTypeContext* DXXParser::theType() {
  TheTypeContext *_localctx = _tracker.createInstance<TheTypeContext>(_ctx, getState());
  enterRule(_localctx, 92, DXXParser::RuleTheType);
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
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 678881722624) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(537);
      info();
      setState(542);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(543);
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

tree::TerminalNode* DXXParser::TheTypeSubContext::Type() {
  return getToken(DXXParser::Type, 0);
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

void DXXParser::TheTypeSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTheTypeSub(this);
}

void DXXParser::TheTypeSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTheTypeSub(this);
}


std::any DXXParser::TheTypeSubContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitTheTypeSub(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::TheTypeSubContext* DXXParser::theTypeSub() {
  TheTypeSubContext *_localctx = _tracker.createInstance<TheTypeSubContext>(_ctx, getState());
  enterRule(_localctx, 94, DXXParser::RuleTheTypeSub);
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
    setState(545);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2534376466546692) != 0) || _la == DXXParser::ID)) {
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

void DXXParser::IdExContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdEx(this);
}

void DXXParser::IdExContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdEx(this);
}


std::any DXXParser::IdExContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitIdEx(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::IdExContext* DXXParser::idEx() {
  IdExContext *_localctx = _tracker.createInstance<IdExContext>(_ctx, getState());
  enterRule(_localctx, 96, DXXParser::RuleIdEx);

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
    setState(551);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(547);
        match(DXXParser::ID);
        setState(548);
        match(DXXParser::Dot); 
      }
      setState(553);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx);
    }
    setState(554);
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

tree::TerminalNode* DXXParser::InfoContext::Compiletime() {
  return getToken(DXXParser::Compiletime, 0);
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

void DXXParser::InfoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInfo(this);
}

void DXXParser::InfoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInfo(this);
}


std::any DXXParser::InfoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitInfo(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::InfoContext* DXXParser::info() {
  InfoContext *_localctx = _tracker.createInstance<InfoContext>(_ctx, getState());
  enterRule(_localctx, 98, DXXParser::RuleInfo);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(567);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DXXParser::Compiletime: {
        enterOuterAlt(_localctx, 1);
        setState(556);
        match(DXXParser::Compiletime);
        break;
      }

      case DXXParser::Final: {
        enterOuterAlt(_localctx, 2);
        setState(557);
        match(DXXParser::Final);
        break;
      }

      case DXXParser::Override: {
        enterOuterAlt(_localctx, 3);
        setState(558);
        match(DXXParser::Override);
        break;
      }

      case DXXParser::Inline: {
        enterOuterAlt(_localctx, 4);
        setState(559);
        match(DXXParser::Inline);
        break;
      }

      case DXXParser::Static: {
        enterOuterAlt(_localctx, 5);
        setState(560);
        match(DXXParser::Static);
        break;
      }

      case DXXParser::Public: {
        enterOuterAlt(_localctx, 6);
        setState(561);
        match(DXXParser::Public);
        break;
      }

      case DXXParser::Protected: {
        enterOuterAlt(_localctx, 7);
        setState(562);
        match(DXXParser::Protected);
        break;
      }

      case DXXParser::Private: {
        enterOuterAlt(_localctx, 8);
        setState(563);
        match(DXXParser::Private);
        break;
      }

      case DXXParser::Constructor: {
        enterOuterAlt(_localctx, 9);
        setState(564);
        match(DXXParser::Constructor);
        break;
      }

      case DXXParser::Destructor: {
        enterOuterAlt(_localctx, 10);
        setState(565);
        match(DXXParser::Destructor);
        break;
      }

      case DXXParser::Native: {
        enterOuterAlt(_localctx, 11);
        setState(566);
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

void DXXParser::NativeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNative(this);
}

void DXXParser::NativeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNative(this);
}


std::any DXXParser::NativeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitNative(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::NativeContext* DXXParser::native() {
  NativeContext *_localctx = _tracker.createInstance<NativeContext>(_ctx, getState());
  enterRule(_localctx, 100, DXXParser::RuleNative);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(569);
    match(DXXParser::Native);
    setState(570);
    match(DXXParser::LeftParen);
    setState(571);
    match(DXXParser::StringData);
    setState(572);
    match(DXXParser::Comma);
    setState(573);
    match(DXXParser::StringData);
    setState(574);
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

void DXXParser::AssignsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssigns(this);
}

void DXXParser::AssignsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssigns(this);
}


std::any DXXParser::AssignsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitAssigns(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::AssignsContext* DXXParser::assigns() {
  AssignsContext *_localctx = _tracker.createInstance<AssignsContext>(_ctx, getState());
  enterRule(_localctx, 102, DXXParser::RuleAssigns);
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
    setState(576);
    _la = _input->LA(1);
    if (!(((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 16371) != 0))) {
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

void DXXParser::AllOperatorsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAllOperators(this);
}

void DXXParser::AllOperatorsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DXXParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAllOperators(this);
}


std::any DXXParser::AllOperatorsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitAllOperators(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::AllOperatorsContext* DXXParser::allOperators() {
  AllOperatorsContext *_localctx = _tracker.createInstance<AllOperatorsContext>(_ctx, getState());
  enterRule(_localctx, 104, DXXParser::RuleAllOperators);
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
    setState(578);
    _la = _input->LA(1);
    if (!(((((_la - 60) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 60)) & 919123001343) != 0))) {
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
    case 4: return dataSempred(antlrcpp::downCast<DataContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool DXXParser::dataSempred(DataContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);
    case 4: return precpred(_ctx, 9);
    case 5: return precpred(_ctx, 8);
    case 6: return precpred(_ctx, 7);
    case 7: return precpred(_ctx, 6);
    case 8: return precpred(_ctx, 5);
    case 9: return precpred(_ctx, 4);

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
