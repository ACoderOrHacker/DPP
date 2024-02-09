#pragma once

#include "antlr4-runtime.h"

class DXXParserBase : public antlr4::Parser {
public:
    DXXParserBase(antlr4::TokenStream *input) : Parser(input) { }
    bool IsPureSpecifierAllowed();
};
