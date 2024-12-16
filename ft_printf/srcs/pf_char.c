/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:39:58 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 18:49:18 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>

int	_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	pf_char(va_list val)
{
	char	c;

	c = va_arg(val, int);
	_putchar(c);
	return (1);
}

int	pf_37(va_list val)
{
	(void)val;
	_putchar('%');
	return (1);
}
