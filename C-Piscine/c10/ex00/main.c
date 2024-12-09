/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 11:24:47 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/27 11:25:21 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	open_file(char *path_to_file)
{
	int	file;

	file = open(path_to_file, O_RDONLY);
	if (file == -1)
		ft_putstr("Cannot read file.\n");
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

int	main(int argc, char *argv[])
{
	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		read_file(argv[1]);
	}
	return (0);
}
