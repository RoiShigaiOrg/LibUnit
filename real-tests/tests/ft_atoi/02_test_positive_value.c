#include "libft.h"

int	test_positive_value(void)
{
	if (ft_atoi("255") == 255)
		return (0);
	else
		return (-1);
}
