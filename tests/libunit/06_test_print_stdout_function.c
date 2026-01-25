#include "libunit.h"
#include "ft_printf.h"

int	test_print_stdout_function(void)
{
	if (ft_printf("abc") == 3)
		return (0);
	else
		return (-1);
}
