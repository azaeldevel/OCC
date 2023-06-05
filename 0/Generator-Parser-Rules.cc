
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Parser::rules(std::ostream& out) const
    {
        out << "constant_integer : constant_integer_16b {$$ = $1;};\n";
        out << "constant_integer_8b : CONSTANT_INTEGER_DEC_8b {$$ = $1;} | CONSTANT_INTEGER_HEX_8b {$$ = $1;} ;\n";
        out << "constant_integer_16b : constant_integer_8b | CONSTANT_INTEGER_DEC_16b {$$ = $1;} | CONSTANT_INTEGER_HEX_16b {$$ = $1;} ;\n";

        rules_instructions(out);

        rules_expressions(out);

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
    void Parser::rules_expressions(std::ostream& out) const
    {
        out << "\n\n//6.3.1\n";
        out << "primary_expression :\n";
            out << "\tIDENTIFIER\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tconstant_integer\n";
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
                out << "\t\tauto expre = tray->block.create<AI_here::nodes::Parenthesis>();\n";
                out << "\t\texpre->set($2);\n";
                out << "\t\t$$ = expre;\n";
            out << "\t}\n";
            if(is_disnastic_A())
            {
                out << "\t|\n";
                out << "\tregisters\n";
                out << "\t{\n";
                out << "\t\tauto reg = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\treg->token = $1;\n";
                out << "\t\treg->type = AI_here::nodes::Node::Type::registers;\n";
                out << "\t\t$$ = reg;\n";
                out << "\t}\n";
                out << "\t|\n";
                out << "\tsegments\n";
                out << "\t{\n";
                out << "\t\tauto seg = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tseg->token = $1;\n";
                out << "\t\tseg->type = AI_here::nodes::Node::Type::segment;\n";
                out << "\t\t$$ = seg;\n";
                out << "\t}\n";
            }
            out << "\t;\n\n";

        out << "postfix_expression :\n";
            out << "\tprimary_expression\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tpostfix_expression '[' primary_expression ']' \n";
            out << "\t{\n";
                out << "\t\tauto posfexpr = tray->block.create<AI_here::nodes::Branch>();\n";
                out << "\t\tauto bs = posfexpr->create(2,tray->block);\n";
                out << "\t\tbs[0] = $1;\n";
                out << "\t\tbs[2] = $3;\n";
                out << "\t\t$$ = posfexpr;\n";
            out << "\t}\n";

            out << "\t;\n\n";


        out << "unary_expression :\n";
            out << "\tpostfix_expression\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t\"++\" unary_expression\n";
            out << "\t{\n";
                out << "\t\tauto unexpr = tray->block.create<AI_here::nodes::Unary>();\n";
                out << "\t\tunexpr->set($2);\n";
                out << "\t\t$$ = unexpr;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t\"--\" unary_expression\n";
            out << "\t{\n";
                out << "\t\tauto unexpr = tray->block.create<AI_here::nodes::Unary>();\n";
                out << "\t\tunexpr->set($2);\n";
                out << "\t\t$$ = unexpr;\n";
            out << "\t}\n";
            out << "\t;\n\n";

        out << "cast_expression :\n";
            out << "\tunary_expression\n";
            out << "\t{\n";
                out << "\t\tauto unexpr = tray->block.create<AI_here::nodes::Unary>();\n";
                out << "\t\tunexpr->set($1);\n";
                out << "\t\t$$ = unexpr;\n";
            out << "\t}\n";
            out << "\t;\n\n";

        out << "multiplicative_expression :\n";
            out << "\tcast_expression\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tmultiplicative_expression '*' cast_expression\n";
            out << "\t{\n";
                out << "\t\tauto mult = tray->block.create<AI_here::nodes::Multiplication>();\n";
                out << "\t\tmult->set($1,$3,tray->block,AI_here::nodes::Expression::Operator::mult);\n";
                out << "\t\t$$ = mult;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tmultiplicative_expression '/' cast_expression\n";
            out << "\t{\n";
                out << "\t\tauto mult = tray->block.create<AI_here::nodes::Multiplication>();\n";
                out << "\t\tmult->set($1,$3,tray->block,AI_here::nodes::Expression::Operator::div);\n";
                out << "\t\t$$ = mult;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tmultiplicative_expression '%' cast_expression\n";
            out << "\t{\n";
                out << "\t\tauto mult = tray->block.create<AI_here::nodes::Multiplication>();\n";
                out << "\t\tmult->set($1,$3,tray->block,AI_here::nodes::Expression::Operator::mod);\n";
                out << "\t\t$$ = mult;\n";
            out << "\t}\n";
            out << "\t;\n\n";

        out << "additive_expression :\n";
            out << "\tmultiplicative_expression\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tadditive_expression '+' multiplicative_expression\n";
            out << "\t{\n";
                out << "\t\tauto add = tray->block.create<AI_here::nodes::Suma>();\n";
                out << "\t\tadd->set($1,$3,tray->block,AI_here::nodes::Expression::Operator::suma);\n";
                out << "\t\t$$ = add;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tadditive_expression '-' multiplicative_expression\n";
            out << "\t{\n";
                out << "\t\tauto add = tray->block.create<AI_here::nodes::Suma>();\n";
                out << "\t\tadd->set($1,$3,tray->block,AI_here::nodes::Expression::Operator::rest);\n";
                out << "\t\t$$ = add;\n";
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
            out << "\t|\n";
            out << "\tSP\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::SP;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBP\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::BP;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSI\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::SI;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDI\n";
            out << "\t{\n";
                out << "\t\t$$ = AI_here::Tokens::DI;\n";
            out << "\t}\n";
            out << "\t;\n\n";

    out << "registers :\n";
            out << "\tregisters_16b\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tregisters_8b\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n\n";

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
            {//1) register/memory to/from register
            out << "\tMOV registers_8b ',' registers_8b ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' registers_16b ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* source = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tsource->token = $4;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 8;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::register_register;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_16b ',' registers_16b ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' registers_16b ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* source = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tsource->token = $4;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 16;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::register_register;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_16b ',' '[' additive_expression ']' ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' '[' memory ']' ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tAI_here::nodes::Memory* source = tray->block.create<AI_here::nodes::Memory>();\n";
                out << "\t\tsource->set((AI_here::nodes::Suma*)$5);\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 16;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::register_memory;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_8b ',' '[' additive_expression ']' ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' '[' memory ']' ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tAI_here::nodes::Memory* source = tray->block.create<AI_here::nodes::Memory>();\n";
                out << "\t\tsource->set((AI_here::nodes::Suma*)$5);\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 8;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::register_memory;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV '[' additive_expression ']' ',' registers_16b ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' '[' memory ']' ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Memory* destine = tray->block.create<AI_here::nodes::Memory>();\n";
                out << "\t\tdestine->set((AI_here::nodes::Suma*)$3);\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* source = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tsource->token = $6;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 16;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::memory_register;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            }
            {//2) inmediate to resgister/memory
            out << "\t|\n";
            out << "\tMOV '[' additive_expression ']' ',' constant_integer_16b ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' '[' memory ']' ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Memory* destine = tray->block.create<AI_here::nodes::Memory>();\n";
                out << "\t\tdestine->set((AI_here::nodes::Suma*)$3);\n";
                //out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* source = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                //out << "\t\tsource->token = $6;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = $6;\n";
                out << "\t\tmv->word_size = 16;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::memory_integer;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV '[' additive_expression ']' ',' CONSTANT_CHAR ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' '[' memory ']' ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Memory* destine = tray->block.create<AI_here::nodes::Memory>();\n";
                out << "\t\tdestine->set((AI_here::nodes::Suma*)$3);\n";
                //out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* source = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                //out << "\t\tsource->token = $6;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = $6;\n";
                out << "\t\tmv->word_size = 8;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::memory_char;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            }
            {//inmediate to registerout << "\t|\n";
            out << "\t|\n";
            out << "\tMOV registers_8b ',' constant_integer_8b ';'\n";
            out << "\t{\n";
                out << "\t\tif($4->get_data_size() > 8) yyerror(&yylloc,scanner,tray,\"MOV registers_8b .. requiere que el valor de la fuente se de 8-btis\");\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = $4;\n";
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
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = $4;\n";
                out << "\t\tmv->word_size = 8;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::regiter_char;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers_16b ',' constant_integer_16b ';'\n";
            out << "\t{\n";
                out << "\t\tstd::string err = \"MOV registers_16b .. requiere que el valor de la fuente se de 16-btis pero es de \" + std::to_string($4->get_data_size());\n";
                out << "\t\tif($4->get_data_size() > 16) yyerror(&yylloc,scanner,tray,err.c_str());\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = $4;\n";
                out << "\t\tmv->word_size = 16;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::regiter_integer;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            }
            {//memory to acumulator

            }
            {//acumulator to memory
            }
            {//register/memory to segment
            out << "\t|\n";
            out << "\tMOV segments ',' registers_16b ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' registers_16b ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* source = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tsource->token = $4;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 16;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::segment_register;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV segments ',' '[' additive_expression ']' ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' registers_16b ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tAI_here::nodes::Memory* source = tray->block.create<AI_here::nodes::Memory>();\n";
                //out << "\t\tsource = $5;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 16;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::segment_memory;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            }
            {//segment to register/memory
            out << "\t|\n";
            out << "\tMOV registers_16b ',' segments ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' registers_16b ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* destine = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tdestine->token = $2;\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* source = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tsource->token = $4;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 16;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::register_segment;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV '[' additive_expression ']' ',' segments ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"MOV segments ',' registers_16b ';'\\n\";\n";
                out << "\t\tAI_here::nodes::intel::i8086::Move* mv = tray->block.create<AI_here::nodes::intel::i8086::Move>();\n";
                out << "\t\tAI_here::nodes::Memory* destine = tray->block.create<AI_here::nodes::Memory>();\n";
                //out << "\t\tdestine = $3;\n";
                out << "\t\tAI_here::nodes::Token<AI_here::Tokens>* source = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\tsource->token = $6;\n";
                out << "\t\tmv->destine = destine;\n";
                out << "\t\tmv->source = source;\n";
                out << "\t\tmv->word_size = 16;\n";
                out << "\t\tmv->inst = AI_here::Tokens::MOV;\n";
                out << "\t\tmv->op_type = AI_here::nodes::Move::operands_type::memory_segment;\n";
                out << "\t\tmv->is_instruction = true;\n";
                out << "\t\t$$ = mv;\n";
            out << "\t}\n";
            }
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
            out << "\tINT constant_integer_16b ';'\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"int \" << $2->get_value() << \"\\n\";\n";
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
            out << "\tRETURN constant_integer_16b ';'\n";
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
            out << "\t|\n";
            out << "\tpointer direct_declarator\n";
            out << "\t{\n";
                //std::cout << "declarator : direct_declarator\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::declarator>();\n";
                out << "\t\t$$->point = $1;\n";
                out << "\t\t$$->direct = $2;\n";
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
            out << "\t}\n";
            */
            out << "\t|\n";
            out << "\tdirect_declarator '('  ')'\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\t$$->identifier_list = NULL;\n";
            out << "\t}\n";
            out << "\t;\n\n";


        out << "type_qualifier: \n";
            out << "\tCONST\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::CONST;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tVOLATIL\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::VOLATIL;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "type_qualifiers: \n";
            out << "\ttype_qualifier\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_qualifiers type_qualifier\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tif(not type_qualifier) type_qualifier = $1;\n";
                out << "\t\t$$->next = $2;\n";
                out << "\t\ttype_qualifier = $2;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "pointer: \n";
            out << "\t'*'\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::pointer>();\n";
                out << "\t\t$$->list = NULL;\n";
                out << "\t\t$$->next = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t'*' type_qualifiers\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::pointer>();\n";
                out << "\t\t$$->list = $2;\n";
                out << "\t\t$$->next = NULL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t'*' pointer\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::pointer>();\n";
                out << "\t\t$$->list = NULL;\n";
                out << "\t\t$$->next = $2;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t'*' type_qualifiers pointer\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::pointer>();\n";
                out << "\t\t$$->list = $2;\n";
                out << "\t\t$$->next = $3;\n";
            out << "\t}\n";
            out << "\t;\n";

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
                out << "\t\ttray->symbols->add($$);\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "declaration_specifiers :\n";
            out << "\ttype_specifier\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"specifier\\n\";\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_qualifier\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"qualifier\\n\";\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_specifier declaration_specifiers\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"specifier\\n\";\n";
                out << "\t\t$$ = $2;\n";
                out << "\t\tif(not declaration_specifiers) declaration_specifiers = $2;\n";
                out << "\t\tdeclaration_specifiers->next = $1;\n";
                out << "\t\tdeclaration_specifiers = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_qualifier declaration_specifiers\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"qualifier\\n\";\n";
                out << "\t\t$$ = $2;\n";
                out << "\t\tif(not declaration_specifiers) declaration_specifiers = $2;\n";
                out << "\t\tdeclaration_specifiers->next = $1;\n";
                out << "\t\tdeclaration_specifiers = $1;\n";
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
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::VOID;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCHAR\n";
            out << "\t{\n";
                //std::cout << "type_specifier : CHAR\n";
                //std::cout << "char ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::CHAR;\n";
                //$$->next = NULL;
                //std::cout << "type_specifier\n";
            out << "\t}\n";
            /*if(is_disnastic_A())
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
            }*/
            out << "\t|\n";
            out << "\tSHORT\n";
            out << "\t{\n";
                //std::cout << "type_specifier : SHORT\n";
                //std::cout << "short ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::SHORT;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tINT\n";
            out << "\t{\n";
                //std::cout << "type_specifier : INT\n";
                //std::cout << "int ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::INT;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tLONG\n";
            out << "\t{\n";
                //std::cout << "type_specifier : INT\n";
                //std::cout << "int ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::LONG;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tFLOAT\n";
            out << "\t{\n";
                //std::cout << "type_specifier : FLOAT\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::FLOAT;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDOUBLE\n";
            out << "\t{\n";
                //std::cout << "type_specifier : DOUBLE\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::DOUBLE;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSIGNED\n";
            out << "\t{\n";
                //std::cout << "type_specifier : SIGNED\n";
                //std::cout << "signed ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::SIGNED;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tUNSIGNED\n";
            out << "\t{\n";
                //std::cout << "type_specifier : UNSIGNED\n";
                //std::cout << "unsigned ";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::Token<AI_here::Tokens>>();\n";
                out << "\t\t$$->token = AI_here::Tokens::UNSIGNED;\n";
            out << "\t}\n";
            out << "\t;\n";

        //6.5.4
        rules_declarator(out);

        //6.5.7
        out << "initializer : \n";
        //esta seccion no es parte del estandar C
        {
            out << "\tconstant_integer\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCONSTANT_CHAR\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
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
            out << "\tIDENTIFIER  '{' instructions_list '}'\n";
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
                out << "\t\ttray->symbols->add($1);\n";
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
                out << "\t\ttray->symbols->add($2);\n";
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
            out << "\t|\n";
            out << "\tfunction_list\n";
            out << "\t{\n";
                out << "\t\t$$ = tray->block.create<AI_here::nodes::translation_unit>();\n";
                out << "\t\t$$->declarations = NULL;\n";
                out << "\t\t$$->functions = $1;\n";
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

