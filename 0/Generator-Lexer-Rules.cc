
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Lexer::rules(std::ostream& out) const
    {

        out << "%{\n";
            /** Code executed at the beginning of yylex **/
            out << "\tyylval = lval;// A handy shortcut to the location held by the driver.\n";
            //yy::location& loc = driver.location;
            out << "\tloc->step ();\n";
        out << "%}\n";


        out << "\"auto\"		return token::AUTO;\n";
        out << "\"byte\"		return token::BYTE;\n";
        out << "\"const\"		return token::CONST;\n";
        out << "\"char\"		return token::CHAR;\n";
        out << "\"double\"	    return token::DOUBLE;\n";
        out << "\"float\"		return token::FLOAT;\n";
        out << "\"register\"	return token::REGISTER;\n";
        out << "\"short\"		return token::SHORT;\n";
        out << "\"signed\"	    return token::SIGNED;\n";
        out << "\"sizeof\"	    return token::SIZEOF;\n";
        out << "\"static\"	    return token::STATIC;\n";
        out << "\"typedef\"	    return token::TYPEDEF;\n";
        out << "\"unsigned\"	return token::UNSIGNED;\n";
        out << "\"void\"		return token::VOID;\n";
        out << "\"volatil\"	    return token::VOLATIL;\n";
        out << "\"extern\"	    return token::EXTERN;\n";
        out << "\"goto\"		return token::GOTO;\n";
        out << "\"int\"		    return token::INT;\n";
        out << "\"long\"		return token::LONG;\n";
        out << "\"default\"	    return token::DEFAULT;\n";

        out << "\"mov\"         return token::MOV;\n";
        out << "\"al\"	        return token::AL;\n";
        out << "\"ah\"	        return token::AH;\n";


        out << "\"break\"		return token::BREAK;\n";
        out << "\"case\"		return token::CASE;\n";
        out << "\"continue\"	return token::CONTINUE;\n";
        out << "\"do\"		    return token::DO;\n";
        out << "\"else\"		return token::ELSE;\n";
        out << "\"enum\"		return token::ENUM;\n";
        out << "\"for\"		    return token::FOR;\n";
        out << "\"if\"		return token::IF;\n";
        out << "\"return\"	return token::RETURN;\n";
        out << "\"struct\"	return token::STRUCT;\n";
        out << "\"switch\"	return token::SWITCH;\n";
        out << "\"union\"		return token::UNION;\n";
        out << "\"while\"		return token::WHILE;\n";



        out << "[[:space:]]			;\n";

        out << "{IDENTIFIER}	{\n";
                            //std::cout << "Line IDENTIFIER : " << yylineno << " : " << yytext << "\n";
                            out << "\t\tAI_here::nodes::identifier* identifer = block.create<AI_here::nodes::identifier>();\n";
                            out << "\t\tidentifer->line = yylineno;\n";
                            out << "\t\tidentifer->name = yytext;\n";
                            out << "\t\tyylval->build<AI_here::nodes::identifier*>(identifer);\n";
                            out << "\t\treturn token::IDENTIFIER;\n";
                        out << "\t\t}\n";

        out << "{CONSTANT_INTEGER_HEX}  {\n";
                                    //std::cout << "Line LIETRAL_INTEGER_HEX : " << yylineno << "\n";
                                    out << "\t\tAI_here::nodes::Integer* integer = block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tinteger->format = 'H';\n";
                                    out << "\t\tinteger->number = std::stoll(yytext, nullptr, 16);\n";
                                    out << "\t\tyylval->build<long long>(integer->number);\n";
                                    out << "\t\treturn token::CONSTANT_INTEGER_HEX;\n";
                                out << "\t\t}\n";
        out << "{CONSTANT_INTEGER_DEC}  {\n";
                                    //std::cout << "Line LITERAL_INTEGER_DEC : " << yylineno << "\n";
                                    out << "\t\tAI_here::nodes::Integer* integer = block.create<AI_here::nodes::Integer>();\n";
                                    out << "\t\tinteger->format = 'D';\n";
                                    out << "\t\tinteger->number = std::stoll(yytext);\n";
                                    out << "\t\tyylval->build<long long>(integer->number);\n";
                                    out << "\t\treturn token::CONSTANT_INTEGER_HEX;\n";
                                out << "\t\t}\n";
        out << "{CONSTANT_CHAR} {\n";
                            //std::cout << "Line LIETRAL_CHAR : " << yylineno << "\n";
                            out << "\t\tyylval->build<char>(yytext[1]);\n";
                            out << "\t\treturn token::CONSTANT_CHAR;\n";
                        out << "\t\t}\n";




        out << "[[:punct:]]	{\n";
                        //std::cout << "Lexer(" << yytext[0] << ") ";
                        out << "\t\treturn yytext[0];\n";
                out << "\t\t}\n";






        out << ".	;\n";

    }

}

