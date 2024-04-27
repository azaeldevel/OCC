
#include "intel.hh"

#include <core/3/numbers.hh>

namespace oct::cc::v1::A::intel
{





    Move::Move(Register& nTo,Register& nFront) : from(nFront),to(nTo)
    {
        throw core::exception("Still developing..");
    }
    Move::Move(Register& nTo,Memory& nFront) : from(nFront),to(nTo)
    {
        throw core::exception("Still developing..");
    }
    Move::Move(Memory& nTo,Register& nFront) : from(nFront),to(nTo)
    {
        throw core::exception("Still developing..");
    }


    Move::Move(Register& nTo,Integer& nFront) : Instruction(Statemants::move,1 + nFront.size()),from(nFront),to(nTo)
    {
        mcode[0] = 0b1011;
        //mcode[0] <<= 4;
        //std::cout << "before : " << (int)mcode[0] << "\n";
        nTo.word(mcode[0]);
        nTo.rm(mcode[0]);
        //std::cout << "after : " << (int)mcode[0] << "\n";
        if(nFront.size() == 1)
        {
            mcode[1] = static_cast<char>(std::strtol(nFront.string().c_str(),NULL,nFront.base()));
        }
        else if(nFront.size() == 2)
        {
            *static_cast<short*>(static_cast<void*>(&mcode[1])) = static_cast<short>(std::strtol(nFront.string().c_str(),NULL,nFront.base()));
        }
        else
        {

        }
    }
    Move::Move(Register& nTo,Letter& nFront) : Instruction(Statemants::move,2),from(nFront),to(nTo)
    {
        mcode[0] = 0b1011;
        //std::cout << "before : " << (int)mcode[0] << "\n";
        nTo.word(mcode[0]);
        nTo.rm(mcode[0]);
        //std::cout << "afther : " << (int)mcode[0] << "\n";
        mcode[1] = nFront.letter();
    }
    Move::Move(Memory& nTo,Integer& nFront) : from(nFront),to(nTo)
    {
        throw core::exception("Still developing..");
    }
    Move::Move(Memory& nTo,Letter& nFront) : from(nFront),to(nTo)
    {
        throw core::exception("Still developing..");
    }
    Move::Move(Segment& nTo,Register& nFront) : from(nFront),to(nTo)
    {
        throw core::exception("Still developing..");
    }
    Move::Move(Segment& nTo,Memory& nFront) : from(nFront),to(nTo)
    {
        throw core::exception("Still developing..");
    }
    Move::Move(Register& nTo,Segment& nFront) : from(nFront),to(nTo)
    {
        throw core::exception("Still developing..");
    }
    Move::Move(Memory& nTo,Segment& nFront) : from(nFront),to(nTo)
    {
        throw core::exception("Still developing..");
    }

    void Move::print(std::ostream& out)const
    {
        out << "\tmove ";
        switch(to.data)
        {
        case Statemants::reg:
            out << static_cast<Register&>(to).string();
            break;
        case Statemants::segment:
            out << static_cast<Segment&>(to).string();
            break;
        case Statemants::letter:
            out << "'" << static_cast<Letter&>(to).letter() << "'";
            break;
        case Statemants::integer:
            out << static_cast<Integer&>(to).string();
            break;
        default:
            break;
        }
        out << ", ";
        switch(from.data)
        {
        case Statemants::reg:
            out << static_cast<Register&>(from).string();
            break;
        case Statemants::segment:
            out << static_cast<Segment&>(from).string();
            break;
        case Statemants::letter:
            out << "'" << static_cast<Letter&>(from).letter() << "'";
            break;
        case Statemants::integer:
            out << static_cast<Integer&>(from).string();
            break;
        default:
            break;
        }

        out << ";\n";
    }




    Return::Return() : Instruction(Statemants::ret,1),type(Type::none),address(NULL)
    {
        mcode[0] = 0b11000011;
    }
    Return::Return(const Integer& a, Type t) : Instruction(Statemants::ret,get_size(t)),type(t),address(&a)
    {
        switch(type)
        {
            case Type::within:
                throw core::exception("Return Within segment has not address.");
                break;
            case Type::within_sp:
                mcode[0] = 0b11000010;
                address->to_short(mcode + 1);
                break;
            case Type::inter:
                throw core::exception("Return Within segment has not address.");
                break;
            case Type::inter_sp:
                mcode[0] = 0b1101010;
                address->to_short(mcode + 1);
                break;
            default:
                break;
        }
    }
    void Return::print(std::ostream& out)const
    {
        switch(type)
        {
        case Type::within:
            out << "\treturn;\n";
            break;
        case Type::within_sp:
            out << "\treturn " << address->string() << ";\n";
            break;
        case Type::inter:
            out << "\treturn;\n";
            break;
        case Type::inter_sp:
            out << "\treturn " << address->string() << ";\n";
            break;
        default:
            out << "\treturn;\n";
            break;
        }
    }
    size_t Return::get_size(Type type)
    {
        switch(type)
        {
        case Type::inter:
            return 1;
        case Type::inter_sp:
            return 3;
        case Type::within:
            return 1;
        case Type::within_sp:
            return 3;
        default:
            break;
        }

        return 0;
    }



