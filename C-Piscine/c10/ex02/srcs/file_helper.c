/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:03:01 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/28 19:28:12 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	open_file(char *path_to_file)
{
	int	file;

	file = open(path_to_file, 00);
	return (file);
}

int	read_file(char *path_to_file)
{
	int		file;
	int		size;
	char	buffer[1];

	file = open_file(path_to_file);
	if (file == -1)
		return (-1);
	size = 0;
	while (read(file, buffer, 1) > 0)
	{
		ft_putchar(buffer[0]);
		size++;
	}
	close(file);
	return (size);
}

t_file_info	*get_file_info(char *path_to_file)
{
	int			file;
	int			bytes;
	t_file_info	*file_info;
	char		buffer[1];

	file = open_file(path_to_file);
	file_info = malloc(sizeof(t_file_info *));
	file_info->byte_size = 0;
	file_info->number_of_lines = 0;
	file_info->path_to_file = ft_strdup(path_to_file);
	bytes = read(file, buffer, 1);
	if (bytes == -1)
		file_info->byte_size = -2;
	if (file == -1)
		file_info->byte_size = -1;
	while (bytes > 0)
	{
		if (buffer[0] == '\n')
			file_info->number_of_lines++;
		file_info->byte_size++;
		bytes = read(file, buffer, 1);
	}
	close(file);
	return (file_info);
}

void	write_from_stdin_to_file(char *pf)
{
	char	buffer;
	int		file;

	file = open(pf, 01 | 0100 | 01000, 0644);
	if (file == -1)
	{
		ft_putstr("Couldn't create file for writing");
		exit(-1);
	}
	while (read(0, &buffer, 1) > 0)
		write(file, &buffer, 1);
}

void	print_last_n_bytes(t_file_info *file_info, int bytes)
{
	int		cur_byte;
	int		file;
	char	buffer[1];

	if (check_t_file_info(file_info))
		return ;
	cur_byte = 0;
	file = open_file(file_info->path_to_file);
	if (file == -1)
		return ;
	while (read(file, buffer, 1) > 0)
	{
		if (cur_byte >= file_info->byte_size - bytes)
			ft_putchar(buffer[0]);
		cur_byte++;
	}
}
