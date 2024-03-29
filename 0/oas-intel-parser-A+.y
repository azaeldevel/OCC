
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
	#include <iostream>
	#include <fstream>
	#include <core/3/Exception.hh>
	namespace A_here = oct::cc::v0::A;
	namespace core_here = oct::core::v3;
	//A_here::nodes::identifier* identifier = NULL;
	unsigned char instruction[6];
	int instruction_len = 0;
	std::fstream outstream;
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
%token DL
%token DH
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
%token LITERAL_INTEGER_HEX_SCHAR
%token <signed char>LITERAL_INTEGER_HEX_UCHAR
%token LITERAL_INTEGER_HEX_SHORT
%token <unsigned short>LITERAL_INTEGER_HEX_USHORT
%token LITERAL_INTEGER_HEX_INT
%token <unsigned int>LITERAL_INTEGER_HEX_UINT
%token LITERAL_INTEGER_HEX_LONG
%token LITERAL_INTEGER_HEX_ULONG
%token <char> LITERAL_CHAR
%token <const char*> IDENTIFIER
%type <yytoken_kind_t> registers_8b
%type <yytoken_kind_t> registers_16b
%type <long long>literals_integer

%type <A_here::nodes::statement*> statement
%type <A_here::nodes::statement*> instruction_mov
%type <A_here::nodes::statement*> instruction_int
%type <std::list<A_here::nodes::statement*>*> statement_list
%type <A_here::nodes::return_statement*> statement_return
%type <A_here::nodes::compound_statement*> compound_statement
%type <A_here::nodes::function_implementation*> function_implementation
%type <A_here::nodes::type_qualifer*> type_qualifer
%type <std::list<A_here::nodes::type_qualifer*>*> type_qualifer_list
%type <A_here::nodes::direct_declarator*> direct_declarator
%type <A_here::nodes::declarator*> declarator
%type <A_here::nodes::pointer*> pointer
%type <A_here::nodes::type_specifier*> type_specifier
%type <A_here::nodes::declaration_specifiers*> declaration_specifiers
%type <std::list<A_here::nodes::identifier*>*> identifer_list
//%type <A_here::nodes::Symbol*> const_expression




%%

translation_unit : 
	external_declaration ENDOFFILE 
	{
		$$ = $1;
	}
	|
	external_declaration translation_unit ENDOFFILE
	{
		$$ = $1;
	}
	;

external_declaration : 
function_implementation 
	{
		$$ = $1;
	}
	|
	declaration ';'
	{
		$$ = $1;
	}
	;

function_implementation :
	declaration_specifiers declarator declaration_list compound_statement
	{
        $$ = A_here::block.create<A_here::nodes::function_implementation>();
        $$->body = $4;
        $$->declaration = $2;
        //std::cout << "Function 1\n";
	}
	|
	declaration_specifiers declarator compound_statement
	{
        //std::cout << "Function 2 - 1\n";
        $$ = A_here::block.create<A_here::nodes::function_implementation>();
        $$->body = $3;
        $$->declaration = $2;
        $$->specifier = $1;
        //std::cout << "Function 2 - 2\n";
        $$->print();
	}
	|
	declarator declaration_list compound_statement
	{
        $$ = A_here::block.create<A_here::nodes::function_implementation>();
        $$->body = $3;
        $$->declaration = $1;
        //std::cout << "Function 3\n";
	}
	|
	declarator compound_statement
	{
        $$ = A_here::block.create<A_here::nodes::function_implementation>();
        $$->body = $2;
        $$->declaration = $1;
        //std::cout << "Function 4\n";
	}
	;

declaration_specifiers : storage_class_specifier
        {
            //std::cout << "1\n";
            $$ = NULL;
        }
        |
        storage_class_specifier declaration_specifiers
        {
            //std::cout << "2\n";
            $$ = NULL;
        }
        |
        type_specifier
        {
            //std::cout << "3\n";
            $$ = A_here::block.create<A_here::nodes::declaration_specifiers>();
            $$->storage = NULL;
            $$->type = $1;
            $$->qualifer = NULL;
            $$->declaration = NULL;
        }
        |
        type_specifier declaration_specifiers
        {
            //std::cout << "4\n";
            $$ = NULL;
        }
        |
        type_qualifer
        {
            //std::cout << "5\n";
            $$ = NULL;
        }
        |
        type_qualifer declaration_specifiers
        {
            //std::cout << "6\n";
            $$ = NULL;
        }
        ;

storage_class_specifier : TYPEDEF | EXTERN | STATIC | AUTO | REGISTER

