/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 19:58:26 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/25 23:30:39 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_arguments
{
	char				*number;
	char				*path_to_dict;
	struct s_dictionary	**dict;
	int					size;
}	t_arguments;

typedef struct s_dictionary
{
	char	*number;
	char	*printable_char;
	int		size_of_number;
}	t_dictionary;

typedef t_dictionary	t_d;

int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
t_d		**get_dict(char *path_to_file, int *size);
char	**ft_split(char *str, char *charset);
char	*ft_strdup(char *src);
void	free_arguments(struct s_arguments *args);
void	free_split(char **arr);
char	*get_value_of_nbr(struct s_arguments *args, char *nbr, int size);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**get_tens_printable(struct s_arguments *args, char *number);
char	**get_hudrets_printable(struct s_arguments *args, char *number);
char	**get_digit_printable(struct s_arguments *args, char digit);
void	logic(struct s_arguments *args);
char	*get_content_of_file(char *path_to_file, int *size);

#endif