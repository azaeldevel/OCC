
#include "Generator.hh"

#include <core/3/string.hh>


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

            rules_add_keyword(out,"es");
            rules_add_keyword(out,"cs");
            rules_add_keyword(out,"ss");
            rules_add_keyword(out,"ds");

            rules_add_keyword(out,"si");
            rules_add_keyword(out,"di");
            rules_add_keyword(out,"bp");
            rules_add_keyword(out,"sp");

            rules_add_keyword(out,"mov","MOV");
            rules_add_keyword(out,"ret","RET");
            rules_add_keyword(out,"iret","IRET");

            //out << "\"byte\"		return BYTE;\n";
            //out << "\"tiny\"		return TINY;\n";
        }

        out << "{IDENTIFIER}\t\t{\n";
                            out << "\t\tyylval->IDENTIFIER = new occ::Identifier(occ::Tokens::IDENTIFIER,yytext,yyleng);\n";
                            //out << "\t\tstd::cout << yytext << \":\" << yyleng ;\n";
                            out << "\t\treturn IDENTIFIER;\n";
        out << "\t\t}\n";

        out << "{INTEGER_DECIMAL}  {\n";
                                    out << "\t\tyylval->INTEGER_DECIMAL = new occ::Number(occ::Statemants::number,occ::Tokens::INTEGER,yytext,yyleng);\n";
                                    out << "\t\treturn INTEGER_DECIMAL;\n";
                                out << "\t\t}\n";

        out << "{INTEGER_HEXDECIMAL}  {\n";
                                    out << "\t\tyylval->INTEGER_HEXDECIMAL = new occ::Number(occ::Statemants::number,occ::Tokens::INTEGER,yytext,yyleng);\n";
                                    out << "\t\treturn INTEGER_HEXDECIMAL;\n";
                                out << "\t\t}\n";

         out << "{LETTER}  {\n";
                                    out << "\t\tyylval->LETTER = new occ::Char(yytext[1]);\n";
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
            out << "\t\tyylexnext->yylexnext = new occ::Keyword(occ::Statemants::keyword,occ::Tokens::" << token << ",yytext,yyleng);\n";
            out << "\t\tyylexnext = yylexnext->yylexnext;\n";
            out << "\t\tyylval->" << token << " = (occ::Keyword*)yylexnext;\n";
            out << "\t\treturn " << token << ";\n";
        out << "        }\n";
    }

    void Lexer::rules_add_keyword(std::ostream& out,const std::string& string) const
    {
        out << "\"" << string << "\"     {\n";
            out << "\t\tyylexnext->yylexnext = new occ::Keyword(occ::Statemants::keyword,occ::Tokens::" << core::toupper(string) << ",yytext,yyleng);\n";
            out << "\t\tyylexnext = yylexnext->yylexnext;\n";
            out << "\t\tyylval->" << core::toupper(string) << " = (occ::Keyword*)yylexnext;\n";
            out << "\t\treturn " << core::toupper(string) << ";\n";
        out << "        }\n";
    }
    void Lexer::rules_add_keyword_register(std::ostream& out,const std::string& string) const
    {
        out << "\"" << string << "\"     {\n";
            out << "\t\tyylexnext->yylexnext = new occ::A::Register(occ::Tokens::" << core::toupper(string) << ",yytext,yyleng);\n";
            out << "\t\tyylexnext = yylexnext->yylexnext;\n";
            out << "\t\tyylval->" << core::toupper(string) << " = (occ::A::Register*)yylexnext;\n";
            out << "\t\treturn " << core::toupper(string) << ";\n";
        out << "        }\n";
    }

    void Lexer::rules_keywords(std::ostream& out,Language l) const
    {
        if(Language::C == l or Language::C90 == l)
        {
            //out << "\"auto\"		return AUTO;\n";
            out << "\"char\"		return CHAR;\n";
            //out << "\"break\"		return BREAK;\n";
            //out << "\"case\"		return CASE;\n";
            out << "\"const\"		return CONST;\n";
            //out << "\"continue\"	return CONTINUE;\n";
            //out << "\"default\"	return DEFAULT;\n";
            //out << "\"do\"		return DO;\n";
            out << "\"double\"	return DOUBLE;\n";
            //out << "\"else\"		return ELSE;\n";
            //out << "\"enum\"		return ENUM;\n";
            //out << "\"extern\"	return EXTERN;\n";
            out << "\"float\"		return FLOAT;\n";
            //out << "\"for\"		return FOR;\n";
            //out << "\"goto\"		return GOTO;\n";
            //out << "\"if\"		return IF;\n";
            out << "\"int\"		    yylval->INT = new occ::Keyword(occ::Tokens::INT,yytext,yyleng);return INT;\n";
            out << "\"long\"		return LONG;\n";
            out << "\"register\"	return REGISTER;\n";
            //if(has_return_statement()) out << "\"return\"	return RETURN;\n";
            out << "\"short\"		return SHORT;\n";
            out << "\"signed\"	return SIGNED;\n";
            out << "\"sizeof\"	return SIZEOF;\n";
            //out << "\"static\"	return STATIC;\n";
            //out << "\"struct\"	return STRUCT;\n";
            //out << "\"switch\"	return SWITCH;\n";
            //out << "\"typedef\"	return TYPEDEF;\n";
            //out << "\"union\"		return UNION;\n";
            out << "\"unsigned\"	return UNSIGNED;\n";
            out << "\"void\"		return VOID;\n";
            out << "\"volatil\"	return VOLATIL;\n";
            //out << "\"while\"		return WHILE;\n";
        }
    }

}

