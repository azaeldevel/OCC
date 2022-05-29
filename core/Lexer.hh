
#ifndef OCTETOS_CC_LEXER_HH
#define OCTETOS_CC_LEXER_HH

/*
 * Lexer.hh
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

#include <string>


namespace oct::cc
{

struct Tray
{

};

class Lexer
{
public:
	typedef unsigned int Identifier;

	class Token
	{
	public:
		enum class Type
		{
			Unknow,
			Number,
			Identifier,
			Space,
			NewLine,
			Tabulator,
			keyword,
			String,
			Comment,
			Symbol,
		};

		Token(const Buffer&, std::uintmax_t begin, std::uintmax_t end,Type type);
		~Token();

		Identifier get_id()const;
		const char* get_text()const;
		Type get_type()const;
	
	private:
		void copy(const Buffer&, std::uintmax_t begin, std::uintmax_t end);
	private:
		Identifier id;
		char* text;
		Type type;
	};

	
public:
	Lexer(const std::filesystem::path& file);
	~Lexer();

	virtual Token* next();
	
protected:
	static bool is_letter(char);
	static bool is_digit(char);
	static bool is_blank_space(char);
	static bool is_base_prefix(char);
	static bool is_symbol(char);
	
	Token* build(Lexer::Token::Type type);
private:
	Buffer buffer;
	std::uintmax_t begin,end;	
	const Tray* tray;
};


}

#endif