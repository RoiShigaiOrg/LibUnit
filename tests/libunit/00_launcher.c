/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:19:41 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:19:52 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tests.h"
#include "libunit.h"

int	libunit_launcher(void)
{
	t_test_group	tests;

	tests = new_test_group("libunit");
	load_test(&tests, "Test Print Stdout Function",
		&test_print_stdout_function, 0);
	load_test(&tests, "Test KO", &test_ko, 0);
	load_test(&tests, "Test Segfault", &test_segfault, 0);
	load_test(&tests, "Test Bus Error", &test_buserror, 0);
	load_test(&tests, "Test Skipped Test", &test_ok, 1);
	load_test(&tests, "Test Timeout", &test_timeout, 0);
	load_test(&tests, "Test OK", &test_ok, 0);
	launch_test(&tests);
	return (0);
}
