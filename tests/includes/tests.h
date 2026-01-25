/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:18:52 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:56:18 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

int	libunit_launcher(int skip);
int	test_ok(void);
int	test_ko(void);
int	test_segfault(void);
int	test_buserror(void);
int	test_timeout(void);
int	test_print_stdout_function(void);
int	test_sigabort(void);
int	test_sigfpe(void);

#endif
