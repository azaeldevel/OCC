
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
#include <oas-intel-A+.tab.h>
#include <stdarg.h> // va_list.
#include <stdio.h>  // printf.
#include <stdlib.h> // getenv.


#include <iostream>
#include <fstream>
#include "A+.hh"


namespace A_here = oct::cc::v0::A;

//A_here::Tokens lexer();

int main (int argc, char* argv[])
{		
	if(argc < 2)
	{
		fprintf(stderr,"Indique el nombre de archivos");
		return EXIT_FAILURE;
	}

	
	A_here::SymbolTable symbols;
	A_here::File current_file(symbols);		
	if(not current_file.open(argv[1]))
	{
		fprintf(stderr,"Fallo al abrir el archivo %s",argv[1]);
		return EXIT_FAILURE;		
	}
	
	result res = {0, 0, 0};
	yyparse(current_file.get_scanner(),&res,&symbols);
	
	
	for(const A_here::identifier* id : symbols)
	{
		std::cout << id->number << " " << id->name << " " << "\n";
	}
	//std::cout << "ID : " << (int)A_here::Tokens::AUTO << "\n";
	

	return EXIT_SUCCESS;
}

