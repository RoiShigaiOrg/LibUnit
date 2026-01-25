/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_print_stdout_function.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:20:16 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:36:21 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	test_print_stdout_function(void)
{
	if (ft_printf("abc") == 3)
		return (0);
	else
		return (1);
}
