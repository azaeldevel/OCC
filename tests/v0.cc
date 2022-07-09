#include <Buffer.hh>
#include <AF.hh>

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

	CU_ASSERT(buffer1.size() == 49);
	CU_ASSERT(buffer1[2] == 'a');
	CU_ASSERT(buffer1[5] == ':');
	CU_ASSERT(buffer1[15] == '5');
	//std::cout << "Test : " << buffer1[15] << "\n";
	
	Number af_number;
	//std::cout << "Table size : " << af_number.get_table().size() << "\n";
	/*
	for(const Transition<Char>& t : af_number.get_table())
	{
		t.print(std::cout);
	}
	*/
	const Transition<Char>* trans1 = af_number.get_table().search(1,'8');
	CU_ASSERT(trans1 != NULL);
	/*if(trans1)
	{
		std::cout << "Se encontro : ";
		trans1->print(std::cout);
	}*/	

	//pertenice al lenguaje
	CU_ASSERT(af_number.transition("123456"));
	CU_ASSERT(af_number.transition("0123456"));
	//no pertenice al lenguaje
	CU_ASSERT(not af_number.transition("A123456"));
	CU_ASSERT(not af_number.transition("!123456"));	
	CU_ASSERT(not af_number.transition("123456@"));	
	CU_ASSERT(not af_number.transition("Juan"));
	
	
}