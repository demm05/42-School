/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:44:43 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/26 14:34:39 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + ' ';
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	is_new_word;
	int	i;

	is_new_word = 1;
	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (is_new_word == 1)
				str[i] -= 32;
			is_new_word = 0;
		}
		else if (str[i] >= '0' && str[i] <= '9')
			is_new_word = 0;
		else
			is_new_word = 1;
		i++;
	}
	return (str);
}

/*#include <stdio.h>
int	main(void)
{
	char ar[] = "salut, comment .THIST vas ? 42mots ";

    printf("%s", ft_strcapitalize(&ar[0]));
    return (0);
}*/
