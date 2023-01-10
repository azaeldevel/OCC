
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

#include "tt.hh"
#include "AF.hh"

using namespace oct::cc;
static const tt::b::TT<int,int> test
{
	//{0,0,tt::Indicator::None,1,1,false},
	{0,1,tt::Indicator::None,2,2,false},
	{2,2,tt::Indicator::None,3,3,false},
	{3,3,tt::Indicator::Prefix_Accept,0,100,false},
};

int main()
{
	int prg[] = {0,1,2,3,0};
	Buffer prgBuff(prg);
	std::cout << "Testing...\n";
	dfa::B testing(test);
	testing.enable_echo(true);
	auto tk = testing.transition(prgBuff);
	std::cout << "Token : " << tk << "\n";
	
	return 0;
}

