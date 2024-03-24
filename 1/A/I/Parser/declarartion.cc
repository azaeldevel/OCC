
#include <core/3/string.hh>

#include "Generator.hh"

namespace oct::cc::v1::A::I
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

            //out << "\t#include \"oas-intel.lexer.hh\"\n";
            //out << "\t#include <Buffer.hh>\n";
            out << "\t#include <A/intel.hh>\n";
            out << "\t#include <A/I/Driver.hh>\n";
            out << "\t\tstatic occ::A::Function* function_last = NULL;\n";
            out << "\t\tstatic occ::A::Instruction* instruction_last = NULL;\n";
            out << "\t\tstatic occ::Statement* statement_last = NULL;\n";
            out << "\t\tstatic occ::Block<occ::A::Declaration> declarations;\n";

        out << "}\n";

        // Emitted in the header file, after the definition of YYSTYPE.
        out << "%code provides\n";
        out << "{\n";
        // Tell Flex the expected prototype of yylex.
        // The scanner argument must be named yyscanner.
        out << "\t#define YY_DECL yytoken_kind_t yylex (YYSTYPE* yylval_param,YYLTYPE* yylloc, yyscan_t yyscanner, occ::A::I::Tray* tray)\n";
            out << "\tYY_DECL;\n";
            out << "\tvoid yyerror(YYLTYPE* yylloc,yyscan_t scanner,occ::A::I::Tray* tray, const char *msg, ...);\n";
            out << "\tvoid yyerror_unknow_symbol(YYLTYPE* yylloc,yyscan_t scanner, occ::A::I::Tray* tray, char);\n";
            //out << "using namespace occ = oct::cc::v1;\n";

        out << "}\n";

        // Emitted on top of the implementation file.
        out << "%code top\n";
        out << "{\n";
            out << "#include <stdarg.h>\n";
            out << "#include <stdio.h> \n";
            out << "#include <stdlib.h>\n";
            //out << "\t#include \"oas-intel.lexer.hh\"\n";

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
        out << "%param {yyscan_t scanner}{occ::A::I::Tray* tray}\n";


        out << "%token ENDOFFILE 0  \"end-of-file\"\n";
        //keywords
        out << "%token <occ::Keyword*> AUTO  110200 \"auto\"\n";
        declaration_add_keyword(out,"break");
        declaration_add_keyword(out,"case");
        declaration_add_keyword(out,"char");
        declaration_add_keyword(out,"const");
        declaration_add_keyword(out,"continue");
        declaration_add_keyword(out,"default");
        declaration_add_keyword(out,"do");
        declaration_add_keyword(out,"double");
        declaration_add_keyword(out,"else");
        declaration_add_keyword(out,"enum");
        declaration_add_keyword(out,"extern");
        declaration_add_keyword(out,"float");
        declaration_add_keyword(out,"for");
        declaration_add_keyword(out,"goto");
        declaration_add_keyword(out,"if");
        declaration_add_keyword(out,"int");
        declaration_add_keyword(out,"long");
        declaration_add_keyword(out,"register");
        declaration_add_keyword(out,"return");
        declaration_add_keyword(out,"short");
        declaration_add_keyword(out,"signed");
        declaration_add_keyword(out,"sizeof");
        declaration_add_keyword(out,"static");
        declaration_add_keyword(out,"struct");
        declaration_add_keyword(out,"switch");
        declaration_add_keyword(out,"typedef");
        declaration_add_keyword(out,"union");
        declaration_add_keyword(out,"unsigned");
        declaration_add_keyword(out,"void");
        declaration_add_keyword(out,"volatil");
        declaration_add_keyword(out,"while");

        //
        declaration_add_keyword(out,"aaa","AAA");
        declaration_add_keyword(out,"aad","AAD");
        declaration_add_keyword(out,"aam","AAM");
        declaration_add_keyword(out,"aas","AAS");
        declaration_add_keyword(out,"adc","ADC");
        declaration_add_keyword(out,"add","ADD");
        declaration_add_keyword(out,"and","AND");
        declaration_add_keyword(out,"call","CALL");
        declaration_add_keyword(out,"cbw","CBW");
        declaration_add_keyword(out,"clc","CLC");
        declaration_add_keyword(out,"cld","CLD");
        declaration_add_keyword(out,"cli","CLI");
        declaration_add_keyword(out,"cmc","CMC");
        declaration_add_keyword(out,"cmp","CMP");
        declaration_add_keyword(out,"cmps","CMPS");
        declaration_add_keyword(out,"cwd","CWD");
        declaration_add_keyword(out,"daa","DAA");
        declaration_add_keyword(out,"das","DAS");
        declaration_add_keyword(out,"dec","DEC");
        declaration_add_keyword(out,"div","DIV");
        out << "%token ESC\n";
        out << "%token HLT\n";
        out << "%token IDIV\n";
        out << "%token IMUL\n";
        out << "%token IN\n";
        out << "%token INC\n";
        out << "%token INTR\n";
        out << "%token INTO\n";
        declaration_add_keyword(out,"iret","IRET");
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
        declaration_add_keyword(out,"mov","MOV");
        out << "%token MOVS\n";
        out << "%token MOVSB\n";
        out << "%token MOVSW\n";
        out << "%token MUL\n";
        out << "%token NEG\n";
        out << "%token NOP\n";
        out << "%token NOT\n";
        out << "%token OR\n";
        out << "%token OUT\n";
        declaration_add_keyword(out,"pop");
        out << "%token POPF\n";
        declaration_add_keyword(out,"push");
        out << "%token PUSHF\n";
        out << "%token RCL\n";
        out << "%token RCR\n";
        out << "%token REPE\n";
        out << "%token REPZ\n";
        out << "%token REPNE\n";
        out << "%token REPNZ\n";
        declaration_add_keyword(out,"ret","RET");
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
        declaration_add_keyword_register(out,"al");
        declaration_add_keyword_register(out,"ah");
        declaration_add_keyword_register(out,"ax");
        declaration_add_keyword_register(out,"bl");
        declaration_add_keyword_register(out,"bh");
        declaration_add_keyword_register(out,"bx");
        declaration_add_keyword_register(out,"cl");
        declaration_add_keyword_register(out,"ch");
        declaration_add_keyword_register(out,"cx");
        declaration_add_keyword_register(out,"dl");
        declaration_add_keyword_register(out,"dh");
        declaration_add_keyword_register(out,"dx");

        out << "\n";

        //Ponters
        declaration_add_keyword(out,"sp");
        declaration_add_keyword(out,"bp");
        declaration_add_keyword(out,"si");
        declaration_add_keyword(out,"di");

        out << "\n";

        //Segments
        declaration_add_keyword_segment(out,"cs");
        declaration_add_keyword_segment(out,"ds");
        declaration_add_keyword_segment(out,"ss");
        declaration_add_keyword_segment(out,"es");
        declaration_add_keyword_segment(out,"fs");
        declaration_add_keyword_segment(out,"gs");

        out << "\n";

        out << "%token BYTE\n";
        out << "%token TINY\n";


        declaration_occ(out);
        declaration_C_expression(out);
        declaration_C_declaration(out);
        declaration_A(out);
        declaration_AI(out);


        out << "%start unit\n";
    }

    void Parser::declaration_add_keyword(std::ostream& out,const std::string& string,const std::string& token) const
    {
        out << "%token <occ::Keyword*> " << token << "\t\"" << string << "\"\n";
    }
    void Parser::declaration_add_keyword(std::ostream& out,const std::string& string) const
    {
        out << "%token <occ::Keyword*> " << core::toupper(string) << "\t\"" << string << "\"\n";
    }
    void Parser::declaration_add_keyword_register(std::ostream& out,const std::string& string) const
    {
        out << "%token <occ::A::Register*> " << core::toupper(string) << "\t\"" << string << "\"\n";
    }
    void Parser::declaration_add_keyword_segment(std::ostream& out,const std::string& string) const
    {
        out << "%token <occ::A::Segment*> " << core::toupper(string) << "\t\"" << string << "\"\n";
    }


    void Parser::declaration_occ(std::ostream& out) const
    {
        out << "%type <occ::A::Segment*> segments\n";
        out << "%token <occ::Letter*> LETTER\n";
        out << "%token <occ::Number*> INTEGER_DECIMAL\n";
        out << "%token <occ::Number*> INTEGER_HEXDECIMAL\n";
        out << "%type <occ::Integer*> integer\n";
        out << "%token <occ::Word*> IDENTIFIER\n";
        out << "%type <occ::Word*> identifier\n";
        out << "%type <occ::Keyword*> softword\n";
        out << "%type <occ::Statement*> statement\n";
        out << "%type <occ::Statement*> statements\n";
        out << "%type <occ::Node*> variable\n";
    }
    void Parser::declaration_A(std::ostream& out) const
    {
        out << "%type <occ::A::Function*> function\n";
        out << "%type <occ::A::Function*> functions\n";
        out << "%type <occ::A::Memory*> memory\n";//puede ser un identificador o un entero
        out << "%type <occ::A::Register*> registers_8b\n";
        out << "%type <occ::A::Register*> registers_16b\n";
        out << "%type <occ::A::Register*> registers\n";
        out << "%type <occ::A::Instruction*> inst\n";
        out << "%type <occ::A::Instruction*> instructions\n";
        out << "%type <occ::A::intel::Move*> move\n";
        out << "%type <occ::A::intel::Return*> ret\n";
        out << "%type <occ::A::intel::Interrupt*> interrupt\n";
        out << "%type <occ::A::intel::Call*> call\n";
        out << "%type <occ::A::intel::Push*> push\n";
        out << "%type <occ::A::intel::Pop*> pop\n";
    }
    void Parser::declaration_AI(std::ostream& out) const
    {
        out << "%type <occ::A::I::Unit*> unit\n";
    }
    void Parser::declaration_C_expression(std::ostream& out) const
    {
        out << "%type <occ::node*> assignment_expresion\n";
    }
    void Parser::declaration_C_declaration(std::ostream& out) const
    {
        out << "%type <occ::A::Declaration*> declaration\n";
        out << "%type <occ::node*> declaration_specifiers\n";
        out << "%type <occ::node*> init_declarator_list\n";
        out << "%type <occ::node*> init_declarator\n";
        out << "%type <occ::node*> storage_class_specifier\n";
        out << "%type <occ::node*> type_specifier\n";
        out << "%type <occ::node*> type_qualifier\n";
        out << "%type <occ::A::Declarator*> declarator\n";
        out << "%type <occ::Statement*> direct_declarator\n";
        out << "%type <occ::node*> pointer\n";
        out << "%type <occ::node*> type_qualifier_list\n";
        out << "%type <occ::node*> initializer\n";
        out << "%type <occ::node*> initializer_list\n";
    }

}

