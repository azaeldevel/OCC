


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

#include <A/oas-intel-parser.hh>

#include <limits>
#include <core/3/Exception.hh>
#include <core/3/math.hh>
#include <limits>
#include <cstring>


#include "A.hh"



namespace oct::cc::v0::AI
{



File::File() : file(NULL),buffer(NULL),scanner(NULL)
{
}


void* File::get_scanner()
{
	return scanner;
}



const std::filesystem::path& File::get_filename() const
{
	return filename;
}


namespace nodes
{
    const char* register_to_string(Tokens tk)
    {
        switch(tk)
        {
            case Tokens::AL : return "AL";
            case Tokens::AH : return "AH";
            case Tokens::AX : return "AX";
            case Tokens::BL : return "BL";
            case Tokens::BH : return "BH";
            case Tokens::BX : return "BX";
            case Tokens::CL : return "CL";
            case Tokens::CH : return "CH";
            case Tokens::CX : return "CX";
            case Tokens::DL : return "DL";
            case Tokens::DH : return "DH";
            case Tokens::DX : return "DX";
            case Tokens::SP : return "SP";
            case Tokens::BP : return "BP";
            case Tokens::SI : return "SI";
            case Tokens::DI : return "DI";
            default:
                return "unknow";
        }
    }
    const char* segment_to_string(Tokens tk)
    {
        switch(tk)
        {
            case Tokens::ES : return "ES";
            case Tokens::CS : return "CS";
            case Tokens::SS : return "SS";
            case Tokens::DS : return "DS";
            default:
                return "unknow";
        }
    }
    const char* type_specifier_to_string(Tokens type)
    {
        switch(type)
        {
            case Tokens::VOID :
                return "void";
            case Tokens::CHAR :
                return "char";
            case Tokens::SHORT :
                return "short";
            case Tokens::INT :
                return "int";
            case Tokens::LONG :
                return "long";
            case Tokens::FLOAT :
                return "float";
            case Tokens::DOUBLE :
                return "double";
            case Tokens::SIGNED :
                return "signed";
            case Tokens::UNSIGNED :
                return "unsigned";
			default:
				return "unknow";
        }
    }

    bool is_type_specifier(Tokens type)
    {
        switch(type)
        {
            case Tokens::VOID :
            case Tokens::CHAR :
            case Tokens::SHORT :
            case Tokens::INT :
            case Tokens::LONG :
            case Tokens::FLOAT :
            case Tokens::DOUBLE :
            case Tokens::SIGNED :
            case Tokens::UNSIGNED :
                return true;
			default:
				return false;
        }

        return false;
    }

    const char* type_qualifier_to_string(Tokens type)
    {
        switch(type)
        {
            case Tokens::CONST :
                return "const";
            case Tokens::VOLATIL :
                return "volatil";
			default:
				return "unknow";
        }
    }
    bool is_type_qualifier(Tokens type)
    {
        switch(type)
        {
            case Tokens::CONST :
            case Tokens::VOLATIL :
                return true;
			default:
				return false;
        }

        return false;
    }


    Node::Node() : next(NULL),symbol_type('\n'),type(Node::Type::none)
    {
    }
    Node::Node(Type t) : next(NULL),symbol_type('\n'),type(t)
    {
    }
    Node* Node::get()
    {
        return Node::next;
    }
    void Node::set(Node* n)
    {
        Node::next = n;
    }


    Expression::Expression() : Branch(Node::Type::expression)
    {
    }
    Expression::Expression(Type t) : Branch(t)
    {
    }



    Parenthesis::Parenthesis() : Expression(Node::Type::parenthesis)
    {
    }

    Unary::Unary() : Expression(Node::Type::unary)
    {
    }


    Cast::Cast() : Expression(Node::Type::cast)
    {
    }

    statement::statement() : is_instruction(false)
    {
    }
    void statement::print(std::ostream&)const
    {
    }


    Branch::Branch() : Node(Node::Type::none)
    {
    }
    Branch::Branch(Node::Type t) : Node(t)
    {
    }
    Node*& Branch::operator [](size_t i)
    {
        Node** n = (Node**)next;
        return n[i];
    }
    Node*& Branch::at(size_t i)
    {
        Node** n = (Node**)next;
        return n[i];
    }
    const Node*& Branch::at(size_t i)const
    {
        const Node** n = (const Node**)next;
        return n[i];
    }
    Node** Branch::create(size_t leng, core_here::Block& block)
    {
        Node::next = (Node*)block.array<Node*>(leng);
        return (Node**) Node::next;
    }


