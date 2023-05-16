
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Parser::declaration(std::ostream& out) const
    {

        // Emitted in the header file, before the definition of YYSTYPE.
        out << "%code requires\n";
        out << "{\n";
          out << "\t#ifndef YY_TYPEDEF_YY_SCANNER_T\n";
          out << "\t# define YY_TYPEDEF_YY_SCANNER_T\n";
          out << "\ttypedef void* yyscan_t;\n";
          out << "\t#endif\n";

          out << "\ttypedef struct\n";
          out << "\t{\n";
            // Whether to print the intermediate results.
            out << "\t\tint verbose;\n";
            // Value of the last computation.
            out << "\t\tint value;\n";
            // Number of errors.
            out << "\t\tint nerrs;\n";
          out << "\t} result;\n";
            out << "\t#include <" << header_file() << ">\n";
            out << "\t#include <" << language(true) << "-Driver.hh>\n";
            out << "\tnamespace " << space() << "_here = oct::cc::v0::" << space() << ";\n";
            out << "\tnamespace core_here = oct::core::v3;\n";
        out << "}\n";

        // Emitted in the header file, after the definition of YYSTYPE.
        out << "%code provides\n";
        out << "{\n";
        // Tell Flex the expected prototype of yylex.
        // The scanner argument must be named yyscanner.
        out << "\t#define YY_DECL yytoken_kind_t yylex (YYSTYPE* yylval_param,YYLTYPE* yylloc, yyscan_t yyscanner, " << space(1) << "_here::Tray<" << space() << "_here::nodes::" << tree_node() << ">* tray)\n";
            out << "\tYY_DECL;\n";

            //out << "\tvoid yyerror(YYLTYPE* yyalloc,yyscan_t scanner, result *res, const " << space() << "_here::nodes::" << tree_node() << "** unit,core_here::Block& block, const char *msg);\n";
            out << "\tvoid yyerror(YYLTYPE* yylloc,yyscan_t scanner, " << space(1) << "_here::Tray<" << space() << "_here::nodes::" << tree_node() << ">* tray, const char *msg, ...);\n";
            out << "\tvoid yyerror_unknow_symbol(YYLTYPE* yylloc,yyscan_t scanner, " << space(1) << "_here::Tray<" << space() << "_here::nodes::" << tree_node() << ">* tray, char);\n";
            //out << "\tvoid yyerror(YYLTYPE* yyalloc,yyscan_t scanner, result *res, const " << space() << "_here::nodes::" << tree_node() << "** unit,core_here::Block& block, const char *msg, char);\n";
            //out << "\tvoid yyerror(YYLTYPE* yyalloc,yyscan_t scanner, result *res, const " << space() << "_here::nodes::" << tree_node() << "** unit,core_here::Block& block, const char *msg, yytoken_kind_t);\n";


        out << "}\n";

        // Emitted on top of the implementation file.
        out << "%code top\n";
        out << "{\n";
            out << "#include <stdarg.h>\n";
            out << "#include <stdio.h> \n";
            out << "#include <stdlib.h>\n";
            out << "\t#include <" << header_file() << ">\n";
            out << "\t#include <" << language(true) << "-Driver.hh>\n";
            out << "\tnamespace " << space() << "_here = oct::cc::v0::" << space() << ";\n";
            if(lang == Language::AI) out << "\tstatic " << space(1) << "_here::nodes::statement *statement_list_body = NULL;\n";
        out << "}\n";


        // Don't share global variables between the scanner and the parser.
        out << "%define api.pure full\n";
        // Generate YYSTYPE from the types assigned to symbols.
        out << "%define api.value.type union\n";
        // Error messages with "unexpected XXX, expected XXX...".
        out << "%define parse.error detailed\n";
        // Enable run-time traces (yydebug).
        //out << "%define parse.trace\n";
        // Generate the parser description file (parse.output).
        out << "%verbose\n";
        out << "%locations\n";
        //out << "%define api.prefix {" << prefix() << "}\n";

        // Scanner and error count are exchanged between main, yyparse and yylex.
        //out << "%param {yyscan_t scanner}{const " << space() << "_here::nodes::" << tree_node() << "** unit}{core_here::Block& block}\n";
        out << "%param {yyscan_t scanner}{" << space(1) << "_here::Tray<" << space() << "_here::nodes::" << tree_node() << ">* tray}\n";


        out << "%token ENDOFFILE 0  \"end-of-file\"\n";
        //keywords
        out << "%token AUTO 110200\n";
        out << "%token BREAK\n";
        out << "%token CASE\n";
        out << "%token CHAR\n";
        out << "%token CONST\n";
        out << "%token CONTINUE\n";
        out << "%token DEFAULT\n";
        out << "%token DO\n";
        out << "%token DOUBLE\n";
        out << "%token ELSE\n";
        out << "%token ENUM\n";
        out << "%token EXTERN\n";
        out << "%token FLOAT\n";
        out << "%token FOR\n";
        out << "%token GOTO\n";
        out << "%token IF\n";
        out << "%token INT\n";
        out << "%token LONG\n";
        out << "%token REGISTER\n";
        out << "%token RETURN\n";
        out << "%token SHORT\n";
        out << "%token SIGNED\n";
        out << "%token SIZEOF\n";
        out << "%token STATIC\n";
        out << "%token STRUCT\n";
        out << "%token SWITCH\n";
        out << "%token TYPEDEF\n";
        out << "%token UNION\n";
        out << "%token UNSIGNED\n";
        out << "%token VOID\n";
        out << "%token VOLATIL\n";
        out << "%token WHILE\n";

        //
        out << "%token AAA\n";
        out << "%token AAD\n";
        out << "%token AAM\n";
        out << "%token AAS\n";
        out << "%token ADC\n";
        out << "%token ADD\n";
        out << "%token AND\n";
        out << "%token CALL\n";
        out << "%token CBW\n";
        out << "%token CLC\n";
        out << "%token CLD\n";
        out << "%token CLI\n";
        out << "%token CMC\n";
        out << "%token CMP\n";
        out << "%token CMPS\n";
        out << "%token CWD\n";
        out << "%token DAA\n";
        out << "%token DAS\n";
        out << "%token DEC\n";
        out << "%token DIV\n";
        out << "%token ESC\n";
        out << "%token HLT\n";
        out << "%token IDIV\n";
        out << "%token IMUL\n";
        out << "%token IN\n";
        out << "%token INC\n";
        out << "%token INTR\n";
        out << "%token INTO\n";
        out << "%token IRET\n";
        out << "%token JA\n";
        out << "%token JNBE\n";
        out << "%token JAE\n";
        out << "%token JNB\n";
        out << "%token JB\n";
        out << "%token JNAE\n";
        out << "%token JBE\n";
        out << "%token JNA\n";
        out << "%token JC\n";
        out << "%token JCXZ\n";
        out << "%token JE\n";
        out << "%token JZ\n";
        out << "%token JG\n";
        out << "%token JNLE\n";
        out << "%token JGE\n";
        out << "%token JNL\n";
        out << "%token JL\n";
        out << "%token JNGE\n";
        out << "%token JLE\n";
        out << "%token JNG\n";
        out << "%token JMP\n";
        out << "%token JNC\n";
        out << "%token JNE\n";
        out << "%token JNZ\n";
        out << "%token JNO\n";
        out << "%token JNP\n";
        out << "%token JPO\n";
        out << "%token JNS\n";
        out << "%token JO\n";
        out << "%token JP\n";
        out << "%token JPE\n";
        out << "%token JS\n";
        out << "%token LAHF\n";
        out << "%token LDS\n";
        out << "%token LEA\n";
        out << "%token LES\n";
        out << "%token LOCK\n";
        out << "%token LODS\n";
        out << "%token LOOP\n";
        out << "%token LOOPE\n";
        out << "%token LOOPNE\n";
        out << "%token NMI\n";
        out << "%token MOV\n";
        out << "%token MOVS\n";
        out << "%token MOVSB\n";
        out << "%token MOVSW\n";
        out << "%token MUL\n";
        out << "%token NEG\n";
        out << "%token NOP\n";
        out << "%token NOT\n";
        out << "%token OR\n";
        out << "%token OUT\n";
        out << "%token POP\n";
        out << "%token POPF\n";
        out << "%token PUSH\n";
        out << "%token PUSHF\n";
        out << "%token RCL\n";
        out << "%token RCR\n";
        out << "%token REPE\n";
        out << "%token REPZ\n";
        out << "%token REPNE\n";
        out << "%token REPNZ\n";
        out << "%token RET\n";
        out << "%token ROL\n";
        out << "%token ROR\n";
        out << "%token SAHF\n";
        out << "%token SAL\n";
        out << "%token SHL\n";
        out << "%token SAR\n";
        out << "%token SBB\n";
        out << "%token SCAS\n";
        out << "%token SEGMENT\n";
        out << "%token SHR\n";
        out << "%token SINGLE\n";
        out << "%token STEP\n";
        out << "%token STC\n";
        out << "%token STD\n";
        out << "%token STI\n";
        out << "%token STOS\n";
        out << "%token SUB\n";
        out << "%token TEST\n";
        out << "%token WAIT\n";
        out << "%token XCHG\n";
        out << "%token XLAT\n";
        out << "%token XORG\n";

        //registers
        out << "%token AL\n";
        out << "%token AH\n";
        out << "%token AX\n";
        out << "%token BL\n";
        out << "%token BH\n";
        out << "%token BX\n";
        out << "%token CL\n";
        out << "%token CH\n";
        out << "%token CX\n";
        out << "%token DL\n";
        out << "%token DH\n";
        out << "%token DX\n";


        //Ponters
        out << "%token SP\n";
        out << "%token BP\n";
        out << "%token SI\n";
        out << "%token DI\n";

        //Segments
        out << "%token CS\n";
        out << "%token DS\n";
        out << "%token SS\n";
        out << "%token ES\n";


        out << "%token BYTE\n";
        out << "%token TINY\n";

        //
        out << "%token <AI_here::nodes::constant_integer<AI_here::integer>*> CONSTANT_INTEGER_8b\n";
        out << "%token <AI_here::nodes::constant_integer<AI_here::integer>*> CONSTANT_INTEGER_16b\n";
        out << "%token <AI_here::nodes::constant_integer<AI_here::integer>*> CONSTANT_INTEGER_DEC\n";
        out << "%token LITERAL_INTEGER_DEC_SCHAR\n";
        out << "%token LITERAL_INTEGER_DEC_UCHAR\n";
        out << "%token LITERAL_INTEGER_DEC_SHORT\n";
        out << "%token LITERAL_INTEGER_DEC_USHORT\n";
        out << "%token LITERAL_INTEGER_DEC_INT\n";
        out << "%token LITERAL_INTEGER_DEC_UNIT\n";
        out << "%token LITERAL_INTEGER_DEC_LONG\n";
        out << "%token LITERAL_INTEGER_DEC_ULONG\n";
        out << "%token <AI_here::nodes::constant_integer<AI_here::integer>*> CONSTANT_INTEGER_HEX\n";
        out << "%token LITERAL_INTEGER_HEX_SCHAR\n";
        out << "%token <signed char>LITERAL_INTEGER_HEX_UCHAR\n";
        out << "%token LITERAL_INTEGER_HEX_SHORT\n";
        out << "%token <unsigned short>LITERAL_INTEGER_HEX_USHORT\n";
        out << "%token LITERAL_INTEGER_HEX_INT\n";
        out << "%token <unsigned int>LITERAL_INTEGER_HEX_UINT\n";
        out << "%token LITERAL_INTEGER_HEX_LONG\n";
        out << "%token LITERAL_INTEGER_HEX_ULONG\n";
        out << "%token <AI_here::nodes::constant_integer<AI_here::integer>*> CONSTANT_INTEGER_OCT\n";
        out << "%token <AI_here::nodes::charater_constant<char>*> CONSTANT_CHAR\n";
        out << "%token <const char*> LITERAL_STRING\n";
        out << "%token <AI_here::nodes::identifier*> IDENTIFIER\n";

        out << "%type <AI_here::Tokens> registers_8b\n";
        out << "%type <AI_here::Tokens> registers_16b\n";
        //out << "%type <AI_here::Tokens> registers\n";
        out << "%type <AI_here::Tokens> segments\n";
        //out << "%type <AI_here::Tokens> index_array\n";
        out << "%type <AI_here::nodes::Memory*> memory\n";


        out << "%type <AI_here::nodes::Move*> move\n";
        out << "%type <AI_here::nodes::Interruption*> interruption\n";
        out << "%type <AI_here::nodes::Label*> label\n";
        out << "%type <AI_here::nodes::Return*> ret\n";
        //out << "%type <AI_here::nodes::constant_integer<AI_here::integer>*> constant_integer\n";
        out << "%type <AI_here::nodes::constant_integer<AI_here::integer>*> constant_integer_8b\n";
        out << "%type <AI_here::nodes::constant_integer<AI_here::integer>*> constant_integer_16b\n";
        //out << "%type <char> const_char\n";
        out << "%type <AI_here::nodes::statement*> instructions\n";

        //out << "%type <AI_here::nodes::const_expression*> const_expression\n";
        out << "%type <AI_here::nodes::direct_declarator*> direct_declarator\n";
        out << "%type <AI_here::nodes::declarator*> declarator\n";
        out << "%type <AI_here::nodes::type_specifier*> type_specifier\n";
        out << "%type <AI_here::nodes::type_specifier*> declaration_specifiers\n";
        out << "%type <AI_here::nodes::init_declarator*> init_declarator\n";
        out << "%type <AI_here::nodes::init_declarator*> init_declarator_list\n";
        out << "%type <AI_here::nodes::constant*> initializer\n";
        out << "%type <AI_here::nodes::declaration*> declaration\n";

        //out << "%type <AI_here::nodes::identifier*> identifier_list\n";

        switch(lang)
        {
        case Language::AI:
            declaration_types_AI(out);
            break;
        case Language::AII:
            declaration_types_AII(out);
            break;
        default:
            ;
        }

        out << "%start translation_unit\n";
    }
    void Parser::declaration_code_required(std::ostream& out) const
    {

        out << "%code requires\n";
        out << "{\n";
            out << "\t#include <" << header_file() << ">\n";
            out << "\t#include <" << language(true) << "-Driver.hh>\n";
            out << "\t#include <core/3/Exception.hh>\n";
            out << "\tnamespace " << space() << "_here = oct::cc::v0::" << space() << ";\n";
            out << "\tnamespace core_here = oct::core::v3;\n";

            out << "\tnamespace oct::cc::v0::" << space() << "\n";
            out << "\t{\n";
                out << "\t\tclass Scanner;\n";
                out << "\t\tclass Driver;\n";
            out << "\t}\n";

            out << "\t# ifndef YY_NULLPTR\n";
            out << "\t#  if defined __cplusplus && 201103L <= __cplusplus\n";
            out << "\t#   define YY_NULLPTR nullptr\n";
            out << "\t#  else\n";
            out << "\t#   define YY_NULLPTR 0\n";
            out << "\t#  endif\n";
            out << "\t# endif\n";
        out << "}\n";

    }
    void Parser::declaration_types_AI(std::ostream& out) const
    {
        out << "%type <AI_here::nodes::declaration*> declaration_list\n";
        out << "%type <AI_here::nodes::statement*> instructions_list\n";
        out << "%type <AI_here::nodes::function*> function\n";
        out << "%type <AI_here::nodes::function*> function_list\n";
        out << "%type <AI_here::nodes::translation_unit*> translation_unit\n";
    }
    void Parser::declaration_types_AII(std::ostream& out) const
    {
        out << "%type <AI_here::nodes::statement*> statement_list\n";
        out << "%type <AI_here::nodes::statement*> statements\n";
        out << "%type <AII_here::nodes::compound_statement*> compound_statement\n";
        out << "%type <AII_here::nodes::function_definition*> function_definition\n";
        out << "%type <AII_here::nodes::external_declaration*> external_declaration\n";
        out << "%type <AII_here::nodes::external_declaration*> translation_unit\n";
        out << "%type <AI_here::nodes::Return*> Return\n";

    }

}

