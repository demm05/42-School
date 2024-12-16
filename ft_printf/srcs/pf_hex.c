/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:40:20 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 18:49:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	hex_len(unsigned long long nb);
static char	*get_hex(unsigned long long nb, int is_upper);

int	pf_uhex(va_list val)
{
	unsigned int	nb;
	int				len;
	char			*buffer;

	nb = va_arg(val, unsigned int);
	if (nb == 0)
		return (_putchar('0'));
	buffer = get_hex(nb, 1);
	len = _pf_putstr(buffer, 1);
	free(buffer);
	return (len);
}

int	pf_lhex(va_list val)
{
	unsigned int	nb;
	int				len;
	char			*buffer;

	nb = va_arg(val, unsigned int);
	if (nb == 0)
		return (_putchar('0'));
	buffer = get_hex(nb, 0);
	len = _pf_putstr(buffer, 1);
	free(buffer);
	return (len);
}

static char	*get_hex(unsigned long long nb, int is_upper)
{
	int		i;
	int		len;
	int		r;
	char	*buffer;

	len = hex_len(nb);
	buffer = malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < len)
	{
		r = nb % 16;
		if (r <= 9)
			buffer[len - i - 1] = r + '0';
		else if (is_upper)
			buffer[len - i - 1] = r - 10 + 'A';
		else
			buffer[len - i - 1] = r - 10 + 'a';
		i++;
		nb /= 16;
	}
	buffer[i] = 0;
	return (buffer);
}

static int	hex_len(unsigned long long nb)
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
