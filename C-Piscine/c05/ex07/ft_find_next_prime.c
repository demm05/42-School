/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 13:11:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/19 16:53:21 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	mid;
	int		low;
	int		high;

	if (nb < 2)
		return (nb);
	low = 1;
	high = nb;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid > nb)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (high);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	square_root_of;

	if (nb == 2)
		return (1);
	if (nb == 0 || nb == 1 || nb % 2 == 0)
		return (0);
	i = 3;
	square_root_of = ft_sqrt(nb);
	while (i < square_root_of)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
	{
		nb ++;
	}
	return (nb);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_find_next_prime(3329919));
	return (0);
}*/