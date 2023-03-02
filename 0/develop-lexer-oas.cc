
/*
 * develop-lexer-c90.cc
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

#include <chrono>
#include <algorithm>
#include <iterator>

#include "OAS.hh"

namespace occ_here = oct::cc::v0;

int main()
{
	std::filesystem::path file1_as = "C:\\Users\\Azael\\Documents\\develop\\octetos\\OCC\\tests\\main-ansi-90.c";
	const char* str_as = "byte short integer tiny long char int mov 923456789 5 j a0 aabcd a1_test z juan contianer09 _09cont _09cont % ? # inta main()";
	core_here::Buffer<char> buff1_as(str_as);
    core_here::lex::Tokenized<char,occ_here::as::Tokens> tkzed;
	constexpr const occ_here::as::TTB tt_as;
	std::string strtk;
	core_here::lex::Lexer<char,occ_here::as::Tokens,core_here::lex::State,occ_here::as::TTB_BASE> lex_as(tt_as, buff1_as);
	//std::cout << "\n\n";
	occ_here::as::Tokens tk_as = lex_as.next(tkzed);
	if (tk_as != occ_here::as::Tokens::keyword_byte)
	{
		std::cout << "Fallo, se espera keyword auto, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	if(lex_as.get_string_length() != 4)
    {
        std::cout << "Tamano del es tring es incorrecto se peseraba 4\n";
    }
    strtk = (std::string)tkzed;
    std::cout << strtk << "\n";
	std::cout << "\n";

	tk_as = lex_as.next();
	if (tk_as != occ_here::as::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	std::cout << "\n";

	tk_as = lex_as.next(tkzed);
	if (tk_as != occ_here::as::Tokens::keyword_short)
	{
		std::cout << "Fallo, se espera keyword short, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	if(lex_as.get_string_length() != 5)
    {
        std::cout << "Tamano del es tring es incorrecto se peseraba 5\n";
    }
    strtk = (std::string)tkzed;
    std::cout << "'" << strtk << "'\n";
	std::cout << "\n";

	tk_as = lex_as.next();
	if (tk_as != occ_here::as::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	std::cout << "\n";

	tk_as = lex_as.next(tkzed);
	if (tk_as != occ_here::as::Tokens::keyword_integer)
	{
		std::cout << "Fallo, se espera keyword short, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	if(lex_as.get_string_length() != 7)
    {
        std::cout << "Tamano del es tring es incorrecto se esperaba 7\n";
    }
    strtk = (std::string)tkzed;
    std::cout << "'" << strtk << "'\n";
	std::cout << "\n";

	tk_as = lex_as.next();
	if (tk_as != occ_here::as::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	std::cout << "\n";

	tk_as = lex_as.next(tkzed);
	if (tk_as != occ_here::as::Tokens::keyword_tiny)
	{
		std::cout << "Fallo, se espera keyword short, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	if(lex_as.get_string_length() != 4)
    {
        std::cout << "Tamano del es tring es incorrecto se esperaba 4\n";
    }
    strtk = (std::string)tkzed;
    std::cout << "'" << strtk << "'\n";
	std::cout << "\n";

	tk_as = lex_as.next();
	if (tk_as != occ_here::as::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	std::cout << "\n";

	tk_as = lex_as.next(tkzed);
	if (tk_as != occ_here::as::Tokens::keyword_long)
	{
		std::cout << "Fallo, se espera keyword long, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	if(lex_as.get_string_length() != 4)
    {
        std::cout << "Tamano del es tring es incorrecto se esperaba 7\n";
    }
    strtk = (std::string)tkzed;
    std::cout << "'" << strtk << "'\n";
	std::cout << "\n";

	tk_as = lex_as.next();
	if (tk_as != occ_here::as::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	std::cout << "\n";

	tk_as = lex_as.next(tkzed);
	if (tk_as != occ_here::as::Tokens::keyword_char)
	{
		std::cout << "Fallo, se espera keyword short, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	if(lex_as.get_string_length() != 4)
    {
        std::cout << "Tamano del es tring es incorrecto se esperaba 4\n";
    }
    strtk = (std::string)tkzed;
    std::cout << "'" << strtk << "'\n";
	std::cout << "\n";

	tk_as = lex_as.next();
	if (tk_as != occ_here::as::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	std::cout << "\n";

	tk_as = lex_as.next(tkzed);
	if (tk_as != occ_here::as::Tokens::keyword_int)
	{
		std::cout << "Fallo, se espera keyword mov, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	if(lex_as.get_string_length() != 3)
    {
        std::cout << "Tamano del es tring es incorrecto se esperaba 3\n";
    }
    strtk = (std::string)tkzed;
    std::cout << "'" << strtk << "'\n";
	std::cout << "\n";

	tk_as = lex_as.next();
	if (tk_as != occ_here::as::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	std::cout << "\n";

	tk_as = lex_as.next(tkzed);
	if (tk_as != occ_here::as::Tokens::keyword_mov)
	{
		std::cout << "Fallo, se espera keyword int, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	if(lex_as.get_string_length() != 3)
    {
        std::cout << "Tamano del es tring es incorrecto se esperaba 7\n";
    }
    strtk = (std::string)tkzed;
    std::cout << "'" << strtk << "'\n";
	std::cout << "\n";

	tk_as = lex_as.next();
	if (tk_as != occ_here::as::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << std::to_string((int)tk_as) << "\n";
	}
	std::cout << "\n";

	return EXIT_SUCCESS;
}

