/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:20:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/28 13:28:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int f(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

/*#include <stdio.h>
#include <stdlib.h>
int power(char	*ch)
{
	return (ch[4] == 'z');
}

int main(void)
{
	int	res;
	char	*nums[5];
	int	i;

	i = 0;
	while (i < 4)
	{
		nums[i] = malloc(sizeof(char *) * 16);
		i++;
	}
	nums[0] = "hello ow";
	nums[1] = "asd z";
	nums[2] = "dfdfadsfasd";
	nums[3] = "asfasdfasdf";
	nums[4] = 0;
	res = ft_count_if(nums, 4, &power);
	printf("%d\n", res);
}*/
