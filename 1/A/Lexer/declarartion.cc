
#include "Generator.hh"

namespace oct::cc::v1::A
{
    void Lexer::declaration(std::ostream& out) const
    {

        out << "%option noyywrap nounput reentrant bison-bridge yylineno\n";
        //out << "%option prefix = \"" << prefix() << "\"\n";

        out << "%{\n";
            out << "\t#include <assert.h>\n";
            out << "\t#include <limits.h>\n";
            out << "\t#include <stdlib.h>\n";
            out << "\t#include <stdio.h>\n";
            out << "\t#include <string.h>\n";
            out << "\t#include \"oas-intel-parser.hh\"\n";


            // Each time a rule is matched, advance the end cursor/position.
            out << "\t#define YY_USER_ACTION  yylloc->last_column += (int) yyleng;\n";
            out << "\t#define LOCATION_STEP() do {yylloc->first_line = yylloc->last_line;yylloc->first_column = yylloc->last_column;} while (0)\n";

        out << "%}\n";
        out << "IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*\n";

    }

}

