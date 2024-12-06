/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:11:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:32:39 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_array(char	**s, size_t size)
{
	size_t	i;

	i = 0;
	while (i++ < size)
		free(s[i]);
	free(s);
}

static size_t	strs_in_str(char const *s, char c)
{
	size_t	strs;
	int		is_new_str;

	strs = 0;
	is_new_str = 1;
	while (*s)
	{
		if (*s != c && is_new_str)
		{
			strs++;
			is_new_str = 0;
		}
		else if (*s == c && !is_new_str)
			is_new_str = 1;
		s++;
	}
	return (strs);
}

static size_t	get_len_of_word(char const *str, char c)
{
	const char	*anchor;

	anchor = str;
	while (*str && *str != c)
		str++;
	return (str - anchor);
}

static int	split_it(char const *s, char **s2, char c, size_t size)
{
	size_t	i;
	size_t	len_of_word;

	i = 0;
	while (i < size)
	{
		while (*s == c)
			s++;
		len_of_word = get_len_of_word(s, c);
		if (len_of_word == 0)
			break ;
		*s2 = ft_substr(s, 0, len_of_word);
		if (!*s2)
		{
			free_array(s2, size);
			return (1);
		}
		s += len_of_word;
		s2++;
		i++;
	}
	*s2 = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	substrs;

	if (!s)
		return (0);
	substrs = strs_in_str(s, c);
	res = malloc((substrs + 1) * sizeof(char *));
	if (!res)
		return (0);
	if (!split_it(s, res, c, substrs))
		return (0);
	return (res);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	**res;
// 
// 	res = ft_split("asdf asdf asdzf   z", 'z'); 
// 	if (!res)
// 		return (1);
// 	while (*res)
// 	{
// 		printf("%s\n", *res);
// 		free(*res);
// 		res++;
// 	}
// 	free(res);
// 	return (0);
// }
