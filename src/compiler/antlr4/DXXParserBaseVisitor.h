
// Generated from templates/DXXParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DXXParserVisitor.h"


/**
 * This class provides an empty implementation of DXXParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  DXXParserBaseVisitor : public DXXParserVisitor {
public:

  virtual std::any visitStat(DXXParser::StatContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportExpr(DXXParser::ImportExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionExpr(DXXParser::FunctionExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDefineExpr(DXXParser::FunctionDefineExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefineExpr(DXXParser::VarDefineExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassExpr(DXXParser::ClassExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceExpr(DXXParser::InterfaceExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGSemiExpr(DXXParser::GSemiExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpr(DXXParser::NewExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDeleteExpr(DXXParser::DeleteExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefineExprTag(DXXParser::VarDefineExprTagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarSetExpr(DXXParser::VarSetExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithExpr(DXXParser::WithExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileLoopExpr(DXXParser::WhileLoopExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoWhileLoopExpr(DXXParser::DoWhileLoopExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForeachLoopExpr(DXXParser::ForeachLoopExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGotoExpr(DXXParser::GotoExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGotoLabelDefineExpr(DXXParser::GotoLabelDefineExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTryExpr(DXXParser::TryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThrowExpr(DXXParser::ThrowExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypedefExprTag(DXXParser::TypedefExprTagContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturnExpr(DXXParser::ReturnExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreakExpr(DXXParser::BreakExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinueExpr(DXXParser::ContinueExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSemiExpr(DXXParser::SemiExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIntegerExpr(DXXParser::IntegerExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFloatingExpr(DXXParser::FloatingExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStringExpr(DXXParser::StringExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBooleanExpr(DXXParser::BooleanExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNullExpr(DXXParser::NullExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrorExpr(DXXParser::OrorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParens(DXXParser::ParensContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdExExpr(DXXParser::IdExExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypeExpr(DXXParser::TypeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNotClassExpr(DXXParser::NotClassExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNegativeExpr(DXXParser::NegativeExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLeftOrRightShiftExpr(DXXParser::LeftOrRightShiftExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOrExpr(DXXParser::OrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitPlusClassExpr(DXXParser::PlusClassExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaFunctionExpr(DXXParser::LambdaFunctionExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndandExpr(DXXParser::AndandExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEqualOrNotEqualExpr(DXXParser::EqualOrNotEqualExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaretExpr(DXXParser::CaretExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStarClassExpr(DXXParser::StarClassExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCallExpr(DXXParser::FunctionCallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLessClassExpr(DXXParser::LessClassExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstantExpr(DXXParser::ConstantExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAndExpr(DXXParser::AndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBoolean(DXXParser::BooleanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNegative(DXXParser::NegativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSemi(DXXParser::SemiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitImportLib(DXXParser::ImportLibContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNew(DXXParser::NewContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDelete(DXXParser::DeleteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTypedef(DXXParser::TypedefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDefine(DXXParser::FunctionDefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunction(DXXParser::FunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn(DXXParser::ReturnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLambdaFunction(DXXParser::LambdaFunctionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionHead(DXXParser::FunctionHeadContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionCall(DXXParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParamList(DXXParser::ParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCallParamList(DXXParser::CallParamListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThrowtable(DXXParser::ThrowtableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefine(DXXParser::VarDefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefineNoSet(DXXParser::VarDefineNoSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarSet(DXXParser::VarSetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithStatement(DXXParser::WithStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithIf(DXXParser::WithIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithIfExtends(DXXParser::WithIfExtendsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithIfExtendsSub(DXXParser::WithIfExtendsSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithSwitchStatement(DXXParser::WithSwitchStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCaseStatement(DXXParser::CaseStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDefaultStatement(DXXParser::DefaultStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileLoop(DXXParser::WhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDoWhileLoop(DXXParser::DoWhileLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForeachLoop(DXXParser::ForeachLoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGoto(DXXParser::GotoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitGotoLabelDefine(DXXParser::GotoLabelDefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnum(DXXParser::EnumContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitEnumSub(DXXParser::EnumSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass(DXXParser::ClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterface(DXXParser::InterfaceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassMethods(DXXParser::ClassMethodsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInterfaceMethods(DXXParser::InterfaceMethodsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperatorDefine(DXXParser::OperatorDefineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(DXXParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTry(DXXParser::TryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitThrow(DXXParser::ThrowContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTheType(DXXParser::TheTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTheTypeSub(DXXParser::TheTypeSubContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdEx(DXXParser::IdExContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInfo(DXXParser::InfoContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNative(DXXParser::NativeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssigns(DXXParser::AssignsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAllOperators(DXXParser::AllOperatorsContext *ctx) override {
    return visitChildren(ctx);
  }


};

