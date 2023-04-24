
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Lexer::rules(std::ostream& out) const
    {

        out << "\"auto\"		return AUTO;\n";
        out << "\"byte\"		return BYTE;\n";
        out << "\"const\"		return CONST;\n";
        out << "\"char\"		return CHAR;\n";
        out << "\"double\"	    return DOUBLE;\n";
        out << "\"float\"		return FLOAT;\n";
        out << "\"register\"	return REGISTER;\n";
        out << "\"short\"		return SHORT;\n";
        out << "\"signed\"	    return SIGNED;\n";
        out << "\"sizeof\"	    return SIZEOF;\n";
        out << "\"static\"	    return STATIC;\n";
        out << "\"typedef\"	    return TYPEDEF;\n";
        out << "\"unsigned\"	return UNSIGNED;\n";
        out << "\"void\"		return VOID;\n";
        out << "\"volatil\"	    return VOLATIL;\n";
        out << "\"extern\"	    return EXTERN;\n";
        out << "\"goto\"		return GOTO;\n";
        out << "\"int\"		    return INT;\n";
        out << "\"long\"		return LONG;\n";
        out << "\"default\"	    return DEFAULT;\n";

        out << "\"mov\"         return MOV;\n";
        out << "\"al\"	        return AL;\n";
        out << "\"ah\"	        return AH;\n";


        out << "\"break\"		return BREAK;\n";
        out << "\"case\"		return CASE;\n";
        out << "\"continue\"	return CONTINUE;\n";
        out << "\"do\"		    return DO;\n";
        out << "\"else\"		return ELSE;\n";
        out << "\"enum\"		return ENUM;\n";
        out << "\"for\"		    return FOR;\n";
        out << "\"if\"		return IF;\n";
        out << "\"return\"	return RETURN;\n";
        out << "\"struct\"	return STRUCT;\n";
        out << "\"switch\"	return SWITCH;\n";
        out << "\"union\"		return UNION;\n";
        out << "\"while\"		return WHILE;\n";



        out << "[[:space:]]			;\n";

        out << "{IDENTIFIER}	{\n";
                            //std::cout << "Line IDENTIFIER : " << yylineno << " : " << yytext << "\n";
                            out << "\t\tAI_here::nodes::identifier* identifer = block.create<AI_here::nodes::identifier>();\n";
                            out << "\t\tidentifer->line = yylineno;\n";
                            out << "\t\tidentifer->name = yytext;\n";
                            out << "\t\tyylval->IDENTIFIER = identifer;\n";
                            out << "\t\treturn IDENTIFIER;\n";
                        out << "\t\t}\n";

        out << "{CONSTANT_INTEGER_HEX}  {\n";
                                    //std::cout << "Line LIETRAL_INTEGER_HEX : " << yylineno << "\n";
                                    out << "\t\tAI_here::nodes::Integer* integer = block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tinteger->format = 'H';\n";
                                    out << "\t\tinteger->number = std::stoll(yytext, nullptr, 16);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_HEX = integer->number;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_HEX;\n";
                                out << "\t\t}\n";
        out << "{CONSTANT_INTEGER_DEC}  {\n";
                                    //std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
                                    out << "\t\tAI_here::nodes::Integer* integer = block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tinteger->format = 'D';\n";
                                    out << "\t\tinteger->number = std::stoll(yytext);\n";
                                    out << "\t\tyylval->CONSTANT_INTEGER_HEX = integer->number;\n";
                                    out << "\t\treturn CONSTANT_INTEGER_HEX;\n";
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


        out << ".	;\n";

    }

}

