/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_convert_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:00:52 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/27 17:01:23 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_len(unsigned long n, int div)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n /= div;
		len++;
	}
	return (len);
}

static int	check_base(char *base)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	while (base[i])
	{
		c = 0;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[j] == base[i])
				c++;
			if (c > 1)
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	else
		return (1);
}

static void	basing(unsigned long nbr, char *base, int div, char *str)
{
	if (nbr > 0)
	{
		basing(nbr / div, base, div, str);
		str[ft_strlen(str)] = base[nbr % div];
	}
}

char	*unsigned_convert_base(unsigned long nbr, char *base)
{
	int		div;
	char	*str;

	if (check_base(base) == 1)
	{
		if (nbr == 0)
		{
			str = ft_calloc(2, sizeof(char));
			str[0] = base[0];
			return (str);
		}
		div = ft_strlen(base);
		str = ft_calloc(get_len(nbr, div) + 2, sizeof(char));
		if (str == NULL)
			return (NULL);
		basing(nbr, base, div, str);
		return (str);
	}
	return (NULL);
}
