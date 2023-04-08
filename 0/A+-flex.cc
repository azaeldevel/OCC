


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

#include <oas-intel-parser-A+.hh>
//#include <oas-intel-A+.tab.h>


#include "A+.hh"



namespace oct::cc::v0::A
{


File::~File()
{
	if(buffer)
	{
		yy_delete_buffer ((YY_BUFFER_STATE)buffer);
		buffer = NULL;
	}
	if(file)
	{
		fclose(file);
		file = NULL;
	}
}



bool File::open(const std::filesystem::path& fn)
{
	if(file) return false;
	if(buffer) return false;
	if(not filename.empty()) return false;
	if(fn.empty()) return false;
	//std::cout << "Loading file " << fn << "..\n";

	filename = fn;
	yyin = fopen(filename.string().c_str(), "r");
	if(not file) return false;
	//std::cout << "Create file " << fn << "..\n";

	buffer = yy_create_buffer(yyin, YY_BUF_SIZE);
    yy_switch_to_buffer((YY_BUFFER_STATE)buffer);

	return true;
}




}
