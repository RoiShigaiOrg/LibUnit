/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_test_different_strings_negative_result.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:17:05 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:17:10 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_different_strings_negative_result(void)
{
	if (ft_strncmp("abcxxx", "abczzz", 6) < 0)
		return (0);
	else
		return (1);
}
