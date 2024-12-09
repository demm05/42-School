/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 18:23:55 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/19 19:02:59 by dmelnyk          ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

void	joid_strings(char *buffer, char **strs, char *sep, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		buffer = ft_strcpy(buffer, strs[i]);
		if (i == size - 1)
			break ;
		*buffer = *sep;
		buffer++;
		i++;
	}
	*buffer = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*output;
	int		bound;

	if (size == 0)
	{
		return ((char *)malloc(sizeof(char)));
	}
	i = 0;
	bound = 0;
	while (i < size)
	{
		bound += ft_strlen(strs[i]);
		i++;
	}
	output = (char *)malloc(sizeof(char) * bound + 1);
	joid_strings(output, strs, sep, size);
	return (output);
}

/*#include <stdio.h>
int	main(void)
{
	char	**strs;
	char	*separator;
	char	*result;
	int	size;

	size = 3;
	strs = (char **)malloc(3 * sizeof(char *));
	strs[0] = (char *)malloc(sizeof(char) * 5 + 1);
	strs[1] = (char *)malloc(sizeof(char) * 7 + 1);
	strs[2] = (char *)malloc(sizeof(char) * 14 + 1);
	strs[0] = "Hello";
	strs[1] = "friend,";
	strs[2] = "you are awesome";
	separator = " ";
	result = ft_strjoin(size, strs, separator);
	printf("%s$\n", result);
	free(result);
}*/