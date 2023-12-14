
#include "Generator.hh"

namespace oct::cc::v1
{

    Generator::Generator(Language l) : lang(l)
    {
    }

    void Generator::keywords_c(std::ostream& out) const
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

