#include "libunit.h"
#include <stdlib.h>

int	load_test(t_list **test_list, char *name, int (*test_function)(void))
{
	t_unit_test	*test;
	t_list		*new_node;
	
	test = malloc(sizeof(t_unit_test));
	if (!test)
		return (-1);
	test->name = name;
	test->test_function = test_function;
	new_node = ft_lstnew(test);
	if (!new_node)
	{
		free(test);
		return (-1);
	}
	ft_lstadd_back(test_list, new_node);
	return (0);
}
