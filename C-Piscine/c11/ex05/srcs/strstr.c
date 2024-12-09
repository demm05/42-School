/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:47:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/28 17:39:36 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lib.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	len;

	len = 0;
	while (to_find[len])
		len++;
	if (!len)
		return (str);
	while (*str)
	{
		if (ft_strncmp(str, to_find, len) == 0)
			return (str);
		str++;
	}
	return (0);
}
