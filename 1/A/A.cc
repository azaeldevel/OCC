


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


    Function::Function() : v1::Function(Statemants::function)
    {
    }
    Function::Function(Statemants t) : v1::Function(t)
    {
    }
    void Function::print(std::ostream& out) const
    {
        if(identifier) identifier->print(out);
        out << "\n{\n";
        Instruction* actual_inst = (Instruction*)insts;
        while(actual_inst)
        {
            //out << "statment: " << (int)actual_inst->data << "\n";
            actual_inst->print(out);
            actual_inst = actual_inst->next;
        }
        out << "}\n";
    }
    void Function::generate(std::ostream& out) const
    {
        Instruction* actual_inst = (Instruction*)insts;
        while(actual_inst)
        {
            actual_inst->generate(out);
            //std::cout << "code:" << actual_inst->mcode[0] << "-" << actual_inst->mcode[1] << "\n";
            //std::cout << "code:" << (void*)actual_inst << "\n";
            actual_inst = actual_inst->next;
        }
    }





    Declaration::Declaration() : Statement(Statemants::declaration),specifiers(NULL),initlist(NULL)
    {
    }
    Declaration::Declaration(Statemants t) : Statement(Statemants::declaration),specifiers(NULL),initlist(NULL)
    {
    }
    Declaration::Declaration(node& s) : Statement(Statemants::declaration),specifiers(&s),initlist(NULL)
    {
    }
    Declaration::Declaration(node& s,node& i) : Statement(Statemants::declaration),specifiers(&s),initlist(&i)
    {
    }

    void Declaration::print(std::ostream& out) const
    {
        //out << "void Declaration::print(std::ostream& out) const\n";
        node* actual = specifiers;
        //out << "\tif(actual)\n\t{\n";
        while(actual)
        {
            switch(actual->data)
            {
            case Statemants::keyword:
            case Statemants::identifier:
            case Statemants::segment:
            case Statemants::reg:
                actual->print(out);
                actual = actual->next;
                break;
            default:
                actual = NULL;
                break;
            }
        }
        //out << "\n\t}\n";
        out << "\n";
    }


    Direct_Declarator::Direct_Declarator(Identifier& n)
    {
    }
    Direct_Declarator::Direct_Declarator(Declarator& n)
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
    Register::Register(Tokens t) : Keyword(Statemants::reg,t,to_string(t),string_size(t))
    {
    }

    unsigned char Register::size()const
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
        if(is_register()) return 0b11;
        else return 0b00;
    }
    void Register::word(unsigned char& inst) const
    {
        if(core::node<Statemants>::data == Statemants::reg)
        {
            inst <<= 1;
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
                break;
            case Tokens::AX:
            case Tokens::BX:
            case Tokens::CX:
            case Tokens::DX:
            case Tokens::SP:
            case Tokens::BP:
            case Tokens::SI:
            case Tokens::DI:
                inst++;
                break;
            default:
                break;
            }
        }
    }
    /*void Register::code(unsigned char& inst) const
    {
        inst <<= 3;
        if(core::node<Statemants>::data == Statemants::reg)
        {
            //std::cout << "REG<<";
            switch(_token_)
            {
            case Tokens::AL:
            case Tokens::AX:
                break;
            case Tokens::CL:
            case Tokens::CX:
                inst +=  1;
                break;
            case Tokens::DL:
            case Tokens::DX:
                inst += 2;
                break;
            case Tokens::BL:
            case Tokens::BX:
                inst += 3;
                break;
            case Tokens::AH:
            case Tokens::SP:
                inst += 4;
                break;
            case Tokens::CH:
            case Tokens::BP:
                inst += 5;
                break;
            case Tokens::DH:
            case Tokens::SI:
                inst += 6;
                break;
            case Tokens::BH:
            case Tokens::DI:
                inst += 7;
                break;
            default:
                break;
            }
        }
    }*/
    void Register::mode(unsigned char& inst) const
    {
        if(not next and is_general_register())
        {
            inst = (inst << 2) + 0b11;
        }
        else if(next)
        {
        }

    }
    void Register::mode(unsigned char& inst, char type) const
    {
        if(not next and is_general_register() and type == 3)
        {
            inst = (inst << 2) + 0b11;
        }
        else if(next)
        {
        }

    }
    void Register::rm(unsigned char& inst) const
    {
        if(core::node<Statemants>::data == Statemants::reg)
        {
            inst <<= 3;
            //std::cout << "REG<<";
            switch(_token_)
            {
            case Tokens::AL:
            case Tokens::AX:
                break;
            case Tokens::CL:
            case Tokens::CX:
                inst +=  1;
                break;
            case Tokens::DL:
            case Tokens::DX:
                inst += 2;
                break;
            case Tokens::BL:
            case Tokens::BX:
                inst += 3;
                break;
            case Tokens::AH:
            case Tokens::SP:
                inst += 4;
                break;
            case Tokens::CH:
            case Tokens::BP:
                inst += 5;
                break;
            case Tokens::DH:
            case Tokens::SI:
                inst += 6;
                break;
            case Tokens::BH:
            case Tokens::DI:
                inst += 7;
                break;
            default:
                break;
            }
        }
    }

    Instruction::Instruction() : Statement(Statemants::instruction),next(NULL),mcode(NULL),msize(0)
    {
    }
    Instruction::Instruction(Statemants t) : Statement(t),next(NULL),mcode(NULL),msize(0)
    {
    }
    Instruction::Instruction(Statemants t,size_t s) : Statement(t),next(NULL),mcode(new unsigned char[s]),msize(s)
    {
        for(size_t i = 0; i < s ; i++) mcode[i] = 0;
    }
    Instruction::~Instruction()
    {
    }

    void Instruction::init(size_t s)
    {
        data = Statemants::instruction;

        next = NULL;
        mcode = new unsigned char[s];
        msize = s;
        for(size_t i = 0; i < s ; i++) mcode[i] = 0;
    }
    void Instruction::init(Statemants t,size_t s)
    {
        data = t;

        next = NULL;
        mcode = new unsigned char[s];
        msize = s;
        for(size_t i = 0; i < s ; i++) mcode[i] = 0;
    }


    void Instruction::print(std::ostream& out)const
    {
    }
    void Instruction::generate(std::ostream& out) const
    {
        out.write((char*)mcode,msize);
    }

    /**
    *\brief write the mod code on the i-byte of mcode array, based on the node string passed
    */
    void Instruction::mode(size_t i, const node& node)
    {
        std::cout << "mode : 1\n";

        //create a pointer to Register variable casting from node
        const Register* node_register = static_cast<const Register*>(&node);

        std::cout << "mode : 2\n";
        //if has only one register(general register) in the string then set mod value 0b11
        if(!node_register->next)
        {
            std::cout << "2.1\n";
            if(is_general_register(node_register->token()))
            {
                std::cout << "2.1.1\n";
                mcode[i] = (mcode[i] << 2) + 0b11;
                return;
            }
        }

        std::cout << "mode : 3\n";
        //if has one or two register combining BX,BP with SI, DI or memory then set mod value 0b00
        if(node_register->token() == Tokens::BP || node_register->token() == Tokens::BX || node_register->data == Statemants::memory)
        {
            std::cout << "mode : 3.1\n";
            if(node_register->next and node_register->data != Statemants::reg)
            {
                const Register* offset = static_cast<const Register*>(node_register->next);
                if(offset->token() == Tokens::SI || offset->token() == Tokens::DI)
                {
                    mcode[i] = (mcode[i] << 2) + 0b00;
                    return;
                }
            }
        }
        else if(node_register->token() == Tokens::SI || node_register->token() == Tokens::DI || node.data == Statemants::number || node_register->token() == Tokens::BX)
        {
            std::cout << "mode : 3.2\n";
            mcode[i] = (mcode[i] << 2) + 0b00;
            return;
        }

        std::cout << "mode : 4\n";
        //if has one or two register combining BX,BP with SI, DI and 8-bits number then set mod value 0b01
        if(node_register->token() == Tokens::BX || node_register->token() == Tokens::BP )
        {
            if(node_register->next and node_register->data != Statemants::reg)
            {
                const Register* offset = static_cast<const Register*>(node_register->next);
                if(offset->token() == Tokens::SI || offset->token() == Tokens::DI)
                {
                    if(not offset->next)
                    {
                        mcode[i] = (mcode[i] << 2) + 0b01;
                        return;
                    }
                    else if(offset->next->data == Statemants::number)
                    {
                        const Number* dt8 = static_cast<const Number*>(offset->next);
                        if(dt8->size() == 1)
                        {
                            mcode[i] = (mcode[i] << 2) + 0b01;
                            return;
                        }
                    }
                }
                else if(offset->next->data == Statemants::number)
                {
                    const Number* dt8 = static_cast<const Number*>(offset->next);
                    if(dt8->size() == 1)
                    {
                        mcode[i] = (mcode[i] << 2) + 0b01;
                        return;
                    }
                }
            }
        }

        std::cout << "mode : 5\n";
        //if has one or two register combining BX,BP with SI, DI and 16-bits number then set mod value 0b10
        if(node_register->token() == Tokens::BX || node_register->token() == Tokens::BP )
        {
            if(node_register->next and node_register->data != Statemants::reg)
            {
                const Register* offset = static_cast<const Register*>(node_register->next);
                if(offset->token() == Tokens::SI || offset->token() == Tokens::DI)
                {
                    if(not offset->next)
                    {
                        mcode[i] = (mcode[i] << 2) + 0b10;
                        return;
                    }
                    else if(offset->next->data == Statemants::number)
                    {
                        const Number* dt16 = static_cast<const Number*>(offset->next);
                        if(dt16->size() == 2)
                        {
                            mcode[i] = (mcode[i] << 2) + 0b10;
                            return;
                        }
                    }
                }
                else if(offset->next->data == Statemants::number)
                {
                    const Number* dt8 = static_cast<const Number*>(offset->next);
                    if(dt8->size() == 1)
                    {
                        mcode[i] = (mcode[i] << 2) + 0b10;
                        return;
                    }
                }
            }
        }

    }



    Init_Declarator::Init_Declarator() : Statement(Statemants::init_declarator)
    {
    }
    Init_Declarator::Init_Declarator(Declarator&) : Statement(Statemants::init_declarator)
    {
    }
    Init_Declarator::Init_Declarator(Declarator&,node& initializer) : Statement(Statemants::init_declarator)
    {
    }

    void Init_Declarator::print(std::ostream& out)const
    {
    }


    Memory::Memory() : node(Statemants::memory)
    {
    }

    void Memory::set(node& i,Type t)
    {
        next = &i;
        type = t;
    }

    void Memory::print(std::ostream& out) const
    {
    }
    char Memory::rm() const
    {
        auto node1 = static_cast<Register*>(next);
        if(node1->next)
        {
            auto node2 = static_cast<Register*>(node1->next);
            if(node2->next)
            {
                return char(0xff);
            }
            else if(node1->token() == Tokens::BX)
            {
                if(node2->token() == Tokens::SI)
                {
                    return 1;
                }
                else if(node2->token() == Tokens::DI)
                {
                    return 2;
                }
            }
            else if(node1->token() == Tokens::BP)
            {
                auto node2 = static_cast<Register*>(node1->next);
                if(node2->token() == Tokens::SI)
                {
                    return 3;
                }
                else if(node2->token() == Tokens::DI)
                {
                    return 4;
                }
            }
        }
        else //solo un nodo
        {
            if(node1->is_general_register())
            {
                switch(node1->token())
                {
                case Tokens::AL:
                case Tokens::AX:
                    break;
                case Tokens::CL:
                case Tokens::CX:
                    return 1;
                case Tokens::DL:
                case Tokens::DX:
                    return 2;
                case Tokens::BL:
                case Tokens::BX:
                    return 3;
                case Tokens::AH:
                case Tokens::SP:
                    return 4;
                case Tokens::CH:
                case Tokens::BP:
                    return 5;
                case Tokens::DH:
                case Tokens::SI:
                    return 6;
                case Tokens::BH:
                case Tokens::DI:
                    return 7;
                default:
                    break;
                }
            }
            else if(node1->token() == Tokens::SI)
            {
                return 4;
            }
            else if(node1->token() == Tokens::DI)
            {
                return 5;
            }
            else if(node1->data ==Statemants::integer or node1->data == Statemants::number)
            {
                return 6;
            }
            else if(node1->token() == Tokens::DI)
            {
                return 7;
            }
        }

        return char(0xff);
    }
    char Memory::mode() const
    {
        auto node1 = static_cast<Register*>(next);
        if(node1->next)
        {
            auto node2 = static_cast<Register*>(node1->next);
            if(node2->next)
            {
                return char(0xff);
            }
            else if(node1->token() == Tokens::BX)
            {
                if(node2->token() == Tokens::SI)
                {
                    return 0;
                }
                else if(node2->token() == Tokens::DI)
                {
                    return 0;
                }
            }
            else if(node1->token() == Tokens::BP)
            {
                auto node2 = static_cast<Register*>(node1->next);
                if(node2->token() == Tokens::SI)
                {
                    return 0;
                }
                else if(node2->token() == Tokens::DI)
                {
                    return 0;
                }
            }
        }
        else //solo un nodo
        {
            if(node1->is_general_register() and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::SI and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::DI and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::BP and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::SP and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::SI and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::DI and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::SP and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::BP and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->data ==Statemants::integer or node1->data == Statemants::number)
            {
                return 0;
            }
            else if(node1->token() == Tokens::SI and type == Type::implied)
            {
                return 3;
            }
            else if(node1->token() == Tokens::DI and type == Type::implied)
            {
                return 3;
            }
            else if(node1->token() == Tokens::BX and type == Type::implied)
            {
                return 3;
            }
        }

        return char(0xff);
    }









    TFE::TFE() : node(Statemants::none)
    {
    }
    TFE::TFE(node& n) : node(Statemants::none)
    {
        next = &n;
    }
    TFE::TFE(node& n,node& m) : node(Statemants::none)
    {
        next = &n;
        n.next = &m;
    }
    TFE::TFE(node& n,node& m,node& o) : node(Statemants::none)
    {
        next = &n;
        n.next = &m;
        m.next = &o;
    }

    void TFE::set(node& i,Type t)
    {
        next = &i;
        type = t;
    }

    void TFE::print(std::ostream& out) const
    {
    }
    char TFE::rm() const
    {
        auto node1 = static_cast<Register*>(next);
        if(node1->next)
        {
            auto node2 = static_cast<Register*>(node1->next);
            if(node2->next)
            {
                return char(0xff);
            }
            else if(node1->token() == Tokens::BX)
            {
                if(node2->token() == Tokens::SI)
                {
                    return 1;
                }
                else if(node2->token() == Tokens::DI)
                {
                    return 2;
                }
            }
            else if(node1->token() == Tokens::BP)
            {
                auto node2 = static_cast<Register*>(node1->next);
                if(node2->token() == Tokens::SI)
                {
                    return 3;
                }
                else if(node2->token() == Tokens::DI)
                {
                    return 4;
                }
            }
        }
        else //solo un nodo
        {
            if(node1->is_general_register())
            {
                switch(node1->token())
                {
                case Tokens::AL:
                case Tokens::AX:
                    break;
                case Tokens::CL:
                case Tokens::CX:
                    return 1;
                case Tokens::DL:
                case Tokens::DX:
                    return 2;
                case Tokens::BL:
                case Tokens::BX:
                    return 3;
                case Tokens::AH:
                case Tokens::SP:
                    return 4;
                case Tokens::CH:
                case Tokens::BP:
                    return 5;
                case Tokens::DH:
                case Tokens::SI:
                    return 6;
                case Tokens::BH:
                case Tokens::DI:
                    return 7;
                default:
                    break;
                }
            }
            else if(node1->token() == Tokens::SI)
            {
                return 4;
            }
            else if(node1->token() == Tokens::DI)
            {
                return 5;
            }
            else if(node1->data ==Statemants::integer or node1->data == Statemants::number)
            {
                return 6;
            }
            else if(node1->token() == Tokens::DI)
            {
                return 7;
            }
        }

        return char(0xff);
    }
    char TFE::mode() const
    {
        auto node1 = static_cast<Register*>(next);
        if(node1->next)
        {
            auto node2 = static_cast<Register*>(node1->next);
            if(node2->next)
            {
                return char(0xff);
            }
            else if(node1->token() == Tokens::BX)
            {
                if(node2->token() == Tokens::SI)
                {
                    return 0;
                }
                else if(node2->token() == Tokens::DI)
                {
                    return 0;
                }
            }
            else if(node1->token() == Tokens::BP)
            {
                auto node2 = static_cast<Register*>(node1->next);
                if(node2->token() == Tokens::SI)
                {
                    return 0;
                }
                else if(node2->token() == Tokens::DI)
                {
                    return 0;
                }
            }
        }
        else //solo un nodo
        {
            if(node1->is_general_register() and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::SI and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::DI and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::BP and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::SP and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::SI and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::DI and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::SP and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->token() == Tokens::BP and type == Type::inmediate)
            {
                return 3;
            }
            else if(node1->data ==Statemants::integer or node1->data == Statemants::number)
            {
                return 0;
            }
            else if(node1->token() == Tokens::SI and type == Type::implied)
            {
                return 3;
            }
            else if(node1->token() == Tokens::DI and type == Type::implied)
            {
                return 3;
            }
            else if(node1->token() == Tokens::BX and type == Type::implied)
            {
                return 3;
            }
        }

        return char(0xff);
    }


}

