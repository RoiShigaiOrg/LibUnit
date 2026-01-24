#include "libft.h"
#include "tests.h"
#include "libunit.h"

int strlen_launcher(void)
{
	t_test_group	tests;
	t_list			*testlist;

	tests = new_test_group("ft_strlen")	;
	testlist = tests.tests_list;
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "Failed test", &failed_test);
	load_test(&testlist, "Segfault test", &segfault_test);
	load_test(&testlist, "Bus error test", &buserror_test);
	launch_test(&testlist);
	return (0);
}
