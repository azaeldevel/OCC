
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Parser::rules(std::ostream& out) const
    {
        out << "const_integer : CONSTANT_INTEGER_HEX {$$ = $1;}| CONSTANT_INTEGER_DEC {$$ = $1;};\n";
        rules_instructions(out);

        rules_declarations(out);

        switch(lang)
        {
        case Language::AI:
            rules_translation_unit_AI(out);
            break;
        case Language::AII:
            rules_translation_unit_AII(out);
            break;
        default:
            ;
        }
    }
    void Parser::rules_finals(std::ostream& out) const
    {
    }



    void Parser::rules_constants(std::ostream& out) const
    {
        out << "\n\n//6.1.3\n";
        out << "constant :\n";
            out << "\tinteger_constant\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tcharter_constant\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n\n";


        out << "integer_constant :\n";
            out << "\tdecimal_constant integer_suffix\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdecimal_constant\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\toctal_constant integer_suffix\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\toctal_constant\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\thexadecimal_constant integer_suffix\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\thexadecimal_constant\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n\n";
    }
    void Parser::rules_primary_expression(std::ostream& out) const
    {
        out << "\n\n//6.3.1\n";
        out << "primary_expression :\n";
            out << "\tIDENTIFIER\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCONSTANT_INTEGER_HEX\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCONSTANT_INTEGER_DEC\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCONSTANT_CHAR\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";

            out << "\t|\n";
            out << "\t'(' primary_expression ')' \n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n\n";
    }

    void Parser::rules_instructions(std::ostream& out) const
    {

        out << "registers_8b :\n";
            out << "\tAL\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::AL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tAH\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::AH;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBL\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::BL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBH\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::BH;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCL\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::CL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCH\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::CH;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDL\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::DL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDH\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::DH;\n";
            out << "\t}\n";
            out << "\t;\n\n";


        out << "registers_16b :\n";
            out << "\tAX\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::AX;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBX\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::BX;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCX\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::CX;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDX\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::DX;\n";
            out << "\t}\n";
            out << "\t;\n\n";

    /*out << "registers :\n";
            out << "\tregisters_16b\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tregisters_8b\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n\n";*/

    /*out << "index_array :\n";
            out << "\tregisters\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tsegments\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n\n";*/

        out << "segments :\n";
            out << "\tES\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::ES;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCS\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::CS;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSS\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::SS;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDS\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::DS;\n";
            out << "\t}\n";
            out << "\t;\n\n";

        out << "move :\n";
            out << "\tMOV registers_8b ',' const_integer ';'\n";
            out << "\t{\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";//registro
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tAI_here::nodes::Token<AI_here::integer>* source = tray->block.create<AI_here::nodes::Token<AI_here::integer>>();\n";
                out << "\t\tsource->token = $4;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 8;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::regiter_integer;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_8b ',' CONSTANT_CHAR ';'\n";
            out << "\t{\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";//registro
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tAI_here::nodes::Token<char>* source = tray->block.create<AI_here::nodes::Token<char>>();\n";
                out << "\t\tsource->token = $4;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 8;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::regiter_char;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_16b ',' const_integer ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV segments ',' const_integer ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_16b ',' segments ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV segments ',' registers_16b ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV segments ',' IDENTIFIER ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV IDENTIFIER ',' segments ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV IDENTIFIER ',' registers_8b ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_8b ','  IDENTIFIER ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV IDENTIFIER ',' registers_16b ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_16b ',' IDENTIFIER ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            /*{//MAYBE:operaciones con arreglos
                out << "\t|\n";
                out << "\tMOV registers_8b ',' IDENTIFIER '['  index_array ']' ';'\n";
                out << "\t{\n";
                    out << "\t\t$$ = NULL;\n";
                out << "\t}\n";
                out << "\t|\n";
                out << "\tMOV IDENTIFIER '['  index_array ']' ',' registers_8b ';'\n";
                out << "\t{\n";
                    out << "\t\t$$ = NULL;\n";
                out << "\t}\n";
                out << "\t|\n";
                out << "\tMOV registers_16b ',' IDENTIFIER '['  index_array ']' ';'\n";
                out << "\t{\n";
                    out << "\t\t$$ = NULL;\n";
                out << "\t}\n";
                out << "\t|\n";
                out << "\tMOV IDENTIFIER '['  index_array ']' ',' registers_16b ';'\n";
                out << "\t{\n";
                    out << "\t\t$$ = NULL;\n";
                out << "\t}\n";
                out << "\t|\n";
                out << "\tMOV IDENTIFIER '['  index_array ']' ',' segments ';'\n";
                out << "\t{\n";
                    out << "\t\t$$ = NULL;\n";
                out << "\t}\n";
                out << "\t|\n";
                out << "\tMOV segments ',' IDENTIFIER '['  index_array ']' ';'\n";
                out << "\t{\n";
                    out << "\t\t$$ = NULL;\n";
                out << "\t}\n";
                out << "\t|\n";
                out << "\tMOV segments ',' '&' IDENTIFIER  ';'\n";
                out << "\t{\n";
                    out << "\t\t$$ = NULL;\n";
                out << "\t}\n";
                out << "\t|\n";
                out << "\tMOV registers ',' '&' IDENTIFIER  ';'\n";
                out << "\t{\n";
                    out << "\t\t$$ = NULL;\n";
                out << "\t}\n";
            }*/
            out << "\t;\n\n";


        out << "interruption : \n";
            out << "\tINT const_integer ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"int \" << $2 << \"\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Interruption* serv = tray->block.create<AI_here::nodes::intel::i8086::Interruption>();\n";
                //out << "\t\t$$ = new(serv) AI_here::nodes::intel::i8086::Interruption;\n";
                //if($2 > 127) yyerror("El parametro para la instruccion int dever ser un numero no mayo de de 128");
                out << "\t\tserv->service = $2;\n";
                out << "\t\tserv->inst = AI_here::Tokens::INT;\n";
                out << "\t\tserv->is_instruction = true;\n";
                out << "\t\t$$ = serv;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "label : IDENTIFIER ':'\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::intel::i8086::Label>();\n";
                out << "\t\t$$->id = $1;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "ret : \n";
            out << "\tRET ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"RET 1\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Return* ret = tray->block.create<AI_here::nodes::intel::i8086::Return>();\n";
                out << "\t\tret->inst = AI_here::Tokens::RET;\n";
                out << "\t\tret->is_instruction = true;\n";
                out << "\t\t$$ = ret;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "instructions :\n";
            out << "\tmove\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinterruption\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tlabel\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tret\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n\n";

        switch(lang)
        {
        case Language::AI :
            rules_instructions_AI(out);
            break;
        case Language::AII :
            rules_instructions_AII(out);
            break;
        default:
            ;
        }
    }

    void Parser::rules_instructions_AI(std::ostream& out) const
    {
        out << "instructions_list :\n";
            out << "\tinstructions\n";
            out << "\t{\n";
                //out << "\tstd::cout << \"statement_list : statement\"\n" << "\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tstatement_list_body = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinstructions_list instructions\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not statement_list_body) statement_list_body = $1;\n";
                out << "\t\tstatement_list_body->next = $2;\n";
                out << "\t\tstatement_list_body = $2;\n";
            out << "\t}\n";
            out << "\t;\n\n";

    }
    void Parser::rules_instructions_AII(std::ostream& out) const
    {

        out << "statement_list :\n";
            out << "\tstatements\n";
            out << "\t{\n";
                //std::cout << "statement_list : statement\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tstatement_list statements\n";
            out << "\t{\n";
                out << "\t\tstatic AI_here::nodes::statement *statement_prev = NULL;\n";

                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not statement_prev) statement_prev = $1;\n";
                out << "\t\tstatement_prev->next = $2;\n";


                out << "\t\tstatement_prev = $2;\n";
            out << "\t}\n";
            out << "\t;\n\n";

        out << "Return : \n";
            out << "\tRETURN ';'\n";
            out << "\t{\n";
                out << "\t\tA_here::nodes::Return* ret = tray->block.create<A_here::nodes::C::Return>();\n";
                out << "\t\tret->inst = AI_here::Tokens::RETURN;\n";
                out << "\t\tret->is_instruction = false;\n";
                out << "\t\t$$ = ret;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tRETURN const_integer ';'\n";
            out << "\t{\n";
                out << "\t\tA_here::nodes::Return* ret = tray->block.create<A_here::nodes::C::Return>();\n";
                out << "\t\tret->inst = AI_here::Tokens::RETURN;\n";
                out << "\t\tret->is_instruction = false;\n";
                out << "\t\t$$ = ret;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "statements :\n";
            out << "\tinstructions\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tReturn\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n\n";
    }

    void Parser::rules_declarator(std::ostream& out) const
    {
        out << "\n//6.5.4\n";
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
            /*
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
            out << "\t}\n";*/
            out << "\t|\n";
            out << "\tdirect_declarator '('  ')'\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\t$$->identifier_list = NULL;\n";
            out << "\t}\n";
            out << "\t;\n\n";
        /*
        out << " : \n";
            out << "\t\n";
            out << "\t{\n";
                out << "\t\t;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << " : \n";
            out << "\t\n";
            out << "\t{\n";
                out << "\t\t;\n";
            out << "\t}\n";
            out << "\t;\n";
        */
    }
    void Parser::rules_declarations(std::ostream& out) const
    {
        out << "\n//6.5\n";
        out << "declaration :\n";
            out << "\tdeclaration_specifiers ';'\n";
            out << "\t{\n";
                //std::cout << "declaration : declaration_specifiers\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::declaration>();\n";
                out << "\t\t$$->specifiers = $1;\n";
                out << "\t\t$$->list = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclaration_specifiers init_declarator_list ';'\n";
            out << "\t{\n";
                //std::cout << "declaration : declaration_specifiers init_declarator_list\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::declaration>();\n";
                out << "\t\t$$->specifiers = $1;\n";
                out << "\t\t$$->list = $2;\n";
                out << "\t\ttray->symbols.add($$);\n";
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
            out << "\tdeclarator" << (has_assignment_operator() ? " '=' " : " " ) << "initializer\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"init_declarator : declarator '=' initializer\\n\";\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::init_declarator>();\n";
                out << "\t\t$$->dec = $1;\n";
                out << "\t\t$$->value = $2;\n";
            out << "\t}\n";
            out << "\t;\n";


        //6.5.2
        out << "\n\n//6.5.2\n";
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
            out << "\t}\n";
            if(is_disnastic_A())
            {
                out << "\t|\n";
                out << "\tBYTE\n";
                out << "\t{\n";
                    out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                    out << "\t\t$$->type = AI_here::Tokens::BYTE;\n";
                out << "\t}\n";
                out << "\t|\n";
                out << "\tTINY\n";
                out << "\t{\n";
                    out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                    out << "\t\t$$->type = AI_here::Tokens::TINY;\n";
                out << "\t}\n";
            }
            out << "\t|\n";
            out << "\tSHORT\n";
            out << "\t{\n";
                //std::cout << "type_specifier : SHORT\n";
                //std::cout << "short ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::type_specifier>();\n";
                out << "\t\t$$->type = AI_here::Tokens::SHORT;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tINT\n";
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
            out << "\t;\n";

        //6.5.4
        rules_declarator(out);

        //6.5.7
        out << "initializer : \n";
        //esta seccion no es parte del estandar C
        {
            out << "\tCONSTANT_INTEGER_DEC\n";
            out << "\t{\n";
                out << "\t\tAI_here::nodes::initializer_literal<AI_here::integer>* data = tray->block.create<AI_here::nodes::initializer_literal<AI_here::integer>>();\n";
                out << "\t\tdata->value = $1;\n";
                out << "\t\tdata->data_type = AI_here::Tokens::CONSTANT_INTEGER_DEC;\n";
                out << "\t\t$$ = data;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCONSTANT_INTEGER_HEX\n";
            out << "\t{\n";
                out << "\t\tAI_here::nodes::initializer_literal<AI_here::integer>* data = tray->block.create<AI_here::nodes::initializer_literal<AI_here::integer>>();\n";
                out << "\t\tdata->value = $1;\n";
                out << "\t\tdata->data_type = AI_here::Tokens::CONSTANT_INTEGER_HEX;\n";
                out << "\t\t$$ = data;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCONSTANT_CHAR\n";
            out << "\t{\n";
                out << "\t\tAI_here::nodes::initializer_literal<char>* data = tray->block.create<AI_here::nodes::initializer_literal<char>>();\n";
                out << "\t\tdata->value = $1;\n";
                out << "\t\t$$ = data;\n";
                out << "\t\tdata->data_type = AI_here::Tokens::CONSTANT_CHAR;\n";
            out << "\t}\n";
            out << "\t;\n";
        }

        /*
        out << " : \n";
            out << "\t\n";
            out << "\t{\n";
                out << "\t\t;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << " : \n";
            out << "\t\n";
            out << "\t{\n";
                out << "\t\t;\n";
            out << "\t}\n";
            out << "\t;\n";
        */
    }

    void Parser::rules_translation_unit_AI(std::ostream& out) const
    {
        out << "declaration_list :\n";
            out << "\tdeclaration\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"declaration\";\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclaration_list declaration\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"declaration\";\n";
                out << "\t\tstatic AI_here::nodes::declaration* statement_prev = NULL;\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not statement_prev) statement_prev = $1;\n";
                out << "\t\tstatement_prev->next = $2;\n";
                out << "\t\tstatement_prev = $2;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "function :\n";
            out << "\tIDENTIFIER ':' '{' instructions_list '}'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << $1->name << \":\\n\";\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::function>();\n";
                out << "\t\t$$->id = $1;\n";
                out << "\t\t$$->body_list = $4;\n";
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
    void Parser::rules_translation_unit_AII(std::ostream& out) const
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


        out << "function_definition :\n";
            out << "\tdeclaration_specifiers declarator compound_statement\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AII_here::nodes::function_definition>();\n";
                out << "\t\t$$->body = $3;\n";
                out << "\t\t$$->declaration = $2;\n";
                out << "\t\t$$->specifiers = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclarator compound_statement\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AII_here::nodes::function_definition>();\n";
                out << "\t\t$$->body = $2;\n";
                out << "\t\t$$->declaration = $1;\n";
                out << "\t\t$$->specifiers = NULL;\n";
                //std::cout << "Function 3\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "external_declaration :\n";
            out << "\tfunction_definition\n";
            out << "\t{\n";
                //std::cout << "external_declaration : function_implementation\n";
                //$1->print(std::cout);
                out << "\t\t$$ = tray->block.create<AII_here::nodes::external_declaration>();\n";
                out << "\t\t$$->func = $1;\n";
                out << "\t\t$$->decl = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclaration\n";
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

