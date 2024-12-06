/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:40:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/27 18:31:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < 1)
		return (size + src_len);
	while (src[i] && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = 0;
	if (size < dest_len)
		return (src_len + size);
	return (dest_len + src_len);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char dest[55] = "HEllo worlds";
	char src[] = "asdadfadsf";
	unsigned int size;

	size = 6;
	printf("3 = %d %s %s\n", ft_strlcat(dest, "ASD", size), dest, src);
	printf("0 = %d %s %s\n", ft_strlcat(dest, "", size), dest, src);
	printf("27 = %d %s %s\n", ft_strlcat(dest, src, size), dest, src);
	return (0);
}*/