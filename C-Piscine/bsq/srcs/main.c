/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochernov <ochernov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:50:49 by ochernov          #+#    #+#             */
/*   Updated: 2024/08/28 15:30:45 by ochernov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/ft_lib.h"
#include "../includes/mp.h"

// #include "mp_loader.c"
// #include "mp_printer.c"
// #include "mp_processor.c"
// #include "ft_putstr.c"
// #include "ft_putnbr.c"
// #include "ft_atoi.c"

void	start_solving_file(char *fn)
{
	t_solution	sol;
	t_header	t;

	if (!mp_solve(fn, &sol, &t))
	{
		ft_putstr("map error\n");
		return ;
	}
	print_sol(fn, &sol, t);
}

void	write_from_stdin_to_file(char *pf)
{
	char	buffer;
	int		file;

	file = open(pf, 01 | 0100 | 01000, 0644);
	if (file == -1)
	{
		ft_putstr("Couldn't create file for writing");
		exit(-1);
	}
	while (read(0, &buffer, 1))
		write(file, &buffer, 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
	{
		write_from_stdin_to_file("map.tmpp");
		start_solving_file("map.tmpp");
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			start_solving_file(argv[i]);
			if (i < argc - 1)
				ft_putstr("\n");
		}
	}
	return (0);
}
