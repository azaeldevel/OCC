
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Parser::rules(std::ostream& out) const
    {
        rules_finals(out);
        rules_instructios(out);
        rules_declaration(out);
        rules_unit(out);
    }
    void Parser::rules_finals(std::ostream& out) const
    {
        out << "const_expression : CONSTANT_CHAR\n";
            out << "\t{\n";
                out << "\t\t$$ = block.create<AI_here::nodes::initializer_literal<char>>();\n";
                out << "\t\treinterpret_cast<AI_here::nodes::initializer_literal<char>*>($$)->value = $1;\n";
                out << "\t\t$$->data_type = AI_here::Tokens::CONSTANT_CHAR;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "CONSTANT_INTEGER_HEX\n";
            out << "\t{\n";
                out << "\t\t$$ = block.create<AI_here::nodes::initializer_literal<long long>>();\n";
                out << "\t\treinterpret_cast<AI_here::nodes::initializer_literal<long long>*>($$)->value = $1;\n";
                out << "\t\t$$->data_type = AI_here::Tokens::CONSTANT_INTEGER_HEX;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCONSTANT_INTEGER_DEC\n";
            out << "\t{\n";
                out << "\t\t$$ = block.create<AI_here::nodes::initializer_literal<long long>>();\n";
                out << "\t\treinterpret_cast<AI_here::nodes::initializer_literal<long long>*>($$)->value = $1;\n";
                out << "\t\t$$->data_type = AI_here::Tokens::CONSTANT_INTEGER_DEC;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "consts_integer : CONSTANT_INTEGER_HEX {$$ = $1;}| CONSTANT_INTEGER_DEC {$$ = $1;};\n";


    }

    void Parser::rules_instructios(std::ostream& out) const
    {

        out << "registers_8b :\n";
            out << "AL\n";
            out << "\t{\n";
                out << "\t\t$$ = token::token_kind_type::AL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tAH\n";
            out << "\t{\n";
                out << "\t\t$$ = token::token_kind_type::AH;\n";
            out << "\t}\n";
            out << "|\n";
            out << "BL\n";
            out << "{\n";
                out << "$$ = token::token_kind_type::BL;\n";
            out << "}\n";
            out << "|\n";
            out << "BH\n";
            out << "{\n";
                out << "$$ = token::token_kind_type::BH;\n";
            out << "}\n";
            out << "|\n";
            out << "CL\n";
            out << "{\n";
                out << "$$ = token::token_kind_type::CL;\n";
            out << "}\n";
            out << "|\n";
            out << "CH\n";
            out << "{\n";
                out << "$$ = token::token_kind_type::CH;\n";
            out << "}\n";
            out << "|\n";
            out << "DL\n";
            out << "{\n";
                out << "$$ = token::token_kind_type::DL;\n";
            out << "}\n";
            out << "|\n";
            out << "DH\n";
            out << "{\n";
                out << "$$ = token::token_kind_type::DH;\n";
            out << "}\n";
            out << ";\n";



        out << "registers_16b :\n";
            out << "AX\n";
            out << "{\n";
                out << "$$ = token::token_kind_type::AX;\n";
            out << "}\n";
            out << ";\n";

        out << "instruction_mov :\n";
            out << "MOV registers_8b consts_integer ';'\n";
            out << "{\n";
                //std::cout << "mov register-8b integer\n";
                out << "AI_here::nodes::move_8b_reg_byte* mv8 = block.create<AI_here::nodes::move_8b_reg_byte>();\n";
                out << "mv8->registe = (AI_here::Tokens)$2;\n";
                out << "mv8->byte = (unsigned char)$3;\n";
                out << "mv8->inst = AI_here::Tokens::MOV;\n";
                out << "mv8->is_instruction = true;\n";
                out << "mv8->type = 'I';\n";
                out << "$$ = mv8;\n";
            out << "}\n";
            out << "|\n";
            out << "MOV registers_8b CONSTANT_CHAR ';'\n";
            out << "{\n";
                //std::cout << "mov register-8b char\n";
                out << "AI_here::nodes::move_8b_reg_byte* mv8 = block.create<AI_here::nodes::move_8b_reg_byte>();\n";
                out << "mv8->registe = (AI_here::Tokens)$2;\n";
                out << "mv8->byte = (unsigned char)$3;\n";
                out << "mv8->inst = AI_here::Tokens::MOV;\n";
                out << "mv8->is_instruction = true;\n";
                out << "mv8->type = 'C';\n";
                out << "$$ = mv8;\n";
            out << "}\n";
            out << "|\n";
            out << "MOV registers_16b consts_integer\n";
            out << "{\n";
                out << "$$ = NULL;\n";
            out << "}\n";
            out << ";\n";


        out << "instruction_int : INT consts_integer ';'\n";
            out << "{\n";
                //std::cout << "int " << $2 << "\n";
                out << "AI_here::nodes::instruction_int* serv = block.create<AI_here::nodes::instruction_int>();\n";
                //if($2 > 127) yyerror("El parametro para la instruccion int dever ser un numero no mayo de de 128");
                out << "serv->service = $2;\n";
                out << "serv->inst = AI_here::Tokens::INT;\n";
                out << "serv->is_instruction = true;\n";
                out << "$$ = serv;\n";
            out << "}\n";
            out << ";\n";

        out << "instruction_label : IDENTIFIER ':'\n";
            out << "{\n";
                out << "$$ = block.create<AI_here::nodes::instruction_label>();\n";
                out << "$$->id = $1;\n";
            out << "}\n";
            out << ";\n";


        out << "statement_instruction :\n";
            out << "instruction_mov\n";
            out << "{\n";
                out << "$$ = $1;\n";
            out << "}\n";
            out << "|\n";
            out << "instruction_int\n";
            out << "{\n";
                out << "$$ = $1;\n";
            out << "}\n";
            out << "|\n";
            out << "instruction_label\n";
            out << "{\n";
                out << "$$ = $1;\n";
            out << "}\n";
            out << ";\n";



        out << "statement_list :\n";
            out << "statement_instruction\n";
            out << "{\n";
                //std::cout << "statement_list : statement\n";
                out << "$$ = $1;\n";
            out << "}\n";
            out << "|\n";
            out << "statement_list statement_instruction\n";
            out << "{\n";
                out << "static AI_here::nodes::statement *statement_prev = NULL;\n";

                out << "$$ = $1;\n";
                out << "if(not statement_prev) statement_prev = $1;\n";
                out << "statement_prev->next = $2;\n";


                out << "statement_prev = $2;\n";
            out << "}\n";
            out << ";\n";


    }
    void Parser::rules_declaration(std::ostream& out) const
    {
        out << "identifier_list : IDENTIFIER\n";
            out << "{\n";
                out << "$$ = NULL;\n";
            out << "}\n";
            out << "|\n";
            out << "identifier_list IDENTIFIER\n";
            out << "{\n";
                out << "$$ = NULL;\n";
            out << "}\n";
            out << ";\n";


        out << "declarator :\n";
            out << "direct_declarator\n";
            out << "{\n";
                //std::cout << "declarator : direct_declarator\n";
                out << "$$ = block.create<AI_here::nodes::declarator>();\n";
                out << "$$->point = NULL;\n";
                out << "$$->direct = $1;\n";
                //std::cout << "declarator 2\n";
            out << "}\n";
            out << ";\n";

        out << "direct_declarator : IDENTIFIER\n";
            out << "{\n";
                //std::cout << "direct_declarator : IDENTIFIER\n";
                out << "$$ = block.create<AI_here::nodes::direct_declarator>();\n";
                out << "$$->id = $1;\n";
                out << "$$->direct = NULL;\n";
                //std::cout << $$->id->name << " ";
            out << "}\n";
            out << "|\n";
            out << "'(' declarator ')'\n";
            out << "{\n";
                out << "$$ = NULL;\n";
            out << "}\n";
            out << "|\n";
            out << "direct_declarator '[' const_expression ']'\n";
            out << "{\n";
                out << "$$ = NULL;\n";
            out << "}\n";
            out << "|\n";
            out << "direct_declarator '['  ']'\n";
            out << "{\n";
                out << "$$ = $1;\n";
            out << "}\n";
            out << "|\n";
            out << "direct_declarator '(' identifier_list ')'\n";
            out << "{\n";
                out << "$$ = NULL;\n";
                out << "$$->identifier_list = NULL;\n";
            out << "}\n";
            out << "|\n";
            out << "direct_declarator '('  ')'\n";
            out << "{\n";
                out << "$$ = $1;\n";
                out << "$$->identifier_list = NULL;\n";
            out << "}\n";
            out << ";\n";


        out << "initializer : const_expression\n";
            out << "{\n";
                out << "$$ = $1;\n";
            out << "}\n";
            out << ";\n";



        out << "init_declarator_list : init_declarator\n";
            out << "{\n";
                //std::cout << "init_declarator_list : init_declarator\n";
                out << "$$ = $1;\n";
            out << "}\n";
            out << "|\n";
            out << "init_declarator_list ',' init_declarator\n";
            out << "{\n";
                out << "static AI_here::nodes::init_declarator* statement_prev = NULL;\n";
                out << "$$ = $1;\n";
                out << "if(not statement_prev) statement_prev = $1;\n";
                out << "statement_prev->next = $3;\n";


                out << "statement_prev = $3;\n";
            out << "}\n";
            out << ";\n";
        out << "init_declarator : declarator\n";
            out << "{\n";
                //std::cout << "init_declarator : declarator\n";
                out << "$$ = block.create<AI_here::nodes::init_declarator>();\n";
                out << "$$->dec = $1;\n";
                out << "$$->value = NULL;\n";
            out << "}\n";
            out << "|\n";
            out << "declarator  initializer\n";
            out << "{\n";
                //std::cout << "init_declarator : declarator '=' initializer\n";
                out << "$$ = block.create<AI_here::nodes::init_declarator>();\n";
                out << "$$->dec = $1;\n";
                out << "$$->value = $2;\n";
            out << "}\n";
            out << ";\n";


        out << "type_specifier :\n";
            out << "VOID\n";
            out << "{\n";
                //std::cout << "type_specifier : VOID\n";
                //std::cout << "void ";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::VOID;\n";
            out << "}\n";
            out << "|\n";
            out << "CHAR\n";
            out << "{\n";
                //std::cout << "type_specifier : CHAR\n";
                //std::cout << "char ";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::CHAR;\n";
                //$$->next = NULL;
                //std::cout << "type_specifier\n";
            out << "}\n";
            out << "|\n";
            out << "SHORT\n";
            out << "{\n";
                //std::cout << "type_specifier : SHORT\n";
                //std::cout << "short ";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::SHORT;\n";
            out << "}\n";
            out << "|\n";
            out << "INT\n";
            out << "{\n";
                //std::cout << "type_specifier : INT\n";
                //std::cout << "int ";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::INT;\n";
            out << "}\n";
            out << "|\n";
            out << "LONG\n";
            out << "{\n";
                //std::cout << "type_specifier : INT\n";
                //std::cout << "int ";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::LONG;\n";
            out << "}\n";
            out << "|\n";
            out << "FLOAT\n";
            out << "{\n";
                //std::cout << "type_specifier : FLOAT\n";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::FLOAT;\n";
            out << "}\n";
            out << "|\n";
            out << "DOUBLE\n";
            out << "{\n";
                //std::cout << "type_specifier : DOUBLE\n";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::DOUBLE;\n";
            out << "}\n";
            out << "|\n";
            out << "SIGNED\n";
            out << "{\n";
                //std::cout << "type_specifier : SIGNED\n";
                //std::cout << "signed ";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::SIGNED;\n";
            out << "}\n";
            out << "|\n";
            out << "UNSIGNED\n";
            out << "{\n";
                //std::cout << "type_specifier : UNSIGNED\n";
                //std::cout << "unsigned ";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::UNSIGNED;\n";
            out << "}\n";
            out << "|\n";
            out << "BYTE\n";
            out << "{\n";
                out << "$$ = block.create<AI_here::nodes::type_specifier>();\n";
                out << "$$->type = AI_here::Tokens::BYTE;\n";
            out << "}\n";
            out << ";\n";


        out << "declaration_specifiers :\n";
            out << "type_specifier\n";
            out << "{\n";
                out << "$$ = $1;\n";
            out << "}\n";
            out << "|\n";
            out << "declaration_specifiers type_specifier\n";
            out << "{\n";
                out << "static AI_here::nodes::type_specifier* statement_prev = NULL;\n";
                out << "$$ = $1;\n";
                out << "if(not statement_prev) statement_prev = $1;\n";
                out << "statement_prev->next = $2;\n";


                out << "statement_prev = $2;\n";
            out << "}\n";
            out << ";\n";


        out << "declaration :\n";
            out << "declaration_specifiers\n";
            out << "{\n";
                //std::cout << "declaration : declaration_specifiers\n";
                out << "$$ = block.create<AI_here::nodes::declaration>();\n";
                out << "$$->specifiers = $1;\n";
                out << "$$->list = NULL;\n";
            out << "}\n";
            out << "|\n";
            out << "declaration_specifiers init_declarator_list\n";
            out << "{\n";
                //std::cout << "declaration : declaration_specifiers init_declarator_list\n";
                out << "$$ = block.create<AI_here::nodes::declaration>();\n";
                out << "$$->specifiers = $1;\n";
                out << "$$->list = $2;\n";
            out << "}\n";
            out << ";\n";


        out << "declaration_list :\n";
            out << "declaration ';'\n";
            out << "{\n";
                out << "$$ = $1;\n";
            out << "}\n";
            out << "|\n";
            out << "declaration_list declaration ';'\n";
            out << "{\n";
                out << "static AI_here::nodes::declaration* statement_prev = NULL;\n";
                out << "$$ = $1;\n";
                out << "if(not statement_prev) statement_prev = $1;\n";
                out << "statement_prev->next = $2;\n";


                out << "statement_prev = $2;\n";
            out << "}\n";
            out << ";\n";
    }
    void Parser::rules_unit(std::ostream& out) const
    {
        out << "translation_unit :\n";
            out << "declaration_list statement_list\n";
            out << "{\n";
                out << "$$ = block.create<AI_here::nodes::translation_unit>();\n";
                out << "$$->declarations = $1;\n";
                out << "$$->instructions = $2;\n";
                out << "*unit = $$;\n";
            out << "}\n";            out << ";\n";

    }
}

