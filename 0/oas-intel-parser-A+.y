
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
%token MOV

//registers
%token AL
%token AH
%token AX
%token BL
%token BH
%token BX
%token CL
%token CH
%token CX
%token DH
%token DL
%token DX



%token ENDOFFILE 0  "end-of-file"
%token <long long>LITERAL_INTEGER_DEC
%token <signed char>LITERAL_INTEGER_DEC_SCHAR	
%token <unsigned char>LITERAL_INTEGER_DEC_UCHAR
%token <short> LITERAL_INTEGER_DEC_SHORT
%token <unsigned short> LITERAL_INTEGER_DEC_USHORT
%token <long long>LITERAL_INTEGER_HEX
%token <signed char>LITERAL_INTEGER_HEX_SCHAR		
%token <unsigned char>LITERAL_INTEGER_HEX_UCHAR
%token <short> LITERAL_INTEGER_HEX_SHORT
%token <unsigned short> LITERAL_INTEGER_HEX_USHORT
%token <char> LITERAL_CHAR
%token <const char*> IDENTIFIER
%type <long long> literals_integers 

%%

unit : decls insts ENDOFFILE;

decls : decl {printf("Declaration\n");}| decls decl {printf("Declaration\n");};
insts : inst {printf("Instruction\n");}| insts inst {printf("Instruction\n");};

inst : inst_mov | inst_int | inst_label ;
inst_mov : MOV registers_8b literals_8b ';' | MOV registers_16b literals_16b ';';		
inst_int : INT literals_integers ';';
inst_label : IDENTIFIER ':';

decl :
	CHAR IDENTIFIER initializer_char ';' 	|
	SHORT IDENTIFIER initializer_integer ';'|
	LONG IDENTIFIER initializer_integer ';' |
	INT IDENTIFIER initializer_integer ';'	
;


literals_8b : LITERAL_CHAR | LITERAL_INTEGER_DEC_UCHAR | LITERAL_INTEGER_DEC_SCHAR;
literals_16b : LITERAL_INTEGER_DEC_USHORT | LITERAL_INTEGER_DEC_SHORT;
literals_integers : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC;
initializer_char : LITERAL_CHAR | ;
initializer_integer : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC | ;

registers_8b : AL | AH ;
registers_16b : AX ;

%%

void yyerror (const char  *s)
{
  fprintf (stderr, "%s\n", s);
}





