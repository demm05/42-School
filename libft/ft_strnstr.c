/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:12:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:30:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, size_t n)
{
	size_t	len;

	len = 0;
	while (needle[len])
		len++;
	if (!len)
		return ((char *)str);
	if (!str && !n)
		return (0);
	while (*str && n >= len)
	{
		if (ft_strncmp(str, needle, len) == 0)
			return ((char *)str);
		str++;
		n--;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	char str1[] = "";
// 	char to_find1[] = "";
// 	printf("Test 1: %s\n", ft_strnstr(NULL, "FAKE", 0));
// 	return (0);
// }
