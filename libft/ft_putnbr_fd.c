/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:11:35 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:32:49 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

static int	get_len_of_num(long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n /= 10;
	}
	return (len);
}

void	ft_putnbr_fd(int num, int fd)
{
	int		len;
	int		temp;
	char	buffer[1];
	long	n;

	if (fd < 0)
		return ;
	if (num < 0)
	{
		n = num;
		n *= -1;
		write(fd, "-", 1);
	}
	else
		n = num;
	len = get_len_of_num(n);
	while (len)
	{
		temp = ft_recursive_power(10, len - 1);
		buffer[0] = n / temp + '0';
		n = n % temp;
		write(fd, buffer, 1);
		len--;
	}
}

// #include <fcntl.h>
// int	main(void)
// {
// 	int	fd;
// 
// 	fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (!fd)
// 		return (0);
// 	ft_putnbr_fd(2147483647, fd);
// 	close(fd);
// 	return (0);
// }
