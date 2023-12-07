
#include "Generator.hh"

namespace oct::cc::v1::A::I
{
        Parser::Parser(Language l) : Generator(l)
        {
        }
        void Parser::save(std::ostream& out) const
        {
            declaration(out);
            out << "\n%%\n";
            rules(out);
            out << "\n%%\n";
            functions(out);
        }

}

