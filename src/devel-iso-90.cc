
/*
 * main.cc
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

#include <iostream>
#include <core/src/Buffer-v3.hh>
#include <core/src/lexer.hh>

namespace core_current = oct::core::v3;
//namespace lex_current = oct::core::v3::lex;

constexpr core_current::lex::TT<char, core_current::lex::Tokens, core_current::lex::Status> create_tt_c_90()
{
	std::vector<char> symbols(91);
	symbols[0] = '0';
	symbols[1] = '1';
	symbols[2] = '2';
	symbols[3] = '3';
	symbols[4] = '4';
	symbols[5] = '5';
	symbols[6] = '6';
	symbols[7] = '7';
	symbols[8] = '8';
	symbols[9] = '9';
	symbols[10] = 'a';
	symbols[11] = 'b';
	symbols[12] = 'c';
	symbols[13] = 'd';
	symbols[14] = 'e';
	symbols[15] = 'f';
	symbols[16] = 'g';
	symbols[17] = 'h';
	symbols[18] = 'i';
	symbols[19] = 'j';
	symbols[20] = 'k';
	symbols[21] = 'l';
	symbols[22] = 'm';
	symbols[23] = 'n';
	symbols[24] = 'o';
	symbols[25] = 'p';
	symbols[26] = 'q';
	symbols[27] = 'r';
	symbols[28] = 's';
	symbols[29] = 't';
	symbols[30] = 'u';
	symbols[31] = 'v';
	symbols[32] = 'w';
	symbols[33] = 'x';
	symbols[34] = 'y';
	symbols[35] = 'z';
	symbols[36] = 'A';
	symbols[37] = 'B';
	symbols[38] = 'C';
	symbols[39] = 'D';
	symbols[40] = 'E';
	symbols[41] = 'F';
	symbols[42] = 'G';
	symbols[43] = 'H';
	symbols[44] = 'I';
	symbols[45] = 'J';
	symbols[46] = 'K';
	symbols[47] = 'L';
	symbols[48] = 'M';
	symbols[49] = 'N';
	symbols[50] = 'O';
	symbols[51] = 'P';
	symbols[52] = 'Q';
	symbols[53] = 'R';
	symbols[54] = 'S';
	symbols[55] = 'T';
	symbols[56] = 'U';
	symbols[57] = 'V';
	symbols[58] = 'W';
	symbols[59] = 'X';
	symbols[60] = 'Y';
	symbols[61] = 'Z';
	symbols[62] = '!';
	symbols[63] = '"';
	symbols[64] = '#';
	symbols[65] = '%';
	symbols[66] = '&';
	symbols[67] = '\'';
	symbols[68] = '(';
	symbols[69] = ')';
	symbols[70] = '*';
	symbols[71] = '+';
	symbols[72] = ',';
	symbols[73] = '-';
	symbols[74] = '.';
	symbols[75] = '/';
	symbols[76] = ':';
	symbols[77] = ';';
	symbols[78] = '<';
	symbols[79] = '=';
	symbols[80] = '>';
	symbols[81] = '?';
	symbols[82] = '[';
	symbols[83] = '\\';
	symbols[84] = ']';
	symbols[85] = '^';
	symbols[86] = '_';
	symbols[87] = '{';
	symbols[88] = '|';
	symbols[89] = '}';
	symbols[90] = '~';

	core_current::lex::TT<char, core_current::lex::Tokens, core_current::lex::Status> c_90(3, symbols);
	


	return c_90;
}

int main()
{
	std::filesystem::path c_90_source_1 = "C:\\Users\\Azael\\Documents\\develop\\octetos\\OCC\\tests\\main-ansi-90.c";
	core_current::Buffer<char> buff1_c_90(c_90_source_1);
	auto tt_c_90 = create_tt_c_90();
	core_current::lex::A lex_c_90(tt_c_90, buff1_c_90);
	core_current::lex::Tokens tk_c_90;

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}
	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}


	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}


	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}


	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}

	tk_c_90 = lex_c_90.next();
	if (int(tk_c_90) < 128)
	{
		std::cout << (char)tk_c_90 << "\n";
	}
	else
	{
		std::cout << "Token : " << int(tk_c_90) << "\n";
	}
	return 0;
}

