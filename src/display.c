/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:44:35 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/24 16:08:51 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libunit.h"

static char	*format_status(int status)
{
	ft_printf("value = %d\n", status);
	if (status == 1)
		return(ft_strdup("[OK]"));
	if (status == 65280)
		return(ft_strdup("[KO]"));
	if (status == 127)
		return(ft_strdup("[SIGILL]"));
	if (status == 134)
		return(ft_strdup("[SIGABRT]"));
	if (status == 136)
		return(ft_strdup("[SIGFPE]"));
	if (status == 138)
		return(ft_strdup("[SIGBUS]"));
	if (status == 138)
		return(ft_strdup("[SEGV]"));
	return (ft_strdup("[UNKNOWN]"));
}

int	display_result(t_unit_test *test, int status)
{
	char	*status_str;

	status_str = format_status(status);
	if (status_str == NULL)
		return (0);
	if (status == 1)
		ft_printf("%s%s %s%s\n", GREEN, test->name, status_str, RESET);
	else
	 	ft_printf("%s%s %s%s\n", RED, test->name, status_str, RESET);
	if (status_str != NULL)
		free(status_str);
	return (1);
}
