
/*
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




#include "AF.hh"



namespace oct::cc
{




template<> void Transition<char>::print(std::ostream& out) const
{
		if(input == '\n')
		{
			out << current << "--New line->" << next << "\n";
		}
		else if(input == '\t')
		{
			out << current << "--Tabulator->" << next << "\n";
		}
		else if(input == ' ')
		{
			out << current << "--Espace->" << next << "\n";
		}
		else if(input == '\0')
		{
			out << current << "--\\0->" << next << "\n";
		}
		else
		{
			out << current << "--" << input << "->" << next << "\n";
		}
}
template<> void Transition<wchar_t>::print(std::wostream& out) const
{
		if(input == '\n')
		{
			out << current << "--New line->" << next << "\n";
		}
		else if(input == '\t')
		{
			out << current << "--Tabulator->" << next << "\n";
		}
		else if(input == ' ')
		{
			out << current << "--Espace->" << next << "\n";
		}
		else if(input == '\0')
		{
			out << current << "--\\0->" << next << "\n";
		}
		else
		{
			out << current << "--" << input << "->" << next << "\n";
		}
}

	 







template<> void Table<char>::print(std::ostream& out) const
{
	for(const Transition<char>& t : *this)
	{
		t.print(out);
	}
}
template<> void Table<wchar_t>::print(std::wostream& out) const
{
	for(const Transition<wchar_t>& t : *this)
	{
		t.print(out);
	}
}





	


}