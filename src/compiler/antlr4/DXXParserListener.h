
// Generated from templates/DXXParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DXXParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by DXXParser.
 */
class  DXXParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStat(DXXParser::StatContext *ctx) = 0;
  virtual void exitStat(DXXParser::StatContext *ctx) = 0;

  virtual void enterImportExpr(DXXParser::ImportExprContext *ctx) = 0;
  virtual void exitImportExpr(DXXParser::ImportExprContext *ctx) = 0;

  virtual void enterFunctionExpr(DXXParser::FunctionExprContext *ctx) = 0;
  virtual void exitFunctionExpr(DXXParser::FunctionExprContext *ctx) = 0;

  virtual void enterFunctionDefineExpr(DXXParser::FunctionDefineExprContext *ctx) = 0;
  virtual void exitFunctionDefineExpr(DXXParser::FunctionDefineExprContext *ctx) = 0;

  virtual void enterVarDefineExpr(DXXParser::VarDefineExprContext *ctx) = 0;
  virtual void exitVarDefineExpr(DXXParser::VarDefineExprContext *ctx) = 0;

  virtual void enterClassExpr(DXXParser::ClassExprContext *ctx) = 0;
  virtual void exitClassExpr(DXXParser::ClassExprContext *ctx) = 0;

  virtual void enterInterfaceExpr(DXXParser::InterfaceExprContext *ctx) = 0;
  virtual void exitInterfaceExpr(DXXParser::InterfaceExprContext *ctx) = 0;

  virtual void enterGSemiExpr(DXXParser::GSemiExprContext *ctx) = 0;
  virtual void exitGSemiExpr(DXXParser::GSemiExprContext *ctx) = 0;

  virtual void enterNewExpr(DXXParser::NewExprContext *ctx) = 0;
  virtual void exitNewExpr(DXXParser::NewExprContext *ctx) = 0;

  virtual void enterDeleteExpr(DXXParser::DeleteExprContext *ctx) = 0;
  virtual void exitDeleteExpr(DXXParser::DeleteExprContext *ctx) = 0;

  virtual void enterVarDefineExprTag(DXXParser::VarDefineExprTagContext *ctx) = 0;
  virtual void exitVarDefineExprTag(DXXParser::VarDefineExprTagContext *ctx) = 0;

  virtual void enterVarSetExpr(DXXParser::VarSetExprContext *ctx) = 0;
  virtual void exitVarSetExpr(DXXParser::VarSetExprContext *ctx) = 0;

  virtual void enterWithExpr(DXXParser::WithExprContext *ctx) = 0;
  virtual void exitWithExpr(DXXParser::WithExprContext *ctx) = 0;

  virtual void enterWhileLoopExpr(DXXParser::WhileLoopExprContext *ctx) = 0;
  virtual void exitWhileLoopExpr(DXXParser::WhileLoopExprContext *ctx) = 0;

  virtual void enterDoWhileLoopExpr(DXXParser::DoWhileLoopExprContext *ctx) = 0;
  virtual void exitDoWhileLoopExpr(DXXParser::DoWhileLoopExprContext *ctx) = 0;

  virtual void enterForeachLoopExpr(DXXParser::ForeachLoopExprContext *ctx) = 0;
  virtual void exitForeachLoopExpr(DXXParser::ForeachLoopExprContext *ctx) = 0;

  virtual void enterGotoExpr(DXXParser::GotoExprContext *ctx) = 0;
  virtual void exitGotoExpr(DXXParser::GotoExprContext *ctx) = 0;

  virtual void enterGotoLabelDefineExpr(DXXParser::GotoLabelDefineExprContext *ctx) = 0;
  virtual void exitGotoLabelDefineExpr(DXXParser::GotoLabelDefineExprContext *ctx) = 0;

  virtual void enterTryExpr(DXXParser::TryExprContext *ctx) = 0;
  virtual void exitTryExpr(DXXParser::TryExprContext *ctx) = 0;

  virtual void enterThrowExpr(DXXParser::ThrowExprContext *ctx) = 0;
  virtual void exitThrowExpr(DXXParser::ThrowExprContext *ctx) = 0;

  virtual void enterTypedefExprTag(DXXParser::TypedefExprTagContext *ctx) = 0;
  virtual void exitTypedefExprTag(DXXParser::TypedefExprTagContext *ctx) = 0;

  virtual void enterReturnExpr(DXXParser::ReturnExprContext *ctx) = 0;
  virtual void exitReturnExpr(DXXParser::ReturnExprContext *ctx) = 0;

  virtual void enterBreakExpr(DXXParser::BreakExprContext *ctx) = 0;
  virtual void exitBreakExpr(DXXParser::BreakExprContext *ctx) = 0;

  virtual void enterContinueExpr(DXXParser::ContinueExprContext *ctx) = 0;
  virtual void exitContinueExpr(DXXParser::ContinueExprContext *ctx) = 0;

  virtual void enterSemiExpr(DXXParser::SemiExprContext *ctx) = 0;
  virtual void exitSemiExpr(DXXParser::SemiExprContext *ctx) = 0;

  virtual void enterIntegerExpr(DXXParser::IntegerExprContext *ctx) = 0;
  virtual void exitIntegerExpr(DXXParser::IntegerExprContext *ctx) = 0;

  virtual void enterFloatingExpr(DXXParser::FloatingExprContext *ctx) = 0;
  virtual void exitFloatingExpr(DXXParser::FloatingExprContext *ctx) = 0;

  virtual void enterStringExpr(DXXParser::StringExprContext *ctx) = 0;
  virtual void exitStringExpr(DXXParser::StringExprContext *ctx) = 0;

  virtual void enterBooleanExpr(DXXParser::BooleanExprContext *ctx) = 0;
  virtual void exitBooleanExpr(DXXParser::BooleanExprContext *ctx) = 0;

  virtual void enterNullExpr(DXXParser::NullExprContext *ctx) = 0;
  virtual void exitNullExpr(DXXParser::NullExprContext *ctx) = 0;

  virtual void enterOrorExpr(DXXParser::OrorExprContext *ctx) = 0;
  virtual void exitOrorExpr(DXXParser::OrorExprContext *ctx) = 0;

  virtual void enterParens(DXXParser::ParensContext *ctx) = 0;
  virtual void exitParens(DXXParser::ParensContext *ctx) = 0;

  virtual void enterIdExExpr(DXXParser::IdExExprContext *ctx) = 0;
  virtual void exitIdExExpr(DXXParser::IdExExprContext *ctx) = 0;

  virtual void enterTypeExpr(DXXParser::TypeExprContext *ctx) = 0;
  virtual void exitTypeExpr(DXXParser::TypeExprContext *ctx) = 0;

  virtual void enterNotClassExpr(DXXParser::NotClassExprContext *ctx) = 0;
  virtual void exitNotClassExpr(DXXParser::NotClassExprContext *ctx) = 0;

  virtual void enterNegativeExpr(DXXParser::NegativeExprContext *ctx) = 0;
  virtual void exitNegativeExpr(DXXParser::NegativeExprContext *ctx) = 0;

  virtual void enterLeftOrRightShiftExpr(DXXParser::LeftOrRightShiftExprContext *ctx) = 0;
  virtual void exitLeftOrRightShiftExpr(DXXParser::LeftOrRightShiftExprContext *ctx) = 0;

  virtual void enterOrExpr(DXXParser::OrExprContext *ctx) = 0;
  virtual void exitOrExpr(DXXParser::OrExprContext *ctx) = 0;

  virtual void enterPlusClassExpr(DXXParser::PlusClassExprContext *ctx) = 0;
  virtual void exitPlusClassExpr(DXXParser::PlusClassExprContext *ctx) = 0;

  virtual void enterLambdaFunctionExpr(DXXParser::LambdaFunctionExprContext *ctx) = 0;
  virtual void exitLambdaFunctionExpr(DXXParser::LambdaFunctionExprContext *ctx) = 0;

  virtual void enterAndandExpr(DXXParser::AndandExprContext *ctx) = 0;
  virtual void exitAndandExpr(DXXParser::AndandExprContext *ctx) = 0;

  virtual void enterEqualOrNotEqualExpr(DXXParser::EqualOrNotEqualExprContext *ctx) = 0;
  virtual void exitEqualOrNotEqualExpr(DXXParser::EqualOrNotEqualExprContext *ctx) = 0;

  virtual void enterCaretExpr(DXXParser::CaretExprContext *ctx) = 0;
  virtual void exitCaretExpr(DXXParser::CaretExprContext *ctx) = 0;

  virtual void enterStarClassExpr(DXXParser::StarClassExprContext *ctx) = 0;
  virtual void exitStarClassExpr(DXXParser::StarClassExprContext *ctx) = 0;

  virtual void enterFunctionCallExpr(DXXParser::FunctionCallExprContext *ctx) = 0;
  virtual void exitFunctionCallExpr(DXXParser::FunctionCallExprContext *ctx) = 0;

  virtual void enterLessClassExpr(DXXParser::LessClassExprContext *ctx) = 0;
  virtual void exitLessClassExpr(DXXParser::LessClassExprContext *ctx) = 0;

  virtual void enterConstantExpr(DXXParser::ConstantExprContext *ctx) = 0;
  virtual void exitConstantExpr(DXXParser::ConstantExprContext *ctx) = 0;

  virtual void enterAndExpr(DXXParser::AndExprContext *ctx) = 0;
  virtual void exitAndExpr(DXXParser::AndExprContext *ctx) = 0;

  virtual void enterBoolean(DXXParser::BooleanContext *ctx) = 0;
  virtual void exitBoolean(DXXParser::BooleanContext *ctx) = 0;

  virtual void enterNegative(DXXParser::NegativeContext *ctx) = 0;
  virtual void exitNegative(DXXParser::NegativeContext *ctx) = 0;

  virtual void enterSemi(DXXParser::SemiContext *ctx) = 0;
  virtual void exitSemi(DXXParser::SemiContext *ctx) = 0;

  virtual void enterImportLib(DXXParser::ImportLibContext *ctx) = 0;
  virtual void exitImportLib(DXXParser::ImportLibContext *ctx) = 0;

  virtual void enterNew(DXXParser::NewContext *ctx) = 0;
  virtual void exitNew(DXXParser::NewContext *ctx) = 0;

  virtual void enterDelete(DXXParser::DeleteContext *ctx) = 0;
  virtual void exitDelete(DXXParser::DeleteContext *ctx) = 0;

  virtual void enterTypedef(DXXParser::TypedefContext *ctx) = 0;
  virtual void exitTypedef(DXXParser::TypedefContext *ctx) = 0;

  virtual void enterFunctionDefine(DXXParser::FunctionDefineContext *ctx) = 0;
  virtual void exitFunctionDefine(DXXParser::FunctionDefineContext *ctx) = 0;

  virtual void enterFunction(DXXParser::FunctionContext *ctx) = 0;
  virtual void exitFunction(DXXParser::FunctionContext *ctx) = 0;

  virtual void enterReturn(DXXParser::ReturnContext *ctx) = 0;
  virtual void exitReturn(DXXParser::ReturnContext *ctx) = 0;

  virtual void enterLambdaFunction(DXXParser::LambdaFunctionContext *ctx) = 0;
  virtual void exitLambdaFunction(DXXParser::LambdaFunctionContext *ctx) = 0;

  virtual void enterFunctionHead(DXXParser::FunctionHeadContext *ctx) = 0;
  virtual void exitFunctionHead(DXXParser::FunctionHeadContext *ctx) = 0;

  virtual void enterFunctionCall(DXXParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(DXXParser::FunctionCallContext *ctx) = 0;

  virtual void enterParamList(DXXParser::ParamListContext *ctx) = 0;
  virtual void exitParamList(DXXParser::ParamListContext *ctx) = 0;

  virtual void enterCallParamList(DXXParser::CallParamListContext *ctx) = 0;
  virtual void exitCallParamList(DXXParser::CallParamListContext *ctx) = 0;

  virtual void enterThrowtable(DXXParser::ThrowtableContext *ctx) = 0;
  virtual void exitThrowtable(DXXParser::ThrowtableContext *ctx) = 0;

  virtual void enterVarDefine(DXXParser::VarDefineContext *ctx) = 0;
  virtual void exitVarDefine(DXXParser::VarDefineContext *ctx) = 0;

  virtual void enterVarDefineNoSet(DXXParser::VarDefineNoSetContext *ctx) = 0;
  virtual void exitVarDefineNoSet(DXXParser::VarDefineNoSetContext *ctx) = 0;

  virtual void enterVarSet(DXXParser::VarSetContext *ctx) = 0;
  virtual void exitVarSet(DXXParser::VarSetContext *ctx) = 0;

  virtual void enterWithStatement(DXXParser::WithStatementContext *ctx) = 0;
  virtual void exitWithStatement(DXXParser::WithStatementContext *ctx) = 0;

  virtual void enterWithIf(DXXParser::WithIfContext *ctx) = 0;
  virtual void exitWithIf(DXXParser::WithIfContext *ctx) = 0;

  virtual void enterWithIfExtends(DXXParser::WithIfExtendsContext *ctx) = 0;
  virtual void exitWithIfExtends(DXXParser::WithIfExtendsContext *ctx) = 0;

  virtual void enterWithIfExtendsSub(DXXParser::WithIfExtendsSubContext *ctx) = 0;
  virtual void exitWithIfExtendsSub(DXXParser::WithIfExtendsSubContext *ctx) = 0;

  virtual void enterWithSwitchStatement(DXXParser::WithSwitchStatementContext *ctx) = 0;
  virtual void exitWithSwitchStatement(DXXParser::WithSwitchStatementContext *ctx) = 0;

  virtual void enterCaseStatement(DXXParser::CaseStatementContext *ctx) = 0;
  virtual void exitCaseStatement(DXXParser::CaseStatementContext *ctx) = 0;

  virtual void enterDefaultStatement(DXXParser::DefaultStatementContext *ctx) = 0;
  virtual void exitDefaultStatement(DXXParser::DefaultStatementContext *ctx) = 0;

  virtual void enterWhileLoop(DXXParser::WhileLoopContext *ctx) = 0;
  virtual void exitWhileLoop(DXXParser::WhileLoopContext *ctx) = 0;

  virtual void enterDoWhileLoop(DXXParser::DoWhileLoopContext *ctx) = 0;
  virtual void exitDoWhileLoop(DXXParser::DoWhileLoopContext *ctx) = 0;

  virtual void enterForeachLoop(DXXParser::ForeachLoopContext *ctx) = 0;
  virtual void exitForeachLoop(DXXParser::ForeachLoopContext *ctx) = 0;

  virtual void enterGoto(DXXParser::GotoContext *ctx) = 0;
  virtual void exitGoto(DXXParser::GotoContext *ctx) = 0;

  virtual void enterGotoLabelDefine(DXXParser::GotoLabelDefineContext *ctx) = 0;
  virtual void exitGotoLabelDefine(DXXParser::GotoLabelDefineContext *ctx) = 0;

  virtual void enterEnum(DXXParser::EnumContext *ctx) = 0;
  virtual void exitEnum(DXXParser::EnumContext *ctx) = 0;

  virtual void enterEnumSub(DXXParser::EnumSubContext *ctx) = 0;
  virtual void exitEnumSub(DXXParser::EnumSubContext *ctx) = 0;

  virtual void enterClass(DXXParser::ClassContext *ctx) = 0;
  virtual void exitClass(DXXParser::ClassContext *ctx) = 0;

  virtual void enterInterface(DXXParser::InterfaceContext *ctx) = 0;
  virtual void exitInterface(DXXParser::InterfaceContext *ctx) = 0;

  virtual void enterClassMethods(DXXParser::ClassMethodsContext *ctx) = 0;
  virtual void exitClassMethods(DXXParser::ClassMethodsContext *ctx) = 0;

  virtual void enterInterfaceMethods(DXXParser::InterfaceMethodsContext *ctx) = 0;
  virtual void exitInterfaceMethods(DXXParser::InterfaceMethodsContext *ctx) = 0;

  virtual void enterOperatorDefine(DXXParser::OperatorDefineContext *ctx) = 0;
  virtual void exitOperatorDefine(DXXParser::OperatorDefineContext *ctx) = 0;

  virtual void enterBlock(DXXParser::BlockContext *ctx) = 0;
  virtual void exitBlock(DXXParser::BlockContext *ctx) = 0;

  virtual void enterTry(DXXParser::TryContext *ctx) = 0;
  virtual void exitTry(DXXParser::TryContext *ctx) = 0;

  virtual void enterThrow(DXXParser::ThrowContext *ctx) = 0;
  virtual void exitThrow(DXXParser::ThrowContext *ctx) = 0;

  virtual void enterTheType(DXXParser::TheTypeContext *ctx) = 0;
  virtual void exitTheType(DXXParser::TheTypeContext *ctx) = 0;

  virtual void enterTheTypeSub(DXXParser::TheTypeSubContext *ctx) = 0;
  virtual void exitTheTypeSub(DXXParser::TheTypeSubContext *ctx) = 0;

  virtual void enterIdEx(DXXParser::IdExContext *ctx) = 0;
  virtual void exitIdEx(DXXParser::IdExContext *ctx) = 0;

  virtual void enterInfo(DXXParser::InfoContext *ctx) = 0;
  virtual void exitInfo(DXXParser::InfoContext *ctx) = 0;

  virtual void enterNative(DXXParser::NativeContext *ctx) = 0;
  virtual void exitNative(DXXParser::NativeContext *ctx) = 0;

  virtual void enterAssigns(DXXParser::AssignsContext *ctx) = 0;
  virtual void exitAssigns(DXXParser::AssignsContext *ctx) = 0;

  virtual void enterAllOperators(DXXParser::AllOperatorsContext *ctx) = 0;
  virtual void exitAllOperators(DXXParser::AllOperatorsContext *ctx) = 0;


};

