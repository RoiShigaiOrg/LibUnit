/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebilla <arebilla@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:12:29 by arebilla          #+#    #+#             */
/*   Updated: 2026/01/25 17:13:06 by arebilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

//ft_strlen
int	ft_strlen_launcher(void);
int	test_empty_string(void);
int	test_normal_string(void);

//ft_isalpha
int	ft_isalpha_launcher(void);
int	test_alpha(void);
int	test_not_alpha(void);

//ft_itoa
int	ft_atoi_launcher(void);
int	test_zero_value(void);
int	test_positive_value(void);
int	test_negative_value(void);
int	test_valid_prefixes(void);
int	test_invalid_prefixes(void);

//ft_strncmp
int	ft_strncmp_launcher(void);
int	test_empty_strings_comparison(void);
int	test_zero_length(void);
int	test_large_length(void);
int	test_short_length(void);
int	test_different_strings_positive_result(void);
int	test_different_strings_negative_result(void);

#endif
