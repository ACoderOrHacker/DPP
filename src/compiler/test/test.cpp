#include "../compiler.h"
#pragma comment(lib, "antlr4-runtime.lib")
int main() {
	compile("int x = 1;");
	/*antlr4::ANTLRInputStream input("int x=1;f.stream(;");
	  DXXLexer lexer(&input);
	  antlr4::CommonTokenStream tokens(&lexer);
	  DXXParser parser(&tokens);
	  //std::cout << parser.stat()->toStringTree(true);*/
	
	return 0;
}
