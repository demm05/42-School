/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:13:04 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:30:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_str_info	get_str_info(char const *str, char const *set)
{
	t_str_info	info;

	info.str_len = 0;
	info.set_in_str = 0;
	while (*str && ft_strchr(set, *str) != 0)
	{
		info.str_len++;
		info.set_in_str++;
		str++;
	}
	if (!*str)
		return (info);
	info.start = info.str_len;
	while (*str++)
		info.str_len++;
	str -= 2;
	info.end = info.str_len;
	while (*str && ft_strchr(set, *str) != 0)
	{
		str--;
		info.set_in_str++;
		info.end--;
	}
	return (info);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	t_str_info	info;

	if (!s1)
		return (0);
	info = get_str_info(s1, set);
	if (info.set_in_str == 0)
		return (ft_substr(s1, 0, info.str_len));
	if (info.str_len == info.set_in_str)
		return (ft_strdup(""));
	return (ft_substr(s1, info.start, info.end - info.start));
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	while (*s1 || *s2)
// 	{
// 		if (*s1 != *s2)
// 			return (*s1 - *s2);
// 		s1++;
// 		s2++;
// 	}
// 	return (0);
// }
// #include <stdio.h>
// int main(void)
// {
// 	char	*str = "  \t\n     ";
// 	char	*set = "\t\n "; 
// 	char	*res;
// 
// 	res = ft_strtrim(str, set);
// 	printf("\n%d", !ft_strcmp(res, set));
// 	printf("\n%s", res);
// 	return (0);
// }
