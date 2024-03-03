
#include "intel.hh"

#include <core/3/numbers.hh>

namespace oct::cc::v1::A::intel
{





    Move::Move(Register& nTo,Register& nFront) : from(nFront),to(nTo)
    {

    }
    Move::Move(Register& nTo,Memory& nFront) : from(nFront),to(nTo)
    {
    }
    Move::Move(Memory& nTo,Register& nFront) : from(nFront),to(nTo)
    {
    }


    Move::Move(Register& nTo,Integer& nFront) : Instruction(Statemants::move,3),from(nFront),to(nTo)
    {
        mcode[0] = 0x1011;
        mcode[0] = mcode[0] << 0x0; //word size
        mcode[0] = mcode[0] << nTo.code();
        *static_cast<short*>(static_cast<void*>(&mcode[1])) = core::to_number<short>(nFront.string.c_str());
    }
    Move::Move(Register& nTo,Letter& nFront) : Instruction(Statemants::move,2),from(nFront),to(nTo)
    {
        mcode[0] = 0x1011;
        mcode[0] = mcode[0] << 0x1; //word size
        mcode[0] = mcode[0] << nTo.code();
        mcode[1] = nFront.letter;
    }
    Move::Move(Memory& nTo,Integer& nFront) : from(nFront),to(nTo)
    {
    }
    Move::Move(Memory& nTo,Letter& nFront) : from(nFront),to(nTo)
    {
    }


    Move::Move(Segment& nTo,Register& nFront) : from(nFront),to(nTo)
    {
    }
    Move::Move(Segment& nTo,Memory& nFront) : from(nFront),to(nTo)
    {
    }
    Move::Move(Register& nTo,Segment& nFront) : from(nFront),to(nTo)
    {
    }
    Move::Move(Memory& nTo,Segment& nFront) : from(nFront),to(nTo)
    {
    }

    void Move::print(std::ostream& out)const
    {
        out << "\tmove ";
        switch(to.data)
        {
        case Statemants::reg:
            out << static_cast<Register&>(to).string;
            break;
        case Statemants::segment:
            out << static_cast<Segment&>(to).string;
            break;
        case Statemants::letter:
            out << "'" << static_cast<Letter&>(to).letter << "'";
            break;
        case Statemants::integer:
            out << static_cast<Integer&>(to).string;
            break;
        }
        out << ", ";
        switch(from.data)
        {
        case Statemants::reg:
            out << static_cast<Register&>(from).string;
            break;
        case Statemants::segment:
            out << static_cast<Segment&>(from).string;
            break;
        case Statemants::letter:
            out << "'" << static_cast<Letter&>(from).letter << "'";
            break;
        case Statemants::integer:
            out << static_cast<Integer&>(from).string;
            break;
        }

        out << ";\n";
    }




    Return::Return() : Instruction(Statemants::ret,2)
    {
    }
    Return::Return(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Return::print(std::ostream& out)const
    {
        out << "\treturn;\n";
    }



    Empty::Empty() : Instruction(Statemants::empty,2)
    {
    }
    Empty::Empty(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Empty::print(std::ostream& out)const
    {
        out << "\t;\n";
    }




    Interrupt::Interrupt(Integer& s) : service(s)
    {
    }

    void Interrupt::print(std::ostream& out)const
    {
        out << "\tinterrupt ";
        if(service.data == Statemants::integer)
        {
            out << service.string;
        }
        else
        {
            out << "?";
        }
        out << ";\n";
    }


    Call::Call() : Instruction(Statemants::call,2)
    {
    }
    Call::Call(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    Call::Call(Statemants t,size_t s,Word* w) : Instruction(t,s),id(w)
    {
    }
    Call::Call(size_t s,Word* w) : Instruction(Statemants::call,s),id(w)
    {
    }
    void Call::print(std::ostream& out)const
    {
        if(id) out << "\tcall " << id->string << ";\n";
        else out << "\tcall;\n";
    }


    Push::Push() : Instruction(Statemants::push,2)
    {
    }
    Push::Push(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Push::print(std::ostream& out)const
    {
    }

    Pop::Pop() : Instruction(Statemants::pop,2)
    {
    }
    Pop::Pop(Statemants t,size_t s) : Instruction(t,s)
    {
    }
    void Pop::print(std::ostream& out)const
    {
    }


}
