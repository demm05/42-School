/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:55:27 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/28 19:02:08 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	read_stdin(void)
{
	char	buf[1];

	while (read(STDIN_FILENO, buf, 1) > 0)
		write(STDOUT_FILENO, buf, 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 1)
		read_stdin();
	else
	{
		i = 1;
		while (i < argc)
		{
			read_file(argv[i]);
			i++;
		}
	}
	return (0);
}
