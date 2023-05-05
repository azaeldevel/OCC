
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
            out << "\"AL\"	        return AL;\n";
            out << "\"AH\"	        return AH;\n";
            out << "\"BL\"	        return BL;\n";
            out << "\"BH\"	        return BH;\n";
            out << "\"CL\"	        return CL;\n";
            out << "\"CH\"	        return CH;\n";
            out << "\"DL\"	        return DL;\n";
            out << "\"DH\"	        return DH;\n";

            out << "\"ES\"	        return ES;\n";
            out << "\"CS\"	        return CS;\n";
            out << "\"SS\"	        return SS;\n";
            out << "\"DS\"	        return DS;\n";

            out << "\"MOV\"         return MOV;\n";
            out << "\"RET\"	        return RET;\n";
            out << "\"IRET\"	    return IRET;\n";

            out << "\"byte\"		return BYTE;\n";
            out << "\"tiny\"		return TINY;\n";
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



        out << "{IDENTIFIER}	{\n";
                            //out << "\t\tstd::cout << \"Line IDENTIFIER : \" << yylloc->last_line << \" : \" << yytext << \"\\n\";\n";
                            out << "\t\tAI_here::nodes::identifier* identifer = tray->block.create<AI_here::nodes::identifier>();\n";
                            out << "\t\tidentifer->line = yylineno;\n";
                            out << "\t\tidentifer->string = yytext;\n";
                            out << "\t\tyylval->IDENTIFIER = identifer;\n";
                            out << "\t\treturn IDENTIFIER;\n";
                        out << "\t\t}\n";

        out << "{CONSTANT_INTEGER_HEX}  {\n";
                                    //std::cout << "Line LIETRAL_INTEGER_HEX : " << yylineno << "\n";
                                    out << "\t\tAI_here::nodes::Integer* integer = tray->block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tinteger->format = 'H';\n";
                                    out << "\t\tinteger->number = std::stoll(yytext, nullptr, 16);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_HEX = integer->number;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_HEX;\n";
                                out << "\t\t}\n";
        out << "{CONSTANT_INTEGER_DEC}  {\n";
                                    //std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
                                    out << "\t\tAI_here::nodes::Integer* integer = tray->block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tinteger->format = 'D';\n";
                                    out << "\t\tinteger->number = std::stoll(yytext);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_HEX = integer->number;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_HEX;\n";
                                out << "\t\t}\n";
        out << "{CONSTANT_INTEGER_OCT}  {\n";
                                    //std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
                                    out << "\t\tAI_here::nodes::Integer* integer = tray->block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tinteger->format = 'D';\n";
                                    out << "\t\tinteger->number = std::stoll(yytext);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_OCT = integer->number;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_OCT;\n";
                                out << "\t\t}\n";
        out << "{CONSTANT_CHAR} {\n";
                            //std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
                            out << "\t\tyylval->CONSTANT_CHAR = yytext[1];\n";
                            out << "\t\treturn CONSTANT_CHAR;\n";
                        out << "\t\t}\n";




        out << "[[:punct:]]	{\n";
                        //std::cout << "Lexer(" << yytext[0] << ") ";
                        out << "\t\treturn (yytoken_kind_t)yytext[0];\n";
                out << "\t\t}\n";



        out << "<<EOF>>  return ENDOFFILE;\n";


        out << ".       yyerror(yylloc,yyscanner,tray,\"El caracter '%c' no es parte del lenguaje.\",yytext[0]);\n";

    }

}

