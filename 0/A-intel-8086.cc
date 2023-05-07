


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
                auto destine = reinterpret_cast<Token<Tokens>*>(this->destine);
                auto source = reinterpret_cast<Token<integer>*>(this->source);
                out << "\n\tmov " << register_to_string(destine->token) << " ";
                out << source->token;
            }
            break;
        case operands_type::regiter_char:
            {
                auto destine = reinterpret_cast<Token<Tokens>*>(this->destine);
                auto source = reinterpret_cast<Token<char>*>(this->source);
                out << "\n\tmov " << register_to_string(destine->token) << " ";
                out << "'" << source->token << "'";
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
                //generate_16b_inmediate(out);
                break;
            default:
                ;
            }
            break;
        default:
            ;
        }
    }
    /*void Move::generate_8b_inmediate(std::ostream& out)const
    {
        auto destine = reinterpret_cast<Token<Tokens>*>(this->destine);
        auto source = reinterpret_cast<constant_integer<integer>*>(this->source);

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
    }*/
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
    void Move::generate_16b_inmediate(std::ostream& out)const
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
    /*
    void move_8b_reg_byte::generate(std::ostream& out) const
    {
        unsigned char instruction[2];
        instruction[0] = 0b1011;//opcode
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        instruction[0] = instruction[0] << 1;//w = one byte
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        switch(registe)//reg
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
        instruction[1] = byte;
        //std::cout << (int)instruction[0] << " register-8b integer\n";
        out.write((char*)&instruction,2);
    }
    void move_8b_reg_byte::print(std::ostream& out) const
    {
        out << "\n\tmov " << register_to_string(registe) << " ";
        if(type == 'C') out << "'" << (char)byte << "'";
        else if(type == 'I') out << (int)byte;
    }
    */





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
