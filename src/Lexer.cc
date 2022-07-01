
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
#include "Lexer.hh"

#include <string.h>
#include <iostream>


namespace oct::cc
{

Lexer::Token::Token(const Buffer& buffer, std::uintmax_t begin, std::uintmax_t end,Type t) : type(t), text(NULL)
{
	copy(buffer,begin,end);
	switch(t)
	{
	case Type::Space:
	case Type::NewLine:
	case Type::Tabulator:
		white_space = true;
	default:
		white_space = false;
	}
}
Lexer::Token::~Token()
{
	if(text) delete[] text;
}


Lexer::Identifier Lexer::Token::get_id() const
{
	return id;
}
const char* Lexer::Token::get_text() const
{
	return text;
}
Lexer::Token::Type Lexer::Token::get_type() const
{
	return type;
}
const char * Lexer::Token::get_type_string()const
{
	switch(type)
	{
	case Type::Number:
		return "Number";
	case Type::Identifier:
		return "Identifier";
	case Type::Space:
		return "Space";
	case Type::NewLine:
		return "NewLine";
	case Type::Tabulator:
		return "Tabulator";
	case Type::keyword:
		return "keyword";
	case Type::String:
		return "String";
	case Type::Comment:
		return "Comment";
	case Type::Symbol:
		return "Symbol";
	default:
		return "Unknow";
	}

	return "Unknow";
}
void Lexer::Token::up_type(Type t)
{
	type = t;
}
bool Lexer::Token::get_white_space()const
{
	return white_space;
}

void Lexer::Token::copy(const Buffer& buffer, std::uintmax_t begin, std::uintmax_t end)
{
	if(end < begin) throw Exception(Exception::NEGATIVE_STRING,__FILE__,__LINE__);
	if(end == begin) throw Exception(Exception::NULL_STRING,__FILE__,__LINE__);
	
	std::uintmax_t leng = end - begin;
	text = new char[leng + 1];
	for(std::uintmax_t i = 0; i < leng; i++)
	{
		//|std::cout << " i = " << i << "\n";
		//|std::cout << " c = " << buffer[i] << "\n";
		text[i] = buffer[begin + i];
	}
	text[leng] = 0;
}









Lexer::Lexer(const std::filesystem::path& f,const Tray& t) : buffer(f), begin(0), end(1), tray(&t)
{
}

Lexer::~Lexer()
{
}

std::vector<Lexer::Token*>& Lexer::get_tokens()
{
	return tokens;
}


Lexer::Token* Lexer::build(Lexer::Token::Type type)
{
	/*
	std::cout << "Lexer::build() - 1\n";
	std::cout << "\tbegin = " << begin << "\n";
	std::cout << "\tend = " << end << "\n";
	std::cout << "\tsize = " << buffer.size() << "\n";
	*/
	
	Lexer::Token* tok = new Lexer::Token(buffer,begin,end,type);	
	begin = end;
	++end;
	
	/*
	std::cout << "Lexer::build() - 2\n";
	std::cout << "\tbegin = " << begin << "\n";
	std::cout << "\tend = " << end << "\n";
	std::cout << "\tsize = " << buffer.size() << "\n";
	*/
	
	return tok;
}
Lexer::Token* Lexer::next()
{
	//if(begin != end) throw Exception(Exception::DESSYNCHRONIZATION_BUFEER_SENTINEL,__FILE__,__LINE__);
	if(end >= buffer.size()) return NULL;

	/*
	std::cout << "Lexer::next()\n";
	std::cout << "\tbegin = " << begin << "\n";
	std::cout << "\tend = " << end << "\n";
	std::cout << "\tsize = " << buffer.size() << "\n";
	std::cout << "\tbuffer[begin] = " << buffer[begin] << "\n";
	*/
	
	//spacies
	if(buffer[begin] == ' ')
	{
		while(buffer[end] == ' ' and end < buffer.size()) end++;
		if(buffer[end] == 0) end--;
		//std::cout << "Creating Space\n";
		return build(Lexer::Token::Type::Space);
	}
	else if(buffer[begin] == '\n')
	{
		while(buffer[end] == '\n' and end < buffer.size()) end++;
		if(buffer[end] == 0) end--;
		//std::cout << "Creating NewLine\n";
		return build(Lexer::Token::Type::NewLine);
	}	
	else if(buffer[begin] == '\t')
	{
		while(buffer[end] == '\t' and end < buffer.size()) end++;
		if(buffer[end] == 0) end--;
		//std::cout << "Creating Tabulador\n";
		return build(Lexer::Token::Type::Tabulator);
	}

	//
	if(is_symbol(buffer[begin]) and end < buffer.size())
	{
		//std::cout << "Creating Symbol\n";
		return build(Lexer::Token::Type::Symbol);
	}


	//number
	if(is_digit(buffer[begin]))
	{
		while(is_digit(buffer[end]) and end < buffer.size()) end++;
		if(buffer[end] == 0) end--;
		//std::cout << "Creating Number\n";
		return build(Lexer::Token::Type::Number);
	}

	//identifier
	/*if(is_letter(buffer[begin]))
	{
		while((is_letter(buffer[end]) or is_digit(buffer[end])) and end < buffer.size()) end++;
		if(buffer[end] == 0) end--;		
		//std::cout << "Creating Identifier\n";
		return build(Lexer::Token::Type::Identifier);
	}*/

	//String
	if(buffer[begin] == '"')
	{
		while(buffer[begin] != '"' and end < buffer.size()) end++;
		if(buffer[end] == 0) end--;
		//std::cout << "Creating String\n";
		return build(Lexer::Token::Type::String);
	}

	//Comment	
	if(buffer[begin] == '/' and buffer[begin + 1] == '/')
	{
		while(buffer[end] != '\n' and end < buffer.size()) end++;
		if(buffer[end] == 0) end--;
		//std::cout << "Creating String\n";
		return build(Lexer::Token::Type::Comment);
	}
	else if(buffer[begin] == '/' and buffer[begin + 1] == '*')
	{
		while(buffer[end] == '*' and buffer[end + 1] == '/' and  end < buffer.size()) end++;
		if(buffer[end] == 0) end--;
		//std::cout << "Creating String\n";
		return build(Lexer::Token::Type::Comment);
	}	
	
	//Desconocido
	if(buffer[begin] != 0)
	{
		while(buffer[end] != 0 and not is_blank_space(buffer[end]) and not is_symbol (buffer[end]) and end < buffer.size()) end++;
		if(buffer[end] == 0) end--;
		return build(Lexer::Token::Type::Unknow);
	}
	
	if(begin != end) throw Exception(Exception::UNCLASIFIED,__FILE__,__LINE__);

	return NULL;
}

bool Lexer::is_letter(char c)
{
	if( c >= 65 and c <= 90) return true;//mayusculas
	else if( c >= 97 and c <= 122) return true;//minusculas
	return false;
}
bool Lexer::is_digit(char c)
{
	if( c >= 48 and c <= 57) return true;
	return false;
}
bool Lexer::is_blank_space(char c)
{
	switch(c)
	{
		case ' ': 
		case '\n':
		case '\t':
			return true;
	}

	return false;
}
bool Lexer::is_base_prefix(char c)
{
	switch(c)
	{
		case 'B':
		case '0':
		case 'D':
		case 'H':
		case 'O':
			return true;
	}

	return false;
}
bool Lexer::is_symbol(char c)
{
	switch(c)
	{
		case ':':
		case '#':
		case '@':
		case '(':
		case ')':
		case ';':
		case '&':
		case ',':
			return true;
	}

	return false;
}




namespace A
{

	
Lexer::Lexer(const std::filesystem::path& f,const Tray& t) : oct::cc::Lexer(f,t)
{
	
}
Lexer::~Lexer()
{
}
Lexer::Token* Lexer::next()
{
	//
	
	//
	if(buffer[begin] == '#' and is_base_prefix(buffer[begin + 1]) and buffer[begin + 2] == 'x') //es numero con base especificada
	{
		end += 3;
		while(is_digit(buffer[end]) and end < buffer.size()) end++;
		if(buffer[end] == 0) end--;
		
		return build(Lexer::Token::Type::Number);
	}
	
	return oct::cc::Lexer::next();
}

bool Lexer::load()
{
	count_toks = 0;
	Token* token = next();
	while(token)
	{
		count_toks++;
		tokens.push_back(token);
		
		token = next();
	}

	tokens.resize(count_toks);
	
	return true;
}



}
}