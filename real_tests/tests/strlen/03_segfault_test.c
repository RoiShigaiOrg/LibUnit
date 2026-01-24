#include "libft.h"

int	segfault_test(void)
{
	if (ft_strlen(NULL) == 3)
		return (0);
	else
		return (1);
}
