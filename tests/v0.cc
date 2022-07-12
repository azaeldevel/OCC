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
	//af_number.get_table()->print(std::cout);
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
	//af_numberL.get_table()->print(std::wcout);
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
	//std::cout << "\n\nInstruciotn set\n";
	AFA instruction_set_i86(tt::i86_instset_l);
	//instruction_set_i86.get_table()->print(std::cout);
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
	
	CU_ASSERT(instruction_set_i86.transition("cbw"));
	CU_ASSERT(not instruction_set_i86.transition("CBW"));
	CU_ASSERT(not instruction_set_i86.transition("cBW"));
	
	CU_ASSERT(instruction_set_i86.transition("clc"));
	CU_ASSERT(not instruction_set_i86.transition("cLc"));
	CU_ASSERT(not instruction_set_i86.transition("CLC"));
	
	CU_ASSERT(instruction_set_i86.transition("cld"));
	CU_ASSERT(not instruction_set_i86.transition("cLd"));
	CU_ASSERT(not instruction_set_i86.transition("CLD"));
	
	CU_ASSERT(instruction_set_i86.transition("cli"));
	CU_ASSERT(not instruction_set_i86.transition("cLi"));
	CU_ASSERT(not instruction_set_i86.transition("CLI"));
	
	CU_ASSERT(instruction_set_i86.transition("cmc"));
	CU_ASSERT(not instruction_set_i86.transition("cmC"));
	CU_ASSERT(not instruction_set_i86.transition("CMC"));
	
	CU_ASSERT(instruction_set_i86.transition("cmp"));
	CU_ASSERT(not instruction_set_i86.transition("cmP"));
	CU_ASSERT(not instruction_set_i86.transition("CMP"));
	
	CU_ASSERT(instruction_set_i86.transition("cmps"));
	CU_ASSERT(not instruction_set_i86.transition("cmPs"));
	CU_ASSERT(not instruction_set_i86.transition("CMPS"));
	
	CU_ASSERT(instruction_set_i86.transition("cwd"));
	CU_ASSERT(not instruction_set_i86.transition("CWw"));
	CU_ASSERT(not instruction_set_i86.transition("CWD"));
	
	CU_ASSERT(instruction_set_i86.transition("daa"));
	CU_ASSERT(not instruction_set_i86.transition("DAA"));
	CU_ASSERT(not instruction_set_i86.transition("DaA"));
	
	CU_ASSERT(instruction_set_i86.transition("das"));
	CU_ASSERT(not instruction_set_i86.transition("DAs"));
	CU_ASSERT(not instruction_set_i86.transition("DaS"));
	
	CU_ASSERT(instruction_set_i86.transition("dec"));
	CU_ASSERT(not instruction_set_i86.transition("DeC"));
	CU_ASSERT(not instruction_set_i86.transition("Dec"));
	
	CU_ASSERT(instruction_set_i86.transition("div"));
	CU_ASSERT(not instruction_set_i86.transition("Div"));
	CU_ASSERT(not instruction_set_i86.transition("diV"));
	
	CU_ASSERT(instruction_set_i86.transition("esc"));
	CU_ASSERT(not instruction_set_i86.transition("ESC"));
	CU_ASSERT(not instruction_set_i86.transition("Esc"));
	
	CU_ASSERT(instruction_set_i86.transition("hlt"));
	CU_ASSERT(not instruction_set_i86.transition("Hlt"));
	CU_ASSERT(not instruction_set_i86.transition("HLT"));
	
	CU_ASSERT(instruction_set_i86.transition("idiv"));
	CU_ASSERT(not instruction_set_i86.transition("iDiv"));
	CU_ASSERT(not instruction_set_i86.transition("idiV"));
	
	CU_ASSERT(instruction_set_i86.transition("imul"));
	CU_ASSERT(not instruction_set_i86.transition("iMul"));
	CU_ASSERT(not instruction_set_i86.transition("IMUL"));
	
	CU_ASSERT(instruction_set_i86.transition("in"));
	CU_ASSERT(not instruction_set_i86.transition("iN"));
	CU_ASSERT(not instruction_set_i86.transition("IN"));
	
	CU_ASSERT(instruction_set_i86.transition("inc"));
	CU_ASSERT(not instruction_set_i86.transition("iNc"));
	CU_ASSERT(not instruction_set_i86.transition("INc"));
	
	CU_ASSERT(instruction_set_i86.transition("int"));
	CU_ASSERT(not instruction_set_i86.transition("iNt"));
	CU_ASSERT(not instruction_set_i86.transition("INt"));
	
	CU_ASSERT(instruction_set_i86.transition("intr"));
	CU_ASSERT(not instruction_set_i86.transition("iNtr"));
	CU_ASSERT(not instruction_set_i86.transition("INtr"));
	
	CU_ASSERT(instruction_set_i86.transition("into"));
	CU_ASSERT(not instruction_set_i86.transition("iNto"));
	CU_ASSERT(not instruction_set_i86.transition("INto"));
	
	CU_ASSERT(instruction_set_i86.transition("iret"));
	CU_ASSERT(not instruction_set_i86.transition("IRET"));
	CU_ASSERT(not instruction_set_i86.transition("Iret"));
	

	AFA regs_i86(tt::i86_regs_l);
	CU_ASSERT(regs_i86.transition("ax"));
	CU_ASSERT(regs_i86.transition("ah"));
	CU_ASSERT(regs_i86.transition("al"));
	CU_ASSERT(regs_i86.transition("bx"));
	CU_ASSERT(regs_i86.transition("bh"));
	CU_ASSERT(regs_i86.transition("bl"));
	CU_ASSERT(regs_i86.transition("cx"));
	CU_ASSERT(regs_i86.transition("ch"));
	CU_ASSERT(regs_i86.transition("cl"));
	CU_ASSERT(regs_i86.transition("dx"));
	CU_ASSERT(regs_i86.transition("dh"));
	CU_ASSERT(regs_i86.transition("dl"));

	AFA AF_id(tt::Identifier);
	CU_ASSERT(AF_id.transition("ax"));
	CU_ASSERT(AF_id.transition("ah"));
	CU_ASSERT(AF_id.transition("al"));
	CU_ASSERT(AF_id.transition("bx"));
	CU_ASSERT(AF_id.transition("bh"));
	CU_ASSERT(AF_id.transition("bl"));
	CU_ASSERT(AF_id.transition("cx"));
	CU_ASSERT(AF_id.transition("ch"));
	CU_ASSERT(AF_id.transition("cl"));
	CU_ASSERT(AF_id.transition("dx"));
	CU_ASSERT(AF_id.transition("dh"));
	CU_ASSERT(AF_id.transition("dl"));
	
	CU_ASSERT(AF_id.transition("JUAN"));
	CU_ASSERT(AF_id.transition("Carro"));
	CU_ASSERT(AF_id.transition("_Test12"));
	CU_ASSERT(AF_id.transition("_Avion_"));
	CU_ASSERT(AF_id.transition("Aeropueto"));
	CU_ASSERT(AF_id.transition("REF_00256"));
	CU_ASSERT(AF_id.transition("REF_08956"));
	CU_ASSERT(AF_id.transition("Romero1"));
}