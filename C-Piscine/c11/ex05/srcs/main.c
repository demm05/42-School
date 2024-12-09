/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 14:23:56 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/29 15:46:45 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dop.h"
#include "ft_lib.h"

int	is_there_op(char ch)
{
	if (ch == '/' || ch == '+' || ch == '-' || ch == '*' || ch == '%')
		return (0);
	return (1);
}

int	parse_args(t_args *args, int argc, char *argv[])
{
	if (argc != 4)
		return (1);
	if (ft_strlen(argv[2]) != 1 || is_there_op(argv[2][0]))
	{
		ft_putnbr(0);
		return (1);
	}
	args->v1 = ft_atoi(argv[1]);
	args->op = argv[2][0];
	args->v2 = ft_atoi(argv[3]);
	return (0);
}

int	check_for_zero(int nbr, char sign)
{
	if (nbr == 0)
	{
		if (sign == '/')
			ft_putstr("Stop : division by zero");
		else if (sign == '%')
			ft_putstr("Stop : modulo by zero");
		return (1);
	}
	return (0);
}

void	solve_it(t_args args)
{
	int	res;

	if (args.op == '+')
		res = args.v1 + args.v2;
	else if (args.op == '-')
		res = args.v1 - args.v2;
	else if (args.op == '*')
		res = args.v1 * args.v2;
	else if (args.op == '/')
	{
		if (check_for_zero(args.v2, args.op))
			return ;
		res = args.v1 / args.v2;
	}
	else if (args.op == '%')
	{
		if (check_for_zero(args.v2, args.op))
			return ;
		res = args.v1 % args.v2;
	}
	ft_putnbr(res);
}

int	main(int argc, char *argv[])
{
	t_args	args;

	if (parse_args(&args, argc, argv))
		return (-1);
	solve_it(args);
	ft_putchar('\n');
	return (0);
}
