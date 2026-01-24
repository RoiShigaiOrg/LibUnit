#include "libunit.h"
#include <stdlib.h>

void	load_test(t_list **test_list, char *name, int (*test_function)(void))
{
	t_unit_test	*test;
	
	test = malloc(sizeof(t_unit_test));
	if (!test)
		return (NULL);
	test->name = name;
	test->test_function = test_function;
	ft_lstadd_back(test_list, test);
}
