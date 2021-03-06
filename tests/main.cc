

#ifdef OCTETOS_CC_V0
	#include "v0.hh"
#endif


int main(int argc, char *argv[])
{
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();
	
#ifdef OCTETOS_CC_V0
	CU_pSuite pSuite_v0 = CU_add_suite("Core", v0_init, v0_clean);
	if (NULL == pSuite_v0)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	if ((NULL == CU_add_test(pSuite_v0, "AFD A..", v0_AFD_A)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	if ((NULL == CU_add_test(pSuite_v0, "AFD B..", v0_AFD_B)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	if ((NULL == CU_add_test(pSuite_v0, "AFD C..", v0_AFD_C)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/*if ((NULL == CU_add_test(pSuite_v0, "Test performace", v0_performance)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}*/

	if ((NULL == CU_add_test(pSuite_v0, "Developing..", v0_developing)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}
	
#endif
	
	/* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}
