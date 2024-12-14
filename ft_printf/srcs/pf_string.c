/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:42:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/14 17:42:27 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	pf_string(va_list val)
{
	char	*s;
	int		i;

	s = va_arg(val, char *);
	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		_putchar(s[i++]);
	return (i);
}
