/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:16:14 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/19 14:17:26 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*anchor;

	anchor = str;
	while (*str)
		str++;
	return (str - anchor);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof * src * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/*#include <stdio.h>
int main(void)
{
	printf("%s", ft_strdup("Hello worlasdfasdfasdfasfdsafasdsdafds"));
	return (0);
}*/