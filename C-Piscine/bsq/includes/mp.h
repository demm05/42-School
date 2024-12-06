/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mp.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochernov <ochernov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 19:50:49 by ochernov          #+#    #+#             */
/*   Updated: 2024/08/28 15:21:01 by ochernov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MP_H
# define MP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# define EMPTY 0
# define OBSTACLE -1

typedef struct s_solution
{
	int	x;
	int	y;
	int	size;
}	t_solution;

typedef struct s_header
{
	int		sy;
	int		sx;
	char	empty;
	char	obstacle;
	char	full;
}	t_header;

typedef struct s_context
{
	t_header	h;
	int			fd;
	int			*buf;
	char		*row;
}	t_context;

char	mp_solve(char *fn, t_solution *sol, t_header *h);
char	mp_load_header(char *fn, t_header *h);
char	mp_load_row(int fd, char *buf, t_header *h, char islast);
void	mp_put_solution_nofield(t_solution *s);
void	print_sol(char *fn, t_solution *s, t_header h);

#endif