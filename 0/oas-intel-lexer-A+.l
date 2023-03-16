
%option noyywrap yylineno bison-bridge reentrant

%{
	#include <assert.h>
	#include <limits.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	//#include <core/3/math.hh>


	#include <A+.hh>	
	namespace A_here = oct::cc::v0::A;
	namespace core_here = oct::core::v3;
	A_here::File A_here::current_file;
	A_here::Block A_here::block;
	//A_here::Symbol* A_here::current_symbol;	
	//#define YY_DECL A_here::Tokens lexer()	
%}

DIGIT_DEC [0-9]
DIGIT_HEX [0-9A-Fa-f]
LETTER [a-zA-Z]
LITERAL_INTEGER_DEC [+-]?{DIGIT_DEC}+
LIETRAL_INTEGER_HEX 0x{DIGIT_HEX}+
LIETRAL_CHAR '{LETTER}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

"auto"		{		
				std::cout << "Line auto : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::AUTO;
				return AUTO;
			}
"break"		{
				std::cout << "Line break : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::BREAK;
				return yytoken_kind_t::BREAK;
			}
"case"		{
				std::cout << "Line case : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::CASE;
				return A_here::Tokens::CASE;
			}
"char"		{
				std::cout << "Line char : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::CHAR;
				return A_here::Tokens::CHAR;
			}
"const"		{
				std::cout << "Line const : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::CONST;
				return A_here::Tokens::CONST;
			}
"continue"	{
				std::cout << "Line continue : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::CONTINUE;
				return A_here::Tokens::CONTINUE;
			}
"default"	{
				std::cout << "Line default : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::DEFAULT;
				return A_here::Tokens::DEFAULT;
			}
"do"		{
				std::cout << "Line do : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::DO;
				return A_here::Tokens::DO;
			}
"double"	{
				std::cout << "Line double : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::DOUBLE;
				return A_here::Tokens::DOUBLE;
			}
"else"		{
				std::cout << "Line else : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::ELSE;
				return A_here::Tokens::ELSE;
			}
"enum"		{
				std::cout << "Line enum : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::ENUM;
				return A_here::Tokens::ENUM;
			}
"extern"	{
				std::cout << "Line extern : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::EXTERN;
				return A_here::Tokens::EXTERN;
			}
"float"		{
				std::cout << "Line float : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::FLOAT;
				return A_here::Tokens::FLOAT;
			}
"for"		{
				std::cout << "Line for : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::FOR;
				return A_here::Tokens::FOR;
			}
"goto"		{
				std::cout << "Line goto : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::GOTO;
				return A_here::Tokens::GOTO;
			}
"if"		{
				std::cout << "Line if : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::IF;
				return A_here::Tokens::IF;
			}
"int"		{
				std::cout << "Line int : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::INT;
				return A_here::Tokens::INT;
			}
"long"		{
				std::cout << "Line long : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::LONG;
				return A_here::Tokens::LONG;
			}
"register"	{
				std::cout << "Line register : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::REGISTER;
				return A_here::Tokens::REGISTER;
			}
"return"	{
				std::cout << "Line return : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::RETURN;
				return A_here::Tokens::RETURN;
			}
"short"		{
				std::cout << "Line short : " << yylineno << "\n";
				std::cout << "Step 1\n";
				A_here::Symbol* symbol;
				std::cout << "Step 2\n";
				symbol = A_here::block.create<A_here::Symbol>();
				std::cout << "Step 3\n";
				symbol->line = yylineno;
				std::cout << "Step 4\n";
				symbol->token = A_here::Tokens::SHORT;
				std::cout << "Step 5\n";
				return A_here::Tokens::SHORT;
			}
"signed"	{
				std::cout << "Line signed : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::SIGNED;
				return A_here::Tokens::SIGNED;
			}
"sizeof"	{
				std::cout << "Line sizeof : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::SIZEOF;
				return A_here::Tokens::SIZEOF;
			}
"static"	{
				std::cout << "Line static : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::STATIC;
				return A_here::Tokens::STATIC;
			}
