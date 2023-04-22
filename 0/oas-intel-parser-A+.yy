
%skeleton "lalr1.cc"
%require  "3.8"
%defines
%define api.namespace {oct::cc::v0::AII}
%define api.parser.class {parser}

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code requires
{
    #include <A+.hh>
    #include <A+-Driver.hh>
	#include <core/3/Exception.hh>
	#include <fstream>
	namespace AII_here = oct::cc::v0::AII;
	namespace core_here = oct::core::v3;

	namespace oct::cc::v0::AII
    {
        class Scanner;
        class Driver;
	}

    # ifndef YY_NULLPTR
    #  if defined __cplusplus && 201103L <= __cplusplus
    #   define YY_NULLPTR nullptr
    #  else
    #   define YY_NULLPTR 0
    #  endif
    # endif
}

%parse-param { AII_here::Scanner& scanner }
%parse-param { AII_here::Driver& driver }
%parse-param { const AII_here::nodes::external_declaration** unit}
%parse-param { core_here::Block& block}

%code
{
    #include <A+-Scanner.hh>
    #undef yylex
    #define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert
%locations

%token ENDOFFILE 0  "end-of-file"

//keywords
%token AUTO 110200
%token BYTE
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
%token <long long> CONSTANT_INTEGER_DEC
%token LITERAL_INTEGER_DEC_SCHAR
%token LITERAL_INTEGER_DEC_UCHAR
%token LITERAL_INTEGER_DEC_SHORT
%token LITERAL_INTEGER_DEC_USHORT
%token LITERAL_INTEGER_DEC_INT
%token LITERAL_INTEGER_DEC_UNIT
%token LITERAL_INTEGER_DEC_LONG
%token LITERAL_INTEGER_DEC_ULONG
%token <long long> CONSTANT_INTEGER_HEX
%token LITERAL_INTEGER_HEX_SCHAR
%token <signed char>LITERAL_INTEGER_HEX_UCHAR
%token LITERAL_INTEGER_HEX_SHORT
%token <unsigned short>LITERAL_INTEGER_HEX_USHORT
%token LITERAL_INTEGER_HEX_INT
%token <unsigned int>LITERAL_INTEGER_HEX_UINT
%token LITERAL_INTEGER_HEX_LONG
%token LITERAL_INTEGER_HEX_ULONG
%token <char> CONSTANT_CHAR
%token <AI_here::nodes::identifier*> IDENTIFIER
%type <int> registers_8b
%type <int> registers_16b
%type <long long>consts_integer

%type <A_here::nodes::statement*> statement
%type <AI_here::nodes::instruction_mov*> instruction_mov
%type <AI_here::nodes::instruction_int*> instruction_int
%type <AI_here::nodes::instruction_label*> instruction_label
%type <AI_here::nodes::assembler_instruction*> assembler_instruction
%type <AI_here::nodes::assembler_instruction*> instruction_list
%type <AI_here::nodes::direct_declarator*> direct_declarator
%type <AI_here::nodes::declarator*> declarator
%type <AI_here::nodes::type_specifier*> type_specifier
%type <AI_here::nodes::type_specifier*> declaration_specifiers
%type <AI_here::nodes::identifier*> identifier_list
%type <AI_here::nodes::const_expression*> const_expression
%type <AI_here::nodes::init_declarator*> init_declarator
%type <AI_here::nodes::init_declarator*> init_declarator_list
%type <AI_here::nodes::initializer*> initializer
%type <AI_here::nodes::declaration*> declaration

%type <AI_here::nodes::return_statement*> statement_return
%type <AII_here::nodes::compound_statement*> compound_statement
%type <AII_here::nodes::function_implementation*> function_implementation
%type <AII_here::nodes::external_declaration*> external_declaration
%type <AII_here::nodes::external_declaration*> translation_unit


%start translation_unit
%%

/*
storage_class_specifier : TYPEDEF | EXTERN | STATIC | AUTO | REGISTER ;

type_qualifer :
    CONST
    {
        $$ = block.create<A_here::nodes::type_qualifer>();
        $$->qualifer = A_here::Tokens::CONST;
    }
    |
    VOLATIL
    {
        $$ = block.create<A_here::nodes::type_qualifer>();
        $$->qualifer = A_here::Tokens::VOLATIL;
    }
    ;
*/

//

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>A+


registers_8b :
    AL
    {
        $$ = token::token_kind_type::AL;
    }
    |
    AH
    {
        $$ = token::token_kind_type::AH;
    }
    |
    BL
    {
        $$ = token::token_kind_type::BL;
    }
    |
    BH
    {
        $$ = token::token_kind_type::BH;
    }
    |
    CL
    {
        $$ = token::token_kind_type::CL;
    }
    |
    CH
    {
        $$ = token::token_kind_type::CH;
    }
    |
    DL
    {
        $$ = token::token_kind_type::DL;
    }
    |
    DH
    {
        $$ = token::token_kind_type::DH;
    }
    ;


consts_integer : CONSTANT_INTEGER_HEX | CONSTANT_INTEGER_DEC;

registers_16b :
    AX
	{
        $$ = token::token_kind_type::AX;
	}
	;


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Not C statment



instruction_mov :
	MOV registers_8b consts_integer ';'
	{
		//std::cout << "mov register-8b integer\n";
        A_here::nodes::move_8b_reg_byte* mv8 = block.create<A_here::nodes::move_8b_reg_byte>();
        mv8->registe = (A_here::Tokens)$2;
        mv8->byte = (unsigned char)$3;
        mv8->inst = A_here::Tokens::MOV;
        mv8->is_instruction = true;
        mv8->type = 'I';
        $$ = mv8;
	}
	|
	MOV registers_8b CONSTANT_CHAR ';'
	{
		//std::cout << "mov register-8b char\n";
		A_here::nodes::move_8b_reg_byte* mv8 = block.create<A_here::nodes::move_8b_reg_byte>();
        mv8->registe = (A_here::Tokens)$2;
        mv8->byte = (unsigned char)$3;
        mv8->inst = A_here::Tokens::MOV;
        mv8->is_instruction = true;
        mv8->type = 'C';
        $$ = mv8;
	}
	|
	MOV registers_16b consts_integer
	{
		$$ = NULL;
	}
	;


instruction_int : INT consts_integer ';'
	{
		//std::cout << "int " << $2 << "\n";
		A_here::nodes::instruction_int* serv = block.create<A_here::nodes::instruction_int>();
		//if($2 > 127) yyerror("El parametro para la instruccion int dever ser un numero no mayo de de 128");
		serv->service = $2;
		serv->inst = A_here::Tokens::INT;
		serv->is_instruction = true;
		$$ = serv;
	}
	;


instruction_label : IDENTIFIER ':'
	{
		$$ = block.create<AI_here::nodes::instruction_label>();
		$$->id = $1;
	}
	;


assembler_instruction :
    instruction_mov
    {
        $$ = $1;
    }
    |
    instruction_int
    {
        $$ = $1;
    }
    ;



statement_return  :
	RETURN ';'
	{
        $$ = block.create<A_here::nodes::return_statement>();
	}
    |
	RETURN consts_integer ';'
	{
        $$ = block.create<A_here::nodes::return_statement>();
	}
	;


assembler_instruction :
    instruction_mov
    {
        $$ = $1;
    }
    |
    instruction_int
    {
        $$ = $1;
    }
    |
    instruction_label
    {
        $$ = $1;
    }
    ;



//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>C statment




identifier_list : IDENTIFIER
	{
        $$ = NULL;
	}
	|
	identifier_list IDENTIFIER
	{
		$$ = NULL;
	}
	;


declarator :
	direct_declarator
	{
        //std::cout << "declarator : direct_declarator\n";
        $$ = block.create<A_here::nodes::declarator>();
        $$->point = NULL;
        $$->direct = $1;
        //std::cout << "declarator 2\n";
	}
	;

direct_declarator : IDENTIFIER
	{
		//std::cout << "direct_declarator : IDENTIFIER\n";
		$$ = block.create<A_here::nodes::direct_declarator>();
		$$->id = $1;
		$$->direct = NULL;
		//std::cout << $$->id->name << " ";
	}
	|
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
        $$ = $1;
	}
	|
	direct_declarator '(' identifier_list ')'
	{
        $$ = NULL;
		$$->identifier_list = NULL;
	}
	|
	direct_declarator '('  ')'
	{
		$$ = $1;
		$$->identifier_list = NULL;
	}
	;



