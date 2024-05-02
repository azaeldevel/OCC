
#include "Generator.hh"

namespace oct::cc::v1::A::I
{
    void Parser::rules(std::ostream& out) const
    {
        rules_occ(out);
        rules_C_expression(out);
        rules_C_declaration(out);
        rules_A(out);
        rules_AI(out);
    }

    void Parser::rules_registers(std::ostream& out) const
    {
        out << "registers_8b : \n";
            out << "\tAL\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tAH\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBL\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBH\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCL\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCH\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDL\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDH\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "registers_16b : \n";
            out << "\tAX\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBX\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCX\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDX\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "registers : \n";
            out << "\tregisters_8b\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tregisters_16b\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";

    }

    void Parser::rules_types(std::ostream& out) const
    {
        out << "integer : \n";
            out << "\tINTEGER_DECIMAL\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tINTEGER_HEXDECIMAL\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";
    }

    /*void Parser::rules_memory(std::ostream& out) const
    {
        out << "memory : \n";
            out << "\tinteger\n";
            out << "\t{\n";
            out << "\t\t$$ = memories.next();\n";
            out << "\t\t$$->set(*$1,occ::A::Memory::inmediate);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBX '+' SI \n";
            out << "\t{\n";
            out << "\t\t$$ = memories.next();\n";
            out << "\t\t$1->next = $3;\n";
            out << "\t\t$$->set(*$1,occ::A::Memory::implied);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBX '+' SI \n";
            out << "\t{\n";
            out << "\t\t$$ = memories.next();\n";
            out << "\t\t$1->next = $3;\n";
            out << "\t\t$$->set(*$1,occ::A::Memory::implied);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBP '+' SI \n";
            out << "\t{\n";
            out << "\t\t$$ = memories.next();\n";
            out << "\t\t$1->next = $3;\n";
            out << "\t\t$$->set(*$1,occ::A::Memory::implied);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBP '+' DI \n";
            out << "\t{\n";
            out << "\t\t$$ = memories.next();\n";
            out << "\t\t$1->next = $3;\n";
            out << "\t\t$$->set(*$1,occ::A::Memory::implied);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSI \n";
            out << "\t{\n";
            out << "\t\t$$ = memories.next();\n";
            out << "\t\t$$->set(*$1,occ::A::Memory::inmediate);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDI \n";
            out << "\t{\n";
            out << "\t\t$$ = memories.next();\n";
            out << "\t\t$$->set(*$1,occ::A::Memory::inmediate);\n";
            out << "\t}\n";
            out << "\t;\n";
    }*/

    void Parser::rules_memory(std::ostream& out) const
    {
        //additional Register-Memory Field Encoding
        out << "AREMFEN : \n";
            out << "\tBX '+' SI \n";
            out << "\t{\n";
            out << "\t\t$1->next = $3;\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBX '+' SI \n";
            out << "\t{\n";
            out << "\t\t$1->next = $3;\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBP '+' SI \n";
            out << "\t{\n";
            out << "\t\t$1->next = $3;\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBP '+' DI \n";
            out << "\t{\n";
            out << "\t\t$1->next = $3;\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "memory : \n";
            out << "\tAREMFEN\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tAREMFEN '+' integer\n";
            out << "\t{\n";
            out << "\t\t$1->next->next = $3;\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinteger\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";

    }

    void Parser::rules_segments(std::ostream& out) const
    {
        out << "segments : \n";
            out << "\tCS\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDS\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tES\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tFS\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tGS\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSS\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";
    }

    void Parser::rules_functions(std::ostream& out) const
    {
        out << "function : \n";
            out << "\tIDENTIFIER '{' instructions '}'\n";
            out << "\t{\n";
                out << "\t\t$$ = new occ::A::Function(occ::Statemants::function);\n";
                out << "\t\t$$->identifier = $1;\n";
                out << "\t\t$$->insts = $3;\n";
                //out << "\t\tstd::cout << \"Identifier funtion: \" << $1->string << \"\\n\";\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tIDENTIFIER '{' '}'\n";
            out << "\t{\n";
                out << "\t\t$$ = new occ::A::Function(occ::Statemants::function);\n";
                out << "\t\t$$->identifier = $1;\n";
                out << "\t\t$$->insts = NULL;\n";
                //out << "\t\tstd::cout << \"Identifier funtion: \" << $1->string << \"\\n\";\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "statement : \n";
            out << "\tfunction\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclaration\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "statements : \n";
            out << "\tstatement\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tstatement_last = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tstatements statement\n";
            out << "\t{\n";
                out << "\t\tstatement_last->next = $2;\n";
                out << "\t\tstatement_last = $2;\n";
            out << "\t}\n";
            out << "\t;\n";
    }

