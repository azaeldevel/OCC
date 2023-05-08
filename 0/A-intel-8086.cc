


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
        switch(destine->token)//reg
        {
            case Tokens::AL:
                instruction[0] = instruction[0] << 3;
                break;
            case Tokens::CL:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b001;
                break;
            case Tokens::DL:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b010;
                break;
            case Tokens::BL:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b011;
                break;
            case Tokens::AH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b100;
                break;
            case Tokens::CH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b101;
                break;
            case Tokens::DH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b110;
                break;
            case Tokens::BH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b111;
                break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
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
        switch(destine->token)//reg
        {
            case Tokens::AL:
                instruction[0] = instruction[0] << 3;
                break;
            case Tokens::CL:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b001;
                break;
            case Tokens::DL:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b010;
                break;
            case Tokens::BL:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b011;
                break;
            case Tokens::AH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b100;
                break;
            case Tokens::CH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b101;
                break;
            case Tokens::DH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b110;
                break;
            case Tokens::BH:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b111;
                break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
        instruction[1] = source->value;
        //std::cout << "Data : '" << source->value << "'\n";
        //std::cout << "Pointer : '" << (void*)source << "'\n";
        out.write((char*)&instruction,2);
    }
    void Move::generate_16b_register_integer(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<constant_integer<integer>*>(this->source);

        unsigned char instruction[3];
        instruction[0] = 0b1011;//opcode
        instruction[0] = instruction[0] << 1;
        instruction[0]++;//w = 1;one byte
        switch(destine->token)//reg
        {
            case Tokens::AX:
                instruction[0] = instruction[0] << 3;
                break;
            case Tokens::CX:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b001;
                break;
            case Tokens::DX:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b010;
                break;
            case Tokens::BX:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b011;
                break;
            case Tokens::SP:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b100;
                break;
            case Tokens::BP:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b101;
                break;
            case Tokens::SI:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b110;
                break;
            case Tokens::DI:
                instruction[0] = instruction[0] << 3;
                instruction[0] = instruction[0] + 0b111;
                break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
        //instruction[1] = source->token;
        short *data = (short*)&instruction[1];
        *data = (short)source->get_value();
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        out.write((char*)&instruction,3);
    }
    void Move::generate_segment_register(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char opcode = 0b10001100;
        char opinfo = 0;
        opinfo = opinfo << 2;//mod = 0b11
        //opinfo += 0b11;
        opinfo = opinfo << 1;//add 0b0
        switch(destine->token)
        {
        case Tokens::ES:
            opinfo = opinfo << 2;//ES 0b00
            break;
        case Tokens::CS:
            opinfo = opinfo << 2;//CS 0b01
            opinfo += 0b01;
            break;
        case Tokens::SS:
            opinfo = opinfo << 2;//SS 0b10
            opinfo += 0b10;
            break;
        case Tokens::DS:
            opinfo = opinfo << 2;//DS 0b11
            opinfo += 0b11;
            break;
        default:
            ;
        }
        switch(source->token)//reg
        {
            case Tokens::AX:
                opinfo = opinfo << 3;
                break;
            case Tokens::CX:
                opinfo = opinfo << 3;
                opinfo = opinfo + 0b001;
                break;
            case Tokens::DX:
                opinfo = opinfo << 3;
                opinfo = opinfo + 0b010;
                break;
            case Tokens::BX:
                opinfo = opinfo << 3;
                opinfo = opinfo + 0b011;
                break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }

        out.write((char*)&opcode,1);
        out.write((char*)&opinfo,1);
    }
    void Move::generate_register_segment(std::ostream& out)const
    {
        auto destine = static_cast<Token<Tokens>*>(this->destine);
        auto source = static_cast<Token<Tokens>*>(this->source);

        char opcode = 0b10001110;
        char opinfo = 0;
        opinfo = opinfo << 2;//mod = 0b11
        //opinfo += 0b11;
        opinfo = opinfo << 1;//add 0b0

        switch(destine->token)//reg
        {
            case Tokens::AX:
                opinfo = opinfo << 3;
                break;
            case Tokens::CX:
                opinfo = opinfo << 3;
                opinfo = opinfo + 0b001;
                break;
            case Tokens::DX:
                opinfo = opinfo << 3;
                opinfo = opinfo + 0b010;
                break;
            case Tokens::BX:
                opinfo = opinfo << 3;
                opinfo = opinfo + 0b011;
                break;
            default:
                //error
                throw core_here::exception("El operando no es un registro de 8 bits valido.");
                //std::cout << "Error in regiter identifiecation, code " << (int)$2 << "\n";
                break;
        }
        switch(source->token)
        {
        case Tokens::ES:
            opinfo = opinfo << 2;//ES 0b00
            break;
        case Tokens::CS:
            opinfo = opinfo << 2;//CS 0b01
            opinfo += 0b01;
            break;
        case Tokens::SS:
            opinfo = opinfo << 2;//SS 0b10
            opinfo += 0b10;
            break;
        case Tokens::DS:
            opinfo = opinfo << 2;//DS 0b11
            opinfo += 0b11;
            break;
        default:
            ;
        }
        //std::cout << "void Move::generate_register_segment(std::ostream& out)const\n";
        out.write((char*)&opcode,1);
        out.write((char*)&opinfo,1);
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
