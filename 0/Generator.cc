
#include "Generator.hh"

namespace oct::cc::v0::tools
{

    Generator::Generator(Language l) : lang(l)
    {
    }


    const char* Generator::header_file() const
    {
        switch(lang)
        {
        case Language::AI:
            return "A.hh";
        case Language::AII:
            return "A+.hh";
        default:
            ;
        }

        return "?";
    }
    const char* Generator::header_file(int g) const
    {
        switch(g)
        {
        case 1:
            return "A.hh";
        case 2:
            return "A+.hh";
        default:
            ;
        }

        return "?";
    }
    const char* Generator::space() const
    {
        switch(lang)
        {
        case Language::AI:
            return "AI";
        case Language::AII:
            return "AII";
        default:
            ;
        }

        return "?";
    }
    const char* Generator::space(int g) const
    {
        switch(g)
        {
        case 1:
            return "AI";
        case 2:
            return "AII";
        default:
            ;
        }

        return "?";
    }
    const char* Generator::tree_node() const
    {
        switch(lang)
        {
        case Language::AI:
                return "translation_unit";
            break;
        case Language::AII:
                return "external_declaration";
            break;
        default:
            ;
        }

        return "?";
    }
    const char* Generator::language(bool ornament) const
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

