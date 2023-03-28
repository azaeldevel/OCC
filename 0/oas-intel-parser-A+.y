
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
	//A_here::Symbol* A_here::current_symbol;
}

// Emitted in the header file, after the definition of YYSTYPE.
%code provides
{
// Tell Flex the expected prototype of yylex.
// The scanner argument must be named yyscanner.
	#define YY_DECL                                                         \
	  	yytoken_kind_t yylex (YYSTYPE* yylval_param, const YYLTYPE *loc, yyscan_t yyscanner, result *res,A_here::SymbolTable* symbols_table)
	  	YY_DECL;	
		//#define yylex poslex

	void yyerror(const YYLTYPE *loc, yyscan_t scanner, result *res,A_here::SymbolTable* symbols, const char *msg, ...);
}

// Emitted on top of the implementation file.
%code top
{
	#include <stdarg.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <A+.hh>	
	namespace A_here = oct::cc::v0::A;
	A_here::Identifier* identifier = NULL;
	A_here::Instruction instruction;
}

// with locations.
%locations

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
%param {A_here::SymbolTable* symbols_table}



%token ENDOFFILE 0  "end-of-file"

//keywords
%token AUTO 110200
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

//
%token AAA
%token AAD
%token AAM
%token AAS
%token ADC
%token ADD
%token AND
%token CALL
%token CBW
%token CLC
%token CLD
%token CLI
%token CMC
%token CMP
%token CMPS
%token CWD
%token DAA
%token DAS
%token DEC
%token DIV
%token ESC
%token HLT
%token IDIV
%token IMUL
%token IN
%token INC

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


//Ponters
%token SP
%token BP
%token SI
%token DI

//Segments
%token CS
%token DS
%token SS
%token ES

//
%token <long long> LITERAL_INTEGER_DEC
%token LITERAL_INTEGER_DEC_SCHAR	
%token LITERAL_INTEGER_DEC_UCHAR
%token LITERAL_INTEGER_DEC_SHORT
%token LITERAL_INTEGER_DEC_USHORT
%token LITERAL_INTEGER_DEC_INT
%token LITERAL_INTEGER_DEC_UNIT
%token LITERAL_INTEGER_DEC_LONG
%token LITERAL_INTEGER_DEC_ULONG
%token <long long> LITERAL_INTEGER_HEX
%token LITERAL_INTEGER_HEX_UCHAR
%token LITERAL_INTEGER_HEX_USHORT
%token LITERAL_INTEGER_HEX_UNIT
%token <char> LITERAL_CHAR
%token <const char*> IDENTIFIER
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

init_declarator : declarator 		{
										//std::cout << "Line " << A_here::symbol_current->line << "\n";
										auto it = symbols_table->end();
										it--;
										A_here::Identifier* identifier = *it;
										identifier->line = A_here::symbol_current->line;
									}|
	init_declarator '=' initializer {
										//std::cout << "Line " << A_here::symbol_current->line << "\n";
									}
	;

//TODO : esta gramatica no es exacta para el estandar
initializer : const_expression 		{
									}|
	'{' initilizer_list '}'
	;


const_expression : LITERAL_CHAR | 
				LITERAL_INTEGER_DEC_UCHAR 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												//std::cout << "value : " << integer->strvalue << "\n";
												auto it = symbols_table->end();
												it--;
												A_here::Identifier* identifier = *it;
												identifier->strvalue = integer->strvalue;
											}|
				LITERAL_INTEGER_DEC_SCHAR 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												//std::cout << "value : " << integer->strvalue << "\n";
												auto it = symbols_table->end();
												it--;
												A_here::Identifier* identifier = *it;
												identifier->strvalue = integer->strvalue;
											}|
				LITERAL_INTEGER_DEC_USHORT 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												//std::cout << "value : " << integer->strvalue << "\n";
												auto it = symbols_table->end();
												it--;
												A_here::Identifier* identifier = *it;
												identifier->strvalue = integer->strvalue;
											}|
				LITERAL_INTEGER_DEC_SHORT 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												//std::cout << "value : " << integer->strvalue << "\n";
												auto it = symbols_table->end();
												it--;
												A_here::Identifier* identifier = *it;
												identifier->strvalue = integer->strvalue;
											}| 
				LITERAL_INTEGER_HEX 		{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												//std::cout << "value : " << integer->strvalue << "\n";
												auto it = symbols_table->end();
												it--;
												A_here::Identifier* identifier = *it;
												identifier->strvalue = integer->strvalue;
											}|
				LITERAL_INTEGER_DEC 		{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												//std::cout << "value : " << integer->strvalue << "\n";
												auto it = symbols_table->end();
												it--;
												A_here::Identifier* identifier = *it;
												identifier->strvalue = integer->strvalue;
											};



initilizer_list : const_expression  {									
										
									}|
	initilizer_list ',' const_expression
	;

 
type_specifier :  VOID | CHAR | SHORT | INT | LONG | FLOAT | SIGNED | UNSIGNED ;

type_qualifer : CONST | VOLATIL;

declarator : pointer direct_declarator |
	direct_declarator;

direct_declarator : IDENTIFIER 		{
										identifier = new A_here::Identifier;
										identifier->number = symbols_table->size();
										identifier->name = $1;										
										symbols_table->push_back(identifier);
									}|
	'(' declarator ')' 				|
	direct_declarator '[' const_expression ']' 	|
	direct_declarator '['  ']' 					|
	direct_declarator '(' parameter_type_list ')' 		|
	direct_declarator '(' identifer_list ')' 			|
	direct_declarator '('  ')' 
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

statement : compound_statement |  instruction_mov ';' {std::cout << ";\n";} | instruction_int ';' {std::cout << ";\n";} | return ';';

return  : 
	RETURN |
	RETURN literals_8b |
	RETURN literals_16b
	;

instruction_mov : 
	MOV registers_8b literals_8b 	{
										std::cout << "mov ";
									}| 
	MOV registers_16b literals_16b 	{
										std::cout << "mov ";
									}
	;		
instruction_int : INT literals_integers {
										std::cout << "int ";
										}
	;


literals_8b : 	LITERAL_CHAR 	{
									A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
									std::cout << integer->strvalue << " ";
								}| 
				LITERAL_INTEGER_DEC_UCHAR 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
											}| 
				LITERAL_INTEGER_DEC_SCHAR	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
											};
literals_16b : LITERAL_INTEGER_DEC_USHORT 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
											}| 
				LITERAL_INTEGER_DEC_SHORT	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
											};
literals_integers : LITERAL_INTEGER_DEC_UCHAR 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
												}| 
					LITERAL_INTEGER_DEC_SCHAR 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
												}| 
					LITERAL_INTEGER_DEC_USHORT 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
												}| 
					LITERAL_INTEGER_DEC_SHORT 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
												}| 
					LITERAL_INTEGER_HEX 	{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
											}| 
					LITERAL_INTEGER_DEC		{
												A_here::Integer* integer = (A_here::Integer*)A_here::symbol_current;
												std::cout << integer->strvalue << " ";
											};
initializer_char : LITERAL_CHAR | ;
initializer_integer : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC | ;

registers_8b : 	AL 	{
						std::cout << "AL ";
					}| 
				AH 	{
						std::cout <<"AH ";
					};
registers_16b : AX 	{
						std::cout << "AX ";
					};

%%

void yyerror(const YYLTYPE *loc, yyscan_t scanner, result *res, A_here::SymbolTable* symbols, const char *msg, ...)
{
	YYLOCATION_PRINT(stderr, loc);
  	fprintf (stderr, "%s\n", msg);
}

