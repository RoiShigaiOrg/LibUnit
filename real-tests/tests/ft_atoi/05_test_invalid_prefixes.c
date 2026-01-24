#include "libft.h"

int	test_invalid_prefixes(void)
{
	if (ft_strlen("- +40") == 0)
		return (0);
	else
		return (-1);
}
