/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_test_large_length.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:16:55 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:17:10 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_large_length(void)
{
	if (ft_strncmp("abcde", "abcde", 99) == 0)
		return (0);
	else
		return (1);
}
