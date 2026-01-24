#include "libft.h"
#include "tests.h"
#include "libunit.h"

void	launch_tests(t_list **testlist)
{
	t_list	*node;
	t_unit_test	*unit_test;

	node = *testlist;
	while (node)
	{
		unit_test = (t_unit_test *)node->content;
		ft_printf("%s\n", unit_test->name);
		node = node->next;
	}
}

int strlen_launcher(void)
{
	t_list *testlist;
	
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "Failed test", &failed_test);
	launch_tests(&testlist);
	return (0);
}
