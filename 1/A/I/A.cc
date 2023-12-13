


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


#include "A.hh"



namespace oct::cc::v1::A::I
{
    Unit::Unit() : occ::A::Unit(2)
    {
    }
    Unit::Unit(size_t s) : occ::A::Unit(s)
    {
    }
    Unit::Unit(const Statemants& t) : occ::A::Unit(t,2)
    {
    }
    Unit::Unit(const Statemants& t,size_t s) : occ::A::Unit(t,s)
    {
    }

    void Unit::print(std::ostream& out)const
    {
        Function* actual = (Function*)at(1);
        while(actual)
        {
            actual->print(out);
            actual = (Function*)actual->next;
        }
    }

}
