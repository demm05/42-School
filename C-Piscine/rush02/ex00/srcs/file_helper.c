/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:03:01 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/25 22:03:53 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <fcntl.h>
#include <stdio.h>

int	open_file(char *path_to_file)
{
	int	file;

	file = open(path_to_file, O_RDONLY);
	if (file == -1)
		ft_putstr("Cannot read file.\n");
	return (file);
}

int	get_bytessize_file(char *path_to_file)
{
	int		file;
	int		size;
	char	buffer[1];

	file = open_file(path_to_file);
	if (file == -1)
		return (-1);
	size = 0;
	while (read(file, buffer, 1) > 0)
		size++;
	close(file);
	return (size);
}

char	*get_content_of_file(char *path_to_file, int *size)
{
	int		i;
	int		file;
	char	*content;
	char	buffer[1];

	file = open_file(path_to_file);
	if (file == -1)
		return (NULL);
	content = malloc(sizeof(char *) * get_bytessize_file(path_to_file) + 1);
	if (!content)
	{
		ft_putstr("malloc: get_content_of_file couldn't allocate memory;");
		return (NULL);
	}
	i = 0;
	while (read(file, buffer, 1) > 0)
	{
		content[i] = buffer[0];
		if (content[i] == ':')
			*size = *size + 1;
		i++;
	}
	close(file);
	return (content);
}
