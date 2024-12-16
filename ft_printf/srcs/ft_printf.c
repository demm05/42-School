/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:42:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 18:49:01 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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
		return (pf_lhex);
	if (c == 'X')
		return (pf_uhex);
	return (0);
}

void	parse_specifier(const char *format, t_format_info *info, va_list val)
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

int	parse_format(const char *format, va_list val)
{
	int				len;
	int				i;
	t_format_info	info;

	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			parse_specifier(format + i, &info, val);
			if (info.is_valid)
			{
				len += info.len;
				i += info.f_len;
				continue ;
			}
		}
		len += _putchar(format[i++]);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	int				len;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	len = parse_format(format, args);
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	int a;
// 
// 	a = 123;
// 	printf("Hello my name is: %#x\n", a);
// 	ft_printf("Hello my name is: %x", a);
// 	return (0);
// }
