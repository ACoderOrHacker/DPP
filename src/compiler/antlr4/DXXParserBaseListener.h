
// Generated from templates/DXXParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DXXParserListener.h"


/**
 * This class provides an empty implementation of DXXParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  DXXParserBaseListener : public DXXParserListener {
public:

  virtual void enterStat(DXXParser::StatContext * /*ctx*/) override { }
  virtual void exitStat(DXXParser::StatContext * /*ctx*/) override { }

  virtual void enterImportExpr(DXXParser::ImportExprContext * /*ctx*/) override { }
  virtual void exitImportExpr(DXXParser::ImportExprContext * /*ctx*/) override { }

  virtual void enterFunctionExpr(DXXParser::FunctionExprContext * /*ctx*/) override { }
  virtual void exitFunctionExpr(DXXParser::FunctionExprContext * /*ctx*/) override { }

  virtual void enterFunctionDefineExpr(DXXParser::FunctionDefineExprContext * /*ctx*/) override { }
  virtual void exitFunctionDefineExpr(DXXParser::FunctionDefineExprContext * /*ctx*/) override { }

  virtual void enterVarDefineExpr(DXXParser::VarDefineExprContext * /*ctx*/) override { }
  virtual void exitVarDefineExpr(DXXParser::VarDefineExprContext * /*ctx*/) override { }

  virtual void enterClassExpr(DXXParser::ClassExprContext * /*ctx*/) override { }
  virtual void exitClassExpr(DXXParser::ClassExprContext * /*ctx*/) override { }

  virtual void enterInterfaceExpr(DXXParser::InterfaceExprContext * /*ctx*/) override { }
  virtual void exitInterfaceExpr(DXXParser::InterfaceExprContext * /*ctx*/) override { }

  virtual void enterGSemiExpr(DXXParser::GSemiExprContext * /*ctx*/) override { }
  virtual void exitGSemiExpr(DXXParser::GSemiExprContext * /*ctx*/) override { }

  virtual void enterNewExpr(DXXParser::NewExprContext * /*ctx*/) override { }
  virtual void exitNewExpr(DXXParser::NewExprContext * /*ctx*/) override { }

  virtual void enterDeleteExpr(DXXParser::DeleteExprContext * /*ctx*/) override { }
  virtual void exitDeleteExpr(DXXParser::DeleteExprContext * /*ctx*/) override { }

  virtual void enterVarDefineExprTag(DXXParser::VarDefineExprTagContext * /*ctx*/) override { }
  virtual void exitVarDefineExprTag(DXXParser::VarDefineExprTagContext * /*ctx*/) override { }

  virtual void enterVarSetExpr(DXXParser::VarSetExprContext * /*ctx*/) override { }
  virtual void exitVarSetExpr(DXXParser::VarSetExprContext * /*ctx*/) override { }

  virtual void enterWithExpr(DXXParser::WithExprContext * /*ctx*/) override { }
  virtual void exitWithExpr(DXXParser::WithExprContext * /*ctx*/) override { }

  virtual void enterWhileLoopExpr(DXXParser::WhileLoopExprContext * /*ctx*/) override { }
  virtual void exitWhileLoopExpr(DXXParser::WhileLoopExprContext * /*ctx*/) override { }

  virtual void enterDoWhileLoopExpr(DXXParser::DoWhileLoopExprContext * /*ctx*/) override { }
  virtual void exitDoWhileLoopExpr(DXXParser::DoWhileLoopExprContext * /*ctx*/) override { }

  virtual void enterForeachLoopExpr(DXXParser::ForeachLoopExprContext * /*ctx*/) override { }
  virtual void exitForeachLoopExpr(DXXParser::ForeachLoopExprContext * /*ctx*/) override { }

  virtual void enterGotoExpr(DXXParser::GotoExprContext * /*ctx*/) override { }
  virtual void exitGotoExpr(DXXParser::GotoExprContext * /*ctx*/) override { }

  virtual void enterGotoLabelDefineExpr(DXXParser::GotoLabelDefineExprContext * /*ctx*/) override { }
  virtual void exitGotoLabelDefineExpr(DXXParser::GotoLabelDefineExprContext * /*ctx*/) override { }

  virtual void enterTryExpr(DXXParser::TryExprContext * /*ctx*/) override { }
  virtual void exitTryExpr(DXXParser::TryExprContext * /*ctx*/) override { }

  virtual void enterThrowExpr(DXXParser::ThrowExprContext * /*ctx*/) override { }
  virtual void exitThrowExpr(DXXParser::ThrowExprContext * /*ctx*/) override { }

  virtual void enterTypedefExprTag(DXXParser::TypedefExprTagContext * /*ctx*/) override { }
  virtual void exitTypedefExprTag(DXXParser::TypedefExprTagContext * /*ctx*/) override { }

  virtual void enterReturnExpr(DXXParser::ReturnExprContext * /*ctx*/) override { }
  virtual void exitReturnExpr(DXXParser::ReturnExprContext * /*ctx*/) override { }

  virtual void enterBreakExpr(DXXParser::BreakExprContext * /*ctx*/) override { }
  virtual void exitBreakExpr(DXXParser::BreakExprContext * /*ctx*/) override { }

  virtual void enterContinueExpr(DXXParser::ContinueExprContext * /*ctx*/) override { }
  virtual void exitContinueExpr(DXXParser::ContinueExprContext * /*ctx*/) override { }

  virtual void enterSemiExpr(DXXParser::SemiExprContext * /*ctx*/) override { }
  virtual void exitSemiExpr(DXXParser::SemiExprContext * /*ctx*/) override { }

  virtual void enterIntegerExpr(DXXParser::IntegerExprContext * /*ctx*/) override { }
  virtual void exitIntegerExpr(DXXParser::IntegerExprContext * /*ctx*/) override { }

  virtual void enterFloatingExpr(DXXParser::FloatingExprContext * /*ctx*/) override { }
  virtual void exitFloatingExpr(DXXParser::FloatingExprContext * /*ctx*/) override { }

  virtual void enterStringExpr(DXXParser::StringExprContext * /*ctx*/) override { }
  virtual void exitStringExpr(DXXParser::StringExprContext * /*ctx*/) override { }

  virtual void enterBooleanExpr(DXXParser::BooleanExprContext * /*ctx*/) override { }
  virtual void exitBooleanExpr(DXXParser::BooleanExprContext * /*ctx*/) override { }

  virtual void enterNullExpr(DXXParser::NullExprContext * /*ctx*/) override { }
  virtual void exitNullExpr(DXXParser::NullExprContext * /*ctx*/) override { }

  virtual void enterOrorExpr(DXXParser::OrorExprContext * /*ctx*/) override { }
  virtual void exitOrorExpr(DXXParser::OrorExprContext * /*ctx*/) override { }

  virtual void enterParens(DXXParser::ParensContext * /*ctx*/) override { }
  virtual void exitParens(DXXParser::ParensContext * /*ctx*/) override { }

  virtual void enterIdExExpr(DXXParser::IdExExprContext * /*ctx*/) override { }
  virtual void exitIdExExpr(DXXParser::IdExExprContext * /*ctx*/) override { }

  virtual void enterTypeExpr(DXXParser::TypeExprContext * /*ctx*/) override { }
  virtual void exitTypeExpr(DXXParser::TypeExprContext * /*ctx*/) override { }

  virtual void enterNotClassExpr(DXXParser::NotClassExprContext * /*ctx*/) override { }
  virtual void exitNotClassExpr(DXXParser::NotClassExprContext * /*ctx*/) override { }

  virtual void enterNegativeExpr(DXXParser::NegativeExprContext * /*ctx*/) override { }
  virtual void exitNegativeExpr(DXXParser::NegativeExprContext * /*ctx*/) override { }

  virtual void enterLeftOrRightShiftExpr(DXXParser::LeftOrRightShiftExprContext * /*ctx*/) override { }
  virtual void exitLeftOrRightShiftExpr(DXXParser::LeftOrRightShiftExprContext * /*ctx*/) override { }

  virtual void enterOrExpr(DXXParser::OrExprContext * /*ctx*/) override { }
  virtual void exitOrExpr(DXXParser::OrExprContext * /*ctx*/) override { }

  virtual void enterPlusClassExpr(DXXParser::PlusClassExprContext * /*ctx*/) override { }
  virtual void exitPlusClassExpr(DXXParser::PlusClassExprContext * /*ctx*/) override { }

  virtual void enterLambdaFunctionExpr(DXXParser::LambdaFunctionExprContext * /*ctx*/) override { }
  virtual void exitLambdaFunctionExpr(DXXParser::LambdaFunctionExprContext * /*ctx*/) override { }

  virtual void enterAndandExpr(DXXParser::AndandExprContext * /*ctx*/) override { }
  virtual void exitAndandExpr(DXXParser::AndandExprContext * /*ctx*/) override { }

  virtual void enterEqualOrNotEqualExpr(DXXParser::EqualOrNotEqualExprContext * /*ctx*/) override { }
  virtual void exitEqualOrNotEqualExpr(DXXParser::EqualOrNotEqualExprContext * /*ctx*/) override { }

  virtual void enterCaretExpr(DXXParser::CaretExprContext * /*ctx*/) override { }
  virtual void exitCaretExpr(DXXParser::CaretExprContext * /*ctx*/) override { }

  virtual void enterStarClassExpr(DXXParser::StarClassExprContext * /*ctx*/) override { }
  virtual void exitStarClassExpr(DXXParser::StarClassExprContext * /*ctx*/) override { }

  virtual void enterFunctionCallExpr(DXXParser::FunctionCallExprContext * /*ctx*/) override { }
  virtual void exitFunctionCallExpr(DXXParser::FunctionCallExprContext * /*ctx*/) override { }

  virtual void enterLessClassExpr(DXXParser::LessClassExprContext * /*ctx*/) override { }
  virtual void exitLessClassExpr(DXXParser::LessClassExprContext * /*ctx*/) override { }

  virtual void enterConstantExpr(DXXParser::ConstantExprContext * /*ctx*/) override { }
  virtual void exitConstantExpr(DXXParser::ConstantExprContext * /*ctx*/) override { }

  virtual void enterAndExpr(DXXParser::AndExprContext * /*ctx*/) override { }
  virtual void exitAndExpr(DXXParser::AndExprContext * /*ctx*/) override { }

  virtual void enterBoolean(DXXParser::BooleanContext * /*ctx*/) override { }
  virtual void exitBoolean(DXXParser::BooleanContext * /*ctx*/) override { }

  virtual void enterNegative(DXXParser::NegativeContext * /*ctx*/) override { }
  virtual void exitNegative(DXXParser::NegativeContext * /*ctx*/) override { }

  virtual void enterSemi(DXXParser::SemiContext * /*ctx*/) override { }
  virtual void exitSemi(DXXParser::SemiContext * /*ctx*/) override { }

  virtual void enterImportLib(DXXParser::ImportLibContext * /*ctx*/) override { }
  virtual void exitImportLib(DXXParser::ImportLibContext * /*ctx*/) override { }

  virtual void enterNew(DXXParser::NewContext * /*ctx*/) override { }
  virtual void exitNew(DXXParser::NewContext * /*ctx*/) override { }

  virtual void enterDelete(DXXParser::DeleteContext * /*ctx*/) override { }
  virtual void exitDelete(DXXParser::DeleteContext * /*ctx*/) override { }

  virtual void enterTypedef(DXXParser::TypedefContext * /*ctx*/) override { }
  virtual void exitTypedef(DXXParser::TypedefContext * /*ctx*/) override { }

  virtual void enterFunctionDefine(DXXParser::FunctionDefineContext * /*ctx*/) override { }
  virtual void exitFunctionDefine(DXXParser::FunctionDefineContext * /*ctx*/) override { }

  virtual void enterFunction(DXXParser::FunctionContext * /*ctx*/) override { }
  virtual void exitFunction(DXXParser::FunctionContext * /*ctx*/) override { }

  virtual void enterReturn(DXXParser::ReturnContext * /*ctx*/) override { }
  virtual void exitReturn(DXXParser::ReturnContext * /*ctx*/) override { }

  virtual void enterLambdaFunction(DXXParser::LambdaFunctionContext * /*ctx*/) override { }
  virtual void exitLambdaFunction(DXXParser::LambdaFunctionContext * /*ctx*/) override { }

  virtual void enterFunctionHead(DXXParser::FunctionHeadContext * /*ctx*/) override { }
  virtual void exitFunctionHead(DXXParser::FunctionHeadContext * /*ctx*/) override { }

  virtual void enterFunctionCall(DXXParser::FunctionCallContext * /*ctx*/) override { }
  virtual void exitFunctionCall(DXXParser::FunctionCallContext * /*ctx*/) override { }

  virtual void enterParamList(DXXParser::ParamListContext * /*ctx*/) override { }
  virtual void exitParamList(DXXParser::ParamListContext * /*ctx*/) override { }

  virtual void enterCallParamList(DXXParser::CallParamListContext * /*ctx*/) override { }
  virtual void exitCallParamList(DXXParser::CallParamListContext * /*ctx*/) override { }

  virtual void enterThrowtable(DXXParser::ThrowtableContext * /*ctx*/) override { }
  virtual void exitThrowtable(DXXParser::ThrowtableContext * /*ctx*/) override { }

  virtual void enterVarDefine(DXXParser::VarDefineContext * /*ctx*/) override { }
  virtual void exitVarDefine(DXXParser::VarDefineContext * /*ctx*/) override { }

  virtual void enterVarDefineNoSet(DXXParser::VarDefineNoSetContext * /*ctx*/) override { }
  virtual void exitVarDefineNoSet(DXXParser::VarDefineNoSetContext * /*ctx*/) override { }

  virtual void enterVarSet(DXXParser::VarSetContext * /*ctx*/) override { }
  virtual void exitVarSet(DXXParser::VarSetContext * /*ctx*/) override { }

  virtual void enterWithStatement(DXXParser::WithStatementContext * /*ctx*/) override { }
  virtual void exitWithStatement(DXXParser::WithStatementContext * /*ctx*/) override { }

  virtual void enterWithIf(DXXParser::WithIfContext * /*ctx*/) override { }
  virtual void exitWithIf(DXXParser::WithIfContext * /*ctx*/) override { }

  virtual void enterWithIfExtends(DXXParser::WithIfExtendsContext * /*ctx*/) override { }
  virtual void exitWithIfExtends(DXXParser::WithIfExtendsContext * /*ctx*/) override { }

  virtual void enterWithIfExtendsSub(DXXParser::WithIfExtendsSubContext * /*ctx*/) override { }
  virtual void exitWithIfExtendsSub(DXXParser::WithIfExtendsSubContext * /*ctx*/) override { }

  virtual void enterWithSwitchStatement(DXXParser::WithSwitchStatementContext * /*ctx*/) override { }
  virtual void exitWithSwitchStatement(DXXParser::WithSwitchStatementContext * /*ctx*/) override { }

  virtual void enterCaseStatement(DXXParser::CaseStatementContext * /*ctx*/) override { }
  virtual void exitCaseStatement(DXXParser::CaseStatementContext * /*ctx*/) override { }

  virtual void enterDefaultStatement(DXXParser::DefaultStatementContext * /*ctx*/) override { }
  virtual void exitDefaultStatement(DXXParser::DefaultStatementContext * /*ctx*/) override { }

  virtual void enterWhileLoop(DXXParser::WhileLoopContext * /*ctx*/) override { }
  virtual void exitWhileLoop(DXXParser::WhileLoopContext * /*ctx*/) override { }

  virtual void enterDoWhileLoop(DXXParser::DoWhileLoopContext * /*ctx*/) override { }
  virtual void exitDoWhileLoop(DXXParser::DoWhileLoopContext * /*ctx*/) override { }

  virtual void enterForeachLoop(DXXParser::ForeachLoopContext * /*ctx*/) override { }
  virtual void exitForeachLoop(DXXParser::ForeachLoopContext * /*ctx*/) override { }

  virtual void enterGoto(DXXParser::GotoContext * /*ctx*/) override { }
  virtual void exitGoto(DXXParser::GotoContext * /*ctx*/) override { }

  virtual void enterGotoLabelDefine(DXXParser::GotoLabelDefineContext * /*ctx*/) override { }
  virtual void exitGotoLabelDefine(DXXParser::GotoLabelDefineContext * /*ctx*/) override { }

  virtual void enterEnum(DXXParser::EnumContext * /*ctx*/) override { }
  virtual void exitEnum(DXXParser::EnumContext * /*ctx*/) override { }

  virtual void enterEnumSub(DXXParser::EnumSubContext * /*ctx*/) override { }
  virtual void exitEnumSub(DXXParser::EnumSubContext * /*ctx*/) override { }

  virtual void enterClass(DXXParser::ClassContext * /*ctx*/) override { }
  virtual void exitClass(DXXParser::ClassContext * /*ctx*/) override { }

  virtual void enterInterface(DXXParser::InterfaceContext * /*ctx*/) override { }
  virtual void exitInterface(DXXParser::InterfaceContext * /*ctx*/) override { }

  virtual void enterClassMethods(DXXParser::ClassMethodsContext * /*ctx*/) override { }
  virtual void exitClassMethods(DXXParser::ClassMethodsContext * /*ctx*/) override { }

  virtual void enterInterfaceMethods(DXXParser::InterfaceMethodsContext * /*ctx*/) override { }
  virtual void exitInterfaceMethods(DXXParser::InterfaceMethodsContext * /*ctx*/) override { }

  virtual void enterOperatorDefine(DXXParser::OperatorDefineContext * /*ctx*/) override { }
  virtual void exitOperatorDefine(DXXParser::OperatorDefineContext * /*ctx*/) override { }

  virtual void enterBlock(DXXParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(DXXParser::BlockContext * /*ctx*/) override { }

  virtual void enterTry(DXXParser::TryContext * /*ctx*/) override { }
  virtual void exitTry(DXXParser::TryContext * /*ctx*/) override { }

  virtual void enterThrow(DXXParser::ThrowContext * /*ctx*/) override { }
  virtual void exitThrow(DXXParser::ThrowContext * /*ctx*/) override { }

  virtual void enterTheType(DXXParser::TheTypeContext * /*ctx*/) override { }
  virtual void exitTheType(DXXParser::TheTypeContext * /*ctx*/) override { }

  virtual void enterTheTypeSub(DXXParser::TheTypeSubContext * /*ctx*/) override { }
  virtual void exitTheTypeSub(DXXParser::TheTypeSubContext * /*ctx*/) override { }

  virtual void enterIdEx(DXXParser::IdExContext * /*ctx*/) override { }
  virtual void exitIdEx(DXXParser::IdExContext * /*ctx*/) override { }

  virtual void enterInfo(DXXParser::InfoContext * /*ctx*/) override { }
  virtual void exitInfo(DXXParser::InfoContext * /*ctx*/) override { }

  virtual void enterNative(DXXParser::NativeContext * /*ctx*/) override { }
  virtual void exitNative(DXXParser::NativeContext * /*ctx*/) override { }

  virtual void enterAssigns(DXXParser::AssignsContext * /*ctx*/) override { }
  virtual void exitAssigns(DXXParser::AssignsContext * /*ctx*/) override { }

  virtual void enterAllOperators(DXXParser::AllOperatorsContext * /*ctx*/) override { }
  virtual void exitAllOperators(DXXParser::AllOperatorsContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

