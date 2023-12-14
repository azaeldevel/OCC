
#include "Generator.hh"

namespace oct::cc::v1::A::I
{
    void Lexer::rules(std::ostream& out) const
    {

        out << "\"//\".*    {\n";
                                out << "\t\t\tyylexnext->yylexnext = new occ::Word(yytext,yyleng);\n";
                                out << "\t\t\tyylexnext = yylexnext->yylexnext;\n";
        out << "        }\n";
        out << "\\n     {\n";
                                out << "\t\t\tyylloc->last_line++;\n";
                                out << "\t\t\tyylloc->last_column = 1;\n";
                                out << "\t\t\tyylexnext->yylexnext = new occ::Word(yytext,yyleng);\n";
                                out << "\t\t\tyylexnext = yylexnext->yylexnext;\n";
        out << "        }\n";
        out << "\\t             ;\n";
        out << "[[:space:]]     ;\n";


        {
            rules_add_keyword(out,"al","AL");
            rules_add_keyword(out,"ah","AH");
            rules_add_keyword(out,"ax","AX");
            out << "\"bl\"	        return BL;\n";
            out << "\"bh\"	        return BH;\n";
            out << "\"cl\"	        return CL;\n";
            out << "\"ch\"	        return CH;\n";
            out << "\"dl\"	        return DL;\n";
            out << "\"dh\"	        return DH;\n";
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

            rules_add_keyword(out,"mov","MOV");
            rules_add_keyword(out,"ret","RET");
            rules_add_keyword(out,"iret","IRET");

            //out << "\"byte\"		return BYTE;\n";
            //out << "\"tiny\"		return TINY;\n";
        }

        keywords_c(out);

        out << "{IDENTIFIER}\t\t{\n";
                            out << "\t\tyylval->IDENTIFIER = new occ::Identifier(occ::Tokens::IDENTIFIER,yytext,yyleng);\n";
                            //out << "\t\tstd::cout << yytext << \":\" << yyleng ;\n";
                            out << "\t\treturn IDENTIFIER;\n";
        out << "\t\t}\n";

        out << "{INTEGER_DECIMAL}  {\n";
                                    out << "\t\tyylval->INTEGER_DECIMAL = new occ::Number(occ::Tokens::INTEGER,yytext,yyleng);\n";
                                    out << "\t\treturn INTEGER_DECIMAL;\n";
                                out << "\t\t}\n";

        out << "{INTEGER_HEXDECIMAL}  {\n";
                                    out << "\t\tyylval->INTEGER_HEXDECIMAL = new occ::Number(occ::Tokens::INTEGER,yytext,yyleng);\n";
                                    out << "\t\treturn INTEGER_HEXDECIMAL;\n";
                                out << "\t\t}\n";


        out << "{LETTER}  {\n";
                                    out << "\t\tyylval->LETTER = yytext[1];\n";
                                    out << "\t\treturn LETTER;\n";
                                out << "\t\t}\n";

        out << "[[:punct:]]	{\n";
            out << "\t\treturn (yytoken_kind_t)yytext[0];\n";
        out << "\t\t}\n";



        out << "<<EOF>>  return ENDOFFILE;\n";


        out << ".       yyerror_unknow_symbol(yylloc,yyscanner,tray,yytext[0]);\n";

    }

    void Lexer::rules_add_keyword(std::ostream& out,const char* string,const char* token) const
    {
        out << "\"" << string << "\"     {\n";
            out << "\t\tyylexnext->yylexnext = new occ::Word(yytext,yyleng);\n";
            out << "\t\tyylexnext = yylexnext->yylexnext;\n";
            out << "\t\tyylval->" << token << " = yylexnext;\n";
            out << "\t\treturn " << token << ";\n";
        out << "        }\n";
    }

}

