/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:30:21 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/28 19:17:28 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_file_info
{
	char	*path_to_file;
	int		byte_size;
	int		number_of_lines;
}	t_file_info;

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		read_stdin(void);
int			ft_strlen(char *str);
char		*ft_strdup(char *src);
t_file_info	*get_file_info(char *path_to_file);
int			ft_atoi(char *str);
int			ft_strcmp(char *s1, char *s2);
void		print_last_n_bytes(t_file_info *file_info, int bytes);
int			check_t_file_info(t_file_info *file);
void		write_from_stdin_to_file(char *pf);

#endif