#include "libft.h"

int	test_buserror(void)
{
	if (*(char *)(-1))
		return (0);
	else
		return (1);
}
