#include "libft.h"
#include "tests.h"
#include "libunit.h"

int strlen_launcher(void)
{
	t_test_group	tests;

	tests = new_test_group("ft_strlen");
	load_test(&tests, "Basic test", &basic_test, 0);
	load_test(&tests, "Failed test", &failed_test, 0);
	load_test(&tests, "Segfault test", &segfault_test, 0);
	load_test(&tests, "Bus error test", &buserror_test, 0);
	load_test(&tests, "Skipped test", &basic_test, 1);
	launch_test(&(tests.tests_list));
	return (0);
}
