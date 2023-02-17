
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
#include <array>
#include <vector>

#include <core/src/Buffer-v3.hh>
#include <core/src/lexer-v3.hh>

namespace oct::cc::v0::c90
{
	namespace core_here = oct::core::v3;
	enum class Tokens : int
	{//https://www.charset.org/utf-8,https://www.asciitable.com/,https://www.rapidtables.com/code/text/ascii-table.html
		command = -100,
		eoi,//end of input
		none,
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






		y_Diaeresis = 255,//�
		//>>>UTF-8
		a_Macron = 256,

		s_Coptic = 999,
		//Inicode >>>


		//>>>Tokens
		tokens = 0x110000,
		new_line,
		keyword_auto,
		keyword_break,
		keyword_case,
		keyword_char,
		keyword_const,
		keyword_continue,
		keyword_default,
		keyword_do,
		keyword_double,
		keyword_else,
		keyword_enum,
		keyword_extern,
		keyword_float,
		keyword_for,
		keyword_goto,
		keyword_if,
		keyword_int,
		keyword_long,
		keyword_register,
		keyword_return,
		keyword_short,
		keyword_signed,
		keyword_sizeof,
		keyword_static,
		keyword_struct,
		keyword_switch,
		keyword_typedef,
		keyword_union,
		keyword_unsigned,
		keyword_void,
		keyword_volatil,
		keyword_while,
		identifier,
		integer,

	};
	template<typename Token> std::string to_string(Token t)
	{
		std::string str;

		if (t < Token::tokens)
		{
			return core_next::lex::to_string(t);
		}
		else if (t > Token::tokens)
		{
			if (t > Token::keyword_auto)
			{
				return "keyword auto";
			}
			else if (t > Token::keyword_break)
			{
				return "keyword break";
			}
			else if (t > Token::keyword_case)
			{
				return "keyword case";
			}
		}

		return std::to_string((int)t);
	}


	const std::vector<core_here::lex::pair_keyword<char, Tokens>> keywords = {
		{"auto",Tokens::keyword_auto},
		{"break",Tokens::keyword_break},
		{"case",Tokens::keyword_case},
		{"char",Tokens::keyword_char},
		{"const",Tokens::keyword_const},
		{"continue",Tokens::keyword_continue},
		{"default",Tokens::keyword_default},
		{"do",Tokens::keyword_do},
		{"double",Tokens::keyword_double},
		{"else",Tokens::keyword_else},
		{"enum",Tokens::keyword_enum},
		{"extern",Tokens::keyword_extern},
		{"float",Tokens::keyword_float},
		{"for",Tokens::keyword_for},
		{"goto",Tokens::keyword_goto},
		{"if",Tokens::keyword_if},
		{"int",Tokens::keyword_int},
		{"long",Tokens::keyword_long},
		{"register",Tokens::keyword_register},
		{"return",Tokens::keyword_return},
		{"short",Tokens::keyword_short},
		{"signed",Tokens::keyword_signed},
		{"sizeof",Tokens::keyword_sizeof},
		{"static",Tokens::keyword_static},
		{"struct",Tokens::keyword_struct},
		{"switch",Tokens::keyword_switch},
		{"typedef",Tokens::keyword_typedef},
		{"union",Tokens::keyword_union},
		{"unsigned",Tokens::keyword_unsigned},
		{"void",Tokens::keyword_void},
		{"volatil",Tokens::keyword_volatil},
		{"while",Tokens::keyword_while}
	};

	typedef core_here::lex::TT<char, Tokens, core_next::lex::State> TT_CC;
	class TT : public TT_CC
	{
	private:
		const std::vector<char> digits = {'0','1','2','3','4','5','6','7','8','9'};
		const std::vector<char> lower = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		const std::vector<char> upper = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		const std::vector<char> graphic = { '!','"','#','%','%','\'','(',')','*','+',',','-','.','/',':',';','<','=','>','?','[','\\',']','^','_','{','|','}','~'};
		const std::vector<char> display = { '\a','\b','\f','\n','\r','\t','\v'};
		const std::vector<char> not_c = {' '};
		const int simbols_amount = 99;

	public:
		constexpr TT()
		{
			create();
			make();
		}

		constexpr void make()
		{
			_simbols.reserve(simbols_amount);
			for (char c : digits)
			{
				_simbols.push_back(c);
			}
			for (char c : lower)
			{
				_simbols.push_back(c);
			}
			for (char c : upper)
			{
				_simbols.push_back(c);
			}
			for (char c : graphic)
			{
				_simbols.push_back(c);
			}
			for (char c : display)
			{
				_simbols.push_back(c);
			}
			for (char c : not_c)
			{
				_simbols.push_back(c);
			}
			sort_symbols();

			std::vector<char> symbols_end_words(37);
			for (char c : graphic)
			{
				symbols_end_words.push_back(c);
			}
			for (char c : display)
			{
				symbols_end_words.push_back(c);
			}
			for (char c : not_c)
			{
				symbols_end_words.push_back(c);
			}

			std::vector<char> symbols_identifier_begin(lower.size() + upper.size() + 1);
			for (char c : lower)
			{
				symbols_identifier_begin.push_back(c);
			}
			for (char c : upper)
			{
				symbols_identifier_begin.push_back(c);
			}
			symbols_identifier_begin.push_back('_');

			for (const auto& p : keywords)
			{
				word(p.string,p.token, symbols_end_words);
			}
			almost_one(digits, Tokens::integer, symbols_end_words);

		}

	private:

	};
}