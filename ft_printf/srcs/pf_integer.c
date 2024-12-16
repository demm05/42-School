/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:41:01 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 18:49:43 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	get_len_of_num(long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	set_values(int n, long *num, int *len, int *is_minus)
{
	*num = n;
	*len = 0;
	*is_minus = 0;
	if (*num < 0)
	{
		*is_minus = 1;
		*num *= -1;
		*len = *len + 1;
	}
	*len += get_len_of_num(*num);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	int		is_minus;
	char	*res;

	set_values(n, &num, &len, &is_minus);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len] = 0;
	while (len - is_minus)
	{
		res[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	if (is_minus)
		res[0] = '-';
	return (res);
}

int	pf_integer(va_list val)
{
	int		nb;
	char	*buffer;

	nb = va_arg(val, int);
	buffer = ft_itoa(nb);
	if (!buffer)
		return (0);
	nb = _pf_putstr(buffer, 1);
	free(buffer);
	return (nb);
}
