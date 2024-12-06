/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:38:59 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:33:27 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

// #include <stdio.h>
// int	main(void)
// {
// 	t_list	*lst1;
// 	t_list	*lst2;
// 	t_list	*lst3;
// 
// 	lst1 = ft_lstnew("a");
// 	lst2 = ft_lstnew("b");
// 	lst3 = ft_lstnew("c");
// 	ft_lstadd_back(&lst1, lst2);
// 	ft_lstadd_back(&lst1, lst3);
// 	printf("%s", (char *)lst1->content);
// 	ft_lstclear(&lst1, ft_lstdelone);
// 	return (0);
// }
