
/*
 * Buffer.cc
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

#include "Buffer.hh"
#include "Exception.hh"

#include <iostream>
#include <fstream>

namespace oct::cc
{

Buffer::Buffer(const std::filesystem::path& file) : buffer(NULL)
{
	if(not std::filesystem::exists(file)) throw Exception(Exception::FILE_TERGET_NOT_FOUND,__FILE__,__LINE__);

	std::uintmax_t size = std::filesystem::file_size(file);
	if(size == 0) return;

	buffer = new char[size + 1];

	std::ifstream sfile;
	sfile.rdbuf()->pubsetbuf(buffer,size);
	sfile.open (file);
	std::cout << sfile.rdbuf();
}

}