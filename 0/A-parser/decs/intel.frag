%skeleton "lalr1.cc"
%require  "3.8"
%defines
%define api.namespace {oct::cc::v0::##NAME####SUCCESSOR_DINASTI##}
%define api.parser.class {parser}

%define parse.trace
%define parse.error detailed
%define parse.lac full

%code requires
{
    #include <##NAME####SUCCESSOR_ORNAMENT##.hh>
    #include <##NAME####SUCCESSOR_ORNAMENT##-Driver.hh>
	#include <core/3/Exception.hh>
	namespace ##NAME####SUCCESSOR_DINASTI##_here = oct::cc::v0::##NAME####SUCCESSOR_DINASTI##;
	namespace core_here = oct::core::v3;

	namespace oct::cc::v0::##NAME####SUCCESSOR_DINASTI##
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

%parse-param { ##NAME####SUCCESSOR_DINASTI##_here::Scanner& scanner }
%parse-param { ##NAME####SUCCESSOR_DINASTI##_here::Driver& driver }
%parse-param { const ##NAME####SUCCESSOR_DINASTI##_here::nodes::##UNIT##** unit}
%parse-param { core_here::Block& block}

%code
{
    #include <##NAME####SUCCESSOR_ORNAMENT##-Scanner.hh>
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
%token INTR
%token INTO
%token IRET
%token JA
%token JNBE
%token JAE
%token JNB
%token JB
%token JNAE
%token JBE
%token JNA
%token JC
%token JCXZ
%token JE
%token JZ
%token JG
%token JNLE
%token JGE
%token JNL
%token JL
%token JNGE
%token JLE
%token JNG
%token JMP
%token JNC
%token JNE
%token JNZ
%token JNO
%token JNP
%token JPO
%token JNS
%token JO
%token JP
%token JPE
%token JS
%token LAHF
%token LDS
%token LEA
%token LES
%token LOCK
%token LODS
%token LOOP
%token LOOPE
%token LOOPNE
%token NMI
%token MOV
%token MOVS
%token MOVSB
%token MOVSW
%token MUL
%token NEG
%token NOP
%token NOT
%token OR
%token OUT
%token POP
%token POPF
%token PUSH
%token PUSHF
%token RCL
%token RCR
%token REPE
%token REPZ
%token REPNE
%token REPNZ
%token RET
%token ROL
%token ROR
%token SAHF
%token SAL
%token SHL
%token SAR
%token SBB
%token SCAS
%token SEGMENT
%token SHR
%token SINGLE
%token STEP
%token STC
%token STD
%token STI
%token STOS
%token SUB
%token TEST
%token WAIT
%token XCHG
%token XLAT
%token XORG

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

