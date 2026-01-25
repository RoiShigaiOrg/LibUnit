/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:44:43 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 10:45:26 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <stdlib.h>

int	load_test(t_test_group *test_group, char *name, int (*test_function)(void), int skip)
{
	t_unit_test	*test;
	t_list		*new_node;

	if (skip)
	{
		test_group->skipped_tests += 1;
		return (0);
	}
	else
		test_group->run_tests += 1;
	test = malloc(sizeof(t_unit_test));
	if (!test)
		return (-1);
	test->name = name;
	test->test_function = test_function;
	new_node = ft_lstnew(test);
	if (!new_node)
	{
		free(test);
		return (-1);
	}
	ft_lstadd_back(&(test_group->tests_list), new_node);
	return (0);
}
