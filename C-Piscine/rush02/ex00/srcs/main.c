/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:52:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/25 23:06:31 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

void	handle_malloc_error(void *ptr)
{
	if (!ptr)
	{
		ft_putstr("malloc couldn't allocate memory for t_arguments\n");
		exit(1);
	}
}

t_arguments	get_arguments(int argc, char *argv[])
{
	t_arguments	args;

	if (argc == 2)
	{
		args.number = ft_strdup(argv[1]);
		args.path_to_dict = ft_strdup("./dict/numbers.dict");
		handle_malloc_error(args.number);
		handle_malloc_error(args.path_to_dict);
	}
	else if (argc == 3)
	{
		args.number = ft_strdup(argv[2]);
		args.path_to_dict = ft_strdup(argv[1]);
		handle_malloc_error(args.number);
		handle_malloc_error(args.path_to_dict);
	}
	else
	{
		ft_putstr("Error\n");
		exit(1);
	}
	return (args);
}

void	check_number(struct s_arguments *args)
{
	int		i;
	char	*number;

	number = args->number;
	i = 0;
	while (number[i])
	{
		if (number[i] >= '0' && number[i] <= '9')
			i++;
		else
		{
			ft_putstr("Wrong number");
			exit(1);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_arguments		args;

	args = get_arguments(argc, argv);
	check_number(&args);
	args.size = 0;
	args.dict = get_dict(args.path_to_dict, &args.size);
	logic(&args);
	free_arguments(&args);
	return (0);
}
