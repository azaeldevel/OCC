


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





Block::Block() : actual(NULL),index(0)
{
	if(blocks.empty()) return;
	it = blocks.begin();
	actual = (Symbol*)*it;
}

Symbol* Block::next()
{
	std::cout << "Block::next begin\n";
	if(not actual) return NULL;	
	if(index >= page_size)
	{
		//std::cout << "Block::create malloc\n";
		it++;
		actual = (Symbol*)*it;
		index = 0;		
	}
	
	char* newptr = (char*)actual;
	std::cout << "Block::next actual : " << (long)actual << "\n";
	std::cout << "Block::next index : " << index << "\n";
	newptr += index;
	Symbol* obj = (Symbol*)newptr;
	std::cout << "Block::create newptr : " << (long)newptr << "\n";
	//std::cout << "Block::create index : " << index << "\n";
	switch(actual->token)
	{
	case Tokens::identifier:
		//std::cout << "Block::next : identifier\n";
		index += sizeof(Identifier) + 1;
		break;
	case Tokens::LITERAL_INTEGER_DEC:
	case Tokens::LITERAL_INTEGER_HEX:
		//std::cout << "Block::next : LITERAL_INTEGER\n";
		index += sizeof(Integer) + 1;
		std::cout << "Block::create sizeof(T) : " << sizeof(Integer) << "\n";
		break;
	default:
		if (actual->token >= Tokens::AUTO and actual->token <= Tokens::WHILE)
		{
			//std::cout << "Block::next : Symbol\n";
			index += sizeof(Symbol) + 1;
			std::cout << "Block::create sizeof(T) : " << sizeof(Symbol) << "\n";
		}
		else
		{
			//std::cout << "Block::next : char\n";
			index += sizeof(Char) + 1;
			std::cout << "Block::create sizeof(T) : " << sizeof(Char) << "\n";
		}
		break;
	}
	actual = (Symbol*)obj;
	std::cout << "Block::next end\n";
	return obj;
}

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
