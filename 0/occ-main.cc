
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


namespace AII_here = oct::cc::v0::AII;
namespace AI_here = oct::cc::v0::AI;

int main (int argc, char* argv[])
{
    std::fstream outstream;
    std::filesystem::path outpath;
    std::list<std::filesystem::path> inputs;

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

	A_here::SymbolTable symbols;
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

	AII_here::Driver driver;
	//AI_here::Driver driver;
	for(const std::filesystem::path& path : inputs)
	{
        driver.parse(path);
	}
    //driver.print(std::cout);
    driver.generate(outstream);
    outstream.flush();
    outstream.close();

	std::cout << "Todo correcto\n";

	return EXIT_SUCCESS;
}

