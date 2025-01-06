/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:30:19 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/06 16:54:44 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

void	clean_list(t_list **lst)
{
	t_list	*next;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
}

void	append_list(t_list **lst, int num)
{
	t_list	*new;
	t_list	*node;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		clean_list(lst);
		exit(1);
	}
	new->data = num;
	new->next = NULL;
	if (!*lst)
	{
		new->prev = NULL;
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
		node = node->next;
	new->prev = node;
	node->next = new;
	node->next->prev = node;
}
