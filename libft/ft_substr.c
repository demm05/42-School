/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:13:08 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:30:23 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len >= s_len - start)
		len = s_len - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (i + start < s_len && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	*res;
// 	char	*s;
// 
// 	s = ft_strdup("0123456789");
// 	res = ft_substr(s, 9, 10);
// 	printf("%s", res);
// 	free(res);
// 	free(s);
// 	return (0);
// }
