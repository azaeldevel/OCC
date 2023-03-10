
%option noyywrap reentrant bison-bridge yylineno

%{
	#include <assert.h>
	#include <limits.h>
	#include <stdlib.h>

	#include <A.hh>	
	namespace A_here = oct::cc::v0::A;
	A_here::File A_here::current_file;

	#include "oas-intel-parser.hh"
%}

DIGIT_DEC [0-9]
DIGIT_HEX [0-9(A-F)|(a-f)]
LETTER [a-zA-Z]
LIETRAL_INTEGER_DEC {DIGIT_DEC}+
LIETRAL_INTEGER_HEX 0x{DIGIT_HEX}+
LIETRAL_CHAR '{LETTER}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

"byte"			{return keyword_byte;}
"char"			{return keyword_char;}
"tiny"			{return keyword_tiny;}
"short"			{return keyword_short;}
"medium"		{return keyword_medium;}
"long"			{return keyword_long;}
"integer"		{return keyword_integer;}

"int"			{return keyword_int;}
"mov"			{return keyword_mov;}

"al"			{return keyword_al;}
"ah"			{return keyword_ah;}

{LIETRAL_INTEGER_HEX}		{return LITERAL_INTEGER_HEX;}
{LIETRAL_INTEGER_DEC}		{return LITERAL_INTEGER_DEC;}


{IDENTIFIER}		{oct::cc::v0::A::add_identifier(yylineno,A_here::current_file.get_filename().string().c_str(),yytext,yyleng);return IDENTIFIER;}
{LIETRAL_CHAR}		{return LITERAL_CHAR;}


,			return (yytoken_kind_t)',';
:			return (yytoken_kind_t)':';
;			return (yytoken_kind_t)';';

<<EOF>>  return ENDOFFILE;

[.\n\t ]				;

%%
