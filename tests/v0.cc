
#include <AF.hh>
#include <tt.hh>
#include <A.hh>


#include <iostream>
#include <chrono>

#include "v0.hh"

using namespace oct::cc;
using namespace std::chrono;

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
	CU_ASSERT(LENGTH_TT(tt::Identifier) == 2);
	AFDA<char> idC(TABLE(tt::Identifier));
	CU_ASSERT(idC.transition("gnu") == 3);
	CU_ASSERT(idC.transition("1gnu") == 0);
	CU_ASSERT(idC.transition("azael") == 5);
	CU_ASSERT(idC.transition("zip1") == 4);
	CU_ASSERT(idC.transition("azip1") == 5);
	CU_ASSERT(idC.transition("az3p1") == 5);
		
	AFDB<char> idCB(TABLE(tt::IdentifierB));
	CU_ASSERT(idCB.transition("gnu") == 3);
	CU_ASSERT(idCB.transition("1gnu") == 0);
	CU_ASSERT(idCB.transition("azael") == 5);
	CU_ASSERT(idCB.transition("zip1") == 4);
	CU_ASSERT(idCB.transition("azip1") == 5);
	CU_ASSERT(idCB.transition("az3p1") == 5);
	//std::cout << "EOF : " << EOF << "\n";
	
	/*
	auto begin_a = high_resolution_clock::now();
	for(unsigned int i = 0; i < 1000000; i++)
	{
		CU_ASSERT(idC.transition("1gnu") == 0);
		CU_ASSERT(idC.transition("azael") == 5);
		CU_ASSERT(idC.transition("zip1") == 4);
		CU_ASSERT(idC.transition("azip1") == 5);
	}
	auto end_a = high_resolution_clock::now();
	auto duration_a = duration_cast<milliseconds>(end_a - begin_a);
	std::cout << "AFD(A) : " << duration_a.count() << "\n";
	
	auto begin_b = high_resolution_clock::now();
	for(unsigned int i = 0; i < 1000000; i++)
	{
		CU_ASSERT(idCB.transition("1gnu") == 0);
		CU_ASSERT(idCB.transition("azael") == 5);
		CU_ASSERT(idCB.transition("zip1") == 4);
		CU_ASSERT(idCB.transition("azip1") == 5);
	}
	auto end_b = high_resolution_clock::now();
	auto duration_b = duration_cast<milliseconds>(end_b - begin_b);
	std::cout << "AFD(B) : " << duration_b.count() << "\n";
	*/
	
	CU_ASSERT(LENGTH_TT(tt::Interger) == 2);
	AFDA<char> intC(TABLE(tt::Interger));
	CU_ASSERT(intC.transition("1236589") == 7);
	CU_ASSERT(intC.transition("00065") == 5);
	CU_ASSERT(intC.transition("00A65") == 0);
	//std::cout << "counbt : " << intC.transition("00A65") << "\n";
	
	CU_ASSERT(LENGTH_TT(tt::Interger) == 2);
	AFDB<char> intCB(TABLE(tt::Integer_B));
	CU_ASSERT(intCB.transition("1236589") == 7);
	CU_ASSERT(intCB.transition("00065") == 5);
	CU_ASSERT(intCB.transition("00A65") == 2);
	//std::cout << "counbt : " << intC.transition("00A65") << "\n";
	
	//Assembler A
	AFDA<char> i8080_regs(a::i8086_regs,LENGTH_TT(a::i8086_regs));
	try
	{
		CU_ASSERT(i8080_regs.transition("alg") == 0);
	}
	catch(const oct::core::v3::Exception& ex)
	{
		std::cout << ex.describe() << "\n";
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
	}
	CU_ASSERT(i8080_regs.transition("ax") == 2);
	CU_ASSERT(i8080_regs.transition("ax,") == 2);
	CU_ASSERT(i8080_regs.transition("ax ") == 2);
	CU_ASSERT(i8080_regs.transition("ah") == 2);
	CU_ASSERT(i8080_regs.transition("al") == 2);
	CU_ASSERT(i8080_regs.transition("az") == 0);
	CU_ASSERT(i8080_regs.transition("am") == 0);
	//std::cout << "count : " << i8080_regs.transition("ax") << "\n";
	CU_ASSERT(i8080_regs.transition("all") == 0);
	CU_ASSERT(i8080_regs.transition("al()") == 0);
	CU_ASSERT(i8080_regs.transition("bx") == 2);
	CU_ASSERT(i8080_regs.transition("bh") == 2);
	CU_ASSERT(i8080_regs.transition("bh,") == 2);
	CU_ASSERT(i8080_regs.transition("bl") == 2);
	CU_ASSERT(i8080_regs.transition("bl  ") == 2);
	CU_ASSERT(i8080_regs.transition("bl.") == 0);
	CU_ASSERT(i8080_regs.transition("bl-") == 0);
	CU_ASSERT(i8080_regs.transition("cx") == 2);
	CU_ASSERT(i8080_regs.transition("cx,") == 2);
	CU_ASSERT(i8080_regs.transition("ch") == 2);
	CU_ASSERT(i8080_regs.transition("cl") == 2);
	CU_ASSERT(i8080_regs.transition("cl ") == 2);
	CU_ASSERT(i8080_regs.transition("dx") == 2);
	CU_ASSERT(i8080_regs.transition("dx,") == 2);
	CU_ASSERT(i8080_regs.transition("dx  ") == 2);
	//CU_ASSERT(i8080_regs.transition("dx ") == 2);
	CU_ASSERT(i8080_regs.transition("dh") == 2);
	CU_ASSERT(i8080_regs.transition("dl") == 2);
	CU_ASSERT(i8080_regs.transition("dl[]") == 0);
	CU_ASSERT(i8080_regs.transition("dl  ") == 2);
}