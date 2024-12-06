/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochernov <ochernov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 10:13:53 by ochernov          #+#    #+#             */
/*   Updated: 2024/08/28 15:24:08 by ochernov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mp.h"

int	min3(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	if (b < c)
		return (b);
	return (c);
}

void	skip_line(int fd)
{
	char	c;

	while (read(fd, &c, 1) == 1)
		if (c == '\n')
			return ;
}

/// @brief recalculates buffer with loaded row
/// @param s - state
/// @return index of maximum
int	process_row(t_context *c, int row)
{
	int	i;
	int	max;
	int	prev_buf;
	int	v;

	i = 1;
	max = 0;
	prev_buf = c->buf[0];
	c->buf[0] = c->row[0];
	while (i < c->h.sx)
	{
		if (row == 0)
			c->buf[i] = c->row[i];
		else
		{
			v = min3(c->buf[i - 1], prev_buf, c->buf[i]) + 1;
			prev_buf = c->buf[i];
			c->buf[i] = v * c->row[i];
		}
		if (c->buf[i] > c->buf[max])
			max = i;
		i++;
	}
	return (max);
}

char	solve2(t_context *c, t_solution *s)
{
	int			y;
	int			idx;

	s->size = 0;
	y = -1;
	while (++y < c->h.sy)
	{
		if (!mp_load_row(c->fd, c->row, &c->h, y == c->h.sy - 1))
			return (0);
		idx = process_row(c, y);
		if (c->buf[idx] > s->size)
		{
			s->size = c->buf[idx];
			s->x = idx;
			s->y = y;
		}
	}
	return (1);
}

char	mp_solve(char *fn, t_solution *sol, t_header *header)
{
	t_context	c;
	char		res;

	if (!mp_load_header(fn, &c.h))
		return (0);
	c.fd = open(fn, 0);
	if (c.fd < 0)
		return (0);
	skip_line(c.fd);
	c.buf = malloc(c.h.sx * sizeof(int));
	c.row = malloc(c.h.sx * sizeof(char));
	res = solve2(&c, sol);
	sol->x -= sol->size - 1;
	sol->y -= sol->size - 1;
	*header = c.h;
	close(c.fd);
	free(c.buf);
	free(c.row);
	return (res);
}
