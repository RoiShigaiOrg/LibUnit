/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:31:24 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/27 16:53:19 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*proceed_pointers(va_list args)
{
	char			*ptr;
	char			*str;
	unsigned long	val;

	val = va_arg(args, unsigned long);
	if (val == 0)
		return (ft_strdup("(nil)"));
	ptr = unsigned_convert_base(val, "0123456789abcdef");
	str = ft_strjoin("0x", ptr);
	free(ptr);
	return (str);
}

char	*proceed_str(va_list args)
{
	char	*str;
	char	*arg;

	arg = (char *)va_arg(args, char *);
	if (arg == NULL)
		return (ft_strdup("(null)"));
	str = ft_strdup(arg);
	if (str == NULL)
		return (NULL);
	return (str);
}

t_bool	is_dictionary(char c)
{
	size_t	i;

	i = 0;
	while (DICTIONARY[i])
	{
		if (DICTIONARY[i] == c)
			return (TRUE);
		i++;
	}
	if (c == '\0')
		return (TRUE);
	return (FALSE);
}

char	*get_string_args(char c, va_list args)
{
	if (c == 'c')
		return (proceed_char(args));
	else if (c == 's')
		return (proceed_str(args));
	else if (c == 'p')
		return (proceed_pointers(args));
	else if (c == 'd' || c == 'i')
		return (proceed_integer(args));
	else if (c == 'u')
		return (proceed_uinteger(args));
	else if (c == 'x')
		return (proceed_hex(args));
	else if (c == 'X')
		return (proceed_uphex(args));
	else if (c == '%')
		return (ft_strdup("%"));
	return (NULL);
}
