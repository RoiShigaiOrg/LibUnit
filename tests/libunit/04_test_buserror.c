#include "libft.h"

static int	bus_error_function(void)
{
	int 	*iptr;
	char 	*cptr;

	__asm__("pushf\norl $0x40000,(%rsp)\npopf");

	cptr = malloc(sizeof(int) + 1);
	iptr = (int *)++cptr;
	*iptr = 42;
	return 0;
}

int	test_buserror(void)
{
	if (bus_error_function())
		return (0);
	else
		return (1);
}
