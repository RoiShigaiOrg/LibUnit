/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:40:21 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/24 16:07:05 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"
# include <sys/wait.h>

# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define RESET "\e[m"

typedef struct s_unit_test
{
	char	*name;
	int		(*test_function)(void);

}	t_unit_test;


typedef struct s_test_group
{
	char	*function_name;
	t_list	*tests_list;
}	t_test_group;

int				load_test(t_list **test_list, char *name, int (*test_function)(void));
int				launch_test(t_list **test_list);
int				display_result(t_unit_test *test, int status);
t_test_group	new_test_group(char *function_name);

#endif
