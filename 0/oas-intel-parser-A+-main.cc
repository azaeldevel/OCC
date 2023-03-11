
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


/*void yyerror (yyscan_t scanner, result *res, const char *msg, ...)
{
  (void) scanner;
  va_list args;
  va_start (args, msg);
  vfprintf (stderr, msg, args);
  va_end (args);
  fputc ('\n', stderr);
  res->nerrs += 1;
}*/


#include <iostream>
#include <fstream>
#include "A+.hh"
namespace A_here = oct::cc::v0::A;
static std::ifstream infile;

yytoken_kind_t yylex()
{
	yytoken_kind_t token;
	infile.read((char*)&token,sizeof(token));
	return token;
}

int main (int argc, char* argv[])
{
	//std::cout << "Step 1\n";
		
	if(argc != 2)
	{
		std::cerr << "La cantiad de parametros no es correcta\n";
		return EXIT_FAILURE;
	}
	
	std::filesystem::path infile_path = argv[1];	
    infile.open(infile_path, std::ios_base::in|std::ios_base::binary);
	if(!infile.is_open())
    {
        std::cout << "No se puede abrir '" << infile_path << "'\n";
        return EXIT_FAILURE;
    }

	/*
	yytoken_kind_t token;
	YYSTYPE yylval;	
	do
	{
		token = yylex();
		std::cout << token << "\n";
	}
	while(token > 0);
	*/
	yyparse();

	return EXIT_SUCCESS;
}
