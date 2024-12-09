/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 11:26:23 by fsmyth            #+#    #+#             */
/*   Updated: 2024/08/11 13:16:21 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	putline_first_last(int columns)
{
	int	i;

	i = 0;
	while (i < columns)
	{
		if (i == 0)
			ft_putchar('A');
		else if (i == (columns - 1))
			ft_putchar('C');
		else
			ft_putchar('B');
		i++;
	}
	ft_putchar('\n');
}

void	putline_mid(int columns)
{
	int	i;

	i = 0;
	while (i < columns)
	{
		if (i == 0)
			ft_putchar('B');
		else if (i == (columns - 1))
			ft_putchar('B');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int	rush(int x, int y)
{
	char	*error;
	int		j;

	error = "Error: dimensions must be greater than 0\n";
	if (x <= 0 || y <= 0)
	{
		write(1, error, 41);
		return (-1);
	}
	j = 0;
	while (j < y)
	{
		if (j == 0)
			putline_first_last(x);
		else if (j == (y - 1))
			putline_first_last(x);
		else
			putline_mid(x);
		j++;
	}
	return (0);
}
