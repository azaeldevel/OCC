#include <Buffer.hh>
#include <AF-2.hh>
#include <tt-2.hh>

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
	AFD<char> idC(tt::Identifier_C,sizeof(tt::Identifier_C));
	CU_ASSERT(idC.transition("gnu") == 3);
	
}