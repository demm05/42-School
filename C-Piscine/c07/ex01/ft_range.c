/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:18:23 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/20 14:43:06 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	range;

	if (min >= max)
		return (NULL);
	range = max - min;
	arr = (int *)malloc(sizeof(int) * range);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < range)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

/*#include <stdio.h>
int main(void)
{
	int *result = ft_range(100, 170);
	int i = 0;

	while (i < 171)
	{
		printf("%d\n", result[i]);
		i++;
	}
	return (0);
}*/