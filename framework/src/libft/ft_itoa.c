/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:52:19 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 12:56:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long int n)
{
	size_t	res;

	res = 0;
	if (n <= 0)
	{
		n *= -1;
		res++;
	}
	while (n > 0)
	{
		n -= n % 10;
		n /= 10;
		res++;
	}
	return (res);
}

static void	recursion(long int n, char *str, size_t i)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
	{
		str[i] = (n % 10) + '0';
		n -= n % 10;
		recursion(n / 10, str, i - 1);
	}
	else
		str[i] = n + '0';
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;

	len = get_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (len == 0)
		return (str);
	if (n < 0)
		str[0] = '-';
	recursion(n, str, len - 1);
	return (str);
}
