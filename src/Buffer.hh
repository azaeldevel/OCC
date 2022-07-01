

#ifndef OCTETOS_CC_BUFFER_HH
#define OCTETOS_CC_BUFFER_HH


/*
 * Buffer.hh
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 * 
 * CC is free software: you can redistribute it and/or modify it
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

#include <filesystem>
#include <list>
#include <fstream>

namespace oct::cc
{

typedef char Char;
/**
*\brief
*
*/
class Buffer
{
public:
	Buffer(const std::filesystem::path& file);
	~Buffer();

	explicit operator const Char*()const;
	char operator[](unsigned int)const;

	std::uintmax_t size() const;
	
private:
	Char* buffer;
	std::uintmax_t _size;
	std::ifstream sfile;
	std::filebuf* pbuf;
};


}

#endif