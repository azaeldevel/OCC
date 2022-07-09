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
	
	AFD af_number(0,table_number_10);
	//std::cout << "Table size : " << af_number.get_table().size() << "\n";
	/*
	for(const Transition<Char>& t : af_number.get_table())
	{
		t.print(std::cout);
	}
	*/
	const Transition<Char>* trans1 = af_number.get_table()->search(1,'8');
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
	CU_ASSERT(not af_number.transition("0x123456"));
	CU_ASSERT(not af_number.transition("!123456"));	
	CU_ASSERT(not af_number.transition("123456@"));	
	CU_ASSERT(not af_number.transition("Juan"));
	
	AFD af_hex(0,table_number_16);
	const Transition<Char>* trans2 = af_hex.get_table()->search(1,'x');
	CU_ASSERT(trans2 != NULL);
	/*if(trans2)
	{
		std::cout << "Se encontro : ";
		trans2->print(std::cout);
	}*/
	CU_ASSERT(af_hex.transition("0x123F5A"));
	CU_ASSERT(af_hex.transition("0x01"));
	//reject
	CU_ASSERT(not af_hex.transition("123456"));
	CU_ASSERT(not af_hex.transition("!123456"));




	AFD af_hex2(0,table_number_beautifull_16);
	const Transition<Char>* trans3 = af_hex2.get_table()->search(1,'x');
	CU_ASSERT(trans3 != NULL);
	/*if(trans2)
	{
		std::cout << "Se encontro : ";
		trans2->print(std::cout);
	}*/
	CU_ASSERT(af_hex2.transition("0X123F5A"));
	CU_ASSERT(af_hex2.transition("0x01"));
	//reject
	CU_ASSERT(not af_hex2.transition("123456"));
	CU_ASSERT(not af_hex2.transition("!123456"));
}