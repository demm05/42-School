/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:04:19 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/10 12:20:39 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	*el;

	i = 0;
	el = tab + i;
	while (size > 1)
	{
		if (*el < *(tab + i))
		{
			el = tab + i;
			i++;
			continue ;
		}
		if (i >= size - 1)
		{
			ft_swap(el, tab + i);
			size--;
			i = 0;
			continue ;
		}
		i++;
	}
}

/*int     main(void)
{
        int arr[] = {3, 8, 1, 1};
        int size = 4;
        ft_sort_int_tab(arr, size);
        
        int i = 0;
     	   while (i < size)
        {
            printf("%d", arr[i]);
            i++;
        }
        return (0);
}*/
