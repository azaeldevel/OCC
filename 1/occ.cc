


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

    Node::Node() : core::Node<Statemants,node>(Statemants::none)
    {
    }
    Node::Node(Statemants t) : core::Node<Statemants,node>(t)
    {
    }
    Node::Node(Statemants t,size_t s) : core::Node<Statemants,node>(t,s)
    {
    }

    void Node::print(std::ostream& out)const
    {
        out << "Node " << (void*)this << "\n";
    }


    Word::Word(const char* text, size_t size) : node(Statemants::none),string(text,size),token(Tokens::none),yylexnext(NULL)
    {
    }
    Word::Word(Tokens t,const char* text, size_t size) : node(Statemants::none),string(text,size),token(t),yylexnext(NULL)
    {
    }
    Word::Word(Statemants s,const char* text, size_t size) : node(s),string(text,size),token(Tokens::none),yylexnext(NULL)
    {
    }
    Word::Word(Statemants s,Tokens t,const char* text, size_t size) : node(s),string(text,size),token(t),yylexnext(NULL)
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

    void Keyword::print(std::ostream& out)const
    {
        out << string;
    }


    bool Keyword::is_register() const
    {
        if(core::node<Statemants>::data == Statemants::keyword)
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
    bool Keyword::is_memory() const
    {
        return false;
    }



    Letter::Letter(char c) : node(Statemants::letter), letter(c)
    {
    }
    void Letter::print(std::ostream& out)const
    {
        out << "'" << letter << "'";
    }




    Statement::Statement() : Node(Statemants::none),next(NULL)
    {
    }
    Statement::Statement(Statemants t) : Node(t),next(NULL)
    {
    }


    Space::Space() : Statement(Statemants::none)
    {
    }
    Space::Space(Statemants t) : Statement(t)
    {
    }
}
