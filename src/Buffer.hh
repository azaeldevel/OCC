

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
#include "base.hh"


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
	Buffer(const std::filesystem::path& file) : buffer(NULL),base(0),auto_delete_buffer(0)
	{
		if(not std::filesystem::exists(file)) throw Exception(Exception::FILE_TERGET_NOT_FOUND,__FILE__,__LINE__);

		_size = std::filesystem::file_size(file);
		if(_size == 0) return;

		buffer = new T[_size + 1];

		std::ifstream ifs(file, std::ifstream::binary);
		pbuf = ifs.rdbuf();
		pbuf->sgetn (buffer,_size);
	}
	Buffer(const T* string) : buffer(string),base(0),auto_delete_buffer(0)
	{
	}
	~Buffer()
	{
		if(sfile.is_open()) sfile.close();
		if(auto_delete_buffer)if(buffer) delete[] buffer;
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


	/*bool thereis(const T* initial)
	{
		std::uintmax_t lengInitial = length(initial);
		if(lengInitial == 0) return false;

		for(std::uintmax_t i = 0; i < lengInitial; i++)
		{	
			if(buffer[i] == '\0') return true;//se llego al final sin fallar la verificacion
			if(initial[i] != buffer[i]) return false;		
		}
	
		return true;
	}*/

	const T* walk(const T* string)
	{
		std::uintmax_t lengString = length(string);
		if(lengString == 0) return NULL;

		std::uintmax_t i = 0;
		for(; i < lengString; i++)
		{	
			if(buffer[base + i] == '\0') break;//se llego al final sin fallar la verificacion
			if(buffer[base + i] != string[i]) break;		
		}

		if(i < lengString) return NULL;

		base += i;	
		return &buffer[base];
	}
	const T* walk(T c)
	{
		
		if(buffer[base] == '\0') return NULL;//se llego al final sin fallar la verificacion
		if(buffer[base] != c) return NULL;		

		++base;	
		return &buffer[base];
	}
	std::uintmax_t consume_whites()
	{
		std::uintmax_t i = 0;
		do
		{
			if(buffer[base + i] == '\0') break;
			else if(is_whitespace(buffer[base + i])) i++;
			else break;
		}
		while(true);

		base += i;
		return i;
	}
	
	std::uintmax_t get_base()const
	{
		return base;
	}

	T get_actual()const
	{
		return buffer[base];
	}
private:
	const T* buffer;
	std::uintmax_t _size;
	std::ifstream sfile;
	std::filebuf* pbuf;
	std::uintmax_t base;
	bool auto_delete_buffer;
};


}

#endif