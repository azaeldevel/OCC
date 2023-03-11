
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
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    ENDOFFILE = 0,                 /* "end-of-file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    keyword_byte = 258,            /* keyword_byte  */
    keyword_char = 259,            /* keyword_char  */
    keyword_short = 260,           /* keyword_short  */
    keyword_int = 261,             /* keyword_int  */
    keyword_long = 262,            /* keyword_long  */
    keyword_mov = 263,             /* keyword_mov  */
    keyword_al = 264,              /* keyword_al  */
    keyword_ah = 265,              /* keyword_ah  */
    IDENTIFIER = 266,              /* IDENTIFIER  */
    LITERAL_INTEGER_DEC = 267,     /* LITERAL_INTEGER_DEC  */
    LITERAL_INTEGER_HEX = 268,     /* LITERAL_INTEGER_HEX  */
    LITERAL_CHAR = 269             /* LITERAL_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
yytoken_kind_t lexer();

int main (int argc, char* argv[])
{
	//std::cout << "Step 1\n";
		
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

	int token = -1;
	do
	{
		token = lexer();
		result_file.write((const char*)&token,sizeof(token));
		std::cout << token << "\n";
	}
	while(token > 0);
	result_file.flush();
	result_file.close();

	return EXIT_SUCCESS;
}
