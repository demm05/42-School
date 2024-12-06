/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:01:27 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/12/06 12:33:50 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = malloc (size * nmemb);
	if (ptr)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}

// #include <stdio.h>
// int main(void)
// {
// 	char	*ptr;
// 	int	nmemb = -10;
// 	ptr = (calloc(nmemb, -10)); 
// 	printf("%d", ptr==NULL);
// 	// while (nmemb)
// 	// 	printf("%c\n", ptr[nmemb-- -1]);
// 	free(ptr);
// 	return(0);
// }
