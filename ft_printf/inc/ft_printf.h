/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 17:28:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/14 17:42:10 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

typedef struct format_info
{
	int	is_valid;
	int	len;
	int	f_len;
}	t_format_info;
typedef int	(*t_spec_formatter)(va_list);

int	_putchar(char c);
int	pf_37(va_list val);
int	pf_char(va_list val);
int	pf_string(va_list val);
int	pf_integer(va_list val);
int	pf_unsigned(va_list val);
int	pf_hex(va_list val);
int	pf_uhex(va_list val);
int	pf_pointer(va_list val);

#endif
