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

Compiletime: 'compiletime';

Continue: 'continue';

Default: 'default';

Delete: 'delete';

Do: 'do';

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

Interface: 'interface';

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

Type: 'type';

Using: 'using';

Virtual: 'virtual';

Void: 'void';

While: 'while';

With: 'with';

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

Colon: ':';

Semi: ';';

Dot: '.';

Ellipsis: '...';

LeftShift: '<<';

RightShift: '>>';

ID:
   [a-zA-Z_] ([a-zA-Z_] | [0-9])*
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

StringData: '"' (ESC | ~["\\])* '"';