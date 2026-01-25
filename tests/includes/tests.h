/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:18:52 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:19:15 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

int	libunit_launcher(void);
int	test_ok(void);
int	test_ko(void);
int	test_segfault(void);
int	test_buserror(void);
int	test_timeout(void);
int	test_print_stdout_function(void);

#endif