"struct"	{
				std::cout << "Line struct : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::STRUCT;
				return A_here::Tokens::STRUCT;
			}
"switch"	{
				std::cout << "Line switch : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::SWITCH;
				return A_here::Tokens::SWITCH;
			}
"typedef"	{
				std::cout << "Line typedef : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::TYPEDEF;
				return A_here::Tokens::TYPEDEF;
			}
"union"		{
				std::cout << "Line : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::UNION;
				return A_here::Tokens::UNION;
			}
"unsigned"	{
				std::cout << "Line union : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::UNSIGNED;
				return A_here::Tokens::UNSIGNED;
			}
"void"		{
				std::cout << "Line : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::VOID;
				return A_here::Tokens::VOID;
			}
"volatil"	{
				std::cout << "Line volatil : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::VOLATIL;
				return A_here::Tokens::VOLATIL;
			}
"while"		{
				std::cout << "Line : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::WHILE;
				return A_here::Tokens::WHILE;
			}

"mov"		{
				std::cout << "Line while : " << yylineno << "\n";
				A_here::Symbol* symbol;
				symbol = A_here::block.create<A_here::Symbol>();
				symbol->line = yylineno;
				symbol->token = A_here::Tokens::MOV;
				return A_here::Tokens::MOV;
			}

"al"	{
			std::cout << "Line al : " << yylineno << "\n";
			A_here::Symbol* symbol;
			symbol = A_here::block.create<A_here::Symbol>();
			symbol->line = yylineno;
			symbol->token = A_here::Tokens::AL;
			return A_here::Tokens::AL;
		}
"ah"	{
			std::cout << "Line ah : " << yylineno << "\n";
			A_here::Symbol* symbol;
			symbol = A_here::block.create<A_here::Symbol>();
			symbol->line = yylineno;
			symbol->token = A_here::Tokens::AH;
			return A_here::Tokens::AH;
		}

[\n\t ]			;

{IDENTIFIER}	{								
					std::cout << "Line IDENTIFIER : " << yylineno << "\n";
					A_here::Identifier* identifier;
					identifier = A_here::block.create<A_here::Identifier>();
					identifier->line = yylineno;
					identifier->name.insert(0,yytext,yyleng);					
					return A_here::Tokens::identifier;
				}

[!"#%'()*+,-./:;<=>?\[\\\]^_\{|\}~]	{
										std::cout << "Line !#%'()* ... : " << yylineno << "\n";
										A_here::Symbol* letter;
										letter = A_here::block.create<A_here::Symbol>();
										letter->line = yylineno;
										letter->token = (A_here::Tokens)yytext[0];
										return (A_here::Tokens)yytext[0];
									}

{LIETRAL_INTEGER_HEX}	{
							std::cout << "Line LIETRAL_INTEGER_HEX : " << yylineno << "\n";
							A_here::Integer* integer;
							integer = A_here::block.create<A_here::Integer>();	
							integer->line = yylineno;
							integer->format = 'H';		
							integer->token = A_here::Tokens::LITERAL_INTEGER_HEX;				
							integer->number = std::stoll(yytext, nullptr, 16);								
							return integer->reduced_token();
						}
{LITERAL_INTEGER_DEC}	{
							std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
							A_here::Integer* integer;
							integer = A_here::block.create<A_here::Integer>();
							integer->line = yylineno;		
							integer->format = 'D';
							integer->token = A_here::Tokens::LITERAL_INTEGER_DEC;					
							integer->number = std::stoll(yytext);
							return integer->reduced_token();
						}
{LIETRAL_CHAR}		{
						std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
						A_here::Symbol* letter;
						letter = A_here::block.create<A_here::Symbol>();
						letter->token = (A_here::Tokens)yytext[0];
						letter->line = yylineno;
						return A_here::Tokens::LITERAL_CHAR;
					}

<<EOF>>  	{
				std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
				A_here::Symbol* letter;
				letter = A_here::block.create<A_here::Symbol>();
				letter->token = A_here::Tokens::NUL;
				letter->line = yylineno;
				return A_here::Tokens::NUL;
			}

.	;

%%
