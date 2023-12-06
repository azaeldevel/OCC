
#include "Generator.hh"

namespace oct::cc::v1::A
{
    void Parser::rules(std::ostream& out) const
    {


        out << "regiters_8b : \n";
            out << "\tAL\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::AL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tAH\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::AH;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBL\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::BL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBH\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::BH;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCL\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::CL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCH\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::CH;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDL\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::DL;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDH\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::DH;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "regiters_16b : \n";
            out << "\tAX\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::AX;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tBX\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::BX;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCX\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::CX;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDX\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::DX;\n";
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

        out << "memory : \n";
            out << "\t'[' integer ']'\n";
            out << "\t{\n";
            out << "\t\t$$ = $2;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "segments : \n";
            out << "\tCS\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::CS;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tDS\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::DS;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tES\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::ES;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tFS\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::FS;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tGS\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::GS;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tSS\n";
            out << "\t{\n";
            out << "\t\t$$ = occ::Tokens::SS;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "move : \n";
            //1,4,5).-
            out << "\tMOV regiters ',' regiters ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' regiters ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV regiters ',' memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            //2,3).-
            out << "\tMOV regiters ',' LETTER ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV regiters ',' integer ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' CHAR ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' integer ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            //6).-
            out << "\tMOV segments ',' regiters ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV segments ',' memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            //7).-
            out << "\tMOV regiters ',' segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t;\n";

        out << "ret : \n";
            out << "\tRET ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Return(occ::Types::ret,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\tIRET ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Return(occ::Types::ret,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t;\n";

        out << "inst : \n";
            out << "\tmove\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tret\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\t';'\n";
            out << "\t{\n";
            out << "\t\t$$ = NULL;\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "instructions : \n";
            out << "\tinst\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\tstd::cout << \"inst\\n\";\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinstructions inst\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"instructions inst\\n\";\n";
                out << "\t\t$1->next = $2;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "function : IDENTIFIER '{' instructions '}'\n";
            out << "\t{\n";
                out << "\t\t$$ = new occ::A::Function(occ::Types::function);\n";
                out << "\t\t$$->identifier = $1;\n";
                out << "\t\t$$->insts = $3;\n";
                //out << "\t\tstd::cout << \"Identifier funtion: \" << $1->string << \"\\n\";\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "functions : \n";
            out << "\tfunction\n";
            out << "\t{\n";
                out << "\t\t$$ = $1;\n";
                //out << "\t\tstd::cout << \"Identifier funtion: \" << $1->identifier->string << \"\\n\";\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tfunctions function\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"Identifier funtion: \" << $2->identifier->string << \"\\n\";\n";
                out << "\t\t$1->next = $2;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "unit : functions\n";
            out << "\t{\n";
                out << "\t\ttray->unit = new occ::A::I::Unit(occ::Types::unit);\n";
                out << "\t\ttray->unit->at(1) = $1;\n";
                out << "\t\t$$ = tray->unit;\n";
            out << "\t}\n";
            out << "\t;\n";

    }
}