    Suma::Suma() : Expression(Node::Type::suma)
    {
    }
    void Suma::set(Node* a, Node* b, core_here::Block& block, Expression::Operator op)
    {
        next = (Node*)block.create<Node*,2>();
        Branch::length = 2;
        oper = op;

        std::cout << "at(0) -> " << at(0) << "\n";
        std::cout << "at(1) -> " << at(1) << "\n";
        at(0) = a;
        at(1) = b;
        std::cout << "at(0) -> " << at(0) << "\n";
        std::cout << "at(1) -> " << at(1) << "\n";
    }

    void Suma::print(std::ostream& out,const Node* node)const
    {
        switch(node->type)
        {
        case Node::Type::constant_integer:
                ((const constant_integer<integer>*)node)->print(out);
            break;
        case Node::Type::constant_char:

            break;
        case Node::Type::identifier:

            break;
        case Node::Type::registers:
                out << register_to_string(((const Token<Tokens>*)node)->token);
            break;
        case Node::Type::segment:
                out << segment_to_string(((const Token<Tokens>*)node)->token);
            break;
        default:
                ;
        }
    }
    void Suma::print(std::ostream& out)const
    {
        if(at(0)) print(out,at(0));
        if(at(1)) print(out,at(1));
    }


    Multiplication::Multiplication() : Expression(Node::Type::mult)
    {
    }
    void Multiplication::set(Node* a, Node* b, core_here::Block& block, Expression::Operator op)
    {
        next = (Node*)block.create<Node*,2>();
        Branch::length = 2;
        oper = op;

    }



    identifier::identifier() : Node(Node::Type::identifier)
    {
    }

    constant::constant() : Node(Node::Type::constant)
    {
    }
    constant::constant(Node::Type t) : Node(t)
    {
    }


