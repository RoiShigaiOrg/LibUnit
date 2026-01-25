/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_invalid_prefixes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:16:18 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:16:21 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_invalid_prefixes(void)
{
	if (ft_atoi("- +40") == 0)
		return (0);
	else
		return (-1);
}
