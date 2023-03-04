
%expect 0

// Emitted in the header file, before the definition of YYSTYPE.
%code requires
{
  #ifndef YY_TYPEDEF_YY_SCANNER_T
  # define YY_TYPEDEF_YY_SCANNER_T
  typedef void* yyscan_t;
  #endif

  typedef struct
  {
    // Whether to print the intermediate results.
    int verbose;
    // Value of the last computation.
    int value;
    // Number of errors.
    int nerrs;
  } result;
}

// Emitted in the header file, after the definition of YYSTYPE.
%code provides
{
  // Tell Flex the expected prototype of yylex.
  // The scanner argument must be named yyscanner.
#define YY_DECL                                                         \
  yytoken_kind_t yylex (YYSTYPE* yylval, yyscan_t yyscanner, result *res)
  YY_DECL;

  void yyerror (yyscan_t scanner, result *res, const char *msg, ...);
}

// Emitted on top of the implementation file.
%code top
{
#include <stdarg.h> // va_list.
#include <stdio.h>  // printf.
#include <stdlib.h> // getenv.
}

%code
{
  result parse_string (const char* cp);
  result parse (void);
}

// Include the header in the implementation rather than duplicating it.
//%define api.header.include {"parse.h"}

// Don't share global variables between the scanner and the parser.
%define api.pure full

// Generate YYSTYPE from the types assigned to symbols.
%define api.value.type union

// Error messages with "unexpected XXX, expected XXX...".
%define parse.error detailed

// Enable run-time traces (yydebug).
%define parse.trace

// Generate the parser description file (parse.output).
%verbose

// Scanner and error count are exchanged between main, yyparse and yylex.
%param {yyscan_t scanner}{result *res}





%token keyword_byte
%token keyword_char
%token keyword_tiny
%token keyword_short
%token keyword_medium
%token keyword_long
%token keyword_integer

//instruction set
%token keyword_int
%token keyword_mov

//
%token keyword_al
%token keyword_ah

%token IDENTIFIER
%token LITERAL_INTEGER_DEC
%token LITERAL_INTEGER_HEX
%token LITERAL_CHAR



%%

stm : stm
	decl | 
	label | 
	insts ;


insts : insts_mov | insts_int;

insts_mov : keyword_mov LITERAL_CHAR ',' LITERAL_INTEGER_HEX ';';

insts_int : keyword_int LITERAL_INTEGER_HEX ';';

label : IDENTIFIER ':';

decl :
	keyword_byte IDENTIFIER ';' |
	keyword_char IDENTIFIER LITERAL_CHAR ';' |
	keyword_char IDENTIFIER ';' |
	keyword_tiny IDENTIFIER LITERAL_INTEGER_HEX ';' |
	keyword_tiny IDENTIFIER LITERAL_INTEGER_DEC ';' |
	keyword_tiny IDENTIFIER ';' |
	keyword_short IDENTIFIER ';' |
	keyword_short IDENTIFIER LITERAL_INTEGER_HEX ';' |
	keyword_short IDENTIFIER LITERAL_INTEGER_DEC ';' |
	keyword_medium IDENTIFIER LITERAL_INTEGER_HEX ';' |
	keyword_medium IDENTIFIER LITERAL_INTEGER_DEC ';' |
	keyword_medium IDENTIFIER ';' |
	keyword_long IDENTIFIER LITERAL_INTEGER_HEX ';' |
	keyword_long IDENTIFIER LITERAL_INTEGER_DEC ';' |
	keyword_long IDENTIFIER ';' |
	keyword_integer '<' keyword_tiny '>' IDENTIFIER LITERAL_INTEGER_HEX ';'|
	keyword_integer '<' keyword_tiny '>' IDENTIFIER LITERAL_INTEGER_DEC ';'|
	keyword_integer '<' keyword_tiny '>' IDENTIFIER ';'
;

%%

#include "oas-intel.tab.h"
#include "oas-intel-parser.tab.h"

result
parse (void)
{
  yyscan_t scanner;
  yylex_init (&scanner);
  result res = {1, 0, 0};
  yyparse (scanner, &res);
  yylex_destroy (scanner);
  return res;
}

result parse_string (const char *str)
{
  yyscan_t scanner;
  yylex_init (&scanner);
  YY_BUFFER_STATE buf = yy_scan_string (str ? str : "", scanner);
  result res = {0, 0, 0};
  yyparse (scanner, &res);
  yy_delete_buffer (buf, scanner);
  yylex_destroy (scanner);
  return res;
}

void yyerror (yyscan_t scanner, result *res,const char *msg, ...)
{
  (void) scanner;
  va_list args;
  va_start (args, msg);
  vfprintf (stderr, msg, args);
  va_end (args);
  fputc ('\n', stderr);
  res->nerrs += 1;
}

int main (void)
{
  // Possibly enable parser runtime debugging.
  yydebug = !!getenv ("YYDEBUG");
  result res = parse ();
  // Exit on failure if there were errors.
  return !!res.nerrs;
}


