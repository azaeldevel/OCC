
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

#include <oas-intel-A+.tab.h>
#include <stdarg.h> // va_list.
#include <stdio.h>  // printf.
#include <stdlib.h> // getenv.


#include <iostream>
#include <fstream>
#include "A+.hh"


namespace A_here = oct::cc::v0::A;

A_here::Tokens lexer();

int main (int argc, char* argv[])
{		
	if(argc != 3)
	{
		fprintf(stderr,"Indique el nombre de archivos");
		return EXIT_FAILURE;
	}
	
	std::filesystem::path work_dir = argv[2];
	std::filesystem::path result_file_path = argv[1];
	result_file_path = result_file_path.filename();
	result_file_path = work_dir/result_file_path;
	result_file_path.replace_extension(".asm.lex");
	std::fstream result_file;
    result_file.open(result_file_path, std::ios_base::out|std::ios_base::binary);
	if(!result_file.is_open())
    {
        std::cout << "No se puede abrir '" << result_file_path << "'\n";
        return EXIT_FAILURE;
    }
	
	if(not A_here::current_file.open(argv[1]))
	{
		fprintf(stderr,"Fallo al abrir el archivo %s",argv[1]);
		return EXIT_FAILURE;		
	}	

	A_here::Tokens token;
	do
	{
		token = lexer();
		result_file.write((const char*)&token,sizeof(token));
		//std::cout << (int)token << "\n";
	}

	while((int)token > 0);
	result_file.flush();
	result_file.close();

	/*A_here::Symbol* symbol = A_here::block.next();
	while(symbol)
	{
		std::cout << A_here::to_string(symbol->token) << "\n";

		
		symbol = A_here::block.next();		
	}*/

	return EXIT_SUCCESS;
}
