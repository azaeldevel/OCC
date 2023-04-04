
%option noyywrap yylineno bison-bridge reentrant

%{
	#include <assert.h>
	#include <limits.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	//#include <core/3/math.hh>
	#include "oas-intel-parser-A+.hh"


	#include <A+.hh>
	namespace A_here = oct::cc::v0::A;
	namespace core_here = oct::core::v3;
	core_here::Block A_here::block;
	A_here::Symbol* A_here::symbol_current;

%}

DIGIT_DEC [[:digit:]]
DIGIT_HEX [[:xdigit:]]
CHAR [[:alpha:][:digit:][:punct:][:graph:][:blank:]]
LITERAL_INTEGER_DEC [+-]?{DIGIT_DEC}+
LITERAL_INTEGER_HEX 0x{DIGIT_HEX}+
LITERAL_CHAR '{CHAR}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

"auto"		{
				//std::cout << "Line auto : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::AUTO;
				return AUTO;
			}
"break"		{
				//std::cout << "Line break : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::BREAK;
				return BREAK;
			}
"case"		{
				//std::cout << "Line case : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::CASE;
				return CASE;
			}
"char"		{
				//std::cout << "Line char : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::CHAR;
				return CHAR;
			}
"const"		{
				//std::cout << "Line const : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::CONST;
				return CONST;
			}
"continue"	{
				//std::cout << "Line continue : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::CONTINUE;
				return CONTINUE;
			}
"default"	{
				//std::cout << "Line default : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::DEFAULT;
				return DEFAULT;
			}
"do"		{
				//std::cout << "Line do : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::DO;
				return DO;
			}
"double"	{
				//std::cout << "Line double : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::DOUBLE;
				return DOUBLE;
			}
"else"		{
				//std::cout << "Line else : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::ELSE;
				return ELSE;
			}
"enum"		{
				//std::cout << "Line enum : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::ENUM;
				return ENUM;
			}
"extern"	{
				//std::cout << "Line extern : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::EXTERN;
				return EXTERN;
			}
"float"		{
				//std::cout << "Line float : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::FLOAT;
				return FLOAT;
			}
"for"		{
				//std::cout << "Line for : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::FOR;
				return FOR;
			}
"goto"		{
				//std::cout << "Line goto : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::GOTO;
				return GOTO;
			}
"if"		{
				//std::cout << "Line if : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::IF;
				return IF;
			}
"int"		{
				//std::cout << "Line int : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::INT;
				return INT;
			}
"long"		{
				//std::cout << "Line long : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::LONG;
				return LONG;
			}
"register"	{
				//std::cout << "Line register : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::REGISTER;
				return REGISTER;
			}
"return"	{
				//std::cout << "Line return : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::RETURN;
				return RETURN;
			}
"short"		{
				//std::cout << "Line short : " << yylineno << "\n";
				//std::cout << "Step 1\n";
				//std::cout << "Step 2\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				//std::cout << "Step 3\n";
				A_here::symbol_current->line = yylineno;
				//std::cout << "Step 4\n";
				A_here::symbol_current->token = A_here::Tokens::SHORT;
				//std::cout << "Step 5\n";
				return SHORT;
			}
"signed"	{
				//std::cout << "Line signed : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::SIGNED;
				return SIGNED;
			}
"sizeof"	{
				//std::cout << "Line sizeof : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::SIZEOF;
				return SIZEOF;
			}
"static"	{
				//std::cout << "Line static : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::STATIC;
				return STATIC;
			}
"struct"	{
				//std::cout << "Line struct : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::STRUCT;
				return STRUCT;
			}
"switch"	{
				//std::cout << "Line switch : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::SWITCH;
				return SWITCH;
			}
"typedef"	{
				//std::cout << "Line typedef : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::TYPEDEF;
				return TYPEDEF;
			}
"union"		{
				//std::cout << "Line union : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::UNION;
				return UNION;
			}
"unsigned"	{
				//std::cout << "Line unsigned : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::UNSIGNED;
				return UNSIGNED;
			}
