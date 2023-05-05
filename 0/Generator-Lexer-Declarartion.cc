
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Lexer::declaration(std::ostream& out) const
    {

        out << "%option noyywrap nounput reentrant bison-bridge yylineno\n";

        out << "%{\n";
            out << "\t#include <assert.h>\n";
            out << "\t#include <limits.h>\n";
            out << "\t#include <stdlib.h>\n";
            out << "\t#include <stdio.h>\n";
            out << "\t#include <string.h>\n";
            //#include <core/3/math.hh>


            out << "\t#include <" << header_file() << ">\n";
            out << "\tnamespace " << space() << "_here = oct::cc::v0::" << space() << ";\n";
            out << "\tnamespace core_here = oct::core::v3;\n";
            out << "\t//" << space() << "_here::File " << space() << "_here::current_file;\n";

            out << "\t#include \"" << language(true) << "/oas-intel-parser.hh\"\n";

            // Each time a rule is matched, advance the end cursor/position.
            out << "\t#define YY_USER_ACTION  yylloc->last_column += (int) yyleng;\n";
            out << "\t#define LOCATION_STEP() do {yylloc->first_line = yylloc->last_line;yylloc->first_column = yylloc->last_column;} while (0)\n";

        out << "%}\n";

        //out << "CHAR [[:alpha:][:digit:][:punct:][:graph:][:blank:]]\n";
        out << "CONSTANT_INTEGER_OCT 0[0-7]+(['u''U']?['l''L']?|['l''L']?['u''U']?)\n";
        out << "CONSTANT_INTEGER_DEC [+-]?[1-9][[:digit:]]+(['u''U']?['l''L']?|['l''L']?['u''U']?)\n";
        out << "CONSTANT_INTEGER_HEX 0x[[:xdigit:]]+(['u''U']?['l''L']?|['l''L']?['u''U']?)\n";
        out << "CONSTANT_CHAR '.'\n";
        out << "LITERAL_STRING \\\"(\\\\.|[^\"\\\\])*\\\"\n";

        out << "IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*\n";


        //out << "%x LITERAL_STRING\n";
    }

}

