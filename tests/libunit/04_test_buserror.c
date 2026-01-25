/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_test_buserror.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:20:09 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:20:19 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bus_error_function(void)
{
	int		*iptr;
	char	*cptr;

	__asm__("pushf\norl $0x40000,(%rsp)\npopf");
	cptr = malloc(sizeof(int) + 1);
	iptr = (int *)++cptr;
	*iptr = 42;
	return (0);
}

int	test_buserror(void)
{
	if (bus_error_function())
		return (0);
	else
		return (1);
}
