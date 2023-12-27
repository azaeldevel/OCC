


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

    void Node::print(std::ostream&)const
    {
    }


    Word::Word(const char* text, size_t size) : Node(Statemants::none),string(text,size),token(Tokens::none),yylexnext(NULL)
    {
    }
    Word::Word(Tokens t,const char* text, size_t size) : Node(Statemants::none),string(text,size),token(t),yylexnext(NULL)
    {
    }
    Word::Word(Statemants s,const char* text, size_t size) : Node(s),string(text,size),token(Tokens::none),yylexnext(NULL)
    {
    }
    Word::Word(Statemants s,Tokens t,const char* text, size_t size) : Node(s),string(text,size),token(t),yylexnext(NULL)
    {
    }
    void Word::print(std::ostream& out)const
    {
        out << string;
    }




    Keyword::Keyword(const char* text, size_t size) : Word(text,size)
    {
    }
    Keyword::Keyword(Tokens t,const char* text, size_t size) : Word(t,text,size)
    {
    }
    Keyword::Keyword(Statemants s,const char* text, size_t size) : Word(s,text,size)
    {
    }
    Keyword::Keyword(Statemants s,Tokens t,const char* text, size_t size) : Word(s,t,text,size)
    {
    }

    bool Keyword::is_register()const
    {
        if(data == Statemants::keyword)
        {
            switch(token)
            {
            case Tokens::AL:
            case Tokens::AH:
            case Tokens::BL:
            case Tokens::BH:
            case Tokens::CL:
            case Tokens::CH:
            case Tokens::DL:
            case Tokens::DH:
                return true;
            case Tokens::AX:
            case Tokens::BX:
            case Tokens::CX:
            case Tokens::DX:
                return true;
            default :
                return false;
            }
        }

        return false;
    }



    Char::Char(char c) : Node(Statemants::letter), letter(c)
    {
    }
    void Char::print(std::ostream& out)const
    {
        out << "'" << letter << "'";
    }
}
