


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


#include "occ.hh"



namespace oct::cc::v1
{

    Node::Node()
    {
    }
    Node::Node(Statemants t) : core::node<Statemants>(t)
    {
    }


    Word::Word(const char* text, size_t size) : string(text,size),yylexnext(NULL)
    {
    }
    Word::Word(Tokens t,const char* text, size_t size) : Node(to_statement(t)),string(text,size),yylexnext(NULL)
    {
    }
    void Word::print(std::ostream& out)const
    {
        out << string;
    }

}
