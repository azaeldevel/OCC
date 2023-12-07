
#include "Generator.hh"

namespace oct::cc::v1::A::I
{
        Lexer::Lexer(Language l) : Generator(l)
        {
        }
        void Lexer::save(std::ostream& out) const
        {
            declaration(out);
            out << "\n%%\n";
            rules(out);
            out << "\n%%\n";
            functions(out);
        }

}

