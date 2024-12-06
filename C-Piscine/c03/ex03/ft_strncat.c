/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:13:23 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/13 16:04:55 by dmelnyk          ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				len;
	unsigned int	i;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] && i < nb)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}

/*#include <stdio.h>
int main(void)
{
	char dest[50] = "What a nice world! ";

	printf("Dest before: %s\n", dest);
	ft_strncat(dest, "Hello world", 5);
	printf("Dest after:  %s", dest);
	return (0);
}*/