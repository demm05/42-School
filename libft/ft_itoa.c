/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:10:55 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:33:33 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static void	set_values(int n, long *num, int *len, int *is_minus)
{
	*num = n;
	*len = 0;
	*is_minus = 0;
	if (*num < 0)
	{
		*is_minus = 1;
		*num *= -1;
		*len = *len + 1;
	}
	*len += get_len_of_num(*num);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	int		is_minus;
	char	*res;

	set_values(n, &num, &len, &is_minus);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	res[len] = 0;
	while (len - is_minus)
	{
		res[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	if (is_minus)
		res[0] = '-';
	return (res);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int	n = 0;
// 	char	*res;
// 
// 	res = ft_itoa(n);
// 	printf("%s", res);
// 	free(res);
// 	return (0);
// }
