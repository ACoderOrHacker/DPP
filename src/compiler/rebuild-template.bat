@echo off

cd antlr4
del * /Q
cd ..
antlr4 -visitor -no-listener templates/DXXLexer.g4 templates/DXXParser.g4 -o antlr4/