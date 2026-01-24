/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:40:21 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/24 10:41:35 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"

# define RED "\e[e;30m"
# define GREEN "\e[e;32m"
# define RESET "\e[0m"

typedef struct s_unit_test
{
	char	*name;
	int		(*test_function)(void);

}	t_unit_test;

#endif
