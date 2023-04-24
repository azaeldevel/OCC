


/*
 * main.cc
 * Copyright (C) 2022 Azael Reyes <azael.devel@gmail.com>
 *
 * Octetos Compiler Collection is free software: you can redistribute it and/or modify it
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


#include "cc.hh"



namespace oct::cc::v0
{

    Driver::Driver() : block(new core_here::Block),block_new(true)
    {
    }
    Driver::Driver(core_here::Block& b) : block(&b),block_new(false)
    {
    }
    Driver::~Driver()
    {
        if(block_new)
        {
            delete block;
            block = NULL;
        }
    }


}
