/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:29:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/19 16:47:01 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;
	int	i;

	result = 1;
	i = 0;
	while (i < nb)
	{
		result *= i + 1;
		i++;
	}
	return (result);
}

/* #include <stdio.h>
int main(void)
{
	printf("%d", ft_iterative_factorial(3));
	return (0);
} */