instruction_list :
    assembler_instruction
	{
		//std::cout << "statement_list : statement\n";
		$$ = $1;
		//std::cout << "Singular $1 = " << $1 << "\n";
		//if(reinterpret_cast<const AI_here::nodes::instruction*>($1)->inst == Tokens::MOV) reinterpret_cast<const AI_here::nodes::move_8b_reg_byte*>($1)->print(std::cout);
	}
	|
	instruction_list assembler_instruction
	{
		//std::cout << "statement_list : statement_list statement\n";
        //if($$) if(reinterpret_cast<const AI_here::nodes::instruction*>($$)->inst == Tokens::MOV) reinterpret_cast<const AI_here::nodes::move_8b_reg_byte*>($$)->print(std::cout);
        /*
        if($1) if(reinterpret_cast<const AI_here::nodes::instruction*>($1)->inst == Tokens::MOV)
        {
            std::cout << "$1 : ";
            reinterpret_cast<const AI_here::nodes::move_8b_reg_byte*>($1)->print(std::cout);
        }
        if($2) if(reinterpret_cast<const AI_here::nodes::instruction*>($2)->inst == Tokens::MOV)
        {
            std::cout << "$2 : ";
            reinterpret_cast<const AI_here::nodes::move_8b_reg_byte*>($2)->print(std::cout);
        }
        std::cout << "\n--\n";
        */

        static AI_here::nodes::statement *statement_prev = NULL;
        /*
		std::cout << "$$ = " << $$ << "\n";
		std::cout << "$1 = " << $1 << "\n";
		std::cout << "$2 = " << $2 << "\n";
		std::cout << "statement_prev = " << statement_prev << "\n";
		*/

		$$ = $1;
        if(not statement_prev) statement_prev = $1;
		statement_prev->next = $2;


		statement_prev = $2;
	}
	;


