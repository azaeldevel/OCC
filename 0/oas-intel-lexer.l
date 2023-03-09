
%option noyywrap reentrant bison-bridge yylineno

%{
	#include <assert.h>
	#include <limits.h>
	#include <stdlib.h>

	#include <A.hh>	

	#include "oas-intel-parser.hh"
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

struct instance
{
	yyscan_t scanner;
	FILE* file;
	char* filename;
	YY_BUFFER_STATE buffer;
};

struct instance open_file(char* fn)
{
	struct instance inst;
  	yylex_init (&inst.scanner);
	inst.file = fopen(fn, "r" );
    if (inst.file) return inst;
	inst.buffer = yy_create_buffer(inst.file, YY_BUF_SIZE, inst.scanner);
    yy_switch_to_buffer(inst.buffer, inst.scanner);

	return inst;
}

void close_file(struct instance* inst)
{
  	yy_delete_buffer (inst->buffer, inst->scanner);
  	yylex_destroy (inst->scanner);
}


