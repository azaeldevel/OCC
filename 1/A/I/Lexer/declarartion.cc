
#include "Generator.hh"

namespace oct::cc::v1::A::I
{
    void Lexer::declaration(std::ostream& out) const
    {

        out << "%option noyywrap nounput reentrant bison-bridge yylineno\n";
        //out << "%option prefix = \"" << prefix() << "\"\n";

        /*out << "%top{\n";
            out << "\t#include \"oas-intel.lexer.hh\"\n";
            out << "\t#include \"oas-intel-parser.hh\"\n";
        out << "%}\n";*/

        out << "%{\n";
            out << "\t#include <assert.h>\n";
            out << "\t#include <limits.h>\n";
            out << "\t#include <stdlib.h>\n";
            out << "\t#include <stdio.h>\n";
            out << "\t#include <string.h>\n";
            //out << "\t#include \"oas-intel.lexer.hh\"\n";
            out << "\t#include \"occ-intel.parser.hh\"\n";


            // Each time a rule is matched, advance the end cursor/position.
            out << "\t#define YY_USER_ACTION  yylloc->last_column += (int) yyleng;\n";
            out << "\t#define LOCATION_STEP() yylloc->first_line = yylloc->last_line;yylloc->first_column = yylloc->last_column;\n";

            out << "\t\tstatic occ::Word yylexroot(\"root\",4);\n";
            out << "\t\tstatic occ::Word* yylexnext = &yylexroot;\n";

            out << "\t\tstatic occ::Block<occ::Letter> letters;\n";
            out << "\t\tstatic occ::Block<occ::Number> numbers;\n";
            out << "\t\tstatic occ::Block<occ::Keyword> keywords;\n";

        out << "%}\n";
        out << "IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*\n";
        out << "LETTER '.'\n";
        /*out << "INTEGER_DECIMAL \t\t";
        {
            out << "0";
            out << "|";
            out << "[+-][0-9]+";
            out << "\n";
        }*/
        out << "INTEGER_DECIMAL_TINY \t\t";
        {
            out << "[+-][0-9]";
            out << "|";
            out << "[+-][0-9][0-9]";
            out << "|";
            out << "[+-]100";
            out << "|";
            out << "[+-]1[0-1][0-9]";
            out << "|";
            out << "[+-]12[0-8]";
            out << "\n";
        }
        out << "INTEGER_DECIMAL_UTINY \t\t";
        {
            out << "[0-9][0-9]";
            out << "|";
            out << "1[0-9][0-9]";
            out << "|";
            out << "2[0-4][0-9]";
            out << "|";
            out << "250";
            out << "|";
            out << "25[0-5]";
            out << "\n";
        }

        //out << "INTEGER_HEXDECIMAL \t\t(0x|0X)[[:xdigit:]]+\n";
        out << "INTEGER_HEXDECIMAL_TINY \t\t(0x|0X)[[:xdigit:]]{1,2}\n";
        out << "INTEGER_HEXDECIMAL_SHORT \t\t(0x|0X)[[:xdigit:]]{3,4}\n";


    }

}

