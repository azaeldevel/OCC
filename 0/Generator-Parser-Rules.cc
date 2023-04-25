
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Parser::rules(std::ostream& out) const
    {
        rules_finals(out);
        rules_instructios(out);
        if(lang == Language::AII) rules_statement_AII(out);
        rules_declaration(out);
        switch(lang)
        {
        case Language::AI:
            rules_unit_AI(out);
            break;
        case Language::AII:
            rules_unit_AII(out);
            break;
        default:
            ;
        }
    }
    void Parser::rules_finals(std::ostream& out) const
    {
        out << "const_expression : CONSTANT_CHAR\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::initializer_literal<char>>();\n";
                out << "\t\treinterpret_cast<AI_here::nodes::initializer_literal<char>*>($$)->value = $1;\n";
                out << "\t\t$$->data_type = AI_here::Tokens::CONSTANT_CHAR;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "CONSTANT_INTEGER_HEX\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::initializer_literal<long long>>();\n";
                out << "\t\treinterpret_cast<AI_here::nodes::initializer_literal<long long>*>($$)->value = $1;\n";
                out << "\t\t$$->data_type = AI_here::Tokens::CONSTANT_INTEGER_HEX;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCONSTANT_INTEGER_DEC\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::initializer_literal<long long>>();\n";
                out << "\t\treinterpret_cast<AI_here::nodes::initializer_literal<long long>*>($$)->value = $1;\n";
                out << "\t\t$$->data_type = AI_here::Tokens::CONSTANT_INTEGER_DEC;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "consts_integer : CONSTANT_INTEGER_HEX {$$ = $1;}| CONSTANT_INTEGER_DEC {$$ = $1;};\n";


    }

    void Parser::rules_instructios(std::ostream& out) const
    {

        out << "registers_8b :\n";
            out << "\tAL\n";
            out << "\t{\n";
                out << "\t\t$$ = AL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tAH\n";
            out << "\t{\n";
                out << "\t\t$$ = AH;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBL\n";
            out << "\t{\n";
                out << "\t\t$$ = BL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBH\n";
            out << "\t{\n";
                out << "\t\t$$ = BH;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCL\n";
            out << "\t{\n";
                out << "\t\t$$ = CL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCH\n";
            out << "\t{\n";
                out << "\t\t$$ = CH;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDL\n";
            out << "\t{\n";
                out << "\t\t$$ = DL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDH\n";
            out << "\t{\n";
                out << "\t\t$$ = DH;\n";
            out << "\t}\n";
            out << "\t;\n\n";


        out << "registers_16b :\n";
            out << "\tAX\n";
            out << "\t{\n";
                out << "\t\t$$ = AX;\n";
            out << "\t}\n";
            out << "\t;\n\n";

        out << "instruction_mov :\n";
            out << "\tMOV registers_8b consts_integer ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"mov register-8b \" << $3 << \"\\n\";\n";
                out << "\t\tAI_here::nodes::move_8b_reg_byte* mv8 = tray->block.create<AI_here::nodes::move_8b_reg_byte>();\n";
                out << "\t\tmv8->registe = (AI_here::Tokens)$2;\n";
                out << "\t\tmv8->byte = (unsigned char)$3;\n";
                out << "\t\tmv8->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv8->is_instruction = true;\n";
                out << "\t\tmv8->type = 'I';\n";
                out << "\t\t$$ = mv8;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_8b CONSTANT_CHAR ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"mov register-8b \" << $3 << \"\\n\";\n";
                out << "\t\tAI_here::nodes::move_8b_reg_byte* mv8 = tray->block.create<AI_here::nodes::move_8b_reg_byte>();\n";
                out << "\t\tmv8->registe = (AI_here::Tokens)$2;\n";
                out << "\t\tmv8->byte = (unsigned char)$3;\n";
                out << "\t\tmv8->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv8->is_instruction = true;\n";
                out << "\t\tmv8->type = 'C';\n";
                out << "\t\t$$ = mv8;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_16b consts_integer\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t;\n\n";


        out << "instruction_int : \n";
            out << "\tINT consts_integer ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"int \" << $2 << \"\\n\";\n";
                out << "\t\tAI_here::nodes::instruction_int* serv = tray->block.create<AI_here::nodes::instruction_int>();\n";
                //if($2 > 127) yyerror("El parametro para la instruccion int dever ser un numero no mayo de de 128");
                out << "\t\tserv->service = $2;\n";
                out << "\t\tserv->inst = AI_here::Tokens::INT;\n";
                out << "\t\tserv->is_instruction = true;\n";
                out << "\t\t$$ = serv;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "instruction_ret : \n";
            out << "\tRET ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"RET 1\";\n";
                out << "\t\tAI_here::nodes::instruction* ret = tray->block.create<AI_here::nodes::instruction>();\n";
                out << "\t\tret->inst = AI_here::Tokens::RET;\n";
                out << "\t\tret->is_instruction = true;\n";
                out << "\t\t$$ = ret;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "instruction_label : IDENTIFIER ':'\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::instruction_label>();\n";
                out << "\t\t$$->id = $1;\n";
            out << "\t}\n";
            out << "\t;\n";

        switch(lang)
        {
        case Language::AI :
            rules_instructios_statment_AI(out);
            break;
        case Language::AII :
            rules_instructios_statment_AII(out);
            break;
        default:
            ;
        }



        out << "statement_list :\n";
            out << "\tstatement_instruction\n";
            out << "\t{\n";
                //std::cout << "statement_list : statement\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tstatement_list statement_instruction\n";
            out << "\t{\n";
                out << "\t\tstatic AI_here::nodes::statement *statement_prev = NULL;\n";

                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not statement_prev) statement_prev = $1;\n";
                out << "\t\tstatement_prev->next = $2;\n";


                out << "\t\tstatement_prev = $2;\n";
            out << "\t}\n";
            out << "\t;\n\n";

        out << "statement_list_body :\n";
            out << "\tstatement_instruction\n";
            out << "\t{\n";
                //out << "\tstd::cout << \"statement_list : statement\"\n" << "\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tstatement_list_body = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tstatement_list_body statement_instruction\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not statement_list_body) statement_list_body = $1;\n";
                out << "\t\tstatement_list_body->next = $2;\n";
                out << "\t\tstatement_list_body = $2;\n";
            out << "\t}\n";
            out << "\t;\n\n";

    }
    void Parser::rules_statement_AII(std::ostream& out) const
    {
        out << "statement_return : \n";
            out << "\tRETURN ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<A_here::nodes::return_statement>();\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tRETURN consts_integer ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<A_here::nodes::return_statement>();\n";
            out << "\t}\n";
            out << "\t;\n";
    }

    void Parser::rules_instructios_statment_AI(std::ostream& out) const
    {
        out << "statement_instruction :\n";
            out << "\tinstruction_mov\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinstruction_int\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            /*out << "\t|\n";
            out << "\tinstruction_label\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";*/
            /*out << "\t|\n";
            out << "\tinstruction_ret\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";*/
            out << "\t;\n\n";
    }
    void Parser::rules_instructios_statment_AII(std::ostream& out) const
    {
        out << "statement_instruction :\n";
            out << "\tinstruction_mov\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinstruction_int\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinstruction_label\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tstatement_return\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n\n";
    }
    void Parser::rules_declaration(std::ostream& out) const
    {
        out << "identifier_list : \n";
            out << "\tIDENTIFIER\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tidentifier_list IDENTIFIER\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "declarator :\n";
            out << "\tdirect_declarator\n";
            out << "\t{\n";
                //std::cout << "declarator : direct_declarator\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::declarator>();\n";
                out << "\t\t$$->point = NULL;\n";
                out << "\t\t$$->direct = $1;\n";
                //std::cout << "declarator 2\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "direct_declarator : IDENTIFIER\n";
            out << "\t{\n";
                //std::cout << "direct_declarator : IDENTIFIER\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::direct_declarator>();\n";
                out << "\t\t$$->id = $1;\n";
                out << "\t\t$$->direct = NULL;\n";
                //std::cout << $$->id->name << " ";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t'(' declarator ')'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdirect_declarator '[' const_expression ']'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdirect_declarator '['  ']'\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdirect_declarator '(' identifier_list ')'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
                out << "\t\t$$->identifier_list = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdirect_declarator '('  ')'\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\t$$->identifier_list = NULL;\n";
            out << "\t}\n";
            out << "\t;\n\n";


        out << "initializer : \n";
            out << "\tconst_expression\n";
            out << "\t{\n";
                out << "\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";



        out << "init_declarator_list : \n";
            out << "\tinit_declarator\n";
            out << "\t{\n";
                //std::cout << "init_declarator_list : init_declarator\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinit_declarator_list ',' init_declarator\n";
            out << "\t{\n";
                out << "\t\tstatic AI_here::nodes::init_declarator* statement_prev = NULL;\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not statement_prev) statement_prev = $1;\n";
                out << "\t\tstatement_prev->next = $3;\n";
                out << "\t\tstatement_prev = $3;\n";
            out << "\t}\n";
            out << "\t;\n";
        out << "init_declarator : \n";
            out << "\tdeclarator\n";
            out << "\t{\n";
                //std::cout << "init_declarator : declarator\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::init_declarator>();\n";
                out << "\t\t$$->dec = $1;\n";
                out << "\t\t$$->value = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclarator  initializer\n";
            out << "\t{\n";
                //std::cout << "init_declarator : declarator '=' initializer\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::init_declarator>();\n";
                out << "\t\t$$->dec = $1;\n";
                out << "\t\t$$->value = $2;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "type_specifier :\n";
            out << "\tVOID\n";
            out << "\t{\n";
                //std::cout << "type_specifier : VOID\n";
                //std::cout << "void ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::VOID;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCHAR\n";
            out << "\t{\n";
                //std::cout << "type_specifier : CHAR\n";
                //std::cout << "char ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::CHAR;\n";
                //$$->next = NULL;
                //std::cout << "type_specifier\n";
            out << "\t\t}\n";
            out << "\t\t|\n";
            out << "\t\tSHORT\n";
            out << "\t\t{\n";
                //std::cout << "type_specifier : SHORT\n";
                //std::cout << "short ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::SHORT;\n";
            out << "\t\t}\n";
            out << "\t|\n";
            out << "\t\tINT\n";
            out << "\t{\n";
                //std::cout << "type_specifier : INT\n";
                //std::cout << "int ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::INT;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tLONG\n";
            out << "\t{\n";
                //std::cout << "type_specifier : INT\n";
                //std::cout << "int ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::LONG;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tFLOAT\n";
            out << "\t{\n";
                //std::cout << "type_specifier : FLOAT\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::FLOAT;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDOUBLE\n";
            out << "\t{\n";
                //std::cout << "type_specifier : DOUBLE\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::DOUBLE;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSIGNED\n";
            out << "\t{\n";
                //std::cout << "type_specifier : SIGNED\n";
                //std::cout << "signed ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::SIGNED;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tUNSIGNED\n";
            out << "\t{\n";
                //std::cout << "type_specifier : UNSIGNED\n";
                //std::cout << "unsigned ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::UNSIGNED;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBYTE\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::BYTE;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "declaration_specifiers :\n";
            out << "\ttype_specifier\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclaration_specifiers type_specifier\n";
            out << "\t{\n";
                out << "\t\tstatic AI_here::nodes::type_specifier* statement_prev = NULL;\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not statement_prev) statement_prev = $1;\n";
                out << "\t\tstatement_prev->next = $2;\n";
                out << "\t\tstatement_prev = $2;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "declaration :\n";
            out << "\tdeclaration_specifiers\n";
            out << "\t{\n";
                //std::cout << "declaration : declaration_specifiers\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::declaration>();\n";
                out << "\t\t$$->specifiers = $1;\n";
                out << "\t\t$$->list = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclaration_specifiers init_declarator_list\n";
            out << "\t{\n";
                //std::cout << "declaration : declaration_specifiers init_declarator_list\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::declaration>();\n";
                out << "\t\t$$->specifiers = $1;\n";
                out << "\t\t$$->list = $2;\n";
            out << "\t}\n";
            out << "\t;\n";
        out << "declaration_list :\n";
            out << "\tdeclaration ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"declaration\";\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclaration_list declaration ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"declaration\";\n";
                out << "\t\tstatic AI_here::nodes::declaration* statement_prev = NULL;\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not statement_prev) statement_prev = $1;\n";
                out << "\t\tstatement_prev->next = $2;\n";
                out << "\t\tstatement_prev = $2;\n";
            out << "\t}\n";
            out << "\t;\n";
    }
    void Parser::rules_unit_AI(std::ostream& out) const
    {
        out << "function :\n";
            out << "\tIDENTIFIER ':' statement_list_body RET ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << $1->name << \":\\n\";\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::function>();\n";
                out << "\t\t$$->id = $1;\n";
                out << "\t\t$$->body_list = $3;\n";
            out << "\t}\n";
            /*
            out << "\t|\n";
            out << "\tIDENTIFIER ':' statement_list IRET ';'\n";
            out << "\t{\n";
            out << "\t}\n";
            */
            out << "\t;\n";

        out << "function_list :\n";
            out << "\tfunction\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"function\";\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tfunction_list function\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"function\";\n";
                out << "\t\tstatic AI_here::nodes::function* statement_prev = NULL;\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not statement_prev) statement_prev = $1;\n";
                out << "\t\tstatement_prev->next = $2;\n";
                out << "\t\tstatement_prev = $2;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "translation_unit :\n";
            out << "\tdeclaration_list function_list\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::translation_unit>();\n";
                out << "\t\t$$->declarations = $1;\n";
                out << "\t\t$$->functions = $2;\n";
                out << "\t\ttray->unit = $$;\n";
            out << "\t}\n";
            out << "\t;\n";
    }
    void Parser::rules_unit_AII(std::ostream& out) const
    {

        out << "compound_statement :\n";
            out << "\t'{' statement_list '}'\n";
            out << "\t{\n";
                //std::cout << "compound_statement : '{' statement_list '}'\n";
                out << "\t\t$$ = tray->block.create<AII_here::nodes::compound_statement>();\n";
                out << "\t\t$$->statement_list = $2;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t'{' '}'\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AII_here::nodes::compound_statement>();\n";
                out << "\t\t$$->statement_list = NULL;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "function_implementation :\n";
            out << "\tdeclaration_specifiers declarator compound_statement\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AII_here::nodes::function_implementation>();\n";
                out << "\t\t$$->body = $3;\n";
                out << "\t\t$$->declaration = $2;\n";
                out << "\t\t$$->specifiers = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclarator compound_statement\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AII_here::nodes::function_implementation>();\n";
                out << "\t\t$$->body = $2;\n";
                out << "\t\t$$->declaration = $1;\n";
                out << "\t\t$$->specifiers = NULL;\n";
                //std::cout << "Function 3\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "external_declaration :\n";
            out << "\tfunction_implementation\n";
            out << "\t{\n";
                //std::cout << "external_declaration : function_implementation\n";
                //$1->print(std::cout);
                out << "\t\t$$ = tray->block.create<AII_here::nodes::external_declaration>();\n";
                out << "\t\t$$->func = $1;\n";
                out << "\t\t$$->decl = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclaration ';'\n";
            out << "\t{\n";
                //std::cout << "storage_class_specifier : declaration ';'\n";
                //std::cout << ";\n";
                //$1->print(std::cout);
                out << "\t\t$$ = tray->block.create<AII_here::nodes::external_declaration>();\n";
                out << "\t\t$$->func = NULL;\n";
                out << "\t\t$$->decl = $1;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "translation_unit :\n";
            out << "\texternal_declaration\n";
            out << "\t{\n";
                //std::cout << "external_declaration\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\ttray->unit = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttranslation_unit external_declaration\n";
            out << "\t{\n";
                //std::cout << "external_declaration translation_unit\n";
                out << "\t\tstatic AII_here::nodes::external_declaration* statement_prev = NULL;\n";
                out << "\t\t$$ = $1;\n";
                //$2->print(std::cout);
                out << "\t\tif(not statement_prev) statement_prev = $1;\n";
                out << "\t\tstatement_prev->next = $2;\n";
                out << "\t\tstatement_prev = $2;\n";
            out << "\t}\n";
            out << "\t;\n";
    }
}

