
#include "Generator.hh"

namespace oct::cc::v1::A::I
{
    void Parser::rules_instructions(std::ostream& out) const
    {
        out << "move : \n";
            //1,4,5).-
            out << "\tMOV registers ',' registers ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' registers ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers ',' memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            /*out << "\t|\n";
            out << "\tMOV identifier ',' registers ';'\n";//identifier is a pointer/inmendiate
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(*$2,*$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers ',' identifier ';'\n";//identifier is a pointer/inmendiate
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::Move(*$2,*$4);\n";
            out << "\t}\n";*/
            //2,3).-
            out << "\t|\n";
            out << "\tMOV registers ',' LETTER ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV registers ',' integer ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' integer ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            //6).-
            out << "\t|\n";
            out << "\tMOV segments ',' registers ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV segments ',' memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            //7).-
            out << "\tMOV registers ',' segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tMOV memory ',' segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Move(*$2,*$4);\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "ret : \n";
            out << "\tRET ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Return(occ::Statemants::ret,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t|\n";
            out << "\tIRET ';'\n";
            out << "\t{\n";
            ////out << "\t\t$$ = new occ::A::Return(occ::Statemants::iret,2);\n";//2 bit: l6bits
            out << "\t}\n";
            out << "\t;\n";

        out << "interrupt : \n";
            out << "\tINT integer ';'\n";
            out << "\t{\n";
            out << "\t\tauto inst  = new occ::A::intel::Interrupt(*$2);\n";//2 bit: l6bits
            out << "\t\t$$ = inst;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "call : \n";
            out << "\tCALL identifier ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Call(3,$2);\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tCALL memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Call;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "push : \n";
            out << "\tPUSH identifier ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Push;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPUSH memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Push;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPUSH registers ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Push;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPUSH segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Push;\n";
            out << "\t}\n";
            out << "\t;\n";

        out << "pop : \n";
            out << "\tPOP identifier ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Pop;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPOP memory ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Pop;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPOP registers ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Pop;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tPOP segments ';'\n";
            out << "\t{\n";
            out << "\t\t$$ = new occ::A::intel::Pop;\n";
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
            out << "\t\t$$ = new occ::A::intel::Empty;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tinterrupt\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tcall\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tpush\n";
            out << "\t{\n";
            out << "\t\t$$ = $1;\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tpop\n";
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

