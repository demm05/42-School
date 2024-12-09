/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:04:29 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/24 21:05:00 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "rush.h"

void	free_dictionary(struct s_dictionary *dict)
{
	if (dict)
	{
		free(dict->number);
		free(dict->printable_char);
		free(dict);
	}
}

void	free_arguments(struct s_arguments *args)
{
	int	i;

	i = 0;
	if (args)
	{
		free(args->number);
		free(args->path_to_dict);
		if (args->dict)
		{
			while (i < args->size)
			{
				free_dictionary(args->dict[i]);
				i++;
			}
			free(args->dict);
		}
	}
}

void	free_split(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}