"void"		{
				//std::cout << "Line : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::VOID;
				return VOID;
			}
"volatil"	{
				//std::cout << "Line volatil : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::VOLATIL;
				return VOLATIL;
			}
"while"		{
				//std::cout << "Line : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::WHILE;
				return WHILE;
			}

"mov"		{
				//std::cout << "Line mov : " << yylineno << "\n";
				A_here::symbol_current = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current->line = yylineno;
				A_here::symbol_current->token = A_here::Tokens::MOV;
				return MOV;
			}

"al"	{
			//std::cout << "Line al : " << yylineno << "\n";
			A_here::symbol_current = A_here::block.create<A_here::Symbol>();
			A_here::symbol_current->line = yylineno;
			A_here::symbol_current->token = A_here::Tokens::AL;
			return AL;
		}
"ah"	{
			//std::cout << "Line ah : " << yylineno << "\n";
			A_here::symbol_current = A_here::block.create<A_here::Symbol>();
			A_here::symbol_current->line = yylineno;
			A_here::symbol_current->token = A_here::Tokens::AH;
			return AH;
		}

[[:space:]]			;

{IDENTIFIER}	{
			//std::cout << "Line IDENTIFIER : " << yylineno << "\n";
			A_here::Identifier* identifer;
			identifer = A_here::block.create<A_here::Identifier>();
			A_here::symbol_current = (A_here::Symbol*)identifer;
			identifer->line = yylineno;
			identifer->name.insert(0,yytext,yyleng);
			yylval->IDENTIFIER = identifer->name.c_str();
			return IDENTIFIER;
		}

{LITERAL_INTEGER_HEX}	{
				//std::cout << "Line LIETRAL_INTEGER_HEX : " << yylineno << "\n";
				A_here::Integer* integer;
				integer = A_here::block.create<A_here::Integer>();
				A_here::symbol_current = (A_here::Symbol*)integer;
				integer->line = yylineno;
				integer->format = 'H';
				integer->token = A_here::Tokens::LITERAL_INTEGER_HEX;
				integer->number = std::stoll(yytext, nullptr, 16);
				integer->strvalue.insert(0,yytext,yyleng);
				yylval->LITERAL_INTEGER_HEX = integer->number;
				return LITERAL_INTEGER_HEX;
			}
{LITERAL_INTEGER_DEC}	{
				//std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
				A_here::Integer* integer;
				integer = A_here::block.create<A_here::Integer>();
				A_here::symbol_current = (A_here::Symbol*)integer;
				integer->line = yylineno;
				integer->format = 'D';
				integer->token = A_here::Tokens::LITERAL_INTEGER_DEC;
				integer->number = std::stoll(yytext);
				integer->strvalue.insert(0,yytext,yyleng);
				yylval->LITERAL_INTEGER_DEC = integer->number;
				return LITERAL_INTEGER_DEC;
			}
{LITERAL_CHAR}		{
				//std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
				A_here::Symbol* letter;
				letter = A_here::block.create<A_here::Symbol>();
				A_here::symbol_current = (A_here::Symbol*)letter;
				letter->token = (A_here::Tokens)yytext[1];
				letter->line = yylineno;
				yylval->LITERAL_CHAR = yytext[1];
				letter->strvalue.insert(0,yytext,yyleng);
				//std::cout << "Line LIETRAL_CHAR : " << yylineno << "  " << letter->strvalue << "\n";
				return LITERAL_CHAR;
			}



[[:punct:]]	{
						//std::cout << "Line symbol '" << yytext[0] << "' : " << yylineno << "\n";
						A_here::symbol_current = A_here::block.create<A_here::Symbol>();
						A_here::symbol_current->line = yylineno;
						A_here::symbol_current->token = (A_here::Tokens)yytext[0];
						A_here::symbol_current->strvalue.insert(0,yytext,yyleng);
						return (yytoken_kind_t)yytext[0];
					}

<<EOF>>  	{
				return ENDOFFILE;
			}

.	;

%%





