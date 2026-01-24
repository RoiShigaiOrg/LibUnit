#include "libunit.h"
#include <stdlib.h>

void	load_test(t_list **test_list, char *name, int (*test_function)(void))
{
	t_unit_test	*test;
	t_list		*new;
	
	test = malloc(sizeof(t_unit_test));
	if (!test)
		return ;
	test->name = name;
	test->test_function = test_function;
	new = ft_lstnew(test);
	ft_lstadd_back(test_list, new);
}
