/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 16:30:13 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/12 17:47:25 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/*int	main(void)
{
	char	dest[2] = {};

	ft_strcpy(dest, "hello");
	printf("%s\n", dest);
	ft_strcpy(dest, "asdfdafd");
	printf("%s", dest);
	return (0);
}*/