/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:13:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:30:42 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*anchor;

	anchor = 0;
	while (*s)
	{
		if (*s == (char)c)
			anchor = (char *)s;
		s++;
	}
	if (*s == (char)c)
		anchor = (char *)s;
	return (anchor);
}
