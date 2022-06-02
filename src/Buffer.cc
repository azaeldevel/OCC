
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


namespace oct::cc
{

Buffer::Buffer(const std::filesystem::path& file) : buffer(NULL)
{
	if(not std::filesystem::exists(file)) throw Exception(Exception::FILE_TERGET_NOT_FOUND,__FILE__,__LINE__);

	_size = std::filesystem::file_size(file);
	if(_size == 0) return;

	buffer = new symbol[_size + 1];

	std::ifstream ifs(file, std::ifstream::binary);
	pbuf = ifs.rdbuf();
	pbuf->sgetn (buffer,_size);
	
	//std::cout << "buffer:\n" << buffer << "\n";
}

Buffer::~Buffer()
{
	if(sfile.is_open()) sfile.close();
	if(buffer) delete[] buffer;
}

Buffer::operator const symbol*()const
{
	return buffer;
}
symbol Buffer::operator[](unsigned int index)const
{
#ifdef OCTETOS_CC_FULL_CHECK
	if(index > _size) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
#endif
	
	return buffer[index];
}
std::uintmax_t Buffer::size() const
{
	return _size;
}

}