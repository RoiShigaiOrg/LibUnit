/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:56:08 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 12:56:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_malloc_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	size = ft_strlen(s);
	if (size == 0)
		return (1);
	size = ft_strlen(s) - start;
	if (len > size)
		return (size);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = start;
	if (s == NULL || start >= ft_strlen(s))
	{
		str = malloc(1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc ((get_malloc_size(s, start, len) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', len + 1);
	while (s[i] && ((i - start) < len))
	{
		str[i - start] = s[i];
		i++;
	}
	str[i - start] = '\0';
	return (str);
}
