#include <Buffer.hh>
#include <AF.hh>
#include <tt.hh>

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
	
	AFA af_number(0,tt::table_number_10);
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


	AFA af_numberL(0,tt::table_number_10L);
	const Transition<wchar_t>* trans1L = af_numberL.get_table()->search(1,'8');
	CU_ASSERT(trans1L != NULL);
	/*if(trans1L)
	{
		std::cout << "Se encontro : ";
		trans1L->print(std::wcout);
	}*/
	
	//pertenice al lenguaje
	CU_ASSERT(af_numberL.transition(L"123456"));
	CU_ASSERT(af_numberL.transition(L"0123456"));
	//no pertenice al lenguaje
	CU_ASSERT(not af_numberL.transition(L"A123456"));
	CU_ASSERT(not af_numberL.transition(L"0x123456"));
	CU_ASSERT(not af_numberL.transition(L"!123456"));	
	CU_ASSERT(not af_numberL.transition(L"123456@"));	
	CU_ASSERT(not af_numberL.transition(L"Juan"));


	
	
	AFA af_hex(0,tt::table_number_16);
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
	
	AFA af_hexL(0,tt::table_number_16L);
	const Transition<wchar_t>* trans2L = af_hexL.get_table()->search(1,'x');
	CU_ASSERT(trans2L != NULL);
	/*if(trans2L)
	{
		std::cout << "Se encontro : ";
		trans2L->print(std::wcout);
	}*/

	
	AFA af_hex2(0,tt::table_number_beautifull_16);
	const Transition<char>* trans3 = af_hex2.get_table()->search(1,'x');
	CU_ASSERT(trans3 != NULL);
	/*if(trans3)
	{
		std::cout << "Se encontro : ";
		trans3->print(std::cout);
	}*/
	CU_ASSERT(af_hex2.transition("0X123F5A"));
	CU_ASSERT(af_hex2.transition("0x01"));
	//reject
	CU_ASSERT(not af_hex2.transition("123456"));
	CU_ASSERT(not af_hex2.transition("!123456"));

	AFA af_hex2L(0,tt::table_number_beautifull_16L);
	const Transition<wchar_t>* trans3L = af_hex2L.get_table()->search(1,'x');
	CU_ASSERT(trans3L != NULL);
	/*if(trans3L)
	{
		std::wcout << "Se encontro : ";
		trans3L->print(std::wcout);
	}*/
	CU_ASSERT(af_hex2L.transition(L"0X123F5A"));
	CU_ASSERT(af_hex2L.transition(L"0x01"));
	//reject
	CU_ASSERT(not af_hex2L.transition(L"123456"));
	CU_ASSERT(not af_hex2L.transition(L"!123456"));



	
	//instruction set
	std::cout << "\n\nInstruciotn set\n";
	AFA instruction_set_i86(tt::i86l);
	instruction_set_i86.get_table()->print(std::cout);
	CU_ASSERT(instruction_set_i86.transition("aaa"));
	CU_ASSERT(not instruction_set_i86.transition("aAa"));
	CU_ASSERT(not instruction_set_i86.transition("AAA"));
	CU_ASSERT(not instruction_set_i86.transition("ana"));
	
	CU_ASSERT(instruction_set_i86.transition("aad"));
	CU_ASSERT(not instruction_set_i86.transition("AAD"));
	CU_ASSERT(not instruction_set_i86.transition("AAd"));
	
	CU_ASSERT(instruction_set_i86.transition("aam"));
	CU_ASSERT(not instruction_set_i86.transition("AAM"));
	CU_ASSERT(not instruction_set_i86.transition("AaM"));
	
	CU_ASSERT(instruction_set_i86.transition("adc"));
	CU_ASSERT(not instruction_set_i86.transition("ADC"));
	CU_ASSERT(not instruction_set_i86.transition("aDc"));
	
	CU_ASSERT(instruction_set_i86.transition("add"));
	CU_ASSERT(not instruction_set_i86.transition("ADD"));
	CU_ASSERT(not instruction_set_i86.transition("aDd"));
	
	CU_ASSERT(instruction_set_i86.transition("and"));
	CU_ASSERT(not instruction_set_i86.transition("AND"));
	CU_ASSERT(not instruction_set_i86.transition("aNd"));
	
	CU_ASSERT(instruction_set_i86.transition("call"));
	CU_ASSERT(not instruction_set_i86.transition("CALL"));
	CU_ASSERT(not instruction_set_i86.transition("Call"));
	CU_ASSERT(not instruction_set_i86.transition("CaLL"));
	
	CU_ASSERT(instruction_set_i86.transition("and"));
	CU_ASSERT(not instruction_set_i86.transition("AND"));
	CU_ASSERT(not instruction_set_i86.transition("aNd"));

	
	
}