type_specifier : VOID
    {
        $$ = A_here::block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::VOID;
    }
    |
    CHAR
    {
        $$ = A_here::block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::CHAR;
    }
    |
    SHORT
    {
        $$ = A_here::block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::SHORT;
    }
    |
    INT
    {
        $$ = A_here::block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::INT;
    }
    |
    LONG
    {
        $$ = A_here::block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::LONG;
    }
    |
    FLOAT
    {
        $$ = A_here::block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::FLOAT;
    }
    | DOUBLE
    {
        $$ = A_here::block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::DOUBLE;
    }
    | SIGNED
    {
        $$ = A_here::block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::SIGNED;
    }
    | UNSIGNED
    {
        $$ = A_here::block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::UNSIGNED;
    }
    | struct_or_union_specifier
    {
        $$ = NULL;
    }
    | enum_specifier
    {
        $$ = NULL;
    }
    | typedef_name
    {
        $$ = NULL;
    }
    ;


struct_or_union_specifier :

enum_specifier :

typedef_name :

//6.5
declaration : declaration_specifiers init_declarator_list | declaration_specifiers;
declaration_specifiers :
	storage_class_especifier declaration_specifiers |
	storage_class_especifier |
	type_specifier declaration_specifiers |
	type_specifier |
	type_qualifer declaration_specifiers |
	type_qualifer
	;

storage_class_especifier : TYPEDEF | EXTERN | STATIC | AUTO | REGISTER ;

init_declarator_list : init_declarator |
	init_declarator_list ',' init_declarator
	;

