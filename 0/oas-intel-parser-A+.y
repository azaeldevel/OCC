
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
	  	yytoken_kind_t yylex (YYSTYPE* yylval_param, const YYLTYPE *loc, yyscan_t yyscanner, result *res)
	  	YY_DECL;	
		//#define yylex poslex

	void yyerror(const YYLTYPE *loc, yyscan_t scanner, result *res, const char *msg, ...);
}

// Emitted on top of the implementation file.
%code top
{
	#include <stdarg.h> // va_list.
	#include <stdio.h>  // printf.
	#include <stdlib.h> // getenv.
}

// with locations.
%locations

// Don't share global variables between the scanner and the parser.
%define api.pure full

// Generate YYSTYPE from the types assigned to symbols.
//%define api.value.type union

// Error messages with "unexpected XXX, expected XXX...".
%define parse.error detailed

// Enable run-time traces (yydebug).
%define parse.trace

// Generate the parser description file (parse.output).
%verbose

// Scanner and error count are exchanged between main, yyparse and yylex.
%param {yyscan_t scanner}{result *res}




%token ENDOFFILE 0  "end-of-file"

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

%token LITERAL_INTEGER_DEC
%token LITERAL_INTEGER_DEC_SCHAR	
%token LITERAL_INTEGER_DEC_UCHAR
%token LITERAL_INTEGER_DEC_SHORT
%token LITERAL_INTEGER_DEC_USHORT
%token LITERAL_INTEGER_HEX
%token LITERAL_INTEGER_HEX_SCHAR		
%token LITERAL_INTEGER_HEX_UCHAR
%token LITERAL_INTEGER_HEX_SHORT
%token LITERAL_INTEGER_HEX_USHORT
%token LITERAL_CHAR
%token IDENTIFIER
%type literals_integers 

%%

translation_unit : external_declaration ENDOFFILE |
	external_declaration translation_unit ENDOFFILE
	;

external_declaration : function_implementation |
	declaration ';'
	;

function_implementation : 
	declaration_specifiers declarator declaration_list compound_statement |
	declaration_specifiers declarator compound_statement |
	declarator declaration_list compound_statement |
	declarator compound_statement
	;

//6.5
declaration : declaration_specifiers init_declarator_list | declaration_specifiers;
declaration_specifiers :
	starage_class_especifier declaration_specifiers |
	starage_class_especifier |
	type_specifier declaration_specifiers |
	type_specifier |
	type_qualifer declaration_specifiers |
	type_qualifer
	;

starage_class_especifier : TYPEDEF | EXTERN | STATIC | AUTO | REGISTER ;

init_declarator_list : init_declarator |
	init_declarator_list ',' init_declarator
	;

init_declarator : declarator |
	init_declarator '=' initializer;

//TODO : esta gramatica no es exacta para el estandar
initializer : const_expression |
	'{' initilizer_list '}'
	;


const_expression : LITERAL_CHAR | LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC ; 



initilizer_list : const_expression |
	initilizer_list ',' const_expression
	;

 
type_specifier :  VOID | CHAR | SHORT | INT | LONG | FLOAT | SIGNED | UNSIGNED ;

type_qualifer : CONST | VOLATIL;

declarator : pointer direct_declarator |
	direct_declarator;

direct_declarator : IDENTIFIER |
	'(' declarator ')' |
	direct_declarator '[' const_expression ']' |
	direct_declarator '(' parameter_type_list ')' |
	direct_declarator '(' identifer_list ')' 
	;

identifer_list : IDENTIFIER |
	identifer_list IDENTIFIER
	;
	

parameter_type_list : parameter_list |
	parameter_list ',' "..."
	;

parameter_list : parameter_declaration
	parameter_list ',' parameter_declaration
	;

parameter_declaration : 
	declaration_specifiers declarator |
	declaration_specifiers abstract_declarator |
	declaration_specifiers |
	;

abstract_declarator : pointer |
	pointer direct_abstract_declarator|
	direct_abstract_declarator
	;

direct_abstract_declarator : 
	'(' abstract_declarator ')' |
	direct_abstract_declarator '[' const_expression ']' |
	'[' const_expression ']' |
	direct_abstract_declarator '[' ']' |	
	'[' ']' |
	direct_abstract_declarator '(' const_expression ')' | 
	'(' const_expression ')' |
	direct_abstract_declarator '(' ')' |	
	'(' ')' |
	;

pointer : '*' type_qualifer_list |
	'*' |
	'*' type_qualifer_list pointer |
	'*' pointer
	;

type_qualifer_list : type_qualifer |
	type_qualifer_list type_qualifer 
	;

compound_statement : '{' declaration_list statement_list '}' | 
	'{' statement_list '}' |
	'{' declaration_list '}' |
	'{' '}' 
	;
	
declaration_list : declaration |
	declaration_list declaration
	;


statement_list : statement |
	statement_list statement
	;

statement : compound_statement |  instruction_mov | instruction_int ;



instruction_mov : MOV registers_8b literals_8b ';' | MOV registers_16b literals_16b ';';		
instruction_int : INT literals_integers ';';


literals_8b : LITERAL_CHAR | LITERAL_INTEGER_DEC_UCHAR | LITERAL_INTEGER_DEC_SCHAR;
literals_16b : LITERAL_INTEGER_DEC_USHORT | LITERAL_INTEGER_DEC_SHORT;
literals_integers : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC;
initializer_char : LITERAL_CHAR | ;
initializer_integer : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC | ;

registers_8b : AL | AH ;
registers_16b : AX ;

%%

void yyerror(const YYLTYPE *loc, yyscan_t scanner, result *res, const char *msg, ...)
{
	YYLOCATION_PRINT (stderr, loc);
  	fprintf (stderr, "%s\n", msg);
}





