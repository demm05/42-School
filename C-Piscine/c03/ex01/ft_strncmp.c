/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:33:27 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/28 12:09:15 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
	printf("0 = %d\n", ft_strncmp("ABC", "ABC", 3));
	printf("0 = %d\n", ft_strncmp("ABC", "AB", 2));
	printf("-25 = %d\n", ft_strncmp("ABA", "ABZ", 3));
	printf("25 = %d\n", ft_strncmp("ZBJ", "ABC", 1));
	return (0);
}*/