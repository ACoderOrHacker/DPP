parser grammar DXXParser;

options {
	language = Cpp;
	tokenVocab = DXXLexer;
}

// main: the parser tree root
main: gExpressions* EOF;

gExpressions:
	importLib # importExpr
	| operatorDefine	# operatorDefineExpr
	| function			# functionExpr // Done
	| varDefine			# varDefineExpr // Done
	| enum				# enumExpr // Done
	| class				# classExpr
	| interface			# interfaceExpr
	| semi				# gSemiExpr // Done
	| typedef			# typedefExpr ; // Done

// all expressions
expressions:
	new					# newExpr // Done
	| delete			# deleteExpr // Done
	| varDefine			# varDefineExprTag // Done
	| varSet			# varSetExpr // Done
	| functionCall		# functionCallExprTag // Done
	| withStatement		# withExpr
	| whileLoop			# whileLoopExpr
	| doWhileLoop		# doWhileLoopExpr
	| foreachLoop		# foreachLoopExpr
	| goto				# gotoExpr
	| gotoLabelDefine	# gotoLabelDefineExpr
	| try				# tryExpr
	| throw				# throwExpr
	| typedef			# typedefExprTag // Done
	| return			# returnExpr
	| Break				# breakExpr
	| Continue			# continueExpr
	| semi				# semiExpr;

constant:
	IntegerData				# integerExpr // Done
	| FloatingNumberData	# floatingExpr // Done
	| StringData			# stringExpr // Done
	| boolean				# booleanExpr // Done
	| Null					# nullExpr; // Done

data:
	constant												# constantExpr // Done
	| idEx													# idExExpr // Done
	| functionCall											# functionCallExpr // May Done
	| LeftParen data RightParen							    # parens // simple: (1+2)/3 Change priorities // Done
	| (Not | Tilde | PlusPlus | MinusMinus) data			# notClassExpr // simple: !114, ~114, ++i, --i // Done
	| data AndAnd data										# andandExpr // Done
	| data OrOr data										# ororExpr // Done
	| data (Equal | NotEqual) data							# equalOrNotEqualExpr // simple: 1 == 1, 2 != 1 // Done
	| data (Star | Div | Mod) data							# starClassExpr // simple: 1 * 2, 1 / 2, 1 % 2 // Done
	| data (Plus | Minus) data								# plusClassExpr // simple: 1 + 2, 1 - 2 // Done
	| data (LeftShift | RightShift) data					# leftOrRightShiftExpr // simple: 1 << 2, 1 >> 2 // Done
	| data (Less | Greater | LessEqual | GreaterEqual) data	# lessClassExpr // Done
	// simple: 1 < 2, 2 > 1, 1 <= 2, 2 >=1
	| data And data		# andExpr // Done
	| data Caret data	# caretExpr // Done
	| data Or data		# orExpr // Done
	| negative			# negativeExpr // Done
	| lambdaFunction	# lambdaFunctionExpr
	| theType			# typeExpr // Done
	| new				# newExpr_
	| delete			# deleteExpr_;
boolean: True | False;
negative: Minus data;
semi: Semi;

importLib: Import idEx;

new: New theType;

delete: Delete data;

typedef: Using ID Assign theType;

// simple: static x(int y) => int { return y++;}
function: functionHead block?;

return: Return data;

lambdaFunction:
	LeftBracket RightBracket LeftParen paramList? RightParen block;

functionHead:
	info* ID LeftParen paramList? RightParen Arrow theType throwtable?;

functionCall: idEx LeftParen callParamList? RightParen;

// TODO: If change the varDefineNoSet to varDefine, it will has bug, the auto value will always be the paramter but not the user set
paramList: varDefine (Comma varDefine)* (Comma Ellipsis)?;

callParamList: data (Comma data)*;

throwtable: Throw (idEx Comma)* idEx?;

varDefine: theType info* ID (assigns data)?;

varDefineNoSet: theType info* ID;

varSet: idEx assigns data;

withStatement:
	withIf // Done
	| withIfExtends
	| withSwitchStatement;

withIf: With If LeftParen data RightParen block;

withIfExtends: With If LeftBrace withIfExtendsSub* RightBrace;

withIfExtendsSub: data Arrow block;

withSwitchStatement:
	With LeftParen data RightParen LeftBrace caseStatement* defaultStatement? RightBrace;

caseStatement: constant Arrow block;

defaultStatement: Default Arrow block;

whileLoop: While LeftParen expressions RightParen block?;

doWhileLoop: whileLoop Do LeftParen expressions RightParen;

foreachLoop:
	Foreach LeftParen (varDefine | idEx) Colon expressions RightParen block?;

goto: Goto ID;

gotoLabelDefine: ID Colon;

enum: Enum ID LeftBrace (enumSub (Comma enumSub)*)? RightBrace;

enumSub: ID Assign IntegerData;

class:
	Class ID (Extends (idEx (Comma idEx))?)? (
		Implements (idEx (Comma idEx))?
	)? LeftBrace classMethods* RightBrace;

interface:
	Interface ID (Implements (idEx Comma)* idEx?)? LeftBrace interfaceMethods* RightBrace;

classMethods: class | interface | function | varDefine | semi;

interfaceMethods: function | varDefineNoSet | interface | semi;

operatorDefine:
	Operator allOperators LeftParen paramList? RightParen Arrow theType block?;

block: LeftBrace expressions* RightBrace;

try:
	Try block (
		Catch LeftParen (varDefine | Ellipsis) RightParen block
	)* (Finally block)?;

throw: Throw (idEx | functionCall);

// the variable or function return types
theType: info* theTypeSub;

theTypeSub:
	Int
	| Float
	| String
	| Bool
	| Type
	| Object
	| Void
	| ID; // the user define types

idEx: (ID Dot)* ID;

// function or variable info
info:
	Compiletime
	| Final
	| Override
	| Inline
	| Static
	| Public
	| Protected
	| Private
	| Constructor
	| Destructor
	| native;

// simple: native("library", "function")
native: Native LeftParen StringData Comma StringData RightParen;

assigns:
	Assign
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
	| RightShiftAssign;

allOperators:
	Arrow
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
	| RightShift;