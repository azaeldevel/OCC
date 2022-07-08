

#ifndef OCTETOS_CC_BUFFER_HH
#define OCTETOS_CC_BUFFER_HH


/*
 * Copyright (C) 2022 Azael Reyes Martinez. <azael.devel@gmail.com>
 * All rights reserved
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