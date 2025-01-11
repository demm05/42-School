/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:30:44 by dmelnyk           #+#    #+#             */
/*   Updated: 2025/01/11 19:00:49 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H 
# define LIST_H 

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void	append_list(t_node **lst, int num);
void	clean_list(t_node **lst);
t_node	*parse_argv(int argc, char *argv[]);
int		ft_lstsize(t_node *lst);

#endif
