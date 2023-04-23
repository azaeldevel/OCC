
#include "Generator.hh"

namespace oct::cc::v0::tools
{

    Parser::Parser(Language l) : lang(l)
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


    const char* Parser::header_file() const
    {
        switch(lang)
        {
        case Language::AI:
                return "A.hh";
            break;
        case Language::AII:
                return "A+.hh";
            break;
        default:
            ;
        }

        return "?";
    }
    const char* Parser::space() const
    {
        switch(lang)
        {
        case Language::AI:
                return "AI";
            break;
        case Language::AII:
                return "AII";
            break;
        default:
            ;
        }

        return "?";
    }

    const char* Parser::language(bool ornament) const
    {
        switch(lang)
        {
        case Language::AI:
            if(ornament) return "A";
            else return "AI";
        case Language::AII:
            if(ornament) return "A+";
            else return "AII";
        default:
            ;
        }

        return "?";
    }
}

