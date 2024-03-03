


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

    void Unit::print(std::ostream& out)const
    {
    }
    bool Unit::semantic(std::ostream& out)
    {
        return false;
    }


    Memory::Memory(Integer& w) : node(Statemants::memory),memory(w)
    {
    }



    Segment::Segment(const char* text, size_t size) : Keyword(text,size)
    {
    }
    Segment::Segment(Tokens t,const char* text, size_t size) : Keyword(t,text,size)
    {
    }
    Segment::Segment(Statemants s,const char* text, size_t size) : Keyword(s,text,size)
    {
    }
    Segment::Segment(Statemants s,Tokens t,const char* text, size_t size) : Keyword(s,t,text,size)
    {
    }


    Function::Function() : Statement(Statemants::function),identifier(NULL),insts(NULL)
    {
    }
    Function::Function(Statemants t) : Statement(t),identifier(NULL),insts(NULL)
    {
    }
    void Function::print(std::ostream& out)const
    {
        if(identifier) identifier->print(out);
        out << "\n{\n";
        Instruction* actual_inst = (Instruction*)insts;
        while(actual_inst)
        {
            //out << "statment: " << (int)actual_inst->data << "\n";
            actual_inst->print(out);
            actual_inst = (Instruction*)actual_inst->next;
        }
        out << "}\n";
    }





    Declaration::Declaration() : Statement(Statemants::declaration)
    {
    }
    Declaration::Declaration(Statemants t) : Statement(t)
    {
    }
    void Declaration::print(std::ostream& out)const
    {
    }



    /*Direct_Declarator::Direct_Declarator() : Statement(Statemants::declaration)
    {
    }
    Direct_Declarator::Direct_Declarator(Statemants t) : Statement(t)
    {
    }
    Direct_Declarator::Direct_Declarator(Statemants t,Node* n,Form f) : Statement(t),first(n),form(f)
    {
    }
    Direct_Declarator::Direct_Declarator(Node* n,Form f) : Statement(Statemants::declaration),first(n),form(f)
    {
    }*/

    Direct_Declarator::Direct_Declarator(Identifier& n)
    {
    }

    void Direct_Declarator::print(std::ostream& out)const
    {
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

    unsigned char Register::size()const
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
    unsigned char Register::mode() const
    {
        if(is_register()) return 0x11;
        else return 0x0;
    }
    unsigned char Register::word() const
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
                return 0x00;
            case Tokens::AX:
            case Tokens::BX:
            case Tokens::CX:
            case Tokens::DX:
            case Tokens::SP:
            case Tokens::BP:
            case Tokens::SI:
            case Tokens::DI:
                return 0x01;
            default :
                return 0;
            }
        }

        return 0x11;
    }
    unsigned char Register::code() const
    {
        if(core::node<Statemants>::data == Statemants::keyword)
        {
            switch(token)
            {
            case Tokens::AL:
            case Tokens::AX:
                return 0x00;
            case Tokens::CL:
            case Tokens::CX:
                return 0x01;
            case Tokens::DL:
            case Tokens::DX:
                return 0x10;
            case Tokens::BL:
            case Tokens::BX:
                return 0x11;
            case Tokens::AH:
            case Tokens::SP:
                return 0x100;
            case Tokens::CH:
            case Tokens::BP:
                return 0x101;
            case Tokens::DH:
            case Tokens::SI:
                return 0x110;
            case Tokens::BH:
            case Tokens::DI:
                return 0x111;
            default :
                return 0;
            }
        }

        return 0xFF;
    }


    Instruction::Instruction() : node(Statemants::instruction),next(NULL),mcode(NULL),msize(0)
    {
    }
    Instruction::Instruction(Statemants t) : node(t),next(NULL),mcode(NULL),msize(0)
    {
    }
    Instruction::Instruction(Statemants t,size_t s) : node(t),next(NULL),mcode(new char[s]),msize(s)
    {
        //for(size_t i = 0; i < instsize; i++) mcode[i] = 0;
    }
    Instruction::~Instruction()
    {
        if(mcode) delete[] mcode;
    }


    void Instruction::print(std::ostream& out)const
    {
    }
    void Instruction::generate(std::ostream& out) const
    {
        out.write(mcode,msize);
    }


}
