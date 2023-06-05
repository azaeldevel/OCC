


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

#include <core/3/Exception.hh>


#include "A.hh"

namespace oct::cc::v0::AI::nodes::intel::i8086
{

    void Move::print(std::ostream& out)const
    {
        //out << "void Move::print(std::ostream& out)const\n";
        switch(op_type)
        {
        case operands_type::regiter_integer:
            {
                auto destine = static_cast<Token<Tokens>*>(this->destine);
                auto source = static_cast<constant_integer<integer>*>(this->source);
                out << "\n\tmov " << register_to_string(destine->token) << " ";
                source->print(out);
            }
            break;
        case operands_type::regiter_char:
            {
                auto destine = static_cast<Token<Tokens>*>(this->destine);
                auto source = static_cast<charater_constant<char>*>(this->source);
                out << "\n\tmov " << register_to_string(destine->token) << " ";
                out << "'";
                source->print(out);
                out << "'";
            }
            break;
        case operands_type::segment_register:
            {
                //out << "operands_type::segment_register\n";
                auto destine = static_cast<Token<Tokens>*>(this->destine);
                auto source = static_cast<Token<Tokens>*>(this->source);
                out << "\n\tmov " << segment_to_string(destine->token) << " " << register_to_string(source->token);
            }
            break;
        case operands_type::register_segment:
            {
                //out << "operands_type::segment_register\n";
                auto destine = static_cast<Token<Tokens>*>(this->destine);
                auto source = static_cast<Token<Tokens>*>(this->source);
                out << "\n\tmov " << register_to_string(destine->token) << " " << segment_to_string(source->token);
            }
            break;
        case operands_type::register_register:
            {
                //out << "operands_type::segment_register\n";
                auto destine = static_cast<Token<Tokens>*>(this->destine);
                auto source = static_cast<Token<Tokens>*>(this->source);
                out << "\n\tmov " << register_to_string(destine->token) << " " << register_to_string(source->token);
            }
            break;
        case operands_type::register_memory:
            {
                //out << "operands_type::segment_register\n";
                auto destine = static_cast<Token<Tokens>*>(this->destine);
                auto source = static_cast<Memory*>(this->source);
                out << "\n\tmov " << register_to_string(destine->token) << ", ";
                source->print(out);
            }
            break;
        case operands_type::memory_register:
            {
                //out << "operands_type::segment_register\n";
                auto destine = static_cast<Memory*>(this->destine);
                auto source = static_cast<Token<Tokens>*>(this->source);
                out << "\n\tmov ";
                destine->print(out);
                out << ", " << register_to_string(source->token);
            }
            break;
        case operands_type::memory_integer:
            {
                //out << "operands_type::segment_register\n";
                auto destine = static_cast<Memory*>(this->destine);
                auto source = static_cast<constant_integer<integer>*>(this->source);
                out << "\n\tmov ";
                destine->print(out);
                out << ", " << source->get_value();
            }
            break;
        case operands_type::memory_char:
            {
                //out << "operands_type::segment_register\n";
                auto destine = static_cast<Memory*>(this->destine);
                auto source = static_cast<charater_constant<char>*>(this->source);
                out << "\n\tmov ";
                destine->print(out);
                out << ", '" << source->value << "'";
            }
            break;
        case operands_type::segment_memory:
            {
                //out << "operands_type::segment_register\n";
                auto destine = static_cast<Token<Tokens>*>(this->destine);
                auto source = static_cast<Memory*>(this->source);
                out << "\n\tmov " << segment_to_string(destine->token) << ", ";
                source->print(out);
            }
            break;
        case operands_type::memory_segment:
            {
                //out << "operands_type::segment_register\n";
                auto destine = static_cast<Memory*>(this->destine);
                auto source = static_cast<Token<Tokens>*>(this->source);
                out << "\n\tmov ";
                destine->print(out);
                out << ", " << segment_to_string(source->token);
            }
            break;
        default:
            ;//error
        }
    }
    void Move::generate(std::ostream& out)const
    {
        switch(word_size)
        {
        case 8:
            switch(op_type)
            {
            case operands_type::regiter_integer:
                generate_8b_register_integer(out);
                break;
            case operands_type::regiter_char:
                generate_8b_register_char(out);
                break;
            case operands_type::register_register:
                generate_8b_register_register(out);
                break;
            case operands_type::memory_char:
                generate_8b_memory_char(out);
                break;
            case operands_type::register_memory:
                generate_8b_register_memory(out);
                break;
            default:
                ;
            }
            break;
        case 16:
            switch(op_type)
            {
            case operands_type::regiter_integer:
                generate_16b_register_integer(out);
                break;
            case operands_type::segment_register:
                generate_segment_register(out);
                break;
            case operands_type::register_segment:
                generate_register_segment(out);
                break;
            case operands_type::register_register:
                generate_16b_register_register(out);
                break;
            case operands_type::register_memory:
                generate_16b_register_memory(out);
                break;
            case operands_type::memory_register:
                generate_16b_memory_register(out);
                break;
            case operands_type::memory_integer:
                generate_16b_memory_integer(out);
                break;
            case operands_type::segment_memory:
                generate_16b_segment_memory(out);
                break;
            case operands_type::memory_segment:
                generate_16b_memory_segment(out);
                break;
            default:
                ;
            }
            break;
        default:
            ;
        }
    }
    void Move::generate_8b_register_integer(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<constant_integer<integer>*>(this->source);

        char instruction[get_size_memory()];
        instruction[0] = 0b1011;//opcode
        instruction[0] = instruction[0] << 1;//w = 0;one byte
        generate_fill_rm_8b(instruction[0],destine);
        instruction[1] = (char)source->get_value();
        //sstd::cout << (int)instruction[0] << " register-8b integer\n";
        out.write((char*)&instruction,get_size_memory());
    }
    void Move::generate_8b_register_char(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<charater_constant<char>*>(this->source);

        char instruction[get_size_memory()];
        instruction[0] = 0b1011;//opcode
        instruction[0] = instruction[0] << 1;//w = 0;one byte
        generate_fill_rm_8b(instruction[0],destine);
        instruction[1] = source->value;
        //std::cout << "Data : '" << source->value << "'\n";
        //std::cout << "Pointer : '" << (void*)source << "'\n";
        out.write((char*)&instruction,get_size_memory());
    }
    void Move::generate_16b_register_integer(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<constant_integer<integer>*>(this->source);

        char instruction[get_size_memory()];
        instruction[0] = 0b1011;//opcode
        instruction[0] = instruction[0] << 1;
        instruction[0]++;//w = 1;one byte
        generate_fill_rm_16b(instruction[0],destine);
        short *data = (short*)&instruction[1];
        *data = (short)source->get_value();
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        out.write((char*)&instruction,get_size_memory());
    }
    void Move::generate_segment_register(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b10001110;
        inst[1] = 0;
        inst[1] += 0b11;//mod
        inst[1] = inst[1] << 1;//add 0b0
        generate_16b_fill_segment(inst[1],destine);
        generate_fill_rm_16b(inst[1],source);
        out.write(inst,get_size_memory());
    }
    void Move::generate_register_segment(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b10001100;
        inst[1] = 0;
        inst[1] += 0b11;//mod
        inst[1] = inst[1] << 1;//add 0b0
        generate_16b_fill_segment(inst[1],source);
        generate_fill_rm_16b(inst[1],destine);
        out.write(inst,get_size_memory());
    }
    void Move::generate_8b_fill_register(char& data,Token<Tokens>* token) const
    {
        switch(token->token)//reg
        {
            case Tokens::AL:
                data = data << 3;
                break;
            case Tokens::CL:
                data = data << 3;
                data = data + 0b001;
                break;
            case Tokens::DL:
                data = data << 3;
                data = data + 0b010;
                break;
            case Tokens::BL:
                data = data << 3;
                data = data + 0b011;
                break;
            case Tokens::AH:
                data = data << 3;
                data = data + 0b100;
                break;
            case Tokens::CH:
                data = data << 3;
                data = data + 0b101;
                break;
            case Tokens::DH:
                data = data << 3;
                data = data + 0b110;
                break;
            case Tokens::BH:
                data = data << 3;
                data = data + 0b111;
                break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
    }
    void Move::generate_16b_fill_register(char& data,Token<Tokens>* token) const
    {
        switch(token->token)//reg
        {
        case Tokens::AX:
            data = data << 3;
            break;
        case Tokens::CX:
            data = data << 3;
            data = data + 0b001;
            break;
        case Tokens::DX:
            data = data << 3;
            data = data + 0b010;
            break;
        case Tokens::BX:
            data = data << 3;
            data = data + 0b011;
            break;
        case Tokens::SP:
            data = data << 3;
            data = data + 0b100;
            break;
        case Tokens::BP:
            data = data << 3;
            data = data + 0b101;
            break;
        case Tokens::SI:
            data = data << 3;
            data = data + 0b110;
            break;
        case Tokens::DI:
            data = data << 3;
            data = data + 0b111;
            break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
    }
    void Move::generate_16b_fill_segment(char& data,Token<Tokens>* token) const
    {
        switch(token->token)
        {
        case Tokens::ES:
            data = data << 2;//ES 0b00
            break;
        case Tokens::CS:
            data = data << 2;//CS 0b01
            data += 0b01;
            break;
        case Tokens::SS:
            data = data << 2;//SS 0b10
            data += 0b10;
            break;
        case Tokens::DS:
            data = data << 2;//DS 0b11
            data += 0b11;
            break;
        default:
            ;
        }
    }
    void Move::generate_16b_register_register(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b100010;//1)opecode
        inst[0] = inst[0] << 1;//d? que es?, pero se que deve ser 0
        inst[0] = inst[0] << 1;
        inst[0]++; // w = 1
        inst[1] = 0;
        inst[1] += 0b11;//mod
        generate_fill_rm_16b(inst[1],source);
        generate_fill_rm_16b(inst[1],destine);
        out.write(inst,get_size_memory());
    }
    void Move::generate_8b_register_register(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b100010;//1)opecode
        inst[0] = inst[0] << 1;//d? que es?, pero se que deve ser 0
        inst[0] = inst[0] << 1;// w = 0
        inst[1] = 0;
        inst[1] += 0b11;//mod
        generate_8b_fill_register(inst[1],source);
        generate_8b_fill_register(inst[1],destine);
        out.write(inst,get_size_memory());
    }
    //>>memory
    void Move::generate_16b_register_memory(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Memory*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b10001011;//1)opecode 0b1000101 d w
        //generate_fill_w(inst[0],source);
        inst[1] = 0;
        //inst[1] += 0b00;//mod
        generate_fill_mod(inst[1],source);

        generate_fill_rm_16b(inst[1],destine);

        //inst[1] = inst[1] << 3;
        //inst[1] += 0b110;//r/m
        generate_fill_rm(inst[1],source);

        short& mem = (short&)inst[2];
        mem = (short)static_cast<constant_integer<integer>*>(source->address)->get_value();

        out.write(inst,get_size_memory());
    }
    void Move::generate_8b_register_memory(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Memory*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b10001010;//1)opecode
        inst[1] = 0;
        inst[1] += 0b00;//mod

        generate_8b_fill_register(inst[1],destine);
        generate_16b_fill_memory(inst[1],source);
        generate_fill_rm(inst[1],source);

        //short& mem = (short&)inst[2];
        //mem = (short)static_cast<constant_integer<integer>*>(source->address)->get_value();

        out.write(inst,get_size_memory());
    }
    void Move::generate_16b_fill_memory(char& data,const Memory* m) const
    {
        switch(m->rm)//reg
        {
        case 0:
            data = data << 3;
            break;
        case 1:
            data = data << 3;
            data = data + 0b001;
            break;
        case 2:
            data = data << 3;
            data = data + 0b010;
            break;
        case 3:
            data = data << 3;
            data = data + 0b011;
            break;
        case 4:
            data = data << 3;
            data = data + 0b100;
            break;
        case 5:
            data = data << 3;
            data = data + 0b101;
            break;
        case 6:
            data = data << 3;
            data = data + 0b110;
            break;
        case 7:
            data = data << 3;
            data = data + 0b111;
            break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
    }
    void Move::generate_16b_memory_register(std::ostream& out)const
    {
        auto destine = static_cast<Memory*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b10001001;//1)opecode
        inst[1] = 0;
        inst[1] += 0b00;//mod

        generate_fill_rm_16b(inst[1],source);

        //inst[1] = inst[1] << 3;
        //inst[1] += 0b110;//r/m
        generate_fill_rm(inst[1],destine);

        short& mem = (short&)inst[2];
        mem = (short)static_cast<constant_integer<integer>*>(destine->address)->get_value();

        out.write(inst,get_size_memory());
    }
    void Move::generate_16b_memory_integer(std::ostream& out)const
    {
        auto destine = static_cast<Memory*>(this->destine);
        auto source = static_cast<constant_integer<integer>*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b11000111;//1)opecode
        inst[1] = 0;
        //inst[1] += 0b00;//mod
        generate_fill_mod(inst[1],destine);
        inst[1] = inst[1] << 3; //000
        //inst[1] = inst[1] << 3;
        //inst[1] += 0b110;//r/m
        generate_fill_rm(inst[1],destine);
        short& mem = (short&)inst[2];
        mem = (short)static_cast<constant_integer<integer>*>(destine->address)->get_value();
        short& dat = (short&)inst[4];
        dat = (short)source->get_value();

        out.write(inst,get_size_memory());
    }
    void Move::generate_8b_memory_char(std::ostream& out)const
    {
        auto destine = static_cast<Memory*>(this->destine);
        auto source = static_cast<charater_constant<char>*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b11000110;//1)opecode
        inst[1] = 0;
        //inst[1] += 0b00;//mod
        generate_fill_mod(inst[1],destine);
        inst[1] = inst[1] << 3; //000
        //inst[1] = inst[1] << 3;
        //inst[1] += 0b110;//r/m
        generate_fill_rm(inst[1],destine);
        short& mem = (short&)inst[2];
        mem = (short)static_cast<constant_integer<integer>*>(destine->address)->get_value();
        inst[4] = source->value;

        out.write(inst,get_size_memory());
    }
    void Move::generate_16b_segment_memory(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Memory*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b10001110;
        inst[1] = 0;
        //inst[1] = inst[1] << 2;//mod 00
        generate_fill_mod(inst[1],source);
        inst[1] = inst[1] << 1;//add 0b0
        generate_16b_fill_segment(inst[1],destine);
        //inst[1] = inst[1] << 3;//preparando par rm
        //inst[1] += 0b110;//rm
        generate_fill_rm(inst[1],source);
        short& mem = (short&)inst[2];
        mem = (short)static_cast<constant_integer<integer>*>(source->address)->get_value();

        out.write(inst,get_size_memory());
    }
    void Move::generate_16b_memory_segment(std::ostream& out)const
    {
        auto destine = static_cast<Memory*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char inst[get_size_memory()];
        inst[0] = 0b10001100;
        inst[1] = 0;
        //inst[1] = inst[1] << 2;//mod 0x00
        generate_fill_mod(inst[1],destine);
        inst[1] = inst[1] << 1;//add 0b0
        generate_16b_fill_segment(inst[1],source);

        //inst[1] = inst[1] << 3;//preparando par rm
        //inst[1] += 0b110;//rm
        generate_fill_rm(inst[1],destine);

        short& mem = (short&)inst[2];
        mem = (short)static_cast<constant_integer<integer>*>(destine->address)->get_value();

        out.write(inst,get_size_memory());
    }
    //opcode data
    void Move::generate_fill_mod(char& data,const Memory* mem)const
    {
        switch(mem->mod)
        {
        case 0:
            data = data << 2;
            break;
        case 1:
            data = data << 2;
            data++;
            break;
        case 2:
            data = data << 2;
            data = data + 2;
            break;
        case 3:
            data = data << 2;
            data = data + 3;
            break;
        }
    }
    void Move::generate_fill_rm(char& data,const Memory* m) const
    {
        switch(m->rm)
        {
        case 0:
            data = data << 3;
            break;
        case 1:
            data = data << 3;
            data = data + 0b001;
            break;
        case 2:
            data = data << 3;
            data = data + 0b010;
            break;
        case 3:
            data = data << 3;
            data = data + 0b011;
            break;
        case 4:
            data = data << 3;
            data = data + 0b100;
            break;
        case 5:
            data = data << 3;
            data = data + 0b101;
            break;
        case 6:
            data = data << 3;
            data = data + 0b110;
            break;
        case 7:
            data = data << 3;
            data = data + 0b111;
            break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
    }
    void Move::generate_fill_rm_8b(char& data,const Token<Tokens>* token) const
    {
        switch(token->token)//reg
        {
            case Tokens::AL:
                data = data << 3;
                break;
            case Tokens::CL:
                data = data << 3;
                data = data + 0b001;
                break;
            case Tokens::DL:
                data = data << 3;
                data = data + 0b010;
                break;
            case Tokens::BL:
                data = data << 3;
                data = data + 0b011;
                break;
            case Tokens::AH:
                data = data << 3;
                data = data + 0b100;
                break;
            case Tokens::CH:
                data = data << 3;
                data = data + 0b101;
                break;
            case Tokens::DH:
                data = data << 3;
                data = data + 0b110;
                break;
            case Tokens::BH:
                data = data << 3;
                data = data + 0b111;
                break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
    }
    void Move::generate_fill_rm_16b(char& data,const Token<Tokens>* token) const
    {
        switch(token->token)//reg
        {
        case Tokens::AX:
            data = data << 3;
            break;
        case Tokens::CX:
            data = data << 3;
            data = data + 0b001;
            break;
        case Tokens::DX:
            data = data << 3;
            data = data + 0b010;
            break;
        case Tokens::BX:
            data = data << 3;
            data = data + 0b011;
            break;
        case Tokens::SP:
            data = data << 3;
            data = data + 0b100;
            break;
        case Tokens::BP:
            data = data << 3;
            data = data + 0b101;
            break;
        case Tokens::SI:
            data = data << 3;
            data = data + 0b110;
            break;
        case Tokens::DI:
            data = data << 3;
            data = data + 0b111;
            break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
    }




    void Interruption::generate(std::ostream& out) const
    {
        char instruction[2];
		instruction[0] = 0b11001101;//opcode
		instruction[1] = (char)service->get_value();
		out.write((char*)&instruction,2);
    }
    void Interruption::print(std::ostream& out) const
    {
        //out << "void Interruption::print(std::ostream& out) const\n";
        out << "\n\tint " << service->get_value() << "";
    }



    void Label::generate(std::ostream& out) const
    {
    }
    void Label::print(std::ostream& out) const
    {
        //out << "void Label::print(std::ostream& out) const\n";
    }




    void Return::generate(std::ostream& out) const
    {
        char instruction = 0b11000011;
		out.write(&instruction,1);
    }
    void Return::print(std::ostream& out) const
    {
        out << "ret\n";
    }
}
