#include "libft.h"

int	test_segfault(void)
{
	if (*(char *)-1)
		return (0);
	else
		return (1);
}
