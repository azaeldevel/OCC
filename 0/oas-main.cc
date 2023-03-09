
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


void yyerror (yyscan_t scanner, result *res, const char *msg, ...)
{
  (void) scanner;
  va_list args;
  va_start (args, msg);
  vfprintf (stderr, msg, args);
  va_end (args);
  fputc ('\n', stderr);
  res->nerrs += 1;
}

/*
void yyerror (const char  *s)
{
  fprintf (stderr, "%s\n", s);
}
*/

#include <iostream>

int main (int argc, char* argv[])
{
	//std::cout << "Step 1\n";
	//std::list<instance> instances;
	
	if(argc != 2)
	{
		fprintf(stderr,"Indique el nombre de archivo");
		return EXIT_FAILURE;
	}
	//std::cout << "Step 2 " << argv[1] << "\n";
  	result res = {0, 0, 0};
	FILE* file = fopen(argv[1],"r");
    if(!file) 
	{
		std::cout << "Fail to open file : " << argv[1] << "\n";
		return EXIT_FAILURE;
	}
	printf("Reding %s...\n",argv[1]);
	yyscan_t scanner;
  	yylex_init (&scanner);
	YY_BUFFER_STATE buf = yy_create_buffer(file, YY_BUF_SIZE, scanner);
    yy_switch_to_buffer(buf, scanner);
  	yyparse (scanner, &res);
  	yy_delete_buffer (buf, scanner);
  	yylex_destroy (scanner);
  	return EXIT_SUCCESS;
	
}
