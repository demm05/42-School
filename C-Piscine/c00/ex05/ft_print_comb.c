/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 17:53:08 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/09 11:02:37 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char ch1, char ch2, char ch3)
{
	write(1, &ch1, 1);
	write(1, &ch2, 1);
	write(1, &ch3, 1);
	if (ch1 != '7')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	ch1;
	char	ch2;
	char	ch3;

	ch1 = '0';
	while (ch1 <= '7')
	{
		ch2 = ch1 + 1;
		while (ch2 <= '8')
		{
			ch3 = ch2 + 1;
			while (ch3 <= '9')
			{
				ft_print(ch1, ch2, ch3);
				ch3++;
			}
			ch2++;
		}
		ch1++;
	}
}

/*int	main(void)
{
	ft_print_comb();
	return (0);
}*/