    template<> void constant_integer<integer>::sizes()
    {
        //std::cout << "template<> void constant_integer<integer>::sizes()\n";
        //std::cout << "Step 1\n";
        if(suffix_l)
        {
            //std::cout << "sufijo long\n";
            data_size =  8 * sizeof(long);
            return;
        }
        //std::cout << "Step 2\n";
        if(format == Format::hexadecimal)
        {
            //std::cout << "Format hexadecimal\n";
            data_size = string.size() - 2;//cantidad ed nibbles
            //std::cout << "Format hexadecimal : " << data_size << "\n";
            if(suffix_l) data_size--;
            if(suffix_u) data_size--;
            data_size /= 2;
            data_size *= 8;

            return;
        }
        //std::cout << "Step 3\n";

        if(value < integer(0))
        {
            if((integer)std::numeric_limits<signed char>::min() <= value)
            {
                //std::cout << "type : signed char\n";
                data_size = 8;
                type_data = Tokens::CHAR;
                type_singed = Tokens::SIGNED;
                return;
            }
            else if((integer)std::numeric_limits<short>::min() <= value)
            {
                //std::cout << "type : short\n";
                data_size =  8 * sizeof(short);
                type_singed = Tokens::SIGNED;
                type_data = Tokens::SHORT;
                return;
            }
            else if((integer)std::numeric_limits<int>::min() <= value)
            {
                //std::cout << "type : int\n";
                data_size =  8 * sizeof(int);
                type_data = Tokens::INT;
                type_singed = Tokens::SIGNED;
                return;
            }
            else if(std::numeric_limits<long>::min() <= value)
            {
                //std::cout << "type : long\n";
                data_size =  8 * sizeof(signed long);
                type_data = Tokens::LONG;
                type_singed = Tokens::SIGNED;
                return;
            }
        }
        else if(value > integer(0))
        {
            if((integer)std::numeric_limits<signed char>::max() >= value)
            {
                //std::cout << "type : signed char\n";
                data_size = 8;
                type_data = Tokens::CHAR;
                type_singed = Tokens::SIGNED;
                //std::cout << "type : signed char : " << data_size << "\n";
                return;
            }
            else if(integer(std::numeric_limits<unsigned char>::max()) >= value)
            {
                //std::cout << "type : unsigned char\n";
                data_size =  8;
                type_data = Tokens::CHAR;
                type_singed = Tokens::UNSIGNED;
                return;
            }
            else if(integer(std::numeric_limits<short>::max()) >= value)
            {
                //std::cout << "type : short\n";
                data_size =  8 * sizeof(short);
                type_data = Tokens::SHORT;
                type_singed = Tokens::SIGNED;
                return;
            }
            else if(integer(std::numeric_limits<unsigned short>::max()) >= value)
            {
                //std::cout << "type : short\n";
                data_size =  8 * sizeof(short);
                type_data = Tokens::SHORT;
                type_singed = Tokens::UNSIGNED;
                return;
            }
            else if(integer(std::numeric_limits<int>::max()) >= value)
            {
                //std::cout << "type : int\n";
                data_size =  8 * sizeof(int);
                type_data = Tokens::INT;
                type_singed = Tokens::SIGNED;
                return;
            }
            else if(integer(std::numeric_limits<unsigned int>::max()) >= value)
            {
                //std::cout << "type : int\n";
                data_size =  8 * sizeof(int);
                type_data = Tokens::INT;
                type_singed = Tokens::UNSIGNED;
                return;
            }
            else if(integer(std::numeric_limits<long>::max()) >= value)
            {
                //std::cout << "type : long\n";
                data_size =  8 * sizeof(long);
                type_data = Tokens::LONG;
                type_singed = Tokens::SIGNED;
                return;
            }
            else if(integer(std::numeric_limits<unsigned long>::max()) >= value)
            {
                //std::cout << "type : long\n";
                data_size =  8 * sizeof(long);
                type_data = Tokens::LONG;
                type_singed = Tokens::UNSIGNED;
                return;
            }
            else
            {
                //std::cout << "type : unknow\n";
            }
        }
        else
        {
            //std::cout << "type : signed char\n";
            data_size = 8;
            type_data = Tokens::CHAR;
        }

        //std::cout << "Step 4\n";
    }
    template<> void constant_integer<integer>::set(const std::string& s,Format f)
    {
        //std::cout << "Step 1\n";
        //std::cout << "Number : " << s << "\n";
        string = s;
        format = f;
        Node::type = Node::Type::constant_integer;

        suffix_u = false;
        suffix_l = false;
        for(size_t i = string.size()  - 1; i >= 0; i--)
        {
            switch(string[i])
            {
            case 'u':
            case 'U':
                suffix_u = true;
                break;
            case 'l':
            case 'L':
                suffix_l = true;
                break;
            default:
                goto end;
                break;
            }
        }

    end:
        switch(format)
        {
        case Format::decimal:
            value = std::stoll(string);
            break;
        case Format::hexadecimal:
            value = std::stoll(string,nullptr,16);
            break;
        case Format::octal:
            value = std::stoll(string,nullptr,8);
            break;
        case Format::binary:
            value = std::stoll(string,nullptr,2);
            break;
        default:
            value = 0;
        }

        //std::cout << "Value : " << value << "\n";

        sizes();
    }
    template<> void constant_integer<integer>::set(const std::string& s,Format f,Tokens t)
    {
        token = t;
        set(s,f);
    }


    template<> bool constant_integer<integer>::is_data_8b()const
    {
        return data_size == 8;
    }
    template<> bool constant_integer<integer>::is_data_16b()const
    {
        return data_size == 16;
    }


    size_t instruction::get_size_memory()const
    {
        return 0;
    }


    size_t Move::get_size_memory()const
    {
        switch(op_type)
        {
        case operands_type::regiter_integer:
            if(word_size == 8) return 2;
            else if(word_size == 16) return 3;
            return 0;
        case operands_type::regiter_char:
            if(word_size == 8) return 2;
            return 0;
        case operands_type::segment_register:
            return 2;
        case operands_type::register_segment:
            return 2;
        case operands_type::register_register:
            return 2;
        case operands_type::register_memory:
            if(word_size == 8) return 2;
            else if(word_size == 16) return 4;
            return 0;
        case operands_type::memory_register:
            return 4;
        case operands_type::memory_integer:
            if(word_size == 8) return 5;
            else if(word_size == 16) return 6;
            return 0;
        case operands_type::memory_char:
            if(word_size == 8) return 5;
            return 0;
        case operands_type::segment_memory:
        case operands_type::memory_segment:
            return 4;
        default:
            return 0;
        }

        return 0;
    }
    size_t Move::get_size_memory(const Memory* m)const
    {
        switch(op_type)
        {
        case operands_type::regiter_integer:
            if(word_size == 8) return 2;
            else if(word_size == 16) return 3;
            return 0;
        case operands_type::regiter_char:
            if(word_size == 8) return 2;
            return 0;
        case operands_type::segment_register:
            return 2;
        case operands_type::register_segment:
            return 2;
        case operands_type::register_register:
            return 2;
        case operands_type::register_memory:
            //if(m->mod == 1)
            if(word_size == 8) return 2;
            else if(word_size == 16) return 4;
            return 0;
        case operands_type::memory_register:
            return 4;
        case operands_type::memory_integer:
            if(word_size == 8) return 5;
            else if(word_size == 16) return 6;
            return 0;
        case operands_type::memory_char:
            if(word_size == 8) return 5;
            return 0;
        case operands_type::segment_memory:
        case operands_type::memory_segment:
            return 4;
        default:
            return 0;
        }

        return 0;
    }

