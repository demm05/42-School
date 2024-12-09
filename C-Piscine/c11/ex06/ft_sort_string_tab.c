/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:40:32 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/28 18:31:49 by dmelnyk          ###   ########.fr       */
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

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		smallest;
	char	*temp;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		smallest = i;
		while (tab[j])
		{
			if (ft_strcmp(tab[smallest], tab[j]) > 0)
				smallest = j;
			j++;
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

/*#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	char	**strs = malloc(sizeof(char *) * 5);
	int		i = -1;

	while (++i < 5)
		strs[i] = malloc(sizeof(char *) * 30);
	strs[i] = 0;

	strs[0] = "99fhfdgh";
	strs[1] = "23b gfdf";
	strs[2] = "1a5jfgsdf";
	strs[3] = "1a3gsfd";
	strs[4] = "96fhj6";
	ft_sort_string_tab(strs);
	i = -1;
	while (strs[++i])
		printf("%s\n", strs[i]);
	return (0);
}*/