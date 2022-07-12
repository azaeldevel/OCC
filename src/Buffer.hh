

#ifndef OCTETOS_CC_BUFFER_HH
#define OCTETOS_CC_BUFFER_HH


/*
 * Copyright (C) 2022 Azael Reyes Martinez. <azael.devel@gmail.com>
 * All rights reserved
 */


#include <filesystem>
#include <list>
#include <fstream>

#include "Exception.hh"

namespace oct::cc
{

/**
*\brief
*
*/
template<typename T>
class Buffer
{
public:
	Buffer(const std::filesystem::path& file) : buffer(NULL)
	{
		if(not std::filesystem::exists(file)) throw Exception(Exception::FILE_TERGET_NOT_FOUND,__FILE__,__LINE__);

		_size = std::filesystem::file_size(file);
		if(_size == 0) return;

		buffer = new T[_size + 1];

		std::ifstream ifs(file, std::ifstream::binary);
		pbuf = ifs.rdbuf();
		pbuf->sgetn (buffer,_size);
		
		//std::cout << "buffer:\n" << buffer << "\n";
	}
	~Buffer()
	{
		if(sfile.is_open()) sfile.close();
		if(buffer) delete[] buffer;
	}

	explicit operator const T*()const
	{
		return buffer;
	}
	T operator[](unsigned int index)const
	{
	#ifdef OCTETOS_CC_FULL_CHECK
		if(index > _size) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
	#endif
		
		return buffer[index];
	}

	std::uintmax_t size() const
	{
		return _size;
	}
	
private:
	T* buffer;
	std::uintmax_t _size;
	std::ifstream sfile;
	std::filebuf* pbuf;
};


}

#endif