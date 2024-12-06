/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:54:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/10 12:19:05 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int	main(void)
{
	int	a, b, div, mod;

	a = 5;
	b = 2;
	ft_div_mod(a, b, &div, &mod);
	printf("Div: %d\n Mod: %d", div, mod);
	return (0);
}*/
