#include "libft.h"

int	test_valid_prefixes(void)
{
	if (ft_atoi("  \t\t\f ---++-10") == 10)
		return (0);
	else
		return (-1);
}
