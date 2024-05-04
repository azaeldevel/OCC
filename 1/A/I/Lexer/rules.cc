
#include "Generator.hh"

#include <core/3/string.hh>


namespace oct::cc::v1::A::I
{
    void Lexer::rules(std::ostream& out) const
    {

        out << "\"//\".*    {\n";
                                out << "\t\t\tyylexnext->yylexnext(words.next(yytext,yyleng));\n";
                                out << "\t\t\tyylexnext = yylexnext->yylexnext();\n";
        out << "        }\n";
        out << "\\n     {\n";
                                out << "\t\t\tyylloc->last_line++;\n";
                                out << "\t\t\tyylloc->last_column = 1;\n";
                                out << "\t\t\tyylexnext->yylexnext(words.next(yytext,yyleng));\n";
                                out << "\t\t\tyylexnext = yylexnext->yylexnext();\n";
        out << "        }\n";
        out << "\\t             ;\n";
        out << "[[:space:]]     ;\n";

        rules_keywords(out,Language::C90);

        {
            rules_add_keyword_register(out,"al");
            rules_add_keyword_register(out,"ah");
            rules_add_keyword_register(out,"ax");
            rules_add_keyword_register(out,"bl");
            rules_add_keyword_register(out,"bh");
            rules_add_keyword_register(out,"bx");
            rules_add_keyword_register(out,"cl");
            rules_add_keyword_register(out,"ch");
            rules_add_keyword_register(out,"cx");
            rules_add_keyword_register(out,"dl");
            rules_add_keyword_register(out,"dh");
            rules_add_keyword_register(out,"dx");

            rules_add_keyword_segment(out,"es");
            rules_add_keyword_segment(out,"cs");
            rules_add_keyword_segment(out,"ss");
            rules_add_keyword_segment(out,"ds");

            rules_add_keyword(out,"si");
            rules_add_keyword(out,"di");
            rules_add_keyword(out,"bp");
            rules_add_keyword(out,"sp");

            rules_add_keyword(out,"mov","MOV");
            rules_add_keyword(out,"ret","RET");
            rules_add_keyword(out,"iret","IRET");
            rules_add_keyword(out,"call");
            rules_add_keyword(out,"push");
            rules_add_keyword(out,"pop");

            //out << "\"byte\"		return BYTE;\n";
            //out << "\"tiny\"		return TINY;\n";
        }

        out << "{IDENTIFIER}\t\t{\n";
                            out << "\t\tyylval->IDENTIFIER = identifiers.next(occ::Statemants::string,occ::Tokens::IDENTIFIER,yytext,yyleng);\n";
                            //out << "\t\tstd::cout << yytext << \":\" << yyleng ;\n";
                            out << "\t\treturn IDENTIFIER;\n";
        out << "\t\t}\n";

        /*out << "{INTEGER_DECIMAL}  {\n";
                                    out << "\t\tyylval->INTEGER_DECIMAL = new occ::Number(occ::Statemants::integer,occ::Tokens::INTEGER,yytext,yyleng);\n";
                                    out << "\t\treturn INTEGER_DECIMAL;\n";
                                out << "\t\t}\n";*/
        out << "{INTEGER_DECIMAL_TINY}  {\n";
                                    out << "\t\tyylval->INTEGER_DECIMAL = numbers.next(occ::Statemants::integer,occ::Tokens::TINY,yytext,yyleng);\n";
                                    out << "\t\treturn INTEGER_DECIMAL;\n";
                                out << "\t\t}\n";
        out << "{INTEGER_DECIMAL_UTINY}  {\n";
                                    out << "\t\tyylval->INTEGER_DECIMAL = numbers.next(occ::Statemants::integer,occ::Tokens::TINY,yytext,yyleng,10);\n";
                                    out << "\t\treturn INTEGER_DECIMAL;\n";
                                out << "\t\t}\n";

        /*out << "{INTEGER_HEXDECIMAL}  {\n";
                                    out << "\t\tyylval->INTEGER_HEXDECIMAL = new occ::Number(occ::Statemants::integer,occ::Tokens::INTEGER,yytext,yyleng);\n";
                                    out << "\t\treturn INTEGER_HEXDECIMAL;\n";
                                out << "\t\t}\n";*/

        out << "{INTEGER_HEXDECIMAL_TINY}  {\n";
                                    out << "\t\tyylval->INTEGER_HEXDECIMAL = numbers.next(occ::Statemants::integer,occ::Tokens::TINY,yytext,yyleng,16);\n";
                                    out << "\t\treturn INTEGER_HEXDECIMAL;\n";
                                out << "\t\t}\n";

        out << "{INTEGER_HEXDECIMAL_SHORT}  {\n";
                                    out << "\t\tyylval->INTEGER_HEXDECIMAL = numbers.next(occ::Statemants::integer,occ::Tokens::SHORT,yytext,yyleng,16);\n";
                                    out << "\t\treturn INTEGER_HEXDECIMAL;\n";
                                out << "\t\t}\n";

         out << "{LETTER}  {\n";
                                    out << "\t\tyylval->LETTER = letters.next((char)yytext[1]);\n";
                                    out << "\t\treturn LETTER;\n";
                                out << "\t\t}\n";

        out << "[[:punct:]]	{\n";
            out << "\t\treturn (yytoken_kind_t)yytext[0];\n";
        out << "\t\t}\n";



        out << "<<EOF>>  return ENDOFFILE;\n";


        out << ".       yyerror_unknow_symbol(yylloc,yyscanner,tray,yytext[0]);\n";

    }

