
#ifndef OCTETOT_CC_V0_AII
#define OCTETOT_CC_V0_AII


#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include <oas-intel-parser-A+.hh>
//#include <oas-intel-A+.tab.h>
//#include <location.hh>
namespace oct::cc::v0::A
{

class Scanner : public yyFlexLexer
{
public:
    Scanner(std::ifstream *in);
    ~Scanner();

    using FlexLexer::yylex;
    int yylex(parser::semantic_type * const lval, parser::location_type *loc);

private:
    parser::semantic_type *yylval = nullptr;
};

}

#endif
