/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 16:43:09 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/27 16:43:42 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*proceed_integer(va_list args)
{
	char	*str;

	str = convert_base(va_arg(args, int), "0123456789");
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*proceed_char(va_list args)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[0] = (char) va_arg(args, int);
	return (str);
}

char	*proceed_uphex(va_list args)
{
	char	*str;

	str = unsigned_convert_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (str == NULL)
		return (NULL);
	return (str);
}

/*	Proceed_uinteger :
 *
 *		Will return the unsigned value of the actual arg 
 *			of va_list
 *
 *		return NULL if an error occur
 */

char	*proceed_uinteger(va_list args)
{
	char	*str;

	str = unsigned_convert_base(va_arg(args, unsigned int), "0123456789");
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*proceed_hex(va_list args)
{
	char	*str;

	str = unsigned_convert_base(va_arg(args, unsigned int), "0123456789abcdef");
	if (str == NULL)
		return (NULL);
	return (str);
}
