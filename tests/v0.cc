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
	Buffer<char> buffer1("../../tests/prg1.cc.asm");

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
	/*const Transition<char>* trans1 = af_number.get_table()->search(1,'8');
	CU_ASSERT(trans1 != NULL);
	if(trans1)
	{
		std::cout << "Se encontro : ";
		trans1->print(std::cout);
	}*/	
	
	//pertenice al lenguaje
	//std::cout << "Length : " << af_number.transition("123456") << "\n";
	CU_ASSERT(af_number.transition("123456") == 5);
	CU_ASSERT(af_number.transition("0123456") == 6);
	//no pertenice al lenguaje
	CU_ASSERT(af_number.transition("A123456") == 0);
	CU_ASSERT(af_number.transition("0x123456") == 0);
	CU_ASSERT(af_number.transition("!123456") == 0);	
	CU_ASSERT(af_number.transition("123456@") == 5);	
	CU_ASSERT(af_number.transition("Juan") == 0);


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
	CU_ASSERT(af_numberL.transition(L"123456") == 5);
	CU_ASSERT(af_numberL.transition(L"0123456") == 6);
	CU_ASSERT(af_numberL.transition(L"A123456") == 0);
	CU_ASSERT(af_numberL.transition(L"0x123456") == 0);
	CU_ASSERT(af_numberL.transition(L"!123456") == 0);	
	CU_ASSERT(af_numberL.transition(L"123456@") == 5);	
	CU_ASSERT( af_numberL.transition(L"Juan") == 0);


	
	
	AFA af_hex(0,tt::table_number_16);
	const Transition<char>* trans2 = af_hex.get_table()->search(1,'x');
	CU_ASSERT(trans2 != NULL);
	/*if(trans2)
	{
		std::cout << "Se encontro : ";
		trans2->print(std::cout);
	}*/
	CU_ASSERT(af_hex.transition("0x123F5A") == 7);
	CU_ASSERT(af_hex.transition("0x01") == 3);
	//reject
	CU_ASSERT(af_hex.transition("123456") == 0);
	CU_ASSERT(af_hex.transition("!123456") == 0);
	
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
	CU_ASSERT(af_hex2.transition("0X123F5A")  == 7);
	CU_ASSERT(af_hex2.transition("0x01") == 3);
	//reject
	CU_ASSERT(af_hex2.transition("123456") == 0);
	CU_ASSERT(af_hex2.transition("!123456") == 0);

	AFA af_hex2L(0,tt::table_number_beautifull_16L);
	const Transition<wchar_t>* trans3L = af_hex2L.get_table()->search(1,'x');
	CU_ASSERT(trans3L != NULL);
	/*if(trans3L)
	{
		std::wcout << "Se encontro : ";
		trans3L->print(std::wcout);
	}*/
	CU_ASSERT(af_hex2L.transition(L"0X123F5A") == 7);
	CU_ASSERT(af_hex2L.transition(L"0x01") == 3);
	//reject
	CU_ASSERT(af_hex2L.transition(L"123456") == 0);
	CU_ASSERT(af_hex2L.transition(L"!123456") == 0);



	
	//instruction set
	//std::cout << "\n\nInstruciotn set\n";
	AFA instruction_set_i86(tt::i86_instset_l);
	//instruction_set_i86.get_table()->print(std::cout);
	//std::cout << "Length : " << instruction_set_i86.transition("aaa") << "\n";
	CU_ASSERT(instruction_set_i86.transition("aaa") == 2);
	CU_ASSERT(instruction_set_i86.transition("aAa") == 0);
	CU_ASSERT(instruction_set_i86.transition("AAA") == 0);
	CU_ASSERT(instruction_set_i86.transition("ana") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("aad") == 2);
	CU_ASSERT(instruction_set_i86.transition("AAD") == 0);
	CU_ASSERT(instruction_set_i86.transition("AAd") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("aam") == 2);
	CU_ASSERT(instruction_set_i86.transition("AAM") == 0);
	CU_ASSERT(instruction_set_i86.transition("AaM") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("adc") == 2);
	CU_ASSERT(instruction_set_i86.transition("ADC") == 0);
	CU_ASSERT(instruction_set_i86.transition("aDc") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("add") == 2);
	CU_ASSERT(instruction_set_i86.transition("ADD") == 0);
	CU_ASSERT(instruction_set_i86.transition("aDd") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("and") == 2);
	CU_ASSERT(instruction_set_i86.transition("AND") == 0);
	CU_ASSERT(instruction_set_i86.transition("aNd") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("call") == 3);
	CU_ASSERT(instruction_set_i86.transition("CALL") == 0);
	CU_ASSERT(instruction_set_i86.transition("Call") == 0);
	CU_ASSERT(instruction_set_i86.transition("CaLL") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("cbw") == 2);
	CU_ASSERT(instruction_set_i86.transition("CBW") == 0);
	CU_ASSERT(instruction_set_i86.transition("cBW") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("clc") == 2);
	CU_ASSERT(instruction_set_i86.transition("cLc") == 0);
	CU_ASSERT(instruction_set_i86.transition("CLC") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("cld") == 2);
	CU_ASSERT(instruction_set_i86.transition("cLd") == 0);
	CU_ASSERT(instruction_set_i86.transition("CLD") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("cli") == 2);
	CU_ASSERT(instruction_set_i86.transition("cLi") == 0);
	CU_ASSERT(instruction_set_i86.transition("CLI") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("cmc") == 2);
	CU_ASSERT(instruction_set_i86.transition("cmC") == 0);
	CU_ASSERT(instruction_set_i86.transition("CMC") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("cmp") == 2);
	CU_ASSERT(instruction_set_i86.transition("cmP") == 0);
	CU_ASSERT(instruction_set_i86.transition("CMP") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("cmps") == 3);
	CU_ASSERT(instruction_set_i86.transition("cmPs") == 0);
	CU_ASSERT(instruction_set_i86.transition("CMPS") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("cwd") == 2);
	CU_ASSERT(instruction_set_i86.transition("CWw") == 0);
	CU_ASSERT(instruction_set_i86.transition("CWD") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("daa") == 2);
	CU_ASSERT(instruction_set_i86.transition("DAA") == 0);
	CU_ASSERT(instruction_set_i86.transition("DaA") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("das") == 2);
	CU_ASSERT(instruction_set_i86.transition("DAs") == 0);
	CU_ASSERT(instruction_set_i86.transition("DaS") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("dec") == 2);
	CU_ASSERT(instruction_set_i86.transition("DeC") == 0);
	CU_ASSERT(instruction_set_i86.transition("Dec") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("div"));
	CU_ASSERT(instruction_set_i86.transition("Div") == 0);
	CU_ASSERT(instruction_set_i86.transition("diV") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("esc"));
	CU_ASSERT(instruction_set_i86.transition("ESC") == 0);
	CU_ASSERT(instruction_set_i86.transition("Esc") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("hlt") == 2);
	CU_ASSERT(instruction_set_i86.transition("Hlt") == 0);
	CU_ASSERT(instruction_set_i86.transition("HLT") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("idiv") == 3);
	CU_ASSERT(instruction_set_i86.transition("iDiv") == 0);
	CU_ASSERT(instruction_set_i86.transition("idiV") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("imul") == 3);
	CU_ASSERT(instruction_set_i86.transition("iMul") == 0);
	CU_ASSERT(instruction_set_i86.transition("IMUL") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("in") == 1);
	CU_ASSERT(instruction_set_i86.transition("iN") == 0);
	CU_ASSERT(instruction_set_i86.transition("IN") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("inc") == 2);
	CU_ASSERT(instruction_set_i86.transition("iNc") == 0);
	CU_ASSERT(instruction_set_i86.transition("INc") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("int") == 2);
	CU_ASSERT(instruction_set_i86.transition("iNt") == 0);
	CU_ASSERT(instruction_set_i86.transition("INt") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("intr") == 3);
	CU_ASSERT(instruction_set_i86.transition("iNtr") == 0);
	CU_ASSERT(instruction_set_i86.transition("INtr") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("into") == 3);
	CU_ASSERT(instruction_set_i86.transition("iNto") == 0);
	CU_ASSERT(instruction_set_i86.transition("INto") == 0);
	
	CU_ASSERT(instruction_set_i86.transition("iret") == 3);
	CU_ASSERT(instruction_set_i86.transition("IRET") == 0);
	CU_ASSERT(instruction_set_i86.transition("Iret") == 0);
	

	AFA regs_i86(tt::i86_regs_l);
	CU_ASSERT(regs_i86.transition("ax") == 1);
	CU_ASSERT(regs_i86.transition("ah") == 1);
	CU_ASSERT(regs_i86.transition("al") == 1);
	CU_ASSERT(regs_i86.transition("bx") == 1);
	CU_ASSERT(regs_i86.transition("bh") == 1);
	CU_ASSERT(regs_i86.transition("bl") == 1);
	CU_ASSERT(regs_i86.transition("cx") == 1);
	CU_ASSERT(regs_i86.transition("ch") == 1);
	CU_ASSERT(regs_i86.transition("cl") == 1);
	CU_ASSERT(regs_i86.transition("dx") == 1);
	CU_ASSERT(regs_i86.transition("dh") == 1);
	CU_ASSERT(regs_i86.transition("dl") == 1);

	AFA AF_id(tt::Identifier);
	CU_ASSERT(AF_id.transition("ax") == 1);
	CU_ASSERT(AF_id.transition("ah") == 1);
	CU_ASSERT(AF_id.transition("al") == 1);
	CU_ASSERT(AF_id.transition("bx") == 1);
	CU_ASSERT(AF_id.transition("bh") == 1);
	CU_ASSERT(AF_id.transition("bl") == 1);
	CU_ASSERT(AF_id.transition("cx") == 1);
	CU_ASSERT(AF_id.transition("ch") == 1);
	CU_ASSERT(AF_id.transition("cl") == 1);
	CU_ASSERT(AF_id.transition("dx") == 1);
	CU_ASSERT(AF_id.transition("dh") == 1);
	CU_ASSERT(AF_id.transition("dl") == 1);
	
	CU_ASSERT(AF_id.transition("JUAN") == 3);
	CU_ASSERT(AF_id.transition("Carro") == 4);
	CU_ASSERT(AF_id.transition("_Test12") == 6);
	CU_ASSERT(AF_id.transition("_Avion_") == 6);
	CU_ASSERT(AF_id.transition("Aeropueto") == 8);
	CU_ASSERT(AF_id.transition("REF_00256") == 8);
	CU_ASSERT(AF_id.transition("REF_08956") == 8);
	CU_ASSERT(AF_id.transition("Romero1") == 6);
	CU_ASSERT(AF_id.transition("Romero1!") == 6);
	CU_ASSERT(AF_id.transition("1Romero1") == 0);


	AFA AF_segs(tt::i86_segs_l);
	CU_ASSERT(AF_segs.transition("es") == 1);
	CU_ASSERT(AF_segs.transition("ss") == 1);
	CU_ASSERT(AF_segs.transition("ds") == 1);
	CU_ASSERT(AF_segs.transition("cs") == 1);
	
	CU_ASSERT(AF_segs.transition("sp") == 1);
	CU_ASSERT(AF_segs.transition("bp") == 1);
	CU_ASSERT(AF_segs.transition("si") == 1);
	CU_ASSERT(AF_segs.transition("di") == 1);
	CU_ASSERT(AF_segs.transition("ip") == 1);

	
}