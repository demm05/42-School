/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 19:15:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/16 10:51:50 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ('9' < str[i] || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

/*#include <stdio.h>
int main(void)
{
    int res;
    res = ft_str_is_numeric("12342342");
    printf("%d", res);
    return 0;
}*/