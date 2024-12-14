/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:24:50 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/13 15:29:15 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s && *s)
		s++;
	if ((char)c == *s)
		return ((char *)s);
	return (0);
}

void	append_list(t_list **lst, char *content, int len, int is_nl)
{
	t_list	*new;
	t_list	*cur;

	if (!lst)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->content = content;
	new->c_len = len;
	new->next = NULL;
	new->is_nl = is_nl;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	join_nodes(t_list *lst, char *dest)
{
	int	i;
	int	j;

	j = 0;
	while (lst)
	{
		i = 0;
		while (i < lst->c_len)
		{
			dest[j++] = lst->content[i];
			if (lst->is_nl && lst->content[i] == '\n')
			{
				dest[j] = '\0';
				return ;
			}
			i++;
		}
		lst = lst->next;
	}
	dest[j] = '\0';
}

int	is_there_nl(t_list *lst)
{
	int	i;

	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i++] == '\n')
			{
				lst->is_nl = 1;
				return (1);
			}
		}
		lst = lst->next;
	}
	return (0);
}

void	clean_node_with_nl(t_list *current, t_list **lst)
{
	int		i;
	int		j;

	i = 0;
	while (current->content[i++] != '\n')
		continue ;
	if (i == current->c_len)
	{
		free(current->content);
		free(current);
		*lst = NULL;
		return ;
	}
	j = 0;
	while (i < current->c_len)
		current->content[j++] = current->content[i++];
	current->content[j] = '\0';
	current->c_len = j;
	current->is_nl = 0;
	*lst = current;
}
