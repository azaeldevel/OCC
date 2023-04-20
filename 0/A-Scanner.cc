#include "A-Scanner.hh"


namespace oct::cc::v0::AI
{
Scanner::Scanner(std::ifstream *in,core_here::Block& b) : yyFlexLexer(in),block(b)
{
    //loc = new yy::location_type();
}
Scanner::~Scanner()
{
    //delete loc;
}

}
