/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:29:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/29 12:44:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int f(int, int))
{
	int	i;
	int	order;

	i = -1;
	order = 0;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) != 0 && order == 0)
			order = f(tab[i], tab[i + 1]);
		else if (f(tab[i], tab[i + 1]) > 0 && order < 0)
			return (0);
		else if (f(tab[i], tab[i + 1]) < 0 && order > 0)
			return (0);
	}
	return (1);
}

/*int	test(int a, int b)
{
	return (a - b);
}

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int	arr[] = {-10, 1, 5, 7, 9};
	printf("%d", ft_is_sort(arr, 5, test));

	int	arr2[] = {1000, 100, 100, 100};
	printf("%d", ft_is_sort(arr2, 4, test));

	int	arr3[] = {10, 0, 10};
	printf("%d", ft_is_sort(arr3, 3, test));

	return (0);
}*/