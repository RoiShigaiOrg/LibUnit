/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:09:53 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 10:48:21 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	test(t_unit_test *test)
{
	return (run_print_fct(test->test_function));
}

int	launch_test(t_list **test_list)
{
	int		status;
	int		ret;
	pid_t	child_pid;

	ret = 0;
	if (test_list == NULL)
		return (-1);
	while (*test_list)
	{
		child_pid = fork();
		if (child_pid == 0)
			exit (test((*test_list)->content));
		else
			wait(&status);
		if (WIFEXITED(status))
			display_result((*test_list)->content, WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			display_result((*test_list)->content, WTERMSIG(status));
		test_list = &(*test_list)->next;
	}
	return (ret);
}
