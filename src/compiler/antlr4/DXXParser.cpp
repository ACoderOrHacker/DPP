
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
      "main", "gExpressions", "expressions", "constant", "data", "boolean", 
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
  	4,1,109,579,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,1,0,5,0,108,8,0,10,0,12,0,111,9,0,1,
  	0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,123,8,1,1,2,1,2,1,2,1,2,1,2,
  	1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,142,8,2,1,3,1,3,1,
  	3,1,3,1,3,3,3,149,8,3,1,4,1,4,1,4,1,4,1,4,1,4,3,4,157,8,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,3,4,165,8,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,
  	4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,5,4,197,8,4,10,4,12,4,200,9,4,1,5,1,5,1,6,1,6,1,6,1,7,1,7,1,8,1,8,
  	1,8,1,9,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,13,
  	1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,15,3,15,235,8,15,1,15,1,15,
  	1,15,1,16,5,16,241,8,16,10,16,12,16,244,9,16,1,16,1,16,1,16,3,16,249,
  	8,16,1,16,1,16,1,16,1,16,3,16,255,8,16,1,17,1,17,1,17,3,17,260,8,17,1,
  	17,1,17,1,18,1,18,1,18,5,18,267,8,18,10,18,12,18,270,9,18,1,18,1,18,3,
  	18,274,8,18,1,19,1,19,1,19,5,19,279,8,19,10,19,12,19,282,9,19,1,20,1,
  	20,1,20,1,20,5,20,288,8,20,10,20,12,20,291,9,20,1,20,3,20,294,8,20,1,
  	21,1,21,5,21,298,8,21,10,21,12,21,301,9,21,1,21,1,21,1,21,1,21,3,21,307,
  	8,21,1,22,1,22,5,22,311,8,22,10,22,12,22,314,9,22,1,22,1,22,1,23,1,23,
  	1,23,1,23,1,24,1,24,1,24,3,24,325,8,24,1,25,1,25,1,25,1,25,1,25,1,25,
  	1,25,1,26,1,26,1,26,1,26,5,26,338,8,26,10,26,12,26,341,9,26,1,26,1,26,
  	1,27,1,27,1,27,1,27,1,28,1,28,1,28,1,28,1,28,1,28,5,28,355,8,28,10,28,
  	12,28,358,9,28,1,28,3,28,361,8,28,1,28,1,28,1,29,1,29,1,29,1,29,1,30,
  	1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,3,31,378,8,31,1,32,1,32,1,32,
  	1,32,1,32,1,32,1,33,1,33,1,33,1,33,3,33,390,8,33,1,33,1,33,1,33,1,33,
  	3,33,396,8,33,1,34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,36,1,36,1,36,
  	1,36,5,36,410,8,36,10,36,12,36,413,9,36,3,36,415,8,36,1,36,1,36,1,37,
  	1,37,1,37,1,37,1,38,1,38,1,38,1,38,1,38,1,38,1,38,3,38,430,8,38,3,38,
  	432,8,38,1,38,1,38,1,38,1,38,1,38,3,38,439,8,38,3,38,441,8,38,1,38,1,
  	38,5,38,445,8,38,10,38,12,38,448,9,38,1,38,1,38,1,39,1,39,1,39,1,39,1,
  	39,1,39,5,39,458,8,39,10,39,12,39,461,9,39,1,39,3,39,464,8,39,3,39,466,
  	8,39,1,39,1,39,5,39,470,8,39,10,39,12,39,473,9,39,1,39,1,39,1,40,1,40,
  	1,40,1,40,1,40,1,40,3,40,483,8,40,1,41,1,41,1,41,1,41,3,41,489,8,41,1,
  	42,1,42,1,42,1,42,3,42,495,8,42,1,42,1,42,1,42,1,42,3,42,501,8,42,1,43,
  	1,43,5,43,505,8,43,10,43,12,43,508,9,43,1,43,1,43,1,44,1,44,1,44,1,44,
  	1,44,1,44,3,44,518,8,44,1,44,1,44,5,44,522,8,44,10,44,12,44,525,9,44,
  	1,44,1,44,3,44,529,8,44,1,45,1,45,1,45,3,45,534,8,45,1,46,5,46,537,8,
  	46,10,46,12,46,540,9,46,1,46,1,46,1,47,1,47,1,48,1,48,5,48,548,8,48,10,
  	48,12,48,551,9,48,1,48,1,48,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,49,1,
  	49,1,49,1,49,3,49,566,8,49,1,50,1,50,1,50,1,50,1,50,1,50,1,50,1,51,1,
  	51,1,52,1,52,1,52,0,1,8,53,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,
  	32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,
  	78,80,82,84,86,88,90,92,94,96,98,100,102,104,0,10,2,0,69,70,91,92,1,0,
  	85,86,1,0,63,65,1,0,61,62,1,0,98,99,2,0,73,74,87,88,2,0,15,15,46,46,8,
  	0,2,2,18,18,24,24,31,31,40,40,48,48,51,51,100,100,2,0,71,72,75,84,4,0,
  	60,92,94,94,96,96,98,99,630,0,109,1,0,0,0,2,122,1,0,0,0,4,141,1,0,0,0,
  	6,148,1,0,0,0,8,164,1,0,0,0,10,201,1,0,0,0,12,203,1,0,0,0,14,206,1,0,
  	0,0,16,208,1,0,0,0,18,211,1,0,0,0,20,214,1,0,0,0,22,217,1,0,0,0,24,222,
  	1,0,0,0,26,224,1,0,0,0,28,227,1,0,0,0,30,230,1,0,0,0,32,242,1,0,0,0,34,
  	256,1,0,0,0,36,263,1,0,0,0,38,275,1,0,0,0,40,283,1,0,0,0,42,295,1,0,0,
  	0,44,308,1,0,0,0,46,317,1,0,0,0,48,324,1,0,0,0,50,326,1,0,0,0,52,333,
  	1,0,0,0,54,344,1,0,0,0,56,348,1,0,0,0,58,364,1,0,0,0,60,368,1,0,0,0,62,
  	372,1,0,0,0,64,379,1,0,0,0,66,385,1,0,0,0,68,397,1,0,0,0,70,400,1,0,0,
  	0,72,403,1,0,0,0,74,418,1,0,0,0,76,422,1,0,0,0,78,451,1,0,0,0,80,482,
  	1,0,0,0,82,488,1,0,0,0,84,490,1,0,0,0,86,502,1,0,0,0,88,511,1,0,0,0,90,
  	530,1,0,0,0,92,538,1,0,0,0,94,543,1,0,0,0,96,549,1,0,0,0,98,565,1,0,0,
  	0,100,567,1,0,0,0,102,574,1,0,0,0,104,576,1,0,0,0,106,108,3,2,1,0,107,
  	106,1,0,0,0,108,111,1,0,0,0,109,107,1,0,0,0,109,110,1,0,0,0,110,112,1,
  	0,0,0,111,109,1,0,0,0,112,113,5,0,0,1,113,1,1,0,0,0,114,123,3,16,8,0,
  	115,123,3,26,13,0,116,123,3,24,12,0,117,123,3,42,21,0,118,123,3,72,36,
  	0,119,123,3,76,38,0,120,123,3,78,39,0,121,123,3,14,7,0,122,114,1,0,0,
  	0,122,115,1,0,0,0,122,116,1,0,0,0,122,117,1,0,0,0,122,118,1,0,0,0,122,
  	119,1,0,0,0,122,120,1,0,0,0,122,121,1,0,0,0,123,3,1,0,0,0,124,142,3,18,
  	9,0,125,142,3,20,10,0,126,142,3,42,21,0,127,142,3,46,23,0,128,142,3,48,
  	24,0,129,142,3,62,31,0,130,142,3,64,32,0,131,142,3,66,33,0,132,142,3,
  	68,34,0,133,142,3,70,35,0,134,142,3,88,44,0,135,142,3,90,45,0,136,142,
  	3,22,11,0,137,142,3,28,14,0,138,142,5,3,0,0,139,142,5,9,0,0,140,142,3,
  	14,7,0,141,124,1,0,0,0,141,125,1,0,0,0,141,126,1,0,0,0,141,127,1,0,0,
  	0,141,128,1,0,0,0,141,129,1,0,0,0,141,130,1,0,0,0,141,131,1,0,0,0,141,
  	132,1,0,0,0,141,133,1,0,0,0,141,134,1,0,0,0,141,135,1,0,0,0,141,136,1,
  	0,0,0,141,137,1,0,0,0,141,138,1,0,0,0,141,139,1,0,0,0,141,140,1,0,0,0,
  	142,5,1,0,0,0,143,149,5,107,0,0,144,149,5,108,0,0,145,149,5,109,0,0,146,
  	149,3,10,5,0,147,149,5,30,0,0,148,143,1,0,0,0,148,144,1,0,0,0,148,145,
  	1,0,0,0,148,146,1,0,0,0,148,147,1,0,0,0,149,7,1,0,0,0,150,151,6,4,-1,
  	0,151,165,3,6,3,0,152,165,3,96,48,0,153,165,3,34,17,0,154,156,5,54,0,
  	0,155,157,3,8,4,0,156,155,1,0,0,0,156,157,1,0,0,0,157,158,1,0,0,0,158,
  	165,5,55,0,0,159,160,7,0,0,0,160,165,3,8,4,14,161,165,3,12,6,0,162,165,
  	3,30,15,0,163,165,3,92,46,0,164,150,1,0,0,0,164,152,1,0,0,0,164,153,1,
  	0,0,0,164,154,1,0,0,0,164,159,1,0,0,0,164,161,1,0,0,0,164,162,1,0,0,0,
  	164,163,1,0,0,0,165,198,1,0,0,0,166,167,10,13,0,0,167,168,5,89,0,0,168,
  	197,3,8,4,14,169,170,10,12,0,0,170,171,5,90,0,0,171,197,3,8,4,13,172,
  	173,10,11,0,0,173,174,7,1,0,0,174,197,3,8,4,12,175,176,10,10,0,0,176,
  	177,7,2,0,0,177,197,3,8,4,11,178,179,10,9,0,0,179,180,7,3,0,0,180,197,
  	3,8,4,10,181,182,10,8,0,0,182,183,7,4,0,0,183,197,3,8,4,9,184,185,10,
  	7,0,0,185,186,7,5,0,0,186,197,3,8,4,8,187,188,10,6,0,0,188,189,5,67,0,
  	0,189,197,3,8,4,7,190,191,10,5,0,0,191,192,5,66,0,0,192,197,3,8,4,6,193,
  	194,10,4,0,0,194,195,5,68,0,0,195,197,3,8,4,5,196,166,1,0,0,0,196,169,
  	1,0,0,0,196,172,1,0,0,0,196,175,1,0,0,0,196,178,1,0,0,0,196,181,1,0,0,
  	0,196,184,1,0,0,0,196,187,1,0,0,0,196,190,1,0,0,0,196,193,1,0,0,0,197,
  	200,1,0,0,0,198,196,1,0,0,0,198,199,1,0,0,0,199,9,1,0,0,0,200,198,1,0,
  	0,0,201,202,7,6,0,0,202,11,1,0,0,0,203,204,5,62,0,0,204,205,3,8,4,0,205,
  	13,1,0,0,0,206,207,5,95,0,0,207,15,1,0,0,0,208,209,5,22,0,0,209,210,3,
  	96,48,0,210,17,1,0,0,0,211,212,5,29,0,0,212,213,3,92,46,0,213,19,1,0,
  	0,0,214,215,5,11,0,0,215,216,3,8,4,0,216,21,1,0,0,0,217,218,5,49,0,0,
  	218,219,5,100,0,0,219,220,5,71,0,0,220,221,3,92,46,0,221,23,1,0,0,0,222,
  	223,3,32,16,0,223,25,1,0,0,0,224,225,3,32,16,0,225,226,3,86,43,0,226,
  	27,1,0,0,0,227,228,5,37,0,0,228,229,3,8,4,0,229,29,1,0,0,0,230,231,5,
  	56,0,0,231,232,5,57,0,0,232,234,5,54,0,0,233,235,3,36,18,0,234,233,1,
  	0,0,0,234,235,1,0,0,0,235,236,1,0,0,0,236,237,5,55,0,0,237,238,3,86,43,
  	0,238,31,1,0,0,0,239,241,3,98,49,0,240,239,1,0,0,0,241,244,1,0,0,0,242,
  	240,1,0,0,0,242,243,1,0,0,0,243,245,1,0,0,0,244,242,1,0,0,0,245,246,5,
  	100,0,0,246,248,5,54,0,0,247,249,3,36,18,0,248,247,1,0,0,0,248,249,1,
  	0,0,0,249,250,1,0,0,0,250,251,5,55,0,0,251,252,5,60,0,0,252,254,3,92,
  	46,0,253,255,3,40,20,0,254,253,1,0,0,0,254,255,1,0,0,0,255,33,1,0,0,0,
  	256,257,3,96,48,0,257,259,5,54,0,0,258,260,3,38,19,0,259,258,1,0,0,0,
  	259,260,1,0,0,0,260,261,1,0,0,0,261,262,5,55,0,0,262,35,1,0,0,0,263,268,
  	3,42,21,0,264,265,5,93,0,0,265,267,3,42,21,0,266,264,1,0,0,0,267,270,
  	1,0,0,0,268,266,1,0,0,0,268,269,1,0,0,0,269,273,1,0,0,0,270,268,1,0,0,
  	0,271,272,5,93,0,0,272,274,5,97,0,0,273,271,1,0,0,0,273,274,1,0,0,0,274,
  	37,1,0,0,0,275,280,3,8,4,0,276,277,5,93,0,0,277,279,3,8,4,0,278,276,1,
  	0,0,0,279,282,1,0,0,0,280,278,1,0,0,0,280,281,1,0,0,0,281,39,1,0,0,0,
  	282,280,1,0,0,0,283,289,5,45,0,0,284,285,3,96,48,0,285,286,5,93,0,0,286,
  	288,1,0,0,0,287,284,1,0,0,0,288,291,1,0,0,0,289,287,1,0,0,0,289,290,1,
  	0,0,0,290,293,1,0,0,0,291,289,1,0,0,0,292,294,3,96,48,0,293,292,1,0,0,
  	0,293,294,1,0,0,0,294,41,1,0,0,0,295,299,3,92,46,0,296,298,3,98,49,0,
  	297,296,1,0,0,0,298,301,1,0,0,0,299,297,1,0,0,0,299,300,1,0,0,0,300,302,
  	1,0,0,0,301,299,1,0,0,0,302,306,5,100,0,0,303,304,3,102,51,0,304,305,
  	3,8,4,0,305,307,1,0,0,0,306,303,1,0,0,0,306,307,1,0,0,0,307,43,1,0,0,
  	0,308,312,3,92,46,0,309,311,3,98,49,0,310,309,1,0,0,0,311,314,1,0,0,0,
  	312,310,1,0,0,0,312,313,1,0,0,0,313,315,1,0,0,0,314,312,1,0,0,0,315,316,
  	5,100,0,0,316,45,1,0,0,0,317,318,3,96,48,0,318,319,3,102,51,0,319,320,
  	3,8,4,0,320,47,1,0,0,0,321,325,3,50,25,0,322,325,3,52,26,0,323,325,3,
  	56,28,0,324,321,1,0,0,0,324,322,1,0,0,0,324,323,1,0,0,0,325,49,1,0,0,
  	0,326,327,5,53,0,0,327,328,5,21,0,0,328,329,5,54,0,0,329,330,3,8,4,0,
  	330,331,5,55,0,0,331,332,3,86,43,0,332,51,1,0,0,0,333,334,5,53,0,0,334,
  	335,5,21,0,0,335,339,5,58,0,0,336,338,3,54,27,0,337,336,1,0,0,0,338,341,
  	1,0,0,0,339,337,1,0,0,0,339,340,1,0,0,0,340,342,1,0,0,0,341,339,1,0,0,
  	0,342,343,5,59,0,0,343,53,1,0,0,0,344,345,3,8,4,0,345,346,5,60,0,0,346,
  	347,3,86,43,0,347,55,1,0,0,0,348,349,5,53,0,0,349,350,5,54,0,0,350,351,
  	3,8,4,0,351,352,5,55,0,0,352,356,5,58,0,0,353,355,3,58,29,0,354,353,1,
  	0,0,0,355,358,1,0,0,0,356,354,1,0,0,0,356,357,1,0,0,0,357,360,1,0,0,0,
  	358,356,1,0,0,0,359,361,3,60,30,0,360,359,1,0,0,0,360,361,1,0,0,0,361,
  	362,1,0,0,0,362,363,5,59,0,0,363,57,1,0,0,0,364,365,3,6,3,0,365,366,5,
  	60,0,0,366,367,3,86,43,0,367,59,1,0,0,0,368,369,5,10,0,0,369,370,5,60,
  	0,0,370,371,3,86,43,0,371,61,1,0,0,0,372,373,5,52,0,0,373,374,5,54,0,
  	0,374,375,3,4,2,0,375,377,5,55,0,0,376,378,3,86,43,0,377,376,1,0,0,0,
  	377,378,1,0,0,0,378,63,1,0,0,0,379,380,3,62,31,0,380,381,5,12,0,0,381,
  	382,5,54,0,0,382,383,3,4,2,0,383,384,5,55,0,0,384,65,1,0,0,0,385,386,
  	5,19,0,0,386,389,5,54,0,0,387,390,3,42,21,0,388,390,3,96,48,0,389,387,
  	1,0,0,0,389,388,1,0,0,0,390,391,1,0,0,0,391,392,5,94,0,0,392,393,3,4,
  	2,0,393,395,5,55,0,0,394,396,3,86,43,0,395,394,1,0,0,0,395,396,1,0,0,
  	0,396,67,1,0,0,0,397,398,5,20,0,0,398,399,5,100,0,0,399,69,1,0,0,0,400,
  	401,5,100,0,0,401,402,5,94,0,0,402,71,1,0,0,0,403,404,5,13,0,0,404,405,
  	5,100,0,0,405,414,5,58,0,0,406,411,3,74,37,0,407,408,5,93,0,0,408,410,
  	3,74,37,0,409,407,1,0,0,0,410,413,1,0,0,0,411,409,1,0,0,0,411,412,1,0,
  	0,0,412,415,1,0,0,0,413,411,1,0,0,0,414,406,1,0,0,0,414,415,1,0,0,0,415,
  	416,1,0,0,0,416,417,5,59,0,0,417,73,1,0,0,0,418,419,5,100,0,0,419,420,
  	5,71,0,0,420,421,5,107,0,0,421,75,1,0,0,0,422,423,5,7,0,0,423,431,5,100,
  	0,0,424,429,5,14,0,0,425,426,3,96,48,0,426,427,5,93,0,0,427,428,3,96,
  	48,0,428,430,1,0,0,0,429,425,1,0,0,0,429,430,1,0,0,0,430,432,1,0,0,0,
  	431,424,1,0,0,0,431,432,1,0,0,0,432,440,1,0,0,0,433,438,5,25,0,0,434,
  	435,3,96,48,0,435,436,5,93,0,0,436,437,3,96,48,0,437,439,1,0,0,0,438,
  	434,1,0,0,0,438,439,1,0,0,0,439,441,1,0,0,0,440,433,1,0,0,0,440,441,1,
  	0,0,0,441,442,1,0,0,0,442,446,5,58,0,0,443,445,3,80,40,0,444,443,1,0,
  	0,0,445,448,1,0,0,0,446,444,1,0,0,0,446,447,1,0,0,0,447,449,1,0,0,0,448,
  	446,1,0,0,0,449,450,5,59,0,0,450,77,1,0,0,0,451,452,5,26,0,0,452,465,
  	5,100,0,0,453,459,5,25,0,0,454,455,3,96,48,0,455,456,5,93,0,0,456,458,
  	1,0,0,0,457,454,1,0,0,0,458,461,1,0,0,0,459,457,1,0,0,0,459,460,1,0,0,
  	0,460,463,1,0,0,0,461,459,1,0,0,0,462,464,3,96,48,0,463,462,1,0,0,0,463,
  	464,1,0,0,0,464,466,1,0,0,0,465,453,1,0,0,0,465,466,1,0,0,0,466,467,1,
  	0,0,0,467,471,5,58,0,0,468,470,3,82,41,0,469,468,1,0,0,0,470,473,1,0,
  	0,0,471,469,1,0,0,0,471,472,1,0,0,0,472,474,1,0,0,0,473,471,1,0,0,0,474,
  	475,5,59,0,0,475,79,1,0,0,0,476,483,3,76,38,0,477,483,3,78,39,0,478,483,
  	3,26,13,0,479,483,3,24,12,0,480,483,3,42,21,0,481,483,3,14,7,0,482,476,
  	1,0,0,0,482,477,1,0,0,0,482,478,1,0,0,0,482,479,1,0,0,0,482,480,1,0,0,
  	0,482,481,1,0,0,0,483,81,1,0,0,0,484,489,3,24,12,0,485,489,3,44,22,0,
  	486,489,3,78,39,0,487,489,3,14,7,0,488,484,1,0,0,0,488,485,1,0,0,0,488,
  	486,1,0,0,0,488,487,1,0,0,0,489,83,1,0,0,0,490,491,5,32,0,0,491,492,3,
  	104,52,0,492,494,5,54,0,0,493,495,3,36,18,0,494,493,1,0,0,0,494,495,1,
  	0,0,0,495,496,1,0,0,0,496,497,5,55,0,0,497,498,5,60,0,0,498,500,3,92,
  	46,0,499,501,3,86,43,0,500,499,1,0,0,0,500,501,1,0,0,0,501,85,1,0,0,0,
  	502,506,5,58,0,0,503,505,3,4,2,0,504,503,1,0,0,0,505,508,1,0,0,0,506,
  	504,1,0,0,0,506,507,1,0,0,0,507,509,1,0,0,0,508,506,1,0,0,0,509,510,5,
  	59,0,0,510,87,1,0,0,0,511,512,5,47,0,0,512,523,3,86,43,0,513,514,5,5,
  	0,0,514,517,5,54,0,0,515,518,3,42,21,0,516,518,5,97,0,0,517,515,1,0,0,
  	0,517,516,1,0,0,0,518,519,1,0,0,0,519,520,5,55,0,0,520,522,3,86,43,0,
  	521,513,1,0,0,0,522,525,1,0,0,0,523,521,1,0,0,0,523,524,1,0,0,0,524,528,
  	1,0,0,0,525,523,1,0,0,0,526,527,5,17,0,0,527,529,3,86,43,0,528,526,1,
  	0,0,0,528,529,1,0,0,0,529,89,1,0,0,0,530,533,5,45,0,0,531,534,3,96,48,
  	0,532,534,3,34,17,0,533,531,1,0,0,0,533,532,1,0,0,0,534,91,1,0,0,0,535,
  	537,3,98,49,0,536,535,1,0,0,0,537,540,1,0,0,0,538,536,1,0,0,0,538,539,
  	1,0,0,0,539,541,1,0,0,0,540,538,1,0,0,0,541,542,3,94,47,0,542,93,1,0,
  	0,0,543,544,7,7,0,0,544,95,1,0,0,0,545,546,5,100,0,0,546,548,5,96,0,0,
  	547,545,1,0,0,0,548,551,1,0,0,0,549,547,1,0,0,0,549,550,1,0,0,0,550,552,
  	1,0,0,0,551,549,1,0,0,0,552,553,5,100,0,0,553,97,1,0,0,0,554,566,5,8,
  	0,0,555,566,5,16,0,0,556,566,5,33,0,0,557,566,5,23,0,0,558,566,5,39,0,
  	0,559,566,5,36,0,0,560,566,5,35,0,0,561,566,5,34,0,0,562,566,5,101,0,
  	0,563,566,5,102,0,0,564,566,3,100,50,0,565,554,1,0,0,0,565,555,1,0,0,
  	0,565,556,1,0,0,0,565,557,1,0,0,0,565,558,1,0,0,0,565,559,1,0,0,0,565,
  	560,1,0,0,0,565,561,1,0,0,0,565,562,1,0,0,0,565,563,1,0,0,0,565,564,1,
  	0,0,0,566,99,1,0,0,0,567,568,5,28,0,0,568,569,5,54,0,0,569,570,5,109,
  	0,0,570,571,5,93,0,0,571,572,5,109,0,0,572,573,5,55,0,0,573,101,1,0,0,
  	0,574,575,7,8,0,0,575,103,1,0,0,0,576,577,7,9,0,0,577,105,1,0,0,0,51,
  	109,122,141,148,156,164,196,198,234,242,248,254,259,268,273,280,289,293,
  	299,306,312,324,339,356,360,377,389,395,411,414,429,431,438,440,446,459,
  	463,465,471,482,488,494,500,506,517,523,528,533,538,549,565
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


