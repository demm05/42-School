/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:56:57 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 12:43:44 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*content;
	int				c_len;
	int				is_nl;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	join_nodes(t_list *lst, char *dest);
void	append_list(t_list **lst, char *content, int len, int is_nl);
int		is_there_nl(t_list *lst);
void	clean_node_with_nl(t_list *current, t_list **lst);
char	*ft_strchr(const char *s, int c);

#endif