    size_t Interruption::get_size_memory()const
    {
        return 2;
    }



    size_t Return::get_size_memory()const
    {
        return 1;
    }



    void Memory::set(unsigned char m, unsigned char r,core_here::Block& block)
    {
        mod = m;
        rm = r;
        offset = false;
        offset_size = 0;
    }
    void Memory::set(unsigned char m, unsigned char r,core_here::Block& block,unsigned char wz)
    {
        set(m,r,block);
        offset = true;
        offset_size = wz;
    }
    const char* Memory::to_string() const
    {
        switch(mod)
        {
        case 0:
            switch(rm)
            {
            case 0:
                return "[ BX + SI ]";
            case 1:
                return "[ BX + DI ]";
            case 2:
                return "[ BP + SI ]";
            case 3:
                return "[ BP + DI ]";
            case 4:
                return "[ SI ]";
            case 5:
                return "[ DI ]";
                break;
            case 6:
                return "[ driect address ]";
            case 7:
                return "[ BX ]";
            }
        case 1:
            switch(rm)
            {
            case 0:
                return "[ BX + SI + off_8b]";
            case 1:
                return "[ BX + DI + off_8b]";
            case 2:
                return "[ BP + SI + off_8b]";
            case 3:
                return "[ BP + DI + off_8b]";
            case 4:
                return "[ SI + off_8b]";
            case 5:
                return "[ DI + off_8b]";
                break;
            case 6:
                return "[ BP + off_8b ]";
            case 7:
                return "[ BX + off_8b]";
            }
        case 2:
            switch(rm)
            {
            case 0:
                return "[ BX + SI + off_16b]";
            case 1:
                return "[ BX + DI + off_16b]";
            case 2:
                return "[ BP + SI + off_16b]";
            case 3:
                return "[ BP + DI + off_16b]";
            case 4:
                return "[ SI + off_16b]";
            case 5:
                return "[ DI + off_16b]";
                break;
            case 6:
                return "[ BP + off_16b ]";
            case 7:
                return "[ BX + off_16b]";
            }
        case 3:
            return "Unknow Memory";
        default:
            return "Unknow Memory";
        }

        return "Unknow Memory";
    }
    void Memory::print(std::ostream& out) const
    {
        switch(mod)
        {
        case 0:
            switch(rm)
            {
            case 0:
                out << "[ BX + SI ]";
                break;
            case 1:
                out << "[ BX + DI ]";
                break;
            case 2:
                out << "[ BP + SI ]";
                break;
            case 3:
                out << "[ BP + DI ]";
                break;
            case 4:
                out << "[ SI ]";
                break;
            case 5:
                out << "[ DI ]";
                break;
            case 6:
                out << "[ ";
                ((constant_integer<integer>*)address)->print(out);
                out << " ]";
                break;
            case 7:
                out << "[ BX ]";
                break;
            }
            break;
        case 1:
            switch(rm)
            {
            case 0:
                out << "[ BX + SI + off_8b]";
                break;
            case 1:
                out << "[ BX + DI + off_8b]";
                break;
            case 2:
                out << "[ BP + SI + off_8b]";
                break;
            case 3:
                out << "[ BP + DI + off_8b]";
                break;
            case 4:
                out << "[ SI + off_8b]";
                break;
            case 5:
                out << "[ DI + off_8b]";
                break;
            case 6:
                out << "[ BP + off_8b ]";
                break;
            case 7:
                out << "[ BX + off_8b]";
                break;
            }
            break;
        case 2:
            switch(rm)
            {
            case 0:
                out << "[ BX + SI + off_16b]";
                break;
            case 1:
                out << "[ BX + DI + off_16b]";
                break;
            case 2:
                out << "[ BP + SI + off_16b]";
                break;
            case 3:
                out << "[ BP + DI + off_16b]";
                break;
            case 4:
                out << "[ SI + off_16b]";
                break;
            case 5:
                out << "[ DI + off_16b]";
                break;
            case 6:
                out << "[ BP + off_16b ]";
                break;
            case 7:
                out << "[ BX + off_16b]";
                break;
            }
            break;
        case 3:
            out << "Unknow Memory";
            break;
        default:
            out << "Unknow Memory";
            break;
        }
    }
    void Memory::set(const Base* base)
    {
        //std::cout << "void Memory::set(const Base* base)\n";
        mod = 0;
        rm = get_rm(base);
    }
    void Memory::set(const Base* base,constant_integer<integer>* number)
    {
        //std::cout << "void Memory::set(const Base* base,constant_integer<integer>* number)\n";
        if(number->is_data_8b()) mod = 1;
        else if(number->is_data_16b()) mod = 2;

        rm = get_rm(base);
        address = number;
    }
    unsigned char Memory::get_rm(const Base* base) const
    {
        if(base->base == Tokens::BX)
        {
            if(base->index == Tokens::SI)
            {
                return 1;
            }
            else if(base->index == Tokens::DI)
            {
                return 2;
            }
        }
        else if(base->base == Tokens::BP)
        {
            if(base->index == Tokens::SI)
            {
                return 3;
            }
            else if(base->index == Tokens::DI)
            {
                return 4;
            }
        }
        if(base->index == Tokens::SI)
        {
            return 5;
        }
        else if(base->index == Tokens::DI)
        {
            return 6;
        }
        if(base->index == Tokens::BP)
        {
            return 7;
        }
        else if(base->index == Tokens::BX)
        {
            return 8;
        }

        return 127;
    }
    void Memory::set(Tokens t)
    {
        //std::cout << "void Memory::set(Tokens t)\n";
        mod = 0;
        rm = get_rm(t);
    }
    unsigned char Memory::get_rm(Tokens t) const
    {
        switch(t)
        {
        case Tokens::SI:
            return 5;
        case Tokens::DI:
            return 6;
        case Tokens::BP:
            return 7;
        case Tokens::BX:
            return 8;
        default:
            return 127;
        }

        return 127;
    }
    void Memory::set(Tokens t,constant_integer<integer>* number)
    {
        //std::cout << "void Memory::set(Tokens t,constant_integer<integer>* number)\n";
        if(number->is_data_8b()) mod = 1;
        else if(number->is_data_16b()) mod = 2;

        rm = get_rm(t);
        address = number;
    }
    void Memory::set(constant_integer<integer>* number)
    {
        //std::cout << "void Memory::set(constant_integer<integer>* number)\n";
        mod = 0;
        rm = 6;
        address = number;
    }










