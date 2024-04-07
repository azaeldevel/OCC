


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

    node::node(const Statemants& t) : core::node<Statemants>(t),next(NULL)
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


    Word::Word(const char* text, size_t size) : node(Statemants::none),_string_(text,size),_token_(Tokens::none),_yylexnext_(NULL)
    {
    }
    Word::Word(Tokens t,const char* text, size_t size) : node(Statemants::none),_string_(text,size),_token_(t),_yylexnext_(NULL)
    {
    }
    Word::Word(Statemants s,const char* text, size_t size) : node(s),_string_(text,size),_token_(Tokens::none),_yylexnext_(NULL)
    {
    }
    Word::Word(Statemants s,Tokens t,const char* text, size_t size) : node(s),_string_(text,size),_token_(t),_yylexnext_(NULL)
    {
    }
    void Word::print(std::ostream& out)const
    {
        out << _string_;
    }

    Word& Word::operator=(const Word& w)
    {
        _string_ = w._string_;
        _token_ = w._token_;
        _yylexnext_ = w._yylexnext_;
        data = w.data;

        return *this;
    }
    Word& Word::operator=(Word&& w)
    {
        _string_ = w._string_;
        _token_ = w._token_;
        _yylexnext_ = w._yylexnext_;
        data = w.data;

        return *this;
    }
    const std::string& Word::string() const
    {
        return _string_;
    }
    void Word::yylexnext(Word* w)
    {
        _yylexnext_ = w;
    }
    Word* Word::yylexnext()
    {
        return _yylexnext_;
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
        out << _string_;
    }

    Keyword& Keyword::operator=(const Keyword& w)
    {
        _string_ = w._string_;
        _token_ = w._token_;
        _yylexnext_ = w._yylexnext_;
        data = w.data;

        return *this;
    }
    Keyword& Keyword::operator=(Keyword&& w)
    {
        _string_ = w._string_;
        _token_ = w._token_;
        _yylexnext_ = w._yylexnext_;
        data = w.data;

        return *this;
    }


    bool Keyword::is_register() const
    {
        if(core::node<Statemants>::data == Statemants::keyword)
        {
            switch(_token_)
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



    Letter::Letter(char c) : node(Statemants::letter), _letter_(c)
    {
    }
    void Letter::print(std::ostream& out)const
    {
        out << "'" << _letter_ << "'";
    }

    Letter& Letter::operator=(const Letter& l)
    {
        _letter_ = l._letter_;
        data = l.data;

        return *this;
    }
    Letter& Letter::operator=(Letter&& l)
    {
        _letter_ = l._letter_;
        data = l.data;

        return *this;
    }

    void Letter::letter(char l)
    {
        _letter_ = l;
    }
    char Letter::letter()const
    {
        return _letter_;
    }





    Statement::Statement() : node(Statemants::none),next(NULL)
    {
    }
    Statement::Statement(Statemants t) : node(t),next(NULL)
    {
    }




    Number::Number(const char* text, size_t size) : Word(text,size),_base_(10)
    {
    }
    Number::Number(Tokens t,const char* text, size_t size) : Word(t,text,size),_base_(10)
    {
    }
    Number::Number(Statemants s,const char* text, size_t size) : Word(s,text,size),_base_(10)
    {
    }
    Number::Number(Statemants s,Tokens t,const char* text, size_t size) : Word(s,t,text,size),_base_(10)
    {
    }
    Number::Number(Statemants s,Tokens t,const char* text, size_t size,char b) : Word(s,t,text,size),_base_(b)
    {
    }

    void Number::print(std::ostream& out)const
    {
        out << _string_;
    }
    char Number::size() const
    {
        switch(_token_)
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
        _string_ = w._string_;
        _token_ = w._token_;
        _yylexnext_ = w._yylexnext_;
        data = w.data;

        return *this;
    }
    Number& Number::operator=(Number&& w)
    {
        _string_ = w._string_;
        _token_ = w._token_;
        _yylexnext_ = w._yylexnext_;
        data = w.data;

        return *this;
    }
    char Number::base()const
    {
        return _base_;
    }


}
