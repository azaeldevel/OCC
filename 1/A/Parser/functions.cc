
#include "Generator.hh"

namespace oct::cc::v1
{
    void Parser::functions(std::ostream& out) const
    {
        /*
        out << "void yyerror(YYLTYPE* yyalloc,yyscan_t scanner, result *res, const " << space() << "_here::nodes::" << tree_node() << "** unit,core_here::Block& block, const char *msg)\n";
        out << "{\n";
            out << "\tprintf(msg);\n";
        out << "}\n";
        */

        out << "void yyerror(YYLTYPE* yylloc,yyscan_t scanner," << space(1) << "_here::Tray<" << space() << "_here::nodes::" << tree_node() << ">* tray, const char *msg, ...)\n";
        out << "{\n";
          //out << "\tYYLOCATION_PRINT (stderr, yylloc);\n";
          out << "\tfprintf (stderr, \"%i : %s\\n\", yylloc->last_line, msg);\n";
        out << "}\n";

        out << "void yyerror_unknow_symbol(YYLTYPE* yylloc,yyscan_t scanner," << space(1) << "_here::Tray<" << space() << "_here::nodes::" << tree_node() << ">* tray, char c)\n";
        out << "{\n";
          //out << "\tYYLOCATION_PRINT (stderr, yylloc);\n";
          out << "\tfprintf (stderr, \"%i : El caracter '%c', no es parte de lenguaje.\\n\", yylloc->last_line, c);\n";
        out << "}\n";

        out << "bool oct::cc::v0::" << space() << "::Driver::parse(const std::filesystem::path& path)\n";
        out << "{\n";
            out << "\tfile.open(path);\n";
            out << "\tif(yyparse(file.get_scanner(),tray) == 0) return true;\n";
            out << "\treturn false;\n";
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