    /*void initializer::print(std::ostream& out)const
    {
        //std::cout << "void init_declarator::print(std::ostream& out)const\n";
        if(data_type == Tokens::CONSTANT_CHAR)
        {
            //std::cout << "Tokens::LITERAL_CHAR\n";
            const initializer_literal<char>* literial = reinterpret_cast<const initializer_literal<char>*>(this);
            literial->print(out);
        }
        else if(data_type == Tokens::CONSTANT_INTEGER_HEX or data_type == Tokens::CONSTANT_INTEGER_DEC)
        {
            //std::cout << "Tokens::LITERAL_..\n";
            const initializer_literal<long long>* literial = reinterpret_cast<const initializer_literal<long long>*>(this);
            literial->print(out);
        }
        else
        {
                //std::cout << "no se encotro constate\n";
        }
    }*/


    void init_declarator::print(std::ostream& out)const
    {
        //std::cout << "void init_declarator::print(std::ostream& out)const\n";
        if(dec) dec->print(out);
        if(value)
        {
            out << " ";
            value->print(out);
        }
    }


    void direct_declarator::print(std::ostream& out)const
    {
        //std::cout << "void direct_declarator::print(std::ostream& out)const\n";
        //std::cout << " id : " << id << "\n";
        //std::cout << " id : " << id->string << "\n";
        if(id) out << id->string;
    }

