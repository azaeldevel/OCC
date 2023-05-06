


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



    Node::Node() : next(NULL)
    {
    }

    statement::statement() : is_instruction(false)
    {
    }
    void statement::print(std::ostream&)const
    {
    }






    template<> void constant_integer<integer>::sizes()
    {
        if(suffix_l)
        {
            word_size =  8 * sizeof(long);
            return;
        }
        if(format == Format::hexadecimal)
        {
            word_size = string.size() - 2;//cantidad ed nibbles
            if(suffix_l) word_size--;
            if(suffix_u) word_size--;
            word_size /= 2;

            return;
        }

        if(value < 0)
        {
            if(std::numeric_limits<signed char>::min() > value)
            {
                word_size = 8;
                type = Tokens::CHAR;
                return;
            }
            else if(std::numeric_limits<signed short>::min() > value)
            {
                word_size =  8 * sizeof(signed int);
                type = Tokens::SHORT;
                return;
            }
            else if(std::numeric_limits<signed int>::min() > value)
            {
                word_size =  8 * sizeof(signed int);
                type = Tokens::INT;
                return;
            }
            else if(std::numeric_limits<signed long>::min() > value)
            {
                word_size =  8 * sizeof(signed long);
                type = Tokens::LONG;
                return;
            }
        }
        else
        {
            if(std::numeric_limits<char>::max() > value)
            {
                word_size = 8;
                type = Tokens::CHAR;
                return;
            }
            else if(std::numeric_limits<short>::max() > value)
            {
                word_size =  8 * sizeof(int);
                type = Tokens::SHORT;
                return;
            }
            else if(std::numeric_limits<int>::max() > value)
            {
                word_size =  8 * sizeof(int);
                type = Tokens::INT;
                return;
            }
            else if(std::numeric_limits<long>::max() > value)
            {
                word_size =  8 * sizeof(long);
                type = Tokens::LONG;
                return;
            }
        }
    }
    template<> void constant_integer<integer>::set(const std::string& s,Format f)
    {
        string = s;
        format = f;

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

        sizes();
    }


    template<> bool constant_integer<integer>::is_data_8b()const
    {
        return word_size == 8;
    }
    template<> bool constant_integer<integer>::is_data_16b()const
    {
        return word_size == 16;
    }
    template<> unsigned char constant_integer<integer>::data_size()const
    {
        return word_size;
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
        //std::cout << "Step 1\n";
        type_specifier* spec = specifiers;
        while(spec)
        {
            spec->print(out);
            out << " ";
            spec = (type_specifier*)spec->next;
        }

        //std::cout << "Step 2\n";
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
                        ((instruction*)inst)->print(out);
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
                        ;
                        break;
                    default:
                        ;
                }
            }
            inst = (statement*)inst->next;
        }
    }
    bool function::semantic()const
    {

        return true;
    }

    void translation_unit::print(std::ostream& out)const
    {
        //std::cout << "void translation_unit::print(std::ostream& out)const\n";
        //std::cout << "Step 1\n";
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

        //std::cout << "Step 2\n";
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

        //std::cout << "Step 3\n";
    }
    void translation_unit::generate(std::ostream& out) const
    {
        //std::cout << "void translation_unit::print(std::ostream& out)const\n";
        if(functions) functions->generate(out);
    }

}


    void SymbolTable::add(const nodes::declaration* d)
    {
        insert(std::pair(d->list->dec->direct->id->string.c_str(),d));
    }

    /*
    void SymbolTable::add(nodes::declarator* d)
    {
        insert(std::pair(d->direct->id->string.c_str(),d));
    }
    */

    void SymbolTable::add(const space* s)
    {
        insert(std::pair(s->name->string.c_str(),s));
    }

    void SymbolTable::add(const nodes::function* f)
    {
        insert(std::pair(f->id->string.c_str(),f));
    }


}
