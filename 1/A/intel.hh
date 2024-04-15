#ifndef OCC_INTEL_HH_INCLUDED
#define OCC_INTEL_HH_INCLUDED


#include "I/A.hh"


namespace oct::cc::v1::A::intel
{


    /**
    *\brief Node Base para instruciones mov
    **/
    struct Move : public Instruction
    {

        /**
        *\biref COntrulle la instruccion Move
        **/
        Move(Register& nTo,Register& nFront);
        Move(Register& nTo,Memory& nFront);
        Move(Memory& nTo,Register& nFront);

        Move(Register& nTo,Integer& nFront);
        Move(Register& nTo,Letter& nFront);
        Move(Memory& nTo,Integer& nFront);
        Move(Memory& nTo,Letter& nFront);


        Move(Segment& nTo,Register& nFront);
        Move(Segment& nTo,Memory& nFront);
        Move(Register& nTo,Segment& nFront);
        Move(Memory& nTo,Segment& nFront);


        virtual void print(std::ostream&)const;

        node &from, &to;
    };


    /**
    *\brief Node Base para instruciones mov
    **/
    class Return : public Instruction
    {
    public:
        enum Type
        {
            none,
            within,
            within_sp,
            inter,
            inter_sp
        };

    public:
        Return();
        Return(const Integer&, Type type);


        virtual void print(std::ostream&)const;

    private:
        static size_t get_size(Type type);

    };


    /**
    *\brief Node Base para instruciones mov
    **/
    struct Empty : public Instruction
    {
        Empty();
        Empty(Statemants,size_t instsize);
        virtual void print(std::ostream&)const;

    };


    /**
    *\brief Node Base para instruciones mov
    **/
    struct Interrupt : public Instruction
    {
        Interrupt(Integer&);

        virtual void print(std::ostream&)const;
        //
        Integer& service;
    };


    /**
    *\brief Instruccion call
    **/
    struct Call : public Instruction
    {
        Call();
        Call(Statemants,size_t instsize);
        Call(Statemants,size_t instsize,Word*);
        Call(size_t instsize,Word*);

        Call(Memory&);
        Call(Identifier&);

        virtual void print(std::ostream&)const;

        Word* id;
    };


    /**
    *\brief Instruccion call
    **/
    struct Push : public Instruction
    {
        Push();
        Push(Statemants,size_t instsize);
        virtual void print(std::ostream&)const;

    };


    /**
    *\brief Instruccion call
    **/
    struct Pop : public Instruction
    {
        Pop();
        Pop(Statemants,size_t instsize);
        virtual void print(std::ostream&)const;

    };



}

#endif // OCC_INTEL_HH_INCLUDED