    void declarator::print(std::ostream& out)const
    {
        if(direct) direct->print(out);
    }
    void declarator::generate(std::ostream& out) const
    {
        ;
    }
    identifier* declarator::get_name() const
    {
        return direct->id;
    }

    void type_specifier::print(std::ostream& out)const
    {
        switch(type)
        {
            case Tokens::VOID :
                out << "void";
                break;
            case Tokens::CHAR :
                out << "char";
                break;
            case Tokens::SHORT :
                out << "short";
                break;
            case Tokens::INT :
                out << "int";
                break;
            case Tokens::LONG :
                out << "long";
                break;
            case Tokens::FLOAT :
                out << "float";
                break;
            case Tokens::DOUBLE :
                out << "double";
                break;
            case Tokens::SIGNED :
                out << "signed";
                break;
            case Tokens::UNSIGNED :
                out << "unsigned";
                break;
            case Tokens::BYTE :
                out << "byte";
                break;
			default:
				;
        }
    }
    void type_specifier::generate(std::ostream& out) const
    {
        ;
    }


    void declaration::print(std::ostream& out)const
    {
        //std::cout << "void declaration::print(std::ostream& out)const\n";
        //std::cout << "Step declaration 1\n";
        Token<Tokens>* spec = specifiers;
        const char* str;

        while(spec)
        {
            if(is_type_specifier(spec->token))
            {
                str = type_specifier_to_string(spec->token);
            }
            else if(is_type_qualifier(spec->token))
            {
                str = type_qualifier_to_string(spec->token);
            }
            else
            {
                str = "unknow";
            }
            out << str << " ";
            spec = (Token<Tokens>*)spec->next;
        }

        //std::cout << "Step declaration 2\n";
        init_declarator* dec = list;
        while(dec)
        {
            dec->print(out);
            if(dec->next) out << ", ";

            dec = (init_declarator*)dec->next;
        }
        out << ";";
        //std::cout << "Step 3\n";
    }
    void declaration::generate(std::ostream& out) const
    {
        ;
    }
    bool declaration::semantic()const
    {

        return true;
    }




    void function::print(std::ostream& out)const
    {
        //std::cout << "void function::print(std::ostream& out)const\n";
        //std::cout << "Step 1\n";
        if(not body_list) return;
        //std::cout << "Step 2\n";
        if(id) out << "\n" << id->string << ":";
        //std::cout << "Step 3\n";
        statement* inst = (statement*)body_list;
        //std::cout << "Step 4\n";
        while(inst)
        {
            //std::cout << "Step 4.1\n";
            if(inst->is_instruction)
            {
                switch(((instruction*)inst)->inst)
                {
                    case Tokens::MOV :
                        //std::cout << "Step 4.1.1\n";
                        ((Move*)inst)->print(out);
                        break;
                    case Tokens::INT :
                        //std::cout << "Step 4.1.2\n";
                        ((instruction*)inst)->print(out);
                        break;
                    case Tokens::RET :
                        //std::cout << "Step 4.1.3\n";
                        out << "\n\tret;\n";
                        break;
                    default:
                        ;
                }
            }
            //std::cout << "Step 4.2\n";
            inst = (statement*)inst->next;
            //std::cout << "Step 4.3\n";
        }
        //std::cout << "Step 5\n";
    }
    void function::generate(std::ostream& out) const
    {
        statement* inst = (statement*)body_list;
        while(inst)
        {
            if(inst->is_instruction)
            {
                switch(((instruction*)inst)->inst)
                {
                    case Tokens::MOV :
                        ((Move*)inst)->generate(out);
                        break;
                    case Tokens::INT :
                        ((Interruption*)inst)->generate(out);
                        break;
                    case Tokens::RET :
                        ((intel::i8086::Return*)inst)->generate(out);
                        break;
                    default:
                        ;
                }
            }
            inst = (statement*)inst->next;
        }
    }
    bool function::semantic()
    {
        //std::cout << "bool function::semantic()\n";
        id->size = 0;
        statement* stmt = (statement*)body_list;
        instruction* inst = NULL;
        while(stmt)
        {
            if(stmt->is_instruction)
            {
                inst = ((instruction*)stmt);
                switch(inst->inst)
                {
                    case Tokens::MOV :
                        id->size += ((Move*)inst)->get_size_memory();
                        //std::cout << "id->size = " << id->size << "\n";
                        break;
                    case Tokens::INT :
                        id->size += ((Interruption*)inst)->get_size_memory();
                        break;
                    case Tokens::RET :
                        id->size += ((intel::i8086::Return*)inst)->get_size_memory();
                        break;
                    default:
                        core_here::exception("Instruccion desconocida");
                }
            }
            stmt = (statement*)stmt->next;
        }

        return true;
    }

