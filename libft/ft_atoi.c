/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:09:31 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:29:04 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign *= -1;
	while (*nptr >= '0' && *nptr <= '9' && *nptr)
		result = result * 10 + (*nptr++ - '0');
	return (result * sign);
}

// #include <stdlib.h>
// #include <string.h>
// int main(void)
// {
// 	char	str[] = "";
// 	printf("%d\n", ft_atoi(str));
// 	printf("%d\n", atoi(str));
// }