    void Parser::rules_unit(std::ostream& out) const
    {
        out << "unit : statements\n";
            out << "\t{\n";
                out << "\t\ttray->unit = new occ::A::I::Unit(occ::Statemants::unit);\n";
                out << "\t\ttray->unit->statement = $1;\n";
                out << "\t\t$$ = tray->unit;\n";
            out << "\t}\n";
            out << "\t;\n";
    }

    const char* Parser::instruction_string(Tokens t) const
    {
        switch(t)
        {
        case Tokens::MOV:
            return "\"mov\"";
        case Tokens::RET:
            return "\"ret\"";
        case Tokens::IRET:
            return "\"iret\"";
        case Tokens::INT:
            return "\"int\"";
        default:
            break;
        }
        return NULL;
    }

    void Parser::rules_identifier(std::ostream& out) const
    {//las intruccin no son keywords
        out << "softword : \n";
            out << "\tMOV\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tRET\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tIRET\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "identifier : \n";
            out << "\tIDENTIFIER\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tsoftword\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";
    }


    void Parser::rules_occ(std::ostream& out) const
    {
        rules_types(out);
        rules_identifier(out);
    }
    void Parser::rules_A(std::ostream& out) const
    {
        rules_registers(out);
        rules_memory(out);
        rules_segments(out);
        rules_instructions(out);
    }
    void Parser::rules_AI(std::ostream& out) const
    {
        rules_functions(out);
        rules_unit(out);
    }

    void Parser::rules_C_expression(std::ostream& out) const
    {
        out << "assignment_expresion :\n";
            out << "\tinteger\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t;\n";
    }
    void Parser::rules_C_declaration(std::ostream& out) const
    {
        out << "declaration :\n";
            out << "\tdeclaration_specifiers ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = declarations.next(*$1);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclaration_specifiers init_declarator_list ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = declarations.next(*$1,*$2);\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "declaration_specifiers :\n";
            out << "\tstorage_class_specifier\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tspecifiers_last = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tstorage_class_specifier declaration_specifiers\n";
            out << "\t{\n";
                out << "\t\tspecifiers_last->next = $2;\n";
                out << "\t\tspecifiers_last = $2;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_specifier\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tspecifiers_last = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_specifier declaration_specifiers\n";
            out << "\t{\n";
                out << "\t\tspecifiers_last->next = $2;\n";
                out << "\t\tspecifiers_last = $2;\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_qualifier\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tspecifiers_last = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_qualifier declaration_specifiers\n";
            out << "\t{\n";
                out << "\t\tspecifiers_last->next = $2;\n";
                out << "\t\tspecifiers_last = $2;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "init_declarator_list :\n";
            out << "\tinit_declarator\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinit_declarator_list, init_declarator\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "init_declarator :\n";
            out << "\tdeclarator\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdeclarator '=' initializer\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "storage_class_specifier :\n";
            out << "\tTYPEDEF\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tEXTERN\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSTATIC\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tAUTO\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tREGISTER\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";



        out << "type_specifier :\n";
            out << "\tVOID\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCHAR\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSHORT\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tINT\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tLONG\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tFLOAT\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDOUBLE\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSIGNED\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tUNSIGNED\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            {//TODO: Agrgar desde 6.5.2.1 hasta 6.5.2.2
                ;
            }
            out << "\t;\n";

        out << "type_qualifier :\n";
            out << "\tCONST\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\t$1->print(std::cout);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tVOLATIL\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "declarator :\n";
            out << "\tpointer direct_declarator\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tdirect_declarator\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "direct_declarator :\n";
            out << "\tidentifier\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Direct_Declarator(*$1);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t'(' declarator ')'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Direct_Declarator(*$2);\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "pointer :\n";
            out << "\t'*'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::Node(occ::Statemants::pointer);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t'*' type_qualifier_list\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::Node(occ::Statemants::pointer);\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "type_qualifier_list :\n";
            out << "\ttype_qualifier\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_qualifier_list type_qualifier\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "initializer :\n";
            out << "\tassignment_expresion\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\'{' initializer_list '}'\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "initializer_list :\n";
            out << "\tinitializer\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinitializer_list initializer\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t;\n";

    }


}

