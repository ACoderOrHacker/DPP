

// $antlr-format alignTrailingComments true, columnLimit 150, minEmptyLines 1, maxEmptyLinesToKeep 1, reflowComments false, useTab false
// $antlr-format allowShortRulesOnASingleLine false, allowShortBlocksOnASingleLine true, alignSemicolons hanging, alignColons hanging

parser grammar DXXParser;

options {
    language = Cpp;
    //superClass = DXXParserBase;
    tokenVocab = DXXLexer;
}

// stat: the parser tree root
stat
   : expressions* EOF
   ;

// all expressions
expressions
   : importLib # importExpr
   | operatorDefine # operatorDefineExpr
   | LeftParen expressions? RightParen # parens // simple: (1+2)/3 Change priorities
   | (Not | Tilde | PlusPlus | MinusMinus) expressions # notClassExpr // simple: !114, ~114, ++i, --i
   | LeftParen theType RightParen expressions # convertExpr // simple: (int)x
   | expressions (Star | Div | Mod) expressions # starClassExpr // simple: 1 * 2, 1 / 2, 1 % 2
   | expressions (Plus | Minus) expressions # plusClassExpr // simple: 1 + 2, 1 - 2
   | expressions (LeftShift | RightShift) expressions # leftOrRightShiftExpr // simple: 1 << 2, 1 >> 2
   | expressions (Less | Greater | LessEqual | GreaterEqual) expressions # lessClassExpr // simple: 1 < 2, 2 > 1, 1 <= 2, 2 >=1
   | expressions (Equal | NotEqual) expressions # equalOrNotEqualExpr // simple: 1 == 1, 2 != 1
   | expressions And expressions # andExpr
   | expressions Caret expressions # caretExpr
   | expressions Or expressions # orExpr
   | expressions OrOr expressions # ororExpr
   | expressions AndAnd expressions # andandExpr
   | expressions Question expressions Colon expressions # questionExpr
   | negative # negativeExpr
   | varSet # varSetExpr
   | function # functionExpr
   | functionDefine # functionDefineExpr
   | functionCall # functionCallExpr
   | return # returnExpr
   | varDefine # varDefineExpr
   | ifStatement # ifStatementExpr
   | switchStatement # switchStatementExpr
   | whileLoop # whileLoopExpr
   | doWhileLoop # doWhileLoopExpr
   | foreachLoop # foreachLoopExpr
   | goto # gotoExpr
   | gotoLabelDefine # gotoLabelDefineExpr
   | enum # enumExpr
   | class # classExpr
   | try # tryExpr
   | throw # throwExpr
   | idEx # idExExpr
   | Break # breakExpr
   | Continue # continueExpr
   | IntegerData # integerExpr
   | FloatingNumberData # floatingExpr
   | StringData # stringExpr
   | boolean # booleanExpr
   | Null # nullExpr
   | Void # voidExpr
   | Semi # semiExpr
   | theType # typeExpr
   | lambdaFunction # lambdaFunctionExpr
   ;

boolean: True | False;
negative: Minus expressions;

importLib
   : Import idEx
   ;

// simple: int x(int y) final
functionDefine
   : functionHead
   ;

// simple: static x(int y) => int { return y++;}
function
   : functionHead block
   ;

return
   : Return expressions
   ;

lambdaFunction
   : LeftBracket RightBracket block
   ;

functionHead
   : templateList? info* ID LeftParen paramList? RightParen Arrow theType
   ;

functionCall
   : idEx callTemplateList? LeftParen callParamList? RightParen
   ;

paramList: varDefine (Comma varDefine)* (Comma Ellipsis)?;

callParamList: expressions (Comma expressions)*;

varDefine
   : theType info* (varSet | ID)
   ;

varSet
   : idEx assigns expressions
   ;

ifStatement
   : If LeftParen expressions? RightParen block
     (Else If LeftParen expressions? RightParen block)*
     (Else LeftBrace expressions* RightBrace)?
   ;

switchStatement
   : Switch LeftParen expressions RightParen LeftBrace caseStatement* defaultStatement? RightBrace
   ;

caseStatement
   : Case expressions block
   ;

defaultStatement
   : Default LeftBrace expressions* RightBrace
   ;

whileLoop
   : While LeftParen expressions RightParen block?
   ;

doWhileLoop
   : whileLoop Do LeftParen expressions RightParen
   ;

foreachLoop
   : Foreach LeftParen (varDefine | idEx) Colon expressions RightParen block?
   ;

goto
   : Goto ID
   ;

gotoLabelDefine
   : ID Colon block
   ;

enum
   : Enum ID LeftBrace enumList? RightBrace
   ;

enumList
   : ID (Comma ID)*
   ;

// 'idEx*' is not a standard, but it can help visitor throw a right error
class
   : templateList Class ID (Extends idEx*)? (Implements idEx*)? LeftBrace classMethods* RightBrace
   ;


classMethods
   : expressions
   ;

operatorDefine
   : Operator allOperators LeftParen paramList? RightParen Arrow theType block?
   ;

block
   : LeftBrace expressions* RightBrace
   ;

templateList
   : Template Less templateListSub Greater
   ;

callTemplateList
   : Less callTemplateSub Greater
   ;

templateListSub
   : (Class | theType) ID (Assign expressions)? (Comma (Class | theType) ID (Assign expressions)?)*
   ;

callTemplateSub
   : expressions (Comma expressions)*
   ;

try
   : trySub catchSub* finallySub?
   ;

trySub
   : Try block
   ;

catchSub
   : Catch LeftParen (varDefine | Ellipsis) RightParen block
   ;

finallySub
   : Finally block
   ;

throw
   : Throw expressions
   ;

// the variable or function return types
theType
   : info* theTypeSub
   ;

theTypeSub
   : Int
   | Float
   | String
   | Bool
   | Object
   | Void
   | ID // the user define types
   ;

idEx
   : (ID Dot)* ID
   ;

// function or variable info
info
   : Final
   | Override
   | Inline
   | Static
   | Public
   | Protected
   | Private
   | Constructor
   | Destructor
   | native
   ;

// simple: native("library", "function")
native
   : Native LeftParen StringData Comma StringData RightParen
   ;

assigns
   : Assign
   | ColonAssign // move the ref
   | DivAssign
   | ModAssign
   | PlusAssign
   | MinusAssign
   | StarAssign
   | XorAssign
   | AndAssign
   | OrAssign
   | LeftShiftAssign
   | RightShiftAssign
   ;

allOperators
   : Arrow
   | Plus
   | Minus
   | Star
   | Div
   | Mod
   | Caret
   | And
   | Or
   | Tilde
   | Not
   | Assign
   | ColonAssign
   | Less
   | Greater
   | PlusAssign
   | MinusAssign
   | StarAssign
   | DivAssign
   | ModAssign
   | XorAssign
   | AndAssign
   | OrAssign
   | LeftShiftAssign
   | RightShiftAssign
   | Equal
   | NotEqual
   | LessEqual
   | GreaterEqual
   | AndAnd
   | OrOr
   | PlusPlus
   | MinusMinus
   | Colon
   | Dot
   | LeftShift
   | RightShift
   ;