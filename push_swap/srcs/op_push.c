/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:16:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/11 19:25:34 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pb(t_stack *stack)
{
	t_node	*temp;

	if (!stack->a)
		return ;
	temp = stack->a;
	stack->a = stack->a->next;
	if (stack->a)
		stack->a->prev = NULL;
	if (stack->b)
		stack->b->prev = temp;
	temp->next = stack->b;
	stack->b = temp;
	stack->a_len--;
	stack->b_len++;
	write(1, "pb\n", 3);
}

void	pa(t_stack *stack)
{
	t_node	*temp;

	if (!stack->b)
		return ;
	temp = stack->b;
	stack->b = temp->next;
	if (stack->b)
		stack->b->prev = NULL;
	if (stack->a)
		stack->a->prev = temp;
	temp->next = stack->a;
	stack->a = temp;
	stack->a_len++;
	stack->b_len--;
	write(1, "pa\n", 3);
}