    void translation_unit::print(std::ostream& out)const
    {
        //std::cout << "void translation_unit::print(std::ostream& out)const\n";
        //std::cout << "Step translation_unit 1\n";
        declaration* dec = declarations;
        while(dec)
        {
            //std::cout << "Step 1.1\n";
            dec->print(out);
            //std::cout << "Step 1.2\n";
            if(dec->next) out << "\n";
            //std::cout << "Step 1.3\n";

            dec = (declaration*)dec->next;
            //std::cout << "Step 1.4\n";
        }

        //std::cout << "Step translation_unit 2\n";
        function* func = functions;
        while(func)
        {
            //std::cout << "Step 1.1\n";
            func->print(out);
            //std::cout << "Step 1.2\n";
            if(func->next) out << "\n";
            //std::cout << "Step 1.3\n";

            func = (function*)func->next;
            //std::cout << "Step 1.4\n";
        }

        //std::cout << "Step translation_unit 3\n";
    }
    void translation_unit::generate(std::ostream& out) const
    {
        //std::cout << "void translation_unit::print(std::ostream& out)const\n";
        //std::cout << "Step 1\n";
        declaration* dec = declarations;
        while(dec)
        {
            //std::cout << "Step 1.1\n";
            //std::cout << "Step 1.2\n";
            //std::cout << "Step 1.3\n";
            dec = (declaration*)dec->next;
            //std::cout << "Step 1.4\n";
        }

        //std::cout << "Step 2\n";
        function* func = functions;
        while(func)
        {
            //std::cout << "Step 1.1\n";
            func->generate(out);
            //std::cout << "Step 1.2\n";
            //std::cout << "Step 1.3\n";

            func = (function*)func->next;
            //std::cout << "Step 1.4\n";
        }
        //std::cout << "Step 3\n";
    }

    bool translation_unit::semantic()
    {
        //std::cout << "void translation_unit::print(std::ostream& out)const\n";
        //std::cout << "Step 1\n";
        declaration* dec = declarations;
        while(dec)
        {
            //std::cout << "Step 1.1\n";
            dec->semantic();
            //std::cout << "Step 1.2\n";
            //std::cout << "Step 1.3\n";
            dec = (declaration*)dec->next;
            //std::cout << "Step 1.4\n";
        }

        //std::cout << "Step 2\n";
        function* func = functions;
        while(func)
        {
            //std::cout << "Step 1.1\n";
            func->semantic();
            //std::cout << "Step 1.2\n";
            //std::cout << "Step 1.3\n";

            func = (function*)func->next;
            //std::cout << "Step 1.4\n";
        }
        //std::cout << "Step 3\n";

        return true;
    }

}

    space::space() : nodes::Node(nodes::Node::Type::space)
    {
    }
    space::space(nodes::Node::Type t) : nodes::Node(t)
    {
    }

    SymbolTable::SymbolTable() : last_id(1)
    {
    }

