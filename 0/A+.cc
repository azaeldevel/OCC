


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
#include <oas-intel-A+.tab.h>
#include <limits>
#include <core/3/Exception.hh>

#include "A+.hh"



namespace oct::cc::v0::A
{


void add_identifier(int l,const char* f,const char* w, int leng)
{
	//printf("%s:%i %s\n",f,l,w);
	std::string str;
	str.insert(0,w,leng);
	std::cout << f << ":" << l << " " << str << "\n";
}






File::File() : file(NULL),buffer(NULL)
{
}

FILE* File::get_file()
{
	return file;
}


const std::filesystem::path& File::get_filename() const
{
	return filename;
}





Block::Block() : actual(NULL)
{
	if(blocks.empty()) return;
	it = blocks.begin();
	actual = (Symbol*)*it;
}

/*Symbol* Block::next()
{
	if(not actual) return NULL;
	Symbol* prev = actual;
	size_t index;
	
	char* obj = (char*)actual;	
	std::cout << "Block::next actual : " << (long)actual << "\n";
	switch(actual->token)
	{
	case Tokens::identifier:
		//std::cout << "Block::next : identifier\n";
		index = sizeof(Identifier) + 1;
		obj += index;
		break;
	case Tokens::LITERAL_INTEGER_DEC:
	case Tokens::LITERAL_INTEGER_HEX:
		//std::cout << "Block::next : LITERAL_INTEGER\n";
		obj += sizeof(Integer) + 1;
		break;
	default:
		if (actual->token >= Tokens::AUTO and actual->token <= Tokens::WHILE)
		{
			//std::cout << "Block::next : Symbol\n";
			obj += sizeof(Symbol) + 1;
		}
		else
		{
			//std::cout << "Block::next : char\n";
			obj += sizeof(Char) + 1;
		}			
		break;
	}
	actual = (Symbol*)obj;
	std::cout << "Block::next index : " << index << "\n";	
	
	return prev;
}*/

Tokens Integer::reduced_token() const
{
	//std::cout << "reduced_token : step 1 " << number << "\n";
	if(0 > number)
	{
		if(std::numeric_limits<signed char>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_SCHAR;
		else if(std::numeric_limits<short>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_SHORT;
		else if(std::numeric_limits<int>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_INT;
		else if(std::numeric_limits<long>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_LONG;
		else if(std::numeric_limits<long long>::min()  < number) return Tokens::LITERAL_INTEGER_DEC_LONGLONG;	
	}
	else
	{
		if(std::numeric_limits<unsigned char>::max() > number) return Tokens::LITERAL_INTEGER_DEC_UCHAR;
		else if(std::numeric_limits<unsigned short>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_USHORT;
		else if(std::numeric_limits<unsigned int>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_UINT;
		else if(std::numeric_limits<unsigned long>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_ULONG;
		else if(std::numeric_limits<unsigned long long>::max()  > number) return Tokens::LITERAL_INTEGER_DEC_ULONGLONG;		
	}
	
	return Tokens::LITERAL_INTEGER_DEC_LONGLONG;
}


}
