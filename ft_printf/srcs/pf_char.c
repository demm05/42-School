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

char	*pf_char(va_list val, t_spec_info s_info)
{
	char	c;
	char	*buffer;

	c = va_arg(val, int);
	buffer = malloc(sizeof(char) * 2);
	buffer[0] = c;
	buffer[1] = 0;
	return (buffer);
}

char	*pf_37(va_list val, t_spec_info s_info)
{
	char	*buffer;

	(void)val;
	buffer = malloc(sizeof(char) * 2);
	buffer[0] = '%';
	buffer[1] = 0;
	return (buffer);
}
