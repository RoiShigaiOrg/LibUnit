/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:09:53 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 16:22:23 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	test(t_unit_test *test)
{
	return (run_print_fct(test->test_function));
}

void	exec_test(t_list *test_list, t_test_group *test_group, int *score)
{
	int		status;
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == 0)
		exit (test(test_list->content));
	if (timeout(&status, child_pid) == 0)
	{
		if (WIFEXITED(status))
			display_result(test_group, test_list->content, WEXITSTATUS(status));
		else if (WIFSIGNALED(status))
			display_result(test_group, test_list->content, WTERMSIG(status));
		if (status == 0)
			*score += 1;
	}
	else
		print_timeout(test_group,test_list->content);
}

int	launch_test(t_test_group *test_group)
{
	t_list	*test_list;
	int		score;

	score = 0;
	if (!test_group)
		return (-1);
	display_header(test_group);
	test_list = test_group->tests_list;
	if (!test_list)
		return (0);
	while (test_list)
	{
		exec_test(test_list, test_group, &score);
		test_list = test_list->next;
	}
	display_footer(test_group, score);
	return (0);
}
