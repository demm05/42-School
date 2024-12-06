/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochernov <ochernov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:50:49 by ochernov          #+#    #+#             */
/*   Updated: 2024/08/28 17:04:17 by ochernov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"
#include "../includes/mp.h"

void	print_row(t_solution *s, t_header *h, char *buf, int y)
{
	int	x;

	x = -1;
	while (++x < h->sx)
	{
		if (x >= s->x && x <= s->x + s->size - 1 && \
				y >= s->y && y <= s->y + s->size - 1)
			write(1, &h->full, 1);
		else
			write(1, buf + x, 1);
	}
	write(1, "\n", 1);
}

void	print_sol(char *fn, t_solution *s, t_header h)
{
	int		y;
	char	*buf;
	int		fd;

	buf = malloc(h.sx + 1);
	fd = open(fn, 0);
	while (read(fd, buf, 1) > 0)
		if (*buf == '\n')
			break ;
	y = -1;
	while (++y < h.sy)
	{
		read(fd, buf, h.sx + 1);
		print_row(s, &h, buf, y);
	}
	close(fd);
	free(buf);
}
