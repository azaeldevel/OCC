
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


#include "C90-v0.hh"

namespace occ_here = oct::cc::v0;

int main()
{

	std::cout << "///>>>A section\n\n\n";
	///>>>A
	std::filesystem::path file1_c90 = "C:\\Users\\Azael\\Documents\\develop\\octetos\\OCC\\tests\\main-ansi-90.c";
	//const char* str_c90 = "auto char break switch volatil void int 923456789 5 j a0 aabcd a1_test z juan contianer09 _09cont _09cont % ? #";
	const char* str_c90 = "auto char break switch volatil void int";
	core_next::Buffer<char> buff1_c90(str_c90);
	//constexpr auto tt_c90 = occ_here::c90::create_lexer_a();
	occ_here::c90::TT tt_c90;
	//std::cout << "TT listing...\n";
	//tt_c90.print(std::cout);
	//tt_c90.check(std::cout);
	std::cout << "\n";
	core_next::lex::A lex_c90(tt_c90, buff1_c90);

	std::cout << "\n\n";
	occ_here::c90::Tokens tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_auto)
	{
		std::cout << "Fallo, se espera keyword auto, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "TT size : " << tt_c90.size() << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_char)
	{
		std::cout << "Fallo, se espera keywod char, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_break)
	{
		std::cout << "Fallo, se espera keywod break, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_switch)
	{
		std::cout << "Fallo, se espera keywod switch, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_volatil)
	{
		std::cout << "Fallo, se espera keywod volatil, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_void)
	{
		std::cout << "Fallo, se espera keywod void, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_int)
	{
		std::cout << "Fallo, se espera keywod int, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
/*
	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::integer)
	{
		std::cout << "Fallo, se espera integer, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::integer)
	{
		std::cout << "Fallo, se espera integer, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::identifier)
	{
		std::cout << "Fallo, se espera identifier, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != (occ_here::c90::Tokens)'%')
	{
		std::cout << "Fallo, se espera %, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != (occ_here::c90::Tokens)'?')
	{
		std::cout << "Fallo, se espera %, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "\n";

	tk_c90 = lex_c90.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90.next();
	if (tk_c90 != (occ_here::c90::Tokens)'#')
	{
		std::cout << "Fallo, se espera %, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}*/
	//std::cout << "\n";


	/*auto begin1 = std::chrono::high_resolution_clock::now();
	occ_here::c90::TT tt_c90test[177];
	auto end1 = std::chrono::high_resolution_clock::now();
	auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
	std::cout << "Tiempo : " << elapsed1 << "\n";


	auto begin2 = std::chrono::high_resolution_clock::now();
	std::vector<std::vector<core_here::lex::Transition<occ_here::c90::Tokens, core_here::lex::State>>> tts[177];
	auto end2 = std::chrono::high_resolution_clock::now();
	auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
	std::cout << "Tiempo : " << elapsed2 << "\n";

	constexpr const std::vector<char> symbols {'a','b'};*/


	std::cout << "///>>>B section\n\n\n";
	///>>>B

	constexpr auto ttb = occ_here::c90::create_lexer_b();
	//constexpr const occ_here::c90::TTB ttb;
	/*for(size_t i = 0; i < 99; i++)
	{
		std::cout << ttb.get_symbols()[i] << "\n";
	}*/
	if(ttb.get_last_error() > core_here::lex::errors::none) std::cout << "Error detectado : " << core_here::lex::to_string(ttb.get_last_error()) << "\n";
	std::cout << "Ultimo estado creado : " << ttb.get_state_last() << "\n";
	//ttb.print(std::cout);
	/*for(size_t i = 0; i < ttb.get_amoun_states(); i++)
	{
		for(size_t j = 0; j < ttb.get_amoun_transitions(); j++)
		{
			if(ttb.get(i,j)->next < 0)
			{
			}
			else
			{
				std::cout << i << "--" << j << "-->" << ttb.get(i,j)->next << "\n";
			}
		}
	}*/
	std::filesystem::path file1_c90b = "C:\\Users\\Azael\\Documents\\develop\\octetos\\OCC\\tests\\main-ansi-90.c";
	const char* str_c90b = "auto char break switch volatil void int";
	core_next::Buffer<char> buff1_c90b(str_c90b);
	//constexpr auto tt_c90 = occ_here::c90::create_lexer_a();
	occ_here::c90::TTB tt_c90b;
	//std::cout << "TT listing...\n";
	//tt_c90.print(std::cout);
	//tt_c90.check(std::cout);
	std::cout << "\n";
	core_next::lex::B lex_c90b(tt_c90b, buff1_c90b);

	//std::cout << "\n\n";
	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_auto)
	{
		std::cout << "Fallo, se espera keyword auto, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}
	//std::cout << "TT size : " << tt_c90.size() << "\n";

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_char)
	{
		std::cout << "Fallo, se espera keywod char, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_break)
	{
		std::cout << "Fallo, se espera keywod break, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_switch)
	{
		std::cout << "Fallo, se espera keywod switch, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_volatil)
	{
		std::cout << "Fallo, se espera keywod volatil, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_void)
	{
		std::cout << "Fallo, se espera keywod void, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::space)
	{
		std::cout << "Fallo, se espera space, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}

	tk_c90 = lex_c90b.next();
	if (tk_c90 != occ_here::c90::Tokens::keyword_int)
	{
		std::cout << "Fallo, se espera keywod int, se encontro " << to_string(tk_c90) << " - " << std::to_string((int)tk_c90) << "\n";
	}



	return EXIT_SUCCESS;
}

