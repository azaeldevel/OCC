#ifndef OCC_INTEL_HH_INCLUDED
#define OCC_INTEL_HH_INCLUDED


#include "../I/A.hh"


namespace oct::cc::v1::intel
{
    class Generator
    {
    public:

    private:
        void move(A::Register&,A::Register&,char*& code);
    };



}

#endif // OCC_INTEL_HH_INCLUDED
