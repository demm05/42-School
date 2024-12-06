/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:11:22 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:32:54 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

// #include <fcntl.h>
// int main(void)
// {
// 	int	fd;
// 
// 	fd = open("test.txt", O_APPEND | O_WRONLY);
// 	if (!fd)
// 		return (0);
// 	ft_putchar_fd('d',fd);
// 	close(fd);
// 	return (0);
// }
