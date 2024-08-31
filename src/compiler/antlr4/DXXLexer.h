
// Generated from templates/DXXLexer.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DXXLexer : public antlr4::Lexer {
public:
  enum {
    Asm = 1, Bool = 2, Break = 3, Case = 4, Catch = 5, Char = 6, Class = 7, 
    Compiletime = 8, Continue = 9, Default = 10, Delete = 11, Do = 12, Enum = 13, 
    Extends = 14, False = 15, Final = 16, Finally = 17, Float = 18, Foreach = 19, 
    Goto = 20, If = 21, Import = 22, Inline = 23, Int = 24, Implements = 25, 
    Interface = 26, Long = 27, Native = 28, New = 29, Null = 30, Object = 31, 
    Operator = 32, Override = 33, Private = 34, Protected = 35, Public = 36, 
    Return = 37, Short = 38, Static = 39, String = 40, Super = 41, Switch = 42, 
    Template = 43, This = 44, Throw = 45, True = 46, Try = 47, Type = 48, 
    Using = 49, Virtual = 50, Void = 51, While = 52, With = 53, LeftParen = 54, 
    RightParen = 55, LeftBracket = 56, RightBracket = 57, LeftBrace = 58, 
    RightBrace = 59, Arrow = 60, Plus = 61, Minus = 62, Star = 63, Div = 64, 
    Mod = 65, Caret = 66, And = 67, Or = 68, Tilde = 69, Not = 70, Assign = 71, 
    ColonAssign = 72, Less = 73, Greater = 74, PlusAssign = 75, MinusAssign = 76, 
    StarAssign = 77, DivAssign = 78, ModAssign = 79, XorAssign = 80, AndAssign = 81, 
    OrAssign = 82, LeftShiftAssign = 83, RightShiftAssign = 84, Equal = 85, 
    NotEqual = 86, LessEqual = 87, GreaterEqual = 88, AndAnd = 89, OrOr = 90, 
    PlusPlus = 91, MinusMinus = 92, Comma = 93, Colon = 94, Semi = 95, Dot = 96, 
    Ellipsis = 97, LeftShift = 98, RightShift = 99, ID = 100, Constructor = 101, 
    Destructor = 102, Whitespace = 103, Newline = 104, BlockComment = 105, 
    LineComment = 106, IntegerData = 107, FloatingNumberData = 108, StringData = 109
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

