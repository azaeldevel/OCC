


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




    Instruction::Instruction() : Node(Statemants::instruction),next(NULL),inscode(NULL)
    {
    }
    Instruction::Instruction(Statemants t,size_t instsize) : Node(t),next(NULL),inscode(new char[instsize])
    {
    }
    Instruction::~Instruction()
    {
        if(inscode) delete inscode;
    }


    void Instruction::print(std::ostream& out)const
    {
    }




    Move::Move() : Instruction(Statemants::move,2),to(NULL),from(NULL)
    {
    }
    Move::Move(Statemants t,size_t s) : Instruction(t,s),to(NULL),from(NULL)
    {
    }
    Move::Move(Statemants t,size_t s,Node* nTo,Node* nFront) : Instruction(t,s),to(NULL),from(NULL)
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

    void Move::make(Node* t, Node* f)
    {
        //std::cout << "nodes move\n";
        to = t;
        from = f;
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
