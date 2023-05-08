
/*
 * Octetos Assembler
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 *
 * Octetos Compuler Collection is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CC is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string.h>
#include <iostream>
#include <fstream>
#include <list>

#include "A-Driver.hh"
#include "A+-Driver.hh"

bool extension(const std::filesystem::path& path, const std::string& ext)
{
    //std::cout << "\n\n";
    if(ext.size() >= path.string().size()) return false;
    for(size_t i = 0; i < ext.size(); i++)
    {
        if(path.string()[path.string().size() - i - 1] != ext[ext.size() - i - 1]) return false;
        //std::cout << path.string()[path.string().size() - i - 1] << " == " << ext[ext.size() - i - 1] << "\n";
    }
    //std::cout << "El archivo " << path << ", tinen extecion '" << ext << "'\n";
    return true;
}

namespace AII_here = oct::cc::v0::AII;
namespace AI_here = oct::cc::v0::AI;

int main (int argc, char* argv[])
{
    std::fstream outstream;
    std::filesystem::path outpath;
    std::list<std::filesystem::path> inputs;
    core_here::Block block;

	for(size_t i = 0; i < (size_t)argc; i++)
	{
		if(strcmp(argv[i],"--output") == 0)
		{
			outpath = argv[++i];
		}
		else if(argv[i][0] == '-')
		{
			std::cout << "Comando desconocido\n";
		}
		else
		{//posibles archivos input
			inputs.push_back(argv[++i]);
		}
	}

	if(inputs.empty())
	{
		std::cout << "Indique almenos un archivo para compilar.";
		return EXIT_FAILURE;
	}

	if(outpath.empty())
	{
		std::cerr << "Indique el archivo de resultado.";
		return EXIT_FAILURE;
	}
	outstream.open(outpath, std::ios_base::out | std::ios_base::binary);
    if(not outstream.is_open())
    {
		std::cerr << "Fallo al abrir el archivo de resultado.";
		return EXIT_FAILURE;
    }

	AI_here::Tray<AI_here::nodes::translation_unit> trayI;
	AI_here::Tray<AII_here::nodes::external_declaration> trayII;
    AI_here::Driver driverI(trayI);
	AII_here::Driver driverII(trayII);
	for(const std::filesystem::path& path : inputs)
	{
	    if(not std::filesystem::exists(path))
        {
            std::cerr << "No existe el archivo fuente " << path << "\n";
            return EXIT_FAILURE;
        }

        //
        if(extension(path,".a.asm"))
        {
            //std::cout << "Parsing ...\n";
            if(driverI.parse(path))
            {
                if(not driverI.semantic())
                {

                }
                //std::cout << "Printing ...\n";
                //driverI.print(std::cout);
                //std::cout << "Generating ...\n";
                driverI.generate(outstream);
                outstream.flush();
                outstream.close();
                std::cout << "\n\nCompletdo.\n";
            }
        }
        else if(extension(path,".a+.asm"))
        {
            //std::cout << "Parsing ...\n";
            if(driverII.parse(path))
            {
                if(not driverII.semantic())
                {

                }
                const AI_here::nodes::translation_unit* tree = driverII.translate();
                //std::cout << "Printing ...\n";
                //driverII.print(std::cout);
                if(tree) driverI.print(std::cout,tree);
                //std::cout << "Generating ...\n";
                if(tree) driverI.generate(outstream,tree);
                outstream.flush();
                outstream.close();
                std::cout << "\n\nCompletdo.\n";
            }
        }
        else
        {
            //std::cerr << "El archivo " << path << ", no se reconoce como un archivo fuente.\n";
            std::cerr << "La extencion " << path.extension() << ", no se reconoce como un archivo fuente.\n";
        }
	}

    /*for (auto const& [key, val] : trayI.symbols)
    {
        std::cout << key << "->" << val << "\n";
    }*/

	return EXIT_SUCCESS;
}

