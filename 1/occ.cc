


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

    /*File::File() : file(NULL),buffer(NULL),scanner(NULL)
    {
    }



    void* File::get_scanner()
    {
        return scanner;
    }*/


    Node::Node()
    {
    }
    Node::Node(size_t s) : core::Node<Types>(s)
    {
    }
    Node::Node(const Types& t) : core::Node<Types>(t)
    {
    }
    Node::Node(const Types& t,size_t s) : core::Node<Types>(t,s)
    {
    }
}