    void Lexer::rules_add_keyword(std::ostream& out,const std::string& string,const std::string& token) const
    {
        out << "\"" << string << "\"     {\n";
            out << "\t\tyylexnext->yylexnext(keywords.next(occ::Statemants::keyword,occ::Tokens::" << token << ",yytext,yyleng));\n";
            out << "\t\tyylexnext = yylexnext->yylexnext();\n";
            out << "\t\tyylval->" << token << " = (occ::Keyword*)yylexnext;\n";
            out << "\t\treturn " << token << ";\n";
        out << "        }\n";
    }

    void Lexer::rules_add_keyword(std::ostream& out,const std::string& string) const
    {
        out << "\"" << string << "\"     {\n";
            //out << "\t\tstd::cout << \"" << core::toupper(string) << "\" << \"\\n\";\n";
            out << "\t\tyylexnext->yylexnext(keywords.next(occ::Statemants::keyword,occ::Tokens::" << core::toupper(string) << ",yytext,yyleng));\n";
            out << "\t\tyylexnext = yylexnext->yylexnext();\n";
            out << "\t\tyylval->" << core::toupper(string) << " = (occ::Keyword*)yylexnext;\n";
            out << "\t\treturn " << core::toupper(string) << ";\n";
        out << "        }\n";
    }
    void Lexer::rules_add_keyword_register(std::ostream& out,const std::string& string) const
    {
        out << "\"" << string << "\"     {\n";
            out << "\t\tyylexnext->yylexnext(registers.next(occ::Statemants::reg,occ::Tokens::" << core::toupper(string) << ",yytext,yyleng));\n";
            out << "\t\tyylexnext = yylexnext->yylexnext();\n";
            out << "\t\tyylval->" << core::toupper(string) << " = (occ::A::Register*)yylexnext;\n";
            out << "\t\treturn " << core::toupper(string) << ";\n";
        out << "        }\n";
    }
    void Lexer::rules_add_keyword_segment(std::ostream& out,const std::string& string) const
    {
        out << "\"" << string << "\"     {\n";
            out << "\t\tyylexnext->yylexnext(segments.next(occ::Statemants::segment,occ::Tokens::" << core::toupper(string) << ",yytext,yyleng));\n";
            out << "\t\tyylexnext = yylexnext->yylexnext();\n";
            out << "\t\tyylval->" << core::toupper(string) << " = (occ::A::Segment*)yylexnext;\n";
            out << "\t\treturn " << core::toupper(string) << ";\n";
        out << "        }\n";
    }

    void Lexer::rules_keywords(std::ostream& out,Language l) const
    {
        if(Language::C == l or Language::C90 == l)
        {
            rules_add_keyword(out,"auto");
            rules_add_keyword(out,"char");
            rules_add_keyword(out,"break");
            rules_add_keyword(out,"case");
            rules_add_keyword(out,"const");
            rules_add_keyword(out,"continue");
            rules_add_keyword(out,"default");
            rules_add_keyword(out,"do");
            rules_add_keyword(out,"double");
            rules_add_keyword(out,"else");
            rules_add_keyword(out,"enum");
            rules_add_keyword(out,"extern");
            rules_add_keyword(out,"float");
            rules_add_keyword(out,"for");
            rules_add_keyword(out,"goto");
            rules_add_keyword(out,"if");
            rules_add_keyword(out,"int");
            rules_add_keyword(out,"long");
            rules_add_keyword(out,"register");
            rules_add_keyword(out,"return");
            rules_add_keyword(out,"short");
            rules_add_keyword(out,"signed");
            rules_add_keyword(out,"sizeof");
            rules_add_keyword(out,"static");
            rules_add_keyword(out,"struct");
            rules_add_keyword(out,"switch");
            rules_add_keyword(out,"typedef");
            rules_add_keyword(out,"union");
            rules_add_keyword(out,"unsigned");
            rules_add_keyword(out,"void");
            rules_add_keyword(out,"volatil");
            rules_add_keyword(out,"while");
        }
    }

}

