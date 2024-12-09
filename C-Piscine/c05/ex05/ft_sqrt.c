/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:58:42 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/19 16:52:05 by dmelnyk          ###   ########.fr       */
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
	return (0);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d", ft_sqrt(20000000));
	return (0);
}*/