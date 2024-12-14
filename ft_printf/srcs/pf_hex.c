/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:40:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/14 17:40:20 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	hex_len(unsigned int nb);
static void	put_hex(unsigned int nb, int is_upper);

int	pf_hex(va_list val)
{
	unsigned int	nb;

	nb = va_arg(val, unsigned int);
	if (nb == 0)
		return (_putchar('0'));
	put_hex(nb, 0);
	return (hex_len(nb));
}

int	pf_uhex(va_list val)
{
	unsigned int	nb;

	nb = va_arg(val, unsigned int);
	if (nb == 0)
		return (_putchar('0'));
	put_hex(nb, 0);
	return (hex_len(nb));
}

static int	hex_len(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		len++;
		nb /= 16;
	}
	return (len);
}

static void	put_hex(unsigned int nb, int is_upper)
{
	if (nb > 16)
	{
		put_hex(nb / 16, is_upper);
		put_hex(nb % 16, is_upper);
	}
	else if (nb <= 9)
		_putchar(nb + '0');
	else
	{
		if (is_upper)
			_putchar(nb - 10 + 'A');
		else
			_putchar(nb - 10 + 'a');
	}
}
