#include "A+-Scanner.hh"


namespace oct::cc::v0::AII
{
Scanner::Scanner(std::ifstream *in) : AIIFlexLexer(in)
{
    //loc = new yy::location_type();
}
Scanner::~Scanner()
{
    //delete loc;
}

}
