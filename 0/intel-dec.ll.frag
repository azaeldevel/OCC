
%option debug
%option nodefault
%option yyclass="oct::cc::v0::##NAME####SUCCESSOR_DINASTI##::Scanner"
%option noyywrap
%option c++

CHAR [[:alpha:][:digit:][:punct:][:graph:][:blank:]]
CONSTANT_INTEGER_DEC [+-]?[[:digit:]]+
CONSTANT_INTEGER_HEX 0x[[:xdigit:]]+
CONSTANT_CHAR '{CHAR}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
