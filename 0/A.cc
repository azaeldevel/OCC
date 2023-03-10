


/*
 * main.cc
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 *
 * Octetos Compiler Collection is free software: you can redistribute it and/or modify it
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


#include "A.hh"



namespace oct::cc::v0::A
{


void add_identifier(int l,const char* f,const char* w, int leng)
{
	//printf("%s:%i %s\n",f,l,w);
	std::string str;
	str.insert(0,w,leng);
	std::cout << f << ":" << l << " " << str << "\n";
}






File::File() : file(NULL),buffer(NULL),scanner(NULL)
{
}
File::~File()
{
	if(buffer)
	{
		yy_delete_buffer ((YY_BUFFER_STATE)buffer, scanner);
		buffer = NULL;
	}
	if(scanner)
	{
		yylex_destroy (scanner);
		scanner = NULL;
	}
	if(file)
	{
		fclose(file);
		file = NULL;
	}
}


void* File::get_scanner()
{
	return scanner;
}

bool File::open(const std::filesystem::path& fn)
{
	if(file) return false;
	if(buffer) return false;
	if(not filename.empty()) return false;
	if(fn.empty()) return false;
	//std::cout << "Loading file " << fn << "..\n";
	
	filename = fn;
	file = fopen(filename.string().c_str(), "r");
	if(not file) return false;
	//std::cout << "Create file " << fn << "..\n";
	
	yylex_init (&scanner);
	//std::cout << "Creating scanner..\n";
	buffer = yy_create_buffer(file, YY_BUF_SIZE, scanner);
    yy_switch_to_buffer((YY_BUFFER_STATE)buffer,(yyscan_t)scanner);
	
	return true;
}

const std::filesystem::path& File::get_filename() const
{
	return filename;
}



}
