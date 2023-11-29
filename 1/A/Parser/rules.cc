
#include "Generator.hh"

namespace oct::cc::v1::A
{
    void Parser::rules(std::ostream& out) const
    {
        out << "unit : functions\n";
            out << "\t{\n";
                out << "\t\t$$ = new occ::A::I::Unit;\n";
                out << "\t\t$$->resize(2);\n";
                out << "\t\t$$->at(1) = $1;;\n";
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

        out << "function : IDENTIFIER '{' '}'\n";
            out << "\t{\n";
                out << "\t\t$$ = new occ::A::Function;\n";
                out << "\t\t$$->identifier = $1;\n";
                //out << "\t\tstd::cout << \"Identifier funtion: \" << $1->string << \"\\n\";\n";
            out << "\t}\n";
            out << "\t;\n";
    }
}

