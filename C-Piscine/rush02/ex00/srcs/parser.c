/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:17:17 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/25 23:29:46 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

int	get_len_of_srts(char **strs)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (strs[i])
	{
		size += ft_strlen(strs[i]);
		size++;
		i++;
	}
	return (size);
}

char *trim_whitespace(char *str) 
{
	char	**strs;
	char	*result;
	int		i;
	int		size;

	strs = ft_split(str, " ");
	size = get_len_of_srts(strs);
	result = malloc(sizeof(char *) * size);
	i = 0;
	while (strs[i])
	{
		size -= ft_strlen(strs[i]);
		ft_strcat(result, strs[i]);
		if (size - i > 1)
			ft_strcat(result, " ");
		i++;
	}
	free_split(strs);
	return (result);
}

t_dictionary	**get_dict(char *path_to_file, int *size)
{
	char				**lines;
	t_dictionary		**arr;
	char				**columns;
	int					i;
	int					j;

	lines = ft_split(get_content_of_file(path_to_file, size), "\n");
	arr = malloc(sizeof(t_dictionary *) * *size);
	if (!lines || !arr)
		return (NULL);
	i = 0;
	j = 0;
	while (j < *size)
	{
		columns = ft_split(lines[j], ":");
		if (!columns)
            continue;

        arr[j] = malloc(sizeof(t_dictionary));
        arr[j]->number = ft_strdup(trim_whitespace(columns[0]));
        arr[j]->printable_char = ft_strdup(trim_whitespace(columns[1]));
        arr[j]->size_of_number = ft_strlen(arr[j]->number);
		i += 2;
		j++;
		free_split(columns);
	}
	free_split(lines);
	return (arr);
}
