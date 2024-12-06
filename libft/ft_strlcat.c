/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:12:11 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:32:22 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*d;
	const char	*s;
	size_t		n;
	size_t		d_len;

	d = dst;
	s = src;
	n = size;
	while (n-- != 0 && *dst != 0)
		dst++;
	d_len = dst - d;
	n = size - d_len;
	if (n-- == 0)
		return (d_len + ft_strlen(src));
	while (*src)
	{
		if (n)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = 0;
	return (d_len + (src - s));
}

// #include <stdio.h>
// int main(void)
// {
// 	char	*dest;
// 
// void	ft_print_result(int n)
// {
// 	char c;
// 
// 	if (n >= 10)
// 		ft_print_result(n / 10);
// 	c = n % 10 + '0';
// 	write (1, &c, 1);
// }
// 	dest = malloc(sizeof(char) * 15);
// 	ft_memset(dest, 'r', 15);
// 	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 5));
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// 	dest[10] = 'a';
// 	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 6));
// 	write(1, "\n", 1);
// 	write(1, dest, 15);
// 
// }
