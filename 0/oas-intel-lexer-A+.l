
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
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    ENDOFFILE = 0,                 /* "end-of-file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    keyword_byte = 258,            /* keyword_byte  */
    keyword_char = 259,            /* keyword_char  */
    keyword_short = 260,           /* keyword_short  */
    keyword_int = 261,             /* keyword_int  */
    keyword_long = 262,            /* keyword_long  */
    keyword_mov = 263,             /* keyword_mov  */
    keyword_al = 264,              /* keyword_al  */
    keyword_ah = 265,              /* keyword_ah  */
    IDENTIFIER = 266,              /* IDENTIFIER  */
    LITERAL_INTEGER_DEC = 267,     /* LITERAL_INTEGER_DEC  */
    LITERAL_INTEGER_HEX = 268,     /* LITERAL_INTEGER_HEX  */
    LITERAL_CHAR = 269             /* LITERAL_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

#define YY_DECL yytoken_kind_t lexer()

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
					return IDENTIFIER;
				}//oct::cc::v0::A::add_identifier(yylineno,A_here::current_file.get_filename().string().c_str(),yytext,yyleng);

[:;]			{
					return (yytoken_kind_t)yytext[0];
				}

{LIETRAL_INTEGER_HEX}		{return LITERAL_INTEGER_HEX;}
{LITERAL_INTEGER_DEC}		{
								return LITERAL_INTEGER_DEC;
							}
{LIETRAL_CHAR}				{
								return LITERAL_CHAR;
							}


<<EOF>>  return ENDOFFILE;

.				;

%%
