/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:20:28 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/11 21:10:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_stack	*initialize_stack(int argc, char *argv[])
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = parse_argv(argc, argv);
	if (!stack->a)
	{
		clean_list(&stack->a);
		free(stack);
		return (NULL);
	}
	stack->a_len = ft_lstsize(stack->a);
	return (stack);
}
// https://github.com/toukoum/push_swap-42/blob/main/srcs/opti_sort.c
// https://github.com/ayogun/push_swap/blob/main/srcs/push_swap/push_swap.c

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	stack = initialize_stack(argc, argv);
	if (!stack)
		return (1);
	sort_stack(stack);
	clean_list(&stack->a);
	clean_list(&stack->b);
	free(stack);
}
