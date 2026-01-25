/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:19:41 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:56:41 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "libunit.h"

int	libunit_launcher(int skip)
{
	t_test_group	tests;
	int				result;

	tests = new_test_group("libunit");
	if (skip)
		return (0);
	load_test(&tests, "Test OK", &test_ok, 0);
	load_test(&tests, "Test KO", &test_ko, 0);
	load_test(&tests, "Test Segfault", &test_segfault, 0);
	load_test(&tests, "Test Bus Error", &test_buserror, 0);
	load_test(&tests, "Test Skipped Test", &test_ok, 1);
	result = launch_test(&tests);
	ft_lstclear(&tests.tests_list, free);
	return (result);
}
