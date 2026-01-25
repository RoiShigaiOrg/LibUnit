/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_test_different_strings_positive_result.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:17:02 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:17:10 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	test_different_strings_positive_result(void)
{
	if (ft_strncmp("abczzz", "abcxxx", 6) > 0)
		return (0);
	else
		return (1);
}
