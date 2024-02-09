// $antlr-format alignTrailingComments true, columnLimit 150, maxEmptyLinesToKeep 1, reflowComments false, useTab false
// $antlr-format allowShortRulesOnASingleLine true, allowShortBlocksOnASingleLine true, minEmptyLines 0, alignSemicolons ownLine
// $antlr-format alignColons trailing, singleLineOverrulesHangingColon true, alignLexerCommands true, alignLabels true, alignTrailers true

lexer grammar DXXLexer;

options {
    language = Cpp;
}

/*Keywords*/

Asm: 'asm';

Bool: 'bool';

Break: 'break';

Case: 'case';

Catch: 'catch';

Char: 'char';

Class: 'class';

Continue: 'continue';

Default: 'default';

Delete: 'delete';

Do: 'do';

Else: 'else';

Enum: 'enum';

Extends: 'extends';

False: 'false';

Final: 'final';

Finally: 'finally';

Float: 'float';

Foreach: 'foreach';

Goto: 'goto';

If: 'if';

Import: 'import';

Inline: 'inline';

Int: 'int';

Implements: 'implements';

Long: 'long';

Native: 'native';

New: 'new';

Null: 'null';

Object: 'object';

Operator: 'operator';

Override: 'override';

Private: 'private';

Protected: 'protected';

Public: 'public';

Return: 'return';

Short: 'short';

Static: 'static';

String: 'string';

Super: 'super';

Switch: 'switch';

Template: 'template';

This: 'this';

Throw: 'throw';

True: 'true';

Try: 'try';

Typedef: 'typedef';

Virtual: 'virtual';

Void: 'void';

While: 'while';

/* Operators */

LeftParen: '(';

RightParen: ')';

LeftBracket: '[';

RightBracket: ']';

LeftBrace: '{';

RightBrace: '}';

Arrow: '=>';

Plus: '+';

Minus: '-';

Star: '*';

Div: '/';

Mod: '%';

Caret: '^';

And: '&';

Or: '|';

Tilde: '~';

Not: '!' | 'not';

Assign: '=';

ColonAssign: ':=';

Less: '<';

Greater: '>';

PlusAssign: '+=';

MinusAssign: '-=';

StarAssign: '*=';

DivAssign: '/=';

ModAssign: '%=';

XorAssign: '^=';

AndAssign: '&=';

OrAssign: '|=';

LeftShiftAssign: '<<=';

RightShiftAssign: '>>=';

Equal: '==';

NotEqual: '!=';

LessEqual: '<=';

GreaterEqual: '>=';

AndAnd: '&&' | 'and';

OrOr: '||' | 'or';

PlusPlus: '++';

MinusMinus: '--';

Comma: ',';

Question: '?';

Colon: ':';

Semi: ';';

Dot: '.';

Ellipsis: '...';

LeftShift: '<<';

RightShift: '>>';

ID:
   [a-zA-Z] ([a-zA-Z] | [0-9])*
;

Constructor: '__constructor__';
Destructor: '__destructor__';

fragment NONZERODIGIT: [1-9];

fragment OCTALDIGIT: [0-7];

fragment HEXADECIMALDIGIT: [0-9a-fA-F];

fragment Simpleescapesequence:
    '\\\''
    | '\\"'
    | '\\?'
    | '\\\\'
    | '\\a'
    | '\\b'
    | '\\f'
    | '\\n'
    | '\\r'
    | '\\' ('\r' '\n'? | '\n')
    | '\\t'
    | '\\v'
;

fragment SIGN: '-';

fragment ESC: '\\' [\\'"] ;

Whitespace: [ \t]+ -> skip;

Newline: ('\r' '\n'? | '\n') -> skip;

BlockComment: '/*' .*? '*/' -> skip;

LineComment: '//' ~ [\r\n]* -> skip;

IntegerData:  [0-9]+;

FloatingNumberData: IntegerData Dot IntegerData;

StringData: ('"' | '\'') (ESC | ~ ["\\])* ('"' | '\'');