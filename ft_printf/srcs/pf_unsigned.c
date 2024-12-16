/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:40:36 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 18:50:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	get_len_of_num(unsigned int n)
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

char	*ft_uitoa(unsigned int num)
{
	int		len;
	char	*res;

	len = get_len_of_num(num);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len] = 0;
	while (len)
	{
		res[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	return (res);
}

int	pf_unsigned(va_list val)
{
	unsigned int	nb;
	char			*buffer;

	nb = va_arg(val, unsigned int);
	buffer = ft_uitoa(nb);
	if (!buffer)
		return (0);
	nb = _pf_putstr(buffer, 1);
	free(buffer);
	return (nb);
}
