
#include <AF.hh>
#include <tt.hh>
#include <A-tt.hh>
#include <A.hh>
#include <Buffer.hh>


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
	//CU_ASSERT(LENGTH_TT(tt::a::Identifier) == 2);
	dfa::A<char> idC(TABLE(a::tt::Identifier));
	//std::cout << "count : " << idC.transition("gnu") << "\n";
	CU_ASSERT(idC.transition("gnu") == 3);
	CU_ASSERT(idC.transition("_gnu_") == 5);
	CU_ASSERT(idC.transition("1gnu") == 0);
	CU_ASSERT(idC.transition("azael") == 5);
	CU_ASSERT(idC.transition("azael ") == 5);
	CU_ASSERT(idC.transition("azael	") == 5);
	CU_ASSERT(idC.transition("zip1") == 4);
	CU_ASSERT(idC.transition("azip1") == 5);
	CU_ASSERT(idC.transition("az3p1") == 5);

	CU_ASSERT(LENGTH_TT(a::tt::Interger) == 2);
	dfa::A<char> intC(TABLE(tt::a::Interger));
	CU_ASSERT(intC.transition("1236589") == 7);
	CU_ASSERT(intC.transition("00065") == 5);
	CU_ASSERT(intC.transition("00A65") == 0);
	
	dfa::A<char> intC_0x(TABLE(a::tt::Integer_0x));
	CU_ASSERT(intC_0x.transition("0x23ae47") == 8);
	CU_ASSERT(intC_0x.transition("0x00065") == 7);
	CU_ASSERT(intC_0x.transition("0x00A65") == 7);

	
	//Assembler A
	dfa::A<char> i8086_regs(TABLE(a::tt::i8086_regs));
	try
	{
		CU_ASSERT(i8086_regs.transition("alg") == 0);
	}
	catch(const oct::core::v3::Exception& ex)
	{
		std::cout << ex.describe() << "\n";
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
	}
	CU_ASSERT(i8086_regs.transition("ax") == 2);
	CU_ASSERT(i8086_regs.transition("ax,") == 2);
	CU_ASSERT(i8086_regs.transition("ax ") == 2);
	CU_ASSERT(i8086_regs.transition("ax	") == 2);
	CU_ASSERT(i8086_regs.transition("ah") == 2);
	CU_ASSERT(i8086_regs.transition("al") == 2);
	CU_ASSERT(i8086_regs.transition("az") == 0);
	CU_ASSERT(i8086_regs.transition("am") == 0);
	//std::cout << "count : " << i8080_regs.transition("ax") << "\n";
	CU_ASSERT(i8086_regs.transition("all") == 0);
	CU_ASSERT(i8086_regs.transition("al()") == 0);
	CU_ASSERT(i8086_regs.transition("bx") == 2);
	CU_ASSERT(i8086_regs.transition("bh") == 2);
	CU_ASSERT(i8086_regs.transition("bh,") == 2);
	CU_ASSERT(i8086_regs.transition("bl") == 2);
	CU_ASSERT(i8086_regs.transition("bl  ") == 2);
	CU_ASSERT(i8086_regs.transition("bl.") == 0);
	CU_ASSERT(i8086_regs.transition("bl-") == 0);
	CU_ASSERT(i8086_regs.transition("cx") == 2);
	CU_ASSERT(i8086_regs.transition("cx,") == 2);
	CU_ASSERT(i8086_regs.transition("ch") == 2);
	CU_ASSERT(i8086_regs.transition("cl") == 2);
	CU_ASSERT(i8086_regs.transition("cl ") == 2);
	CU_ASSERT(i8086_regs.transition("dx") == 2);
	CU_ASSERT(i8086_regs.transition("dx,") == 2);
	CU_ASSERT(i8086_regs.transition("dx  ") == 2);
	//CU_ASSERT(i8080_regs.transition("dx ") == 2);
	CU_ASSERT(i8086_regs.transition("dh") == 2);
	CU_ASSERT(i8086_regs.transition("dl") == 2);
	CU_ASSERT(i8086_regs.transition("dl[]") == 0);
	CU_ASSERT(i8086_regs.transition("dl  ") == 2);
	CU_ASSERT(i8086_regs.transition("dl	") == 2);


	dfa::A<char> i8086_segs(TABLE(a::tt::i8086_segs));
	CU_ASSERT(i8086_segs.transition("bp") == 2);
	CU_ASSERT(i8086_segs.transition("cs") == 2);
	CU_ASSERT(i8086_segs.transition("di") == 2);
	CU_ASSERT(i8086_segs.transition("ds") == 2);
	CU_ASSERT(i8086_segs.transition("es") == 2);
	CU_ASSERT(i8086_segs.transition("ip") == 2);
	CU_ASSERT(i8086_segs.transition("si") == 2);
	/*
	i8086_segs.enable_echo(true);
	std::cout << "count : " << i8086_segs.transition("si") << "\n";
	i8086_segs.enable_echo(false);
	*/
	CU_ASSERT(i8086_segs.transition("sp") == 2);
	CU_ASSERT(i8086_segs.transition("ss") == 2);

	dfa::A<char> i8086_insts(TABLE(a::tt::i8086_insts));
	CU_ASSERT(i8086_insts.transition("aaa") == 3);
	const tt::a::Transition* accepted = i8086_insts.get_accepted();
	CU_ASSERT(accepted != NULL);
	if(accepted) CU_ASSERT(accepted->token == (oct::Word)a::tt::Tokens::i8086_aaa);
	CU_ASSERT(i8086_insts.transition("aaa;") == 3);
	accepted = i8086_insts.get_accepted();
	CU_ASSERT(accepted != NULL);
	if(accepted) CU_ASSERT(accepted->token == (oct::Word)a::tt::Tokens::i8086_aaa);
	CU_ASSERT(i8086_insts.transition("aaa ") == 3);
	accepted = i8086_insts.get_accepted();
	CU_ASSERT(accepted != NULL);
	if(accepted) CU_ASSERT(accepted->token == (oct::Word)a::tt::Tokens::i8086_aaa);
	/*i8086_insts.enable_echo(true);
	auto i8086_insts_count1 = i8086_insts.transition("aaa;");
	i8086_insts.enable_echo(false);
	std::cout << "count : " << i8086_insts_count1 << "\n";
	if(i8086_insts.get_accepted()) std::cout << "0-->(" << i8086_insts.get_accepted()->next << ")\n";*/
	CU_ASSERT(i8086_insts.transition("aad") == 3);
	accepted = i8086_insts.get_accepted();
	CU_ASSERT(accepted != NULL);
	CU_ASSERT(accepted->token == (oct::Word)a::tt::Tokens::i8086_aad);
	CU_ASSERT(i8086_insts.transition("aam") == 3);
	accepted = i8086_insts.get_accepted();
	CU_ASSERT(accepted != NULL);
	CU_ASSERT(accepted->token == (oct::Word)a::tt::Tokens::i8086_aam);
	CU_ASSERT(i8086_insts.transition("aas") == 3);
	accepted = i8086_insts.get_accepted();
	CU_ASSERT(accepted != NULL);
	CU_ASSERT(accepted->token == (oct::Word)a::tt::Tokens::i8086_aas);
	CU_ASSERT(i8086_insts.transition("adc") == 3);
	accepted = i8086_insts.get_accepted();
	CU_ASSERT(accepted != NULL);
	CU_ASSERT(accepted->token == (oct::Word)a::tt::Tokens::i8086_adc);
	CU_ASSERT(i8086_insts.transition("add") == 3);	
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_add);
	CU_ASSERT(i8086_insts.transition("and") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_and_token);
	CU_ASSERT(i8086_insts.transition("call") == 4);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_call);
	CU_ASSERT(i8086_insts.transition("calling") == 0);
	CU_ASSERT(i8086_insts.transition("cbw") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_cbw);
	CU_ASSERT(i8086_insts.transition("cbwl") == 0);	
	CU_ASSERT(i8086_insts.transition("clc") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_clc);
	CU_ASSERT(i8086_insts.transition("cld") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_cld);
	CU_ASSERT(i8086_insts.transition("cli") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_cli);
	CU_ASSERT(i8086_insts.transition("cmc") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_cmc);
	CU_ASSERT(i8086_insts.transition("cmp") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_cmp);
	CU_ASSERT(i8086_insts.transition("cmps") == 4);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_cmps);
	CU_ASSERT(i8086_insts.transition("cwd") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_cwd);
	CU_ASSERT(i8086_insts.transition("cw5") == 0);	
	CU_ASSERT(i8086_insts.transition("cwdd") == 0);
	CU_ASSERT(i8086_insts.transition("daa") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_daa);
	CU_ASSERT(i8086_insts.transition("da1") == 0);
	CU_ASSERT(i8086_insts.transition("daaa") == 0);
	CU_ASSERT(i8086_insts.transition("das") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_das);
	CU_ASSERT(i8086_insts.transition("das1") == 0);
	CU_ASSERT(i8086_insts.transition("dec") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_dec);
	CU_ASSERT(i8086_insts.transition("div") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_div);
	CU_ASSERT(i8086_insts.transition("esc") == 3);	
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_esc);
	CU_ASSERT(i8086_insts.transition("hlt") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_hlt);
	CU_ASSERT(i8086_insts.transition("idiv") == 4);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_idiv);
	CU_ASSERT(i8086_insts.transition("imul") == 4);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_imul);
	CU_ASSERT(i8086_insts.transition("in") == 2);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_in);
	CU_ASSERT(i8086_insts.transition("inc") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_inc);
	CU_ASSERT(i8086_insts.transition("int") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_int_token);
	CU_ASSERT(i8086_insts.transition("intr") == 4);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_intr);
	CU_ASSERT(i8086_insts.transition("into") == 4);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_into);
	CU_ASSERT(i8086_insts.transition("intt") == 0);	
	CU_ASSERT(i8086_insts.transition("ints") == 0);	
	CU_ASSERT(i8086_insts.transition("iret") == 4);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_iret);
	CU_ASSERT(i8086_insts.transition("ja") == 2);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_ja);
	CU_ASSERT(i8086_insts.transition("jae") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jae);
	CU_ASSERT(i8086_insts.transition("jb") == 2);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jb);
	//i8086_insts.enable_echo(true);
	CU_ASSERT(i8086_insts.transition("jbe") == 3);
	//i8086_insts.enable_echo(false);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jbe);
	CU_ASSERT(i8086_insts.transition("jc") == 2);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jc);
	//i8086_insts.enable_echo(true);
	CU_ASSERT(i8086_insts.transition("jcxz") == 4);
	//i8086_insts.enable_echo(false);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jcxz);
	//i8086_insts.enable_echo(true);
	CU_ASSERT(i8086_insts.transition("je") == 2);
	//i8086_insts.enable_echo(false);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_je);
	CU_ASSERT(i8086_insts.transition("jg") == 2);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jg);
	//i8086_insts.enable_echo(true);
	CU_ASSERT(i8086_insts.transition("jge") == 3);
	//i8086_insts.enable_echo(false);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jge);
	CU_ASSERT(i8086_insts.transition("jl") == 2);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jl);
	CU_ASSERT(i8086_insts.transition("jle") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jle);
	CU_ASSERT(i8086_insts.transition("jmp") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jmp);
	CU_ASSERT(i8086_insts.transition("jnc") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jnc);
	CU_ASSERT(i8086_insts.transition("jne") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jne);
	CU_ASSERT(i8086_insts.transition("jno") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jno);
	CU_ASSERT(i8086_insts.transition("jnp") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jnp);
	CU_ASSERT(i8086_insts.transition("jns") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jns);
	CU_ASSERT(i8086_insts.transition("jo") == 2);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jo);
	CU_ASSERT(i8086_insts.transition("jp") == 2);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_jp);
	CU_ASSERT(i8086_insts.transition("js") == 2);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_js);
	CU_ASSERT(i8086_insts.transition("lahf") == 4);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_lahf);
	CU_ASSERT(i8086_insts.transition("lds") == 3);
	CU_ASSERT(i8086_insts.get_actual()->token == (oct::Word)a::tt::Tokens::i8086_lds);
	
		
	CU_ASSERT(length("section") == 7);
	//std::cout << "count : " << length<char>("section") << "\n";
	CU_ASSERT(length("code") == 4);

	CU_ASSERT(equal("section","section"));
	CU_ASSERT(not equal("section","code"));
	CU_ASSERT(equal("code","code"));
	CU_ASSERT(not equal("code","section"));

	Buffer buff1("section code  		{   \n}");
	CU_ASSERT(buff1.walk("section") != NULL);
	CU_ASSERT(buff1.get_base() == 7);
	CU_ASSERT(buff1.get_actual() == ' ');
	//std::cout << "count : " << buff1.eat_whites() << "\n";
	CU_ASSERT(buff1.consume_whites() == 1);
	//std::cout << "count : " << buff1.get_actual() << "\n";
	CU_ASSERT(buff1.get_actual() == 'c');
	//std::cout << "String : " << buff1.walk("code") << "\n";
	CU_ASSERT(buff1.walk("code") != NULL);
	//std::cout << "count : " << buff1.get_actual() << "\n";
	CU_ASSERT(buff1.consume_whites() == 4);
	//std::cout << "count : " << buff1.eat_whites() << "\n";
	CU_ASSERT(buff1.walk('{') != NULL);
	CU_ASSERT(buff1.consume_whites() == 4);
	i8086_insts.transition(buff1);
	CU_ASSERT(buff1.walk('}') != NULL);


	const char* temp_string_1 = "prueba1..";
	char* temp_string_2= new char[length(temp_string_1) + 1];
	CU_ASSERT(copy(temp_string_1,length(temp_string_1),&temp_string_2) == length(temp_string_1));
	CU_ASSERT(equal(temp_string_1,temp_string_2));

	std::filesystem::path booting_file = "../../tests/booting.1.occ.asm";
	Buffer<char> buff2(booting_file);
	//std::cout << "text : " << (const char*)buff2 << "\n";
	CU_ASSERT(buff2.walk("section") != NULL);
	CU_ASSERT(buff2.get_base() == 7);
	CU_ASSERT(buff2.get_actual() == ' ');	
	CU_ASSERT(buff2.consume_whites() == 1);
	CU_ASSERT(buff2.get_actual() == 'c');
	CU_ASSERT(buff2.walk("code") != NULL);
	CU_ASSERT(buff2.consume_whites() == 4);
	CU_ASSERT(buff2.walk('{') != NULL);
	CU_ASSERT(buff2.consume_whites() == 5);
	//i8086_insts.enable_echo(true);
	CU_ASSERT(i8086_insts.transition(buff2) == 3);
	//i8086_insts.enable_echo(false);
	accepted = i8086_insts.get_accepted();
	CU_ASSERT(accepted != NULL);
	CU_ASSERT(accepted->token == (oct::Word)a::tt::Tokens::i8086_hlt);
	CU_ASSERT(buff2.walk(';') != NULL);
	CU_ASSERT(buff2.consume_whites() == 1);
	CU_ASSERT(buff2.walk('}') != NULL);
	
	std::filesystem::path booting_file3 = "../../tests/booting.2.occ.asm";
	Buffer<char> buff3(booting_file3);
	CU_ASSERT(buff3.consume_whites() == 3);
	CU_ASSERT(buff3.walk("section") != NULL);
	CU_ASSERT(buff3.consume_whites() == 1);
	//std::cout << "count : " << buff3.consume_whites() << "\n";
	CU_ASSERT(buff3.walk("code") != NULL);
	CU_ASSERT(buff3.consume_whites() == 7);
	CU_ASSERT(buff3.walk('{') != NULL);
	CU_ASSERT(buff3.consume_whites() == 2);
	
}
void v0_AFD_B()
{
	dfa::B<char> idCB(TABLE(tt::b::Identifier));
	CU_ASSERT(idCB.transition("gnu") == 3);
	CU_ASSERT(idCB.transition("1gnu") == 0);
	CU_ASSERT(idCB.transition("azael") == 5);
	CU_ASSERT(idCB.transition("zip1") == 4);
	CU_ASSERT(idCB.transition("azip1") == 5);
	CU_ASSERT(idCB.transition("az3p1") == 5);
	//std::cout << "EOF : " << EOF << "\n";

	//CU_ASSERT(LENGTH_TT(tt::b::Integer) == 2);
	dfa::B<char> intCB(TABLE(tt::b::Integer));
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
	dfa::C_Identifier<char> id;
	//std::cout << "count : " << id.transition("1gnu") << "\n";
	CU_ASSERT(id.transition("gnu") == 3);
	CU_ASSERT(id.transition("1gnu") == 0);
	CU_ASSERT(id.transition("azael") == 5);
	CU_ASSERT(id.transition("zip1") == 4);
	CU_ASSERT(id.transition("azip1") == 5);
	CU_ASSERT(id.transition("az3p1") == 5);
	CU_ASSERT(id.transition("_gnu") == 4);
	
	dfa::C_Integer<char> integer;
	CU_ASSERT(integer.transition("1236589") == 7);
	CU_ASSERT(integer.transition("00065") == 5);
	CU_ASSERT(integer.transition("00A65") == 0);
}
void v0_performance()
{
	
	dfa::A<char> idC(TABLE(tt::a::Identifier));
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

	dfa::B<char> idCB(TABLE(tt::b::Identifier));
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

	dfa::C_Identifier<char> id;
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