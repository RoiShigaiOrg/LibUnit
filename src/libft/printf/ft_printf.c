/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 14:59:24 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/19 20:23:34 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *nb)
{
	int	len;

	len = write(1, str, ft_strlen(str));
	if (len < 0)
		len *= -1;
	*nb += len;
}

t_bool	check_c(const char *buff)
{
	size_t	i;

	i = 0;
	while (is_dictionary(buff[i]) == FALSE)
		i++;
	if (buff[i] == 'c')
		return (TRUE);
	return (FALSE);
}

void	ft_putchar(char *str, int *len)
{
	int	n;

	n = 0;
	n = write(1, &str[0], 1);
	if (n <= 0)
		n++;
	*len += n;
}

void	print_args(const char *buff, va_list args, size_t *index, int *len)
{
	char	*str;

	str = NULL;
	if (is_dictionary(buff[1]) == TRUE)
		str = get_string_args(buff[1], args);
	*index += 1;
	if (check_c(&buff[1]) == TRUE)
		ft_putchar(str, len);
	else
		ft_putstr(str, len);
	if (str != NULL)
		free(str);
}

int	ft_printf(const char *buff, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, buff);
	if (buff == NULL)
		return (-1);
	while (buff[i])
	{
		if (buff[i] == '%')
			print_args(&buff[i], args, &i, &len);
		else
			len += write(1, &buff[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
