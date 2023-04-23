
#include "Generator.hh"

namespace oct::cc::v0::tools
{

    Parser::Parser(Language l) : lang(l)
    {

    }

    void Parser::declaration(std::ostream& out) const
    {
        out << "%skeleton \"lalr1.cc\"\n";
        out << "%skeleton \%require  \"3.8\"\n";
        out << "%skeleton \%defines\n";
        out << "%skeleton \%define api.namespace {oct::cc::v0::" << space() << "}\n";
        out << "%skeleton \%define api.parser.class {parser}\n";
        out << "\n";

        out << "%skeleton \%define parse.trace\n";
        out << "%skeleton \%define parse.error detailed\n";
        out << "%skeleton \%define parse.lac full\n";
        out << "\n";

        declaration_code_required(out);
    }
    void Parser::declaration_code_required(std::ostream& out) const
    {

        out << "%code requires\n";
        out << "{\n";
            out << "\t#include <" << header_file() << ">\n";
            out << "\t#include <" << language(true) << "-Driver.hh>\n";
            out << "\t#include <core/3/Exception.hh>\n";
            out << "\tnamespace AI_here = oct::cc::v0::AI;\n";
            out << "\tnamespace core_here = oct::core::v3;\n";

            out << "\tnamespace oct::cc::v0::AI\n";
            out << "\t{\n";
                out << "\t\tclass Scanner;\n";
                out << "\t\tclass Driver;\n";
            out << "\t}\n";

            out << "\t# ifndef YY_NULLPTR\n";
            out << "\t#  if defined __cplusplus && 201103L <= __cplusplus\n";
            out << "\t#   define YY_NULLPTR nullptr\n";
            out << "\t#  else\n";
            out << "\t#   define YY_NULLPTR 0\n";
            out << "\t#  endif\n";
            out << "\t# endif\n";
        out << "}\n";

    }
    void Parser::rules(std::ostream& out) const
    {

    }
    void Parser::functions(std::ostream& out) const
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
            else if(ornament) return "AI";
        case Language::AII:
            if(ornament) return "A+";
            else if(ornament) return "AII";
        default:
            ;
        }

        return "?";
    }
}

