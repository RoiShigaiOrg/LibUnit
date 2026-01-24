/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:55:58 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 12:56:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_ischarset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_len(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (check_ischarset(s1[i], set) == 1)
	{
		len++;
		i++;
	}
	i = ft_strlen((char *)s1) - 1;
	while (check_ischarset(s1[i], set) == 1)
	{
		len++;
		i--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	size;
	char	*str;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = get_len(s1, set) + 1;
	size = (ft_strlen((char *)s1) - len + 1);
	while (check_ischarset(s1[i], set) == 1)
		i++;
	if (size == 0)
	{
		str = malloc(1 * sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = ft_substr(s1, i, size);
	return (str);
}
