
%option noyywrap yylineno

%{
	#include <assert.h>
	#include <limits.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	//#include <core/3/math.hh>


	#include <A+.hh>	
	namespace A_here = oct::cc::v0::A;
	A_here::File A_here::current_file;
	
	#define YY_DECL A_here::Tokens lexer()
	
%}

DIGIT_DEC [0-9]
DIGIT_HEX [0-9A-Fa-f]
LETTER [a-zA-Z]
LITERAL_INTEGER_DEC {DIGIT_DEC}+
LIETRAL_INTEGER_HEX 0x{DIGIT_HEX}+
LIETRAL_CHAR '{LETTER}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

"auto"			{return A_here::Tokens::AUTO;}
"break"			{return A_here::Tokens::BREAK;}
"case"			{return A_here::Tokens::CASE;}
"char"			{return A_here::Tokens::CHAR;}
"const"		{return A_here::Tokens::CONST;}
"continue"		{return A_here::Tokens::CONTINUE;}
"default"		{return A_here::Tokens::DEFAULT;}
"do"		{return A_here::Tokens::DO;}
"double"		{return A_here::Tokens::DOUBLE;}
"else"		{return A_here::Tokens::ELSE;}
"enum"		{return A_here::Tokens::ENUM;}
"extern"		{return A_here::Tokens::EXTERN;}
"float"		{return A_here::Tokens::FLOAT;}
"for"		{return A_here::Tokens::FOR;}
"goto"		{return A_here::Tokens::GOTO;}
"if"		{return A_here::Tokens::IF;}
"int"		{return A_here::Tokens::INT;}
"long"		{return A_here::Tokens::LONG;}
"register"		{return A_here::Tokens::REGISTER;}
"return"		{return A_here::Tokens::RETURN;}
"short"		{return A_here::Tokens::SHORT;}
"signed"		{return A_here::Tokens::SIGNED;}
"sizeof"		{return A_here::Tokens::SIZEOF;}
"static"		{return A_here::Tokens::STATIC;}
"struct"		{return A_here::Tokens::STRUCT;}
"switch"		{return A_here::Tokens::SWITCH;}
"typedef"		{return A_here::Tokens::TYPEDEF;}
"union"		{return A_here::Tokens::UNION;}
"unsigned"		{return A_here::Tokens::UNSIGNED;}
"void"		{return A_here::Tokens::VOID;}
"volatil"		{return A_here::Tokens::VOLATIL;}
"while"		{return A_here::Tokens::WHILE;}


"mov"			{return A_here::Tokens::MOV;}

"al"			{return A_here::Tokens::AL;}
"ah"			{return A_here::Tokens::AH;}

[\n\t ]			;

{IDENTIFIER}	{
					return A_here::Tokens::identifier;
				}//oct::cc::v0::A::add_identifier(yylineno,A_here::current_file.get_filename().string().c_str(),yytext,yyleng);

[:;]			{
					return (A_here::Tokens)yytext[0];
				}

{LIETRAL_INTEGER_HEX}		{return A_here::Tokens::LITERAL_INTEGER_HEX;}
{LITERAL_INTEGER_DEC}		{
								return A_here::Tokens::LITERAL_INTEGER_DEC;
							}
{LIETRAL_CHAR}				{
								return A_here::Tokens::LITERAL_CHAR;
							}


<<EOF>>  return A_here::Tokens::NUL;

.				;

%%
