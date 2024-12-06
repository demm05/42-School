/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:41:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/12 11:43:49 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

/*int main(void)
{
	char ar[] = "@AASFA";
	char res[50];

    printf("%s", ft_strlowcase(&ar[0]));
    return (0);
}*/