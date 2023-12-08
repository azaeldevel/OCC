
#include "Generator.hh"

namespace oct::cc::v1::A::I
{
    void Parser::rules_instructions(std::ostream& out) const
    {

        out << "move : \n";
            //1,4,5).-
            out << "\t" << instruction_string(Tokens::MOV) << " regiters ',' regiters ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\t" << instruction_string(Tokens::MOV) << " memory ',' regiters ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\t" << instruction_string(Tokens::MOV) << " regiters ',' memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            //2,3).-
            out << "\t" << instruction_string(Tokens::MOV) << " regiters ',' LETTER ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\t" << instruction_string(Tokens::MOV) << " regiters ',' integer ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\t" << instruction_string(Tokens::MOV) << " memory ',' CHAR ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\t" << instruction_string(Tokens::MOV) << " memory ',' integer ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            //6).-
            out << "\t" << instruction_string(Tokens::MOV) << " segments ',' regiters ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\t" << instruction_string(Tokens::MOV) << " segments ',' memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            //7).-
            out << "\t" << instruction_string(Tokens::MOV) << " regiters ',' segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\t" << instruction_string(Tokens::MOV) << " memory ',' segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(occ::Types::move,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t;\n";

        out << "ret : \n";
            out << "\t" << instruction_string(Tokens::RET) << " ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Return(occ::Types::ret,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\t" << instruction_string(Tokens::IRET) << " ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Return(occ::Types::ret,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t;\n";

        out << "interrupt : \n";
            out << "\t" << instruction_string(Tokens::INT) << " integer ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Interrupt(occ::Types::interrupt,2);\n";//2 bit: l6bits
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
            out << "\t|\n";
            out << "\tinterrupt\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
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

    }
}

