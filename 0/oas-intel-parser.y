
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

	void yyerror (yyscan_t scanner, result *res, const char *msg, ...);
}

// Emitted on top of the implementation file.
%code top
{
#include <stdarg.h> // va_list.
#include <stdio.h>  // printf.
#include <stdlib.h> // getenv.
}






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
%token ENDOFFILE 0  "end-of-file"


%%

unit : decls insts ENDOFFILE;

decls : decl | decls decl;
insts : inst | insts inst;

inst : inst_mov | inst_int | label;
inst_mov : keyword_mov literals ',' keyword_al ';' |		
		keyword_mov literals ',' keyword_ah ';';		

inst_int : keyword_int LITERAL_INTEGER_HEX ';';

label : IDENTIFIER ':';

decl :
	keyword_byte IDENTIFIER ';' 					|
	keyword_byte IDENTIFIER literals_integers ';'	|
	keyword_char IDENTIFIER ';' 					|
	keyword_char IDENTIFIER LITERAL_CHAR ';' 		|
	keyword_tiny IDENTIFIER ';' 					|
	keyword_tiny IDENTIFIER literals_integers ';' 	|
	keyword_short IDENTIFIER ';' 					|
	keyword_short IDENTIFIER literals_integers ';' 	|
	keyword_medium IDENTIFIER ';' 					|
	keyword_medium IDENTIFIER literals_integers ';' |
	keyword_long IDENTIFIER ';' 					|
	keyword_long IDENTIFIER literals_integers ';' 	|
	keyword_integer '<' LITERAL_INTEGER_DEC '>' IDENTIFIER ';'						|
	keyword_integer '<' LITERAL_INTEGER_DEC '>' IDENTIFIER literals_integers ';'	
;


literals : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC | LITERAL_CHAR;
literals_integers : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC;

%%





