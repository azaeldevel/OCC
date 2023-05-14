
#include "Generator.hh"

namespace oct::cc::v0::tools
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
        out << "SUFFIX_INTEGER ['u''U']?['l''L']?|['l''L']?['u''U']?\n";
        out << "CONSTANT_INTEGER_OCT 0[0-7]+(['u''U']?['l''L']?|['l''L']?['u''U']?)\n";
        if(is_byte_based())
        {
            //out << "CONSTANT_INTEGER_DEC_8b +?[1-9][0-9]?|1[0-9]{2}|2[0-5]{2}|-1[1-9][0-9]?|-12[0-7]\n";
            //out << "CONSTANT_INTEGER_DEC_16b +?25[6-9]|+?[1-9][0-9]{3}|+?[12][0-9]{4}|+?3[12][0-7][0-6][0-7]|-12[89]\n";
            out << "CONSTANT_INTEGER_DEC_8b \t\t";
            {
                out << "[+]";
                out << "(";
                    out << "[1-9]|";
                    out << "[1-9][0-9]|";
                    out << "12[0-8]";
                out << ")";
                out << "|";
                out << "(";
                    out << "[1-9]|";
                    out << "[1-9][0-9]|";
                    out << "1[0-9]{2}|";
                    out << "2[0-4][0-9]";
                    out << "25[0-5]";
                out << ")";
                out << "|";
                out << "[-](";
                    out << "[1-9]|";
                    out << "[1-9][0-9]|";
                    out << "12[0-7]";
                out << ")";

                out << "\n";
            }
            out << "CONSTANT_INTEGER_DEC_16b \t\t";
            {
                out << "[+]";
                out << "(";
                    out << "25[6-9]|";
                    out << "260|";
                    out << "2[6-9][0-9]|";
                    out << "3[0-9]{2}|";
                    out << "[4-9][0-9]{2}|";
                    out << "[1-3][0-9]{3,4}|";
                    out << "31[0-9]{3}|";
                    out << "327[0-9]{2}|";
                    out << "3276[0-7]";
                out << ")";
                out << "|";
                out << "(";
                    out << "25[6-9]|";
                    out << "260|";
                    out << "2[6-9][0-9]|";
                    out << "3[0-9]{2}|";
                    out << "[4-9][0-9]{2}|";
                    out << "[1-5][0-9]{3,4}|";
                    out << "6[0-4][0-9]{3}|";
                    out << "65[0-4][0-9]{2}|";
                    out << "655[0-3][0-5]";
                out << ")";
                out << "|";
                out << "[-](";
                    out << "129|";
                    out << "1[3-9][0-9]|";
                    out << "[2-9][0-9]{2}|";
                    out << "[1-9][0-9]{3}|";
                    out << "[1-2][0-9]{4}|";
                    out << "3[01][0-9]{3}|";
                    out << "32[0-6][0-9]{2}|";
                    out << "327[0-5][0-9]";
                    out << "3276[0-7]";
                out << ")";

                out << "\n";
            }
            /*out << "CONSTANT_INTEGER_DEC_32b \t\t";
            {

                out << "\n";
            }*/
        }
        else
        {
            out << "CONSTANT_INTEGER_DEC [+-]?([1-9][[:digit:]]*|0)(['u''U']?['l''L']?|['l''L']?['u''U']?)\n";
        }
        out << "CONSTANT_INTEGER_HEX 0x[[:xdigit:]]+(['u''U']?['l''L']?|['l''L']?['u''U']?)\n";
        out << "CONSTANT_CHAR '.'\n";
        //out << "LITERAL_STRING \\\"(\\\\.|[^\"\\\\])*\\\"\n";

        out << "IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*\n";


        //out << "%x LITERAL_STRING\n";
    }

}

