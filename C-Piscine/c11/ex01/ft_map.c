/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:00:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/29 12:42:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int f(int))
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}

/*#include <stdio.h>
int power(int nb)
{
	return (nb * nb);
}

int main(void)
{
	int	*res;
	int	nums[6] = {1, 2, 3, 4, 5, 6};
	int	i = 0;
	res = ft_map(nums, 6, &power);
	while (i < 6)
	{
		printf("%d\n", res[i]);
		i++;
	}
}*/