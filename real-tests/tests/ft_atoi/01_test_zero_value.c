#include "libft.h"

int	test_zero_value(void)
{
	if (ft_atoi("0") == 0)
		return (0);
	else
		return (1);
}