//----------------- MainContext ------------------------------------------------------------------

DXXParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DXXParser::MainContext::EOF() {
  return getToken(DXXParser::EOF, 0);
}

std::vector<DXXParser::GExpressionsContext *> DXXParser::MainContext::gExpressions() {
  return getRuleContexts<DXXParser::GExpressionsContext>();
}

DXXParser::GExpressionsContext* DXXParser::MainContext::gExpressions(size_t i) {
  return getRuleContext<DXXParser::GExpressionsContext>(i);
}


size_t DXXParser::MainContext::getRuleIndex() const {
  return DXXParser::RuleMain;
}


std::any DXXParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::MainContext* DXXParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, DXXParser::RuleMain);
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
      ((1ULL << _la) & 2535055419580804) != 0) || ((((_la - 95) & ~ 0x3fULL) == 0) &&
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


std::any DXXParser::ClassExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitClassExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- EnumExprContext ------------------------------------------------------------------

DXXParser::EnumContext* DXXParser::EnumExprContext::enum_() {
  return getRuleContext<DXXParser::EnumContext>(0);
}

DXXParser::EnumExprContext::EnumExprContext(GExpressionsContext *ctx) { copyFrom(ctx); }


std::any DXXParser::EnumExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitEnumExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ImportExprContext ------------------------------------------------------------------

DXXParser::ImportLibContext* DXXParser::ImportExprContext::importLib() {
  return getRuleContext<DXXParser::ImportLibContext>(0);
}

DXXParser::ImportExprContext::ImportExprContext(GExpressionsContext *ctx) { copyFrom(ctx); }


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
    setState(122);
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
      _localctx = _tracker.createInstance<DXXParser::EnumExprContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(118);
      enum_();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<DXXParser::ClassExprContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(119);
      class_();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<DXXParser::InterfaceExprContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(120);
      interface();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<DXXParser::GSemiExprContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(121);
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
//----------------- TypedefExprTagContext ------------------------------------------------------------------

DXXParser::TypedefContext* DXXParser::TypedefExprTagContext::typedef_() {
  return getRuleContext<DXXParser::TypedefContext>(0);
}

DXXParser::TypedefExprTagContext::TypedefExprTagContext(ExpressionsContext *ctx) { copyFrom(ctx); }


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
//----------------- WithExprContext ------------------------------------------------------------------

DXXParser::WithStatementContext* DXXParser::WithExprContext::withStatement() {
  return getRuleContext<DXXParser::WithStatementContext>(0);
}

DXXParser::WithExprContext::WithExprContext(ExpressionsContext *ctx) { copyFrom(ctx); }


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
    setState(141);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<DXXParser::NewExprContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(124);
      new_();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<DXXParser::DeleteExprContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(125);
      delete_();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<DXXParser::VarDefineExprTagContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(126);
      varDefine();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<DXXParser::VarSetExprContext>(_localctx);
      enterOuterAlt(_localctx, 4);
      setState(127);
      varSet();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<DXXParser::WithExprContext>(_localctx);
      enterOuterAlt(_localctx, 5);
      setState(128);
      withStatement();
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<DXXParser::WhileLoopExprContext>(_localctx);
      enterOuterAlt(_localctx, 6);
      setState(129);
      whileLoop();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<DXXParser::DoWhileLoopExprContext>(_localctx);
      enterOuterAlt(_localctx, 7);
      setState(130);
      doWhileLoop();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<DXXParser::ForeachLoopExprContext>(_localctx);
      enterOuterAlt(_localctx, 8);
      setState(131);
      foreachLoop();
      break;
    }

    case 9: {
      _localctx = _tracker.createInstance<DXXParser::GotoExprContext>(_localctx);
      enterOuterAlt(_localctx, 9);
      setState(132);
      goto_();
      break;
    }

    case 10: {
      _localctx = _tracker.createInstance<DXXParser::GotoLabelDefineExprContext>(_localctx);
      enterOuterAlt(_localctx, 10);
      setState(133);
      gotoLabelDefine();
      break;
    }

    case 11: {
      _localctx = _tracker.createInstance<DXXParser::TryExprContext>(_localctx);
      enterOuterAlt(_localctx, 11);
      setState(134);
      try_();
      break;
    }

    case 12: {
      _localctx = _tracker.createInstance<DXXParser::ThrowExprContext>(_localctx);
      enterOuterAlt(_localctx, 12);
      setState(135);
      throw_();
      break;
    }

    case 13: {
      _localctx = _tracker.createInstance<DXXParser::TypedefExprTagContext>(_localctx);
      enterOuterAlt(_localctx, 13);
      setState(136);
      typedef_();
      break;
    }

    case 14: {
      _localctx = _tracker.createInstance<DXXParser::ReturnExprContext>(_localctx);
      enterOuterAlt(_localctx, 14);
      setState(137);
      return_();
      break;
    }

    case 15: {
      _localctx = _tracker.createInstance<DXXParser::BreakExprContext>(_localctx);
      enterOuterAlt(_localctx, 15);
      setState(138);
      match(DXXParser::Break);
      break;
    }

    case 16: {
      _localctx = _tracker.createInstance<DXXParser::ContinueExprContext>(_localctx);
      enterOuterAlt(_localctx, 16);
      setState(139);
      match(DXXParser::Continue);
      break;
    }

    case 17: {
      _localctx = _tracker.createInstance<DXXParser::SemiExprContext>(_localctx);
      enterOuterAlt(_localctx, 17);
      setState(140);
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
    setState(148);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DXXParser::IntegerData: {
        _localctx = _tracker.createInstance<DXXParser::IntegerExprContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(143);
        match(DXXParser::IntegerData);
        break;
      }

      case DXXParser::FloatingNumberData: {
        _localctx = _tracker.createInstance<DXXParser::FloatingExprContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(144);
        match(DXXParser::FloatingNumberData);
        break;
      }

      case DXXParser::StringData: {
        _localctx = _tracker.createInstance<DXXParser::StringExprContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(145);
        match(DXXParser::StringData);
        break;
      }

      case DXXParser::False:
      case DXXParser::True: {
        _localctx = _tracker.createInstance<DXXParser::BooleanExprContext>(_localctx);
        enterOuterAlt(_localctx, 4);
        setState(146);
        boolean();
        break;
      }

      case DXXParser::Null: {
        _localctx = _tracker.createInstance<DXXParser::NullExprContext>(_localctx);
        enterOuterAlt(_localctx, 5);
        setState(147);
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
    setState(164);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ConstantExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(151);
      constant();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<IdExExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(152);
      idEx();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<FunctionCallExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(153);
      functionCall();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ParensContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(154);
      match(DXXParser::LeftParen);
      setState(156);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4704363436141019396) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 69)) & 1939190317059) != 0)) {
        setState(155);
        data(0);
      }
      setState(158);
      match(DXXParser::RightParen);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<NotClassExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(159);
      _la = _input->LA(1);
      if (!(((((_la - 69) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 69)) & 12582915) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(160);
      data(14);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<NegativeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(161);
      negative();
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<LambdaFunctionExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(162);
      lambdaFunction();
      break;
    }

    case 8: {
      _localctx = _tracker.createInstance<TypeExprContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(163);
      theType();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(198);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(196);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<AndandExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(166);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(167);
          match(DXXParser::AndAnd);
          setState(168);
          data(14);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<OrorExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(169);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(170);
          match(DXXParser::OrOr);
          setState(171);
          data(13);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<EqualOrNotEqualExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(172);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(173);
          _la = _input->LA(1);
          if (!(_la == DXXParser::Equal

          || _la == DXXParser::NotEqual)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(174);
          data(12);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<StarClassExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(175);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(176);
          _la = _input->LA(1);
          if (!(((((_la - 63) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 63)) & 7) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(177);
          data(11);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<PlusClassExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(178);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(179);
          _la = _input->LA(1);
          if (!(_la == DXXParser::Plus

          || _la == DXXParser::Minus)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(180);
          data(10);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LeftOrRightShiftExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(181);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(182);
          _la = _input->LA(1);
          if (!(_la == DXXParser::LeftShift

          || _la == DXXParser::RightShift)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(183);
          data(9);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<LessClassExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(184);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(185);
          _la = _input->LA(1);
          if (!(((((_la - 73) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 73)) & 49155) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(186);
          data(8);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<AndExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(187);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(188);
          match(DXXParser::And);
          setState(189);
          data(7);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<CaretExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(190);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(191);
          match(DXXParser::Caret);
          setState(192);
          data(6);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<OrExprContext>(_tracker.createInstance<DataContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleData);
          setState(193);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(194);
          match(DXXParser::Or);
          setState(195);
          data(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(200);
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
    setState(201);
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
    setState(203);
    match(DXXParser::Minus);
    setState(204);
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
    setState(206);
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
    setState(208);
    match(DXXParser::Import);
    setState(209);
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
    setState(211);
    match(DXXParser::New);
    setState(212);
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
    setState(214);
    match(DXXParser::Delete);
    setState(215);
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
    setState(217);
    match(DXXParser::Using);
    setState(218);
    match(DXXParser::ID);
    setState(219);
    match(DXXParser::Assign);
    setState(220);
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
    setState(222);
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
    setState(224);
    functionHead();
    setState(225);
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
    setState(227);
    match(DXXParser::Return);
    setState(228);
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
    setState(230);
    match(DXXParser::LeftBracket);
    setState(231);
    match(DXXParser::RightBracket);
    setState(232);
    match(DXXParser::LeftParen);
    setState(234);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055348269316) != 0) || ((((_la - 100) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 100)) & 7) != 0)) {
      setState(233);
      paramList();
    }
    setState(236);
    match(DXXParser::RightParen);
    setState(237);
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
    setState(242);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 678881722624) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(239);
      info();
      setState(244);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(245);
    match(DXXParser::ID);
    setState(246);
    match(DXXParser::LeftParen);
    setState(248);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055348269316) != 0) || ((((_la - 100) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 100)) & 7) != 0)) {
      setState(247);
      paramList();
    }
    setState(250);
    match(DXXParser::RightParen);
    setState(251);
    match(DXXParser::Arrow);
    setState(252);
    theType();
    setState(254);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Throw) {
      setState(253);
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
    setState(256);
    idEx();
    setState(257);
    match(DXXParser::LeftParen);
    setState(259);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4704363436141019396) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & 1939190317059) != 0)) {
      setState(258);
      callParamList();
    }
    setState(261);
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
    setState(263);
    varDefine();
    setState(268);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(264);
        match(DXXParser::Comma);
        setState(265);
        varDefine(); 
      }
      setState(270);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
    setState(273);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Comma) {
      setState(271);
      match(DXXParser::Comma);
      setState(272);
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
    setState(275);
    data(0);
    setState(280);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DXXParser::Comma) {
      setState(276);
      match(DXXParser::Comma);
      setState(277);
      data(0);
      setState(282);
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
    setState(283);
    match(DXXParser::Throw);
    setState(289);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(284);
        idEx();
        setState(285);
        match(DXXParser::Comma); 
      }
      setState(291);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
    setState(293);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      setState(292);
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
    setState(295);
    theType();
    setState(299);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 678881722624) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(296);
      info();
      setState(301);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(302);
    match(DXXParser::ID);
    setState(306);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 71) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 71)) & 16371) != 0)) {
      setState(303);
      assigns();
      setState(304);
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
    setState(308);
    theType();
    setState(312);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 678881722624) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(309);
      info();
      setState(314);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(315);
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
    setState(317);
    idEx();
    setState(318);
    assigns();
    setState(319);
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
    setState(324);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(321);
      withIf();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(322);
      withIfExtends();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(323);
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
    setState(326);
    match(DXXParser::With);
    setState(327);
    match(DXXParser::If);
    setState(328);
    match(DXXParser::LeftParen);
    setState(329);
    data(0);
    setState(330);
    match(DXXParser::RightParen);
    setState(331);
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
    setState(333);
    match(DXXParser::With);
    setState(334);
    match(DXXParser::If);
    setState(335);
    match(DXXParser::LeftBrace);
    setState(339);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4704363436141019396) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & 1939190317059) != 0)) {
      setState(336);
      withIfExtendsSub();
      setState(341);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(342);
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
    setState(344);
    data(0);
    setState(345);
    match(DXXParser::Arrow);
    setState(346);
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
    setState(348);
    match(DXXParser::With);
    setState(349);
    match(DXXParser::LeftParen);
    setState(350);
    data(0);
    setState(351);
    match(DXXParser::RightParen);
    setState(352);
    match(DXXParser::LeftBrace);
    setState(356);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 70369817952256) != 0) || ((((_la - 107) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 107)) & 7) != 0)) {
      setState(353);
      caseStatement();
      setState(358);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(360);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Default) {
      setState(359);
      defaultStatement();
    }
    setState(362);
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
    setState(364);
    constant();
    setState(365);
    match(DXXParser::Arrow);
    setState(366);
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
    setState(368);
    match(DXXParser::Default);
    setState(369);
    match(DXXParser::Arrow);
    setState(370);
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


