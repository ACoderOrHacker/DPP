parser grammar DXXParser;

options {
    language = Cpp;
    tokenVocab = DXXLexer;
}

// stat: the parser tree root
stat
   : gExpressions* EOF
   ;

gExpressions
   : importLib # importExpr // Done
//   | operatorDefine # operatorDefineExpr
   | function # functionExpr // Done
   | functionDefine # functionDefineExpr // Done
   | varDefine # varDefineExpr // Done
   | enum # enumExpr
   | class # classExpr
   | interface # interfaceExpr
   | semi # gSemiExpr // Done
//   | typedef # typedefExpr
   ;

// all expressions
expressions
   : new # newExpr // Done
   | delete # deleteExpr // Done
   | varDefine # varDefineExprTag // Done
   | varSet # varSetExpr // Done
   | withStatement # withExpr
   | whileLoop # whileLoopExpr
   | doWhileLoop # doWhileLoopExpr
   | foreachLoop # foreachLoopExpr
   | goto # gotoExpr
   | gotoLabelDefine # gotoLabelDefineExpr
   | try # tryExpr
   | throw # throwExpr
   | typedef # typedefExprTag
   | return # returnExpr
   | Break # breakExpr
   | Continue # continueExpr
   | semi # semiExpr
   ;

constant
   : IntegerData # integerExpr
   | FloatingNumberData # floatingExpr
   | StringData # stringExpr
   | boolean # booleanExpr
   | Null # nullExpr
   ;

data
   : constant # constantExpr
   | idEx # idExExpr
   | functionCall # functionCallExpr
   | LeftParen data? RightParen # parens // simple: (1+2)/3 Change priorities
   | (Not | Tilde | PlusPlus | MinusMinus) data # notClassExpr // simple: !114, ~114, ++i, --i
   | data AndAnd data # andandExpr
   | data OrOr data # ororExpr
   | data (Equal | NotEqual) data # equalOrNotEqualExpr // simple: 1 == 1, 2 != 1
   | data (Star | Div | Mod) data # starClassExpr // simple: 1 * 2, 1 / 2, 1 % 2
   | data (Plus | Minus) data # plusClassExpr // simple: 1 + 2, 1 - 2
   | data (LeftShift | RightShift) data # leftOrRightShiftExpr // simple: 1 << 2, 1 >> 2
   | data (Less | Greater | LessEqual | GreaterEqual) data # lessClassExpr // simple: 1 < 2, 2 > 1, 1 <= 2, 2 >=1
   | data And data # andExpr
   | data Caret data # caretExpr
   | data Or data # orExpr
   | negative # negativeExpr
   | lambdaFunction # lambdaFunctionExpr
   | theType # typeExpr
   ;

boolean: True | False;
negative: Minus data;
semi: Semi;

importLib
   : Import idEx
   ;

new
   : New theType
   ;

delete
   : Delete data
   ;

typedef
   : Using ID Assign theType
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
   : Return data
   ;

lambdaFunction
   : LeftBracket RightBracket LeftParen paramList? RightParen block
   ;

functionHead
   : info* ID LeftParen paramList? RightParen Arrow theType throwtable?
   ;

functionCall
   : idEx LeftParen callParamList? RightParen
   ;

paramList: varDefine (Comma varDefine)* (Comma Ellipsis)?;

callParamList: data (Comma data)*;

throwtable: Throw (idEx Comma)* idEx?;

varDefine
   : theType info* ID (assigns data)?
   ;

varDefineNoSet
   : theType info* ID
   ;

varSet
   : idEx assigns data
   ;

withStatement
   : withIf
   | withIfExtends
   | withSwitchStatement
   ;

withIf
   : With If LeftParen data RightParen block
   ;

withIfExtends
   : With If LeftBrace withIfExtendsSub* RightBrace
   ;

withIfExtendsSub
   : data Arrow block
   ;

withSwitchStatement
   : With LeftParen data RightParen LeftBrace caseStatement* defaultStatement? RightBrace
   ;

caseStatement
   : constant Arrow block
   ;

defaultStatement
   : Default Arrow block
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
   : ID Colon
   ;

enum
   : Enum ID LeftBrace (enumSub (Comma enumSub)*)? RightBrace
   ;

enumSub
   : ID Assign IntegerData
   ;

class
   : Class ID (Extends (idEx (Comma idEx))?)? (Implements (idEx (Comma idEx))?)? LeftBrace classMethods* RightBrace
   ;

interface
   : Interface ID (Implements (idEx Comma)* idEx?)? LeftBrace interfaceMethods* RightBrace
   ;

classMethods
   : class
   | interface
   | function
   | functionDefine
   | varDefine
   | semi
   ;

interfaceMethods
   : functionDefine
   | varDefineNoSet
   | interface
   | semi
   ;

operatorDefine
   : Operator allOperators LeftParen paramList? RightParen Arrow theType block?
   ;

block
   : LeftBrace expressions* RightBrace
   ;

try
   : Try block (Catch LeftParen (varDefine | Ellipsis) RightParen block)* (Finally block)?
   ;

throw
   : Throw (idEx | functionCall)
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
   | Type
   | Object
   | Void
   | ID // the user define types
   ;

idEx
   : (ID Dot)* ID
   ;

// function or variable info
info
   : Compiletime
   | Final
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