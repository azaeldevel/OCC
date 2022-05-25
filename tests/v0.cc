#include <Buffer.hh>
#include <Lexer.hh>
#include <CUnit/Basic.h>
#include <iostream>

using namespace oct::cc;


int v0_init(void)
{
	return 0;
}
int v0_clean(void)
{
	return 0;
}


void v0_developing()
{
	Buffer buffer1("../../tests/prg1.cc.asm");

	CU_ASSERT(buffer1.size() == 46);
	CU_ASSERT(buffer1[2] == 'a');
	CU_ASSERT(buffer1[5] == ':');
	CU_ASSERT(buffer1[15] == '#');
	
	//std::cout << "-->>" << buffer1[15] << "<<--\n";
	//std::cout << "file:\n" << (const char*)buffer1 << "\n";
	//std::cout << "size:\n" << buffer1.size() << "\n";



	Lexer lexer("../../tests/prg1.cc.asm");
	Lexer::Token* token = lexer.next();
	while(token)
	{
		std::cout << "Token : '" << token->get_text() << "'\n";
		
		token = lexer.next();
	}
}