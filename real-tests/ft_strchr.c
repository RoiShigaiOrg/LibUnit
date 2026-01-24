/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:54:32 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 13:59:19 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if ((unsigned char)s[i] == (c % 256))
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int	main()
{
	printf("%s\n", ft_strchr("teste", 357));
	printf("%s\n", ft_strchr("teste", 1024));
	return (0);
}*/
