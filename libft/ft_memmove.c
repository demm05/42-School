/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:11:14 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:32:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (!dest && !src)
		return (dest);
	if (s < d)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
		while (n--)
			*d++ = *s++;
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char str[50] = "Hello word";
// 
// 	printf("%s", (char *)memmove(str + 5, str, 11));
// 	printf("\n%s", (char *)ft_memmove(str + 5, str, 11));
// }
