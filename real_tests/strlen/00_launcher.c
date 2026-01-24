#include "libft.h"
#include "tests.h"
#include "libunit.h"

int strlen_launcher(void)
{
	t_list *testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "Failed test", &failed_test);
	launch_tests(&testlist);
	return (0);
}
