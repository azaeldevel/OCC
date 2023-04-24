
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
    }
}

