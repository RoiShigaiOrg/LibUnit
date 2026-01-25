#include "libft.h"
#include "tests.h"
#include "libunit.h"

int libunit_launcher(void)
{
	t_test_group	tests;

	tests = new_test_group("libunit");
	load_test(&tests, "Test OK", &test_ok, 0);
	load_test(&tests, "Test KO", &test_ko, 0);
	load_test(&tests, "Test Segfault", &test_segfault, 0);
	load_test(&tests, "Test Bus Error", &test_buserror, 0);
	load_test(&tests, "Test Skipped Test", &test_ok, 1);
	launch_test(&(tests.tests_list));
	return (0);
}