initializer : const_expression
	{
		$$ = $1;
	}
	;


const_expression : CONSTANT_CHAR
	{
		//std::cout << "'" << (char)$1 << "' ";
		$$ = block.create<A_here::nodes::initializer_literal<char>>();
		reinterpret_cast<A_here::nodes::initializer_literal<char>*>($$)->value = $1;
		$$->data_type = A_here::Tokens::CONSTANT_CHAR;
	}
	|
	CONSTANT_INTEGER_HEX
	{
		//std::cout << $1 << " ";
		$$ = block.create<A_here::nodes::initializer_literal<long long>>();
		reinterpret_cast<A_here::nodes::initializer_literal<long long>*>($$)->value = $1;
		$$->data_type = A_here::Tokens::CONSTANT_INTEGER_HEX;
	}
	|
	CONSTANT_INTEGER_DEC
	{
		//std::cout << $1 << " ";
		$$ = block.create<A_here::nodes::initializer_literal<long long>>();
		reinterpret_cast<A_here::nodes::initializer_literal<long long>*>($$)->value = $1;
		$$->data_type = A_here::Tokens::CONSTANT_INTEGER_DEC;
	}
	;

init_declarator_list : init_declarator
	{
		//std::cout << "init_declarator_list : init_declarator\n";
		$$ = $1;
	}
	|
	init_declarator_list ',' init_declarator
	{
        static A_here::nodes::init_declarator* statement_prev = NULL;
		$$ = $1;
        if(not statement_prev) statement_prev = $1;
		statement_prev->next = $3;


		statement_prev = $3;
	}
	;
init_declarator : declarator
	{
		//std::cout << "init_declarator : declarator\n";
		$$ = block.create<A_here::nodes::init_declarator>();
		$$->dec = $1;
		$$->value = NULL;
	}
	|
	declarator initializer
	{
		//std::cout << "init_declarator : declarator '=' initializer\n";
		$$ = block.create<A_here::nodes::init_declarator>();
		$$->dec = $1;
		$$->value = $2;
	}
	;


