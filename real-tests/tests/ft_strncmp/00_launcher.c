/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:16:37 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:16:42 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"
#include "tests.h"

int	ft_strncmp_launcher(void)
{
	t_test_group	tests;

	tests = new_test_group("ft_strncmp");
	load_test(&tests, "Test empty string", &test_empty_strings_comparison, 0);
	load_test(&tests, "Test zero length", &test_zero_length, 0);
	load_test(&tests, "Test large length", &test_large_length, 0);
	load_test(&tests, "Test short length", &test_short_length, 0);
	load_test(&tests, "Test different strings positive result",
		&test_different_strings_positive_result, 0);
	load_test(&tests, "Test different strings negative result",
		&test_different_strings_negative_result, 0);
	launch_test(&tests);
	return (0);
}
