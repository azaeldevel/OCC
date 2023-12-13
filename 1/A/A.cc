


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
    Unit::Unit(size_t s) : Node(s)
    {
    }
    Unit::Unit(const Statemants& t) : Node(t)
    {
    }
    Unit::Unit(const Statemants& t,size_t s) : Node(t,s)
    {
    }

    void Unit::print(std::ostream&)const
    {
    }
    bool Unit::semantic(std::ostream& out)
    {
        return false;
    }


    Function::Function() : next(NULL)
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
            switch(reinterpret_cast<core::Node<Statemants>*>(actual_inst)->data)
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




    Instruction::Instruction() : next(NULL),inscode(NULL)
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




    Move::Move()
    {
    }
    Move::Move(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Move::print(std::ostream& out)const
    {
        out << "move;\n";
    }

    void Move::make(Tokens to, Tokens front)
    {

    }
    void Move::make(Tokens to,const Node* nTo, Tokens front,const Node* nFront)
    {
        make(to,front);

    }




    Return::Return()
    {
    }
    Return::Return(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Return::print(std::ostream& out)const
    {
        out << "return;\n";
    }




    Empty::Empty()
    {
    }
    Empty::Empty(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Empty::print(std::ostream& out)const
    {
        out << ";\n";
    }




    Interrupt::Interrupt()
    {
    }
    Interrupt::Interrupt(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Interrupt::print(std::ostream& out)const
    {
        out << "interrupt;\n";
    }


}
