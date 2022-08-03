

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
	Buffer(const std::filesystem::path& file) : base(0)
	{
		if(not std::filesystem::exists(file)) throw Exception(Exception::FILE_TERGET_NOT_FOUND,__FILE__,__LINE__);

		_size = std::filesystem::file_size(file);
		if(_size == 0) return;

		buffer = new T[_size + 1];

		std::ifstream ifs(file, std::ifstream::binary);
		pbuf = ifs.rdbuf();
		pbuf->sgetn (buffer,_size);
	}
	Buffer(const T* string) : base(0)
	{
		_size = length(string);
		buffer = new T[_size + 1];
		copy(string,_size,&buffer);
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
	const T* get_base_string()const
	{
		return &buffer[base];
	}
	T operator[](unsigned int index)const
	{
	#ifdef OCTETOS_CC_FULL_CHECK
		if(index > _size) throw Exception(Exception::INDEX_OUT_OF_RANGE,__FILE__,__LINE__);
	#endif
		
		return buffer[base + index];
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

	/**
	*\brief Si la string indicada es existe coinside con el continedo del buffer el apuntador avanza al final de dicha string
	*
	*/
	const T* walk(const T* string)
	{
		std::uintmax_t lengString = length(string);
		if(lengString == 0) return NULL;

		std::uintmax_t i = 0;
		for(; i < lengString; i++)
		{	
			if(buffer[base + i] == 0) break;//se llego al final sin fallar la verificacion
			if(buffer[base + i] != string[i]) break;		
		}

		if(i < lengString) return NULL;

		base += i;	
		return string;
	}
	T walk(T c)
	{		
		if(buffer[base] == 0) return 0;//se llego al final sin fallar la verificacion
		if(buffer[base] != c) return buffer[base];		

		++base;	
		return c;
	} 
	void walk(size_t i)
	{
		base += i;
	}
	T next_char()
	{		
		if(buffer[base] == 0) return 0;//se llego al final sin fallar la verificacion
		
		return buffer[base++];
	}
	std::uintmax_t consume_whites()
	{
		std::uintmax_t i = 0;
		do
		{
			if(buffer[base + i] == 0) break;
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

	bool empty()const
	{
		return (base >= _size);
	}
private:
	T* buffer;
	std::uintmax_t _size;
	std::ifstream sfile;
	std::filebuf* pbuf;
	std::uintmax_t base;
};


}

#endif