/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_group.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 10:45:58 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 10:46:14 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_test_group	new_test_group(char *function_name)
{
	t_test_group	tests_list;

	tests_list.function_name = function_name;
	tests_list.tests_list = NULL;
	return (tests_list);
}
