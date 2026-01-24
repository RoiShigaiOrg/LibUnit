/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melschmi <melschmi@student.42lyon.fr>      +#+  +:+       +#+        */
/*            +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 16:41:41 by melschmi          #+#    #+#             */
/*   Updated: 2025/11/19 19:30:15 by melschmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define DICTIONARY "cspdiuxX%"

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

int		ft_printf(const char *buff, ...);
char	*create_specificier(char const *buff, va_list args);
t_bool	is_dictionary(char c);
char	*get_string_args(char c, va_list args);
char	*proceed_char(va_list args);
char	*proceed_str(va_list args);
char	*proceed_pointers(va_list args);
char	*proceed_integer(va_list args);
char	*proceed_hex(va_list args);
char	*proceed_uinteger(va_list args);
char	*proceed_uphex(va_list args);
char	*proceed_char(va_list args);
char	*unsigned_convert_base(unsigned long nbr, char *base);
char	*convert_base(int nbr, char *base);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

#endif
