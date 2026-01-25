/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:15:13 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:15:33 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libunit.h"
#include "tests.h"

int	ft_isalpha_launcher(void)
{
	t_test_group	tests;

	tests = new_test_group("ft_isalpha");
	load_test(&tests, "Test alphanumeric character", &test_alpha, 0);
	load_test(&tests, "Test non alphanumeric character", &test_not_alpha, 0);
	launch_test(&tests);
	return (0);
}
