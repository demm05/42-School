/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:33:46 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:33:14 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			del(content);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}

// #include <stdio.h>
// void	*test(void *t)
// {
// 	return (t);
// }
// 
// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*lst1;
// 	t_list	*res;
// 	t_list	*next;
// 
// 	lst1 = ft_lstnew(ft_strdup("HELLO"));
// 	ft_lstadd_back(&lst1, ft_lstnew(ft_strdup("HELLO2")));
// 	ft_lstadd_back(&lst1, ft_lstnew(ft_strdup("HELLO3")));
// 	//ft_lstclear(&lst1, free);
// 	res = ft_lstmap(lst1, &test, free);
// 	while (res)
// 	{
// 		printf("%s\n", (char *)res->content);
// 		next = res->next;
// 		res = next;
// 	}
// 	return (0);
// }
