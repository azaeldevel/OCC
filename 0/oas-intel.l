%option nodefault noinput nounput noyywrap

%option reentrant

%{
#include <assert.h>
#include <limits.h> /* INT_MIN */
#include <stdlib.h> /* strtol */

#include "oas-intel.tab.h"
%}

DIGIT_DEC [0-9]
DIGIT_HEX [0-9A-Fa-f]
LETTER [a-zA-Z]
LIETRAL_INTEGER_DEC {DIGIT_DEC}+
LIETRAL_INTEGER_HEX 0x{DIGIT_HEX}+
LIETRAL_CHAR '{LETTER}'

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*

%%

"byte"			{printf("keyword byte\n");}
"char"			{printf("keyword char\n");}
"tiny"			{printf("keyword tiny\n");}
"short"			{printf("keyword short\n");}
"medium"		{printf("keyword medium\n");}
"long"			{printf("keyword long\n");}
"integer"		{printf("keyword integer\n");}

"int"			{printf("keyword int\n");}
"mov"			{printf("keyword mov\n");}

"al"			{printf("keyword al\n");}
"ah"			{printf("keyword ah\n");}

{LIETRAL_INTEGER_HEX}		{printf("Hexadecimal \"%s\"\n",yytext);}
{LIETRAL_INTEGER_DEC}		{printf("Entero \"%s\"\n",yytext);}


{IDENTIFIER}		{printf("Identificador \"%s\"\n",yytext);}
{LIETRAL_CHAR}		{printf("Literal char \"%s\"\n",yytext);}

[,:;]			{printf("Simbol \"%s\"\n",yytext);}

[.\n\t ]				;

%%

