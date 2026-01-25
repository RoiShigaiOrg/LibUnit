#include "libft.h"
#include "libunit.h"
#include "tests.h"

int ft_atoi_launcher(void)
{
	t_test_group	tests;

	tests = new_test_group("ft_atoi");
	load_test(&tests, "Test zero value", &test_zero_value, 0);
	load_test(&tests, "Test positive value", &test_positive_value, 0);
	load_test(&tests, "Test negative value", &test_negative_value, 0);
	load_test(&tests, "Test valid prefixes", &test_valid_prefixes, 0);
	load_test(&tests, "Test invalid prefixes", &test_invalid_prefixes, 0);
	launch_test(&(tests.tests_list));
	return (0);
}
