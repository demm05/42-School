/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:44:35 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/22 19:34:48 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_on_seperator(char ch, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ch == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && check_on_seperator(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !check_on_seperator(str[i], charset))
			i++;
	}
	return (count);
}

int	get_len_of_word(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !check_on_seperator(str[i], charset))
		i++;
	return (i);
}

char	*get_word(char *str, char *charset, int *ptr_i)
{
	int		i;
	char	*word;
	int		len_of_str;

	len_of_str = get_len_of_word(str, charset);
	word = malloc(sizeof(char) * len_of_str + 1);
	if (!word)
		return (0);
	i = 0;
	while (i < len_of_str)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	*ptr_i += i;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		i;
	int		j;

	arr = (char **)malloc(sizeof(char *) * (count_words(str, charset) + 1));
	if (arr == NULL)
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (check_on_seperator(str[i], charset))
			i++;
		if (str[i])
		{
			arr[j] = get_word(str + i, charset, &i);
			j++;
		}
	}
	arr[j] = 0;
	return (arr);
}

/*#include <stdio.h>
int main(int argc, char *argv[])
{
	char **strs;
	int i = 0;
	if (argc != 3)
	{	
		argv[1] = "Hello,,,asdfasdf worlds";
		argv[2] = ",";
	}
	strs = ft_split(argv[1], argv[2]);
	while (strs[i])
	{
		printf("%s\n", strs[i]);
		i++;
	}
	free(strs);
	return (0);
}*/