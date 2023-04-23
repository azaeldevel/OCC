
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Parser::functions(std::ostream& out) const
    {
        out << "void AI_here::parser::error (const location_type& l, const std::string& m)\n";
        out << "{\n";
            out << "std::cerr << l << \": \" << m << '\\n';\n";
        out << "}\n";
    }
}

