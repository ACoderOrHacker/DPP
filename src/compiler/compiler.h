/*
  MIT License
  
  Copyright (c) 2023 ACoderOrHacker
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 */

#ifndef _COMPILER_H

#include <string>
#include <fstream>

#include "acdpp.h"
#include "DXXLexer.h"
#include "DXXParserBaseVisitor.h"

bool compile(std::string code);
bool compile(std::ifstream file);


void underlineError(antlr4::Recognizer *recognizer, 
	                antlr4::Token *offendingSymbol, 
	                size_t line, 
	                size_t charPositionInLine);
/*
class ErrorListener : public antlr4::BaseErrorListener {
public:
	ErrorListener(){}
	~ErrorListener(){}
	
	void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
		size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
		std::cerr << "Syntax error at line " << line << ", column " << charPositionInLine << ": " << msg << std::endl;
		//underlineError(recognizer, offendingSymbol, line, charPositionInLine);
	}
	
	void reportAmbiguity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex, bool exact,
		const antlrcpp::BitSet &ambigAlts, antlr4::atn::ATNConfigSet *configs){}
	
	void reportAttemptingFullContext(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		const antlrcpp::BitSet &conflictingAlts, antlr4::atn::ATNConfigSet *configs){}

	void reportContextSensitivity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
		size_t prediction, antlr4::atn::ATNConfigSet *configs){}
};
*/

class DXXVisitor : public DXXParserBaseVisitor {
	std::any visitStat(DXXParser::StatContext *ctx) {
		return visitVarDefineExpr();
	}
	
	std::any visitVarDefineExpr(DXXParser::VarDefineContext *ctx) {
		DXXParser::TheTypeContext *type = ctx->getRuleContext<DXXParser::TheTypeContext>(0);
		std::cout << type->toString();
	}
	
	std::any visitVarSetExpr(DXXParser::VarSetExprContext *ctx) {
		std::cout << ctx->isEmpty() << "lll";
		return nullptr;
	}
};

#endif // !_COMPILER_H