    Empty::Empty() : Instruction(Statemants::empty,2)
    {
        throw core::exception("Still developing..");
    }
    Empty::Empty(Statemants t,size_t s) : Instruction(t,s)
    {
        throw core::exception("Still developing..");
    }
    void Empty::print(std::ostream& out)const
    {
        out << "\t;\n";
    }




    Interrupt::Interrupt(Integer& s) : Instruction(Statemants::interrupt,2),service(s)
    {
        mcode[0] = 0b11001101;
        //mcode[1] = (char)std::atoi(s.string.c_str());
        if(s.size() == 1)
        {
            mcode[1] = static_cast<char>(std::strtol(s.string().c_str(),NULL,s.base()));
        }
        else if(s.size() == 2)
        {
            *static_cast<short*>(static_cast<void*>(&mcode[1])) = static_cast<short>(std::strtol(s.string().c_str(),NULL,s.base()));
        }
        else
        {

        }
    }

    void Interrupt::print(std::ostream& out)const
    {
        out << "\tinterrupt ";
        if(service.data == Statemants::integer)
        {
            out << service.string();
        }
        else
        {
            out << "?";
        }
        out << ";\n";
    }

    /**
    *\brief Generate code for call instrucction
    **/
    Call::Call(const node& n) : Instruction(Statemants::call,get_size(Type::none)),type(Type::none),address(&n)
    {
        //if the node is integer o memory node then the type is direct within segment and address is thu number in the node
        if(n.data == Statemants::integer or n.data == Statemants::memory)
        {
            //initializind data
            type = Type::within_direct;
            msize = get_size(type);
            mcode = new unsigned char[msize];

            //generating mcode
            mcode[0] = 0b11101000;
            if(address->data == Statemants::integer)
            {
                auto number = static_cast<const Integer*>(address);
                *static_cast<short*>(static_cast<void*>(&mcode[1])) = static_cast<short>(std::strtol(number->string().c_str(),NULL,number->base()));
            }
            else if(address->data == Statemants::memory)
            {
                auto memory = static_cast<const Memory*>(address);
                //*static_cast<short*>(static_cast<void*>(&mcode[1])) = static_cast<short>(std::strtol(memory->string().c_str(),NULL,memory->base()));
            }
            return;
        }
        //if the node is general register use it like direction value
        else if(is_general_register(static_cast<const Word&>(n).token()) and not n.next)
        {
            //initializind data
            type = Type::within_indirect;//becuase use register to set address
            msize = get_size(type);
            mcode = new unsigned char[msize];

            //generating mcode
            mcode[0] = 0b11111111;
            mcode[1] = (mcode[1] << 3) + 0b000;
            mcode[1] = (mcode[1] << 3) + 0b010;
            const Register& reg = static_cast<const Register&>(n);


            return;
        }
        //throw core::exception("Still develipong..");
        //if the node is some combination of BP or BX with SI or DI use it like direction value
        //if the node is some combination of BP or BX with SI or DI and has a integer 8 bits use it like direction value
        //if the node is some combination of BP or BX with SI or DI and has a integer 16 bits use it like direction value
    }
    /**
    *\brief Generate code for call instrucction
    **/
    Call::Call(const Integer& a, Type t) : Instruction(Statemants::call,get_size(t)),type(t),address(&a)
    {
        //write the instruction code on mscode varible for ever case
        switch(type)
        {
        case Type::none:
            break;
        case Type::within_direct:
            mcode[0] = 0b11101000;
            *static_cast<short*>(static_cast<void*>(&mcode[1])) = static_cast<short>(std::strtol(a.string().c_str(),NULL,a.base()));
            break;
        case Type::within_indirect:
            mcode[0] = 0b11111111;
            mode(1,a);
            mcode[1] = (mcode[1] << 3) + 0b010;
            mcode[1] = (mcode[1] << 3) + 0b110;
            *static_cast<short*>(static_cast<void*>(&mcode[2])) = static_cast<short>(std::strtol(a.string().c_str(),NULL,a.base()));
            break;
        case Type::inter_direct:
            break;
        case Type::inter_indirect:

            break;
        default:
            break;
        }
    }
    size_t Call::get_size(Type type)
    {
        switch(type)
        {
        case Type::within_direct:
            return 3;
        case Type::within_indirect:
            return 4;
        case Type::inter_direct:
            return 3;
        case Type::inter_indirect:
            return 4;
        default:
            break;
        }

        return 0;
    }

    void Call::print(std::ostream& out)const
    {
        out << "Call;\n";
    }




    Push::Push() : Instruction(Statemants::push,2)
    {
        throw core::exception("Still developing..");
    }
    Push::Push(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Push::print(std::ostream& out)const
    {
    }

    Pop::Pop() : Instruction(Statemants::pop,2)
    {
        throw core::exception("Still developing..");
    }
    Pop::Pop(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Pop::print(std::ostream& out)const
    {
    }


}
