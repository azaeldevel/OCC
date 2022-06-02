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


	
	Tray tray;
	tray.word_size = 8;
	tray.arch = Tray::Arch::x86;
	A::Lexer lexer("../../tests/prg1.cc.asm",tray);
	Lexer::Token* token = lexer.next();
	unsigned int count_toks = 0;
	while(token)
	{
		//std::cout << "Token : " << token->get_type_string() << " - '" << token->get_text() << "'\n";
		count_toks++;
		token = lexer.next();
	}
	//std::cout << "count_toks : " << count_toks << "\n";
	CU_ASSERT(count_toks == 21);
	
}