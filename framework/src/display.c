/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:44:35 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 18:03:40 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include "libunit.h"

static char	*format_status(int status)
{
	if (status == 0)
		return (ft_strdup("[OK]"));
	if (status == 255)
		return (ft_strdup("[KO]"));
	if (status == SIGBUS)
		return (ft_strdup("[SIGBUS]"));
	if (status == SIGSEGV)
		return (ft_strdup("[SIGSEGV]"));
	return (ft_strdup("[UNKNOWN]"));
}

void	display_header(t_test_group *test_group)
{
	ft_printf("\n<====================== ");
	ft_printf("%s test session starts", test_group->function_name);
	ft_printf(" ======================>\n\n");
	ft_printf("Collected %i tests", test_group->run_tests);
	if (test_group->skipped_tests)
		ft_printf(" (skipped %i tests)", test_group->skipped_tests);
	ft_printf("\n\n");
}

void	display_footer(t_test_group *test_group, int success)
{
	ft_printf("\n");
	if (success == test_group->run_tests)
		ft_printf("====> %s tests success (%i / %i)",
			test_group->function_name, success, test_group->run_tests);
	else
		ft_printf("====> %s tests failed (%i / %i)",
			test_group->function_name,
			success, test_group->run_tests);
	ft_printf("\n\n");
}

int	display_result(t_test_group *test_group, t_unit_test *test, int status)
{
	char	*status_str;

	status_str = format_status(status);
	if (status_str == NULL)
	{
		ft_printf("Test Execution Error...\n");
		return (-2);
	}
	if (status == 0)
		ft_printf("%s: %s: %s\n", test_group->function_name,
			test->name, status_str);
	else
		ft_printf("%s: %s: %s\n", test_group->function_name,
			test->name, status_str);
	if (status_str != NULL)
		free(status_str);
	return (1);
}
