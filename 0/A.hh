
#ifndef OCTETOS_CC_A_HH
#define OCTETOS_CC_A_HH


/*
 * main.cc
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 *
 * Octetos Compuler Collection is free software: you can redistribute it and/or modify it
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

#include <iostream>
#include <string>
#include <stdio.h>
#include <filesystem>



namespace oct::cc::v0::A
{
//namespace core_here = oct::core::v3;
void add_identifier(int line,const char* filename,const char* word, int leng);

class File
{
public:
	File();
	~File();

	void* get_scanner();

	const std::filesystem::path& get_filename()const;
	bool open(const std::filesystem::path& file);
protected:
	
private:
	FILE* file;
	std::filesystem::path filename;
	void* buffer;
	void* scanner;
};


class SymbolTable
{
public:

	 int add(int line, const char filename,char* string, size_t leng);
	 
protected:

private:
	 
};

struct Token
{
	int number;
	std::string text;
};


extern File current_file;
}


#endif