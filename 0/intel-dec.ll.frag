
%{
	#include <##NAME##.hh>
	#include <##NAME##-Scanner.hh>
	#include <##NAME##/oas-intel-parser.hh>

	namespace ##NAME####SUCCESSOR##_here = oct::cc::v0::##NAME####SUCCESSOR##;
	namespace core_here = oct::core::v3;

    #undef  YY_DECL
    #define YY_DECL int ##NAME####SUCCESSOR##_here::Scanner::yylex( parser::semantic_type * const lval, parser::location_type *loc)

    /* typedef to make the returns for the tokens shorter */
    using token = ##NAME####SUCCESSOR##_here::parser::token;

    /* define yyterminate as this instead of NULL */
    //#define yyterminate() return( token::END )

    /* msvc2010 requires that we exclude this header file. */
    #define YY_NO_UNISTD_H

    /* update location on matching */
    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option debug
%option nodefault
%option yyclass="oct::cc::v0::##NAME####SUCCESSOR##::Scanner"
%option noyywrap
%option c++

CHAR [[:alpha:][:digit:][:punct:][:graph:][:blank:]]
CONSTANT_INTEGER_DEC [+-]?[[:digit:]]+
CONSTANT_INTEGER_HEX 0x[[:xdigit:]]+
CONSTANT_CHAR '{CHAR}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*


