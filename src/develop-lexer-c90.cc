
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

#include "C90-v0.hh"

namespace occ_here = oct::cc::v0;


template<typename T>
bool lexing(T& lex)
{
	core_here::lex::TokenDefinition<char> c;
	std::string strtk;
	while (lex.next(actual) != occ_here::c90::Tokens::none)
	{
		strtk.clear();
		strtk.load(strtk);
		std::cout << "Token : " << strtk << "\n";
	}
	
	return true;
}

int main()
{
	std::filesystem::path file1_c90 = "C:\\Users\\Azael\\Documents\\develop\\octetos\\OCC\\tests\\main-ansi-90.c";
	const char* str_c90 = "auto char break switch volatil void int 923456789 5 j juan contianer09 _09containuer ";
	core_next::Buffer<char> buff1_c90(str_c90);
	//auto tt_c90 = create_tt_c90();
	occ_here::c90::TT tt_c90;
	//std::cout << "TT listing...\n";
	//tt_c90.print(std::cout);
	tt_c90.check(std::cout);
	std::cout << "\n";
	core_next::lex::A lex_c90(tt_c90, buff1_c90);

	std::cout << "\n\n";
	occ_here::c90::Tokens tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_auto)
	{
		std::cout << "Fallo, se espera keyword auto, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";
	//std::cout << "TT size : " << tt_c90.size() << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_char)
	{
		std::cout << "Fallo, se espera keywod char, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_break)
	{
		std::cout << "Fallo, se espera keywod break, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_switch)
	{
		std::cout << "Fallo, se espera keywod switch, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_volatil)
	{
		std::cout << "Fallo, se espera keywod volatil, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_void)
	{
		std::cout << "Fallo, se espera keywod void, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_int)
	{
		std::cout << "Fallo, se espera keywod int, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::integer)
	{
		std::cout << "Fallo, se espera integer, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::integer)
	{
		std::cout << "Fallo, se espera integer, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	std::cout << "\n";

	return EXIT_SUCCESS;
}

