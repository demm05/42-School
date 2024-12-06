/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:33:25 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:33:10 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// int main(void)
// {
// 	t_list	*lst;
// 	t_list	*lst2;
// 	t_list	*lst3;
// 
// 	lst = ft_lstnew("H");
// 	lst2 = ft_lstnew("h");
// 	lst3 = ft_lstnew("h3");
// 	ft_lstadd_front(&lst3, lst2);
// 	ft_lstadd_front(&lst3, lst);
// 	printf("%d", ft_lstsize(lst3));
// 	return (0);
// }
