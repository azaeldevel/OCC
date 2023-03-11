
%option noyywrap reentrant bison-bridge yylineno

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

	#include "oas-intel-parser-A+.hh"
%}

DIGIT_DEC [0-9]
DIGIT_HEX [0-9A-Fa-f]
LETTER [a-zA-Z]
LITERAL_INTEGER_DEC {DIGIT_DEC}+
LIETRAL_INTEGER_HEX 0x{DIGIT_HEX}+
LIETRAL_CHAR '{LETTER}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

"byte"			{return keyword_byte;}
"char"			{return keyword_char;}
"short"			{return keyword_short;}
"long"			{return keyword_long;}
"int"		{return keyword_int;}

"mov"			{return keyword_mov;}

"al"			{return keyword_al;}
"ah"			{return keyword_ah;}

[\n\t ]			;

{IDENTIFIER}	{
					yylval->IDENTIFIER = new char[yyleng+1];
					memcpy((void*)yylval->IDENTIFIER,(const void*)yytext,yyleng);
					//yylval->IDENTIFIER[yyleng] = '\0';
					return IDENTIFIER;
				}//oct::cc::v0::A::add_identifier(yylineno,A_here::current_file.get_filename().string().c_str(),yytext,yyleng);

[:;]			{
					yylval->LITERAL_CHAR = yytext[0];
					return (yytoken_kind_t)yytext[0];
				}

{LIETRAL_INTEGER_HEX}		{return LITERAL_INTEGER_HEX;}
{LITERAL_INTEGER_DEC}		{
								const char* num = new char[yyleng+1];
								memcpy((void*)num,(const void*)yytext,yyleng);								
								yylval->LITERAL_INTEGER_DEC = std::stoll(num);
								return LITERAL_INTEGER_DEC;
							}
{LIETRAL_CHAR}				{
								yylval->LITERAL_CHAR = yytext[1];
								return LITERAL_CHAR;
							}


<<EOF>>  return ENDOFFILE;

.				;

%%
