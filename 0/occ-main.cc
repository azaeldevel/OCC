
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

	AI_here::SymbolTable symbols;
    AI_here::Driver driverI(symbols);
	AII_here::Driver driverII;
	for(const std::filesystem::path& path : inputs)
	{
	    if(not std::filesystem::exists(path))
        {
            std::cerr << "No existe el archivo fuente " << path << "\n";
            return EXIT_FAILURE;
        }
        if(extension(path,"a.asm"))
        {
            //std::cout << "Parsing ...\n";
            driverI.parse(path);
            //std::cout << "Printing ...\n";
            driverI.print(std::cout);
            //std::cout << "Generating ...\n";
            driverI.generate(outstream);
        }
        else if(extension(path,"a+.asm"))
        {
            driverII.parse(path);
            driverII.print(std::cout);
            driverII.generate(outstream);
        }
        else
        {
            //std::cerr << "El archivo " << path << ", no se reconoce como un archivo fuente.\n";
            std::cerr << "La extencion " << path.extension() << ", no se reconoce como un archivo fuente.\n";
        }
	}
    outstream.flush();
    outstream.close();

	return EXIT_SUCCESS;
}

