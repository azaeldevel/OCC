#include "A-Scanner.hh"


namespace oct::cc::v0::AI
{
Scanner::Scanner(std::ifstream *in) : yyFlexLexer(in)
{
    //loc = new yy::location_type();
}
Scanner::~Scanner()
{
    //delete loc;
}

}
