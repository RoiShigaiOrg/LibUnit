/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_test_empty_strings_comparison.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:16:46 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:17:10 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_empty_string(void)
{
	if (ft_strncmp("", "", 1) == 0)
		return (0);
	else
		return (1);
}
