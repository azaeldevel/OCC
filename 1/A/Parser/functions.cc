
#include "Generator.hh"

namespace oct::cc::v1::A
{
    void Parser::functions(std::ostream& out) const
    {
        out << "void yyerror(YYLTYPE* yylloc,yyscan_t scanner,occ::A::I::Tray* tray, const char *msg, ...)\n";
        out << "{\n";
          //out << "\tYYLOCATION_PRINT (stderr, yylloc);\n";
          out << "\tfprintf (stderr, \"%i : %s\\n\", yylloc->last_line, msg);\n";
        out << "}\n";

        out << "void yyerror_unknow_symbol(YYLTYPE* yylloc,yyscan_t scanner,occ::A::I::Tray* tray, char c)\n";
        out << "{\n";
          //out << "\tYYLOCATION_PRINT (stderr, yylloc);\n";
          out << "\tfprintf (stderr, \"%i : El caracter '%c', no es parte de lenguaje.\\n\", yylloc->last_line, c);\n";
        out << "}\n";

        /*out << "bool occ::A::I::Driver::parse(const std::filesystem::path& path)\n";
        out << "{\n";
            out << "\tfile.open(path);\n";
            out << "\tif(yyparse(file.get_scanner(),tray) == 0) return true;\n";
            out << "\treturn false;\n";
        out << "}\n";*/
    }
}

