
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Parser::functions(std::ostream& out) const
    {
        out << "void yyerror(yyscan_t scanner, result *res, const AI_here::nodes::translation_unit** unit,core_here::Block& block, const char *msg, ...)\n";
        out << "{\n";
        out << "}\n";
    }
}

