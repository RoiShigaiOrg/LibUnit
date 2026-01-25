/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:40:21 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 16:19:09 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"
# include <signal.h>
# include <sys/wait.h>
# include <time.h>
# include "timeout.h"

# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
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
	int		run_tests;
	int		skipped_tests;
} t_test_group;

int				load_test(t_test_group *test_group, char *name, int (*test_function)(void), int skip);
int				launch_test(t_test_group *test_group);
int				display_result(t_test_group *test_group, t_unit_test *test, int status);
void			display_header(t_test_group *test_group);
void			display_footer(t_test_group *test_group, int success);
t_test_group	new_test_group(char *function_name);
void			print_timeout(t_test_group *group, t_unit_test *test);
int				run_print_fct(int (*f)(void));

#endif
