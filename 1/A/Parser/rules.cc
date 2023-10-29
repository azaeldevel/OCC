
#include "Generator.hh"

namespace oct::cc::v1::A
{
    void Parser::rules(std::ostream& out) const
    {
        out << "Unit :\n";
            out << "\tdeclarations\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t|\n";
            out << "\tfunctions\n";
            out << "\t{\n";
            out << "\t}\n";
            out << "\t;\n";


        out << "declarations :\n";
            out << "\t;\n";

        out << "functions :\n";
            out << "\t;\n";
    }
}

