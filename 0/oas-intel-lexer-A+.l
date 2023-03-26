
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
	A_here::Symbol* symbol_current;
		
%}

DIGIT_DEC [0-9]
DIGIT_HEX [0-9A-Fa-f]
CHAR [a-zA-Z]
LITERAL_INTEGER_DEC [+-]?{DIGIT_DEC}+
LITERAL_INTEGER_HEX 0x{DIGIT_HEX}+
LITERAL_CHAR '{CHAR}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

"auto"		{		
				//std::cout << "Line auto : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::AUTO;
				return AUTO;
			}
"break"		{
				//std::cout << "Line break : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::BREAK;
				return BREAK;
			}
"case"		{
				//std::cout << "Line case : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::CASE;
				return CASE;
			}
"char"		{
				//std::cout << "Line char : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::CHAR;
				return CHAR;
			}
"const"		{
				//std::cout << "Line const : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::CONST;
				return CONST;
			}
"continue"	{
				//std::cout << "Line continue : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::CONTINUE;
				return CONTINUE;
			}
"default"	{
				//std::cout << "Line default : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::DEFAULT;
				return DEFAULT;
			}
"do"		{
				//std::cout << "Line do : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::DO;
				return DO;
			}
"double"	{
				//std::cout << "Line double : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::DOUBLE;
				return DOUBLE;
			}
"else"		{
				//std::cout << "Line else : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::ELSE;
				return ELSE;
			}
"enum"		{
				//std::cout << "Line enum : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::ENUM;
				return ENUM;
			}
"extern"	{
				//std::cout << "Line extern : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::EXTERN;
				return EXTERN;
			}
"float"		{
				//std::cout << "Line float : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::FLOAT;
				return FLOAT;
			}
"for"		{
				//std::cout << "Line for : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::FOR;
				return FOR;
			}
"goto"		{
				//std::cout << "Line goto : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::GOTO;
				return GOTO;
			}
"if"		{
				//std::cout << "Line if : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::IF;
				return IF;
			}
"int"		{
				//std::cout << "Line int : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::INT;
				return INT;
			}
"long"		{
				//std::cout << "Line long : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::LONG;
				return LONG;
			}
"register"	{
				//std::cout << "Line register : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::REGISTER;
				return REGISTER;
			}
"return"	{
				//std::cout << "Line return : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::RETURN;
				return RETURN;
			}
"short"		{
				//std::cout << "Line short : " << yylineno << "\n";
				//std::cout << "Step 1\n";
				//std::cout << "Step 2\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				//std::cout << "Step 3\n";
				symbol_current->line = yylineno;
				//std::cout << "Step 4\n";
				symbol_current->token = A_here::Tokens::SHORT;
				//std::cout << "Step 5\n";
				return SHORT;
			}
"signed"	{
				//std::cout << "Line signed : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::SIGNED;
				return SIGNED;
			}
"sizeof"	{
				//std::cout << "Line sizeof : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::SIZEOF;
				return SIZEOF;
			}
"static"	{
				//std::cout << "Line static : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::STATIC;
				return STATIC;
			}
"struct"	{
				//std::cout << "Line struct : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::STRUCT;
				return STRUCT;
			}
"switch"	{
				//std::cout << "Line switch : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::SWITCH;
				return SWITCH;
			}
"typedef"	{
				//std::cout << "Line typedef : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::TYPEDEF;
				return TYPEDEF;
			}
"union"		{
				//std::cout << "Line union : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::UNION;
				return UNION;
			}
"unsigned"	{
				//std::cout << "Line unsigned : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::UNSIGNED;
				return UNSIGNED;
			}
"void"		{
				//std::cout << "Line : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::VOID;
				return VOID;
			}
"volatil"	{
				//std::cout << "Line volatil : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::VOLATIL;
				return VOLATIL;
			}
"while"		{
				//std::cout << "Line : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::WHILE;
				return WHILE;
			}

"mov"		{
				//std::cout << "Line while : " << yylineno << "\n";
				symbol_current = A_here::block.create<A_here::Symbol>();
				symbol_current->line = yylineno;
				symbol_current->token = A_here::Tokens::MOV;
				return MOV;
			}

"al"	{
			//std::cout << "Line al : " << yylineno << "\n";
			symbol_current = A_here::block.create<A_here::Symbol>();
			symbol_current->line = yylineno;
			symbol_current->token = A_here::Tokens::AL;
			return AL;
		}
"ah"	{
			//std::cout << "Line ah : " << yylineno << "\n";
			symbol_current = A_here::block.create<A_here::Symbol>();
			symbol_current->line = yylineno;
			symbol_current->token = A_here::Tokens::AH;
			return AH;
		}

[\n\t ]			;

{IDENTIFIER}	{								
					//std::cout << "Line IDENTIFIER : " << yylineno << "\n";
					A_here::Identifier* identifer;
					identifer = A_here::block.create<A_here::Identifier>();
					symbol_current = (A_here::Symbol*)identifer;
					identifer->line = yylineno;
					identifer->name.insert(0,yytext,yyleng);	
					yylval->IDENTIFIER = identifer->name.c_str();					
					return IDENTIFIER;
				}

[!"#%'()*+,-./:;<=>?\[\\\]^_\{|\}~]	{
										//std::cout << "Line '" << yytext[0] << "'" << yylineno << "\n";
										symbol_current = A_here::block.create<A_here::Symbol>();
										symbol_current->line = yylineno;
										symbol_current->token = (A_here::Tokens)yytext[0];
										return (yytoken_kind_t)yytext[0];
									}

{LITERAL_INTEGER_HEX}	{
							//std::cout << "Line LIETRAL_INTEGER_HEX : " << yylineno << "\n";
							A_here::Integer* integer;
							integer = A_here::block.create<A_here::Integer>();	
							symbol_current = (A_here::Symbol*)integer;
							integer->line = yylineno;
							integer->format = 'H';		
							integer->token = A_here::Tokens::LITERAL_INTEGER_HEX;				
							integer->number = std::stoll(yytext, nullptr, 16);	
							yylval->LITERAL_INTEGER_HEX = integer->number;							
							return (yytoken_kind_t)(int)A_here::integer_token(integer->number);
						}
{LITERAL_INTEGER_DEC}	{
							//std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
							A_here::Integer* integer;
							integer = A_here::block.create<A_here::Integer>();
							symbol_current = (A_here::Symbol*)integer;
							integer->line = yylineno;		
							integer->format = 'D';
							integer->token = A_here::Tokens::LITERAL_INTEGER_DEC;					
							integer->number = std::stoll(yytext);
							yylval->LITERAL_INTEGER_DEC = integer->number;
							return (yytoken_kind_t)(int)A_here::integer_token(integer->number);
						}
{LITERAL_CHAR}		{
						//std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
						A_here::Symbol* letter;
						letter = A_here::block.create<A_here::Symbol>();
						symbol_current = (A_here::Symbol*)letter;
						letter->token = (A_here::Tokens)yytext[1];
						letter->line = yylineno;
						yylval->LITERAL_CHAR = (char)letter->token;
						return LITERAL_CHAR;
					}

<<EOF>>  	{
				return ENDOFFILE;
			}

.	;

%%





