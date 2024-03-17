


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

    node::node(const Statemants& t) : core::node<Statemants>(t)
    {
    }

    void node::print(std::ostream&)const
    {
    }


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

    Word& Word::operator=(const Word& w)
    {
        string = w.string;
        token = w.token;
        yylexnext = w.yylexnext;
        data = w.data;

        return *this;
    }
    Word& Word::operator=(Word&& w)
    {
        string = w.string;
        token = w.token;
        yylexnext = w.yylexnext;
        data = w.data;

        return *this;
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

    Keyword& Keyword::operator=(const Keyword& w)
    {
        string = w.string;
        token = w.token;
        yylexnext = w.yylexnext;
        data = w.data;

        return *this;
    }
    Keyword& Keyword::operator=(Keyword&& w)
    {
        string = w.string;
        token = w.token;
        yylexnext = w.yylexnext;
        data = w.data;

        return *this;
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

    Letter& Letter::operator=(const Letter& l)
    {
        letter = l.letter;
        data = l.data;

        return *this;
    }
    Letter& Letter::operator=(Letter&& l)
    {
        letter = l.letter;
        data = l.data;

        return *this;
    }





    Statement::Statement() : node(Statemants::none),next(NULL)
    {
    }
    Statement::Statement(Statemants t) : node(t),next(NULL)
    {
    }


    Space::Space() : Statement(Statemants::none)
    {
    }
    Space::Space(Statemants t) : Statement(t)
    {
    }



    Number::Number(const char* text, size_t size) : Word(text,size),base(10)
    {
    }
    Number::Number(Tokens t,const char* text, size_t size) : Word(t,text,size),base(10)
    {
    }
    Number::Number(Statemants s,const char* text, size_t size) : Word(s,text,size),base(10)
    {
    }
    Number::Number(Statemants s,Tokens t,const char* text, size_t size) : Word(s,t,text,size),base(10)
    {
    }
    Number::Number(Statemants s,Tokens t,const char* text, size_t size,char b) : Word(s,t,text,size),base(b)
    {
    }

    void Number::print(std::ostream& out)const
    {
        out << string;
    }
    char Number::size() const
    {
        switch(token)
        {
        case Tokens::TINY:
            return 1;
        case Tokens::SHORT:
            return 2;
        default:
            return 0;
        }

        return 0;
    }

    Number& Number::operator=(const Number& w)
    {
        string = w.string;
        token = w.token;
        yylexnext = w.yylexnext;
        data = w.data;

        return *this;
    }
    Number& Number::operator=(Number&& w)
    {
        string = w.string;
        token = w.token;
        yylexnext = w.yylexnext;
        data = w.data;

        return *this;
    }


}
