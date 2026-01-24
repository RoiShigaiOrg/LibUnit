/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:51:49 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 12:56:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem_res;

	mem_res = NULL;
	if ((size > 0) && (nmemb * size) > ((size_t) - 1 / size))
		return (NULL);
	if (nmemb > 0 && size > 0)
	{
		mem_res = malloc(nmemb * size);
		if (mem_res == NULL)
			return (NULL);
		ft_memset(mem_res, 0, size * nmemb);
		return (mem_res);
	}
	else
	{
		mem_res = malloc(0);
		if (mem_res == NULL)
			return (NULL);
		return (mem_res);
	}
}
