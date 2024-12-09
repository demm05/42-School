/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 20:21:53 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/25 23:38:11 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

char	*get_value_of_nbr(struct s_arguments *args, char *nbr, int size)
{
	int	i;
	int	len_of_nbr;

	i = 0;
	len_of_nbr = ft_strlen(nbr);
	while (i < args->size)
	{
		if (size == args->dict[i]->size_of_number)
		{
			if (size == 1 && ft_strncmp(nbr, args->dict[i]->number, 1) == 0)
				return (args->dict[i]->printable_char);
			else if (size == 2 && ft_strncmp(nbr, \
						args->dict[i]->number, len_of_nbr) == 0)
				return (args->dict[i]->printable_char);
			else if (size > 2)
			{
				return (args->dict[i]->printable_char);
			}
		}
		i++;
	}
	return (NULL);
}

char	*ch_get_digit_printable(struct s_arguments *args, char digit)
{
	char	temp[2];

	temp[0] = digit;
	return (ft_strdup(get_value_of_nbr(args, temp, 1)));
}

char	**get_digit_printable(struct s_arguments *args, char digit)
{
	char	temp[2];
	char	**result;
	int		i;

	i = 0;
	result = malloc(sizeof(char *) * 2);
	while (i < 2)
	{
		result[i] = 0;
		i++;
	}
	temp[0] = digit;
	result[0] = ft_strdup(get_value_of_nbr(args, temp, 1));
	return (result);
}

char	**get_tens_printable(struct s_arguments *args, char *number)
{
	char	**result;
	char	temp[2];
	int		i;

	i = 0;
	result = malloc(sizeof(char *) * 3);
	while (i < 3)
	{
		result[i] = 0;
		i++;
	}
	if (number[0] >= '2')
	{
		temp[0] = number[0];
		result[0] = ft_strdup(get_value_of_nbr(args, temp, 2));
		temp[0] = number[1];
		result[1] = ft_strdup(get_value_of_nbr(args, temp, 1));
	}
	else
	{
		result[0] = ft_strdup(get_value_of_nbr(args, number, 2));
	}
	return (result);
}

char	**get_hudrets_printable(struct s_arguments *args, char *number)
{
	char	**result;
	int		i;
	char	**temp;
	
	i = 0;
	result = malloc(sizeof(char *) * 5);
	while (i < 5)
	{
		result[i] = 0;
		i++;
	}
	result[0] = ch_get_digit_printable(args, number[0]);
	result[1] = ft_strdup(get_value_of_nbr(args, number, 3));
	if (number[1])
	{
		i = 2;
		temp = get_tens_printable(args, number + 1);
		while (*temp)
		{
			result[i] = *temp;
			i++;
			temp++;
		}
	}
	else if (number[2])
	{
		result[2] = ch_get_digit_printable(args, number[0]);
	}
	return (result);
}
