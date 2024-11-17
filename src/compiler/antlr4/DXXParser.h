
// Generated from templates/DXXParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  DXXParser : public antlr4::Parser {
public:
  enum {
    Asm = 1, Bool = 2, Break = 3, Case = 4, Catch = 5, Char = 6, Class = 7,
    Compiletime = 8, Continue = 9, Default = 10, Delete = 11, Do = 12, Enum = 13,
    Extends = 14, False = 15, Final = 16, Finally = 17, Float = 18, Foreach = 19,
    Goto = 20, If = 21, Import = 22, Inline = 23, Int = 24, Implements = 25,
    Interface_ = 26, Long = 27, Native = 28, New = 29, Null = 30, Object = 31,
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

  enum {
    RuleMain = 0, RuleGExpressions = 1, RuleExpressions = 2, RuleConstant = 3,
    RuleData = 4, RuleBoolean = 5, RuleNegative = 6, RuleSemi = 7, RuleImportLib = 8,
    RuleNew = 9, RuleDelete = 10, RuleTypedef = 11, RuleFunction = 12, RuleReturn = 13,
    RuleLambdaFunction = 14, RuleFunctionHead = 15, RuleFunctionCall = 16,
    RuleParamList = 17, RuleCallParamList = 18, RuleThrowtable = 19, RuleVarDefine = 20,
    RuleVarDefineNoSet = 21, RuleVarSet = 22, RuleWithStatement = 23, RuleWithIf = 24,
    RuleWithIfExtends = 25, RuleWithIfExtendsSub = 26, RuleWithSwitchStatement = 27,
    RuleCaseStatement = 28, RuleDefaultStatement = 29, RuleWhileLoop = 30,
    RuleDoWhileLoop = 31, RuleForeachLoop = 32, RuleGoto = 33, RuleGotoLabelDefine = 34,
    RuleEnum = 35, RuleEnumSub = 36, RuleClass = 37, RuleInterface_ = 38,
    RuleClassMethods = 39, RuleInterfaceMethods = 40, RuleOperatorDefine = 41,
    RuleBlock = 42, RuleTry = 43, RuleThrow = 44, RuleTheType = 45, RuleTheTypeSub = 46,
    RuleIdEx = 47, RuleInfo = 48, RuleNative = 49, RuleAssigns = 50, RuleAllOperators = 51
  };

  explicit DXXParser(antlr4::TokenStream *input);

  DXXParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~DXXParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class MainContext;
  class GExpressionsContext;
  class ExpressionsContext;
  class ConstantContext;
  class DataContext;
  class BooleanContext;
  class NegativeContext;
  class SemiContext;
  class ImportLibContext;
  class NewContext;
  class DeleteContext;
  class TypedefContext;
  class FunctionContext;
  class ReturnContext;
  class LambdaFunctionContext;
  class FunctionHeadContext;
  class FunctionCallContext;
  class ParamListContext;
  class CallParamListContext;
  class ThrowtableContext;
  class VarDefineContext;
  class VarDefineNoSetContext;
  class VarSetContext;
  class WithStatementContext;
  class WithIfContext;
  class WithIfExtendsContext;
  class WithIfExtendsSubContext;
  class WithSwitchStatementContext;
  class CaseStatementContext;
  class DefaultStatementContext;
  class WhileLoopContext;
  class DoWhileLoopContext;
  class ForeachLoopContext;
  class GotoContext;
  class GotoLabelDefineContext;
  class EnumContext;
  class EnumSubContext;
  class ClassContext;
  class Interface_Context;
  class ClassMethodsContext;
  class InterfaceMethodsContext;
  class OperatorDefineContext;
  class BlockContext;
  class TryContext;
  class ThrowContext;
  class TheTypeContext;
  class TheTypeSubContext;
  class IdExContext;
  class InfoContext;
  class NativeContext;
  class AssignsContext;
  class AllOperatorsContext;

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<GExpressionsContext *> gExpressions();
    GExpressionsContext* gExpressions(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  MainContext* main();

  class  GExpressionsContext : public antlr4::ParserRuleContext {
  public:
    GExpressionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    GExpressionsContext() = default;
    void copyFrom(GExpressionsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;


  };

  class  GSemiExprContext : public GExpressionsContext {
  public:
    GSemiExprContext(GExpressionsContext *ctx);

    SemiContext *semi();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InterfaceExprContext : public GExpressionsContext {
  public:
    InterfaceExprContext(GExpressionsContext *ctx);

    Interface_Context *interface_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypedefExprContext : public GExpressionsContext {
  public:
    TypedefExprContext(GExpressionsContext *ctx);

    TypedefContext *typedef_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ClassExprContext : public GExpressionsContext {
  public:
    ClassExprContext(GExpressionsContext *ctx);

    ClassContext *class_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EnumExprContext : public GExpressionsContext {
  public:
    EnumExprContext(GExpressionsContext *ctx);

    EnumContext *enum_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ImportExprContext : public GExpressionsContext {
  public:
    ImportExprContext(GExpressionsContext *ctx);

    ImportLibContext *importLib();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OperatorDefineExprContext : public GExpressionsContext {
  public:
    OperatorDefineExprContext(GExpressionsContext *ctx);

    OperatorDefineContext *operatorDefine();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarDefineExprContext : public GExpressionsContext {
  public:
    VarDefineExprContext(GExpressionsContext *ctx);

    VarDefineContext *varDefine();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionExprContext : public GExpressionsContext {
  public:
    FunctionExprContext(GExpressionsContext *ctx);

    FunctionContext *function();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  GExpressionsContext* gExpressions();

  class  ExpressionsContext : public antlr4::ParserRuleContext {
  public:
    ExpressionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    ExpressionsContext() = default;
    void copyFrom(ExpressionsContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;


  };

  class  NewExprContext : public ExpressionsContext {
  public:
    NewExprContext(ExpressionsContext *ctx);

    NewContext *new_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarSetExprContext : public ExpressionsContext {
  public:
    VarSetExprContext(ExpressionsContext *ctx);

    VarSetContext *varSet();

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

  class  TypedefExprTagContext : public ExpressionsContext {
  public:
    TypedefExprTagContext(ExpressionsContext *ctx);

    TypedefContext *typedef_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DoWhileLoopExprContext : public ExpressionsContext {
  public:
    DoWhileLoopExprContext(ExpressionsContext *ctx);

    DoWhileLoopContext *doWhileLoop();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GotoExprContext : public ExpressionsContext {
  public:
    GotoExprContext(ExpressionsContext *ctx);

    GotoContext *goto_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeleteExprContext : public ExpressionsContext {
  public:
    DeleteExprContext(ExpressionsContext *ctx);

    DeleteContext *delete_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SemiExprContext : public ExpressionsContext {
  public:
    SemiExprContext(ExpressionsContext *ctx);

    SemiContext *semi();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ReturnExprContext : public ExpressionsContext {
  public:
    ReturnExprContext(ExpressionsContext *ctx);

    ReturnContext *return_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IncDecExprContext : public ExpressionsContext {
  public:
    IncDecExprContext(ExpressionsContext *ctx);

    DataContext *data();
    antlr4::tree::TerminalNode *PlusPlus();
    antlr4::tree::TerminalNode *MinusMinus();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BreakExprContext : public ExpressionsContext {
  public:
    BreakExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *Break();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ContinueExprContext : public ExpressionsContext {
  public:
    ContinueExprContext(ExpressionsContext *ctx);

    antlr4::tree::TerminalNode *Continue();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallExprTagContext : public ExpressionsContext {
  public:
    FunctionCallExprTagContext(ExpressionsContext *ctx);

    FunctionCallContext *functionCall();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarDefineExprTagContext : public ExpressionsContext {
  public:
    VarDefineExprTagContext(ExpressionsContext *ctx);

    VarDefineContext *varDefine();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileLoopExprContext : public ExpressionsContext {
  public:
    WhileLoopExprContext(ExpressionsContext *ctx);

    WhileLoopContext *whileLoop();

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

  class  WithExprContext : public ExpressionsContext {
  public:
    WithExprContext(ExpressionsContext *ctx);

    WithStatementContext *withStatement();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionsContext* expressions();

  class  ConstantContext : public antlr4::ParserRuleContext {
  public:
    ConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    ConstantContext() = default;
    void copyFrom(ConstantContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;


  };

  class  StringExprContext : public ConstantContext {
  public:
    StringExprContext(ConstantContext *ctx);

    antlr4::tree::TerminalNode *StringData();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntegerExprContext : public ConstantContext {
  public:
    IntegerExprContext(ConstantContext *ctx);

    antlr4::tree::TerminalNode *IntegerData();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NullExprContext : public ConstantContext {
  public:
    NullExprContext(ConstantContext *ctx);

    antlr4::tree::TerminalNode *Null();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BooleanExprContext : public ConstantContext {
  public:
    BooleanExprContext(ConstantContext *ctx);

    BooleanContext *boolean();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatingExprContext : public ConstantContext {
  public:
    FloatingExprContext(ConstantContext *ctx);

    antlr4::tree::TerminalNode *FloatingNumberData();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ConstantContext* constant();

  class  DataContext : public antlr4::ParserRuleContext {
  public:
    DataContext(antlr4::ParserRuleContext *parent, size_t invokingState);

    DataContext() = default;
    void copyFrom(DataContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;


  };

  class  NewExpr_Context : public DataContext {
  public:
    NewExpr_Context(DataContext *ctx);

    NewContext *new_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrorExprContext : public DataContext {
  public:
    OrorExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *OrOr();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParensContext : public DataContext {
  public:
    ParensContext(DataContext *ctx);

    antlr4::tree::TerminalNode *LeftParen();
    DataContext *data();
    antlr4::tree::TerminalNode *RightParen();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IdExExprContext : public DataContext {
  public:
    IdExExprContext(DataContext *ctx);

    IdExContext *idEx();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeExprContext : public DataContext {
  public:
    TypeExprContext(DataContext *ctx);

    TheTypeContext *theType();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotClassExprContext : public DataContext {
  public:
    NotClassExprContext(DataContext *ctx);

    DataContext *data();
    antlr4::tree::TerminalNode *Not();
    antlr4::tree::TerminalNode *Tilde();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegativeExprContext : public DataContext {
  public:
    NegativeExprContext(DataContext *ctx);

    NegativeContext *negative();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LeftOrRightShiftExprContext : public DataContext {
  public:
    LeftOrRightShiftExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *LeftShift();
    antlr4::tree::TerminalNode *RightShift();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OrExprContext : public DataContext {
  public:
    OrExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *Or();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DeleteExpr_Context : public DataContext {
  public:
    DeleteExpr_Context(DataContext *ctx);

    DeleteContext *delete_();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PlusClassExprContext : public DataContext {
  public:
    PlusClassExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *Plus();
    antlr4::tree::TerminalNode *Minus();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LambdaFunctionExprContext : public DataContext {
  public:
    LambdaFunctionExprContext(DataContext *ctx);

    LambdaFunctionContext *lambdaFunction();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndandExprContext : public DataContext {
  public:
    AndandExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *AndAnd();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  EqualOrNotEqualExprContext : public DataContext {
  public:
    EqualOrNotEqualExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *Equal();
    antlr4::tree::TerminalNode *NotEqual();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CaretExprContext : public DataContext {
  public:
    CaretExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *Caret();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StarClassExprContext : public DataContext {
  public:
    StarClassExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *Star();
    antlr4::tree::TerminalNode *Div();
    antlr4::tree::TerminalNode *Mod();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallExprContext : public DataContext {
  public:
    FunctionCallExprContext(DataContext *ctx);

    FunctionCallContext *functionCall();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LessClassExprContext : public DataContext {
  public:
    LessClassExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *Less();
    antlr4::tree::TerminalNode *Greater();
    antlr4::tree::TerminalNode *LessEqual();
    antlr4::tree::TerminalNode *GreaterEqual();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ConstantExprContext : public DataContext {
  public:
    ConstantExprContext(DataContext *ctx);

    ConstantContext *constant();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AndExprContext : public DataContext {
  public:
    AndExprContext(DataContext *ctx);

    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    antlr4::tree::TerminalNode *And();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DataContext* data();
  DataContext* data(int precedence);
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
    DataContext *data();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  NegativeContext* negative();

  class  SemiContext : public antlr4::ParserRuleContext {
  public:
    SemiContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Semi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  SemiContext* semi();

  class  ImportLibContext : public antlr4::ParserRuleContext {
  public:
    ImportLibContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Import();
    IdExContext *idEx();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  ImportLibContext* importLib();

  class  NewContext : public antlr4::ParserRuleContext {
  public:
    NewContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *New();
    TheTypeContext *theType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  NewContext* new_();

  class  DeleteContext : public antlr4::ParserRuleContext {
  public:
    DeleteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Delete();
    DataContext *data();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  DeleteContext* delete_();

  class  TypedefContext : public antlr4::ParserRuleContext {
  public:
    TypedefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Using();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Assign();
    TheTypeContext *theType();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  TypedefContext* typedef_();

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
    DataContext *data();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  ReturnContext* return_();

  class  LambdaFunctionContext : public antlr4::ParserRuleContext {
  public:
    LambdaFunctionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    BlockContext *block();
    ParamListContext *paramList();


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
    std::vector<InfoContext *> info();
    InfoContext* info(size_t i);
    ParamListContext *paramList();
    ThrowtableContext *throwtable();


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
    std::vector<DataContext *> data();
    DataContext* data(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  CallParamListContext* callParamList();

  class  ThrowtableContext : public antlr4::ParserRuleContext {
  public:
    ThrowtableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Throw();
    std::vector<IdExContext *> idEx();
    IdExContext* idEx(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  ThrowtableContext* throwtable();

  class  VarDefineContext : public antlr4::ParserRuleContext {
  public:
    VarDefineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Colon();
    TheTypeContext *theType();
    std::vector<InfoContext *> info();
    InfoContext* info(size_t i);
    AssignsContext *assigns();
    DataContext *data();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  VarDefineContext* varDefine();

  class  VarDefineNoSetContext : public antlr4::ParserRuleContext {
  public:
    VarDefineNoSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Colon();
    TheTypeContext *theType();
    std::vector<InfoContext *> info();
    InfoContext* info(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  VarDefineNoSetContext* varDefineNoSet();

  class  VarSetContext : public antlr4::ParserRuleContext {
  public:
    VarSetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IdExContext *idEx();
    AssignsContext *assigns();
    DataContext *data();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  VarSetContext* varSet();

  class  WithStatementContext : public antlr4::ParserRuleContext {
  public:
    WithStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    WithIfContext *withIf();
    WithIfExtendsContext *withIfExtends();
    WithSwitchStatementContext *withSwitchStatement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  WithStatementContext* withStatement();

  class  WithIfContext : public antlr4::ParserRuleContext {
  public:
    WithIfContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *With();
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *LeftParen();
    DataContext *data();
    antlr4::tree::TerminalNode *RightParen();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  WithIfContext* withIf();

  class  WithIfExtendsContext : public antlr4::ParserRuleContext {
  public:
    WithIfExtendsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *With();
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<WithIfExtendsSubContext *> withIfExtendsSub();
    WithIfExtendsSubContext* withIfExtendsSub(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  WithIfExtendsContext* withIfExtends();

  class  WithIfExtendsSubContext : public antlr4::ParserRuleContext {
  public:
    WithIfExtendsSubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DataContext *data();
    antlr4::tree::TerminalNode *Arrow();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  WithIfExtendsSubContext* withIfExtendsSub();

  class  WithSwitchStatementContext : public antlr4::ParserRuleContext {
  public:
    WithSwitchStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *With();
    antlr4::tree::TerminalNode *LeftParen();
    DataContext *data();
    antlr4::tree::TerminalNode *RightParen();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<CaseStatementContext *> caseStatement();
    CaseStatementContext* caseStatement(size_t i);
    DefaultStatementContext *defaultStatement();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  WithSwitchStatementContext* withSwitchStatement();

  class  CaseStatementContext : public antlr4::ParserRuleContext {
  public:
    CaseStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantContext *constant();
    antlr4::tree::TerminalNode *Arrow();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  CaseStatementContext* caseStatement();

  class  DefaultStatementContext : public antlr4::ParserRuleContext {
  public:
    DefaultStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Default();
    antlr4::tree::TerminalNode *Arrow();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  DefaultStatementContext* defaultStatement();

  class  WhileLoopContext : public antlr4::ParserRuleContext {
  public:
    WhileLoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *LeftParen();
    DataContext *data();
    antlr4::tree::TerminalNode *RightParen();
    BlockContext *block();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  WhileLoopContext* whileLoop();

  class  DoWhileLoopContext : public antlr4::ParserRuleContext {
  public:
    DoWhileLoopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Do();
    BlockContext *block();
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *LeftParen();
    DataContext *data();
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
    DataContext *data();
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
    std::vector<EnumSubContext *> enumSub();
    EnumSubContext* enumSub(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  EnumContext* enum_();

  class  EnumSubContext : public antlr4::ParserRuleContext {
  public:
    EnumSubContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *Assign();
    antlr4::tree::TerminalNode *IntegerData();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  EnumSubContext* enumSub();

  class  ClassContext : public antlr4::ParserRuleContext {
  public:
    ClassContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
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
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  ClassContext* class_();

  class  Interface_Context : public antlr4::ParserRuleContext {
  public:
    Interface_Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Interface_();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    antlr4::tree::TerminalNode *Implements();
    std::vector<InterfaceMethodsContext *> interfaceMethods();
    InterfaceMethodsContext* interfaceMethods(size_t i);
    std::vector<IdExContext *> idEx();
    IdExContext* idEx(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  Interface_Context* interface_();

  class  ClassMethodsContext : public antlr4::ParserRuleContext {
  public:
    ClassMethodsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ClassContext *class_();
    Interface_Context *interface_();
    FunctionContext *function();
    VarDefineContext *varDefine();
    SemiContext *semi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  ClassMethodsContext* classMethods();

  class  InterfaceMethodsContext : public antlr4::ParserRuleContext {
  public:
    InterfaceMethodsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionContext *function();
    VarDefineNoSetContext *varDefineNoSet();
    Interface_Context *interface_();
    SemiContext *semi();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  InterfaceMethodsContext* interfaceMethods();

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

  class  TryContext : public antlr4::ParserRuleContext {
  public:
    TryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Try();
    std::vector<BlockContext *> block();
    BlockContext* block(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Catch();
    antlr4::tree::TerminalNode* Catch(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LeftParen();
    antlr4::tree::TerminalNode* LeftParen(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightParen();
    antlr4::tree::TerminalNode* RightParen(size_t i);
    antlr4::tree::TerminalNode *Finally();
    std::vector<VarDefineContext *> varDefine();
    VarDefineContext* varDefine(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Ellipsis();
    antlr4::tree::TerminalNode* Ellipsis(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;

  };

  TryContext* try_();

  class  ThrowContext : public antlr4::ParserRuleContext {
  public:
    ThrowContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Throw();
    IdExContext *idEx();
    FunctionCallContext *functionCall();


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
    antlr4::tree::TerminalNode *Type();
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
    antlr4::tree::TerminalNode *Compiletime();
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

  bool dataSempred(DataContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

