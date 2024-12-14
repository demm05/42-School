/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:40:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/14 17:40:50 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static unsigned int	get_exp(unsigned int nb)
{
	unsigned int	exp;

	exp = 1;
	while (nb / 10 != 0)
	{
		exp = exp * 10;
		nb = nb / 10;
	}
	return (exp);
}

int	pf_unsigned(va_list val)
{
	unsigned int	nb;
	unsigned int	len;
	unsigned int	exp;

	nb = va_arg(val, unsigned int);
	if (nb == 0)
		return (_putchar('0'));
	len = 0;
	exp = get_exp(nb);
	while (nb)
	{
		len += _putchar(nb / exp + '0');
		nb %= exp;
		exp /= 10;
	}
	return (len);
}
