#include "libft.h"

int	buserror_test(void)
{
	if (ft_strlen((char *)(-1)) == 3)
		return (0);
	else
		return (1);
}
