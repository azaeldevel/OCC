
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Parser::functions(std::ostream& out) const
    {
        /*
        out << "void yyerror(YYLTYPE* yyalloc,yyscan_t scanner, result *res, const " << space() << "_here::nodes::" << tree_node() << "** unit,core_here::Block& block, const char *msg)\n";
        out << "{\n";
            out << "\tprintf(msg);\n";
        out << "}\n";
        */

        out << "void yyerror(YYLTYPE* yylloc,yyscan_t scanner, result *res, const " << space() << "_here::nodes::" << tree_node() << "** unit,core_here::Block& block, const char *msg, ...)\n";
        out << "{\n";
          out << "\tYYLOCATION_PRINT (stderr, yylloc);\n";
          out << "\tfprintf (stderr, \": %s\", msg);\n";
        out << "}\n";

        /*
        out << "void yyerror(YYLTYPE* yyalloc,yyscan_t scanner, result *res, const " << space() << "_here::nodes::" << tree_node() << "** unit,core_here::Block& block, const char *msg, char c)\n";
        out << "{\n";
            out << "\tprintf(msg,c);\n";
        out << "}\n";

        out << "void yyerror(YYLTYPE* yyalloc,yyscan_t scanner, result *res, const " << space() << "_here::nodes::" << tree_node() << "** unit,core_here::Block& block, const char *msg, yytoken_kind_t t)\n";
        out << "{\n";
            out << "\tprintf(msg,t);\n";
        out << "}\n";
        */
    }
}

