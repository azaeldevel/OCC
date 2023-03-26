
#include <A+.hh>
#include <core/3/Buffer.hh>
#include <iostream>
#include <chrono>
#include <fstream>
#include <oas-intel-parser-A+.hh>
#include <oas-intel-A+.tab.h>
#include "v0.hh"

using namespace oct::cc;
using namespace std::chrono;
namespace A_here = oct::cc::v0::A;

int v0_init(void)
{

	
	return 0;
}
int v0_clean(void)
{
	
	
	return 0;
}

void v0_AFD_A()
{
}
void v0_AFD_B()
{	
}
void v0_AFD_C()
{
	
}
void v0_performance()
{
}
void v0_developing()
{	
}



void v0_AA()
{
	CU_ASSERT((int)A_here::Tokens::AUTO == (int)yytoken_kind_t::AUTO);
	//std::cout << (int)A_here::Tokens::AUTO << " " << (int)yytoken_kind_t::AUTO << "\n";

	
	CU_ASSERT((int)A_here::Tokens::GOTO == (int)yytoken_kind_t::GOTO);
	
	CU_ASSERT((int)A_here::Tokens::GOTO == (int)yytoken_kind_t::GOTO);
	
	CU_ASSERT((int)A_here::Tokens::WHILE == (int)yytoken_kind_t::WHILE);
	
	CU_ASSERT((int)A_here::Tokens::LITERAL_INTEGER_DEC_INT == (int)yytoken_kind_t::LITERAL_INTEGER_DEC_INT);
	CU_ASSERT((int)A_here::Tokens::LITERAL_INTEGER_DEC_SHORT == (int)yytoken_kind_t::LITERAL_INTEGER_DEC_SHORT);
	CU_ASSERT((int)A_here::Tokens::LITERAL_INTEGER_DEC_LONG == (int)yytoken_kind_t::LITERAL_INTEGER_DEC_LONG);
}





