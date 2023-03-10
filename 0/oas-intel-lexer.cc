
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

#include <oas-intel-parser.hh>
#include <oas-intel.tab.h>
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

/*
void yyerror (const char  *s)
{
  fprintf (stderr, "%s\n", s);
}
*/

#include <iostream>
#include "A.hh"


namespace A_here = oct::cc::v0::A;

int main (int argc, char* argv[])
{
	//std::cout << "Step 1\n";
		
	if(argc != 2)
	{
		fprintf(stderr,"Indique el nombre de archivo");
		return EXIT_FAILURE;
	}
	
	result res = {0, 0, 0};
	if(not A_here::current_file.open(argv[1]))
	{
		fprintf(stderr,"Fallo al abrir el archivo %s",argv[1]);
		return EXIT_FAILURE;		
	}

	int token = -1;
	YYSTYPE yylval;
	yyscan_t scanner = (yyscan_t)A_here::current_file.get_scanner();
	do
	{
		token = yylex(&yylval,A_here::current_file.get_scanner(), &res);
		std::cout << token << "\n";
	}
	while(token > 0);

	return EXIT_SUCCESS;
}
