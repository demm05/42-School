/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:28:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 18:08:50 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct format_info
{
	int	is_valid;
	int	len;
	int	f_len;
}	t_format_info;
typedef int	(*t_spec_formatter)(va_list);

int		ft_printf(const char *format, ...);
int		_putchar(char c);
int		_pf_putstr(char *s, int fd);
int		pf_37(va_list val);
int		pf_char(va_list val);
int		pf_string(va_list val);
int		pf_integer(va_list val);
int		pf_unsigned(va_list val);
int		pf_lhex(va_list val);
int		pf_uhex(va_list val);
int		pf_pointer(va_list val);
size_t	ft_strlen(const char *str);

#endif
