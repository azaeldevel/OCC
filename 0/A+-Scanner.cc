#include "A+-Scanner.hh"


namespace oct::cc::v0::AII
{
Scanner::Scanner(std::ifstream *in) : yyFlexLexer(in)
{
}
Scanner::~Scanner()
{
}

}
