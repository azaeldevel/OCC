
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
        nTo.code(mcode[0]);
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
        nTo.code(mcode[0]);
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

    Call::Call() : Instruction(Statemants::call,2)
    {
        throw core::exception("Still developing..");
    }
    Call::Call(Statemants t,size_t s) : Instruction(t,s)
    {
        throw core::exception("Still developing..");
    }
    Call::Call(Statemants t,size_t s,Word* w) : Instruction(t,s),id(w)
    {
        throw core::exception("Still developing..");
    }
    Call::Call(size_t s,Word* w) : Instruction(Statemants::call,s),id(w)
    {
        throw core::exception("Still developing..");
    }
    void Call::print(std::ostream& out)const
    {
        if(id) out << "\tcall " << id->string() << ";\n";
        else out << "\tcall;\n";
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
