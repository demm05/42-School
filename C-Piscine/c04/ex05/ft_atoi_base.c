/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:55:45 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/19 20:45:55 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_atoi(char *str, int *index, int *sign)
{
	int	signt;
	int	result;
	int	i;

	signt = 1;
	result = 0;
	i = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			signt *= -1;
		i++;
	}
	if (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		*index = i;
		*sign = signt;
	}
	return ;
}

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

int	find_index(char ch, char *base)
{
	int	i;

	i = 0;
	while (ch != base[i])
		i++;
	return (i);
}

int	m_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * m_power(nb, power - 1));
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	result;
	int	s_len;
	int	i;
	int	sign;

	ft_atoi(str, &i, &sign);
	s_len = 0;
	while (str[s_len + i] && str[s_len + i] >= '0' && str[s_len + i] <= '9')
		s_len++;
	s_len += i;
	base_len = is_valid_base(base);
	if (!base_len)
		return (0);
	result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result += find_index(str[i], base) * m_power(base_len, s_len - 1 - i);
		i++;
	}
	return (sign * result);
}

/*#include <stdio.h>
int		main(void)
{
	char *s = "--+---+0015 20";
	printf("%d\n", ft_atoi_base(s,"0123456789"));
	printf("%d\n", ft_atoi_base(s,"01234567089ABCDEF"));
	printf("%d\n", ft_atoi_base(s,"0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("FFFFFFFF","01234567089ABCDEF"));
	return 0;
}*/