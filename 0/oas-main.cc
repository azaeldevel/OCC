
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

#include <oas-intel-parser-A+.hh>
#include <stdio.h>  // printf.
#include <stdlib.h> // getenv.
#include <iostream>
#include <fstream>
#include <string.h>
#include <iostream>
#include <fstream>
#include <list>
#include "A+.hh"


namespace A_here = oct::cc::v0::A;


//extern std::fstream outstream;
//std::filesystem::path outfile;
std::list<std::string> inputs;

int main (int argc, char* argv[])
{
	for(size_t i = 0; i < argc; i++)
	{
		if(strcmp(argv[i],"--output") == 0)
		{
			//outfile = argv[++i];
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
	//A_here::File current_file(symbols);
	if(inputs.empty())
	{
		std::cout << "Indique almenos un archivo para compilar.";
		return EXIT_FAILURE;
	}
	/*
	if(outfile.empty())
	{
		std::cout << "Indique el archivo de resultado.";
		return EXIT_FAILURE;
	}
	*/
	//outstream.open(outfile, std::ios_base::out | std::ios_base::binary);

	for(const std::string& f : inputs)
	{

	}


	//outstream.close();
	return EXIT_SUCCESS;
}

