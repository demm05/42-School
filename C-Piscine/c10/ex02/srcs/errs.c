/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:44:15 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/29 17:10:54 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	check_t_file_info(t_file_info *file)
{
	if (file->byte_size == -2)
	{
		ft_putstr("ft_tail: error reading '");
		ft_putstr(file->path_to_file);
		ft_putstr("' Is a directory\n");
		return (2);
	}
	if (file->byte_size == -1)
	{
		ft_putstr("ft_tail: cannot open '");
		ft_putstr(file->path_to_file);
		ft_putstr("' for reading: No such file or directory\n");
		return (1);
	}
	return (0);
}
