
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Lexer::declaration(std::ostream& out) const
    {


        out << "%{\n";
            out << "\t#include <" << header_file() << ">\n";
            out << "\t#include <" << language(true) << "-Scanner.hh>\n";
            out << "\t#include <" << language(true) << "/oas-intel-parser.hh>\n";

            out << "\tnamespace " << space() << "_here = oct::cc::v0::" << space() << ";\n";
            out << "\tnamespace core_here = oct::core::v3;\n";

            out << "\t#undef  YY_DECL\n";
            out << "\t#define YY_DECL int " << space() << "_here::Scanner::yylex( parser::semantic_type * const lval, parser::location_type *loc)\n";

            out << "\t/* typedef to make the returns for the tokens shorter */\n";
            out << "\tusing token = " << space() << "_here::parser::token;\n";

            out << "\t/* define yyterminate as this instead of NULL */\n";
            out << "\t//#define yyterminate() return( token::END )\n";

            out << "\t/* msvc2010 requires that we exclude this header file. */\n";
            out << "\t#define YY_NO_UNISTD_H\n";

            out << "\t/* update location on matching */\n";
            out << "\t#define YY_USER_ACTION loc->step(); loc->columns(yyleng);\n";
        out << "%}\n";

        out << "%option debug\n";
        out << "%option nodefault\n";
        out << "%option yyclass=\"oct::cc::v0::" << space() << "::Scanner\"\n";
        out << "%option noyywrap\n";
        out << "%option c++\n";

        out << "CHAR [[:alpha:][:digit:][:punct:][:graph:][:blank:]]\n";
        out << "CONSTANT_INTEGER_DEC [+-]?[[:digit:]]+\n";
        out << "CONSTANT_INTEGER_HEX 0x[[:xdigit:]]+\n";
        out << "CONSTANT_CHAR '{CHAR}'\n";

        out << "IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*\n";
    }

}

