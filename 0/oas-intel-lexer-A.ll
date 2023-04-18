
%{
	#include <assert.h>
	#include <limits.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	//#include <core/3/math.hh>
	#include <A-Scanner.hh>
	#include <AI/oas-intel-parser-A.hh>
	#include <AI.hh>
	namespace AI_here = oct::cc::v0::AI;
	namespace core_here = oct::core::v3;
	core_here::Block AI_here::block;

    #undef yyFlexLexer
    #define yyFlexLexer AIFlexLexer

    #undef  YY_DECL
    #define YY_DECL int AI_here::Scanner::yylex( parser::semantic_type * const lval, parser::location_type *loc)

    /* typedef to make the returns for the tokens shorter */
    using token = AI_here::parser::token;

    /* define yyterminate as this instead of NULL */
    #define yyterminate() return( token::END )

    /* msvc2010 requires that we exclude this header file. */
    #define YY_NO_UNISTD_H

    /* update location on matching */
    #define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option prefix="AI"
%option debug
%option nodefault
%option yyclass="oct::cc::v0::AI::Scanner"
%option noyywrap
%option c++

DIGIT_DEC [[:digit:]]
DIGIT_HEX [[:xdigit:]]
CHAR [[:alpha:][:digit:][:punct:][:graph:][:blank:]]
LITERAL_INTEGER_DEC [+-]?{DIGIT_DEC}+
LITERAL_INTEGER_HEX 0x{DIGIT_HEX}+
LITERAL_CHAR '{CHAR}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%
%{          /** Code executed at the beginning of yylex **/
	yylval = lval;// A handy shortcut to the location held by the driver.
	//yy::location& loc = driver.location;
	loc->step ();
%}


"mov"   {return token::MOV;}
"al"	return token::AL;
"ah"	return token::AH;



"byte"		return token::BYTE;
"auto"		return token::AUTO;
"char"		return token::CHAR;

"break"		return token::BREAK;
"case"		return token::CASE;
"const"		return token::CONST;
"continue"	return token::CONTINUE;
"default"	return token::DEFAULT;
"do"		return token::DO;
"double"	return token::DOUBLE;
"else"		return token::ELSE;
"enum"		return token::ENUM;
"extern"	return token::EXTERN;
"float"		return token::FLOAT;
"for"		return token::FOR;
"goto"		return token::GOTO;
"if"		return token::IF;
"int"		return token::INT;
"long"		return token::LONG;
"register"	return token::REGISTER;
"return"	return token::RETURN;
"short"		return token::SHORT;
"signed"	return token::SIGNED;
"sizeof"	return token::SIZEOF;
"static"	return token::STATIC;
"struct"	return token::STRUCT;
"switch"	return token::SWITCH;
"typedef"	return token::TYPEDEF;
"union"		return token::UNION;
"unsigned"	return token::UNSIGNED;
"void"		return token::VOID;
"volatil"	return token::VOLATIL;
"while"		return token::WHILE;



[[:space:]]			;

{IDENTIFIER}	{
			//std::cout << "Line IDENTIFIER : " << yylineno << "\n";
			AI_here::nodes::identifier* identifer = AI_here::block.create<AI_here::nodes::identifier>();
			identifer->line = yylineno;
			identifer->name = yytext;
			yylval->build<AI_here::nodes::identifier*>(identifer);
            return token::IDENTIFIER;
		}

{LITERAL_INTEGER_HEX}	{
				//std::cout << "Line LIETRAL_INTEGER_HEX : " << yylineno << "\n";
				AI_here::nodes::Integer* integer = AI_here::block.create<AI_here::nodes::Integer>();
				//AI_here::symbol_current = (AI_here::nodes::Symbol*)integer;
				integer->line = yylineno;
				integer->format = 'H';
				integer->token = AI_here::Tokens::LITERAL_INTEGER_HEX;
				integer->number = std::stoll(yytext, nullptr, 16);
				//integer->strvalue = yytext;
				yylval->build<long long>(integer->number);
				return token::LITERAL_INTEGER_HEX;
			}
{LITERAL_INTEGER_DEC}	{
				//std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
				AI_here::nodes::Integer* integer = AI_here::block.create<AI_here::nodes::Integer>();
				//AI_here::symbol_current = (AI_here::nodes::Symbol*)integer;
				integer->line = yylineno;
				integer->format = 'D';
				integer->token = AI_here::Tokens::LITERAL_INTEGER_DEC;
				integer->number = std::stoll(yytext);
				//integer->strvalue = yytext;
				yylval->build<long long>(integer->number);
				return token::LITERAL_INTEGER_HEX;
			}
{LITERAL_CHAR}		{
				//std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
				AI_here::nodes::Node* letter = AI_here::block.create<AI_here::nodes::Node>();
				letter->token = (AI_here::Tokens)yytext[1];
				letter->line = yylineno;
				//letter->strvalue = yytext;
				//std::cout << "Line LIETRAL_CHAR : " << yylineno << "  " << letter->strvalue << "\n";
				yylval->build<char>(yytext[1]);
				return token::LITERAL_CHAR;
			}



[[:punct:]]	{
				//std::cout << "Lexer(" << yytext[0] << ") ";
				return yytext[0];
            }

<<EOF>>  	{
				return token::ENDOFFILE;
			}

.	;

%%





