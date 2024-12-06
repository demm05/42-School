/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 20:23:48 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/12 11:39:12 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - ' ';
		}
		i++;
	}
	return (str);
}

/*int main(void)
{
	char ar[] = "@asda";
	char res[50];

    printf("%s", ft_strupcase(&ar[0]));
    return (0);
}*/
