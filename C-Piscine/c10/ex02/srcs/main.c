/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:32:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/29 17:33:59 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"
#include <errno.h>
#include <stdio.h>

void	print_for_args(int argc, char *argv[], int bytes_offset)
{
	int			i;
	t_file_info	*file;

	i = 2;
	while (++i < argc || argc == 3)
	{
		file = get_file_info(argv[i]);
		if (i != 3 && file->byte_size != -1)
			ft_putchar('\n');
		if (argc != 3 && file->byte_size != -1)
		{
			ft_putstr("==> ");
			ft_putstr(file->path_to_file);
			ft_putstr(" <==\n");
		}
		print_last_n_bytes(file, bytes_offset);
		free(file->path_to_file);
		if (argc == 3)
			break ;
	}
}

void	handle_no_args(void)
{
	int		file;
	char	buffer;

	write_from_stdin_to_file("t.tmp");
	file = open("t.tmp", O_RDONLY);
	while (read(file, &buffer, 1) > 0)
		ft_putchar(buffer);
	close(file);
}

void	handle_one_arg(void)
{
	ft_putstr("ft_tail: option requires an argument -- 'c'\n");
}

void	handle_multiple_args(int argc, char *argv[])
{
	int	bytes_offset;

	if (ft_strcmp(argv[1], "-c") != 0)
		return ;
	bytes_offset = ft_atoi(argv[2]);
	if (bytes_offset == -1)
	{
		ft_putstr("ft_tail: invalid number of bytes: ");
		ft_putstr(argv[2]);
		ft_putstr("\n");
		return ;
	}
	if (argc == 3)
	{
		write_from_stdin_to_file("t.tmp");
		argv[3] = "t.tmp";
	}
	print_for_args(argc, argv, bytes_offset);
}

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		handle_no_args();
	}
	else if (argc == 2)
	{
		handle_one_arg();
	}
	else if (argc >= 3)
	{
		handle_multiple_args(argc, argv);
	}
	return (0);
}
