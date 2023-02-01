
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

enum class Tokens_C90 : int
{//https://www.charset.org/utf-8,https://www.asciitable.com/,https://www.rapidtables.com/code/text/ascii-table.html
	none = -1,
	//ASCII>>>
	NUL = 0,
	SOH,
	STX,
	ETX,
	EOT,
	ENQ,
	ACK,
	BEL,
	BS,
	TAB,
	LF,
	VT,
	FF,
	CR,
	SO,
	SI,
	DLE,
	DC1,
	DC2,
	DC3,
	DC4,
	NAK,
	SYN,
	ETB,
	CAN,
	EM,
	SUB,
	ESC,
	FS,
	GS,
	RS,
	US = 31,
	space,
	exclamation_mark,
	double_quote,
	symbol_numbers,
	symbol_money,
	percen,
	ampersan,
	single_quote,
	parenthesis_open,
	parenthesis_close,
	asterisk,
	plus,
	minus,
	dot,
	symbol_diagonal,
	digit_0 = 48,
	digit_1,
	digit_2,
	digit_3,
	digit_4,
	digit_5,
	digit_6,
	digit_7,
	digit_8,
	digit_9,
	symbol_column,
	semicolumn,
	less,
	equal,
	grater,
	question,
	arroba,
	//>>upper case
	char_A = 65,
	char_B,
	char_C,
	char_D,
	char_E,
	char_F,
	char_G,
	char_H,
	char_I,
	char_J,
	char_K,
	char_L,
	char_M,
	char_N,
	char_O,
	char_P,
	char_Q,
	char_R,
	char_S,
	char_T,
	char_U,
	char_V,
	char_W,
	char_X,
	char_Y,
	char_Z,
	//>>

	//>>>
	char_a = 97,
	char_b,
	char_c,
	char_d,
	char_e,
	char_f,
	char_g,
	char_h,
	char_i,
	char_j,
	char_k,
	char_l,
	char_m,
	char_n,
	char_o,
	char_p,
	char_q,
	char_r,
	char_s,
	char_t,
	char_u,
	char_v,
	char_w,
	char_x,
	char_y,
	char_z,

	EuroSign = 218,
	//>>>Extended ASCII






	y_Diaeresis = 255,//ÿ
	//>>>UTF-8
	a_Macron = 256,

	s_Coptic = 999,
	//Inicode >>>


	//>>>Tokens
	tokens = 0x110000,
	keyword_int

};
constexpr size_t initial_lex_c_90 = 0;
constexpr size_t keyword_i_c_90 = 1;
constexpr size_t keyword_in_c_90 = 2;
constexpr size_t keyword_int_prefix_c_90 = 3;
constexpr size_t max_status_c_90 = 4;

constexpr std::array digits {'0','1','2','3','4','5','6','7','8','9'};
constexpr std::array lower = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','y','z'};
constexpr std::array upper = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','Y','Z'};
constexpr std::array graphic = { '!','"','#','%','%','\'','(',')','*','+',',','-','.','/',':',';','<','=','>','?','[','\\',']','^','_','{','|','}','~'};
constexpr std::array display = { '\a','\b','\f','\n','\r','\t','\v'};
constexpr std::array not_c = {' '};

typedef core_current::lex::TT<char, Tokens_C90, core_current::lex::Status> LexC90;
constexpr bool create_tt_c_90_whitespaces(LexC90& tt)
{
	tt.symbol(initial_lex_c_90, Tokens_C90::space, initial_lex_c_90, ' ');
	tt.symbol(initial_lex_c_90, Tokens_C90::CR, initial_lex_c_90, '\n');

	return true;
}
constexpr bool create_tt_c_90_keywords(LexC90& tt)
{
	tt.symbol(initial_lex_c_90, Tokens_C90::none, keyword_i_c_90, 'i');
	tt.symbol(keyword_i_c_90, Tokens_C90::none, keyword_in_c_90, 'n');
	auto t = tt.prefix(keyword_in_c_90, Tokens_C90::keyword_int, keyword_int_prefix_c_90, 't');
	//>>>
	for (char c : graphic)
	{
		tt.at(keyword_int_prefix_c_90)[c].next = initial_lex_c_90;
		tt.at(keyword_int_prefix_c_90)[c].token = Tokens_C90::none;
		tt.at(keyword_int_prefix_c_90)[c].indicator = core_current::lex::Indicator::accept;
	}
	//>>>
	for (char c : display)
	{
		tt.at(keyword_int_prefix_c_90)[c].next = initial_lex_c_90;
		tt.at(keyword_int_prefix_c_90)[c].token = Tokens_C90::none;
		tt.at(keyword_int_prefix_c_90)[c].indicator = core_current::lex::Indicator::accept;
	}
	//>>> ' '
	tt.at(keyword_int_prefix_c_90)[' '].next = initial_lex_c_90;
	tt.at(keyword_int_prefix_c_90)[' '].token = Tokens_C90::none;
	tt.at(keyword_int_prefix_c_90)[' '].indicator = core_current::lex::Indicator::accept;

	return true;
}
constexpr LexC90 create_tt_c_90()
{
	std::vector<char> symbols;
	for (char c : digits)
	{
		symbols.push_back(c);
	}
	for (char c : lower)
	{
		symbols.push_back(c);
	}
	for (char c : upper)
	{
		symbols.push_back(c);
	}
	for (char c : graphic)
	{
		symbols.push_back(c);
	}
	for (char c : display)
	{
		symbols.push_back(c);
	}
	/*for (char c : not_c)
	{
		symbols.push_back(c);
	}*/
	
	//std::cout << "Size : " << symbols.size() << "\n";

	LexC90 c_90(max_status_c_90, symbols);
	create_tt_c_90_whitespaces(c_90);
	create_tt_c_90_keywords(c_90);


	return c_90;
}

int main()
{
	std::filesystem::path c_90_source_1 = "C:\\Users\\Azael\\Documents\\develop\\octetos\\OCC\\tests\\main-ansi-90.c";
	core_current::Buffer<char> buff1_c_90(c_90_source_1);
	auto tt_c_90 = create_tt_c_90();
	core_current::lex::A lex_c_90(tt_c_90, buff1_c_90);
	Tokens_C90 tk_c_90;

	std::cout << "\n";
	if ((int)core_current::lex::Tokens::CR == 12)
	{
		std::cout << "Fallo Codigo de Token : " << int(Tokens_C90::CR) << " deveria ser 12" << "\n";
	}

	std::cout << "\n";
	tk_c_90 = lex_c_90.next();
	if (Tokens_C90::CR != tk_c_90)
	{
		std::cout << "Fallo Token : " << int(tk_c_90) << "\n";
	}

	std::cout << "\n";
	tk_c_90 = lex_c_90.next();
	if (Tokens_C90::CR != tk_c_90)
	{
		std::cout << "Fallo Token : " << int(tk_c_90) << "\n";
	}

	std::cout << "\n";
	tk_c_90 = lex_c_90.next();
	if (Tokens_C90::keyword_int != tk_c_90)
	{
		std::cout << "Fallo Token : " << int(tk_c_90) << "\n";
	}

	std::cout << "\n";
	tk_c_90 = lex_c_90.next();
	if (Tokens_C90::space != tk_c_90)
	{
		std::cout << "Fallo Token : " << int(tk_c_90) << "\n";
	}





	return 0;
}

