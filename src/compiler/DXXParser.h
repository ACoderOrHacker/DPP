
// Generated from templates/DXXParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DXXParser : public antlr4::Parser {
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

  enum {
    RuleStat = 0, RuleExpressions = 1, RuleBoolean = 2, RuleNegative = 3, 
    RuleImportLib = 4, RuleFunctionDefine = 5, RuleFunction = 6, RuleReturn = 7, 
    RuleLambdaFunction = 8, RuleFunctionHead = 9, RuleFunctionCall = 10, 
    RuleParamList = 11, RuleCallParamList = 12, RuleVarDefine = 13, RuleVarSet = 14, 
    RuleIfStatement = 15, RuleSwitchStatement = 16, RuleCaseStatement = 17, 
    RuleDefaultStatement = 18, RuleWhileLoop = 19, RuleDoWhileLoop = 20, 
    RuleForeachLoop = 21, RuleGoto = 22, RuleGotoLabelDefine = 23, RuleEnum = 24, 
    RuleEnumList = 25, RuleClass = 26, RuleClassMethods = 27, RuleOperatorDefine = 28, 
    RuleBlock = 29, RuleTemplateList = 30, RuleCallTemplateList = 31, RuleTemplateListSub = 32, 
    RuleCallTemplateSub = 33, RuleTry = 34, RuleTrySub = 35, RuleCatchSub = 36, 
    RuleFinallySub = 37, RuleThrow = 38, RuleTheType = 39, RuleTheTypeSub = 40, 
    RuleIdEx = 41, RuleInfo = 42, RuleNative = 43, RuleAssigns = 44, RuleAllOperators = 45
  };

  explicit DXXParser(antlr4::TokenStream *input);

  DXXParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~DXXParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class StatContext;
  class ExpressionsContext;
  class BooleanContext;
  class NegativeContext;
  class ImportLibContext;
  class FunctionDefineContext;
  class FunctionContext;
  class ReturnContext;
  class LambdaFunctionContext;
  class FunctionHeadContext;
  class FunctionCallContext;
  class ParamListContext;
  class CallParamListContext;
  class VarDefineContext;
  class VarSetContext;
  class IfStatementContext;
  class SwitchStatementContext;
  class CaseStatementContext;
  class DefaultStatementContext;
  class WhileLoopContext;
  class DoWhileLoopContext;
  class ForeachLoopContext;
  class GotoContext;
  class GotoLabelDefineContext;
  class EnumContext;
  class EnumListContext;
  class ClassContext;
  class ClassMethodsContext;
  class OperatorDefineContext;
  class BlockContext;
  class TemplateListContext;
  class CallTemplateListContext;
  class TemplateListSubContext;
  class CallTemplateSubContext;
  class TryContext;
  class TrySubContext;
  class CatchSubContext;
  class FinallySubContext;
  class ThrowContext;
  class TheTypeContext;
  class TheTypeSubContext;
  class IdExContext;
  class InfoContext;
  class NativeContext;
  class AssignsContext;
  class AllOperatorsContext; 

  class  StatContext : public antlr4::ParserRuleContext {
  public:
    StatContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatContext* stat();

  class  ExpressionsContext : public antlr4::ParserRuleContext {
  public:
    ExpressionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionsContext() = default;
    void copyFrom(ExpressionsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  VarSetExprContext : public ExpressionsContext {
  public:
    VarSetExprContext(ExpressionsContext *ctx);

    VarSetContext *varSet();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParensContext : public ExpressionsContext {
  public:
    ParensContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    ExpressionsContext *expressions();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DoWhileLoopExprContext : public ExpressionsContext {
  public:
    DoWhileLoopExprContext(ExpressionsContext *ctx);

    DoWhileLoopContext *doWhileLoop();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntegerExprContext : public ExpressionsContext {
  public:
    IntegerExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *IntegerData();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NullExprContext : public ExpressionsContext {
  public:
    NullExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *Null();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VoidExprContext : public ExpressionsContext {
  public:
    VoidExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *Void();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdExExprContext : public ExpressionsContext {
  public:
    IdExExprContext(ExpressionsContext *ctx);

    IdExContext *idEx();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegativeExprContext : public ExpressionsContext {
  public:
    NegativeExprContext(ExpressionsContext *ctx);

    NegativeContext *negative();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakExprContext : public ExpressionsContext {
  public:
    BreakExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *Break();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlusClassExprContext : public ExpressionsContext {
  public:
    PlusClassExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  QuestionExprContext : public ExpressionsContext {
  public:
    QuestionExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *Question();
    antlr4::tree::TerminalNode *Colon();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarDefineExprContext : public ExpressionsContext {
  public:
    VarDefineExprContext(ExpressionsContext *ctx);

    VarDefineContext *varDefine();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionExprContext : public ExpressionsContext {
  public:
    FunctionExprContext(ExpressionsContext *ctx);

    FunctionContext *function();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringExprContext : public ExpressionsContext {
  public:
    StringExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *StringData();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfStatementExprContext : public ExpressionsContext {
  public:
    IfStatementExprContext(ExpressionsContext *ctx);

    IfStatementContext *ifStatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqualOrNotEqualExprContext : public ExpressionsContext {
  public:
    EqualOrNotEqualExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *Equal();
    antlr4::tree::TerminalNode *NotEqual();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConvertExprContext : public ExpressionsContext {
  public:
    ConvertExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *LeftParen();
    TheTypeContext *theType();
    antlr4::tree::TerminalNode *RightParen();
    ExpressionsContext *expressions();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StarClassExprContext : public ExpressionsContext {
  public:
    StarClassExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *Star();
    antlr4::tree::TerminalNode *Div();
    antlr4::tree::TerminalNode *Mod();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallExprContext : public ExpressionsContext {
  public:
    FunctionCallExprContext(ExpressionsContext *ctx);

    FunctionCallContext *functionCall();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SwitchStatementExprContext : public ExpressionsContext {
  public:
    SwitchStatementExprContext(ExpressionsContext *ctx);

    SwitchStatementContext *switchStatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EnumExprContext : public ExpressionsContext {
  public:
    EnumExprContext(ExpressionsContext *ctx);

    EnumContext *enum_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatingExprContext : public ExpressionsContext {
  public:
    FloatingExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *FloatingNumberData();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LessClassExprContext : public ExpressionsContext {
  public:
    LessClassExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *LessEqual();
    antlr4::tree::TerminalNode *GreaterEqual();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ImportExprContext : public ExpressionsContext {
  public:
    ImportExprContext(ExpressionsContext *ctx);

    ImportLibContext *importLib();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ForeachLoopExprContext : public ExpressionsContext {
  public:
    ForeachLoopExprContext(ExpressionsContext *ctx);

    ForeachLoopContext *foreachLoop();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ThrowExprContext : public ExpressionsContext {
  public:
    ThrowExprContext(ExpressionsContext *ctx);

    ThrowContext *throw_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrorExprContext : public ExpressionsContext {
  public:
    OrorExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *OrOr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GotoExprContext : public ExpressionsContext {
  public:
    GotoExprContext(ExpressionsContext *ctx);

    GotoContext *goto_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SemiExprContext : public ExpressionsContext {
  public:
    SemiExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *Semi();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeExprContext : public ExpressionsContext {
  public:
    TypeExprContext(ExpressionsContext *ctx);

    TheTypeContext *theType();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotClassExprContext : public ExpressionsContext {
  public:
    NotClassExprContext(ExpressionsContext *ctx);

    ExpressionsContext *expressions();
    antlr4::tree::TerminalNode *Not();
    antlr4::tree::TerminalNode *Tilde();
    antlr4::tree::TerminalNode *PlusPlus();
    antlr4::tree::TerminalNode *MinusMinus();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BooleanExprContext : public ExpressionsContext {
  public:
    BooleanExprContext(ExpressionsContext *ctx);

    BooleanContext *boolean();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionDefineExprContext : public ExpressionsContext {
  public:
    FunctionDefineExprContext(ExpressionsContext *ctx);

    FunctionDefineContext *functionDefine();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnExprContext : public ExpressionsContext {
  public:
    ReturnExprContext(ExpressionsContext *ctx);

    ReturnContext *return_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ClassExprContext : public ExpressionsContext {
  public:
    ClassExprContext(ExpressionsContext *ctx);

    ClassContext *class_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LeftOrRightShiftExprContext : public ExpressionsContext {
  public:
    LeftOrRightShiftExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *LeftShift();
    antlr4::tree::TerminalNode *RightShift();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrExprContext : public ExpressionsContext {
  public:
    OrExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *Or();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LambdaFunctionExprContext : public ExpressionsContext {
  public:
    LambdaFunctionExprContext(ExpressionsContext *ctx);

    LambdaFunctionContext *lambdaFunction();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ContinueExprContext : public ExpressionsContext {
  public:
    ContinueExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *Continue();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndandExprContext : public ExpressionsContext {
  public:
    AndandExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *AndAnd();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileLoopExprContext : public ExpressionsContext {
  public:
    WhileLoopExprContext(ExpressionsContext *ctx);

    WhileLoopContext *whileLoop();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CaretExprContext : public ExpressionsContext {
  public:
    CaretExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *Caret();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TryExprContext : public ExpressionsContext {
  public:
    TryExprContext(ExpressionsContext *ctx);

    TryContext *try_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GotoLabelDefineExprContext : public ExpressionsContext {
  public:
    GotoLabelDefineExprContext(ExpressionsContext *ctx);

    GotoLabelDefineContext *gotoLabelDefine();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OperatorDefineExprContext : public ExpressionsContext {
  public:
    OperatorDefineExprContext(ExpressionsContext *ctx);

    OperatorDefineContext *operatorDefine();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndExprContext : public ExpressionsContext {
  public:
    AndExprContext(ExpressionsContext *ctx);

    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    antlr4::tree::TerminalNode *And();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionsContext* expressions();
  ExpressionsContext* expressions(int precedence);
  class  BooleanContext : public antlr4::ParserRuleContext {
  public:
    BooleanContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *True();
    antlr4::tree::TerminalNode *False();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BooleanContext* boolean();

  class  NegativeContext : public antlr4::ParserRuleContext {
  public:
    NegativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Minus();
    ExpressionsContext *expressions();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NegativeContext* negative();

  class  ImportLibContext : public antlr4::ParserRuleContext {
  public:
    ImportLibContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Import();
    IdExContext *idEx();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImportLibContext* importLib();

  class  FunctionDefineContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionHeadContext *functionHead();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDefineContext* functionDefine();

  class  FunctionContext : public antlr4::ParserRuleContext {
  public:
    FunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionHeadContext *functionHead();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionContext* function();

  class  ReturnContext : public antlr4::ParserRuleContext {
  public:
    ReturnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    ExpressionsContext *expressions();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnContext* return_();

  class  LambdaFunctionContext : public antlr4::ParserRuleContext {
  public:
    LambdaFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LambdaFunctionContext* lambdaFunction();

  class  FunctionHeadContext : public antlr4::ParserRuleContext {
  public:
    FunctionHeadContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    antlr4::tree::TerminalNode *Arrow();
    TheTypeContext *theType();
    TemplateListContext *templateList();
    std::vector<InfoContext *> info();
    InfoContext* info(size_t i);
    ParamListContext *paramList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionHeadContext* functionHead();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdExContext *idEx();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    CallTemplateListContext *callTemplateList();
    CallParamListContext *callParamList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionCallContext* functionCall();

  class  ParamListContext : public antlr4::ParserRuleContext {
  public:
    ParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarDefineContext *> varDefine();
    VarDefineContext* varDefine(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);
    antlr4::tree::TerminalNode *Ellipsis();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamListContext* paramList();

  class  CallParamListContext : public antlr4::ParserRuleContext {
  public:
    CallParamListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallParamListContext* callParamList();

  class  VarDefineContext : public antlr4::ParserRuleContext {
  public:
    VarDefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TheTypeContext *theType();
    VarSetContext *varSet();
    antlr4::tree::TerminalNode *ID();
    std::vector<InfoContext *> info();
    InfoContext* info(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDefineContext* varDefine();

  class  VarSetContext : public antlr4::ParserRuleContext {
  public:
    VarSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdExContext *idEx();
    AssignsContext *assigns();
    ExpressionsContext *expressions();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarSetContext* varSet();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> If();
    antlr4::tree::TerminalNode* If(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LeftParen();
    antlr4::tree::TerminalNode* LeftParen(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightParen();
    antlr4::tree::TerminalNode* RightParen(size_t i);
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Else();
    antlr4::tree::TerminalNode* Else(size_t i);
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatementContext* ifStatement();

  class  SwitchStatementContext : public antlr4::ParserRuleContext {
  public:
    SwitchStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Switch();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionsContext *expressions();
    antlr4::tree::TerminalNode *RightParen();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<CaseStatementContext *> caseStatement();
    CaseStatementContext* caseStatement(size_t i);
    DefaultStatementContext *defaultStatement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SwitchStatementContext* switchStatement();

  class  CaseStatementContext : public antlr4::ParserRuleContext {
  public:
    CaseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Case();
    ExpressionsContext *expressions();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CaseStatementContext* caseStatement();

  class  DefaultStatementContext : public antlr4::ParserRuleContext {
  public:
    DefaultStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Default();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DefaultStatementContext* defaultStatement();

  class  WhileLoopContext : public antlr4::ParserRuleContext {
  public:
    WhileLoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionsContext *expressions();
    antlr4::tree::TerminalNode *RightParen();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileLoopContext* whileLoop();

  class  DoWhileLoopContext : public antlr4::ParserRuleContext {
  public:
    DoWhileLoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    WhileLoopContext *whileLoop();
    antlr4::tree::TerminalNode *Do();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionsContext *expressions();
    antlr4::tree::TerminalNode *RightParen();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DoWhileLoopContext* doWhileLoop();

  class  ForeachLoopContext : public antlr4::ParserRuleContext {
  public:
    ForeachLoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Foreach();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *Colon();
    ExpressionsContext *expressions();
    antlr4::tree::TerminalNode *RightParen();
    VarDefineContext *varDefine();
    IdExContext *idEx();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForeachLoopContext* foreachLoop();

  class  GotoContext : public antlr4::ParserRuleContext {
  public:
    GotoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Goto();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GotoContext* goto_();

  class  GotoLabelDefineContext : public antlr4::ParserRuleContext {
  public:
    GotoLabelDefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Colon();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  GotoLabelDefineContext* gotoLabelDefine();

  class  EnumContext : public antlr4::ParserRuleContext {
  public:
    EnumContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Enum();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    EnumListContext *enumList();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumContext* enum_();

  class  EnumListContext : public antlr4::ParserRuleContext {
  public:
    EnumListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EnumListContext* enumList();

  class  ClassContext : public antlr4::ParserRuleContext {
  public:
    ClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TemplateListContext *templateList();
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    antlr4::tree::TerminalNode *Extends();
    antlr4::tree::TerminalNode *Implements();
    std::vector<ClassMethodsContext *> classMethods();
    ClassMethodsContext* classMethods(size_t i);
    std::vector<IdExContext *> idEx();
    IdExContext* idEx(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassContext* class_();

  class  ClassMethodsContext : public antlr4::ParserRuleContext {
  public:
    ClassMethodsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionsContext *expressions();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassMethodsContext* classMethods();

  class  OperatorDefineContext : public antlr4::ParserRuleContext {
  public:
    OperatorDefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Operator();
    AllOperatorsContext *allOperators();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    antlr4::tree::TerminalNode *Arrow();
    TheTypeContext *theType();
    ParamListContext *paramList();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperatorDefineContext* operatorDefine();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  TemplateListContext : public antlr4::ParserRuleContext {
  public:
    TemplateListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Template();
    antlr4::tree::TerminalNode *Less();
    TemplateListSubContext *templateListSub();
    antlr4::tree::TerminalNode *Greater();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplateListContext* templateList();

  class  CallTemplateListContext : public antlr4::ParserRuleContext {
  public:
    CallTemplateListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Less();
    CallTemplateSubContext *callTemplateSub();
    antlr4::tree::TerminalNode *Greater();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallTemplateListContext* callTemplateList();

  class  TemplateListSubContext : public antlr4::ParserRuleContext {
  public:
    TemplateListSubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Class();
    antlr4::tree::TerminalNode* Class(size_t i);
    std::vector<TheTypeContext *> theType();
    TheTypeContext* theType(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Assign();
    antlr4::tree::TerminalNode* Assign(size_t i);
    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TemplateListSubContext* templateListSub();

  class  CallTemplateSubContext : public antlr4::ParserRuleContext {
  public:
    CallTemplateSubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionsContext *> expressions();
    ExpressionsContext* expressions(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallTemplateSubContext* callTemplateSub();

  class  TryContext : public antlr4::ParserRuleContext {
  public:
    TryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TrySubContext *trySub();
    std::vector<CatchSubContext *> catchSub();
    CatchSubContext* catchSub(size_t i);
    FinallySubContext *finallySub();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TryContext* try_();

  class  TrySubContext : public antlr4::ParserRuleContext {
  public:
    TrySubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Try();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TrySubContext* trySub();

  class  CatchSubContext : public antlr4::ParserRuleContext {
  public:
    CatchSubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Catch();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    BlockContext *block();
    VarDefineContext *varDefine();
    antlr4::tree::TerminalNode *Ellipsis();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CatchSubContext* catchSub();

  class  FinallySubContext : public antlr4::ParserRuleContext {
  public:
    FinallySubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Finally();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FinallySubContext* finallySub();

  class  ThrowContext : public antlr4::ParserRuleContext {
  public:
    ThrowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Throw();
    ExpressionsContext *expressions();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ThrowContext* throw_();

  class  TheTypeContext : public antlr4::ParserRuleContext {
  public:
    TheTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TheTypeSubContext *theTypeSub();
    std::vector<InfoContext *> info();
    InfoContext* info(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TheTypeContext* theType();

  class  TheTypeSubContext : public antlr4::ParserRuleContext {
  public:
    TheTypeSubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *Float();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *Object();
    antlr4::tree::TerminalNode *Void();
    antlr4::tree::TerminalNode *ID();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TheTypeSubContext* theTypeSub();

  class  IdExContext : public antlr4::ParserRuleContext {
  public:
    IdExContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Dot();
    antlr4::tree::TerminalNode* Dot(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IdExContext* idEx();

  class  InfoContext : public antlr4::ParserRuleContext {
  public:
    InfoContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Final();
    antlr4::tree::TerminalNode *Override();
    antlr4::tree::TerminalNode *Inline();
    antlr4::tree::TerminalNode *Static();
    antlr4::tree::TerminalNode *Public();
    antlr4::tree::TerminalNode *Protected();
    antlr4::tree::TerminalNode *Private();
    antlr4::tree::TerminalNode *Constructor();
    antlr4::tree::TerminalNode *Destructor();
    NativeContext *native();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InfoContext* info();

  class  NativeContext : public antlr4::ParserRuleContext {
  public:
    NativeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Native();
    antlr4::tree::TerminalNode *LeftParen();
    std::vector<antlr4::tree::TerminalNode *> StringData();
    antlr4::tree::TerminalNode* StringData(size_t i);
    antlr4::tree::TerminalNode *Comma();
    antlr4::tree::TerminalNode *RightParen();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NativeContext* native();

  class  AssignsContext : public antlr4::ParserRuleContext {
  public:
    AssignsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Assign();
    antlr4::tree::TerminalNode *ColonAssign();
    antlr4::tree::TerminalNode *DivAssign();
    antlr4::tree::TerminalNode *ModAssign();
    antlr4::tree::TerminalNode *PlusAssign();
    antlr4::tree::TerminalNode *MinusAssign();
    antlr4::tree::TerminalNode *StarAssign();
    antlr4::tree::TerminalNode *XorAssign();
    antlr4::tree::TerminalNode *AndAssign();
    antlr4::tree::TerminalNode *OrAssign();
    antlr4::tree::TerminalNode *LeftShiftAssign();
    antlr4::tree::TerminalNode *RightShiftAssign();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignsContext* assigns();

  class  AllOperatorsContext : public antlr4::ParserRuleContext {
  public:
    AllOperatorsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Arrow();
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();
    antlr4::tree::TerminalNode *Star();
    antlr4::tree::TerminalNode *Div();
    antlr4::tree::TerminalNode *Mod();
    antlr4::tree::TerminalNode *Caret();
    antlr4::tree::TerminalNode *And();
    antlr4::tree::TerminalNode *Or();
    antlr4::tree::TerminalNode *Tilde();
    antlr4::tree::TerminalNode *Not();
    antlr4::tree::TerminalNode *Assign();
    antlr4::tree::TerminalNode *ColonAssign();
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *PlusAssign();
    antlr4::tree::TerminalNode *MinusAssign();
    antlr4::tree::TerminalNode *StarAssign();
    antlr4::tree::TerminalNode *DivAssign();
    antlr4::tree::TerminalNode *ModAssign();
    antlr4::tree::TerminalNode *XorAssign();
    antlr4::tree::TerminalNode *AndAssign();
    antlr4::tree::TerminalNode *OrAssign();
    antlr4::tree::TerminalNode *LeftShiftAssign();
    antlr4::tree::TerminalNode *RightShiftAssign();
    antlr4::tree::TerminalNode *Equal();
    antlr4::tree::TerminalNode *NotEqual();
    antlr4::tree::TerminalNode *LessEqual();
    antlr4::tree::TerminalNode *GreaterEqual();
    antlr4::tree::TerminalNode *AndAnd();
    antlr4::tree::TerminalNode *OrOr();
    antlr4::tree::TerminalNode *PlusPlus();
    antlr4::tree::TerminalNode *MinusMinus();
    antlr4::tree::TerminalNode *Colon();
    antlr4::tree::TerminalNode *Dot();
    antlr4::tree::TerminalNode *LeftShift();
    antlr4::tree::TerminalNode *RightShift();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AllOperatorsContext* allOperators();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionsSempred(ExpressionsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

