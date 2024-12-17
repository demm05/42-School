/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:42:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 19:17:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

t_spec_formatter	get_spec(char c)
{
	if (!c)
		return (0);
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

static int	get_len_of_num(long n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (0);
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	do_width(char *buffer, t_format_info *t_info, t_spec_info s_info)
{
	int		i;
	char	pad;
	int		len;

	if (s_info.flags.zero)
		pad = '0';
	else
		pad = ' ';

	if (s_info.flags.minus)
		_pf_putstr(buffer, 1);
	i = 0;
	len = t_info->len;
	while (i++ < (s_info.width - len))
	{
		_putchar(pad);
		t_info->len++;	
	}
	if (!s_info.flags.minus)
		_pf_putstr(buffer, 1);
}

void	parse_specifier(const char *format, t_format_info *t_info, va_list val)
{
	t_spec_formatter	func;	
	t_spec_info			s_info;
	int					i;
	int					temp;
	char				*buffer;

	t_info->is_valid = 0;
	s_info.flags.plus = 0;
	s_info.flags.hash = 0;
	s_info.flags.minus = 0;
	s_info.flags.space = 0;
	s_info.flags.zero = 0;
	s_info.is_precision = 0;
	s_info.precision = 0;
	s_info.is_width = 0;
	s_info.width = 0;

	// Flags
	i = 0;
	while (format[i])
	{
		if (i == 0)
		{
			while (format[i] == '0' && (format[i + 1] >= '0' && format[i + 1] <= '9'))
				i++;
			if (format[i] == '.')
			{
				s_info.is_precision = 1;
				break ;
			}
			i = 0;
		}
		temp = parse_flag(format[i], t_info, &s_info.flags);
		if (temp == 1)
			i++;
		else if (temp == -1)
			return ;
		else if (!temp)
			break;
	}
	// Flags
	// if (format[i] >= '0' && format[i] <= '9')
	// {
	// 	s_info.width = ft_atoi(format + i);
	// 	while (!s_info.precision && (format[i] >= '0' && format[i] <= '9'))
	// 		i++;
	// 	i += get_len_of_num(s_info.width);

	// }
	// Width 
	if (format[i] >= '0' && format[i] <= '9')
	{
		s_info.width = ft_atoi(format + i);
		while (!s_info.width && format[i] == '0' && !s_info.is_precision)
			i++;
		i += get_len_of_num(s_info.width);
	}
	// Width 
	
	// Precision
	if (format[i] == '.')
	{
		s_info.is_precision = ++i;
		s_info.precision = ft_atoi(format + i); 
		while (!s_info.precision && format[i] == '0')
			i++;
		i += get_len_of_num(s_info.precision);
	}
	// Precision
	
	func = get_spec(*(format + i));
	if (!func)
		return ;
	buffer = func(val, s_info);
	if (!buffer)
		return ;
	//t_info->len = _pf_putstr(buffer, 1);
	t_info->len = ft_strlen(buffer);
	do_width(buffer, t_info, s_info);
	t_info->f_len = i + 2;
	t_info->is_valid = 1;
	free(buffer);
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
			parse_specifier(format + i + 1, &info, val);
			if (info.is_valid && info.len >= 0)
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
// 	printf("'%.s'\n", "-");
// 	ft_printf("%20d", -1); 
// 	return (0);
// }
