/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:35:28 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/19 15:51:03 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int	bound;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	bound = max - min;
	arr = (int *)malloc(sizeof(int) * bound);
	if (!arr)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	*range = arr;
	while (i < bound)
	{
		arr[i] = min + i;
		i++;
	}
	return (bound);
}

/*#include <stdio.h>
int main(void)
{
	int size;
	int *arr;
	int i;

	size = ft_ultimate_range(&arr, 5, 10);
	i = 0;
	while (i < size)
	{
		printf("%d", arr[i]);
		i++;
	}
	return (0);
}*/