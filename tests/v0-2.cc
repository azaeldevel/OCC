#include <Buffer.hh>
#include <AF-2.hh>
#include <tt-2.hh>

#include <CUnit/Basic.h>
#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace oct::cc;


int v02_init(void)
{
	return 0;
}
int v02_clean(void)
{
	return 0;
}


void v02_developing()
{
	AFD<char> idC(tt::Identifier_C,sizeof (tt::Identifier_C) / sizeof (tt::Identifier_C[0]));
	try
	{
		CU_ASSERT(idC.transition("gnu") == 3);
	}
	catch(const oct::core::v3::Exception& ex)
	{
		std::cout << ex.describe() << "\n";
	}
	catch(const std::exception& ex)
	{
		std::cout << ex.what() << "\n";
	}

	auto begin = high_resolution_clock::now();
	for(unsigned int i = 0; i < 1000000; i++)
	{
		CU_ASSERT(idC.transition("1gnu") == 0);
		CU_ASSERT(idC.transition("azael") == 5);
		CU_ASSERT(idC.transition("zip1") == 4);
		CU_ASSERT(idC.transition("azip1") == 5);
	}
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(end - begin);
	std::cout << "v0-2 : " << duration.count() << "\n";
}