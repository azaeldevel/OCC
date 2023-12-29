
#include "Generator.hh"

namespace oct::cc::v1::A::I
{
    void Parser::rules_instructions(std::ostream& out) const
    {
        out << "move : \n";
            //1,4,5).-
            out << "\tMOV regiters ',' regiters ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(4,$2,$4,occ::A::Move::Form::register_to_register);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' regiters ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(4,$2,$4,occ::A::Move::Form::register_to_memory);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV regiters ',' memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(4,$2,$4,occ::A::Move::Form::memory_to_register);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV identifier ',' regiters ';'\n";//identifier is a pointer/inmendiate
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(4,$2,$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV regiters ',' identifier ';'\n";//identifier is a pointer/inmendiate
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(4,$2,$4);\n";
            out << "\t}\n";
            //2,3).-
            out << "\t|\n";
            out << "\tMOV regiters ',' LETTER ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(3,$2,$4,occ::A::Move::Form::inmediate_to_register);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV regiters ',' integer ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(3,$2,$4,occ::A::Move::Form::inmediate_to_register);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' integer ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(3,$2,$4,occ::A::Move::Form::inmediate_to_memory);\n";
            out << "\t}\n";
            //6).-
            out << "\t|\n";
            out << "\tMOV segments ',' regiters ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(4,$2,$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV segments ',' memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(4,$2,$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            //7).-
            out << "\tMOV regiters ',' segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(4,$2,$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(4,$2,$4);\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "ret : \n";
            out << "\t" << instruction_string(Tokens::RET) << " ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Return(occ::Statemants::ret,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\t" << instruction_string(Tokens::IRET) << " ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Return(occ::Statemants::ret,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t;\n";

        out << "interrupt : \n";
            out << "\tINT integer ';'\n";
            out << "\t{\n";
            out << "\t\tauto inst  = new occ::A::Interrupt;\n";//2 bit: l6bits
            out << "\t\tinst->make($2);\n";//2 bit: l6bits
            out << "\t\t$$ = inst;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "call : \n";
            out << "\tCALL identifer ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCALL memory ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "push : \n";
            out << "\tPUSH identifer ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPUSH memory ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPUSH registers ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPUSH segments ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "pop : \n";
            out << "\tPOP identifer ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPOP memory ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPOP registers ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPOP segments ';'\n";
            out << "\t{\n";
            out << "\t\t;\n";
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
                out << "\t\tinstruction_last = $1;\n";
                //out << "\t\tstd::cout << \"inst\\n\";\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinstructions inst\n";
            out << "\t{\n";
                //out << "\t\tstd::cout << \"instructions inst\\n\";\n";
                out << "\t\tinstruction_last->next = $2;\n";
                out << "\t\tinstruction_last = $2;\n";
            out << "\t}\n";
            out << "\t;\n";

    }
}

