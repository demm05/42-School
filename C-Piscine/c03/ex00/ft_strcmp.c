/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:06:19 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/13 16:07:46 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	printf("0 = %d\n", ft_strcmp("ABC", "ABC"));
	printf("67 = %d\n", ft_strcmp("ABC", "AB"));
	printf("-25 = %d\n", ft_strcmp("ABA", "ABZ"));
	printf("7 = %d\n", ft_strcmp("ABJ", "ABC"));
	return (0);
}*/