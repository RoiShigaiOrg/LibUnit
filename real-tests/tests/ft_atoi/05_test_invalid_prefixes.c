#include "libft.h"

int	test_invalid_prefixes(void)
{
	if (ft_atoi("- +40") == 0)
		return (0);
	else
		return (-1);
}
