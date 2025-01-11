/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 18:54:57 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/11 19:31:21 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_stack *stack)
{
    if (stack->a->nbr> stack->a->next->nbr)
        sa(stack); 
}

void	sort_3(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->a->nbr;
	second = stack->a->next->nbr;
	third = stack->a->next->next->nbr;
	if (first < second && second < third)
		return ;
	if (first < third && first > second)
		sa(stack);
	else if (third < first && second > first)
		rra(stack);
	else if (first > third && third > second)
		ra(stack);
	else if (third > first && third < second)
	{
		rra(stack);
		sa(stack);
	}
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_4(t_stack *stack)
{

}

void	sort_5(t_stack *stack)
{

}
