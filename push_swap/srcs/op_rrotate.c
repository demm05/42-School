/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 20:20:33 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/06 20:28:58 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	rra_internal(t_stack *stack, int print)
{
	if (print)
		write(1, "rra", 3);
}

static void	rrb_internal(t_stack *stack, int print)
{
	if (print)
		write(1, "rrb", 3);
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
	write(1, "rrr", 3);
}
