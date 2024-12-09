/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmyth <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 12:27:06 by fsmyth            #+#    #+#             */
/*   Updated: 2024/08/11 13:10:35 by fsmyth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	rush(int x, int y);

int	my_atoi(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (-1);
		i = i * 10 + (*s - '0');
		s++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	char	*error1;
	char	*error2;
	int		x;
	int		y;

	error1 = "Error: provide exactly two dimensions\n";
	error2 = "Error: invalid dimensions provided\n";
	if (argc != 3)
	{
		write(1, error1, 38);
		return (0);
	}
	x = my_atoi(*(++argv));
	y = my_atoi(*(++argv));
	if (x == -1 || y == -1)
	{
		write(1, error2, 35);
		return (0);
	}
	rush(x, y);
	return (0);
}
