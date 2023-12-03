
#ifndef OCTETOT_CC_V0_AI_DRIVER_HH
#define OCTETOT_CC_V0_AI_DRIVER_HH
#include <string>
#include <fstream>
#include <list>
//#include <A/oas-intel-parser.hh>
#include "A.hh"
#include  "../../Buffer.hh"

//#include <A/location.hh>


namespace oct::cc::v1::A::I
{

    class Driver
    {
    public:
        Driver (Tray&);
        virtual ~Driver ();

        virtual bool parse(const std::filesystem::path& sources);
        virtual void print(std::ostream&)const;
        virtual void print(std::ostream&,const Unit*)const;
        virtual bool semantic();
        virtual void generate(std::ostream&)const;
        virtual void generate(std::ostream&,const Unit*)const;

    private:

    private:
        //File file;
        Tray* tray;
        Buffer buffer;
    };

}

#endif
