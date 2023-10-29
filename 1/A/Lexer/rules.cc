
#include "Generator.hh"

namespace oct::cc::v1::A
{
    void Lexer::rules(std::ostream& out) const
    {

        out << "\\n    yylloc->last_line++; yylloc->last_column = 1;\n";
        out << "[ \\t]+   LOCATION_STEP (); continue;\n";

        {
            out << "\"al\"	        return AL;\n";
            out << "\"ah\"	        return AH;\n";
            out << "\"bl\"	        return BL;\n";
            out << "\"bh\"	        return BH;\n";
            out << "\"cl\"	        return CL;\n";
            out << "\"ch\"	        return CH;\n";
            out << "\"dl\"	        return DL;\n";
            out << "\"dh\"	        return DH;\n";
            out << "\"ax\"	        return AX;\n";
            out << "\"bx\"	        return BX;\n";
            out << "\"dx\"	        return DX;\n";
            out << "\"cx\"	        return CX;\n";

            out << "\"es\"	        return ES;\n";
            out << "\"cs\"	        return CS;\n";
            out << "\"ss\"	        return SS;\n";
            out << "\"ds\"	        return DS;\n";

            out << "\"si\"	        return SI;\n";
            out << "\"di\"	        return DI;\n";
            out << "\"bp\"	        return BP;\n";
            out << "\"sp\"	        return SP;\n";

            out << "\"mov\"         return MOV;\n";
            out << "\"ret\"	        return RET;\n";
            out << "\"iret\"	    return IRET;\n";

            //out << "\"byte\"		return BYTE;\n";
            //out << "\"tiny\"		return TINY;\n";
        }

        keywords_c(out);

        out << "\"//\".*		;\n";


        out << "{IDENTIFIER}	{\n";

        out << "\t\t}\n";


        out << "[[:punct:]]	{\n";
            out << "\t\treturn (yytoken_kind_t)yytext[0];\n";
        out << "\t\t}\n";



        out << "<<EOF>>  return ENDOFFILE;\n";


        out << ".       yyerror_unknow_symbol(yylloc,yyscanner,tray,yytext[0]);\n";

    }

}

