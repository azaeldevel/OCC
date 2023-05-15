
#include "Generator.hh"

namespace oct::cc::v0::tools
{
    void Lexer::functions(std::ostream& out) const
    {
        out << "namespace oct::cc::v0::AI\n";
        out << "{\n";
            out << "File::~File()\n";
            out << "{\n";
                out << "\tif(buffer)\n";
                out << "\t{\n";
                    out << "\t\tyy_delete_buffer ((YY_BUFFER_STATE)buffer, scanner);\n";
                    out << "\t\tbuffer = NULL;\n";
                out << "\t}\n";
                out << "\tif(scanner)\n";
                out << "\t{\n";
                    out << "\t\tyylex_destroy (scanner);\n";
                    out << "\t\tscanner = NULL;\n";
                out << "\t}\n";
                out << "\tif(file)\n";
                out << "\t{\n";
                    out << "\t\tfclose(file);\n";
                    out << "\t\tfile = NULL;\n";
                out << "\t}\n";
            out << "}\n";

            out << "bool File::open(const std::filesystem::path& fn)\n";
            out << "{\n";
                out << "\tif(file) return false;\n";
                out << "\tif(buffer) return false;\n";
                out << "\tif(not filename.empty()) return false;\n";
                out << "\tif(fn.empty()) return false;\n";
                //std::cout << "Loading file " << fn << "..\n";

                out << "\tfilename = fn;\n";
                out << "\tfile = fopen(filename.string().c_str(), \"r\");\n";
                out << "\tif(not file) return false;\n";
                //std::cout << "Create file " << fn << "..\n";

                out << "\tyylex_init (&scanner);\n";
                //std::cout << "Creating scanner..\n";
                out << "\tbuffer = yy_create_buffer(file, YY_BUF_SIZE, scanner);\n";
                out << "\tyy_switch_to_buffer((YY_BUFFER_STATE)buffer,(yyscan_t)scanner);\n";

                out << "\treturn true;\n";
            out << "}\n";

        out << "}\n";

        out << "\n";
        out << "void v0_AI_lexer()\n";
        out << "{\n";
            out << "\tYYSTYPE yylval_test;\n";
            out << "\tYYLTYPE yylloc_test;\n";
            out << "\tyyscan_t yyscanner_test;\n";
            out << "\t" << space(1) << "_here::Tray<" << space() << "_here::nodes::" << tree_node() << "> tray_test;\n";

            out << "\tstd::string numbers;\n";
            out << "\tYY_BUFFER_STATE bp;\n";
            out << "\tyylex_init (&yyscanner_test);\n";
            out << "\tyytoken_kind_t token;\n";

            out << "\tfor(int i = -128; i < 128; i++)\n";
            out << "\t{\n";
                out << "\t\tif(i > 0)\n";
                out << "\t\t{\n";
                out << "\t\t\tnumbers.clear();\n";
                out << "\t\t\tnumbers = \"+\";\n";
                out << "\t\t\tnumbers += std::to_string(i);\n";
                out << "\t\t}\n";
                out << "\t\telse if(i < 0)\n";
                out << "\t\t{\n";
                out << "\t\t\tnumbers.clear();\n";
                out << "\t\t\tnumbers = std::to_string(i);\n";
                out << "\t\t}\n";
                out << "\t\telse\n";
                out << "\t\t{\n";
                out << "\t\t\tcontinue;\n";
                out << "\t\t}\n";
                out << "\t\tyylex_init (&yyscanner_test);\n";
                out << "\t\tbp = yy_scan_string(numbers.c_str(),yyscanner_test);\n";
                out << "\t\tyy_switch_to_buffer(bp,yyscanner_test);\n";
                out << "\t\ttoken = yylex(&yylval_test,&yylloc_test,yyscanner_test,&tray_test);\n";
                out << "\t\tyy_flush_buffer(bp,yyscanner_test);\n";
                out << "\t\tyy_delete_buffer (bp,yyscanner_test);\n";
                out << "\t\tyylex_destroy (yyscanner_test);\n";
                out << "\t\tif(token == CONSTANT_INTEGER_8b)\n";
                out << "\t\t{\n";
                out << "\t\t\t\n";
                out << "\t\t}\n";
                out << "\t\telse\n";
                out << "\t\t{\n";
                out << "\t\t\tstd::cout << numbers << \": Fallo\\n\";\n";
                out << "\t\t}\n";
            out << "\t}\n";

        out << "}\n";
    }
}

