#include "libft.h"
#include "libunit.h"
#include "tests.h"

int ft_strlen_launcher(void)
{
	t_test_group	tests;

	tests = new_test_group("ft_strlen");
	load_test(&tests, "Test empty string", &test_empty_string, 0);
	load_test(&tests, "Test normal string", &test_normal_string, 0);
	launch_test(&tests);
	return (0);
}
