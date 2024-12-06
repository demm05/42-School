/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:16:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/29 10:13:08 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

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

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[] = "hello world";
	char to_find1[] = "world";
	printf("Test 1: %s\n", ft_strstr(str1, to_find1));
	printf("Test 1: %s\n", strstr(str1, to_find1));

	char str2[] = "hello world";
	char to_find2[] = "planet";
	printf("Test 2: %s\n", ft_strstr(str2, to_find2));
	printf("Test 2: %s\n", strstr(str2, to_find2));

	char str3[] = "";
	char to_find3[] = "";
	printf("Test 3: %s\n", ft_strstr(str3, to_find3));
	printf("Test 3: %s\n", strstr(str3, to_find3));

	char str4[] = "";
	char to_find4[] = "world";
	printf("Test 4: %s\n", ft_strstr(str4, to_find4));
	printf("Test 4: %s\n", strstr(str4, to_find4));

	char str5[] = "hello world";
	char to_find5[] = "ello";
	printf("Test 5: %s\n", ft_strstr(str5, to_find5));
	printf("Test 5: %s\n", strstr(str5, to_find5));
	return (0);
}*/