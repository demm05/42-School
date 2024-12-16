/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:42:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/16 18:50:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <unistd.h>

size_t	ft_strlen(const char *str)
{
	const char	*anchor;

	anchor = str;
	while (*str)
		str++;
	return (str - anchor);
}

int	_pf_putstr(char *s, int fd)
{
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	write(fd, s, len);
	return (len);
}

int	pf_string(va_list val)
{
	char	*s;

	s = va_arg(val, char *);
	if (!s)
		s = "(null)";
	return (_pf_putstr(s, 1));
}
