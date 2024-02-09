
// Generated from templates/DXXParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "DXXParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by DXXParser.
 */
class  DXXParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by DXXParser.
   */
    virtual std::any visitStat(DXXParser::StatContext *context) = 0;

    virtual std::any visitVarSetExpr(DXXParser::VarSetExprContext *context) = 0;

    virtual std::any visitParens(DXXParser::ParensContext *context) = 0;

    virtual std::any visitDoWhileLoopExpr(DXXParser::DoWhileLoopExprContext *context) = 0;

    virtual std::any visitIntegerExpr(DXXParser::IntegerExprContext *context) = 0;

    virtual std::any visitNullExpr(DXXParser::NullExprContext *context) = 0;

    virtual std::any visitVoidExpr(DXXParser::VoidExprContext *context) = 0;

    virtual std::any visitIdExExpr(DXXParser::IdExExprContext *context) = 0;

    virtual std::any visitNegativeExpr(DXXParser::NegativeExprContext *context) = 0;

    virtual std::any visitBreakExpr(DXXParser::BreakExprContext *context) = 0;

    virtual std::any visitPlusClassExpr(DXXParser::PlusClassExprContext *context) = 0;

    virtual std::any visitQuestionExpr(DXXParser::QuestionExprContext *context) = 0;

    virtual std::any visitVarDefineExpr(DXXParser::VarDefineExprContext *context) = 0;

    virtual std::any visitFunctionExpr(DXXParser::FunctionExprContext *context) = 0;

    virtual std::any visitStringExpr(DXXParser::StringExprContext *context) = 0;

    virtual std::any visitIfStatementExpr(DXXParser::IfStatementExprContext *context) = 0;

    virtual std::any visitEqualOrNotEqualExpr(DXXParser::EqualOrNotEqualExprContext *context) = 0;

    virtual std::any visitConvertExpr(DXXParser::ConvertExprContext *context) = 0;

    virtual std::any visitStarClassExpr(DXXParser::StarClassExprContext *context) = 0;

    virtual std::any visitFunctionCallExpr(DXXParser::FunctionCallExprContext *context) = 0;

    virtual std::any visitSwitchStatementExpr(DXXParser::SwitchStatementExprContext *context) = 0;

    virtual std::any visitEnumExpr(DXXParser::EnumExprContext *context) = 0;

    virtual std::any visitFloatingExpr(DXXParser::FloatingExprContext *context) = 0;

    virtual std::any visitLessClassExpr(DXXParser::LessClassExprContext *context) = 0;

    virtual std::any visitImportExpr(DXXParser::ImportExprContext *context) = 0;

    virtual std::any visitForeachLoopExpr(DXXParser::ForeachLoopExprContext *context) = 0;

    virtual std::any visitThrowExpr(DXXParser::ThrowExprContext *context) = 0;

    virtual std::any visitOrorExpr(DXXParser::OrorExprContext *context) = 0;

    virtual std::any visitGotoExpr(DXXParser::GotoExprContext *context) = 0;

    virtual std::any visitSemiExpr(DXXParser::SemiExprContext *context) = 0;

    virtual std::any visitTypeExpr(DXXParser::TypeExprContext *context) = 0;

    virtual std::any visitNotClassExpr(DXXParser::NotClassExprContext *context) = 0;

    virtual std::any visitBooleanExpr(DXXParser::BooleanExprContext *context) = 0;

    virtual std::any visitFunctionDefineExpr(DXXParser::FunctionDefineExprContext *context) = 0;

    virtual std::any visitReturnExpr(DXXParser::ReturnExprContext *context) = 0;

    virtual std::any visitClassExpr(DXXParser::ClassExprContext *context) = 0;

    virtual std::any visitLeftOrRightShiftExpr(DXXParser::LeftOrRightShiftExprContext *context) = 0;

    virtual std::any visitOrExpr(DXXParser::OrExprContext *context) = 0;

    virtual std::any visitLambdaFunctionExpr(DXXParser::LambdaFunctionExprContext *context) = 0;

    virtual std::any visitContinueExpr(DXXParser::ContinueExprContext *context) = 0;

    virtual std::any visitAndandExpr(DXXParser::AndandExprContext *context) = 0;

    virtual std::any visitWhileLoopExpr(DXXParser::WhileLoopExprContext *context) = 0;

    virtual std::any visitCaretExpr(DXXParser::CaretExprContext *context) = 0;

    virtual std::any visitTryExpr(DXXParser::TryExprContext *context) = 0;

    virtual std::any visitGotoLabelDefineExpr(DXXParser::GotoLabelDefineExprContext *context) = 0;

    virtual std::any visitOperatorDefineExpr(DXXParser::OperatorDefineExprContext *context) = 0;

    virtual std::any visitAndExpr(DXXParser::AndExprContext *context) = 0;

    virtual std::any visitBoolean(DXXParser::BooleanContext *context) = 0;

    virtual std::any visitNegative(DXXParser::NegativeContext *context) = 0;

    virtual std::any visitImportLib(DXXParser::ImportLibContext *context) = 0;

    virtual std::any visitFunctionDefine(DXXParser::FunctionDefineContext *context) = 0;

    virtual std::any visitFunction(DXXParser::FunctionContext *context) = 0;

    virtual std::any visitReturn(DXXParser::ReturnContext *context) = 0;

    virtual std::any visitLambdaFunction(DXXParser::LambdaFunctionContext *context) = 0;

    virtual std::any visitFunctionHead(DXXParser::FunctionHeadContext *context) = 0;

    virtual std::any visitFunctionCall(DXXParser::FunctionCallContext *context) = 0;

    virtual std::any visitParamList(DXXParser::ParamListContext *context) = 0;

    virtual std::any visitCallParamList(DXXParser::CallParamListContext *context) = 0;

    virtual std::any visitVarDefine(DXXParser::VarDefineContext *context) = 0;

    virtual std::any visitVarSet(DXXParser::VarSetContext *context) = 0;

    virtual std::any visitIfStatement(DXXParser::IfStatementContext *context) = 0;

    virtual std::any visitSwitchStatement(DXXParser::SwitchStatementContext *context) = 0;

    virtual std::any visitCaseStatement(DXXParser::CaseStatementContext *context) = 0;

    virtual std::any visitDefaultStatement(DXXParser::DefaultStatementContext *context) = 0;

    virtual std::any visitWhileLoop(DXXParser::WhileLoopContext *context) = 0;

    virtual std::any visitDoWhileLoop(DXXParser::DoWhileLoopContext *context) = 0;

    virtual std::any visitForeachLoop(DXXParser::ForeachLoopContext *context) = 0;

    virtual std::any visitGoto(DXXParser::GotoContext *context) = 0;

    virtual std::any visitGotoLabelDefine(DXXParser::GotoLabelDefineContext *context) = 0;

    virtual std::any visitEnum(DXXParser::EnumContext *context) = 0;

    virtual std::any visitEnumList(DXXParser::EnumListContext *context) = 0;

    virtual std::any visitClass(DXXParser::ClassContext *context) = 0;

    virtual std::any visitClassMethods(DXXParser::ClassMethodsContext *context) = 0;

    virtual std::any visitOperatorDefine(DXXParser::OperatorDefineContext *context) = 0;

    virtual std::any visitBlock(DXXParser::BlockContext *context) = 0;

    virtual std::any visitTemplateList(DXXParser::TemplateListContext *context) = 0;

    virtual std::any visitCallTemplateList(DXXParser::CallTemplateListContext *context) = 0;

    virtual std::any visitTemplateListSub(DXXParser::TemplateListSubContext *context) = 0;

    virtual std::any visitCallTemplateSub(DXXParser::CallTemplateSubContext *context) = 0;

    virtual std::any visitTry(DXXParser::TryContext *context) = 0;

    virtual std::any visitTrySub(DXXParser::TrySubContext *context) = 0;

    virtual std::any visitCatchSub(DXXParser::CatchSubContext *context) = 0;

    virtual std::any visitFinallySub(DXXParser::FinallySubContext *context) = 0;

    virtual std::any visitThrow(DXXParser::ThrowContext *context) = 0;

    virtual std::any visitTheType(DXXParser::TheTypeContext *context) = 0;

    virtual std::any visitTheTypeSub(DXXParser::TheTypeSubContext *context) = 0;

    virtual std::any visitIdEx(DXXParser::IdExContext *context) = 0;

    virtual std::any visitInfo(DXXParser::InfoContext *context) = 0;

    virtual std::any visitNative(DXXParser::NativeContext *context) = 0;

    virtual std::any visitAssigns(DXXParser::AssignsContext *context) = 0;

    virtual std::any visitAllOperators(DXXParser::AllOperatorsContext *context) = 0;


};

