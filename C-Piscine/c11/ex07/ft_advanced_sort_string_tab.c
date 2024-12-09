/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:40:32 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/29 17:20:30 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int cmp(char *, char *))
{
	int		i;
	int		j;
	int		smallest;
	char	*temp;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		j = i;
		smallest = i;
		while (tab[++j])
		{
			if (cmp(tab[smallest], tab[j]) > 0)
				smallest = j;
		}
		if (smallest != i)
		{
			temp = tab[i];
			tab[i] = tab[smallest];
			tab[smallest] = temp;
		}
		i++;
	}
}

/*int	ft_strcmp(char *s1, char *s2)
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

#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	*strs[] = {"9fhfdgh", "23b gfdf", "1a5jfgsdf", 
	"1a3gsfd", "6fhj6", (char *)0};

	ft_advanced_sort_string_tab(strs, &ft_strcmp);
	int i = -1;
	while (strs[++i])
		printf("%s\n", strs[i]);
	return (0);
}*/