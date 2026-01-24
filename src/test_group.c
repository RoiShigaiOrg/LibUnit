#include "libunit.h"

t_test_group	new_test_group(char *function_name)
{
	t_test_group tests_list;

	tests_list.function_name = function_name;
	tests_list.tests_list = NULL;
	return (tests_list);
}
