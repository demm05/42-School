/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:11:00 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:33:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*ptr;

	while (n--)
	{
		ptr = s;
		if (*ptr++ == (char)c)
			return ((void *)s);
		s++;
	}
	return (NULL);
}
// #include <stdio.h>
// int main(void)
// {
// 	char	str[] = "zacbggh";
// 
// 	printf("%s", (char *)ft_memchar(str, 'o', sizeof(str)));
// }
