/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp_loader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochernov <ochernov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:52:26 by ochernov          #+#    #+#             */
/*   Updated: 2024/08/28 15:31:20 by ochernov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mp.h"
#include "../includes/ft_lib.h"

#define BUF_SIZE 100

char	invalid(char c)
{
	return (c < 32 || c > 126);
}

char	is_header_valid(t_header *h)
{
	if (h->sy < 1 || h->sx < 1)
		return (0);
	if (invalid(h->empty) || invalid(h->obstacle) || invalid(h->full))
		return (0);
	if (h->empty == h->obstacle || h->empty == h->full)
		return (0);
	if (h->obstacle == h->full)
		return (0);
	return (1);
}

char	mp_load_header(char *fn, t_header *h)
{
	char	buf[BUF_SIZE];
	int		i;
	int		fd;

	fd = open(fn, 0);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < BUF_SIZE && read(fd, buf + i, 1) > 0 && buf[i] != '\n')
		i++;
	if (buf[i] != '\n' || i < 4)
		return (0);
	h->empty = buf[i - 3];
	h->obstacle = buf[i - 2];
	h->full = buf[i - 1];
	buf[i - 3] = 0;
	h->sy = ft_atoi(buf);
	i = 0;
	while (read(fd, buf, 1) == 1 && *buf != '\n')
		i++;
	h->sx = i;
	close(fd);
	return (is_header_valid(h));
}

/// @brief loads n bytes from the map-file, skips 1 nl at the end 
///    for non last row
/// @param fd - file descriptor
/// @param buf - buffer
/// @param h - header (to have size of row and marks)
/// @return 0 on error (including reading of less bytes), 1 on OK
char	mp_load_row(int fd, char *buf, t_header *h, char islast)
{
	char	c;
	int		i;

	if (read(fd, buf, h->sx) != h->sx)
		return (0);
	if (!islast && read(fd, &c, 1) != 1 && c != '\n')
		return (0);
	i = 0;
	while (i < h->sx)
	{
		if (buf[i] == h->obstacle)
			buf[i++] = 0;
		else if (buf[i] == h->empty)
			buf[i++] = 1;
		else
			return (0);
	}
	return (1);
}
