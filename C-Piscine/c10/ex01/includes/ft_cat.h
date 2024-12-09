/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:55:40 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/26 18:56:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAT_H
# define FT_CAT_H
# include <unistd.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		read_file(char *path_to_file);

#endif