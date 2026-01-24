/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:54:49 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 12:56:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen((char *)s1);
	size += ft_strlen((char *)s2);
	res = malloc((size + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res = ft_memcpy(res, s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(&res[ft_strlen((char *)s1)], s2, ft_strlen((char *)s2) + 1);
	return (res);
}
