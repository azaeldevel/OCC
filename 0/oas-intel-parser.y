

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
	#include <A.hh>	
	namespace A_here = oct::cc::v0::A;
	extern A_here::File A_here::current_file;
}

// Emitted in the header file, after the definition of YYSTYPE.
%code provides
{
// Tell Flex the expected prototype of yylex.
// The scanner argument must be named yyscanner.
#define YY_DECL                                                         \
  	yytoken_kind_t yylex (YYSTYPE* yylval_param, yyscan_t yyscanner, result *res)
  	YY_DECL;

	void yyerror(yyscan_t scanner, result *res, const char *msg, ...);
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


//keywords
%token keyword_byte
%token keyword_char
%token keyword_short
%token keyword_int
%token keyword_long

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

decls : decl | decl decls;
insts : inst | inst insts;

inst : inst_mov | inst_int | label;
inst_mov : keyword_mov literals keyword_al ';' |		
		keyword_mov literals keyword_ah ';';		

inst_int : keyword_int literals_integers ';';

label : IDENTIFIER ':';

decl :
	keyword_byte IDENTIFIER ';' 					{printf("byte %s;\n",$2);}|
	keyword_byte IDENTIFIER literals_integers ';'	{printf("byte %s %i;\n",$2,$3);}|
	keyword_char IDENTIFIER ';' 					{printf("char %s;\n",$2);}|
	keyword_char IDENTIFIER LITERAL_CHAR ';' 		{printf("char %s '%c';\n",$2,$3);}|
	keyword_short IDENTIFIER ';' 					{printf("short %s;\n",$2);}|
	keyword_short IDENTIFIER literals_integers ';' 	{printf("short %s %i';\n",$2,$3);}|
	keyword_long IDENTIFIER ';' 					{printf("long %s;\n",$2);}|
	keyword_long IDENTIFIER literals_integers ';' 	{printf("long %s %i';\n",$2,$3);}|
	keyword_int IDENTIFIER ';'						{printf("int %s;\n",$2);}|
	keyword_int IDENTIFIER literals_integers ';'	{printf("int %s %i';\n",$2,$3);}
;


literals : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC | LITERAL_CHAR;
literals_integers : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC;

%%





