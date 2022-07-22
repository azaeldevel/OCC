
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

void v0_AFD_A()
{
	CU_ASSERT(LENGTH_TT(tt::Identifier) == 2);
	a::DFA<char> idC(TABLE(tt::Identifier));
	CU_ASSERT(idC.transition("gnu") == 3);
	CU_ASSERT(idC.transition("1gnu") == 0);
	CU_ASSERT(idC.transition("azael") == 5);
	CU_ASSERT(idC.transition("zip1") == 4);
	CU_ASSERT(idC.transition("azip1") == 5);
	CU_ASSERT(idC.transition("az3p1") == 5);

	CU_ASSERT(LENGTH_TT(tt::Interger) == 2);
	a::DFA<char> intC(TABLE(tt::Interger));
	CU_ASSERT(intC.transition("1236589") == 7);
	CU_ASSERT(intC.transition("00065") == 5);
	CU_ASSERT(intC.transition("00A65") == 0);
	//std::cout << "count : " << intC.transition("1236589") << "\n";

	//Assembler A
	a::DFA<char> i8080_regs(TABLE(a::i8086_regs));
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
	CU_ASSERT(i8080_regs.transition("ax	") == 2);
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
	CU_ASSERT(i8080_regs.transition("dl	") == 2);
}
void v0_AFD_B()
{
	b::DFA<char> idCB(TABLE(tt::IdentifierB));
	CU_ASSERT(idCB.transition("gnu") == 3);
	CU_ASSERT(idCB.transition("1gnu") == 0);
	CU_ASSERT(idCB.transition("azael") == 5);
	CU_ASSERT(idCB.transition("zip1") == 4);
	CU_ASSERT(idCB.transition("azip1") == 5);
	CU_ASSERT(idCB.transition("az3p1") == 5);
	//std::cout << "EOF : " << EOF << "\n";

	CU_ASSERT(LENGTH_TT(tt::Interger) == 2);
	b::DFA<char> intCB(TABLE(tt::Integer_B));
	//CU_ASSERT(intCB.transition("1236589") == 7);
	//CU_ASSERT(intCB.transition("00065") == 5);
	CU_ASSERT(intCB.transition("00A65") == 0);
	//CU_ASSERT(intCB.transition("00065 ") == 5);
	//std::cout << "count : " << intCB.transition("1236589") << "\n";
	//CU_ASSERT(intCB.transition("00065	") == 5);
	//std::cout << "counbt : " << intCB.transition("00A65") << "\n";
}
void v0_AFD_C()
{
	c::Identifier<char> id;
	//std::cout << "count : " << id.transition("1gnu") << "\n";
	CU_ASSERT(id.transition("gnu") == 3);
	CU_ASSERT(id.transition("1gnu") == 0);
	CU_ASSERT(id.transition("azael") == 5);
	CU_ASSERT(id.transition("zip1") == 4);
	CU_ASSERT(id.transition("azip1") == 5);
	CU_ASSERT(id.transition("az3p1") == 5);
	CU_ASSERT(id.transition("_gnu") == 4);
	
	c::Integer<char> integer;
	CU_ASSERT(integer.transition("1236589") == 7);
	CU_ASSERT(integer.transition("00065") == 5);
	CU_ASSERT(integer.transition("00A65") == 0);
}
void v0_performance()
{
	
	a::DFA<char> idC(TABLE(tt::Identifier));
	auto begin_a = high_resolution_clock::now();
	for(unsigned int i = 0; i < 1000000; i++)
	{
		//CU_ASSERT(idC.transition("gnu") == 0);
		CU_ASSERT(idC.transition("1gnu") == 0);
		CU_ASSERT(idC.transition("azael") == 5);
		CU_ASSERT(idC.transition("zip1") == 4);
		CU_ASSERT(idC.transition("azip1") == 5);
	}
	auto end_a = high_resolution_clock::now();
	auto duration_a = duration_cast<milliseconds>(end_a - begin_a);
	std::cout << "AFD(A) : " << duration_a.count() << "\n";

	b::DFA<char> idCB(TABLE(tt::IdentifierB));
	auto begin_b = high_resolution_clock::now();
	for(unsigned int i = 0; i < 1000000; i++)
	{
		//CU_ASSERT(idCB.transition("gnu") == 0);
		CU_ASSERT(idCB.transition("1gnu") == 0);
		CU_ASSERT(idCB.transition("azael") == 5);
		CU_ASSERT(idCB.transition("zip1") == 4);
		CU_ASSERT(idCB.transition("azip1") == 5);
	}
	auto end_b = high_resolution_clock::now();
	auto duration_b = duration_cast<milliseconds>(end_b - begin_b);
	std::cout << "AFD(B) : " << duration_b.count() << "\n";

	c::Identifier<char> id;
	auto begin_c = high_resolution_clock::now();
	for(unsigned int i = 0; i < 1000000; i++)
	{
		//CU_ASSERT(id.transition("gnu") == 0);
		CU_ASSERT(id.transition("1gnu") == 0);
		CU_ASSERT(id.transition("azael") == 5);
		CU_ASSERT(id.transition("zip1") == 4);
		CU_ASSERT(id.transition("azip1") == 5);
	}
	auto end_c = high_resolution_clock::now();
	auto duration_c = duration_cast<milliseconds>(end_c - begin_c);
	std::cout << "AFD(C) : " << duration_c.count() << "\n";
}
void v0_developing()
{	
}