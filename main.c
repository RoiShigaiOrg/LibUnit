#include "libunit.h"

int	basic_test(void)
{
	return (1);
}

int	basic_test2(void)
{
	return (0);
}

int	main()
{
	t_list	**test_list;

	test_list = ft_calloc(1, sizeof(t_list *));
	if (test_list == NULL)
		exit(EXIT_FAILURE);
	if (load_test(test_list, "Basic test", &basic_test) == -1)
		exit(EXIT_FAILURE);
	if (load_test(test_list, "Basic test2", &basic_test2) == -1)
		exit(EXIT_FAILURE);
	ft_printf("Return value : %d\n", launch_test(test_list));
	return (0);
}
