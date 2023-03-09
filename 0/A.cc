


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
}
