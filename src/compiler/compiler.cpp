#include "DXXLexer.h"
#include "compiler.hpp"

DXX_API FObject *_compile(antlr4::ANTLRInputStream input) {
    DXXLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    DXXParser parser(&tokens);
    DXXParser::MainContext *main = parser.main();

    DXXVisitor visitor;
    FObject *fObj = anycast(FObject *, visitor.visit(main));

    return fObj;
}

DXX_API FObject *compile(std::string &code) {
    antlr4::ANTLRInputStream input(code);
    return _compile(input);
}

DXX_API FObject *compile(std::ifstream &ifs) {
    antlr4::ANTLRInputStream input(ifs);
    return _compile(input);
}