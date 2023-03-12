
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
	#include <A+.hh>	
	namespace A_here = oct::cc::v0::A;
	extern A_here::File A_here::current_file;
}

// Emitted in the header file, after the definition of YYSTYPE.
%code provides
{
// Tell Flex the expected prototype of yylex.
// The scanner argument must be named yyscanner.
	#define YY_DECL                                                         \
	  	yytoken_kind_t poslex()
	  	YY_DECL;	
		#define yylex poslex

	void yyerror(const char *msg);
}

// Emitted on top of the implementation file.
%code top
{
	#include <stdarg.h> // va_list.
	#include <stdio.h>  // printf.
	#include <stdlib.h> // getenv.
}






// Don't share global variables between the scanner and the parser.
//%define api.pure full

// Generate YYSTYPE from the types assigned to symbols.
%define api.value.type union

// Error messages with "unexpected XXX, expected XXX...".
%define parse.error detailed

// Enable run-time traces (yydebug).
%define parse.trace

// Generate the parser description file (parse.output).
%verbose

// Scanner and error count are exchanged between main, yyparse and yylex.
//%param {yyscan_t scanner}{result *res}


//keywords
%token AUTO
%token BREAK
%token CASE
%token CHAR
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token ENUM
%token EXTERN
%token FLOAT
%token FOR
%token GOTO
%token IF
%token INT
%token LONG
%token REGISTER
%token RETURN
%token SHORT
%token SIGNED
%token SIZEOF
%token STATIC
%token STRUCT
%token SWITCH
%token TYPEDEF
%token UNION
%token UNSIGNED
%token VOID
%token VOLATIL
%token WHILE

//instruction set
%token keyword_mov

//rgisters
%token keyword_al
%token keyword_ah

%token <const char*>IDENTIFIER
%token <long long>LITERAL_INTEGER_DEC
%token <long long>LITERAL_INTEGER_HEX
%token <char>LITERAL_CHAR
%token ENDOFFILE 0  "end-of-file"
%type <long long> literals_integers 

%%

unit : decls insts ENDOFFILE;

decls : decl {printf("Declaration\n");}| decl decls {printf("Declaration\n");};
insts : inst {printf("Instruction\n");}| inst insts {printf("Instruction\n");};

inst : inst_mov | inst_int | label;
inst_mov : keyword_mov literals keyword_al ';' |		
		keyword_mov literals keyword_ah ';';		

inst_int : INT literals_integers ';';

label : IDENTIFIER ':';

decl :
	CHAR IDENTIFIER ';' 					|
	CHAR IDENTIFIER LITERAL_CHAR ';' 		|
	SHORT IDENTIFIER ';' 					|
	SHORT IDENTIFIER literals_integers ';'  |
	LONG IDENTIFIER ';' 					|
	LONG IDENTIFIER literals_integers ';' 	|
	INT IDENTIFIER ';'						|
	INT IDENTIFIER literals_integers ';'	
;


literals : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC | LITERAL_CHAR;
literals_integers : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC;

%%

void yyerror (const char  *s)
{
  fprintf (stderr, "%s\n", s);
}





