/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:20:33 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/11 19:23:24 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rra_internal(t_stack *stack, int print)
{
	t_node	*last;
	t_node	*first;

	if (!stack->a || !stack->a->next)
		return ;
	first = stack->a;
	last = stack->a;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->a = last;
	if (print)
		write(1, "rra\n", 4);
}

static void	rrb_internal(t_stack *stack, int print)
{
	t_node	*last;
	t_node	*first;

	if (!stack->b || !stack->b->next)
		return ;
	first = stack->b;
	last = stack->b;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->b = last;
	if (print)
		write(1, "rrb\n", 4);
}

void	rra(t_stack *stack)
{
	rra_internal(stack, 1);
}

void	rrb(t_stack *stack)
{
	rrb_internal(stack, 1);
}

void	rrr(t_stack *stack)
{
	rra_internal(stack, 0);
	rrb_internal(stack, 0);
	write(1, "rrr\n", 4);
}