    bool SymbolTable::add(nodes::declaration* d)
    {
        nodes::identifier* id = d->list->dec->direct->id;

        std::map<const char*,nodes::Node*>::iterator it;
        it = find(id->string.c_str());
        if(it != end()) return false;

        insert(std::pair<const char*,nodes::Node*>(id->string.c_str(),d));

        it = find(id->string.c_str());
        if(it != end())
        {
            id->size = get_size_of(get_data_type(d));
            //id->memory = last_memory_varibale;
            //last_memory_varibale += id->size + 1;//siguiente valor disponible
            id->number = last_id++;
            d->symbol_type = 'D';
            return true;
        }

        return false;
    }
    void SymbolTable::add(space* s)
    {
        insert(std::pair(s->name->string.c_str(),s));
    }
    bool SymbolTable::add(nodes::function* f)
    {
        nodes::identifier* id = f->id;
        //std::cout << "bool SymbolTable::add(nodes::function* f)\n";
        //std::cout << "Function : " << id->string << "\n";
        //std::cout << "Function size : " << id->size << "\n";
        std::map<const char*,nodes::Node*>::iterator it;
        it = find(id->string.c_str());
        if(it != end()) return false;

        insert(std::pair<const char*,nodes::Node*>(id->string.c_str(),f));

        it = find(id->string.c_str());
        if(it != end())
        {
            //id->size = 0;
            //id->memory = 0;
            //last_memory_function += id->size + 1;//asignar durante el analisis semantica
            id->number = last_id++;
            f->symbol_type = 'F';
            return true;
        }

        return false;
    }
    size_t SymbolTable::get_size_of(Tokens tk) const
    {
        switch(tk)
        {
        case Tokens::VOID :
            return 0;
        case Tokens::CHAR :
            return 1;
        case Tokens::SHORT :
            return 2;
        case Tokens::SIGNED:
        case Tokens::UNSIGNED:
        case Tokens::INT :
            return 4;
        case Tokens::LONG :
            return 8;
        case Tokens::FLOAT :
            return 8;
        case Tokens::DOUBLE :
            return 8;
        default:
            ;
        }
        return 0;
    }
    Tokens SymbolTable::get_data_type(nodes::declaration* d) const
    {
        nodes::Token<Tokens>* spec = d->specifiers;
        while(spec)
        {
            switch(spec->token)
            {
                case Tokens::VOID :
                    return Tokens::VOID;
                case Tokens::CHAR :
                    return Tokens::CHAR;
                case Tokens::SHORT :
                    return Tokens::SHORT;
                case Tokens::INT :
                    return Tokens::INT;
                case Tokens::LONG :
                    return Tokens::LONG;
                case Tokens::FLOAT :
                    return Tokens::FLOAT;
                case Tokens::DOUBLE :
                    return Tokens::DOUBLE;
                default:
                    if(not spec->next)
                    {
                        switch(spec->token)
                        {
                            case Tokens::SIGNED :
                                return Tokens::SIGNED;
                            case Tokens::UNSIGNED :
                                return Tokens::UNSIGNED;
                            default:
                                ;
                        }
                    }
            }

            spec = (nodes::Token<Tokens>*)spec->next;
        }
        return Tokens::VOID;
    }
    void SymbolTable::generate_memory()
    {
        size_t memory_pointer = 511;
        size_t last_memory_function = 0;
        std::map<const char*,nodes::Node*>::iterator it;
        it = find("main");
        if(it != end())
        {
            input_funtion = (AI_here::nodes::function*)it->second;
            input_funtion->id->memory = 0;
            last_memory_function += input_funtion->id->size + 1;
        }
        else
        {
            input_funtion = NULL;
        }

        AI_here::nodes::declaration* dec;
        AI_here::nodes::function* fun;
        for (auto const& [key, val] : *this)
        {
            if(last_memory_function >= memory_pointer)
            {
                std::cerr << "Sobrecarga de memoria: no hay espacio sufucentes para el programa.\n";
                return;
            }

            if(val->symbol_type == 'D')
            {
                dec = (AI_here::nodes::declaration*)val;
                memory_pointer -= dec->list->dec->direct->id->size;
                dec->list->dec->direct->id->memory = memory_pointer;
            }
            else if(val->symbol_type == 'F')
            {
                //if(strcmp(key, "main") == 0) continue;
                fun = (AI_here::nodes::function*)val;
                fun->id->memory = last_memory_function;
                last_memory_function += fun->id->size + 1;
            }
        }
    }
    void SymbolTable::print() const
    {
        std::cout << "Size table simbols : " << size() << "\n" ;
        unsigned dat1 = 0;
        AI_here::nodes::declaration* dec;
        AI_here::nodes::function* fun;
        for (auto const& [key, val] : *this)
        {
            dat1++;
            std::cout << dat1 << ".- " << key;
            if(val->symbol_type == 'D')
            {
                dec = (AI_here::nodes::declaration*)val;
                std::cout << " " << dec->list->dec->direct->id->number << " " << dec->list->dec->direct->id->memory << " size : " << dec->list->dec->direct->id->size;
            }
            else if(val->symbol_type == 'F')
            {
                fun = (AI_here::nodes::function*)val;
                std::cout << " " << fun->id->number << " " << fun->id->memory << " size : " << fun->id->size;
            }

            std::cout << "\n";
        }
    }

}
