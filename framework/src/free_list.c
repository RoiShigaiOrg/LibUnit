/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:38:17 by melschmi          #+#    #+#             */
/*   Updated: 2026/01/25 16:44:51 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libunit.h"

void	free_test_list(t_list *test_list)
{
	ft_lstclear(test_list, &free);
}
