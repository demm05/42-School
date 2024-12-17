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

char	*pf_string(va_list val, t_spec_info s_info)
{
	char	*s;

	s = va_arg(val, char *);
	if (!s)
	{
		if (s_info.precision < 5 && s_info.is_precision)
			return (ft_strdup(""));
		s = "(null)";
	}
	if (s_info.is_precision)
		return (ft_substr(s, 0, s_info.precision));
	return (ft_strdup(s));
}
