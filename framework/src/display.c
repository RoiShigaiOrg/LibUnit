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
	ft_printf("status %d\n", status);
	if (status == 14)
		return (ft_strdup("[TIMEOUT]"));
	if (status == 0)
		return (ft_strdup("[OK]"));
	if (status == 255)
		return (ft_strdup("[KO]"));
	if (status == SIGILL)
		return (ft_strdup("[SIGILL]"));
	if (status == SIGABRT)
		return (ft_strdup("[SIGABRT]"));
	if (status == SIGFPE)
		return (ft_strdup("[SIGFPE]"));
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
		ft_printf(" %s(skipped %i tests)%s", YELLOW, test_group->skipped_tests,
			RESET);
	ft_printf("\n\n");
}

void	display_footer(t_test_group *test_group, int success)
{
	ft_printf("\n");
	if (success == test_group->run_tests)
		ft_printf("%s====> %s tests success (%i / %i)%s", GREEN,
			test_group->function_name, success, test_group->run_tests, RESET);
	else
		ft_printf("%s====> %s tests failed (%i / %i)%s", RED,
			test_group->function_name,
			success, test_group->run_tests, RESET);
	ft_printf("\n\n");
}

int	display_result(t_test_group *test_group, t_unit_test *test, int status)
{
	char	*status_str;

	status_str = format_status(status);
	if (status_str == NULL)
		return (0);
	if (status == 0)
		ft_printf("%s: %s%s: %s%s\n", test_group->function_name, GREEN,
			test->name, status_str, RESET);
	else
		ft_printf("%s: %s%s: %s%s\n", test_group->function_name, RED,
			test->name, status_str, RESET);
	if (status_str != NULL)
		free(status_str);
	return (1);
}
