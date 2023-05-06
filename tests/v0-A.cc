
#include "v0.hh"

#include "A-Driver.hh"
#include <A/oas-intel-parser.hh>

namespace AI_here = oct::cc::v0::AI;



void v0_AI_developing()
{

}

void v0_AI_components()
{

}

void v0_AI_constans()
{
	CU_ASSERT((int)AI_here::Tokens::AUTO == (int)yytoken_kind_t::AUTO);
	//std::cout << "AUTO : " << (int)A_here::Tokens::AUTO << " " << (int)yytoken_kind_t::AUTO << "\n";

	CU_ASSERT((int)AI_here::Tokens::BREAK == (int)yytoken_kind_t::BREAK);
	//std::cout << "BREAK : " << (int)A_here::Tokens::BREAK << " " << (int)yytoken_kind_t::BREAK << "\n";

	CU_ASSERT((int)AI_here::Tokens::CASE == (int)yytoken_kind_t::CASE);
	//std::cout << "CASE : " << (int)A_here::Tokens::CASE << " " << (int)yytoken_kind_t::CASE << "\n";

	CU_ASSERT((int)AI_here::Tokens::CHAR == (int)yytoken_kind_t::CHAR);
	//std::cout << "CHAR : " << (int)A_here::Tokens::CHAR << " " << (int)yytoken_kind_t::CHAR << "\n";

	CU_ASSERT((int)AI_here::Tokens::CONST == (int)yytoken_kind_t::CONST);
	//std::cout << "CONST : " << (int)A_here::Tokens::CONST << " " << (int)yytoken_kind_t::CONST << "\n";

	CU_ASSERT((int)AI_here::Tokens::DO == (int)yytoken_kind_t::DO);
	//std::cout << "DO : " << (int)A_here::Tokens::DO << " " << (int)yytoken_kind_t::DO << "\n";

	CU_ASSERT((int)AI_here::Tokens::GOTO == (int)yytoken_kind_t::GOTO);
	//std::cout << "GOTO : " << (int)A_here::Tokens::GOTO << " " << (int)yytoken_kind_t::GOTO << "\n";

	CU_ASSERT((int)AI_here::Tokens::WHILE == (int)yytoken_kind_t::WHILE);
	//std::cout << "WHILE : "  << (int)A_here::Tokens::WHILE << " " << (int)yytoken_kind_t::WHILE << "\n";

	CU_ASSERT((int)AI_here::Tokens::LITERAL_INTEGER_DEC_INT == (int)yytoken_kind_t::LITERAL_INTEGER_DEC_INT);
	CU_ASSERT((int)AI_here::Tokens::LITERAL_INTEGER_DEC_SHORT == (int)yytoken_kind_t::LITERAL_INTEGER_DEC_SHORT);
	CU_ASSERT((int)AI_here::Tokens::LITERAL_INTEGER_DEC_LONG == (int)yytoken_kind_t::LITERAL_INTEGER_DEC_LONG);

	CU_ASSERT((int)AI_here::Tokens::AAA == (int)yytoken_kind_t::AAA);
	//std::cout << "WHILE : "  << (int)A_here::Tokens::WHILE << " " << (int)yytoken_kind_t::WHILE << "\n";

	CU_ASSERT((int)AI_here::Tokens::INC == (int)yytoken_kind_t::INC);
	//std::cout << "WHILE : "  << (int)A_here::Tokens::WHILE << " " << (int)yytoken_kind_t::WHILE << "\n";

	CU_ASSERT((int)AI_here::Tokens::MOV == (int)yytoken_kind_t::MOV);
	//std::cout << "WHILE : "  << (int)A_here::Tokens::WHILE << " " << (int)yytoken_kind_t::WHILE << "\n";

	CU_ASSERT((int)AI_here::Tokens::AL == (int)yytoken_kind_t::AL);
	//std::cout << "AL : "  << (int)A_here::Tokens::AL << " " << (int)yytoken_kind_t::AL << "\n";

	CU_ASSERT((int)AI_here::Tokens::DL == (int)yytoken_kind_t::DL);
	//std::cout << "DL : "  << (int)A_here::Tokens::DL << " " << (int)yytoken_kind_t::DL << "\n";



}





