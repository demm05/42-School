/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:52:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/14 20:40:41 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	int		lowest_el;
	char	*temp;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		lowest_el = i;
		while (j < argc)
		{
			if (ft_strcmp(argv[j], argv[lowest_el]) < 0)
			{
				lowest_el = j;
			}
			j++;
		}
		ft_putstr(argv[lowest_el]);
		temp = argv[i];
		argv[i] = argv[lowest_el];
		argv[lowest_el] = temp;
		i++;
	}
	return (0);
}
