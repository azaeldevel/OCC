
%option nodefault noinput nounput noyywrap
%option reentrant


%{
#include <assert.h>
#include <limits.h> /* INT_MIN */
#include <stdlib.h> /* strtol */

//#include "oas-intel.tab.h"
#include "oas-intel-parser.tab.h"
%}

DIGIT_DEC [0-9]
DIGIT_HEX [0-9A-Fa-f]
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


{IDENTIFIER}		{return IDENTIFIER;}
{LIETRAL_CHAR}		{return LITERAL_CHAR;}


,			return ',';
:			return ':';
;			return ';';

<<EOF>>  return ENDOFFILE;

[.\n\t ]				;

%%

