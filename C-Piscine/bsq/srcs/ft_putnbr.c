/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochernov <ochernov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 21:18:40 by ochernov          #+#    #+#             */
/*   Updated: 2024/08/26 21:51:40 by ochernov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int n)
{
	int	c;

	if (n < 0)
		write(1, "-", 1);
	if (n <= -10 || n >= 10)
		ft_putnbr(n / 10);
	c = n % 10;
	if (c < 0)
		c = -c;
	c += '0';
	write(1, &c, 1);
}
