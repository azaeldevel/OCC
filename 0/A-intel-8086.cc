


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
                generate_reg_integer(out);
                break;
            case operands_type::regiter_char:
                generate_reg_char(out);
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
            default:
                ;
            }
            break;
        default:
            ;
        }
    }
    void Move::generate_reg_integer(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<constant_integer<integer>*>(this->source);

        char instruction[2];
        instruction[0] = 0b1011;//opcode
        instruction[0] = instruction[0] << 1;//w = 0;one byte
        generate_8b_fill_register(instruction[0],destine);
        instruction[1] = (char)source->get_value();
        //sstd::cout << (int)instruction[0] << " register-8b integer\n";
        out.write((char*)&instruction,2);
    }
    void Move::generate_reg_char(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<charater_constant<char>*>(this->source);

        char instruction[2];
        instruction[0] = 0b1011;//opcode
        instruction[0] = instruction[0] << 1;//w = 0;one byte
        generate_8b_fill_register(instruction[0],destine);
        instruction[1] = source->value;
        //std::cout << "Data : '" << source->value << "'\n";
        //std::cout << "Pointer : '" << (void*)source << "'\n";
        out.write((char*)&instruction,2);
    }
    void Move::generate_16b_register_integer(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<constant_integer<integer>*>(this->source);

        char instruction[3];
        instruction[0] = 0b1011;//opcode
        instruction[0] = instruction[0] << 1;
        instruction[0]++;//w = 1;one byte
        generate_16b_fill_register(instruction[0],destine);
        short *data = (short*)&instruction[1];
        *data = (short)source->get_value();
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        out.write((char*)&instruction,3);
    }
    void Move::generate_segment_register(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char inst[2];
        inst[0] = 0b10001110;
        inst[1] = 0;
        inst[1] += 0b11;//mod
        inst[1] = inst[1] << 1;//add 0b0
        generate_16b_fill_segment(inst[1],destine);
        generate_16b_fill_register(inst[1],source);
        out.write(inst,2);
    }
    void Move::generate_register_segment(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char inst[2];
        inst[0] = 0b10001100;
        inst[1] = 0;
        inst[1] += 0b11;//mod
        inst[1] = inst[1] << 1;//add 0b0
        generate_16b_fill_segment(inst[1],source);
        generate_16b_fill_register(inst[1],destine);
        out.write(inst,2);
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




    void Interruption::generate(std::ostream& out) const
    {
        unsigned char instruction[2];
		instruction[0] = 0b11001101;//opcode
		instruction[1] = (unsigned char)service->get_value();
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
    }
    void Return::print(std::ostream& out) const
    {
        //out << "void Return::print(std::ostream& out) const\n";
    }
}
