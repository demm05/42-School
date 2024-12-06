/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 10:51:02 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/19 20:50:39 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *base)
{
	int	base_len;
	int	i;
	int	j;

	i = 0;
	base_len = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (0);
		i++;
		base_len++;
	}
	if (base_len <= 1)
		return (0);
	return (base_len);
}

void	transform_to_base(long nbr, char *base, int base_len)
{
	int	radix;

	if (!nbr)
		return ;
	else
	{
		radix = nbr % base_len;
		transform_to_base(nbr / base_len, base, base_len);
	}
	write(1, &base[radix], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	long	nb;

	nb = nbr;
	base_len = is_valid_base(base);
	if (!base_len)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	transform_to_base(nb, base, base_len);
}

/*#include <stdio.h>
int	main(void)
{
	int number = -2147483648;
	printf("%04X\n", number);
	ft_putnbr_base(number, "01");
	return (0);
}*/