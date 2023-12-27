


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



namespace oct::cc::v1::A
{
    Unit::Unit() : Node(Statemants::unit)
    {
    }
    Unit::Unit(const Statemants& t) : Node(t)
    {
    }

    void Unit::print(std::ostream&)const
    {
    }
    bool Unit::semantic(std::ostream& out)
    {
        return false;
    }


    Function::Function() : Node(Statemants::function),next(NULL)
    {
    }
    Function::Function(Statemants t) : Node(t),next(NULL)
    {
    }
    void Function::print(std::ostream& out)const
    {
        if(identifier) identifier->print(out);
        out << "\n{\n";
        Instruction* actual_inst = (Instruction*)insts;
        while(actual_inst)
        {
            switch(reinterpret_cast<core::node<Statemants>*>(actual_inst)->data)
            {
            case Statemants::move:
                    reinterpret_cast<Move*>(actual_inst)->print(out);
                break;
            case Statemants::ret:
                    reinterpret_cast<Return*>(actual_inst)->print(out);
                break;
            case Statemants::interrupt:
                    reinterpret_cast<Interrupt*>(actual_inst)->print(out);
                break;
            default:
                ;
            }
            actual_inst = (Instruction*)actual_inst->next;
        }
        out << "}\n";
    }



    Register::Register(const char* text, size_t size) : Keyword(text,size)
    {
    }
    Register::Register(Tokens t,const char* text, size_t size) : Keyword(t,text,size)
    {
    }
    Register::Register(Statemants s,const char* text, size_t size) : Keyword(s,text,size)
    {
    }
    Register::Register(Statemants s,Tokens t,const char* text, size_t size) : Keyword(s,t,text,size)
    {
    }

    unsigned char Register::register_size()const
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
                return 8;
            case Tokens::AX:
            case Tokens::BX:
            case Tokens::CX:
            case Tokens::DX:
                return 16;
            default :
                return 0;
            }
        }

        return 0;
    }


    Instruction::Instruction() : Node(Statemants::instruction),next(NULL),inscode(NULL)
    {
    }
    Instruction::Instruction(Statemants t) : Node(t),next(NULL),inscode(NULL)
    {
    }
    Instruction::Instruction(Statemants t,size_t instsize) : Node(t),next(NULL),inscode(new char[instsize])
    {
        for(size_t i = 0; i < instsize; i++) inscode[i] = 0;
    }
    Instruction::~Instruction()
    {
        if(inscode) delete[] inscode;
    }


    void Instruction::print(std::ostream& out)const
    {
    }




    Move::Move() : Instruction(Statemants::move),to(NULL),from(NULL)
    {
    }
    Move::Move(Statemants t,size_t s) : Instruction(t,s),to(NULL),from(NULL)
    {
    }
    Move::Move(Statemants t,size_t s,Node* nTo,Node* nFront) : Instruction(t,s),to(nTo),from(nFront)
    {
    }
    Move::Move(size_t s,Node* nTo,Node* nFront) : Instruction(Statemants::move,s),to(nTo),from(nFront),form(Form::none)
    {
    }
    Move::Move(size_t s,Node* nTo,Node* nFront,Form f) : Instruction(Statemants::move,s),to(nTo),from(nFront),form(f)
    {
    }
    void Move::print(std::ostream& out)const
    {
        out << "\tmove ";
        if(to)
        {
            if(to->data == Statemants::keyword)
            {
                out << reinterpret_cast<Keyword*>(to)->string;
            }
            else
            {
                out << "?";
            }
        }
        out << ", ";
        if(from)
        {
            if(from->data == Statemants::number)
            {
                out << reinterpret_cast<Number*>(from)->string;
            }
            else if(from->data == Statemants::letter)
            {
                out << "'" << reinterpret_cast<Char*>(from)->letter << "'";
            }
            else
            {
                out << "?";
            }
        }

        out << ";\n";
    }

    void Move::bind()
    {

        switch(form)
        {
        case Form::inmediate_to_register:
            {
                inscode[0] = 0b1011;
                if(is_register(from))
                {
                    if(register_size(from) == 8)
                    {
                        inscode[0] = inscode[0] << 0;
                    }
                    else
                    {
                        inscode[0] = inscode[0] << 1;
                    }

                }
                break;
            }
        }

    }

    bool Move::is_register(const Node* node) const
    {
        if(node)
        {
            if(node->data == Statemants::keyword)
            {
                switch(reinterpret_cast<const Word*>(node)->token)
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
            else
            {
                return false;
            }
        }
        return false;
    }

    unsigned char Move::register_size(const Node* node) const
    {
        if(node)
        {
            if(node->data == Statemants::keyword)
            {
                switch(reinterpret_cast<const Word*>(node)->token)
                {
                case Tokens::AL:
                case Tokens::AH:
                case Tokens::BL:
                case Tokens::BH:
                case Tokens::CL:
                case Tokens::CH:
                case Tokens::DL:
                case Tokens::DH:
                    return 8;
                case Tokens::AX:
                case Tokens::BX:
                case Tokens::CX:
                case Tokens::DX:
                    return 16;
                default :
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        return 0;
    }


    void Move::bind(Form f)
    {
        if(f > Form::none)
        {
            form = f;
            bind();
        }
        else
        {
            bind();
        }
    }




    Return::Return() : Instruction(Statemants::ret,2)
    {
    }
    Return::Return(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Return::print(std::ostream& out)const
    {
        out << "\treturn;\n";
    }




    Empty::Empty() : Instruction(Statemants::empty,2)
    {
    }
    Empty::Empty(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Empty::print(std::ostream& out)const
    {
        out << "\t;\n";
    }




    Interrupt::Interrupt() : Instruction(Statemants::interrupt,2),service(NULL)
    {
    }
    Interrupt::Interrupt(Statemants t,size_t s) : Instruction(t,s),service(NULL)
    {
    }
    void Interrupt::make(Number* n)
    {
        service = n;
    }
    void Interrupt::print(std::ostream& out)const
    {
        out << "\tinterrupt ";
        if(service)
        {
            if(service->data == Statemants::number)
            {
                out << service->string;
            }
            else
            {
                out << "?";
            }
        }
        else
        {
            out << "?";
        }
        out << ";\n";
    }


}
