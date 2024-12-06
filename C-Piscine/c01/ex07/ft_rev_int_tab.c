/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:54:08 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/10 12:21:38 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	start;
	int	temp;

	start = 0;
	size -= 1;
	while (start < size)
	{
		temp = *(tab + start);
		*(tab + start) = *(tab + size);
		*(tab + size) = temp;
		start++;
		size--;
	}
}

/*int     main(void)
{
        int arr[] = {4, 1};
        int size = 2;

        ft_rev_int_tab(arr, size);
        
        int i = 0;
        while (i < size)
        {
            printf("%d", arr[i]);
            i++;
        }
        return (0);
}*/
