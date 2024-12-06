/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:39:06 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:33:32 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
		else
			*lst = new;
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
// 	return (0);
// }
