/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelnyk <dmelnyk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 11:55:45 by dmelnyk           #+#    #+#             */
/*   Updated: 2024/08/20 14:43:19 by dmelnyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	power(int a, int b)
{
	int	result;

	if (b == 0)
		return (1);
	result = a;
	while (b > 1)
	{
		result *= a;
		b--;
	}
	return (result);
}

int	find_index(char ch, char *base)
{
	int	i;

	i = 0;
	while (ch != base[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	result;
	int	i;
	int	str_len;
	int	test;

	base_len = is_valid_base(base);
	if (!base_len)
		return (0);
	i = 0;
	result = 0;
	str_len = ft_strlen(str);
	while (str[i])
	{
		test = power(base_len, str_len - 1 - i);
		test = find_index(str[i], base);
		result += find_index(str[i], base) * power(base_len, str_len - 1 - i);
		i++;
	}
	return (result);
}

/*#include <stdio.h>
int main(void)
{
	printf("%d", ft_atoi_base("0015", "0123456789"));
	return (0);
}*/
