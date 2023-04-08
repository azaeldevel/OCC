#include "scanner.hh"


Scanner::Scanner(std::ifstream *in) : yyFlexLexer(in)
{
    //loc = new yy::location_type();
}
Scanner::~Scanner()
{
    //delete loc;
}

