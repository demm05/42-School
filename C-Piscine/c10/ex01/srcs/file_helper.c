/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 22:03:01 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/28 18:59:51 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

int	check_pf(char *pf)
{
	int	file;

	file = open(pf, 00);
	if (file < 0)
	{
		file = open(pf, 00 | 65536);
		if (file > 0)
			ft_putstr(": Is a directory\n");
		else
			ft_putstr("Cannot read file.\n");
		close(file);
	}
	else
	{
		close(file);
		return (0);
	}
	return (1);
}

int	open_file(char *path_to_file)
{
	int	file;

	if (check_pf(path_to_file))
		return (-1);
	file = open(path_to_file, 00);
	return (file);
}

int	read_file(char *path_to_file)
{
	int		file;
	int		size;
	int		bytes;
	char	buffer[1];

	file = open_file(path_to_file);
	if (file == -1)
		return (-1);
	size = 0;
	bytes = read(file, buffer, 1);
	if (bytes == -1)
	{
		ft_putstr("ft_cat: ");
		ft_putstr(path_to_file);
		ft_putstr(": Is a directory\n");
	}
	while (bytes > 0)
	{
		ft_putchar(buffer[0]);
		size++;
		bytes = read(file, buffer, 1);
	}
	close(file);
	return (size);
}
