/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:53:50 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/10 12:56:30 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*reverse_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*dest_;
	unsigned char			*src_;

	i = 0;
	dest_ = (unsigned char *)dest;
	src_ = (unsigned char *)src;
	while (n - i > 0)
	{
		dest_[n - i - 1] = src_[n - i - 1];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_;
	unsigned char	*src_;

	dest_ = (unsigned char *)dest;
	src_ = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest < src)
		ft_memcpy(dest, src, n);
	if (src < dest)
		reverse_memcpy(dest, src, n);
	return (dest);
}
