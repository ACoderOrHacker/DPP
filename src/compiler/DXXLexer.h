
// Generated from templates/DXXLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DXXLexer : public antlr4::Lexer {
public:
  enum {
    Asm = 1, Bool = 2, Break = 3, Case = 4, Catch = 5, Char = 6, Class = 7, 
    Continue = 8, Default = 9, Delete = 10, Do = 11, Else = 12, Enum = 13, 
    Extends = 14, False = 15, Final = 16, Finally = 17, Float = 18, Foreach = 19, 
    Goto = 20, If = 21, Import = 22, Inline = 23, Int = 24, Implements = 25, 
    Long = 26, Native = 27, New = 28, Null = 29, Object = 30, Operator = 31, 
    Override = 32, Private = 33, Protected = 34, Public = 35, Return = 36, 
    Short = 37, Static = 38, String = 39, Super = 40, Switch = 41, Template = 42, 
    This = 43, Throw = 44, True = 45, Try = 46, Typedef = 47, Virtual = 48, 
    Void = 49, While = 50, LeftParen = 51, RightParen = 52, LeftBracket = 53, 
    RightBracket = 54, LeftBrace = 55, RightBrace = 56, Arrow = 57, Plus = 58, 
    Minus = 59, Star = 60, Div = 61, Mod = 62, Caret = 63, And = 64, Or = 65, 
    Tilde = 66, Not = 67, Assign = 68, ColonAssign = 69, Less = 70, Greater = 71, 
    PlusAssign = 72, MinusAssign = 73, StarAssign = 74, DivAssign = 75, 
    ModAssign = 76, XorAssign = 77, AndAssign = 78, OrAssign = 79, LeftShiftAssign = 80, 
    RightShiftAssign = 81, Equal = 82, NotEqual = 83, LessEqual = 84, GreaterEqual = 85, 
    AndAnd = 86, OrOr = 87, PlusPlus = 88, MinusMinus = 89, Comma = 90, 
    Question = 91, Colon = 92, Semi = 93, Dot = 94, Ellipsis = 95, LeftShift = 96, 
    RightShift = 97, ID = 98, Constructor = 99, Destructor = 100, Whitespace = 101, 
    Newline = 102, BlockComment = 103, LineComment = 104, IntegerData = 105, 
    FloatingNumberData = 106, StringData = 107
  };

  explicit DXXLexer(antlr4::CharStream *input);

  ~DXXLexer() override;


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

