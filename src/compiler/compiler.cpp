
#include "compiler.hpp"

DXX_API FObject *compile(std::string code) {
	antlr4::ANTLRInputStream input(code);
	DXXLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	DXXParser parser(&tokens);
	DXXVisitor visitor;
	antlr4::tree::ParseTree *tree = parser.stat();

	FObject *fObj = anycast(FObject *, visitor.visit(tree));

    std::cout << "Ending visit";

    return nullptr;
	//return fObj;
}

DXX_API bool compile(std::ifstream file) {
	antlr4::ANTLRInputStream input(file);
	DXXLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	DXXParser parser(&tokens);
	std::cout << parser.stat()->toStringTree();
	return true;
}
