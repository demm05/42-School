/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:41:01 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/14 17:41:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	get_exp(int nb)
{
	int	exp;

	exp = 1;
	while (nb / 10 != 0)
	{
		exp = exp * 10;
		nb = nb / 10;
	}
	return (exp);
}

static void	initialize_var(int *nb, int *last, int *len)
{
	*last = *nb % 10;
	*nb /= 10;
	*len = 0;
	if (*nb < 0)
	{
		*nb = -*nb;
		*last = -*last;
		*len += _putchar('-');
	}
}

int	pf_integer(va_list val)
{
	int	nb;
	int	last;
	int	len;
	int	exp;

	nb = va_arg(val, int);
	initialize_var(&nb, &last, &len);
	if (nb > 0)
	{
		exp = get_exp(nb);
		while (nb)
		{
			len += _putchar(nb / exp + '0');
			nb %= exp;
			exp /= 10;
		}
	}
	len += _putchar(last + '0');
	return (len);
}
