/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 12:56:12 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/29 14:11:49 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int f(char*))
{
	while (*tab)
	{
		if (f(*tab) != 0)
			return (1);
		tab++;
	}
	return (0);
}

/*#include <stdio.h>
#include <stdlib.h>
int power(char	*ch)
{
	return (ch[2] == 'z');
}

int main(void)
{
	int	res;
	char	*nums[100] = {"456", "234", "345", "sdsdfg", "\0", "23zg"};
	res = ft_any(nums, &power);
	printf("%d\n", res);
}*/