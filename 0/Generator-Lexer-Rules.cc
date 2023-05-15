
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Lexer::rules(std::ostream& out) const
    {

        out << "\\n    yylloc->last_line++; yylloc->last_column = 1;\n";
        out << "[ \\t]+   LOCATION_STEP (); continue;\n";


        //Ensamblador
        if(is_disnastic_A())
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


        //C keyword
        //out << "\"auto\"		return AUTO;\n";
        out << "\"char\"		return CHAR;\n";
        //out << "\"break\"		return BREAK;\n";
        //out << "\"case\"		return CASE;\n";
        //out << "\"const\"		return CONST;\n";
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
        out << "\"int\"		return INT;\n";
        out << "\"long\"		return LONG;\n";
        out << "\"register\"	return REGISTER;\n";
        if(has_return_statement()) out << "\"return\"	return RETURN;\n";
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
        //out << "\"volatil\"	return VOLATIL;\n";
        //out << "\"while\"		return WHILE;\n";


        out << "\"//\".*		;\n";


        out << "{IDENTIFIER}	{\n";
                            //out << "\t\tstd::cout << \"Line IDENTIFIER : \" << yylloc->last_line << \" : \" << yytext << \"\\n\";\n";
                            out << "\t\tAI_here::nodes::identifier* identifer = tray->block.create<AI_here::nodes::identifier>();\n";
                            out << "\t\tidentifer->line = yylineno;\n";
                            out << "\t\tidentifer->string = yytext;\n";
                            out << "\t\tyylval->IDENTIFIER = identifer;\n";
                            out << "\t\treturn IDENTIFIER;\n";
                        out << "\t\t}\n";

        out << "{CONSTANT_INTEGER_HEX}  {\n";
                                    out << "\t\tstd::cout << \"Line LIETRAL_INTEGER_HEX : \\n\";\n";
                                    //out << "\t\tAI_here::nodes::Integer* integer = tray->block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tAI_here::nodes::constant_integer<AI_here::integer>* const_integer = tray->block.create<AI_here::nodes::constant_integer<AI_here::integer>>();\n";
                                    out << "\t\tconst_integer->set(yytext,AI_here::nodes::constant_integer<AI_here::integer>::Format::hexadecimal);\n";
                                    //out << "\t\tconst_integer->token = CONSTANT_INTEGER_DEC;\n";
                                    //out << "\t\tinteger->format = 'H';\n";
                                    //out << "\t\tinteger->number = std::stoll(yytext, nullptr, 16);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_HEX = const_integer;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_HEX;\n";
                                out << "\t\t}\n";
        if(is_byte_based())
        {
        out << "{CONSTANT_INTEGER_8b}  {\n";
                                    //out << "\t\tstd::cout << \"Line CONSTANT_INTEGER_DEC_8b : \" << yytext << \"\\n\";\n";
                                    out << "\t\tAI_here::nodes::constant_integer<AI_here::integer>* const_integer = tray->block.create<AI_here::nodes::constant_integer<AI_here::integer>>();\n";
                                    out << "\t\tconst_integer->set(yytext,AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_8b = const_integer;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_8b;\n";
                                out << "\t\t}\n";
        out << "{CONSTANT_INTEGER_16b}  {\n";
                                    //out << "\t\tstd::cout << \"Line CONSTANT_INTEGER_DEC_16b : \" << yytext << \"\\n\";\n";
                                    out << "\t\tAI_here::nodes::constant_integer<AI_here::integer>* const_integer = tray->block.create<AI_here::nodes::constant_integer<AI_here::integer>>();\n";
                                    out << "\t\tconst_integer->set(yytext,AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_16b = const_integer;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_16b;\n";
                                out << "\t\t}\n";
        }
        else
        {
        out << "{CONSTANT_INTEGER_DEC}  {\n";
                                    //std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
                                    //out << "\t\tAI_here::nodes::Integer* integer = tray->block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tAI_here::nodes::constant_integer<AI_here::integer>* const_integer = tray->block.create<AI_here::nodes::constant_integer<AI_here::integer>>();\n";
                                    out << "\t\tconst_integer->set(yytext,AI_here::nodes::constant_integer<AI_here::integer>::Format::decimal);\n";
                                    //out << "\t\tconst_integer->token = CONSTANT_INTEGER_HEX;\n";
                                    //out << "\t\tstd::cout << \"number = \" << const_integer->get_value() << \"\\n\";\n";
                                    //out << "\t\tinteger->format = 'D';\n";
                                    //out << "\t\tinteger->number = std::stoll(yytext);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_DEC = const_integer;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_DEC;\n";
                                out << "\t\t}\n";

        }
        out << "{CONSTANT_INTEGER_OCT}  {\n";
                                    out << "\t\tstd::cout << \"Line CONSTANT_INTEGER_OCT : \\n\";\n";
                                    //out << "\t\tAI_here::nodes::Integer* integer = tray->block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tAI_here::nodes::constant_integer<AI_here::integer>* const_integer = tray->block.create<AI_here::nodes::constant_integer<AI_here::integer>>();\n";
                                    out << "\t\tconst_integer->set(yytext,AI_here::nodes::constant_integer<AI_here::integer>::Format::octal);\n";
                                    //out << "\t\tconst_integer->token = CONSTANT_INTEGER_OCT;\n";
                                    //out << "\t\tinteger->format = 'D';\n";
                                    //out << "\t\tinteger->number = std::stoll(yytext);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_OCT = const_integer;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_OCT;\n";
                                out << "\t\t}\n";
        out << "{CONSTANT_CHAR} {\n";
                            //std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
                            out << "\t\tAI_here::nodes::charater_constant<char>* const_char = tray->block.create<AI_here::nodes::charater_constant<char>>();\n";
                            //out << "\t\tconst_char->token = CONSTANT_CHAR;\n";
                            out << "\t\tconst_char->value = yytext[1];\n";
                            out << "\t\tyylval->CONSTANT_CHAR = const_char;\n";
                            out << "\t\treturn CONSTANT_CHAR;\n";
                        out << "\t\t}\n";




        out << "[[:punct:]]	{\n";
                        //std::cout << "Lexer(" << yytext[0] << ") ";
                        out << "\t\treturn (yytoken_kind_t)yytext[0];\n";
                out << "\t\t}\n";



        out << "<<EOF>>  return ENDOFFILE;\n";


        out << ".       yyerror_unknow_symbol(yylloc,yyscanner,tray,yytext[0]);\n";

    }

}

