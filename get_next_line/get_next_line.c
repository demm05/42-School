/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:35:17 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/19 12:43:40 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line_len(t_list *lst)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (lst && !lst->is_nl)
	{
		len += lst->c_len;
		lst = lst->next;
	}
	if (lst && lst->is_nl)
	{
		while (lst->content[i] && lst->content[i] != '\n')
		{
			i++;
			len++;
		}
		len++;
	}
	return (len);
}

void	clean_list(t_list **lst)
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current->next)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	if (current->is_nl)
		clean_node_with_nl(current, lst);
	else
	{
		free(current->content);
		free(current);
		*lst = NULL;
	}
}

char	*get_line(t_list *lst)
{
	char	*line;
	int		line_len;

	line_len = get_line_len(lst);
	line = malloc(sizeof(char) * (line_len + 1));
	if (!line)
		return (NULL);
	join_nodes(lst, line);
	return (line);
}

int	create_list(int fd, t_list **lst)
{
	char	*buffer;
	int		bytes_read;

	if (is_there_nl(*lst))
		return (0);
	while (1)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			return (bytes_read);
		}
		buffer[bytes_read] = 0;
		if (ft_strchr(buffer, '\n'))
		{
			append_list(lst, buffer, bytes_read, 1);
			return (bytes_read);
		}
		append_list(lst, buffer, bytes_read, 0);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (create_list(fd, &lst) == -1)
	{
		clean_list(&lst);
		return (NULL);
	}
	if (!lst)
		return (NULL);
	line = get_line(lst);
	clean_list(&lst);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*res;
// 	int 	i;
// 	t_list	*lst;
//
// 	fd = open("files/alternate_line_nl_with_nl", O_RDONLY);
// 	i = 0;
// 	//res = get_next_line(fd);
// 	// printf("%s", res);
// 	while ((res = get_next_line(fd)))
// 	{
// 		printf("res: %s", res);
// 		 free(res);
// 		i++;
// 	}
// 	return (0);
// }
