/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 12:58:52 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/11 19:55:29 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

int	get_pivot(t_stack *stack)
{
	// TODO: get pivot so we can presort array bayse on medium of list a
	// SO we have to sort stack first
	return (stack->a_len / 2);
}

void	push_pre_sort(t_stack *stack)
{
	int	median;
	int	i;
	int	size_a;

	size_a = stack->a_len;
	i = 0;
	median = get_pivot(stack);
	if (stack->a_len == 5)
		return ;
	while (i < size_a)
	{
		//sort_3(stack);
		pb(stack);
		if (stack->b->nbr > median)
			rb(stack);
		i++;
	}
}
void	sort_big(t_stack *stack)
{
	push_pre_sort(stack);
}

void	sort_stack(t_stack *stack)
{
	if (stack->a_len == 2) 
		sort_2(stack);
	else if (stack->a_len == 3)
		sort_3(stack);
	else if (stack->a_len == 4)
		sort_4(stack);
	else if (stack->a_len == 5)
		sort_5(stack);
	else if (stack->a_len > 5)
		sort_big(stack);
}
