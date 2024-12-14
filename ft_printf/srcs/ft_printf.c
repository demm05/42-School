/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:42:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/14 17:42:52 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
#include <stdio.h>

t_spec_formatter	get_spec(char c)
{
	if (c == '%')
		return (pf_37);
	if (c == 'c')
		return (pf_char);
	if (c == 's')
		return (pf_string);
	if (c == 'p')
		return (pf_pointer);
	if (c == 'i' || c == 'd')
		return (pf_integer);
	if (c == 'u')
		return (pf_unsigned);
	if (c == 'x')
		return (pf_hex);
	if (c == 'X')
		return (pf_uhex);
	return (0);
}

void	parse_format(const char *format, t_format_info *info, va_list val)
{
	t_spec_formatter	f;	

	info->len = 0;
	info->f_len = 0;
	info->is_valid = 0;
	f = get_spec(*(format + 1));
	if (!f)
		return ;
	info->len = f(val);
	info->f_len = 2;
	info->is_valid = 1;
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_format_info	f_info;
	int				len;
	int				i;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			parse_format(format + i, &f_info, args);
			if (f_info.is_valid)
			{
				len += f_info.len;
				i += f_info.f_len;
				continue ;
			}
		}
		len += _putchar(format[i++]);
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	printf("Hello my name is: %s, I'm %d year's old", "Dmytro", 19);
// 	return (1);
// }
