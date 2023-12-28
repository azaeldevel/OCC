
#include "Generator.hh"

namespace oct::cc::v1::A::I
{
    void Parser::rules(std::ostream& out) const
    {
        rules_occ(out);
        rules_A(out);
        rules_AI(out);
    }

    void Parser::rules_regiters(std::ostream& out) const
    {
        out << "regiters_8b : \n";
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

        out << "regiters_16b : \n";
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

        out << "regiters : \n";
            out << "\tregiters_8b\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tregiters_16b\n";
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

    void Parser::rules_memory(std::ostream& out) const
    {
        out << "memory : \n";
            out << "\t'[' integer ']'\n";
            out << "\t{\n";
            out << "\t\t$$ = $2;\n";
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

        /*out << "functions : \n";
            out << "\tfunction\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                out << "\t\tfunction_last = $1;\n";
                //out << "\t\tstd::cout << \"Identifier funtion: \" << $1->identifier->string << \"\\n\";\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tfunctions function\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"Identifier funtion: \" << $2->identifier->string << \"\\n\";\n";
                out << "\t\tfunction_last->next = $2;\n";
                out << "\t\tfunction_last = $2;\n";
            out << "\t}\n";
            out << "\t;\n";*/


        out << "type_specifier :\n";
            out << "\tVOID\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCHAR\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSHORT\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tINT\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tLONG\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tFLOAT\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDOUBLE\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSIGNED\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tUNSIGNED\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "variable : \n";
            out << "\ttype_specifier IDENTIFIER\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\ttype_specifier '*' IDENTIFIER\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "statement : \n";
            out << "\tfunction\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tvariable\n";
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
        rules_regiters(out);
        rules_memory(out);
        rules_segments(out);
        rules_instructions(out);
    }
    void Parser::rules_AI(std::ostream& out) const
    {
        rules_functions(out);
        rules_unit(out);
    }


}

