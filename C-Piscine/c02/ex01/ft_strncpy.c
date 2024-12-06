/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 18:02:34 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/17 10:03:07 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	dest[15] = {};

	ft_strncpy(dest, "String Copy!", 2);
	printf("%s\n", dest);
	ft_strncpy(dest, "Hello", 8);
	printf("%s", dest);
	return (0);
}*/