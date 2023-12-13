


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
    Node::Node(size_t s) : core::Parent<Statemants>(s)
    {
    }
    Node::Node(Statemants t) : core::Parent<Statemants>(t)
    {
    }
    Node::Node(Statemants t,size_t s) : core::Parent<Statemants>(t,s)
    {
    }


    Number::Number()
    {
    }
    Number::Number(Statemants t) : Word(t)
    {
    }
    Number::Number(Statemants t,const char* text, size_t size) : Word(t,text,size)
    {
    }
    Number::Number(const char* text, size_t size) : Word(text,size)
    {
    }


    Word::Word()
    {
    }
    Word::Word(Statemants t) : Node(t)
    {
    }
    Word::Word(Statemants t,const char* text, size_t size) : Node(t),string(text,size)
    {
    }
    Word::Word(const char* text, size_t size) : string(text,size)
    {
    }
    void Word::print(std::ostream& out)const
    {
        out << string;
    }


    Keyword::Keyword()
    {
    }
    Keyword::Keyword(Statemants t) : Word(t)
    {
    }
    Keyword::Keyword(Statemants t,const char* text, size_t size) : Word(t,text,size)
    {
    }
    Keyword::Keyword(const char* text, size_t size) : Word(text,size)
    {
    }

    Identifier::Identifier()
    {
    }
    Identifier::Identifier(Statemants t) : Word(t)
    {
    }
    Identifier::Identifier(Statemants t,const char* text, size_t size) : Word(t,text,size)
    {
    }
    Identifier::Identifier(const char* text, size_t size) : Word(text,size)
    {
    }


}
