/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:20:28 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/06 20:20:55 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	printf_lst(t_stack *stack)
{
	t_list	*lst;

	lst = stack->a;
	while (lst)
	{
		ft_printf("%d\n", lst->data);
		lst = lst->next;
	}
	ft_printf("\n");
	lst = stack->b;
	while (lst)
	{
		ft_printf("%d\n", lst->data);
		lst = lst->next;
	}
}

t_stack	*initialize_stack(int argc, char *argv[])
{
	t_stack	*stack;
	t_list	*cur;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->a = parse_argv(argc, argv);
	stack->b = NULL;
	stack->len = 0;
	if (!stack->a)
	{
		clean_list(&stack->a);
		free(stack);
		return (NULL);
	}
	cur = stack->a;
	while (cur)
	{
		stack->len++;
		cur = cur->next;
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack;

	stack = initialize_stack(argc, argv);
	if (!stack)
		return (1);
	pb(stack);
	pb(stack);
	pb(stack);
	printf_lst(stack);
	clean_list(&stack->a);
	clean_list(&stack->b);
}