std::any DXXParser::WhileLoopContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DXXParserVisitor*>(visitor))
    return parserVisitor->visitWhileLoop(this);
  else
    return visitor->visitChildren(this);
}

DXXParser::WhileLoopContext* DXXParser::whileLoop() {
  WhileLoopContext *_localctx = _tracker.createInstance<WhileLoopContext>(_ctx, getState());
  enterRule(_localctx, 62, DXXParser::RuleWhileLoop);
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
    match(DXXParser::While);
    setState(373);
    match(DXXParser::LeftParen);
    setState(374);
    expressions();
    setState(375);
    match(DXXParser::RightParen);
    setState(377);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::LeftBrace) {
      setState(376);
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
    setState(379);
    whileLoop();
    setState(380);
    match(DXXParser::Do);
    setState(381);
    match(DXXParser::LeftParen);
    setState(382);
    expressions();
    setState(383);
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
  enterRule(_localctx, 66, DXXParser::RuleForeachLoop);
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
    setState(385);
    match(DXXParser::Foreach);
    setState(386);
    match(DXXParser::LeftParen);
    setState(389);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      setState(387);
      varDefine();
      break;
    }

    case 2: {
      setState(388);
      idEx();
      break;
    }

    default:
      break;
    }
    setState(391);
    match(DXXParser::Colon);
    setState(392);
    expressions();
    setState(393);
    match(DXXParser::RightParen);
    setState(395);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::LeftBrace) {
      setState(394);
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
    setState(397);
    match(DXXParser::Goto);
    setState(398);
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
    setState(400);
    match(DXXParser::ID);
    setState(401);
    match(DXXParser::Colon);
   
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

std::vector<DXXParser::EnumSubContext *> DXXParser::EnumContext::enumSub() {
  return getRuleContexts<DXXParser::EnumSubContext>();
}

DXXParser::EnumSubContext* DXXParser::EnumContext::enumSub(size_t i) {
  return getRuleContext<DXXParser::EnumSubContext>(i);
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
    match(DXXParser::ID);
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

tree::TerminalNode* DXXParser::EnumSubContext::IntegerData() {
  return getToken(DXXParser::IntegerData, 0);
}


size_t DXXParser::EnumSubContext::getRuleIndex() const {
  return DXXParser::RuleEnumSub;
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
    setState(420);
    match(DXXParser::IntegerData);
   
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
    setState(422);
    match(DXXParser::Class);
    setState(423);
    match(DXXParser::ID);
    setState(431);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Extends) {
      setState(424);
      match(DXXParser::Extends);
      setState(429);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DXXParser::ID) {
        setState(425);
        idEx();

        setState(426);
        match(DXXParser::Comma);
        setState(427);
        idEx();
      }
    }
    setState(440);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Implements) {
      setState(433);
      match(DXXParser::Implements);
      setState(438);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DXXParser::ID) {
        setState(434);
        idEx();

        setState(435);
        match(DXXParser::Comma);
        setState(436);
        idEx();
      }
    }
    setState(442);
    match(DXXParser::LeftBrace);
    setState(446);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055415378308) != 0) || ((((_la - 95) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 95)) & 225) != 0)) {
      setState(443);
      classMethods();
      setState(448);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(449);
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
    setState(451);
    match(DXXParser::Interface);
    setState(452);
    match(DXXParser::ID);
    setState(465);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Implements) {
      setState(453);
      match(DXXParser::Implements);
      setState(459);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(454);
          idEx();
          setState(455);
          match(DXXParser::Comma); 
        }
        setState(461);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
      }
      setState(463);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DXXParser::ID) {
        setState(462);
        idEx();
      }
    }
    setState(467);
    match(DXXParser::LeftBrace);
    setState(471);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055415378180) != 0) || ((((_la - 95) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 95)) & 225) != 0)) {
      setState(468);
      interfaceMethods();
      setState(473);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(474);
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
    setState(482);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(476);
      class_();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(477);
      interface();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(478);
      function();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(479);
      functionDefine();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(480);
      varDefine();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(481);
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
    setState(488);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(484);
      functionDefine();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(485);
      varDefineNoSet();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(486);
      interface();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(487);
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
    setState(490);
    match(DXXParser::Operator);
    setState(491);
    allOperators();
    setState(492);
    match(DXXParser::LeftParen);
    setState(494);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2535055348269316) != 0) || ((((_la - 100) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 100)) & 7) != 0)) {
      setState(493);
      paramList();
    }
    setState(496);
    match(DXXParser::RightParen);
    setState(497);
    match(DXXParser::Arrow);
    setState(498);
    theType();
    setState(500);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::LeftBrace) {
      setState(499);
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
    setState(502);
    match(DXXParser::LeftBrace);
    setState(506);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 16784864021646092) != 0) || ((((_la - 95) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 95)) & 225) != 0)) {
      setState(503);
      expressions();
      setState(508);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(509);
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
    setState(511);
    match(DXXParser::Try);
    setState(512);
    block();
    setState(523);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DXXParser::Catch) {
      setState(513);
      match(DXXParser::Catch);
      setState(514);
      match(DXXParser::LeftParen);
      setState(517);
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
          setState(515);
          varDefine();
          break;
        }

        case DXXParser::Ellipsis: {
          setState(516);
          match(DXXParser::Ellipsis);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(519);
      match(DXXParser::RightParen);
      setState(520);
      block();
      setState(525);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(528);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DXXParser::Finally) {
      setState(526);
      match(DXXParser::Finally);
      setState(527);
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
    setState(530);
    match(DXXParser::Throw);
    setState(533);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(531);
      idEx();
      break;
    }

    case 2: {
      setState(532);
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
    setState(538);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 678881722624) != 0) || _la == DXXParser::Constructor

    || _la == DXXParser::Destructor) {
      setState(535);
      info();
      setState(540);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(541);
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
    setState(543);
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
    setState(549);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(545);
        match(DXXParser::ID);
        setState(546);
        match(DXXParser::Dot); 
      }
      setState(551);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx);
    }
    setState(552);
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
    setState(565);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DXXParser::Compiletime: {
        enterOuterAlt(_localctx, 1);
        setState(554);
        match(DXXParser::Compiletime);
        break;
      }

      case DXXParser::Final: {
        enterOuterAlt(_localctx, 2);
        setState(555);
        match(DXXParser::Final);
        break;
      }

      case DXXParser::Override: {
        enterOuterAlt(_localctx, 3);
        setState(556);
        match(DXXParser::Override);
        break;
      }

      case DXXParser::Inline: {
        enterOuterAlt(_localctx, 4);
        setState(557);
        match(DXXParser::Inline);
        break;
      }

      case DXXParser::Static: {
        enterOuterAlt(_localctx, 5);
        setState(558);
        match(DXXParser::Static);
        break;
      }

      case DXXParser::Public: {
        enterOuterAlt(_localctx, 6);
        setState(559);
        match(DXXParser::Public);
        break;
      }

      case DXXParser::Protected: {
        enterOuterAlt(_localctx, 7);
        setState(560);
        match(DXXParser::Protected);
        break;
      }

      case DXXParser::Private: {
        enterOuterAlt(_localctx, 8);
        setState(561);
        match(DXXParser::Private);
        break;
      }

      case DXXParser::Constructor: {
        enterOuterAlt(_localctx, 9);
        setState(562);
        match(DXXParser::Constructor);
        break;
      }

      case DXXParser::Destructor: {
        enterOuterAlt(_localctx, 10);
        setState(563);
        match(DXXParser::Destructor);
        break;
      }

      case DXXParser::Native: {
        enterOuterAlt(_localctx, 11);
        setState(564);
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
    setState(567);
    match(DXXParser::Native);
    setState(568);
    match(DXXParser::LeftParen);
    setState(569);
    match(DXXParser::StringData);
    setState(570);
    match(DXXParser::Comma);
    setState(571);
    match(DXXParser::StringData);
    setState(572);
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
    setState(574);
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
    setState(576);
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
