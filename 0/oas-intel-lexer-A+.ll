
%option noyywrap nounput noinput batch debug

%{
	#include <assert.h>
	#include <limits.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	//#include <core/3/math.hh>
	#include "driver.hh"
	#include "oas-intel-parser-A+.hh"

	#include <A+.hh>
	namespace A_here = oct::cc::v0::A;
	namespace core_here = oct::core::v3;
	core_here::Block A_here::block;
%}



DIGIT_DEC [[:digit:]]
DIGIT_HEX [[:xdigit:]]
CHAR [[:alpha:][:digit:][:punct:][:graph:][:blank:]]
LITERAL_INTEGER_DEC [+-]?{DIGIT_DEC}+
LITERAL_INTEGER_HEX 0x{DIGIT_HEX}+
LITERAL_CHAR '{CHAR}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%{
    #define YY_USER_ACTION  loc.columns (yyleng);
%}
%%
%{
    yy::location& loc = drv.location;
    loc.step ();
%}


"auto"		{
				return yy::parser::make_AUTO(loc);
			}
"break"		{
				return yy::parser::make_BREAK(loc);
			}
"case"		{
				return yy::parser::make_CASE(loc);
			}
"char"		{
				return yy::parser::make_CHAR(loc);
			}
"const"		{
				return yy::parser::make_CONST(loc);
			}
"continue"	{
				return yy::parser::make_CONTINUE(loc);
			}
"default"	{
				return yy::parser::make_DEFAULT(loc);
			}
"do"		{
				return yy::parser::make_DO(loc);
			}
"double"	{
				return yy::parser::make_DOUBLE(loc);
			}
"else"		{
				return yy::parser::make_ELSE(loc);
			}
"enum"		{
				return yy::parser::make_ENUM(loc);
			}
"extern"	{
				return yy::parser::make_EXTERN(loc);
			}
"float"		{
				return yy::parser::make_FLOAT(loc);
			}
"for"		{
				return yy::parser::make_FOR(loc);
			}
"goto"		{
				return yy::parser::make_GOTO(loc);
			}
"if"		{
				return yy::parser::make_IF(loc);
			}
"int"		{
				return yy::parser::make_INT(loc);
			}
"long"		{
				return yy::parser::make_LONG(loc);
			}
"register"	{
				return yy::parser::make_REGISTER(loc);
			}
"return"	{
				return yy::parser::make_RETURN(loc);
			}
"short"		{
				return yy::parser::make_SHORT(loc);
			}
"signed"	{
				return yy::parser::make_SIGNED(loc);
			}
"sizeof"	{
				return yy::parser::make_SIZEOF(loc);
			}
"static"	{
				return yy::parser::make_STATIC(loc);
			}
"struct"	{
				return yy::parser::make_STRUCT(loc);
			}
"switch"	{
				return yy::parser::make_SWITCH(loc);
			}
"typedef"	{
				return yy::parser::make_TYPEDEF(loc);
			}
"union"		{
				return yy::parser::make_UNION(loc);
			}
"unsigned"	{
				return yy::parser::make_UNSIGNED(loc);
			}
"void"		{
				return yy::parser::make_VOID(loc);
			}
"volatil"	{
				return yy::parser::make_VOLATIL(loc);
			}
"while"		{
				return yy::parser::make_WHILE(loc);
			}

"mov"		{
				return yy::parser::make_MOV(loc);
			}

"al"	{

				return yy::parser::make_AL(loc);
		}
"ah"	{

				return yy::parser::make_AH(loc);
		}

[[:space:]]			;

{IDENTIFIER}	{
			//std::cout << "Line IDENTIFIER : " << yylineno << "\n";
			A_here::nodes::identifier* identifer = A_here::block.create<A_here::nodes::identifier>();
			identifer->line = yylineno;
			identifer->name = yytext;
            return yy::parser::make_IDENTIFIER(yytext,loc);
		}

{LITERAL_INTEGER_HEX}	{
				//std::cout << "Line LIETRAL_INTEGER_HEX : " << yylineno << "\n";
				A_here::nodes::Integer* integer = A_here::block.create<A_here::nodes::Integer>();
				//A_here::symbol_current = (A_here::nodes::Symbol*)integer;
				integer->line = yylineno;
				integer->format = 'H';
				integer->token = A_here::Tokens::LITERAL_INTEGER_HEX;
				integer->number = std::stoll(yytext, nullptr, 16);
				integer->strvalue = yytext;
				return yy::parser::make_LITERAL_INTEGER_HEX(integer->number,loc);
			}
{LITERAL_INTEGER_DEC}	{
				//std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
				A_here::nodes::Integer* integer = A_here::block.create<A_here::nodes::Integer>();
				//A_here::symbol_current = (A_here::nodes::Symbol*)integer;
				integer->line = yylineno;
				integer->format = 'D';
				integer->token = A_here::Tokens::LITERAL_INTEGER_DEC;
				integer->number = std::stoll(yytext);
				integer->strvalue = yytext;
				return yy::parser::make_LITERAL_INTEGER_HEX(integer->number,loc);
			}
{LITERAL_CHAR}		{
				//std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
				A_here::nodes::Symbol* letter = A_here::block.create<A_here::nodes::Symbol>();
				letter->token = (A_here::Tokens)yytext[1];
				letter->line = yylineno;
				letter->strvalue = yytext;
				//std::cout << "Line LIETRAL_CHAR : " << yylineno << "  " << letter->strvalue << "\n";
				return yy::parser::make_LITERAL_CHAR(yytext[1],loc);
			}



[[:punct:]]	{
				return yy::parser::symbol_type(yytext[0],loc);
            }

<<EOF>>  	{
				return yy::parser::make_ENDOFFILE(loc);
			}

.	;

%%
void driver::scan_begin ()
{
  yy_flex_debug = trace_scanning;
  if (file.empty () || file == "-")
    yyin = stdin;
  else if (!(yyin = fopen (file.c_str (), "r")))
    {
      std::cerr << "cannot open " << file << ": " << strerror (errno) << '\n';
      exit (EXIT_FAILURE);
    }
}

void driver::scan_end ()
{
  fclose (yyin);
}