type_specifier :
	VOID
    {
		//std::cout << "type_specifier : VOID\n";
		//std::cout << "void ";
        $$ = block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::VOID;
    }
    |
    CHAR
    {
		//std::cout << "type_specifier : CHAR\n";
		//std::cout << "char ";
        $$ = block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::CHAR;
        //$$->next = NULL;
		//std::cout << "type_specifier\n";
    }
    |
    SHORT
    {
		//std::cout << "type_specifier : SHORT\n";
		//std::cout << "short ";
        $$ = block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::SHORT;
    }
    |
    INT
    {
		//std::cout << "type_specifier : INT\n";
		//std::cout << "int ";
        $$ = block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::INT;
    }
    |
    FLOAT
    {
		//std::cout << "type_specifier : FLOAT\n";
        $$ = block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::FLOAT;
    }
    |
    DOUBLE
    {
		//std::cout << "type_specifier : DOUBLE\n";
        $$ = block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::DOUBLE;
    }
    |
    SIGNED
    {
		//std::cout << "type_specifier : SIGNED\n";
		//std::cout << "signed ";
        $$ = block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::SIGNED;
    }
    |
    UNSIGNED
    {
		//std::cout << "type_specifier : UNSIGNED\n";
		//std::cout << "unsigned ";
        $$ = block.create<A_here::nodes::type_specifier>();
        $$->type = A_here::Tokens::UNSIGNED;
    }
    ;


declaration_specifiers :
	type_specifier
	{
		$$ = $1;
	}
	|
    declaration_specifiers type_specifier
	{
        static A_here::nodes::type_specifier* statement_prev = NULL;
		$$ = $1;
        if(not statement_prev) statement_prev = $1;
		statement_prev->next = $2;


		statement_prev = $2;
	}
	;

compound_statement :
	'{' instruction_list '}'
    {
		//std::cout << "compound_statement : '{' statement_list '}'\n";
        $$ = block.create<AII_here::nodes::compound_statement>();
        $$->statement_list = $2;
    }
    |
	'{' '}'
    {
        $$ = block.create<AII_here::nodes::compound_statement>();
        $$->statement_list = NULL;
    }
	;
//6.5
declaration :
	declaration_specifiers
	{
		//std::cout << "declaration : declaration_specifiers\n";
		$$ = block.create<A_here::nodes::declaration>();
		$$->specifiers = $1;
		$$->list = NULL;
	}
	|
	declaration_specifiers init_declarator_list
	{
		//std::cout << "declaration : declaration_specifiers init_declarator_list\n";
		$$ = block.create<A_here::nodes::declaration>();
		$$->specifiers = $1;
		$$->list = $2;
	}
	;


function_implementation :
	declaration_specifiers declarator compound_statement
	{
        //std::cout << "function_implementation - 2\n";
        $$ = block.create<AII_here::nodes::function_implementation>();
        $$->body = $3;
        $$->declaration = $2;
        $$->specifiers = $1;
        //std::cout << $$->declaration->direct->id->name << "\n";
        //std::cout << "function_implementation - 2\n";
	}
	|
	declarator compound_statement
	{
        std::cout << "function_implementation - 3\n";
        $$ = block.create<AII_here::nodes::function_implementation>();
        $$->body = $2;
        $$->declaration = $1;
        $$->specifiers = NULL;
        //std::cout << "Function 3\n";
	}
	;


external_declaration :
	function_implementation
	{
		//std::cout << "external_declaration : function_implementation\n";
        //$1->print(std::cout);
        $$ = block.create<AII_here::nodes::external_declaration>();
        $$->func = $1;
        $$->decl = NULL;
	}
	|
	declaration ';'
	{
		//std::cout << "storage_class_specifier : declaration ';'\n";
		//std::cout << ";\n";
		//$1->print(std::cout);
        $$ = block.create<AII_here::nodes::external_declaration>();
        $$->func = NULL;
        $$->decl = $1;
	}
	;


translation_unit :
    external_declaration
	{
		//std::cout << "external_declaration\n";
		$$ = $1;
		*unit = $1;
	}
	|
	translation_unit external_declaration
	{
		//std::cout << "external_declaration translation_unit\n";
        static AII_here::nodes::external_declaration* statement_prev = NULL;
		$$ = $1;
		//$2->print(std::cout);
        if(not statement_prev) statement_prev = $1;
		statement_prev->next = $2;


		statement_prev = $2;
	}
	;
%%

void AII_here::parser::error (const location_type& l, const std::string& m)
{
    std::cerr << l << ": " << m << '\n';
    //std::cerr << m << '\n';
}
