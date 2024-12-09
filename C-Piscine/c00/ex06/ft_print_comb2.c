/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:07:08 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/14 16:08:13 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb1)
{
	char	ch1;
	char	ch2;

	ch1 = nb1 / 10 + '0';
	ch2 = nb1 % 10 + '0';
	write(1, &ch1, 1);
	write(1, &ch2, 1);
}

void	ft_print_comb2(void)
{
	int	n0;
	int	n1;

	n0 = 0;
	n1 = 1;
	while (n0 <= 99 && n1 <= 99)
	{
		ft_putnbr(n0);
		write(1, " ", 1);
		ft_putnbr(n1);
		if (n0 >= 98 && n1 == 99)
			break ;
		else if (n1 < 99)
		{
			n1++;
		}
		else
		{
			n0++;
			n1 = n0 + 1;
		}
		write(1, ", ", 2);
	}
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}*/