init_declarator : declarator 		{
										//std::cout << "Line " << A_here::symbol_current->line << "\n";
										//auto it = symbols_table->end();
										//it--;
										//A_here::nodes::identifier* identifier = *it;
										//identifier->line = A_here::symbol_current->line;
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


const_expression : LITERAL_CHAR {

                                }|
				LITERAL_INTEGER_HEX {

									}|
				LITERAL_INTEGER_DEC {

									};



initilizer_list : const_expression  {

									}|
	initilizer_list ',' const_expression
	;


type_specifier :  VOID | CHAR | SHORT | INT | LONG | FLOAT | SIGNED | UNSIGNED ;

type_qualifer :
    CONST
    {
        $$ = A_here::block.create<A_here::nodes::type_qualifer>();
        $$->qualifer = A_here::Tokens::CONST;
    }
    |
    VOLATIL
    {
        $$ = A_here::block.create<A_here::nodes::type_qualifer>();
        $$->qualifer = A_here::Tokens::VOLATIL;
    }
    ;

declarator :
    pointer direct_declarator
    {
        $$ = A_here::block.create<A_here::nodes::declarator>();
        $$->point = $1;
        $$->direct = $2;
    }
    |
	direct_declarator
	{
        //std::cout << "declarator 1\n";
        $$ = A_here::block.create<A_here::nodes::declarator>();
        $$->point = NULL;
        $$->direct = $1;
        //std::cout << "declarator 2\n";
	}
	;

direct_declarator : IDENTIFIER 		{
										$$ = A_here::block.create<A_here::nodes::direct_declarator>();
										$$->identity = A_here::block.create<A_here::nodes::identifier>();
										$$->identity->name = $1;
										//std::cout << " direct_declarator identifer\n";
									}|
	'(' declarator ')'
	{
        $$ = NULL;
	}
	|
	direct_declarator '[' const_expression ']'
	{
        $$ = NULL;
	}
	|
	direct_declarator '['  ']'
	{
        $$ = NULL;
	}
	|
	direct_declarator '(' parameter_type_list ')'
	{
        $$ = NULL;
	}
	|
	direct_declarator '(' identifer_list ')'
	{
        $$ = NULL;
	}
	|
	direct_declarator '('  ')'
	{
        //A_here::nodes::identifier* identifier = $$;//optiene el identifier previamente cargado
        //$$ = A_here::block.create<A_here::nodes::direct_declarator>();
        //$$->identity = identifier;
        //std::cout << " direct_declarator funtion\n";
	}
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

pointer :
    '*' type_qualifer_list |
	'*' |
	'*' type_qualifer_list pointer |
	'*' pointer
	;

type_qualifer_list : type_qualifer |
	type_qualifer_list type_qualifer
	;

compound_statement : '{' declaration_list statement_list '}'
    {
        $$ = A_here::block.create<A_here::nodes::compound_statement>();
        $$->statement_list = $3;
    }
    |
	'{' statement_list '}'
    {
        $$ = A_here::block.create<A_here::nodes::compound_statement>();
        $$->statement_list = $2;
    }
    |
	'{' declaration_list '}'
    {
        $$ = A_here::block.create<A_here::nodes::compound_statement>();
        $$->statement_list = NULL;
    }
    |
	'{' '}'
    {
        $$ = A_here::block.create<A_here::nodes::compound_statement>();
        $$->statement_list = NULL;
    }
	;

declaration_list : declaration |
	declaration_list declaration
	;


statement_list : statement
            {
                $$ = new std::list<A_here::nodes::statement*>;
                //std::cout << "statement\n";
                $$->push_back($1);
            } |
            statement_list statement
            {
                //std::cout << "statement_list statement\n";
                $$->push_back($2);
            }
	;

statement : compound_statement
    {
        $$ = $1;
    }
    |
    instruction_mov {$$ = $1;}
    |
    instruction_int {$$ = $1;}
    |
    statement_return  {$$ = $1;};

statement_return  :
	RETURN ';'
	{
        $$ = A_here::block.create<A_here::nodes::return_statement>();
	}
    |
	RETURN literals_integer ';'
	{
        $$ = A_here::block.create<A_here::nodes::return_statement>();
	}
	;

instruction_mov :
	MOV registers_8b literals_integer ';'	{
							//std::cout << "mov register-8b integer\n";
							//inmediate to register 8b
							instruction[0] = 0b1011;//opcode
							//std::cout << (int)instruction[0] << " register-8b integer\n";
							instruction[0] = instruction[0] << 1;//w = one byte
							//std::cout << (int)instruction[0] << " register-8b integer\n";
							switch($2)//reg
							{
							case AL:
								instruction[0] = instruction[0] << 3;
								break;
							case CL:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b001;
								break;
							case DL:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b010;
								break;
							case BL:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b011;
								break;
							case AH:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b100;
								break;
							case CH:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b101;
								break;
							case DH:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b110;
								break;
							case BH:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b111;
								break;
							default:
								//error
								throw core_here::exception("El operando no es un registro de 8 bits valido.");
								//std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
								break;
							}
							instruction[1] = $3;
							//std::cout << (int)instruction[0] << " register-8b integer\n";
							outstream.write((char*)&instruction,2);

							A_here::nodes::MoveI8b* mv8 = A_here::block.create<A_here::nodes::MoveI8b>();
							mv8->registe = (A_here::Tokens)$2;
							mv8->integer = $3;
							mv8->inst = A_here::Tokens::MOV;
							mv8->is_instruction = true;
                            $$ = mv8;
						}|
	MOV registers_8b LITERAL_CHAR ';' {
						//std::cout << "mov register-8b char\n";
							//inmediate to register 8b
							instruction[0] = 0b1011;//opcode
							//std::cout << (int)instruction[0] << " register-8b char\n";
							instruction[0] = instruction[0] << 1;//w = one byte
							//std::cout << (int)instruction[0] << " register-8b char\n";
							switch($2)//reg
							{
							case AL:
								instruction[0] = instruction[0] << 3;
								break;
							case CL:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b001;
								break;
							case DL:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b010;
								break;
							case BL:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b011;
								break;
							case AH:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b100;
								break;
							case CH:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b101;
								break;
							case DH:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b110;
								break;
							case BH:
								instruction[0] = instruction[0] << 3;
								instruction[0] = instruction[0] + 0b111;
								break;
							default:
								//error
								throw core_here::exception("El operando no es un registro de 8 bits valido.");
								//std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
								break;
							}
							instruction[1] = $3;
							//std::cout << (int)instruction[0] << " register-8b char\n";
							outstream.write((char*)&instruction,2);

							A_here::nodes::MoveI8b* mv8 = A_here::block.create<A_here::nodes::MoveI8b>();
							mv8->registe = (A_here::Tokens)$2;
							mv8->integer = $3;
							mv8->inst = A_here::Tokens::MOV;
							mv8->is_instruction = true;
							$$ = mv8;
					}|
	MOV registers_16b literals_integer
	;
instruction_int : INT literals_integer ';' {
						//std::cout << "int " << $2 << "\n";
						instruction[0] = 0b11001101;//opcode
						instruction[1] = $2;
						outstream.write((char*)&instruction,2);

						A_here::nodes::Interruption* serv = A_here::block.create<A_here::nodes::Interruption>();
						serv->service = $2;
                        serv->inst = A_here::Tokens::INT;
                        serv->is_instruction = true;
						$$ = serv;
					}
	;

literals_integer : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC;


initializer_char : LITERAL_CHAR | ;
initializer_integer : LITERAL_INTEGER_HEX | LITERAL_INTEGER_DEC ;

registers_8b : 	AL 	{
				//std::cout << "AL ";
				$$ = AL;
			}|
		AH 	{
				//std::cout <<"AH ";
				$$ = AH;
			}|
		BL 	{
				//std::cout <<"AH ";
				$$ = BL;
			}|
		BH 	{
				//std::cout <<"AH ";
				$$ = BH;
			}|
		CL 	{
				//std::cout <<"AH ";
				$$ = CL;
			}|
		CH 	{
				//std::cout <<"AH ";
				$$ = CH;
			}|
		DL 	{
				//std::cout <<"AH ";
				$$ = DL;
			}|
		DH 	{
				//std::cout <<"AH ";
				$$ = DH;
			};
registers_16b : AX 	{
				//std::cout << "AX ";
				$$ = AX;
			};

%%

void yyerror(const YYLTYPE *loc, yyscan_t scanner, result *res, A_here::SymbolTable* symbols, const char *msg, ...)
{
	YYLOCATION_PRINT(stderr, loc);
  	fprintf (stderr, "%s\n", msg);
}

