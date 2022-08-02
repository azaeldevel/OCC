


/*
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 * 
 * octetos-CC is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * octetos-CC is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>

#include "tt.hh"


namespace oct::cc::tt
{

namespace a
{
	bool check(const Transition (*t)[MAX_SIMBOLS],Word length, std::vector<Selector>& errors)
	{
		for(unsigned int i = 0; i < length; i++)
		{
			for(unsigned short j = 0; j < 128; j++)
			{
				//std::cout << "cheking (" << i << "," << j << ")\n";
				if(t[i][j].indicator ==  Indicator::Reject and t[i][j].next == 0 and t[i][j].token == base_token) continue;
				if(t[i][j].indicator ==  Indicator::None and t[i][j].next > 0 and t[i][j].token == base_token) continue;
				if(t[i][j].indicator ==  Indicator::Prefix_Accept and t[i][j].next == 0 and t[i][j].token == base_token) continue;
				if(t[i][j].indicator ==  Indicator::Accept and t[i][j].token != 0) continue;
				errors.push_back({i,j});
			}
		}
	}
 }


}
