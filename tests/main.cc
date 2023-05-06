

#ifdef OCTETOS_CC_V0
	#include "v0.hh"
#endif


int main(int argc, char *argv[])
{
	/* initialize the CUnit test registry */
	if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

#ifdef OCTETOS_CC_V0
	CU_pSuite pSuite_AI_v0 = CU_add_suite("A the First", v0_init, v0_clean);
	if (NULL == pSuite_AI_v0)
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_AI_v0, "Developing..", v0_AI_developing)))
	{
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite_AI_v0, "A constants ..", v0_A_consts)))
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

int v0_init(void)
{


	return 0;
}
int v0_clean(void)
{


	return 0;
}
