/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_empty_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:14:37 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:14:49 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_empty_strings_comparison(void)
{
	if (ft_strlen("") == 0)
		return (0);
	else
		return (1);
}
