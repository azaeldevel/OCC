
#include "Generator.hh"

namespace oct::cc::v1::A
{
    void Parser::rules(std::ostream& out) const
    {
        out << "unit : functions\n";
            out << "\t{\n";
                out << "\t\ttray->unit = new occ::A::I::Unit(occ::Types::unit);\n";
                out << "\t\ttray->unit->at(1) = $1;\n";
                out << "\t\t$$ = tray->unit;\n";
            out << "\t}\n";
            out << "\t;\n";


        //out << "declarations :\n";
            //out << "\t;\n";

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

        out << "function : IDENTIFIER  RET ';'\n";
            out << "\t{\n";
                out << "\t\t$$ = new occ::A::Function(occ::Types::function);\n";
                out << "\t\t$$->identifier = $1;\n";
                //out << "\t\tstd::cout << \"Identifier funtion: \" << $1->string << \"\\n\";\n";
            out << "\t}\n";
            out << "\t;\n";
    }
}

